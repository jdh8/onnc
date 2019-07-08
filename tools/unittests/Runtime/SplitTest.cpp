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
SKYPAT_F(Operator_Split, test_split_equal_parts_1d) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {6};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1.0, 2.0};
  float output_1[2];
  const int32_t output_1_ndim = 1;
  const int32_t output_1_dims[] = {2};
  const float answer_1[] = {3.0, 4.0};
  float output_2[2];
  const int32_t output_2_ndim = 1;
  const int32_t output_2_dims[] = {2};
  const float answer_2[] = {5.0, 6.0};
  const int32_t axis = 0;
  const int32_t split[] = {3, 3};
  const int32_t number_of_split = 2;

  float *outputs[] = {output_0, output_1, output_2};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim, output_2_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims,
                                    output_2_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 3, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_2, answer_2, 2) < 1e-5f);
}

SKYPAT_F(Operator_Split, test_split_variable_parts_1d) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {6};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1.0, 2.0};
  float output_1[4];
  const int32_t output_1_ndim = 1;
  const int32_t output_1_dims[] = {4};
  const float answer_1[] = {3.0, 4.0, 5.0, 6.0};
  const int32_t axis = 0;
  const int32_t split[] = {2, 4};
  const int32_t number_of_split = 2;

  float *outputs[] = {output_0, output_1};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 2, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 4) < 1e-5f);
}

SKYPAT_F(Operator_Split, test_split_equal_parts_2d) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0,  5.0,  6.0,
                           7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 6};
  float output_0[6];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 3};
  const float answer_0[] = {1.0, 2.0, 3.0, 7.0, 8.0, 9.0};
  float output_1[6];
  const int32_t output_1_ndim = 2;
  const int32_t output_1_dims[] = {2, 3};
  const float answer_1[] = {4.0, 5.0, 6.0, 10.0, 11.0, 12.0};
  const int32_t axis = 1;
  const int32_t split[] = {3, 3};
  const int32_t number_of_split = 2;

  float *outputs[] = {output_0, output_1};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 2, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 6) < 1e-5f);
}

SKYPAT_F(Operator_Split, test_split_variable_parts_2d) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0,  5.0,  6.0,
                           7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 6};
  float output_0[4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 2};
  const float answer_0[] = {1.0, 2.0, 7.0, 8.0};
  float output_1[8];
  const int32_t output_1_ndim = 2;
  const int32_t output_1_dims[] = {2, 4};
  const float answer_1[] = {3.0, 4.0, 5.0, 6.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t axis = 1;
  const int32_t split[] = {2, 4};
  const int32_t number_of_split = 2;

  float *outputs[] = {output_0, output_1};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 2, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 4) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 8) < 1e-5f);
}

SKYPAT_F(Operator_Split, test_split_equal_parts_default_axis) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {6};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1.0, 2.0};
  float output_1[2];
  const int32_t output_1_ndim = 1;
  const int32_t output_1_dims[] = {2};
  const float answer_1[] = {3.0, 4.0};
  float output_2[2];
  const int32_t output_2_ndim = 1;
  const int32_t output_2_dims[] = {2};
  const float answer_2[] = {5.0, 6.0};
  const int32_t split[] = {3, 3};
  const int32_t number_of_split = 2;
  const int32_t axis = 0;

  float *outputs[] = {output_0, output_1, output_2};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim, output_2_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims,
                                    output_2_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 3, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_2, answer_2, 2) < 1e-5f);
}

SKYPAT_F(Operator_Split, test_split_variable_parts_default_axis) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {6};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1.0, 2.0};
  float output_1[4];
  const int32_t output_1_ndim = 1;
  const int32_t output_1_dims[] = {4};
  const float answer_1[] = {3.0, 4.0, 5.0, 6.0};
  const int32_t split[] = {2, 4};
  const int32_t number_of_split = 2;
  const int32_t axis = 0;

  float *outputs[] = {output_0, output_1};
  const int32_t output_ndims[] = {output_0_ndim, output_1_ndim};
  const int32_t *output_shapes[] = {output_0_dims, output_1_dims};
  ONNC_RUNTIME_split_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           outputs, 2, output_ndims, output_shapes, axis,
                           const_cast<int32_t *>(split), number_of_split);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
  ASSERT_TRUE(relative_error(output_1, answer_1, 4) < 1e-5f);
}
