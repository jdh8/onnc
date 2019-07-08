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
SKYPAT_F(Operator_Dropout, test_dropout_default) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const float ratio = 0.5;
  ONNC_RUNTIME_dropout_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             output_0, output_0_ndim, output_0_dims, output_1,
                             output_1_ndim, output_1_dims, ratio);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Dropout, test_dropout_random) {
  const float input_0[] = {
      -1.0099195,  -0.21510866, -0.8487644,  0.0689584,   -0.84181595,
      0.15988688,  -1.4302088,  -0.7684832,  0.05220989,  -0.05617211,
      -0.41293442, -1.2829283,  0.08970178,  0.7575036,   -1.6625646,
      0.58224577,  -2.3422565,  -0.9072342,  -0.26166162, 0.23445846,
      1.1196798,   1.9989598,   2.8069956,   1.9024451,   -0.6563917,
      -0.13344143, 1.4208083,   1.0365888,   -0.7740558,  -0.22300357,
      0.73067385,  -0.18704073, 0.44298574,  0.49447903,  0.53376937,
      0.23053971,  1.4963183,   -0.6791098,  0.12547445,  -0.41390848,
      -0.76128393, 0.001573253, -0.93807477, -0.8100785,  -0.8822975,
      0.22501919,  -0.04203527, 0.2761645,   -0.7175326,  -1.4917359,
      0.9577058,   0.632635,    0.43549782,  -0.77620095, 1.003674,
      -0.71483773, -0.29408157, -0.69374084, 0.052461136, 0.032689545};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.0099195,  -0.21510866, -0.8487644,  0.0689584,   -0.84181595,
      0.15988688,  -1.4302088,  -0.7684832,  0.05220989,  -0.05617211,
      -0.41293442, -1.2829283,  0.08970178,  0.7575036,   -1.6625646,
      0.58224577,  -2.3422565,  -0.9072342,  -0.26166162, 0.23445846,
      1.1196798,   1.9989598,   2.8069956,   1.9024451,   -0.6563917,
      -0.13344143, 1.4208083,   1.0365888,   -0.7740558,  -0.22300357,
      0.73067385,  -0.18704073, 0.44298574,  0.49447903,  0.53376937,
      0.23053971,  1.4963183,   -0.6791098,  0.12547445,  -0.41390848,
      -0.76128393, 0.001573253, -0.93807477, -0.8100785,  -0.8822975,
      0.22501919,  -0.04203527, 0.2761645,   -0.7175326,  -1.4917359,
      0.9577058,   0.632635,    0.43549782,  -0.77620095, 1.003674,
      -0.71483773, -0.29408157, -0.69374084, 0.052461136, 0.032689545};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const float ratio = 0.20000000298023224;
  ONNC_RUNTIME_dropout_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             output_0, output_0_ndim, output_0_dims, output_1,
                             output_1_ndim, output_1_dims, ratio);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
