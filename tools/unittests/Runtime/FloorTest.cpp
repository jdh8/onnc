#include "dragonite.hpp"
SKYPAT_F(Operator_Floor, test_floor_example) {
  const float input_0[] = {-1.5, 1.2, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-2.0, 1.0, 2.0};
  ONNC_RUNTIME_floor_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Floor, test_floor) {
  const float input_0[] = {
      -0.36752188, 1.5690051,   1.8506932,    -0.78273606, 1.3095875,
      0.7623082,   -0.04763498, -0.65535307,  -1.9165742,  1.0152538,
      0.98172677,  0.63153,     -0.47492954,  0.079800695, -0.62179476,
      -0.49732512, 0.83165854,  -2.1496599,   -1.789782,   -0.07343762,
      -1.9305359,  -1.5345742,  1.9527293,    1.3314989,   1.0482403,
      1.0978857,   -0.7874322,  1.6289961,    -1.0875437,  -1.7251005,
      1.0048686,   -1.0121218,  1.3928875,    1.1372198,   1.6962422,
      -0.17150849, -0.6314267,  -1.7373824,   1.0833523,   -0.6129052,
      1.572128,    0.9390046,   -0.117400505, -1.33245,    -1.0069802,
      0.41581705,  1.6956971,   0.06287112,   0.4701257,   1.1988952,
      -1.8792999,  1.7089188,   1.8082964,    0.1390802,   -0.31620196,
      1.2224301,   -1.648856,   1.1157401,    0.39427525,  0.13706003};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.0, 1.0,  1.0,  -1.0, 1.0,  0.0,  -1.0, -1.0, -2.0, 1.0,  0.0, 0.0,
      -1.0, 0.0,  -1.0, -1.0, 0.0,  -3.0, -2.0, -1.0, -2.0, -2.0, 1.0, 1.0,
      1.0,  1.0,  -1.0, 1.0,  -2.0, -2.0, 1.0,  -2.0, 1.0,  1.0,  1.0, -1.0,
      -1.0, -2.0, 1.0,  -1.0, 1.0,  0.0,  -1.0, -2.0, -2.0, 0.0,  1.0, 0.0,
      0.0,  1.0,  -2.0, 1.0,  1.0,  0.0,  -1.0, 1.0,  -2.0, 1.0,  0.0, 0.0};
  ONNC_RUNTIME_floor_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
