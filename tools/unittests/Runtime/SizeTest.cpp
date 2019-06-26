#include "dragonite.hpp"
SKYPAT_F(Operator_Size, test_size_example) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 3};
  float output_0[1];
  const int32_t output_0_ndim = 0;
  const int32_t output_0_dims[] = {};
  const float answer_0[] = {6};
  ONNC_RUNTIME_size_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 1.0);
}

SKYPAT_F(Operator_Size, test_size) {
  const float input_0[] = {
      -0.40051618, 0.9634851,   -0.88878536, -0.06394701, -0.29690772,
      0.73142934,  -2.1440096,  -0.39760035, -0.23574309, 1.3469895,
      1.2049602,   0.96949273,  -1.037319,   -0.745262,   0.14864443,
      0.3363609,   -0.6311694,  0.2797018,   -0.37262043, 0.6793415,
      0.09301186,  -2.0908146,  0.6347771,   -0.11024703, 0.70030266,
      1.2566866,   -0.14950565, -0.42628053, -0.18000607, 0.25862744,
      0.53237784,  1.8937606,   0.16487893,  -0.5545384,  2.2709076,
      1.4452204,   0.31024963,  -1.580179,   -0.42173168, -1.420048,
      -0.0706661,  0.4075444,   -1.0391868,  -1.8161323,  -0.33780605,
      0.68575203,  0.3084806,   -0.8735337,  0.20588943,  -0.34108964,
      -0.23695147, -0.6114743,  -0.9008931,  0.8150326,   1.2274095,
      0.98150736,  0.8749287,   0.506682,    -0.6885869,  -0.73194796};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[1];
  const int32_t output_0_ndim = 0;
  const int32_t output_0_dims[] = {};
  const float answer_0[] = {60};
  ONNC_RUNTIME_size_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 1.0);
}
