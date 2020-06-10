from symforce import sympy as sm
from symforce import types as T

from .base import LieGroup, Group
from .matrix import Matrix
from .matrix import Vector3
from .matrix import Z3
from .matrix import Z6
from .rot3 import Rot3


class Pose3(LieGroup):
    """
    Group of three-dimensional rigid body transformations - SE(3).

    The storage is a quaternion (x, y, z, w) for rotation followed by position (x, y, z).

    The tangent space is 3 elements for rotation followed by 3 elements for translation in
    the rotated frame, meaning we interpolate the translation in the tangent of the rotating
    frame for lie operations. This can be useful but is more expensive than SO3 x R3 for often
    no benefit.
    """

    TANGENT_DIM = 6
    MATRIX_DIMS = (4, 4)
    STORAGE_DIM = 7

    def __init__(self, R=None, t=None):
        # type: (Rot3, Matrix) -> None
        """
        Construct from elements in SO3 and R3.

        Args:
            R: Frame orientation
            t: Translation 3-vector in the global frame
        """
        self.R = R or Rot3()
        self.t = t or Vector3()

        assert isinstance(self.R, Rot3)
        assert isinstance(self.t, sm.MatrixBase)
        assert self.t.shape == (3, 1), self.t.shape

    # -------------------------------------------------------------------------
    # Storage concept - see symforce.ops.storage_ops
    # -------------------------------------------------------------------------

    def __repr__(self):
        # type: () -> str
        return "<Pose3 R={}, t=({}, {}, {})>".format(
            repr(self.R), repr(self.t[0]), repr(self.t[1]), repr(self.t[2])
        )

    def to_storage(self):
        # type: () -> T.List[T.Scalar]
        return self.R.to_storage() + self.t.to_storage()

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[T.Scalar]) -> Pose3
        assert len(vec) == cls.STORAGE_DIM
        return cls(
            R=Rot3.from_storage(vec[0 : Rot3.STORAGE_DIM]),
            t=Vector3(*vec[Rot3.STORAGE_DIM : Rot3.STORAGE_DIM + 3]),
        )

    # -------------------------------------------------------------------------
    # Group concept - see symforce.ops.group_ops
    # -------------------------------------------------------------------------

    @classmethod
    def identity(cls):
        # type: () -> Pose3
        return cls(R=Rot3.identity(), t=Z3())

    def compose(self, other):
        # type: (Pose3) -> Pose3
        assert isinstance(other, self.__class__)
        return self.__class__(R=self.R * other.R, t=self.t + self.R * other.t)

    def inverse(self):
        # type: () -> Pose3
        so3_inv = self.R.inverse()
        return self.__class__(R=so3_inv, t=-(so3_inv * self.t))

    # -------------------------------------------------------------------------
    # Lie group implementation
    # -------------------------------------------------------------------------

    @classmethod
    def expmap(cls, v, epsilon=0):
        # type: (T.Sequence[T.Scalar], T.Scalar) -> Pose3
        if isinstance(v, (list, tuple)):
            v = Matrix(v)

        R_tangent = Vector3(v[0], v[1], v[2])
        t_tangent = Vector3(v[3], v[4], v[5])

        R = Rot3.expmap(R_tangent, epsilon=epsilon)
        R_hat = Matrix(Rot3.hat(R_tangent))
        R_hat_sq = R_hat * R_hat
        theta = sm.sqrt(R_tangent.dot(R_tangent) + epsilon ** 2)

        V = (
            Matrix.eye(3)
            + (1 - sm.cos(theta)) / (theta ** 2) * R_hat
            + (theta - sm.sin(theta)) / (theta ** 3) * R_hat_sq
        )

        return cls(R, V * t_tangent)

    def logmap(self, epsilon=0):
        # type: (float) -> T.List
        R_tangent = Matrix(self.R.logmap(epsilon=epsilon))
        theta = sm.sqrt(R_tangent.dot(R_tangent) + epsilon)
        R_hat = Matrix(Rot3.hat(R_tangent))

        half_theta = 0.5 * theta

        V_inv = (
            Matrix.eye(3)
            - 0.5 * R_hat
            + (1 - theta * sm.cos(half_theta) / (2 * sm.sin(half_theta)))
            / (theta * theta)
            * (R_hat * R_hat)
        )
        t_tangent = V_inv * self.t
        return list(R_tangent.col_join(t_tangent))

    @classmethod
    def hat(cls, vec):
        # type: (T.List) -> Matrix
        R_tangent = Vector3(vec[0], vec[1], vec[2])
        t_tangent = Vector3(vec[3], vec[4], vec[5])
        return Matrix(Rot3.hat(R_tangent)).row_join(t_tangent).col_join(Matrix.zeros(1, 4)).tolist()

    # -------------------------------------------------------------------------
    # Helper methods
    # -------------------------------------------------------------------------

    def __mul__(self, right):
        # type: (T.Union[Pose3, Matrix]) -> T.Any
        """
        Left-multiply with a compatible quantity.
        """
        if isinstance(right, sm.MatrixBase):
            assert right.shape == (3, 1), right.shape
            return self.R * right + self.t
        elif isinstance(right, Pose3):
            return self.compose(right)
        else:
            raise NotImplementedError('Unsupported type: "{}"'.format(right))

    def to_homogenous_matrix(self):
        # type: () -> Matrix
        """
        4x4 matrix representing this pose transform.
        """
        R = self.R.to_rotation_matrix()
        return (R.row_join(self.t)).col_join(Matrix(1, 4, [0, 0, 0, 1]))