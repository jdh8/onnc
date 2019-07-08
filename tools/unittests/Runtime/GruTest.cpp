#if defined(__GNUC__) || defined(_MSC_VER)
#define restrict __restrict
#else
#define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "relative-error.hpp"
#include <skypat/skypat.h>
SKYPAT_F(Operator_GRU, test_gru_defaults) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 2};
  const float input_1[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 15, 2};
  const float input_2[] = {
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
      0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 15, 5};
  const float *input_3 = nullptr;
  const int32_t input_3_ndim = 0;
  const int32_t *input_3_dims = nullptr;
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[15];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[] = {0.12397026, 0.12397026, 0.12397026, 0.12397026,
                            0.12397026, 0.20053662, 0.20053662, 0.20053662,
                            0.20053662, 0.20053662, 0.19991654, 0.19991654,
                            0.19991654, 0.19991654, 0.19991654};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 5;
  const float clip = INFINITY;
  const int32_t linear_before_reset = 0;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Sigmoid", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_gru_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(relative_error(output_0, answer_0, 15) < 1e-5f);
}

SKYPAT_F(Operator_GRU, test_gru_with_initial_bias) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 3};
  const float input_1[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 9, 3};
  const float input_2[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 9, 3};
  const float input_3[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 18};
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[9];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 3};
  const float answer_0[] = {0.20053662, 0.20053662, 0.20053662,
                            0.15482338, 0.15482338, 0.15482338,
                            0.07484276, 0.07484276, 0.07484276};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 3;
  const float clip = INFINITY;
  const int32_t linear_before_reset = 0;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Sigmoid", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_gru_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(relative_error(output_0, answer_0, 9) < 1e-5f);
}

SKYPAT_F(Operator_GRU, test_gru_seq_length) {
  const float input_0[] = {1.0,  2.0,  3.0,  4.0,  5.0,  6.0,
                           7.0,  8.0,  9.0,  10.0, 11.0, 12.0,
                           13.0, 14.0, 15.0, 16.0, 17.0, 18.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 3};
  const float input_1[] = {
      -0.14145947, 0.15629987,  -0.8696651,   0.39270157,  -0.009115411,
      2.0864308,   -1.2779448,  -0.42339265,  0.9324587,   0.33940366,
      -1.5306141,  1.4368279,   -0.24395616,  0.9690903,   0.5733552,
      -0.14629014, 0.20412289,  0.46920726,   -0.06843096, 0.3388744,
      0.64640737,  -0.87271535, -0.2824417,   -0.9504674,  -0.91583234,
      -0.943453,   -0.09839164, -0.08138952,  1.4305339,   -0.095075205,
      -2.437213,   1.2676942,   -0.6419407,   1.2138464,   0.721314,
      -0.39057,    1.924383,    1.1707721,    0.454107,    0.6755402,
      -1.2595876,  -0.3999741,  0.0054785307, -0.41697863, -1.4381818};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 15, 3};
  const float input_2[] = {
      0.34635618,  0.5034088,   -0.5805105,   -0.9902393,  0.24682087,
      -0.636053,   0.3427419,   0.3360334,    0.3982732,   -0.081932455,
      -0.2394276,  -1.4802802,  0.9584542,    1.8984979,   0.37336302,
      1.0209273,   0.6814716,   2.3516529,    1.1145258,   -0.7756634,
      -0.3002846,  -0.3913888,  -0.091858484, -0.351136,   -0.20671156,
      -0.13871741, -1.9705613,  0.047438692,  -0.34903327, 0.6225668,
      0.6506504,   -1.652194,   -0.124538325, -0.60651606, 0.11648655,
      0.7462527,   0.5269936,   -1.524244,    -0.92970574, -0.28682673,
      -0.48664588, -0.99666446, 0.24180508,   0.4055842,   0.7405392,
      0.8865287,   0.5890587,   0.46647847,   -0.43806496, -0.53957254,
      0.67532116,  -1.6129255,  1.3663468,    0.5862357,   -0.903155,
      1.0495981,   1.0017868,   -0.4396629,   0.1464726,   0.4006156,
      -0.20765041, 0.58043265,  0.6111597,    -0.44814602, 0.16703556,
      -1.3143078,  0.3236361,   1.0735934,    -2.078388,   -1.4447336,
      -0.36385012, 0.43763283,  -1.4748638,   -1.2445614,  1.269193};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 15, 5};
  const float input_3[] = {
      0.20299082, -0.07647023, 0.0044486793, 0.82671803, 0.07355727,
      0.09844878, 1.5123485,   -0.23041695,  0.44818214, -0.9535058,
      0.2916974,  0.69797885,  0.041442897,  0.5206962,  -0.92924243,
      -0.9396329, 0.43336096,  -0.3500978,   -1.7441362, 0.963094,
      0.32169133, 0.66892505,  -0.19421501,  -1.0133176, -1.457069,
      -1.6871829, 1.5159851,   -1.7299223,   -1.970997,  0.4916091};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 30};
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[15];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[] = {
      -0.99999934, 0.0009184715,  0.9992182, -0.38732228, -0.0115327565,
      -1.0,        5.5699695E-07, 0.9999664, -0.20582445, -0.00023719217,
      -1.0,        3.370615E-10,  0.9999995, -0.10831358, -4.8241527E-06};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 5;
  const float clip = INFINITY;
  const int32_t linear_before_reset = 0;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Sigmoid", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_gru_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(relative_error(output_0, answer_0, 15) < 1e-5f);
}
