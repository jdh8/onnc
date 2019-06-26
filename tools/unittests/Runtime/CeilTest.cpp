#include "dragonite.hpp"
SKYPAT_F(Operator_Ceil, test_ceil_example) {
  const float input_0[] = {-1.5, 1.2};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {-1.0, 2.0};
  ONNC_RUNTIME_ceil_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_Ceil, test_ceil) {
  const float input_0[] = {
      -0.88139534, -0.8808657,  0.26901108,  0.44686216,  1.4057999,
      -2.480903,   2.1706853,   1.1986642,   1.2983873,   1.3501852,
      -0.2845948,  0.38138494,  0.523523,    -0.0677154,  0.6647833,
      0.6380462,   1.1607376,   0.7923756,   -0.12235768, -0.4101373,
      -0.6388356,  0.23760441,  -0.59265035, 0.5796678,   0.5213819,
      0.5406845,   -0.90050393, 0.91091776,  0.6339115,   0.9083612,
      1.3049151,   0.25641048,  -0.42069015, 0.85298985,  1.3382106,
      1.4859883,   1.6751657,   -0.3693952,  -0.5389426,  2.3714452,
      -0.15371145, 0.11766317,  -0.28351462, -0.5746261,  1.498786,
      -1.4602858,  0.18061066,  -0.6654417,  0.60000974,  0.44642648,
      -0.14600332, 0.032320864, 0.016073357, 0.15635833,  -0.9308595,
      1.0589503,   1.351173,    -0.6524682,  1.2024933,   1.2127671};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -0.0, -0.0, 1.0,  1.0, 2.0,  -2.0, 3.0,  2.0,  2.0,  2.0,  -0.0, 1.0,
      1.0,  -0.0, 1.0,  1.0, 2.0,  1.0,  -0.0, -0.0, -0.0, 1.0,  -0.0, 1.0,
      1.0,  1.0,  -0.0, 1.0, 1.0,  1.0,  2.0,  1.0,  -0.0, 1.0,  2.0,  2.0,
      2.0,  -0.0, -0.0, 3.0, -0.0, 1.0,  -0.0, -0.0, 2.0,  -1.0, 1.0,  -0.0,
      1.0,  1.0,  -0.0, 1.0, 1.0,  1.0,  -0.0, 2.0,  2.0,  -0.0, 2.0,  2.0};
  ONNC_RUNTIME_ceil_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
