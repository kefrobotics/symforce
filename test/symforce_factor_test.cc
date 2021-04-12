#include <iostream>

#include <Eigen/Dense>

#include "../symforce/opt/factor.h"
#include "catch.hpp"

TEST_CASE("Test jacobian constructors", "[factors]") {
  std::cout << "*** TestJacobianConstructors() ***" << std::endl;
  sym::Valuesd values;
  values.Set<double>('x', 1.0);
  values.Set<double>('y', 2.0);
  values.Set<double>('z', -3.0);
  values.Set<sym::Rot3d>({'R', 1}, sym::Rot3d::Identity());
  values.Set<sym::Rot3d>({'R', 2}, sym::Rot3d::FromYawPitchRoll(1.0, 0.3, 0.5));
  values.Set<sym::Pose3d>('P', sym::Pose3d::Identity());
  values.Set<double>('e', 1e-9);

  // Unary / v1 output with fixed size
  const sym::Factord unary_v1 = sym::Factord::Jacobian(
      [](double a, Eigen::Matrix<double, 1, 1>* res, Eigen::Matrix<double, 1, 1>* jac) {
        (*res) << a * a;
        (*jac) << 2 * a;
      },
      {'x'});
  std::cout << unary_v1.Linearize(values) << std::endl;

  // Unary / v1 output with dynamic size
  const sym::Factord unary_v1_dyn = sym::Factord::Jacobian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(1);
        (*res) << a * a;
        jac->resize(1, 1);
        (*jac) << 2 * a;
      },
      {'x'});
  std::cout << unary_v1_dyn.Linearize(values) << std::endl;

  // Unary / v2 output with fixed size
  const sym::Factord unary_v2 = sym::Factord::Jacobian(
      [](double a, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 1>* jac) {
        (*res) << a * a, a - 1;
        (*jac) << 2 * a, 1.0;
      },
      {'x'});
  std::cout << unary_v2.Linearize(values) << std::endl;

  // Unary / v2 output with dynamic size
  const sym::Factord unary_v2_dyn = sym::Factord::Jacobian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(2);
        (*res) << a * a, a - 1;
        jac->resize(2, 1);
        (*jac) << 2 * a, 1.0;
      },
      {'x'});
  std::cout << unary_v2_dyn.Linearize(values) << std::endl;

  // Unary / v3 output with fixed size
  const sym::Factord unary_v3 = sym::Factord::Jacobian(
      [](double a, Eigen::Matrix<double, 3, 1>* res, Eigen::Matrix<double, 3, 1>* jac) {
        (*res) << a * a, a - 1, 4.0;
        (*jac) << 2 * a, 1.0, 0.0;
      },
      {'x'});
  std::cout << unary_v3.Linearize(values) << std::endl;

  // Unary / v3 output with dynamic size
  const sym::Factord unary_v3_dyn = sym::Factord::Jacobian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(3);
        (*res) << a * a, a - 1, 4.0;
        jac->resize(3, 1);
        (*jac) << 2 * a, 1.0, 0.0;
      },
      {'x'});
  std::cout << unary_v3_dyn.Linearize(values) << std::endl;

  // Binary / v1 output with fixed size
  const sym::Factord binary_v1 = sym::Factord::Jacobian(
      [](double a, double b, Eigen::Matrix<double, 1, 1>* res, Eigen::Matrix<double, 1, 2>* jac) {
        (*res) << a * a + 2 * b;
        (*jac) << 2 * a, 2.0;
      },
      {'x', 'y'});
  std::cout << binary_v1.Linearize(values) << std::endl;

  // Binary / v1 output with dynamic size
  const sym::Factord binary_v1_dyn = sym::Factord::Jacobian(
      [](double a, double b, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(1);
        (*res) << a * a + 2 * b;
        jac->resize(1, 2);
        (*jac) << 2 * a, 2.0;
      },
      {'x', 'y'});
  std::cout << binary_v1_dyn.Linearize(values) << std::endl;

  // Binary / v2 output with fixed size
  const sym::Factord binary_v2 = sym::Factord::Jacobian(
      [](double a, double b, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 2>* jac) {
        (*res) << a * a, 2 * b;
        (*jac) << 2 * a, 0.0, 0.0, 2.0;
      },
      {'x', 'y'});
  std::cout << binary_v2.Linearize(values) << std::endl;

  // Binary / v2 output with dynamic size
  const sym::Factord binary_v2_dyn = sym::Factord::Jacobian(
      [](double a, double b, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(2);
        (*res) << a * a, 2 * b;
        jac->resize(2, 2);
        (*jac) << 2 * a, 0.0, 0.0, 2.0;
      },
      {'x', 'y'});
  std::cout << binary_v2_dyn.Linearize(values) << std::endl;

  // Ternary / v3 output with fixed size
  const sym::Factord ternary_v3 = sym::Factord::Jacobian(
      [](double a, double b, double c, Eigen::Matrix<double, 3, 1>* res,
         Eigen::Matrix<double, 3, 3>* jac) {
        (*res) << a * a, 2 * b, b + c;
        (*jac) << 2 * a, 0.0, 0.0,  //
            0.0, 2.0, 0.0,          //
            0.0, 1.0, 1.0;
      },
      {'x', 'y', 'z'});
  std::cout << ternary_v3.Linearize(values) << std::endl;

  // Ternary / v3 output with dynamic size
  const sym::Factord ternary_v3_dyn = sym::Factord::Jacobian(
      [](double a, double b, double c, Eigen::VectorXd* res, Eigen::MatrixXd* jac) {
        res->resize(3);
        (*res) << a * a, 2 * b, b + c;
        jac->resize(3, 3);
        (*jac) << 2 * a, 0.0, 0.0,  //
            0.0, 2.0, 0.0,          //
            0.0, 1.0, 1.0;
      },
      {'x', 'y', 'z'});
  std::cout << ternary_v3_dyn.Linearize(values) << std::endl;

  // Unary with Rot3
  const sym::Factord unary_rot3 = sym::Factord::Jacobian(
      [](const sym::Rot3d& rot, Eigen::Matrix<double, 2, 1>* res,
         Eigen::Matrix<double, 2, 3>* jac) {
        (*res) << rot.YawPitchRoll().tail<2>();
        (*jac) << 2.0 * rot.ToTangent().transpose(), -1.0 * rot.ToTangent().transpose();  // fake
      },
      {{'R', 2}});
  std::cout << unary_rot3.Linearize(values) << std::endl;

  // Binary with Rot3
  const sym::Factord binary_rot3 = sym::Factord::Jacobian(
      [](const sym::Rot3d& a, const sym::Rot3d& b, Eigen::Matrix<double, 3, 1>* res,
         Eigen::Matrix<double, 3, 6>* jac) {
        (*res) << a.LocalCoordinates(b);
        (*jac) << a.ToRotationMatrix(), b.ToRotationMatrix();  // fake
      },
      {{'R', 1}, {'R', 2}});
  std::cout << binary_rot3.Linearize(values) << std::endl;

  // Huge one
  const sym::Factord big_factor = sym::Factord::Jacobian(
      [](double x, const sym::Rot3d& R1, double y, const sym::Rot3d& R2, const sym::Pose3d& P,
         double z, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 15>* jac) {
        (*res)[0] = x + 2 * y + 3 * z;
        (*res)[1] = R1.Between(R2).Between(P.Rotation()).YawPitchRoll()[0];

        // FAKE
        (*jac).row(0) << 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3;
        (*jac).row(1) << 0, R1.ToTangent(), 0.0, R2.ToTangent(), 0, 0, 0, P.Rotation().ToTangent(),
            0.0;
      },
      {'x', {'R', 1}, 'y', {'R', 2}, 'P', 'z'});
  std::cout << big_factor.Linearize(values) << std::endl;

  // Test keys_to_func != keys_to_optimize - pass in extra epsilon not being optimized
  const std::vector<sym::Key> keys_to_optimize = {{'R', 1}, {'R', 2}};
  std::vector<sym::Key> keys_to_func = keys_to_optimize;
  keys_to_func.push_back('e');
  const sym::Factord binary_rot3_with_epsilon = sym::Factord::Jacobian(
      [](const sym::Rot3d& a, const sym::Rot3d& b, const double epsilon,
         Eigen::Matrix<double, 3, 1>* res, Eigen::Matrix<double, 3, 6>* jac) {
        CHECK(epsilon == 1e-9);
        (*res) << a.LocalCoordinates(b, epsilon);
        (*jac) << a.ToRotationMatrix(), b.ToRotationMatrix();  // fake
      },
      keys_to_func, keys_to_optimize);
  std::cout << binary_rot3_with_epsilon.Linearize(values) << std::endl;
}

TEST_CASE("Test hessian constructors", "[factors]") {
  std::cout << "*** TestHessianConstructors() ***" << std::endl;
  sym::Valuesd values;
  values.Set<double>('x', 1.0);
  values.Set<double>('y', 2.0);
  values.Set<double>('z', -3.0);
  values.Set<sym::Rot3d>({'R', 1}, sym::Rot3d::Identity());
  values.Set<sym::Rot3d>({'R', 2}, sym::Rot3d::FromYawPitchRoll(1.0, 0.3, 0.5));
  values.Set<sym::Pose3d>('P', sym::Pose3d::Identity());
  values.Set<double>('e', 1e-9);

  // Unary / v1 output with fixed size
  const sym::Factord unary_v1 = sym::Factord::Hessian(
      [](double a, Eigen::Matrix<double, 1, 1>* res, Eigen::Matrix<double, 1, 1>* jac,
         Eigen::Matrix<double, 1, 1>* hessian, Eigen::Matrix<double, 1, 1>* rhs) {
        (*res) << a * a;
        (*jac) << 2 * a;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v1.Linearize(values) << std::endl;

  // Unary / v1 output with dynamic size
  const sym::Factord unary_v1_dyn = sym::Factord::Hessian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac, Eigen::MatrixXd* hessian,
         Eigen::VectorXd* rhs) {
        res->resize(1);
        (*res) << a * a;
        jac->resize(1, 1);
        (*jac) << 2 * a;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v1_dyn.Linearize(values) << std::endl;

  // Unary / v2 output with fixed size
  const sym::Factord unary_v2 = sym::Factord::Hessian(
      [](double a, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 1>* jac,
         Eigen::Matrix<double, 1, 1>* hessian, Eigen::Matrix<double, 1, 1>* rhs) {
        (*res) << a * a, a - 1;
        (*jac) << 2 * a, 1.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v2.Linearize(values) << std::endl;

  // Unary / v2 output with dynamic size
  const sym::Factord unary_v2_dyn = sym::Factord::Hessian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac, Eigen::MatrixXd* hessian,
         Eigen::VectorXd* rhs) {
        res->resize(2);
        (*res) << a * a, a - 1;
        jac->resize(2, 1);
        (*jac) << 2 * a, 1.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v2_dyn.Linearize(values) << std::endl;

  // Unary / v3 output with fixed size
  const sym::Factord unary_v3 = sym::Factord::Hessian(
      [](double a, Eigen::Matrix<double, 3, 1>* res, Eigen::Matrix<double, 3, 1>* jac,
         Eigen::Matrix<double, 1, 1>* hessian, Eigen::Matrix<double, 1, 1>* rhs) {
        (*res) << a * a, a - 1, 4.0;
        (*jac) << 2 * a, 1.0, 0.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v3.Linearize(values) << std::endl;

  // Unary / v3 output with dynamic size
  const sym::Factord unary_v3_dyn = sym::Factord::Hessian(
      [](double a, Eigen::VectorXd* res, Eigen::MatrixXd* jac, Eigen::MatrixXd* hessian,
         Eigen::VectorXd* rhs) {
        res->resize(3);
        (*res) << a * a, a - 1, 4.0;
        jac->resize(3, 1);
        (*jac) << 2 * a, 1.0, 0.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x'});
  std::cout << unary_v3_dyn.Linearize(values) << std::endl;

  // Binary / v1 output with fixed size
  const sym::Factord binary_v1 = sym::Factord::Hessian(
      [](double a, double b, Eigen::Matrix<double, 1, 1>* res, Eigen::Matrix<double, 1, 2>* jac,
         Eigen::Matrix<double, 2, 2>* hessian, Eigen::Matrix<double, 2, 1>* rhs) {
        (*res) << a * a + 2 * b;
        (*jac) << 2 * a, 2.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y'});
  std::cout << binary_v1.Linearize(values) << std::endl;

  // Binary / v1 output with dynamic size
  const sym::Factord binary_v1_dyn = sym::Factord::Hessian(
      [](double a, double b, Eigen::VectorXd* res, Eigen::MatrixXd* jac, Eigen::MatrixXd* hessian,
         Eigen::VectorXd* rhs) {
        res->resize(1);
        (*res) << a * a + 2 * b;
        jac->resize(1, 2);
        (*jac) << 2 * a, 2.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y'});
  std::cout << binary_v1_dyn.Linearize(values) << std::endl;

  // Binary / v2 output with fixed size
  const sym::Factord binary_v2 = sym::Factord::Hessian(
      [](double a, double b, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 2>* jac,
         Eigen::Matrix<double, 2, 2>* hessian, Eigen::Matrix<double, 2, 1>* rhs) {
        (*res) << a * a, 2 * b;
        (*jac) << 2 * a, 0.0, 0.0, 2.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y'});
  std::cout << binary_v2.Linearize(values) << std::endl;

  // Binary / v2 output with dynamic size
  const sym::Factord binary_v2_dyn = sym::Factord::Hessian(
      [](double a, double b, Eigen::VectorXd* res, Eigen::MatrixXd* jac, Eigen::MatrixXd* hessian,
         Eigen::VectorXd* rhs) {
        res->resize(2);
        (*res) << a * a, 2 * b;
        jac->resize(2, 2);
        (*jac) << 2 * a, 0.0, 0.0, 2.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y'});
  std::cout << binary_v2_dyn.Linearize(values) << std::endl;

  // Ternary / v3 output with fixed size
  const sym::Factord ternary_v3 = sym::Factord::Hessian(
      [](double a, double b, double c, Eigen::Matrix<double, 3, 1>* res,
         Eigen::Matrix<double, 3, 3>* jac, Eigen::Matrix<double, 3, 3>* hessian,
         Eigen::Matrix<double, 3, 1>* rhs) {
        (*res) << a * a, 2 * b, b + c;
        (*jac) << 2 * a, 0.0, 0.0,  //
            0.0, 2.0, 0.0,          //
            0.0, 1.0, 1.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y', 'z'});
  std::cout << ternary_v3.Linearize(values) << std::endl;

  // Ternary / v3 output with dynamic size
  const sym::Factord ternary_v3_dyn = sym::Factord::Hessian(
      [](double a, double b, double c, Eigen::VectorXd* res, Eigen::MatrixXd* jac,
         Eigen::MatrixXd* hessian, Eigen::VectorXd* rhs) {
        res->resize(3);
        (*res) << a * a, 2 * b, b + c;
        jac->resize(3, 3);
        (*jac) << 2 * a, 0.0, 0.0,  //
            0.0, 2.0, 0.0,          //
            0.0, 1.0, 1.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', 'y', 'z'});
  std::cout << ternary_v3_dyn.Linearize(values) << std::endl;

  // Unary with Rot3
  const sym::Factord unary_rot3 = sym::Factord::Hessian(
      [](const sym::Rot3d& rot, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 3>* jac,
         Eigen::Matrix<double, 3, 3>* hessian, Eigen::Matrix<double, 3, 1>* rhs) {
        (*res) << rot.YawPitchRoll().tail<2>();
        (*jac) << 2.0 * rot.ToTangent().transpose(), -1.0 * rot.ToTangent().transpose();  // fake

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {{'R', 2}});
  std::cout << unary_rot3.Linearize(values) << std::endl;

  // Binary with Rot3
  const sym::Factord binary_rot3 = sym::Factord::Hessian(
      [](const sym::Rot3d& a, const sym::Rot3d& b, Eigen::Matrix<double, 3, 1>* res,
         Eigen::Matrix<double, 3, 6>* jac, Eigen::Matrix<double, 6, 6>* hessian,
         Eigen::Matrix<double, 6, 1>* rhs) {
        (*res) << a.LocalCoordinates(b);
        (*jac) << a.ToRotationMatrix(), b.ToRotationMatrix();  // fake

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {{'R', 1}, {'R', 2}});
  std::cout << binary_rot3.Linearize(values) << std::endl;

  // Huge one
  const sym::Factord big_factor = sym::Factord::Hessian(
      [](double x, const sym::Rot3d& R1, double y, const sym::Rot3d& R2, const sym::Pose3d& P,
         double z, Eigen::Matrix<double, 2, 1>* res, Eigen::Matrix<double, 2, 15>* jac,
         Eigen::Matrix<double, 15, 15>* hessian, Eigen::Matrix<double, 15, 1>* rhs) {
        (*res)[0] = x + 2 * y + 3 * z;
        (*res)[1] = R1.Between(R2).Between(P.Rotation()).YawPitchRoll()[0];

        // FAKE
        (*jac).row(0) << 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3;
        (*jac).row(1) << 0, R1.ToTangent(), 0.0, R2.ToTangent(), 0, 0, 0, P.Rotation().ToTangent(),
            0.0;

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      {'x', {'R', 1}, 'y', {'R', 2}, 'P', 'z'});
  std::cout << big_factor.Linearize(values) << std::endl;

  // Test keys_to_func != keys_to_optimize - pass in extra epsilon not being optimized
  const std::vector<sym::Key> keys_to_optimize = {{'R', 1}, {'R', 2}};
  std::vector<sym::Key> keys_to_func = keys_to_optimize;
  keys_to_func.push_back('e');
  const sym::Factord binary_rot3_with_epsilon = sym::Factord::Hessian(
      [](const sym::Rot3d& a, const sym::Rot3d& b, const double epsilon,
         Eigen::Matrix<double, 3, 1>* res, Eigen::Matrix<double, 3, 6>* jac,
         Eigen::Matrix<double, 6, 6>* hessian, Eigen::Matrix<double, 6, 1>* rhs) {
        CHECK(epsilon == 1e-9);
        (*res) << a.LocalCoordinates(b, epsilon);
        (*jac) << a.ToRotationMatrix(), b.ToRotationMatrix();  // fake

        hessian->resize(jac->cols(), jac->cols());
        hessian->triangularView<Eigen::Lower>() =
            (jac->transpose() * (*jac)).triangularView<Eigen::Lower>();
        (*rhs) = jac->transpose() * (*res);
      },
      keys_to_func, keys_to_optimize);
  std::cout << binary_rot3_with_epsilon.Linearize(values) << std::endl;
}

TEMPLATE_TEST_CASE("Test linearized values", "[factors]", double, float) {
  using Scalar = TestType;

  sym::Key x('x');
  sym::Key y('y');
  sym::Key z('z');

  sym::Values<Scalar> values;
  values.template Set<Scalar>(x, 1.0);
  values.template Set<Scalar>(y, 2.0);
  values.template Set<Scalar>(z, -3.0);

  const auto func = [](Scalar a, Scalar b, Eigen::Matrix<Scalar, 1, 1>* res,
                       Eigen::Matrix<Scalar, 1, 2>* jac) {
    (*res) << a * a + b;

    if (jac) {
      (*jac) << 2 * a, 1;
    }
  };

  // Check with keys {x, y} so a = 1, b = 2
  const sym::Factor<Scalar> factor1 = sym::Factor<Scalar>::Jacobian(func, {x, y});
  const auto linearized1 = factor1.Linearize(values);
  std::cout << linearized1 << std::endl;
  CHECK(linearized1.residual[0] == Catch::Approx(3).epsilon(0).margin(1e-3));
  CHECK(linearized1.jacobian(0, 0) == Catch::Approx(2).epsilon(0).margin(1e-3));
  CHECK(linearized1.jacobian(0, 1) == Catch::Approx(1).epsilon(0).margin(1e-3));

  // Check another combination of keys, now a = -3, b = 1
  const sym::Factor<Scalar> factor2 = sym::Factor<Scalar>::Jacobian(func, {z, x});
  const auto linearized2 = factor2.Linearize(values);
  std::cout << linearized2 << std::endl;
  CHECK(linearized2.residual[0] == Catch::Approx(10).epsilon(0).margin(1e-3));
  CHECK(linearized2.jacobian(0, 0) == Catch::Approx(-6).epsilon(0).margin(1e-3));
  CHECK(linearized2.jacobian(0, 1) == Catch::Approx(1).epsilon(0).margin(1e-3));

  // Check Linearize with residual
  sym::VectorX<Scalar> residual;
  factor2.Linearize(values, &residual);
  CHECK(residual.isApprox(linearized2.residual));

  // Check Linearize with residual and jacobian
  sym::MatrixX<Scalar> jacobian;
  factor2.Linearize(values, &residual, &jacobian);
  CHECK(residual.isApprox(linearized2.residual));
  CHECK(jacobian.isApprox(linearized2.jacobian));
}