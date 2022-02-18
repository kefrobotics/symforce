# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     python_templates/ops/CLASS/group_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import numpy
import typing as T

import sym  # pylint: disable=unused-import


class GroupOps(object):
    """
    Python GroupOps implementation for <class 'symforce.geo.pose3.Pose3'>.
    """

    @staticmethod
    def identity():
        # type: () -> sym.Pose3

        # Total ops: 0

        # Input arrays

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 7
        _res[0] = 0
        _res[1] = 0
        _res[2] = 0
        _res[3] = 1
        _res[4] = 0
        _res[5] = 0
        _res[6] = 0
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def inverse(a):
        # type: (sym.Pose3) -> sym.Pose3

        # Total ops: 50

        # Input arrays
        _a = a.data

        # Intermediate terms (11)
        _tmp0 = -2 * _a[1] ** 2
        _tmp1 = 1 - 2 * _a[2] ** 2
        _tmp2 = 2 * _a[0]
        _tmp3 = _a[2] * _tmp2
        _tmp4 = 2 * _a[3]
        _tmp5 = _a[1] * _tmp4
        _tmp6 = _a[1] * _tmp2
        _tmp7 = _a[2] * _tmp4
        _tmp8 = -2 * _a[0] ** 2
        _tmp9 = 2 * _a[1] * _a[2]
        _tmp10 = _a[3] * _tmp2

        # Output terms
        _res = [0.0] * 7
        _res[0] = -_a[0]
        _res[1] = -_a[1]
        _res[2] = -_a[2]
        _res[3] = _a[3]
        _res[4] = -_a[4] * (_tmp0 + _tmp1) - _a[5] * (_tmp6 + _tmp7) - _a[6] * (_tmp3 - _tmp5)
        _res[5] = -_a[4] * (_tmp6 - _tmp7) - _a[5] * (_tmp1 + _tmp8) - _a[6] * (_tmp10 + _tmp9)
        _res[6] = -_a[4] * (_tmp3 + _tmp5) - _a[5] * (-_tmp10 + _tmp9) - _a[6] * (_tmp0 + _tmp8 + 1)
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def compose(a, b):
        # type: (sym.Pose3, sym.Pose3) -> sym.Pose3

        # Total ops: 79

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (11)
        _tmp0 = -2 * _a[2] ** 2
        _tmp1 = -2 * _a[1] ** 2
        _tmp2 = 2 * _a[0]
        _tmp3 = _a[2] * _tmp2
        _tmp4 = 2 * _a[3]
        _tmp5 = _a[1] * _tmp4
        _tmp6 = _a[1] * _tmp2
        _tmp7 = _a[2] * _tmp4
        _tmp8 = 1 - 2 * _a[0] ** 2
        _tmp9 = 2 * _a[1] * _a[2]
        _tmp10 = _a[3] * _tmp2

        # Output terms
        _res = [0.0] * 7
        _res[0] = _a[0] * _b[3] + _a[1] * _b[2] - _a[2] * _b[1] + _a[3] * _b[0]
        _res[1] = -_a[0] * _b[2] + _a[1] * _b[3] + _a[2] * _b[0] + _a[3] * _b[1]
        _res[2] = _a[0] * _b[1] - _a[1] * _b[0] + _a[2] * _b[3] + _a[3] * _b[2]
        _res[3] = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2] + _a[3] * _b[3]
        _res[4] = (
            _a[4] + _b[4] * (_tmp0 + _tmp1 + 1) + _b[5] * (_tmp6 - _tmp7) + _b[6] * (_tmp3 + _tmp5)
        )
        _res[5] = (
            _a[5] + _b[4] * (_tmp6 + _tmp7) + _b[5] * (_tmp0 + _tmp8) + _b[6] * (-_tmp10 + _tmp9)
        )
        _res[6] = (
            _a[6] + _b[4] * (_tmp3 - _tmp5) + _b[5] * (_tmp10 + _tmp9) + _b[6] * (_tmp1 + _tmp8)
        )
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def between(a, b):
        # type: (sym.Pose3, sym.Pose3) -> sym.Pose3

        # Total ops: 103

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (20)
        _tmp0 = -2 * _a[2] ** 2
        _tmp1 = 1 - 2 * _a[1] ** 2
        _tmp2 = _tmp0 + _tmp1
        _tmp3 = 2 * _a[0]
        _tmp4 = _a[2] * _tmp3
        _tmp5 = 2 * _a[3]
        _tmp6 = _a[1] * _tmp5
        _tmp7 = _tmp4 - _tmp6
        _tmp8 = _a[1] * _tmp3
        _tmp9 = _a[2] * _tmp5
        _tmp10 = _tmp8 + _tmp9
        _tmp11 = -2 * _a[0] ** 2
        _tmp12 = _tmp0 + _tmp11 + 1
        _tmp13 = 2 * _a[1] * _a[2]
        _tmp14 = _a[3] * _tmp3
        _tmp15 = _tmp13 + _tmp14
        _tmp16 = _tmp8 - _tmp9
        _tmp17 = _tmp1 + _tmp11
        _tmp18 = _tmp13 - _tmp14
        _tmp19 = _tmp4 + _tmp6

        # Output terms
        _res = [0.0] * 7
        _res[0] = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0]
        _res[1] = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1]
        _res[2] = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2]
        _res[3] = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3]
        _res[4] = (
            -_a[4] * _tmp2
            - _a[5] * _tmp10
            - _a[6] * _tmp7
            + _b[4] * _tmp2
            + _b[5] * _tmp10
            + _b[6] * _tmp7
        )
        _res[5] = (
            -_a[4] * _tmp16
            - _a[5] * _tmp12
            - _a[6] * _tmp15
            + _b[4] * _tmp16
            + _b[5] * _tmp12
            + _b[6] * _tmp15
        )
        _res[6] = (
            -_a[4] * _tmp19
            - _a[5] * _tmp18
            - _a[6] * _tmp17
            + _b[4] * _tmp19
            + _b[5] * _tmp18
            + _b[6] * _tmp17
        )
        return sym.Pose3.from_storage(_res)

    @staticmethod
    def inverse_with_jacobian(a):
        # type: (sym.Pose3) -> T.Tuple[sym.Pose3, numpy.ndarray]

        # Total ops: 128

        # Input arrays
        _a = a.data

        # Intermediate terms (48)
        _tmp0 = _a[2] ** 2
        _tmp1 = 2 * _tmp0
        _tmp2 = -_tmp1
        _tmp3 = _a[1] ** 2
        _tmp4 = 2 * _tmp3
        _tmp5 = -_tmp4
        _tmp6 = 2 * _a[0]
        _tmp7 = _a[2] * _tmp6
        _tmp8 = 2 * _a[3]
        _tmp9 = _a[1] * _tmp8
        _tmp10 = -_tmp9
        _tmp11 = _a[6] * (_tmp10 + _tmp7)
        _tmp12 = _a[1] * _tmp6
        _tmp13 = _a[2] * _tmp8
        _tmp14 = _a[5] * (_tmp12 + _tmp13)
        _tmp15 = _a[0] ** 2
        _tmp16 = 2 * _tmp15
        _tmp17 = 1 - _tmp16
        _tmp18 = 2 * _a[1] * _a[2]
        _tmp19 = _a[3] * _tmp6
        _tmp20 = _a[6] * (_tmp18 + _tmp19)
        _tmp21 = -_tmp13
        _tmp22 = _a[4] * (_tmp12 + _tmp21)
        _tmp23 = -_tmp19
        _tmp24 = _a[5] * (_tmp18 + _tmp23)
        _tmp25 = _a[4] * (_tmp7 + _tmp9)
        _tmp26 = _a[3] ** 2
        _tmp27 = -_tmp26
        _tmp28 = _tmp0 + _tmp27
        _tmp29 = -_tmp15
        _tmp30 = _tmp29 + _tmp3
        _tmp31 = _tmp28 + _tmp30
        _tmp32 = -_tmp12
        _tmp33 = _tmp13 + _tmp32
        _tmp34 = -_tmp7
        _tmp35 = _tmp10 + _tmp34
        _tmp36 = _tmp21 + _tmp32
        _tmp37 = -_tmp3
        _tmp38 = _tmp15 + _tmp37
        _tmp39 = _tmp28 + _tmp38
        _tmp40 = -_tmp18
        _tmp41 = _tmp19 + _tmp40
        _tmp42 = _tmp34 + _tmp9
        _tmp43 = _tmp23 + _tmp40
        _tmp44 = -_tmp0
        _tmp45 = _tmp15 + _tmp27 + _tmp3 + _tmp44
        _tmp46 = _tmp26 + _tmp44
        _tmp47 = _tmp16 - 1

        # Output terms
        _res = [0.0] * 7
        _res[0] = -_a[0]
        _res[1] = -_a[1]
        _res[2] = -_a[2]
        _res[3] = _a[3]
        _res[4] = -_a[4] * (_tmp2 + _tmp5 + 1) - _tmp11 - _tmp14
        _res[5] = -_a[5] * (_tmp17 + _tmp2) - _tmp20 - _tmp22
        _res[6] = -_a[6] * (_tmp17 + _tmp5) - _tmp24 - _tmp25
        _res_D_a = numpy.zeros((6, 6))
        _res_D_a[0, 0] = _tmp31
        _res_D_a[0, 1] = _tmp33
        _res_D_a[0, 2] = _tmp35
        _res_D_a[0, 3] = 0
        _res_D_a[0, 4] = 0
        _res_D_a[0, 5] = 0
        _res_D_a[1, 0] = _tmp36
        _res_D_a[1, 1] = _tmp39
        _res_D_a[1, 2] = _tmp41
        _res_D_a[1, 3] = 0
        _res_D_a[1, 4] = 0
        _res_D_a[1, 5] = 0
        _res_D_a[2, 0] = _tmp42
        _res_D_a[2, 1] = _tmp43
        _res_D_a[2, 2] = _tmp45
        _res_D_a[2, 3] = 0
        _res_D_a[2, 4] = 0
        _res_D_a[2, 5] = 0
        _res_D_a[3, 0] = 0
        _res_D_a[3, 1] = -_a[4] * _tmp35 - _a[5] * _tmp41 - _a[6] * _tmp45
        _res_D_a[3, 2] = -_a[5] * (_tmp30 + _tmp46) - _tmp20 - _tmp22
        _res_D_a[3, 3] = _tmp1 + _tmp4 - 1
        _res_D_a[3, 4] = _tmp36
        _res_D_a[3, 5] = _tmp42
        _res_D_a[4, 0] = -_a[6] * (_tmp0 + _tmp26 + _tmp29 + _tmp37) - _tmp24 - _tmp25
        _res_D_a[4, 1] = 0
        _res_D_a[4, 2] = -_a[4] * _tmp31 - _a[5] * _tmp36 - _a[6] * _tmp42
        _res_D_a[4, 3] = _tmp33
        _res_D_a[4, 4] = _tmp1 + _tmp47
        _res_D_a[4, 5] = _tmp43
        _res_D_a[5, 0] = -_a[4] * _tmp33 - _a[5] * _tmp39 - _a[6] * _tmp43
        _res_D_a[5, 1] = -_a[4] * (_tmp38 + _tmp46) - _tmp11 - _tmp14
        _res_D_a[5, 2] = 0
        _res_D_a[5, 3] = _tmp35
        _res_D_a[5, 4] = _tmp41
        _res_D_a[5, 5] = _tmp4 + _tmp47
        return sym.Pose3.from_storage(_res), _res_D_a

    @staticmethod
    def compose_with_jacobians(a, b):
        # type: (sym.Pose3, sym.Pose3) -> T.Tuple[sym.Pose3, numpy.ndarray, numpy.ndarray]

        # Total ops: 362

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (132)
        _tmp0 = _a[2] * _b[1]
        _tmp1 = _a[0] * _b[3]
        _tmp2 = _a[1] * _b[2]
        _tmp3 = _a[3] * _b[0]
        _tmp4 = -_tmp0 + _tmp1 + _tmp2 + _tmp3
        _tmp5 = _a[3] * _b[1]
        _tmp6 = _a[1] * _b[3]
        _tmp7 = _a[0] * _b[2]
        _tmp8 = _a[2] * _b[0]
        _tmp9 = _tmp5 + _tmp6 - _tmp7 + _tmp8
        _tmp10 = _a[0] * _b[1]
        _tmp11 = _a[2] * _b[3]
        _tmp12 = _a[3] * _b[2]
        _tmp13 = _a[1] * _b[0]
        _tmp14 = _tmp10 + _tmp11 + _tmp12 - _tmp13
        _tmp15 = _a[1] * _b[1]
        _tmp16 = _a[2] * _b[2]
        _tmp17 = _a[0] * _b[0]
        _tmp18 = _a[3] * _b[3]
        _tmp19 = -_tmp15 - _tmp16 - _tmp17 + _tmp18
        _tmp20 = _a[2] ** 2
        _tmp21 = -2 * _tmp20
        _tmp22 = _a[1] ** 2
        _tmp23 = -2 * _tmp22
        _tmp24 = _tmp21 + _tmp23 + 1
        _tmp25 = 2 * _a[0]
        _tmp26 = _a[2] * _tmp25
        _tmp27 = 2 * _a[3]
        _tmp28 = _a[1] * _tmp27
        _tmp29 = _tmp26 + _tmp28
        _tmp30 = _a[1] * _tmp25
        _tmp31 = _a[2] * _tmp27
        _tmp32 = -_tmp31
        _tmp33 = _tmp30 + _tmp32
        _tmp34 = _a[0] ** 2
        _tmp35 = 1 - 2 * _tmp34
        _tmp36 = _tmp21 + _tmp35
        _tmp37 = 2 * _a[1] * _a[2]
        _tmp38 = _a[0] * _tmp27
        _tmp39 = -_tmp38
        _tmp40 = _tmp37 + _tmp39
        _tmp41 = _tmp30 + _tmp31
        _tmp42 = _tmp23 + _tmp35
        _tmp43 = _tmp37 + _tmp38
        _tmp44 = -_tmp28
        _tmp45 = _tmp26 + _tmp44
        _tmp46 = (1.0 / 2.0) * _tmp10
        _tmp47 = -_tmp46
        _tmp48 = (1.0 / 2.0) * _tmp11
        _tmp49 = (1.0 / 2.0) * _tmp12
        _tmp50 = -_tmp49
        _tmp51 = (1.0 / 2.0) * _tmp13
        _tmp52 = -_tmp51
        _tmp53 = _tmp50 + _tmp52
        _tmp54 = _tmp47 + _tmp48 + _tmp53
        _tmp55 = 2 * _tmp14
        _tmp56 = (1.0 / 2.0) * _tmp6
        _tmp57 = -_tmp56
        _tmp58 = (1.0 / 2.0) * _tmp5
        _tmp59 = (1.0 / 2.0) * _tmp7
        _tmp60 = -_tmp59
        _tmp61 = (1.0 / 2.0) * _tmp8
        _tmp62 = -_tmp61
        _tmp63 = _tmp60 + _tmp62
        _tmp64 = _tmp57 + _tmp58 + _tmp63
        _tmp65 = 2 * _tmp9
        _tmp66 = (1.0 / 2.0) * _tmp1
        _tmp67 = -_tmp66
        _tmp68 = (1.0 / 2.0) * _tmp3
        _tmp69 = -_tmp68
        _tmp70 = _tmp67 + _tmp69
        _tmp71 = (1.0 / 2.0) * _tmp0
        _tmp72 = -_tmp71
        _tmp73 = (1.0 / 2.0) * _tmp2
        _tmp74 = _tmp72 + _tmp73
        _tmp75 = _tmp70 + _tmp74
        _tmp76 = 2 * _tmp4
        _tmp77 = (1.0 / 2.0) * _tmp15
        _tmp78 = (1.0 / 2.0) * _tmp16
        _tmp79 = (1.0 / 2.0) * _tmp18
        _tmp80 = (1.0 / 2.0) * _tmp17
        _tmp81 = _tmp79 - _tmp80
        _tmp82 = _tmp77 + _tmp78 + _tmp81
        _tmp83 = 2 * _tmp19
        _tmp84 = -_tmp77
        _tmp85 = _tmp79 + _tmp80
        _tmp86 = _tmp78 + _tmp84 + _tmp85
        _tmp87 = -_tmp73
        _tmp88 = _tmp72 + _tmp87
        _tmp89 = _tmp66 + _tmp69 + _tmp88
        _tmp90 = -_tmp58
        _tmp91 = _tmp57 + _tmp90
        _tmp92 = _tmp60 + _tmp61
        _tmp93 = _tmp91 + _tmp92
        _tmp94 = -_tmp48
        _tmp95 = _tmp47 + _tmp94
        _tmp96 = _tmp49 + _tmp52
        _tmp97 = _tmp95 + _tmp96
        _tmp98 = _tmp67 + _tmp68 + _tmp88
        _tmp99 = -_tmp78
        _tmp100 = _tmp77 + _tmp85 + _tmp99
        _tmp101 = _tmp46 + _tmp53 + _tmp94
        _tmp102 = _tmp56 + _tmp63 + _tmp90
        _tmp103 = -_tmp30
        _tmp104 = -_tmp22
        _tmp105 = _tmp104 + _tmp34
        _tmp106 = -_tmp20
        _tmp107 = _a[3] ** 2
        _tmp108 = _tmp106 + _tmp107
        _tmp109 = -_tmp26
        _tmp110 = -_tmp107
        _tmp111 = _tmp110 + _tmp20
        _tmp112 = -_tmp34
        _tmp113 = _tmp112 + _tmp22
        _tmp114 = -_tmp37
        _tmp115 = _tmp46 + _tmp48 + _tmp96
        _tmp116 = _tmp70 + _tmp71 + _tmp87
        _tmp117 = -_tmp116 * _tmp76
        _tmp118 = _tmp59 + _tmp62 + _tmp91
        _tmp119 = _tmp81 + _tmp84 + _tmp99
        _tmp120 = _tmp119 * _tmp83
        _tmp121 = -_tmp118 * _tmp65 + _tmp120
        _tmp122 = _tmp119 * _tmp55
        _tmp123 = _tmp66 + _tmp68 + _tmp74
        _tmp124 = _tmp118 * _tmp76
        _tmp125 = _tmp50 + _tmp51 + _tmp95
        _tmp126 = _tmp116 * _tmp55
        _tmp127 = _tmp119 * _tmp65
        _tmp128 = _tmp56 + _tmp58 + _tmp92
        _tmp129 = -_tmp125 * _tmp55
        _tmp130 = _tmp125 * _tmp65
        _tmp131 = _tmp119 * _tmp76

        # Output terms
        _res = [0.0] * 7
        _res[0] = _tmp4
        _res[1] = _tmp9
        _res[2] = _tmp14
        _res[3] = _tmp19
        _res[4] = _a[4] + _b[4] * _tmp24 + _b[5] * _tmp33 + _b[6] * _tmp29
        _res[5] = _a[5] + _b[4] * _tmp41 + _b[5] * _tmp36 + _b[6] * _tmp40
        _res[6] = _a[6] + _b[4] * _tmp45 + _b[5] * _tmp43 + _b[6] * _tmp42
        _res_D_a = numpy.zeros((6, 6))
        _res_D_a[0, 0] = _tmp54 * _tmp55 - _tmp64 * _tmp65 - _tmp75 * _tmp76 + _tmp82 * _tmp83
        _res_D_a[0, 1] = _tmp55 * _tmp86 - _tmp65 * _tmp89 - _tmp76 * _tmp93 + _tmp83 * _tmp97
        _res_D_a[0, 2] = -_tmp100 * _tmp65 - _tmp101 * _tmp76 + _tmp102 * _tmp83 + _tmp55 * _tmp98
        _res_D_a[0, 3] = 0
        _res_D_a[0, 4] = 0
        _res_D_a[0, 5] = 0
        _res_D_a[1, 0] = _tmp54 * _tmp83 - _tmp55 * _tmp82 + _tmp64 * _tmp76 - _tmp65 * _tmp75
        _res_D_a[1, 1] = -_tmp55 * _tmp97 - _tmp65 * _tmp93 + _tmp76 * _tmp89 + _tmp83 * _tmp86
        _res_D_a[1, 2] = _tmp100 * _tmp76 - _tmp101 * _tmp65 - _tmp102 * _tmp55 + _tmp83 * _tmp98
        _res_D_a[1, 3] = 0
        _res_D_a[1, 4] = 0
        _res_D_a[1, 5] = 0
        _res_D_a[2, 0] = -_tmp54 * _tmp76 - _tmp55 * _tmp75 + _tmp64 * _tmp83 + _tmp65 * _tmp82
        _res_D_a[2, 1] = -_tmp55 * _tmp93 + _tmp65 * _tmp97 - _tmp76 * _tmp86 + _tmp83 * _tmp89
        _res_D_a[2, 2] = _tmp100 * _tmp83 - _tmp101 * _tmp55 + _tmp102 * _tmp65 - _tmp76 * _tmp98
        _res_D_a[2, 3] = 0
        _res_D_a[2, 4] = 0
        _res_D_a[2, 5] = 0
        _res_D_a[3, 0] = _b[5] * _tmp29 + _b[6] * (_tmp103 + _tmp31)
        _res_D_a[3, 1] = _b[4] * (_tmp109 + _tmp44) + _b[6] * (_tmp105 + _tmp108)
        _res_D_a[3, 2] = _b[4] * _tmp33 + _b[5] * (_tmp111 + _tmp113)
        _res_D_a[3, 3] = 1
        _res_D_a[3, 4] = 0
        _res_D_a[3, 5] = 0
        _res_D_a[4, 0] = _b[5] * _tmp40 + _b[6] * (_tmp105 + _tmp111)
        _res_D_a[4, 1] = _b[4] * (_tmp114 + _tmp38) + _b[6] * _tmp41
        _res_D_a[4, 2] = _b[4] * (_tmp108 + _tmp113) + _b[5] * (_tmp103 + _tmp32)
        _res_D_a[4, 3] = 0
        _res_D_a[4, 4] = 1
        _res_D_a[4, 5] = 0
        _res_D_a[5, 0] = _b[5] * (_tmp104 + _tmp107 + _tmp112 + _tmp20) + _b[6] * (_tmp114 + _tmp39)
        _res_D_a[5, 1] = _b[4] * (_tmp106 + _tmp110 + _tmp22 + _tmp34) + _b[6] * _tmp45
        _res_D_a[5, 2] = _b[4] * _tmp43 + _b[5] * (_tmp109 + _tmp28)
        _res_D_a[5, 3] = 0
        _res_D_a[5, 4] = 0
        _res_D_a[5, 5] = 1
        _res_D_b = numpy.zeros((6, 6))
        _res_D_b[0, 0] = _tmp115 * _tmp55 + _tmp117 + _tmp121
        _res_D_b[0, 1] = _tmp122 - _tmp123 * _tmp65 - _tmp124 + _tmp125 * _tmp83
        _res_D_b[0, 2] = -_tmp125 * _tmp76 + _tmp126 - _tmp127 + _tmp128 * _tmp83
        _res_D_b[0, 3] = 0
        _res_D_b[0, 4] = 0
        _res_D_b[0, 5] = 0
        _res_D_b[1, 0] = _tmp115 * _tmp83 - _tmp116 * _tmp65 - _tmp122 + _tmp124
        _res_D_b[1, 1] = _tmp121 + _tmp123 * _tmp76 + _tmp129
        _res_D_b[1, 2] = _tmp116 * _tmp83 - _tmp128 * _tmp55 - _tmp130 + _tmp131
        _res_D_b[1, 3] = 0
        _res_D_b[1, 4] = 0
        _res_D_b[1, 5] = 0
        _res_D_b[2, 0] = -_tmp115 * _tmp76 + _tmp118 * _tmp83 - _tmp126 + _tmp127
        _res_D_b[2, 1] = -_tmp118 * _tmp55 + _tmp123 * _tmp83 + _tmp130 - _tmp131
        _res_D_b[2, 2] = _tmp117 + _tmp120 + _tmp128 * _tmp65 + _tmp129
        _res_D_b[2, 3] = 0
        _res_D_b[2, 4] = 0
        _res_D_b[2, 5] = 0
        _res_D_b[3, 0] = 0
        _res_D_b[3, 1] = 0
        _res_D_b[3, 2] = 0
        _res_D_b[3, 3] = _tmp24
        _res_D_b[3, 4] = _tmp33
        _res_D_b[3, 5] = _tmp29
        _res_D_b[4, 0] = 0
        _res_D_b[4, 1] = 0
        _res_D_b[4, 2] = 0
        _res_D_b[4, 3] = _tmp41
        _res_D_b[4, 4] = _tmp36
        _res_D_b[4, 5] = _tmp40
        _res_D_b[5, 0] = 0
        _res_D_b[5, 1] = 0
        _res_D_b[5, 2] = 0
        _res_D_b[5, 3] = _tmp45
        _res_D_b[5, 4] = _tmp43
        _res_D_b[5, 5] = _tmp42
        return sym.Pose3.from_storage(_res), _res_D_a, _res_D_b

    @staticmethod
    def between_with_jacobians(a, b):
        # type: (sym.Pose3, sym.Pose3) -> T.Tuple[sym.Pose3, numpy.ndarray, numpy.ndarray]

        # Total ops: 373

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (144)
        _tmp0 = _a[2] * _b[1]
        _tmp1 = _a[0] * _b[3]
        _tmp2 = _a[1] * _b[2]
        _tmp3 = _a[3] * _b[0]
        _tmp4 = _tmp0 - _tmp1 - _tmp2 + _tmp3
        _tmp5 = _a[3] * _b[1]
        _tmp6 = _a[1] * _b[3]
        _tmp7 = _a[0] * _b[2]
        _tmp8 = _a[2] * _b[0]
        _tmp9 = _tmp5 - _tmp6 + _tmp7 - _tmp8
        _tmp10 = _a[0] * _b[1]
        _tmp11 = _a[2] * _b[3]
        _tmp12 = _a[3] * _b[2]
        _tmp13 = _a[1] * _b[0]
        _tmp14 = -_tmp10 - _tmp11 + _tmp12 + _tmp13
        _tmp15 = _a[1] * _b[1]
        _tmp16 = _a[2] * _b[2]
        _tmp17 = _a[0] * _b[0]
        _tmp18 = _a[3] * _b[3]
        _tmp19 = _tmp15 + _tmp16 + _tmp17 + _tmp18
        _tmp20 = _a[2] ** 2
        _tmp21 = 2 * _tmp20
        _tmp22 = -_tmp21
        _tmp23 = _a[1] ** 2
        _tmp24 = 2 * _tmp23
        _tmp25 = -_tmp24
        _tmp26 = _tmp22 + _tmp25 + 1
        _tmp27 = 2 * _a[2]
        _tmp28 = _a[0] * _tmp27
        _tmp29 = 2 * _a[1]
        _tmp30 = _a[3] * _tmp29
        _tmp31 = -_tmp30
        _tmp32 = _tmp28 + _tmp31
        _tmp33 = _a[6] * _tmp32
        _tmp34 = _a[0] * _tmp29
        _tmp35 = _a[3] * _tmp27
        _tmp36 = _tmp34 + _tmp35
        _tmp37 = _a[5] * _tmp36
        _tmp38 = _b[5] * _tmp36 + _b[6] * _tmp32
        _tmp39 = _a[0] ** 2
        _tmp40 = 2 * _tmp39
        _tmp41 = 1 - _tmp40
        _tmp42 = _tmp22 + _tmp41
        _tmp43 = _a[2] * _tmp29
        _tmp44 = 2 * _a[0] * _a[3]
        _tmp45 = _tmp43 + _tmp44
        _tmp46 = _a[6] * _tmp45
        _tmp47 = -_tmp35
        _tmp48 = _tmp34 + _tmp47
        _tmp49 = _a[4] * _tmp48
        _tmp50 = _b[4] * _tmp48 + _b[6] * _tmp45
        _tmp51 = _tmp25 + _tmp41
        _tmp52 = -_tmp44
        _tmp53 = _tmp43 + _tmp52
        _tmp54 = _a[5] * _tmp53
        _tmp55 = _tmp28 + _tmp30
        _tmp56 = _a[4] * _tmp55
        _tmp57 = _b[4] * _tmp55 + _b[5] * _tmp53
        _tmp58 = (1.0 / 2.0) * _tmp15
        _tmp59 = (1.0 / 2.0) * _tmp18
        _tmp60 = (1.0 / 2.0) * _tmp16
        _tmp61 = (1.0 / 2.0) * _tmp17
        _tmp62 = -_tmp58 - _tmp59 - _tmp60 - _tmp61
        _tmp63 = 2 * _tmp19
        _tmp64 = _tmp62 * _tmp63
        _tmp65 = (1.0 / 2.0) * _tmp0
        _tmp66 = (1.0 / 2.0) * _tmp1
        _tmp67 = (1.0 / 2.0) * _tmp2
        _tmp68 = (1.0 / 2.0) * _tmp3
        _tmp69 = _tmp65 - _tmp66 - _tmp67 + _tmp68
        _tmp70 = 2 * _tmp4
        _tmp71 = _tmp69 * _tmp70
        _tmp72 = (1.0 / 2.0) * _tmp5
        _tmp73 = (1.0 / 2.0) * _tmp6
        _tmp74 = (1.0 / 2.0) * _tmp7
        _tmp75 = (1.0 / 2.0) * _tmp8
        _tmp76 = -_tmp72 + _tmp73 - _tmp74 + _tmp75
        _tmp77 = 2 * _tmp9
        _tmp78 = -_tmp76 * _tmp77
        _tmp79 = (1.0 / 2.0) * _tmp10
        _tmp80 = (1.0 / 2.0) * _tmp11
        _tmp81 = (1.0 / 2.0) * _tmp12
        _tmp82 = (1.0 / 2.0) * _tmp13
        _tmp83 = -_tmp79 - _tmp80 + _tmp81 + _tmp82
        _tmp84 = 2 * _tmp83
        _tmp85 = _tmp14 * _tmp84
        _tmp86 = _tmp78 + _tmp85
        _tmp87 = 2 * _tmp14
        _tmp88 = _tmp62 * _tmp87
        _tmp89 = _tmp72 - _tmp73 + _tmp74 - _tmp75
        _tmp90 = 2 * _tmp89
        _tmp91 = -_tmp69 * _tmp77
        _tmp92 = _tmp79 + _tmp80 - _tmp81 - _tmp82
        _tmp93 = _tmp63 * _tmp92 + _tmp91
        _tmp94 = -_tmp4 * _tmp84
        _tmp95 = _tmp62 * _tmp77
        _tmp96 = -_tmp65 + _tmp66 + _tmp67 - _tmp68
        _tmp97 = _tmp87 * _tmp96
        _tmp98 = _tmp63 * _tmp89 + _tmp97
        _tmp99 = _tmp70 * _tmp76
        _tmp100 = _tmp63 * _tmp83 + _tmp99
        _tmp101 = 2 * _tmp92
        _tmp102 = -_tmp101 * _tmp14
        _tmp103 = _tmp9 * _tmp90
        _tmp104 = _tmp62 * _tmp70
        _tmp105 = -_tmp14 * _tmp90
        _tmp106 = _tmp105 + _tmp63 * _tmp96
        _tmp107 = _tmp63 * _tmp76 + _tmp94
        _tmp108 = _tmp101 * _tmp9
        _tmp109 = _tmp108 + _tmp63 * _tmp69
        _tmp110 = -_tmp70 * _tmp96
        _tmp111 = _tmp103 + _tmp110
        _tmp112 = -_tmp20
        _tmp113 = _a[3] ** 2
        _tmp114 = -_tmp113
        _tmp115 = _tmp112 + _tmp114 + _tmp23 + _tmp39
        _tmp116 = -_tmp43
        _tmp117 = _tmp116 + _tmp44
        _tmp118 = -_tmp28
        _tmp119 = _tmp118 + _tmp31
        _tmp120 = _tmp112 + _tmp113
        _tmp121 = -_tmp39
        _tmp122 = _tmp121 + _tmp23
        _tmp123 = _tmp120 + _tmp122
        _tmp124 = -_tmp34
        _tmp125 = _tmp124 + _tmp47
        _tmp126 = _tmp118 + _tmp30
        _tmp127 = -_tmp23
        _tmp128 = _tmp113 + _tmp121 + _tmp127 + _tmp20
        _tmp129 = _tmp114 + _tmp20
        _tmp130 = _tmp122 + _tmp129
        _tmp131 = _tmp124 + _tmp35
        _tmp132 = _tmp40 - 1
        _tmp133 = _tmp116 + _tmp52
        _tmp134 = _tmp127 + _tmp39
        _tmp135 = _tmp129 + _tmp134
        _tmp136 = _tmp120 + _tmp134
        _tmp137 = _tmp58 + _tmp59 + _tmp60 + _tmp61
        _tmp138 = _tmp137 * _tmp63
        _tmp139 = 2 * _tmp137
        _tmp140 = _tmp139 * _tmp14
        _tmp141 = _tmp137 * _tmp77
        _tmp142 = _tmp102 + _tmp138
        _tmp143 = _tmp139 * _tmp4

        # Output terms
        _res = [0.0] * 7
        _res[0] = _tmp4
        _res[1] = _tmp9
        _res[2] = _tmp14
        _res[3] = _tmp19
        _res[4] = -_a[4] * _tmp26 + _b[4] * _tmp26 - _tmp33 - _tmp37 + _tmp38
        _res[5] = -_a[5] * _tmp42 + _b[5] * _tmp42 - _tmp46 - _tmp49 + _tmp50
        _res[6] = -_a[6] * _tmp51 + _b[6] * _tmp51 - _tmp54 - _tmp56 + _tmp57
        _res_D_a = numpy.zeros((6, 6))
        _res_D_a[0, 0] = _tmp64 - _tmp71 + _tmp86
        _res_D_a[0, 1] = -_tmp4 * _tmp90 + _tmp88 + _tmp93
        _res_D_a[0, 2] = _tmp94 - _tmp95 + _tmp98
        _res_D_a[0, 3] = 0
        _res_D_a[0, 4] = 0
        _res_D_a[0, 5] = 0
        _res_D_a[1, 0] = _tmp100 - _tmp88 + _tmp91
        _res_D_a[1, 1] = _tmp102 - _tmp103 + _tmp64 + _tmp71
        _res_D_a[1, 2] = _tmp104 + _tmp106 - _tmp84 * _tmp9
        _res_D_a[1, 3] = 0
        _res_D_a[1, 4] = 0
        _res_D_a[1, 5] = 0
        _res_D_a[2, 0] = _tmp107 - _tmp69 * _tmp87 + _tmp95
        _res_D_a[2, 1] = -_tmp104 + _tmp105 + _tmp109
        _res_D_a[2, 2] = _tmp111 + _tmp64 - _tmp85
        _res_D_a[2, 3] = 0
        _res_D_a[2, 4] = 0
        _res_D_a[2, 5] = 0
        _res_D_a[3, 0] = 0
        _res_D_a[3, 1] = (
            -_a[4] * _tmp119
            - _a[5] * _tmp117
            - _a[6] * _tmp115
            + _b[4] * _tmp119
            + _b[5] * _tmp117
            + _b[6] * _tmp115
        )
        _res_D_a[3, 2] = -_a[5] * _tmp123 + _b[5] * _tmp123 - _tmp46 - _tmp49 + _tmp50
        _res_D_a[3, 3] = _tmp21 + _tmp24 - 1
        _res_D_a[3, 4] = _tmp125
        _res_D_a[3, 5] = _tmp126
        _res_D_a[4, 0] = -_a[6] * _tmp128 + _b[6] * _tmp128 - _tmp54 - _tmp56 + _tmp57
        _res_D_a[4, 1] = 0
        _res_D_a[4, 2] = (
            -_a[4] * _tmp130
            - _a[5] * _tmp125
            - _a[6] * _tmp126
            + _b[4] * _tmp130
            + _b[5] * _tmp125
            + _b[6] * _tmp126
        )
        _res_D_a[4, 3] = _tmp131
        _res_D_a[4, 4] = _tmp132 + _tmp21
        _res_D_a[4, 5] = _tmp133
        _res_D_a[5, 0] = (
            -_a[4] * _tmp131
            - _a[5] * _tmp135
            - _a[6] * _tmp133
            + _b[4] * _tmp131
            + _b[5] * _tmp135
            + _b[6] * _tmp133
        )
        _res_D_a[5, 1] = -_a[4] * _tmp136 + _b[4] * _tmp136 - _tmp33 - _tmp37 + _tmp38
        _res_D_a[5, 2] = 0
        _res_D_a[5, 3] = _tmp119
        _res_D_a[5, 4] = _tmp117
        _res_D_a[5, 5] = _tmp132 + _tmp24
        _res_D_b = numpy.zeros((6, 6))
        _res_D_b[0, 0] = _tmp110 + _tmp138 + _tmp86
        _res_D_b[0, 1] = _tmp140 + _tmp93 - _tmp99
        _res_D_b[0, 2] = -_tmp101 * _tmp4 - _tmp141 + _tmp98
        _res_D_b[0, 3] = 0
        _res_D_b[0, 4] = 0
        _res_D_b[0, 5] = 0
        _res_D_b[1, 0] = _tmp100 - _tmp140 - _tmp77 * _tmp96
        _res_D_b[1, 1] = _tmp142 + _tmp71 + _tmp78
        _res_D_b[1, 2] = _tmp106 - _tmp108 + _tmp143
        _res_D_b[1, 3] = 0
        _res_D_b[1, 4] = 0
        _res_D_b[1, 5] = 0
        _res_D_b[2, 0] = _tmp107 + _tmp141 - _tmp97
        _res_D_b[2, 1] = _tmp109 - _tmp143 - _tmp76 * _tmp87
        _res_D_b[2, 2] = _tmp111 + _tmp142
        _res_D_b[2, 3] = 0
        _res_D_b[2, 4] = 0
        _res_D_b[2, 5] = 0
        _res_D_b[3, 0] = 0
        _res_D_b[3, 1] = 0
        _res_D_b[3, 2] = 0
        _res_D_b[3, 3] = _tmp26
        _res_D_b[3, 4] = _tmp36
        _res_D_b[3, 5] = _tmp32
        _res_D_b[4, 0] = 0
        _res_D_b[4, 1] = 0
        _res_D_b[4, 2] = 0
        _res_D_b[4, 3] = _tmp48
        _res_D_b[4, 4] = _tmp42
        _res_D_b[4, 5] = _tmp45
        _res_D_b[5, 0] = 0
        _res_D_b[5, 1] = 0
        _res_D_b[5, 2] = 0
        _res_D_b[5, 3] = _tmp55
        _res_D_b[5, 4] = _tmp53
        _res_D_b[5, 5] = _tmp51
        return sym.Pose3.from_storage(_res), _res_D_a, _res_D_b
