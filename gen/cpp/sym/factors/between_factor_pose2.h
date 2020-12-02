// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/pose2.h>

namespace sym {

/**
 * Residual that penalizes the difference between between(a, b) and a_T_b.
 *
 * In vector space terms that would be:
 *     (b - a) - a_T_b
 *
 * In lie group terms:
 *     local_coordinates(a_T_b, between(a, b))
 *     to_tangent(compose(inverse(a_T_b), compose(inverse(a), b)))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *
 */
template <typename Scalar>
void BetweenFactorPose2(const geo::Pose2<Scalar>& a, const geo::Pose2<Scalar>& b,
                        const geo::Pose2<Scalar>& a_T_b,
                        const Eigen::Matrix<Scalar, 3, 3>& sqrt_info, const Scalar epsilon,
                        Eigen::Matrix<Scalar, 3, 1>* const res = nullptr,
                        Eigen::Matrix<Scalar, 3, 6>* const jac = nullptr) {
  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _a_T_b = a_T_b.Data();

  // Intermediate terms (131)
  const Scalar _tmp0 = (_a[1] * _a[1]);
  const Scalar _tmp1 = (_a[0] * _a[0]);
  const Scalar _tmp2 = _tmp0 + _tmp1;
  const Scalar _tmp3 = 1.0 / (_tmp2);
  const Scalar _tmp4 = _b[1] * _tmp3;
  const Scalar _tmp5 = _b[0] * _tmp3;
  const Scalar _tmp6 = _a[0] * _tmp4 - _a[1] * _tmp5;
  const Scalar _tmp7 = 1.0 / ((_a_T_b[0] * _a_T_b[0]) + (_a_T_b[1] * _a_T_b[1]));
  const Scalar _tmp8 = _a_T_b[0] * _tmp7;
  const Scalar _tmp9 = _a[0] * _tmp5 + _a[1] * _tmp4;
  const Scalar _tmp10 = _a_T_b[1] * _tmp7;
  const Scalar _tmp11 = -_tmp10 * _tmp9 + _tmp6 * _tmp8;
  const Scalar _tmp12 = _tmp10 * _tmp6 + _tmp8 * _tmp9;
  const Scalar _tmp13 = std::atan2(_tmp11, _tmp12);
  const Scalar _tmp14 = _a[3] * _tmp3;
  const Scalar _tmp15 = _a[2] * _tmp3;
  const Scalar _tmp16 = _b[3] * _tmp3;
  const Scalar _tmp17 = _b[2] * _tmp3;
  const Scalar _tmp18 = -_a[0] * _tmp14 + _a[0] * _tmp16 + _a[1] * _tmp15 - _a[1] * _tmp17;
  const Scalar _tmp19 = -_a[0] * _tmp15 + _a[0] * _tmp17 - _a[1] * _tmp14 + _a[1] * _tmp16;
  const Scalar _tmp20 = _a_T_b[2] * _tmp10 - _a_T_b[3] * _tmp8 - _tmp10 * _tmp19 + _tmp18 * _tmp8;
  const Scalar _tmp21 =
      0.5 * _tmp13 +
      0.5 * epsilon * (2 * std::min<Scalar>(0, (((_tmp13) > 0) - ((_tmp13) < 0))) + 1);
  const Scalar _tmp22 = _tmp20 * _tmp21;
  const Scalar _tmp23 =
      _tmp11 + epsilon * (2 * std::min<Scalar>(0, (((_tmp11) > 0) - ((_tmp11) < 0))) + 1);
  const Scalar _tmp24 = 1.0 / (_tmp23);
  const Scalar _tmp25 = _tmp12 + 1;
  const Scalar _tmp26 = _tmp24 * _tmp25;
  const Scalar _tmp27 = -_a_T_b[2] * _tmp8 - _a_T_b[3] * _tmp10 + _tmp10 * _tmp18 + _tmp19 * _tmp8;
  const Scalar _tmp28 = _tmp21 * _tmp27;
  const Scalar _tmp29 = _tmp22 * _tmp26 - _tmp28;
  const Scalar _tmp30 = _tmp22 + _tmp26 * _tmp28;
  const Scalar _tmp31 = _a[0] * _tmp3;
  const Scalar _tmp32 = _tmp10 * _tmp31;
  const Scalar _tmp33 = _a[1] * _tmp3;
  const Scalar _tmp34 = _tmp33 * _tmp8;
  const Scalar _tmp35 = -_tmp32 - _tmp34;
  const Scalar _tmp36 = _tmp21 * _tmp35;
  const Scalar _tmp37 = _tmp26 * _tmp36;
  const Scalar _tmp38 = _tmp10 * _tmp33;
  const Scalar _tmp39 = _tmp31 * _tmp8;
  const Scalar _tmp40 = _tmp21 * (_tmp38 - _tmp39);
  const Scalar _tmp41 = _tmp37 + _tmp40;
  const Scalar _tmp42 = _tmp26 * _tmp40;
  const Scalar _tmp43 = -_tmp36 + _tmp42;
  const Scalar _tmp44 = _tmp41 * sqrt_info(0, 0) + _tmp43 * sqrt_info(0, 1);
  const Scalar _tmp45 = _tmp32 + _tmp34;
  const Scalar _tmp46 = _tmp21 * _tmp45;
  const Scalar _tmp47 = _tmp42 + _tmp46;
  const Scalar _tmp48 = _tmp26 * _tmp46;
  const Scalar _tmp49 = -_tmp40 + _tmp48;
  const Scalar _tmp50 = _tmp47 * sqrt_info(0, 0) + _tmp49 * sqrt_info(0, 1);
  const Scalar _tmp51 = 2 / (_tmp2 * _tmp2);
  const Scalar _tmp52 = _tmp0 * _tmp51;
  const Scalar _tmp53 = _a[0] * _a[1] * _tmp51;
  const Scalar _tmp54 = _b[0] * _tmp53;
  const Scalar _tmp55 = -_b[1] * _tmp52 + _tmp4 - _tmp54;
  const Scalar _tmp56 = -_b[1] * _tmp53;
  const Scalar _tmp57 = _b[0] * _tmp52 - _tmp5 + _tmp56;
  const Scalar _tmp58 = _tmp10 * _tmp57 + _tmp55 * _tmp8;
  const Scalar _tmp59 = (_tmp12 * _tmp12);
  const Scalar _tmp60 = _tmp11 / _tmp59;
  const Scalar _tmp61 = -_tmp10 * _tmp55 + _tmp57 * _tmp8;
  const Scalar _tmp62 = 1.0 / (_tmp12);
  const Scalar _tmp63 = _tmp59 / ((_tmp11 * _tmp11) + _tmp59);
  const Scalar _tmp64 = _tmp63 * (-_tmp58 * _tmp60 + _tmp61 * _tmp62);
  const Scalar _tmp65 = 0.5 * _tmp64;
  const Scalar _tmp66 = _tmp20 * _tmp65;
  const Scalar _tmp67 = _a[2] * _tmp53;
  const Scalar _tmp68 = _b[2] * _tmp53;
  const Scalar _tmp69 = -_tmp14 + _tmp16;
  const Scalar _tmp70 = _a[3] * _tmp52 - _b[3] * _tmp52 + _tmp67 - _tmp68 + _tmp69;
  const Scalar _tmp71 = _a[3] * _tmp53 - _b[3] * _tmp53;
  const Scalar _tmp72 = -_a[2] * _tmp52 + _b[2] * _tmp52 + _tmp15 - _tmp17 + _tmp71;
  const Scalar _tmp73 = _tmp21 * (_tmp10 * _tmp72 + _tmp70 * _tmp8);
  const Scalar _tmp74 = _tmp21 * (-_tmp10 * _tmp70 + _tmp72 * _tmp8);
  const Scalar _tmp75 = _tmp24 * _tmp58;
  const Scalar _tmp76 = _tmp25 / (_tmp23 * _tmp23);
  const Scalar _tmp77 = _tmp61 * _tmp76;
  const Scalar _tmp78 = _tmp27 * _tmp65;
  const Scalar _tmp79 =
      _tmp26 * _tmp73 + _tmp26 * _tmp78 + _tmp28 * _tmp75 - _tmp28 * _tmp77 + _tmp66 + _tmp74;
  const Scalar _tmp80 =
      _tmp22 * _tmp75 - _tmp22 * _tmp77 + _tmp26 * _tmp66 + _tmp26 * _tmp74 - _tmp73 - _tmp78;
  const Scalar _tmp81 = _tmp1 * _tmp51;
  const Scalar _tmp82 = -_b[0] * _tmp81 + _tmp5 + _tmp56;
  const Scalar _tmp83 = -_b[1] * _tmp81 + _tmp4 + _tmp54;
  const Scalar _tmp84 = _tmp10 * _tmp83 + _tmp8 * _tmp82;
  const Scalar _tmp85 = -_tmp10 * _tmp82 + _tmp8 * _tmp83;
  const Scalar _tmp86 = _tmp63 * (-_tmp60 * _tmp84 + _tmp62 * _tmp85);
  const Scalar _tmp87 = 0.5 * _tmp86;
  const Scalar _tmp88 = _tmp27 * _tmp87;
  const Scalar _tmp89 = _a[2] * _tmp81 - _b[2] * _tmp81 - _tmp15 + _tmp17 + _tmp71;
  const Scalar _tmp90 = _a[3] * _tmp81 - _b[3] * _tmp81 - _tmp67 + _tmp68 + _tmp69;
  const Scalar _tmp91 = _tmp21 * (-_tmp10 * _tmp89 + _tmp8 * _tmp90);
  const Scalar _tmp92 = _tmp76 * _tmp85;
  const Scalar _tmp93 = _tmp21 * (_tmp10 * _tmp90 + _tmp8 * _tmp89);
  const Scalar _tmp94 = _tmp20 * _tmp87;
  const Scalar _tmp95 = _tmp24 * _tmp84;
  const Scalar _tmp96 =
      -_tmp22 * _tmp92 + _tmp22 * _tmp95 + _tmp26 * _tmp91 + _tmp26 * _tmp94 - _tmp88 - _tmp93;
  const Scalar _tmp97 =
      _tmp26 * _tmp88 + _tmp26 * _tmp93 - _tmp28 * _tmp92 + _tmp28 * _tmp95 + _tmp91 + _tmp94;
  const Scalar _tmp98 = -_tmp38 + _tmp39;
  const Scalar _tmp99 = _tmp21 * _tmp98;
  const Scalar _tmp100 = _tmp48 + _tmp99;
  const Scalar _tmp101 = _tmp26 * _tmp99;
  const Scalar _tmp102 = _tmp101 - _tmp46;
  const Scalar _tmp103 = _tmp100 * sqrt_info(0, 0) + _tmp102 * sqrt_info(0, 1);
  const Scalar _tmp104 = _tmp101 + _tmp36;
  const Scalar _tmp105 = _tmp37 - _tmp99;
  const Scalar _tmp106 = _tmp104 * sqrt_info(0, 0) + _tmp105 * sqrt_info(0, 1);
  const Scalar _tmp107 = _tmp24 * _tmp27;
  const Scalar _tmp108 = _tmp63 * (-_tmp45 * _tmp60 + _tmp62 * _tmp98);
  const Scalar _tmp109 = 0.5 * _tmp108;
  const Scalar _tmp110 = _tmp109 * _tmp27;
  const Scalar _tmp111 = _tmp27 * _tmp76;
  const Scalar _tmp112 = _tmp109 * _tmp20;
  const Scalar _tmp113 = _tmp107 * _tmp46 + _tmp110 * _tmp26 - _tmp111 * _tmp99 + _tmp112;
  const Scalar _tmp114 = _tmp20 * _tmp24;
  const Scalar _tmp115 = _tmp20 * _tmp76;
  const Scalar _tmp116 = -_tmp110 + _tmp112 * _tmp26 + _tmp114 * _tmp46 - _tmp115 * _tmp99;
  const Scalar _tmp117 = _tmp63 * (_tmp35 * _tmp62 - _tmp60 * _tmp98);
  const Scalar _tmp118 = 0.5 * _tmp117;
  const Scalar _tmp119 = _tmp118 * _tmp27;
  const Scalar _tmp120 = _tmp118 * _tmp20;
  const Scalar _tmp121 = _tmp107 * _tmp99 - _tmp111 * _tmp36 + _tmp119 * _tmp26 + _tmp120;
  const Scalar _tmp122 = _tmp114 * _tmp99 - _tmp115 * _tmp36 - _tmp119 + _tmp120 * _tmp26;
  const Scalar _tmp123 = _tmp41 * sqrt_info(1, 0) + _tmp43 * sqrt_info(1, 1);
  const Scalar _tmp124 = _tmp47 * sqrt_info(1, 0) + _tmp49 * sqrt_info(1, 1);
  const Scalar _tmp125 = _tmp100 * sqrt_info(1, 0) + _tmp102 * sqrt_info(1, 1);
  const Scalar _tmp126 = _tmp104 * sqrt_info(1, 0) + _tmp105 * sqrt_info(1, 1);
  const Scalar _tmp127 = _tmp41 * sqrt_info(2, 0) + _tmp43 * sqrt_info(2, 1);
  const Scalar _tmp128 = _tmp47 * sqrt_info(2, 0) + _tmp49 * sqrt_info(2, 1);
  const Scalar _tmp129 = _tmp100 * sqrt_info(2, 0) + _tmp102 * sqrt_info(2, 1);
  const Scalar _tmp130 = _tmp104 * sqrt_info(2, 0) + _tmp105 * sqrt_info(2, 1);

  // Output terms (2)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _res = (*res);

    _res(0, 0) = _tmp13 * sqrt_info(0, 2) + _tmp29 * sqrt_info(0, 1) + _tmp30 * sqrt_info(0, 0);
    _res(1, 0) = _tmp13 * sqrt_info(1, 2) + _tmp29 * sqrt_info(1, 1) + _tmp30 * sqrt_info(1, 0);
    _res(2, 0) = _tmp13 * sqrt_info(2, 2) + _tmp29 * sqrt_info(2, 1) + _tmp30 * sqrt_info(2, 0);
  }

  if (jac != nullptr) {
    Eigen::Matrix<Scalar, 3, 6>& _jac = (*jac);

    _jac(0, 0) = _a[0] * _tmp50 + _a[1] * _tmp44;
    _jac(0, 1) = _a[0] * _tmp44 - _a[1] * _tmp50;
    _jac(0, 2) =
        _a[0] * (_tmp64 * sqrt_info(0, 2) + _tmp79 * sqrt_info(0, 0) + _tmp80 * sqrt_info(0, 1)) -
        _a[1] * (_tmp86 * sqrt_info(0, 2) + _tmp96 * sqrt_info(0, 1) + _tmp97 * sqrt_info(0, 0));
    _jac(0, 3) = _b[0] * _tmp106 + _b[1] * _tmp103;
    _jac(0, 4) = _b[0] * _tmp103 - _b[1] * _tmp106;
    _jac(0, 5) =
        _b[0] *
            (_tmp108 * sqrt_info(0, 2) + _tmp113 * sqrt_info(0, 0) + _tmp116 * sqrt_info(0, 1)) -
        _b[1] * (_tmp117 * sqrt_info(0, 2) + _tmp121 * sqrt_info(0, 0) + _tmp122 * sqrt_info(0, 1));
    _jac(1, 0) = _a[0] * _tmp124 + _a[1] * _tmp123;
    _jac(1, 1) = _a[0] * _tmp123 - _a[1] * _tmp124;
    _jac(1, 2) =
        _a[0] * (_tmp64 * sqrt_info(1, 2) + _tmp79 * sqrt_info(1, 0) + _tmp80 * sqrt_info(1, 1)) -
        _a[1] * (_tmp86 * sqrt_info(1, 2) + _tmp96 * sqrt_info(1, 1) + _tmp97 * sqrt_info(1, 0));
    _jac(1, 3) = _b[0] * _tmp126 + _b[1] * _tmp125;
    _jac(1, 4) = _b[0] * _tmp125 - _b[1] * _tmp126;
    _jac(1, 5) =
        _b[0] *
            (_tmp108 * sqrt_info(1, 2) + _tmp113 * sqrt_info(1, 0) + _tmp116 * sqrt_info(1, 1)) -
        _b[1] * (_tmp117 * sqrt_info(1, 2) + _tmp121 * sqrt_info(1, 0) + _tmp122 * sqrt_info(1, 1));
    _jac(2, 0) = _a[0] * _tmp128 + _a[1] * _tmp127;
    _jac(2, 1) = _a[0] * _tmp127 - _a[1] * _tmp128;
    _jac(2, 2) =
        _a[0] * (_tmp64 * sqrt_info(2, 2) + _tmp79 * sqrt_info(2, 0) + _tmp80 * sqrt_info(2, 1)) -
        _a[1] * (_tmp86 * sqrt_info(2, 2) + _tmp96 * sqrt_info(2, 1) + _tmp97 * sqrt_info(2, 0));
    _jac(2, 3) = _b[0] * _tmp130 + _b[1] * _tmp129;
    _jac(2, 4) = _b[0] * _tmp129 - _b[1] * _tmp130;
    _jac(2, 5) =
        _b[0] *
            (_tmp108 * sqrt_info(2, 2) + _tmp113 * sqrt_info(2, 0) + _tmp116 * sqrt_info(2, 1)) -
        _b[1] * (_tmp117 * sqrt_info(2, 2) + _tmp121 * sqrt_info(2, 0) + _tmp122 * sqrt_info(2, 1));
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
