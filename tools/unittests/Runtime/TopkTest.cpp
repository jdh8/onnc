#include "dragonite.hpp"
SKYPAT_F(Operator_TopK, test_top_k) {
  const float input_0[] = {0.0, 1.0, 2.0, 3.0, 4.0,  5.0,
                           6.0, 7.0, 8.0, 9.0, 10.0, 11.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[9];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 3};
  const float answer_0[] = {3.0, 2.0, 1.0, 7.0, 6.0, 5.0, 11.0, 10.0, 9.0};
  float output_1[9];
  const int32_t output_1_ndim = 2;
  const int32_t output_1_dims[] = {3, 3};
  const float answer_1[] = {3, 2, 1, 3, 2, 1, 3, 2, 1};
  const int32_t k = 3;
  const int32_t axis = 0;
  ONNC_RUNTIME_topk_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims,
                          (float *)output_1, output_1_ndim, output_1_dims, axis,
                          k);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 9);
  (dragonite::verify)(reinterpret_cast<float *>(output_1),
                      reinterpret_cast<const float *>(answer_1), 9);
}
