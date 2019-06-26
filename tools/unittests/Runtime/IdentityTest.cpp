#include "dragonite.hpp"
SKYPAT_F(Operator_Identity, test_identity) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 2, 2};
  float output_0[4];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 2, 2};
  const float answer_0[] = {1.0, 2.0, 3.0, 4.0};
  ONNC_RUNTIME_identity_float(NULL, (float *)input_0, input_0_ndim,
                              input_0_dims, (float *)output_0, output_0_ndim,
                              output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 4);
}
