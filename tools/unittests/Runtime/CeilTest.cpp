#if defined(__GNUC__) || defined(_MSC_VER)
#define restrict __restrict
#else
#define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "relative-error.hpp"
#include <skypat/skypat.h>
SKYPAT_F(Operator_Ceil, test_ceil_example) {
  const float input_0[] = {-1.5, 1.2};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {-1.0, 2.0};
  ONNC_RUNTIME_ceil_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_Ceil, test_ceil) {
  const float input_0[] = {
      0.16223462,  0.15332793,  -0.13029309, 0.34906998, -0.6768123,
      -0.7207275,  0.08517971,  -0.3612139,  -1.4433739, 0.76441133,
      -0.4569049,  0.7207717,   -0.17805362, -1.1828744, 0.27450225,
      -0.3034686,  0.36677924,  1.5298203,   0.24831347, 1.484716,
      0.5792381,   -0.68763137, 1.7820652,   0.18057254, 0.3793179,
      -1.989423,   -2.4868584,  0.14978306,  -0.8701113, 1.0312272,
      0.5692347,   0.20478432,  -0.61507565, -1.5093771, -1.3689855,
      0.6116965,   0.18798667,  -1.358859,   0.41533715, 2.3681664,
      -0.5262861,  0.7983595,   1.2968984,   1.3005514,  -2.1909342,
      -0.9271853,  1.3270583,   -1.3597348,  -2.202468,  -0.7181976,
      -0.15122393, 0.49586654,  -0.53494525, 0.7376397,  -1.1293029,
      1.115224,    -0.33622843, 0.6012759,   -0.7270101, 0.033193763};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      1.0,  1.0,  -0.0, 1.0,  -0.0, -0.0, 1.0,  -0.0, -1.0, 1.0,  -0.0, 1.0,
      -0.0, -1.0, 1.0,  -0.0, 1.0,  2.0,  1.0,  2.0,  1.0,  -0.0, 2.0,  1.0,
      1.0,  -1.0, -2.0, 1.0,  -0.0, 2.0,  1.0,  1.0,  -0.0, -1.0, -1.0, 1.0,
      1.0,  -1.0, 1.0,  3.0,  -0.0, 1.0,  2.0,  2.0,  -2.0, -0.0, 2.0,  -1.0,
      -2.0, -0.0, -0.0, 1.0,  -0.0, 1.0,  -1.0, 2.0,  -0.0, 1.0,  -0.0, 1.0};
  ONNC_RUNTIME_ceil_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
