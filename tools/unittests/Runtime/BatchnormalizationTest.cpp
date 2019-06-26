#include "dragonite.hpp"
SKYPAT_F(Operator_BatchNormalization, test_batchnorm_example) {
  const float input_0[] = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 2, 1, 3};
  const float input_1[] = {1.0, 1.5};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  const float input_2[] = {0.0, 1.0};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {2};
  const float input_3[] = {0.0, 3.0};
  const int32_t input_3_ndim = 1;
  const int32_t input_3_dims[] = {2};
  const float input_4[] = {1.0, 1.5};
  const int32_t input_4_ndim = 1;
  const int32_t input_4_dims[] = {2};
  float output_0[6];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 2, 1, 3};
  const float answer_0[] = {-0.999995,   0.0, 0.999995,
                            -0.22474074, 1.0, 2.2247407};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float output_2[] = {};
  const int32_t output_2_ndim = 0;
  const int32_t output_2_dims[] = {};
  const float output_3[] = {};
  const int32_t output_3_ndim = 0;
  const int32_t output_3_dims[] = {};
  const float output_4[] = {};
  const int32_t output_4_ndim = 0;
  const int32_t output_4_dims[] = {};
  const int32_t spatial = 0;
  const float momentum = 0;
  const float epsilon = 0;
  ONNC_RUNTIME_batchnormalization_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)output_0, output_0_ndim,
      output_0_dims, (float *)output_1, output_1_ndim, output_1_dims,
      (float *)output_2, output_2_ndim, output_2_dims, (float *)output_3,
      output_3_ndim, output_3_dims, (float *)output_4, output_4_ndim,
      output_4_dims, epsilon, momentum, spatial);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 6);
}

SKYPAT_F(Operator_BatchNormalization, test_batchnorm_epsilon) {
  const float input_0[] = {
      -0.62805635,  0.79715514,  1.4931481,   -0.21843122, 0.24073194,
      0.80366343,   -2.0132728,  1.4697065,   1.51092,     -1.812751,
      1.4668785,    -2.287044,   -0.36540797, 0.016963094, -1.2519028,
      0.6261822,    0.09913124,  0.22666802,  -0.29512343, -1.3370225,
      -1.0468496,   -1.9296511,  -0.45711595, 2.0399337,   0.5052602,
      -1.9968128,   0.9024503,   1.1141491,   -0.20060998, -0.4082986,
      0.22819048,   1.4659483,   1.887411,    -0.51114786, -0.47570837,
      -0.7759874,   -0.7079053,  1.0927674,   -0.04264211, -0.12961113,
      -0.66181105,  0.04338665,  -1.0605164,  1.8929648,   -0.98793787,
      -0.1180752,   0.8361751,   0.8265745,   1.6693792,   0.36219582,
      -0.071045674, -0.56905866, 1.8875214,   0.66933864,  2.1415083,
      -0.061154667, -0.9681008,  -0.326678,   1.542832,    0.47700012,
      1.076754,     0.18056513,  -0.63766223, 0.22185576,  -1.4285206,
      -1.2920554,   -0.9879347,  0.664247,    -1.0384481,  -1.2564831,
      -1.7584897,   2.1671808,   -0.57657903, 1.1453364,   -2.1040883,
      0.9107052,    -0.7439822,  0.7763961,   -0.72390425, -1.0335757,
      -0.2650163,   -0.55045426, 1.3469605,   -1.4175599,  -0.87946427,
      -1.8336893,   0.500727,    0.8055791,   0.9364005,   0.4251598,
      0.020420583,  -1.3634576,  -0.24492845, -1.8026285,  1.6915708,
      1.104161,     0.8652972,   0.39394796,  0.5334181,   1.9145999,
      0.26876262,   1.2987323,   1.4221952,   0.9865109,   -1.2056373,
      -0.1440221,   -0.29712388, -1.4386973,  1.2322553,   -1.6127064,
      -1.1419197,   -0.69758195, -1.5606647,  -0.82928306, 0.18537109,
      0.29513776,   0.6746203,   -0.18160562, 0.86400235,  -0.63870436};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  const float input_1[] = {-0.43897334, 1.4216152, 0.83289856};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  const float input_2[] = {1.5007718, -0.900441, -1.4958694};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {3};
  const float input_3[] = {0.54763097, 1.3479253, 0.84890485};
  const int32_t input_3_ndim = 1;
  const int32_t input_3_dims[] = {3};
  const float input_4[] = {0.9359342, 0.13282038, 0.05419626};
  const int32_t input_4_ndim = 1;
  const int32_t input_4_dims[] = {3};
  float output_0[120];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {2, 3, 4, 5};
  const float answer_0[] = {
      2.0314112,  1.3881506,    1.0740182,   1.8465294,   1.6392888,
      1.385213,   2.6566205,    1.0845985,   1.065997,    2.566116,
      1.0858748,  2.7801852,    1.9128664,   1.7402855,   2.3129807,
      1.4653181,  1.7031994,    1.6456364,   1.8811439,   2.351399,
      -9.908924,  -13.229779,   -7.6905084,  1.7027037,   -4.0703144,
      -13.482423, -2.576195,    -1.7798426,  -6.725604,   -7.506871,
      -5.1125746, -0.45647088,  1.1289554,   -7.8937616,  -7.760448,
      -8.890015,  -8.633908,    -1.8602748,  -6.1313725,  -6.458526,
      -6.462022,  -4.143837,    -7.7726793,  1.9362526,   -7.534093,
      -4.6746073, -1.5377158,   -1.5692756,  1.2012632,   -3.0958202,
      -4.520008,  -6.157119,    1.9183583,   -2.0861545,  2.7532856,
      -4.4874935, -7.4688835,   -5.3603444,  0.7852664,   -2.7184258,
      1.2619553,  1.6664448,    2.0357468,   1.6478084,   2.392696,
      2.3311033,  2.19384,      1.4481379,   2.216639,    2.3150477,
      2.5416255,  0.7697977,    2.0081773,   1.231001,    2.6976094,
      1.3369004,  2.0837336,    1.39752,     2.0746715,   2.2144399,
      -6.9678826, -8.041621,    -0.90407014, -11.303434,  -9.279266,
      -12.868797, -4.0873675,   -2.9405978,  -2.448484,   -4.3716307,
      -5.894148,  -11.0999155,  -6.892318,   -12.751955,  0.39225847,
      -1.817415,  -2.7159548,   -4.489041,   -3.9643924,  1.2312326,
      -3.4029617, -0.017158866, 0.38869882,  -1.0435193,  -8.249733,
      -4.7599025, -5.2631917,   -9.015868,   -0.23568738, -9.587885,
      -8.040276,  -6.579611,    -9.416809,   -7.0125494,  -3.6770933,
      -3.3162591, -2.0687923,   -4.88345,    -1.4462396,  -6.3860636};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float output_2[] = {};
  const int32_t output_2_ndim = 0;
  const int32_t output_2_dims[] = {};
  const float output_3[] = {};
  const int32_t output_3_ndim = 0;
  const int32_t output_3_dims[] = {};
  const float output_4[] = {};
  const int32_t output_4_ndim = 0;
  const int32_t output_4_dims[] = {};
  const float epsilon = 0.009999999776482582;
  const int32_t spatial = 0;
  const float momentum = 0;
  ONNC_RUNTIME_batchnormalization_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)output_0, output_0_ndim,
      output_0_dims, (float *)output_1, output_1_ndim, output_1_dims,
      (float *)output_2, output_2_ndim, output_2_dims, (float *)output_3,
      output_3_ndim, output_3_dims, (float *)output_4, output_4_ndim,
      output_4_dims, epsilon, momentum, spatial);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}
