#include "dragonite.hpp"
SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_random) {
  const float input_0[] = {
      -1.2191339, 3.6817157,  -4.5617323, -9.81378,   -9.472368, 0.39170164,
      -5.6257973, -9.436001,  0.75057554, -4.8188825, 1.8044119, 9.15932,
      -3.9317777, -3.1640134, 7.371627,   0.4720606,  -3.984718, -4.190951,
      4.997327,   -1.3437682, 8.8168335,  -4.4511347, 7.0531535, -7.5973043};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {2, 0, 2, 2, 2, 0, 0, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 8);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[] = {0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_random) {
  const float input_0[] = {
      3.0904133, 2.081071,    6.63203,   -4.0202403, 9.072109,  8.982568,
      -5.947535, 6.160058,    2.584016,  -2.0381222, 7.510055,  1.247958,
      -2.580031, -0.10717773, -2.453067, 3.3241768,  9.674695,  -6.6562424,
      -9.508869, 6.3449755,   4.3728204, -9.937804,  8.9642105, 1.1350847};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[] = {1, 1, 2, 1, 1, 0, 2, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 8);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[] = {1, 1};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_random) {
  const float input_0[] = {
      6.1212087,  1.5424889,  -5.267021,   3.7225504,  -9.276219,  2.2427602,
      7.9785347,  4.6386166,  -0.73645407, -2.0957918, -3.0949986, -2.9219303,
      -4.1007714, -3.1407034, 5.641354,    -1.8403687, 9.641227,   -3.0095005,
      7.6873007,  -5.5566864, 0.14472623,  9.650351,   -1.6304424, 0.39748943};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[] = {0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}
