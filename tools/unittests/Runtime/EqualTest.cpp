#include "dragonite.hpp"
SKYPAT_F(Operator_Equal, test_equal) {
  const float input_0[] = {-6,  5,  -3, -3, 12, -4,  11, -15, -1, 16,  1,   -6,
                           3,   0,  3,  -9, -6, 0,   -7, -1,  -5, -26, 4,   -12,
                           -13, -3, -5, -4, -5, -20, 1,  8,   0,  -11, 7,   0,
                           6,   11, 10, 8,  -4, -4,  -7, 14,  5,  8,   -11, 0,
                           12,  -8, -6, 2,  5,  5,   0,  -4,  -1, 11,  14,  7};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {
      11,  17, 8,  10, 2,   -4,  10,  -15, 2,  -1,  -4, 0,  -2, 6,  12,
      -1,  -2, -8, 2,  15,  7,   0,   1,   5,  -6,  -3, 3,  15, 22, 6,
      -21, -1, 10, -4, -27, -2,  -15, -2,  0,  -6,  -9, -1, 12, 1,  0,
      3,   12, 8,  17, -1,  -18, -14, -4,  -9, -10, -4, -6, -3, 14, 19};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0};
  ONNC_RUNTIME_equal_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)input_1, input_1_ndim, input_1_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Equal, test_equal_bcast) {
  const float input_0[] = {
      1,  3,  -11, 1,  -3,  12, -4,  -2,  29, -2, 7,   -1,  -6,  -15, 12,
      0,  -7, -12, -4, -2,  14, -16, -2,  -7, -8, -2,  -10, 2,   -11, 2,
      -1, -1, -2,  3,  -13, 7,  -11, -16, 0,  9,  0,   9,   0,   -2,  -4,
      7,  13, -3,  4,  -3,  4,  15,  -8,  5,  5,  -20, -1,  -26, -3,  -11};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {14, 4, 13, -8, -10};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  ONNC_RUNTIME_equal_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)input_1, input_1_ndim, input_1_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
