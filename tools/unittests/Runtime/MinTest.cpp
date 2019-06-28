#include "dragonite.hpp"
SKYPAT_F(Operator_Min, test_min_example) {
  const float input_0[] = {3.0, 2.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {1.0, 4.0, 4.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  const float input_2[] = {2.0, 5.0, 0.0};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {1.0, 2.0, 0.0};
  const float *inputs[] = {input_0, input_1, input_2};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim, input_2_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims, input_2_dims};
  ONNC_RUNTIME_min_float(nullptr, inputs, 3, input_ndims, input_shapes, output_0, output_0_ndim, output_0_dims);
  dragonite::verify(output_0, answer_0, 3);
}

SKYPAT_F(Operator_Min, test_min_one_input) {
  const float input_0[] = {3.0, 2.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {3.0, 2.0, 1.0};
  const float *inputs[] = {input_0};
  const int32_t input_ndims[] = {input_0_ndim};
  const int32_t *input_shapes[] = {input_0_dims};
  ONNC_RUNTIME_min_float(nullptr, inputs, 1, input_ndims, input_shapes, output_0, output_0_ndim, output_0_dims);
  dragonite::verify(output_0, answer_0, 3);
}

SKYPAT_F(Operator_Min, test_min_two_inputs) {
  const float input_0[] = {3.0, 2.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {1.0, 4.0, 4.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {1.0, 2.0, 1.0};
  const float *inputs[] = {input_0, input_1};
  const int32_t input_ndims[] = {input_0_ndim, input_1_ndim};
  const int32_t *input_shapes[] = {input_0_dims, input_1_dims};
  ONNC_RUNTIME_min_float(nullptr, inputs, 2, input_ndims, input_shapes, output_0, output_0_ndim, output_0_dims);
  dragonite::verify(output_0, answer_0, 3);
}
