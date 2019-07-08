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
SKYPAT_F(Operator_Mean, test_mean_example) {
  const float input_0[] = {3.0, 0.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {1.0, 3.0, 4.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  const float input_2[] = {2.0, 6.0, 6.0};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {2.0, 3.0, 4.0};
  const float *inputs[] = {input_0, input_1, input_2};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim, input_2_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims, input_2_dims};
  ONNC_RUNTIME_mean_float(nullptr, inputs, 3, input_ndims, input_shapes,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Mean, test_mean_one_input) {
  const float input_0[] = {3.0, 0.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {3.0, 0.0, 2.0};
  const float *inputs[] = {input_0};
  const int32_t input_ndims[] = {input_0_ndim};
  const int32_t *input_shapes[] = {input_0_dims};
  ONNC_RUNTIME_mean_float(nullptr, inputs, 1, input_ndims, input_shapes,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Mean, test_mean_two_inputs) {
  const float input_0[] = {3.0, 0.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {1.0, 3.0, 4.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {2.0, 1.5, 3.0};
  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_mean_float(nullptr, inputs, 2, input_ndims, input_shapes,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}
