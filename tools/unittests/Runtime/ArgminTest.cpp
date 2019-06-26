#include "dragonite.hpp"
SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_random) {
  const float input_0[] = {
      -4.7386484, 2.3397357, 4.141959,   -5.3159223, 0.5950114,  2.8090122,
      4.8034515,  -3.616223, -5.51661,   3.4111824,  -5.3109555, -2.183282,
      -5.8013983, 1.3519181, -6.2631655, 4.818832,   9.059735,   3.6181,
      9.380291,   -9.790748, 8.491554,   -6.638293,  -3.251693,  -6.6960673};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {2, 0, 2, 0, 0, 2, 0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 8);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[] = {1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_random) {
  const float input_0[] = {
      0.79122055, 9.581378,  2.5741405, -7.3851624,  -1.7420613, 2.77092,
      -2.1703851, 4.428802,  -3.614198, -0.42594898, -1.3548696, 2.5034688,
      1.7305014,  6.0654445, 8.52255,   -9.352282,   4.5631785,  0.85469943,
      -5.2237864, 3.4279737, 8.228386,  -4.6628647,  -0.9004092, -2.8744214};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[] = {2, 2, 1, 0, 0, 2, 1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 8);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[] = {0, 0};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_random) {
  const float input_0[] = {
      9.685191,  7.6520395,  -6.7862635, 0.557882,   -1.9194168, 0.9032159,
      5.887923,  -3.2318628, -7.420356,  -5.9699416, -8.037621,  -7.4046187,
      -9.730699, 8.424039,   0.45472547, 6.2036505,  6.180531,   -0.7556925,
      5.7732134, 7.650525,   -5.296038,  -2.1244166, -1.6795601, -6.7669363};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}
