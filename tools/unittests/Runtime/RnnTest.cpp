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
SKYPAT_F(Operator_RNN, test_simple_rnn_defaults) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 2};
  const float input_1[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 4, 2};
  const float input_2[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 4, 4};
  const float *input_3 = nullptr;
  const int32_t input_3_ndim = 0;
  const int32_t *input_3_dims = nullptr;
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[12];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[] = {0.2913126, 0.2913126, 0.2913126, 0.2913126,
                            0.6043678, 0.6043678, 0.6043678, 0.6043678,
                            0.800499,  0.800499,  0.800499,  0.800499};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 4;
  const float clip = INFINITY;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Tanh", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_rnn_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}

SKYPAT_F(Operator_RNN, test_simple_rnn_with_initial_bias) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 3};
  const float input_1[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 5, 3};
  const float input_2[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 5, 5};
  const float input_3[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 10};
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[15];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[] = {0.6043678, 0.6043678, 0.6043678, 0.6043678,
                            0.6043678, 0.9216685, 0.9216685, 0.9216685,
                            0.9216685, 0.9216685, 0.9866143, 0.9866143,
                            0.9866143, 0.9866143, 0.9866143};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 5;
  const float clip = INFINITY;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Tanh", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_rnn_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  ASSERT_TRUE(relative_error(output_0, answer_0, 15) < 1e-5f);
}

SKYPAT_F(Operator_RNN, test_rnn_seq_length) {
  const float input_0[] = {1.0,  2.0,  3.0,  4.0,  5.0,  6.0,
                           7.0,  8.0,  9.0,  10.0, 11.0, 12.0,
                           13.0, 14.0, 15.0, 16.0, 17.0, 18.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 3};
  const float input_1[] = {-0.40317693, 1.222445,   0.20827498, 0.97663903,
                           0.3563664,   0.7065732,  0.01050002, 1.7858706,
                           0.12691209,  0.40198937, 1.8831507,  -1.347759,
                           -1.270485,   0.9693967,  -1.1731234};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 5, 3};
  const float input_2[] = {
      1.9436212,   -0.41361898, -0.7474548,  1.922942,   1.4805148,
      1.867559,    0.90604466,  -0.86122566, 1.9100649,  -0.26800337,
      0.8024564,   0.947252,    -0.15501009, 0.61407936, 0.9222067,
      0.37642553,  -1.0994008,  0.2982382,   1.3263859,  -0.69456786,
      -0.14963454, -0.43515354, 1.8492638,   0.67229474, 0.40746182};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 5, 5};
  const float input_3[] = {-0.76991606, 0.5392492,  -0.6743327, 0.031830557,
                           -0.6358461,  0.67643327, 0.57659084, -0.20829876,
                           0.3960067,   -1.0930616};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 10};
  const float *input_4 = nullptr;
  const int32_t input_4_ndim = 0;
  const int32_t *input_4_dims = nullptr;
  const float *input_5 = nullptr;
  const int32_t input_5_ndim = 0;
  const int32_t *input_5_dims = nullptr;
  float output_0[15];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[] = {1.0, 1.0,  1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
                            1.0, -1.0, 1.0, 1.0, 1.0,  1.0, -1.0};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  const int32_t hidden_size = 5;
  const float clip = INFINITY;
  const float activation_beta[] = {0, 0};
  const int32_t number_of_activation_beta = 2;
  const char *activations[] = {"Tanh", "Tanh"};
  const int32_t number_of_activations = 2;
  const char direction[] = "forward";
  const float activation_alpha[] = {1, 1};
  const int32_t number_of_activation_alpha = 2;
  ONNC_RUNTIME_rnn_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
      input_5_dims, output_0, output_0_ndim, output_0_dims, output_1,
      output_1_ndim, output_1_dims, const_cast<float *>(activation_alpha),
      number_of_activation_alpha, const_cast<float *>(activation_beta),
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  ASSERT_TRUE(relative_error(output_0, answer_0, 15) < 1e-5f);
}
