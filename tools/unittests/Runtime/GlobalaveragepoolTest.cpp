#include "dragonite.hpp"
SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool) {
  const float input_0[] = {
      0.13533881,  0.40991905,   0.1866696,   -0.047466237, 0.70046645,
      0.35895976,  0.46799597,   0.33750203,  0.5359151,    -1.3161645,
      -1.6140492,  0.9074515,    -0.2588917,  0.429789,     0.16180983,
      1.2908247,   -0.3236104,   -1.3855946,  -0.90826994,  -0.8296956,
      -1.0056512,  -0.41996112,  0.46376258,  0.23115154,   1.4994243,
      -0.2024178,  0.6295883,    1.6290114,   0.92864984,   0.7278866,
      -1.1159445,  -0.007299735, -0.21329555, -0.14369892,  -0.13692725,
      -0.17610654, -0.5190461,   1.2704797,   0.5194119,    -0.29261643,
      -0.12445366, -0.8792003,   -1.422141,   -2.6045392,   1.7038131,
      -0.16332315, 0.092919335,  0.32489532,  0.40862387,   -1.1198988,
      -0.8248346,  0.4565337,    0.45990288,  1.3625172,    0.26521692,
      -1.1665801,  -0.19469479,  1.936589,    0.46063596,   -0.049299054,
      -1.0682999,  -0.10001975,  -0.3736002,  0.40273863,   0.8854383,
      0.621508,    -1.0778228,   0.52472574,  -1.0479897,   -0.43625122,
      -1.1841443,  0.35694578,   -0.5534753,  -0.82572484,  -0.08087107};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float output_0[3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float answer_0[] = {0.00030501842, -0.035425182, -0.05003422};
  ONNC_RUNTIME_globalaveragepool_float(NULL, (float *)input_0, input_0_ndim,
                                       input_0_dims, (float *)output_0,
                                       output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool_precomputed) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float output_0[1];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float answer_0[] = {5.0};
  ONNC_RUNTIME_globalaveragepool_float(NULL, (float *)input_0, input_0_ndim,
                                       input_0_dims, (float *)output_0,
                                       output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 1);
}
