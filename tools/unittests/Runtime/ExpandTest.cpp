#include "dragonite.hpp"
SKYPAT_F(Operator_Expand, test_expand_dim_changed) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[] = {2, 1, 6};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[36];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 6};
  const float answer_0[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0,
                            2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0,
                            2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
  ONNC_RUNTIME_expand_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 36);
}

SKYPAT_F(Operator_Expand, test_expand_dim_unchanged) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[] = {3, 4};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            2.0, 2.0, 3.0, 3.0, 3.0, 3.0};
  ONNC_RUNTIME_expand_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}
