// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (6x6) jacobian of res (6) wrt arg a (6)
 */
template <typename Scalar>
sym::Pose3<Scalar> ComposePose3WithJacobian0(const sym::Pose3<Scalar>& a,
                                             const sym::Pose3<Scalar>& b,
                                             Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr) {
  // Total ops: 356

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (107)
  const Scalar _tmp0 = _a[0] * _b[3];
  const Scalar _tmp1 = _a[1] * _b[2];
  const Scalar _tmp2 = _a[3] * _b[0];
  const Scalar _tmp3 = _a[2] * _b[1];
  const Scalar _tmp4 = _a[1] * _b[3];
  const Scalar _tmp5 = _a[2] * _b[0];
  const Scalar _tmp6 = _a[3] * _b[1];
  const Scalar _tmp7 = _a[0] * _b[2];
  const Scalar _tmp8 = _a[0] * _b[1];
  const Scalar _tmp9 = _a[2] * _b[3];
  const Scalar _tmp10 = _a[3] * _b[2];
  const Scalar _tmp11 = _a[1] * _b[0];
  const Scalar _tmp12 = _a[3] * _b[3];
  const Scalar _tmp13 = _a[0] * _b[0];
  const Scalar _tmp14 = _a[1] * _b[1];
  const Scalar _tmp15 = _a[2] * _b[2];
  const Scalar _tmp16 = 2 * _a[1];
  const Scalar _tmp17 = _a[0] * _tmp16;
  const Scalar _tmp18 = 2 * _a[2];
  const Scalar _tmp19 = _a[3] * _tmp18;
  const Scalar _tmp20 = _a[0] * _tmp18;
  const Scalar _tmp21 = _a[3] * _tmp16;
  const Scalar _tmp22 = -2 * std::pow<Scalar>(_a[1], 2);
  const Scalar _tmp23 = 1 - 2 * std::pow<Scalar>(_a[2], 2);
  const Scalar _tmp24 = 2 * _a[0];
  const Scalar _tmp25 = _a[3] * _tmp24;
  const Scalar _tmp26 = _a[1] * _tmp18;
  const Scalar _tmp27 = -2 * std::pow<Scalar>(_a[0], 2);
  const Scalar _tmp28 = 2 * _tmp12 - 2 * _tmp13 - 2 * _tmp14 - 2 * _tmp15;
  const Scalar _tmp29 = _b[0] * _tmp28;
  const Scalar _tmp30 = 2 * _tmp8;
  const Scalar _tmp31 = 2 * _tmp11;
  const Scalar _tmp32 = 2 * _tmp9;
  const Scalar _tmp33 = 2 * _tmp10;
  const Scalar _tmp34 = _tmp30 - _tmp31 + _tmp32 + _tmp33;
  const Scalar _tmp35 = 2 * _tmp7;
  const Scalar _tmp36 = 2 * _tmp4;
  const Scalar _tmp37 = 2 * _tmp5;
  const Scalar _tmp38 = 2 * _tmp6;
  const Scalar _tmp39 = _tmp35 - _tmp36 - _tmp37 - _tmp38;
  const Scalar _tmp40 = _b[2] * _tmp39;
  const Scalar _tmp41 = 2 * _tmp0;
  const Scalar _tmp42 = 2 * _tmp1;
  const Scalar _tmp43 = 2 * _tmp3;
  const Scalar _tmp44 = 2 * _tmp2;
  const Scalar _tmp45 = -_tmp41 - _tmp42 + _tmp43 - _tmp44;
  const Scalar _tmp46 = _b[3] * _tmp45;
  const Scalar _tmp47 = _b[1] * _tmp34 + _tmp29 + _tmp40 + _tmp46;
  const Scalar _tmp48 = (Scalar(1) / Scalar(2)) * _a[0];
  const Scalar _tmp49 = _b[3] * _tmp39;
  const Scalar _tmp50 = _b[1] * _tmp28;
  const Scalar _tmp51 = -_b[2] * _tmp45;
  const Scalar _tmp52 = _b[0] * _tmp34 + _tmp49 - _tmp50 + _tmp51;
  const Scalar _tmp53 = (Scalar(1) / Scalar(2)) * _a[1];
  const Scalar _tmp54 = _b[2] * _tmp28;
  const Scalar _tmp55 = -_b[0] * _tmp39;
  const Scalar _tmp56 = _b[1] * _tmp45;
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _b[3] * _tmp34 +
                        (Scalar(1) / Scalar(2)) * _tmp54 + (Scalar(1) / Scalar(2)) * _tmp55 -
                        Scalar(1) / Scalar(2) * _tmp56;
  const Scalar _tmp58 = _b[1] * _tmp39;
  const Scalar _tmp59 = _b[3] * _tmp28;
  const Scalar _tmp60 = _b[0] * _tmp45;
  const Scalar _tmp61 = -Scalar(1) / Scalar(2) * _b[2] * _tmp34 + (Scalar(1) / Scalar(2)) * _tmp58 +
                        (Scalar(1) / Scalar(2)) * _tmp59 - Scalar(1) / Scalar(2) * _tmp60;
  const Scalar _tmp62 = (Scalar(1) / Scalar(2)) * _a[2];
  const Scalar _tmp63 = (Scalar(1) / Scalar(2)) * _a[3];
  const Scalar _tmp64 = -_tmp30 + _tmp31 - _tmp32 - _tmp33;
  const Scalar _tmp65 = _b[0] * _tmp64;
  const Scalar _tmp66 = _tmp41 + _tmp42 - _tmp43 + _tmp44;
  const Scalar _tmp67 = _b[2] * _tmp66 + _tmp49 + _tmp50 + _tmp65;
  const Scalar _tmp68 = -_b[1] * _tmp64;
  const Scalar _tmp69 = _b[3] * _tmp66 + _tmp29 - _tmp40 + _tmp68;
  const Scalar _tmp70 = _b[2] * _tmp64;
  const Scalar _tmp71 = -_b[0] * _tmp66 - _tmp58 + _tmp59 + _tmp70;
  const Scalar _tmp72 = _b[3] * _tmp64;
  const Scalar _tmp73 = _b[1] * _tmp66 - _tmp54 + _tmp55 + _tmp72;
  const Scalar _tmp74 = -_tmp35 + _tmp36 + _tmp37 + _tmp38;
  const Scalar _tmp75 = _b[0] * _tmp74 + _tmp54 + _tmp56 + _tmp72;
  const Scalar _tmp76 = -_b[1] * _tmp74 + _tmp59 + _tmp60 - _tmp70;
  const Scalar _tmp77 = _b[2] * _tmp74 - _tmp29 + _tmp46 + _tmp68;
  const Scalar _tmp78 = _b[3] * _tmp74 + _tmp50 + _tmp51 - _tmp65;
  const Scalar _tmp79 = _b[6] * _tmp16;
  const Scalar _tmp80 = _b[5] * _tmp18;
  const Scalar _tmp81 = _tmp79 - _tmp80;
  const Scalar _tmp82 = _b[5] * _tmp16;
  const Scalar _tmp83 = _b[6] * _tmp18;
  const Scalar _tmp84 = _tmp82 + _tmp83;
  const Scalar _tmp85 = _b[6] * _tmp24;
  const Scalar _tmp86 = 4 * _b[4];
  const Scalar _tmp87 = 2 * _a[3];
  const Scalar _tmp88 = _b[5] * _tmp87;
  const Scalar _tmp89 = -_a[2] * _tmp86 + _tmp85 - _tmp88;
  const Scalar _tmp90 = _b[5] * _tmp24;
  const Scalar _tmp91 = _b[6] * _tmp87;
  const Scalar _tmp92 = -_a[1] * _tmp86 + _tmp90 + _tmp91;
  const Scalar _tmp93 = _b[4] * _tmp18;
  const Scalar _tmp94 = -_tmp85 + _tmp93;
  const Scalar _tmp95 = _b[4] * _tmp24;
  const Scalar _tmp96 = _tmp83 + _tmp95;
  const Scalar _tmp97 = 4 * _b[5];
  const Scalar _tmp98 = _b[4] * _tmp87;
  const Scalar _tmp99 = -_a[2] * _tmp97 + _tmp79 + _tmp98;
  const Scalar _tmp100 = _b[4] * _tmp16;
  const Scalar _tmp101 = -_a[0] * _tmp97 + _tmp100 - _tmp91;
  const Scalar _tmp102 = -_tmp100 + _tmp90;
  const Scalar _tmp103 = _tmp82 + _tmp95;
  const Scalar _tmp104 = 4 * _b[6];
  const Scalar _tmp105 = -_a[1] * _tmp104 + _tmp80 - _tmp98;
  const Scalar _tmp106 = -_a[0] * _tmp104 + _tmp88 + _tmp93;

  // Output terms (2)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _tmp0 + _tmp1 + _tmp2 - _tmp3;
  _res[1] = _tmp4 + _tmp5 + _tmp6 - _tmp7;
  _res[2] = _tmp10 - _tmp11 + _tmp8 + _tmp9;
  _res[3] = _tmp12 - _tmp13 - _tmp14 - _tmp15;
  _res[4] =
      _a[4] + _b[4] * (_tmp22 + _tmp23) + _b[5] * (_tmp17 - _tmp19) + _b[6] * (_tmp20 + _tmp21);
  _res[5] =
      _a[5] + _b[4] * (_tmp17 + _tmp19) + _b[5] * (_tmp23 + _tmp27) + _b[6] * (-_tmp25 + _tmp26);
  _res[6] =
      _a[6] + _b[4] * (_tmp20 - _tmp21) + _b[5] * (_tmp25 + _tmp26) + _b[6] * (_tmp22 + _tmp27 + 1);

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _a[2] * _tmp57 + _a[3] * _tmp61 - _tmp47 * _tmp48 - _tmp52 * _tmp53;
    _res_D_a(0, 1) = -_a[2] * _tmp61 + _a[3] * _tmp57 - _tmp47 * _tmp53 + _tmp48 * _tmp52;
    _res_D_a(0, 2) = -_a[0] * _tmp57 + _a[1] * _tmp61 - _tmp47 * _tmp62 + _tmp52 * _tmp63;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = -_tmp48 * _tmp67 - _tmp53 * _tmp69 + _tmp62 * _tmp71 + _tmp63 * _tmp73;
    _res_D_a(1, 1) = _tmp48 * _tmp69 - _tmp53 * _tmp67 - _tmp62 * _tmp73 + _tmp63 * _tmp71;
    _res_D_a(1, 2) = -_tmp48 * _tmp71 + _tmp53 * _tmp73 - _tmp62 * _tmp67 + _tmp63 * _tmp69;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = -_tmp48 * _tmp75 - _tmp53 * _tmp76 + _tmp62 * _tmp77 + _tmp63 * _tmp78;
    _res_D_a(2, 1) = _tmp48 * _tmp76 - _tmp53 * _tmp75 - _tmp62 * _tmp78 + _tmp63 * _tmp77;
    _res_D_a(2, 2) = -_tmp48 * _tmp77 + _tmp53 * _tmp78 - _tmp62 * _tmp75 + _tmp63 * _tmp76;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = -_tmp48 * _tmp81 - _tmp53 * _tmp89 + _tmp62 * _tmp92 + _tmp63 * _tmp84;
    _res_D_a(3, 1) = _tmp48 * _tmp89 - _tmp53 * _tmp81 - _tmp62 * _tmp84 + _tmp63 * _tmp92;
    _res_D_a(3, 2) = -_tmp48 * _tmp92 + _tmp53 * _tmp84 - _tmp62 * _tmp81 + _tmp63 * _tmp89;
    _res_D_a(3, 3) = 1;
    _res_D_a(3, 4) = 0;
    _res_D_a(3, 5) = 0;
    _res_D_a(4, 0) = _tmp101 * _tmp63 - _tmp48 * _tmp94 - _tmp53 * _tmp99 + _tmp62 * _tmp96;
    _res_D_a(4, 1) = -_tmp101 * _tmp62 + _tmp48 * _tmp99 - _tmp53 * _tmp94 + _tmp63 * _tmp96;
    _res_D_a(4, 2) = _tmp101 * _tmp53 - _tmp48 * _tmp96 - _tmp62 * _tmp94 + _tmp63 * _tmp99;
    _res_D_a(4, 3) = 0;
    _res_D_a(4, 4) = 1;
    _res_D_a(4, 5) = 0;
    _res_D_a(5, 0) = -_tmp102 * _tmp48 - _tmp103 * _tmp53 + _tmp105 * _tmp62 + _tmp106 * _tmp63;
    _res_D_a(5, 1) = -_tmp102 * _tmp53 + _tmp103 * _tmp48 + _tmp105 * _tmp63 - _tmp106 * _tmp62;
    _res_D_a(5, 2) = -_tmp102 * _tmp62 + _tmp103 * _tmp63 - _tmp105 * _tmp48 + _tmp106 * _tmp53;
    _res_D_a(5, 3) = 0;
    _res_D_a(5, 4) = 0;
    _res_D_a(5, 5) = 1;
  }

  return sym::Pose3<Scalar>(_res);
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym