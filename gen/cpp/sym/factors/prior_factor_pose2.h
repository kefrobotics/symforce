// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/pose2.h>

namespace sym {

/**
 * Residual that penalizes the difference between a value and prior (desired / measured value).
 *
 * In vector space terms that would be:
 *     prior - value
 *
 * In lie group terms:
 *     to_tangent(compose(inverse(value), prior))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *
 */
template <typename Scalar>
void PriorFactorPose2(const geo::Pose2<Scalar>& value, const geo::Pose2<Scalar>& prior,
                      const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                      Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                      Eigen::Matrix<Scalar, 3, 3>* const jac = nullptr) {
  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _prior = prior.Data();

  // Intermediate terms (50)
  const Scalar _tmp0 = 1.0 / ((_prior[0] * _prior[0]) + (_prior[1] * _prior[1]));
  const Scalar _tmp1 = _prior[0] * _tmp0;
  const Scalar _tmp2 = _prior[1] * _tmp0;
  const Scalar _tmp3 = _tmp1 * _value[1] - _tmp2 * _value[0];
  const Scalar _tmp4 = _tmp1 * _value[0] + _tmp2 * _value[1];
  const Scalar _tmp5 = std::atan2(_tmp3, _tmp4);
  const Scalar _tmp6 =
      _prior[2] * _tmp2 - _prior[3] * _tmp1 + _tmp1 * _value[3] - _tmp2 * _value[2];
  const Scalar _tmp7 =
      0.5 * _tmp5 + 0.5 * epsilon * (2 * std::min<Scalar>(0, (((_tmp5) > 0) - ((_tmp5) < 0))) + 1);
  const Scalar _tmp8 = _tmp6 * _tmp7;
  const Scalar _tmp9 = _tmp4 + 1;
  const Scalar _tmp10 =
      _tmp3 + epsilon * (2 * std::min<Scalar>(0, (((_tmp3) > 0) - ((_tmp3) < 0))) + 1);
  const Scalar _tmp11 = 1.0 / (_tmp10);
  const Scalar _tmp12 = _tmp11 * _tmp9;
  const Scalar _tmp13 =
      -_prior[2] * _tmp1 - _prior[3] * _tmp2 + _tmp1 * _value[2] + _tmp2 * _value[3];
  const Scalar _tmp14 = _tmp13 * _tmp7;
  const Scalar _tmp15 = _tmp12 * _tmp8 - _tmp14;
  const Scalar _tmp16 = _tmp12 * _tmp14 + _tmp8;
  const Scalar _tmp17 = _tmp2 * _tmp7;
  const Scalar _tmp18 = _tmp12 * _tmp17;
  const Scalar _tmp19 = _tmp1 * _tmp7;
  const Scalar _tmp20 = _tmp18 + _tmp19;
  const Scalar _tmp21 = _tmp12 * _tmp19 - _tmp17;
  const Scalar _tmp22 = _tmp20 * sqrt_info(0, 0) + _tmp21 * sqrt_info(0, 1);
  const Scalar _tmp23 = -_tmp18 - _tmp19;
  const Scalar _tmp24 = _tmp21 * sqrt_info(0, 0) + _tmp23 * sqrt_info(0, 1);
  const Scalar _tmp25 = 1.0 / (_tmp4);
  const Scalar _tmp26 = (_tmp4 * _tmp4);
  const Scalar _tmp27 = _tmp3 / _tmp26;
  const Scalar _tmp28 = _tmp26 / (_tmp26 + (_tmp3 * _tmp3));
  const Scalar _tmp29 = _tmp28 * (_tmp1 * _tmp25 - _tmp2 * _tmp27);
  const Scalar _tmp30 = 0.5 * _tmp29;
  const Scalar _tmp31 = _tmp13 * _tmp30;
  const Scalar _tmp32 = _tmp11 * _tmp2;
  const Scalar _tmp33 = _tmp9 / (_tmp10 * _tmp10);
  const Scalar _tmp34 = _tmp33 * _tmp8;
  const Scalar _tmp35 = _tmp30 * _tmp6;
  const Scalar _tmp36 = -_tmp1 * _tmp34 + _tmp12 * _tmp35 - _tmp31 + _tmp32 * _tmp8;
  const Scalar _tmp37 = _tmp14 * _tmp33;
  const Scalar _tmp38 = -_tmp1 * _tmp37 + _tmp12 * _tmp31 + _tmp14 * _tmp32 + _tmp35;
  const Scalar _tmp39 = _tmp1 * _tmp11;
  const Scalar _tmp40 = _tmp28 * (-_tmp1 * _tmp27 - _tmp2 * _tmp25);
  const Scalar _tmp41 = 0.5 * _tmp40;
  const Scalar _tmp42 = _tmp13 * _tmp41;
  const Scalar _tmp43 = _tmp41 * _tmp6;
  const Scalar _tmp44 = _tmp12 * _tmp42 + _tmp14 * _tmp39 + _tmp2 * _tmp37 + _tmp43;
  const Scalar _tmp45 = _tmp12 * _tmp43 + _tmp2 * _tmp34 + _tmp39 * _tmp8 - _tmp42;
  const Scalar _tmp46 = _tmp20 * sqrt_info(1, 0) + _tmp21 * sqrt_info(1, 1);
  const Scalar _tmp47 = _tmp21 * sqrt_info(1, 0) + _tmp23 * sqrt_info(1, 1);
  const Scalar _tmp48 = _tmp20 * sqrt_info(2, 0) + _tmp21 * sqrt_info(2, 1);
  const Scalar _tmp49 = _tmp21 * sqrt_info(2, 0) + _tmp23 * sqrt_info(2, 1);

  // Output terms (2)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp15 * sqrt_info(0, 1) + _tmp16 * sqrt_info(0, 0) + _tmp5 * sqrt_info(0, 2);
    _res(1, 0) = _tmp15 * sqrt_info(1, 1) + _tmp16 * sqrt_info(1, 0) + _tmp5 * sqrt_info(1, 2);
    _res(2, 0) = _tmp15 * sqrt_info(2, 1) + _tmp16 * sqrt_info(2, 0) + _tmp5 * sqrt_info(2, 2);
  }

  if (jac != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _jac = (*jac);

    _jac(0, 0) = _tmp22 * _value[1] + _tmp24 * _value[0];
    _jac(0, 1) = _tmp22 * _value[0] - _tmp24 * _value[1];
    _jac(0, 2) =
        _value[0] *
            (_tmp29 * sqrt_info(0, 2) + _tmp36 * sqrt_info(0, 1) + _tmp38 * sqrt_info(0, 0)) -
        _value[1] *
            (_tmp40 * sqrt_info(0, 2) + _tmp44 * sqrt_info(0, 0) + _tmp45 * sqrt_info(0, 1));
    _jac(1, 0) = _tmp46 * _value[1] + _tmp47 * _value[0];
    _jac(1, 1) = _tmp46 * _value[0] - _tmp47 * _value[1];
    _jac(1, 2) =
        _value[0] *
            (_tmp29 * sqrt_info(1, 2) + _tmp36 * sqrt_info(1, 1) + _tmp38 * sqrt_info(1, 0)) -
        _value[1] *
            (_tmp40 * sqrt_info(1, 2) + _tmp44 * sqrt_info(1, 0) + _tmp45 * sqrt_info(1, 1));
    _jac(2, 0) = _tmp48 * _value[1] + _tmp49 * _value[0];
    _jac(2, 1) = _tmp48 * _value[0] - _tmp49 * _value[1];
    _jac(2, 2) =
        _value[0] *
            (_tmp29 * sqrt_info(2, 2) + _tmp36 * sqrt_info(2, 1) + _tmp38 * sqrt_info(2, 0)) -
        _value[1] *
            (_tmp40 * sqrt_info(2, 2) + _tmp44 * sqrt_info(2, 0) + _tmp45 * sqrt_info(2, 1));
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
