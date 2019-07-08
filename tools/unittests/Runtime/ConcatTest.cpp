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
SKYPAT_F(Operator_Concat, test_concat_1d_axis_0) {
  const float input_0[] = {1.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {2};
  const float input_1[] = {3.0, 4.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[4];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {4};
  const float answer_0[] = {1.0, 2.0, 3.0, 4.0};
  const int32_t axis = 0;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 4) < 1e-5f);
}

SKYPAT_F(Operator_Concat, test_concat_2d_axis_0) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  const float input_1[] = {5.0, 6.0, 7.0, 8.0};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {2, 2};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {4, 2};
  const float answer_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t axis = 0;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_Concat, test_concat_2d_axis_1) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  const float input_1[] = {5.0, 6.0, 7.0, 8.0};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {2, 2};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {1.0, 2.0, 5.0, 6.0, 3.0, 4.0, 7.0, 8.0};
  const int32_t axis = 1;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_Concat, test_concat_3d_axis_0) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 2, 2};
  const float input_1[] = {9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {2, 2, 2};
  float output_0[16];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 2, 2};
  const float answer_0[] = {1.0, 2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,
                            9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  const int32_t axis = 0;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 16) < 1e-5f);
}

SKYPAT_F(Operator_Concat, test_concat_3d_axis_1) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 2, 2};
  const float input_1[] = {9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {2, 2, 2};
  float output_0[16];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 4, 2};
  const float answer_0[] = {1.0, 2.0, 3.0, 4.0, 9.0,  10.0, 11.0, 12.0,
                            5.0, 6.0, 7.0, 8.0, 13.0, 14.0, 15.0, 16.0};
  const int32_t axis = 1;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 16) < 1e-5f);
}

SKYPAT_F(Operator_Concat, test_concat_3d_axis_2) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 2, 2};
  const float input_1[] = {9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {2, 2, 2};
  float output_0[16];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 2, 4};
  const float answer_0[] = {1.0, 2.0, 9.0,  10.0, 3.0, 4.0, 11.0, 12.0,
                            5.0, 6.0, 13.0, 14.0, 7.0, 8.0, 15.0, 16.0};
  const int32_t axis = 2;

  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_concat_float(nullptr, inputs, 2, input_ndims, input_shapes,
                            output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 16) < 1e-5f);
}
