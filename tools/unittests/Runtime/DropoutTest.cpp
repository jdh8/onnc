#include "dragonite.hpp"
SKYPAT_F(Operator_Dropout, test_dropout_default) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float ratio = 0;
  ONNC_RUNTIME_dropout_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             (float *)output_1, output_1_ndim, output_1_dims,
                             ratio);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Dropout, test_dropout_random) {
  const float input_0[] = {
      0.06627449,  0.23723835,   0.8515664,   -0.17554203, 1.5094777,
      0.24873272,  -1.5502543,   -0.90171367, 0.7557386,   0.6887631,
      -0.23746502, -0.31936735,  0.52838767,  1.7084522,   0.39970756,
      1.3094364,   -0.43243763,  0.44660953,  -1.0042448,  0.13533427,
      0.42398968,  -0.053200338, 0.80378276,  0.594873,    0.4806278,
      0.25220594,  1.0085131,    -2.3872435,  1.1630601,   -0.03630254,
      2.4719822,   -0.55141926,  -1.8431138,  0.39012253,  0.7292931,
      0.9388013,   2.2073336,    -1.0168375,  1.4860256,   -0.17479825,
      -0.14079957, 0.18528484,   -0.12999213, -0.24088015, -1.1919793,
      0.59361404,  -1.2237632,   -2.7126195,  2.4596584,   -0.22559585,
      0.005736162, -0.6440964,   -0.77150226, 0.51196367,  -0.1687961,
      0.0919526,   -0.755106,    -0.08921673, 1.0265738,   0.47590798};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.06627449,  0.23723835,   0.8515664,   -0.17554203, 1.5094777,
      0.24873272,  -1.5502543,   -0.90171367, 0.7557386,   0.6887631,
      -0.23746502, -0.31936735,  0.52838767,  1.7084522,   0.39970756,
      1.3094364,   -0.43243763,  0.44660953,  -1.0042448,  0.13533427,
      0.42398968,  -0.053200338, 0.80378276,  0.594873,    0.4806278,
      0.25220594,  1.0085131,    -2.3872435,  1.1630601,   -0.03630254,
      2.4719822,   -0.55141926,  -1.8431138,  0.39012253,  0.7292931,
      0.9388013,   2.2073336,    -1.0168375,  1.4860256,   -0.17479825,
      -0.14079957, 0.18528484,   -0.12999213, -0.24088015, -1.1919793,
      0.59361404,  -1.2237632,   -2.7126195,  2.4596584,   -0.22559585,
      0.005736162, -0.6440964,   -0.77150226, 0.51196367,  -0.1687961,
      0.0919526,   -0.755106,    -0.08921673, 1.0265738,   0.47590798};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float ratio = 0.20000000298023224;
  ONNC_RUNTIME_dropout_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             (float *)output_1, output_1_ndim, output_1_dims,
                             ratio);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
