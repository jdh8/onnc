#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_LSTM, test_lstm_defaults) {
  const float input_0[1][3][2] = {{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 2};
  const float input_1[1][12][2] = {
      {{0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 12, 2};
  const float input_2[1][12][3] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 12, 3};
  const float input_3[] = {};
  const int32_t input_3_ndim = 0;
  const int32_t input_3_dims[] = {};
  const float input_4[] = {};
  const int32_t input_4_ndim = 0;
  const int32_t input_4_dims[] = {};
  const float input_5[] = {};
  const int32_t input_5_ndim = 0;
  const int32_t input_5_dims[] = {};
  const float input_6[] = {};
  const int32_t input_6_ndim = 0;
  const int32_t input_6_dims[] = {};
  const float input_7[] = {};
  const int32_t input_7_ndim = 0;
  const int32_t input_7_dims[] = {};
  float output_0[1][3][3];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 3};
  const float answer_0[1][3][3] = {
      {{0.09524118900299072, 0.09524118900299072, 0.09524118900299072},
       {0.25606444478034973, 0.25606444478034973, 0.25606444478034973},
       {0.4032377600669861, 0.4032377600669861, 0.4032377600669861}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float output_2[] = {};
  const int32_t output_2_ndim = 0;
  const int32_t output_2_dims[] = {};
  const int32_t hidden_size = 3;
  const int32_t input_forget = 0;
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const auto direction = "NOTSET";
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_lstm_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)input_6, input_6_ndim, input_6_dims, (float *)input_7,
      input_7_ndim, input_7_dims, (float *)output_0, output_0_ndim,
      output_0_dims, (float *)output_1, output_1_ndim, output_1_dims,
      (float *)output_2, output_2_ndim, output_2_dims,
      (float *)activation_alpha, number_of_activation_alpha,
      (float *)activation_beta, number_of_activation_beta, activations,
      number_of_activations, clip, direction, hidden_size, input_forget);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 3; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_LSTM, test_lstm_with_initial_bias) {
  const float input_0[1][3][3] = {
      {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 3};
  const float input_1[1][16][3] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 16, 3};
  const float input_2[1][16][4] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 16, 4};
  const float input_3[1][32] = {{0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.10000000149011612,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.0}};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 32};
  const float input_4[] = {};
  const int32_t input_4_ndim = 0;
  const int32_t input_4_dims[] = {};
  const float input_5[] = {};
  const int32_t input_5_ndim = 0;
  const int32_t input_5_dims[] = {};
  const float input_6[] = {};
  const int32_t input_6_ndim = 0;
  const int32_t input_6_dims[] = {};
  const float input_7[] = {};
  const int32_t input_7_ndim = 0;
  const int32_t input_7_dims[] = {};
  float output_0[1][3][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[1][3][4] = {{{0.25606444478034973, 0.25606444478034973,
                                     0.25606444478034973, 0.25606444478034973},
                                    {0.536727786064148, 0.536727786064148,
                                     0.536727786064148, 0.536727786064148},
                                    {0.6672132015228271, 0.6672132015228271,
                                     0.6672132015228271, 0.6672132015228271}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float output_2[] = {};
  const int32_t output_2_ndim = 0;
  const int32_t output_2_dims[] = {};
  const int32_t hidden_size = 4;
  const int32_t input_forget = 0;
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const auto direction = "NOTSET";
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_lstm_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)input_6, input_6_ndim, input_6_dims, (float *)input_7,
      input_7_ndim, input_7_dims, (float *)output_0, output_0_ndim,
      output_0_dims, (float *)output_1, output_1_ndim, output_1_dims,
      (float *)output_2, output_2_ndim, output_2_dims,
      (float *)activation_alpha, number_of_activation_alpha,
      (float *)activation_beta, number_of_activation_beta, activations,
      number_of_activations, clip, direction, hidden_size, input_forget);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_LSTM, test_lstm_with_peepholes) {
  const float input_0[1][2][4] = {{{1.0, 2.0, 3.0, 4.0}, {5.0, 6.0, 7.0, 8.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 2, 4};
  const float input_1[1][12][4] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 12, 4};
  const float input_2[1][12][3] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 12, 3};
  const float input_3[1][24] = {{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 24};
  const float input_4[2] = {1, 1};
  const int32_t input_4_ndim = 1;
  const int32_t input_4_dims[] = {2};
  const float input_5[1][2][3] = {{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}};
  const int32_t input_5_ndim = 3;
  const int32_t input_5_dims[] = {1, 2, 3};
  const float input_6[1][2][3] = {{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}};
  const int32_t input_6_ndim = 3;
  const int32_t input_6_dims[] = {1, 2, 3};
  const float input_7[1][9] = {
      {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
       0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
       0.10000000149011612, 0.10000000149011612, 0.10000000149011612}};
  const int32_t input_7_ndim = 2;
  const int32_t input_7_dims[] = {1, 9};
  float output_0[1][2][3];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 2, 3};
  const float answer_0[1][2][3] = {
      {{0.37506911158561707, 0.37506911158561707, 0.37506911158561707},
       {0.6801309585571289, 0.6801309585571289, 0.6801309585571289}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float output_2[] = {};
  const int32_t output_2_ndim = 0;
  const int32_t output_2_dims[] = {};
  const int32_t hidden_size = 3;
  const int32_t input_forget = 0;
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const auto direction = "NOTSET";
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_lstm_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)input_6, input_6_ndim, input_6_dims, (float *)input_7,
      input_7_ndim, input_7_dims, (float *)output_0, output_0_ndim,
      output_0_dims, (float *)output_1, output_1_ndim, output_1_dims,
      (float *)output_2, output_2_ndim, output_2_dims,
      (float *)activation_alpha, number_of_activation_alpha,
      (float *)activation_beta, number_of_activation_beta, activations,
      number_of_activations, clip, direction, hidden_size, input_forget);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 2 * 3; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
