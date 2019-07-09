#if defined(__GNUC__) || defined(_MSC_VER)
#  define restrict __restrict
#else
#  define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "norm.hpp"
#include <skypat/skypat.h>
SKYPAT_F(Operator_GRU, test_gru_defaults)
{
  const float    input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 3, 2};
  const float    input_1[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 15, 2};
  const float    input_2[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 15, 5};
  const float*   input_3        = nullptr;
  const int32_t  input_3_ndim   = 0;
  const int32_t* input_3_dims   = nullptr;
  const float*   input_4        = nullptr;
  const int32_t  input_4_ndim   = 0;
  const int32_t* input_4_dims   = nullptr;
  const float*   input_5        = nullptr;
  const int32_t  input_5_ndim   = 0;
  const int32_t* input_5_dims   = nullptr;
  float          output_0[15];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 3, 5};
  const float    answer_0[]                 = {0.12397026, 0.12397026, 0.12397026, 0.12397026, 0.12397026,
                            0.20053662, 0.20053662, 0.20053662, 0.20053662, 0.20053662,
                            0.19991654, 0.19991654, 0.19991654, 0.19991654, 0.19991654};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  const int32_t  hidden_size                = 5;
  const int32_t  linear_before_reset        = 0;
  const char     direction[]                = "forward";
  const float    activation_beta[]          = {0, 0};
  const int32_t  number_of_activation_beta  = 2;
  const float    activation_alpha[]         = {1, 1};
  const int32_t  number_of_activation_alpha = 2;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh"};
  const int32_t  number_of_activations      = 2;
  using dragonite::norm;

  ONNC_RUNTIME_gru_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2,
                         input_2_ndim, input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim,
                         input_4_dims, input_5, input_5_ndim, input_5_dims, output_0, output_0_ndim, output_0_dims,
                         output_1, output_1_ndim, output_1_dims, const_cast<float*>(activation_alpha),
                         number_of_activation_alpha, const_cast<float*>(activation_beta), number_of_activation_beta,
                         activations, number_of_activations, clip, direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(norm(answer_0, output_0, 15) <= 1e-5 * norm(answer_0, 15));
}

SKYPAT_F(Operator_GRU, test_gru_with_initial_bias)
{
  const float    input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 3, 3};
  const float    input_1[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 9, 3};
  const float    input_2[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 9, 3};
  const float    input_3[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t  input_3_ndim   = 2;
  const int32_t  input_3_dims[] = {1, 18};
  const float*   input_4        = nullptr;
  const int32_t  input_4_ndim   = 0;
  const int32_t* input_4_dims   = nullptr;
  const float*   input_5        = nullptr;
  const int32_t  input_5_ndim   = 0;
  const int32_t* input_5_dims   = nullptr;
  float          output_0[9];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 3, 3};
  const float    answer_0[]                 = {0.20053662, 0.20053662, 0.20053662, 0.15482338, 0.15482338,
                            0.15482338, 0.07484276, 0.07484276, 0.07484276};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  const int32_t  hidden_size                = 3;
  const int32_t  linear_before_reset        = 0;
  const char     direction[]                = "forward";
  const float    activation_beta[]          = {0, 0};
  const int32_t  number_of_activation_beta  = 2;
  const float    activation_alpha[]         = {1, 1};
  const int32_t  number_of_activation_alpha = 2;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh"};
  const int32_t  number_of_activations      = 2;
  using dragonite::norm;

  ONNC_RUNTIME_gru_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2,
                         input_2_ndim, input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim,
                         input_4_dims, input_5, input_5_ndim, input_5_dims, output_0, output_0_ndim, output_0_dims,
                         output_1, output_1_ndim, output_1_dims, const_cast<float*>(activation_alpha),
                         number_of_activation_alpha, const_cast<float*>(activation_beta), number_of_activation_beta,
                         activations, number_of_activations, clip, direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(norm(answer_0, output_0, 9) <= 1e-5 * norm(answer_0, 9));
}

SKYPAT_F(Operator_GRU, test_gru_seq_length)
{
  const float   input_0[]      = {1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,
                           10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 3};
  const float   input_1[]      = {
    -0.043314952, -1.019314,    0.23779412,  0.08175103,  1.1142192,   -0.8523093,  2.1824274,     -0.13174225,
    -3.2591233,   0.93447614,   1.2999996,   -1.8213494,  -0.29659572, 1.5936377,   0.4322273,     -0.10017771,
    -0.53495854,  -0.116974264, 0.9800366,   -0.6152288,  0.5013462,   0.033330955, 0.51269054,    -0.898808,
    1.4997867,    -0.1724834,   0.6864317,   1.3737723,   -1.4965702,  0.649875,    -0.0018122777, -0.692358,
    1.3780599,    -0.5585421,   -0.79715616, -1.0726401,  -1.7065121,  0.55122006,  -0.29662538,   -0.89236176,
    0.6156694,    0.82753116,   -1.8209474,  -0.22358307, -0.31301624};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 15, 3};
  const float    input_2[] = {-0.5807489,  -0.5325666,   -0.29373273, 0.705488,    -1.27724,    -1.6149656,  -0.8742862,
                           0.34101275,  -0.068776675, -0.5961883,  1.6851256,   0.13530125,  -0.48998538, -1.6156826,
                           1.7979498,   0.31718177,   0.6261246,   -0.7620508,  0.13471235,  0.7138864,   0.62392884,
                           -0.44346577, -0.10204875,  1.544452,    -0.17371874, -1.6503178,  -1.2716733,  1.2497865,
                           -0.51056784, 0.002449487,  -0.21397486, 1.1841677,   -0.51149243, -0.25099903, -1.3802423,
                           -0.11793291, -1.8156711,   -0.16290218, 0.7313013,   0.14576083,  0.12328743,  -0.0061508464,
                           0.49742645,  0.35337797,   -1.334512,   1.2602637,   2.4217396,   -0.8660945,  -0.98536885,
                           1.546389,    0.8306132,    -0.37362358, -2.8423882,  -1.6764375,  -1.1356151,  2.0864184,
                           -0.08484734, 0.8730494,    1.6390615,   1.2305721,   0.13779908,  1.9065329,   -0.8090206,
                           -0.50879705, -0.61173105,  1.2885544,   1.2543435,   -0.3730818,  0.1414854,   -1.7475294,
                           -0.01819713, -0.7481895,   1.7719576,   -1.7745404,  -0.06545862};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 15, 5};
  const float    input_3[]      = {1.0735136,   2.5983825,   -0.9207675,  1.1009611,  0.7467011, 0.83722067,
                           1.2293862,   -0.40461946, -0.56941986, 0.22557911, 1.585617,  -0.18825677,
                           -0.80171305, 1.0935292,   0.4349456,   0.53420377, 1.5711474, 0.3758251,
                           -0.38168406, -0.15646581, 0.7707287,   0.3631234,  0.1757824, 1.1217912,
                           -1.17113,    0.23364426,  0.5607129,   0.18184267, 1.2538985, -0.8804708};
  const int32_t  input_3_ndim   = 2;
  const int32_t  input_3_dims[] = {1, 30};
  const float*   input_4        = nullptr;
  const int32_t  input_4_ndim   = 0;
  const int32_t* input_4_dims   = nullptr;
  const float*   input_5        = nullptr;
  const int32_t  input_5_ndim   = 0;
  const int32_t* input_5_dims   = nullptr;
  float          output_0[15];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 3, 5};
  const float    answer_0[]                 = {0.9992325,  -0.02196836,   -1.0, 0.77721196, -0.008334749,
                            0.999993,   -0.0089805145, -1.0, 0.4966387,  -4.699586E-05,
                            0.99999994, -0.0033139852, -1.0, 0.221283,   -2.6244788E-07};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  const int32_t  hidden_size                = 5;
  const int32_t  linear_before_reset        = 0;
  const char     direction[]                = "forward";
  const float    activation_beta[]          = {0, 0};
  const int32_t  number_of_activation_beta  = 2;
  const float    activation_alpha[]         = {1, 1};
  const int32_t  number_of_activation_alpha = 2;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh"};
  const int32_t  number_of_activations      = 2;
  using dragonite::norm;

  ONNC_RUNTIME_gru_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2,
                         input_2_ndim, input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim,
                         input_4_dims, input_5, input_5_ndim, input_5_dims, output_0, output_0_ndim, output_0_dims,
                         output_1, output_1_ndim, output_1_dims, const_cast<float*>(activation_alpha),
                         number_of_activation_alpha, const_cast<float*>(activation_beta), number_of_activation_beta,
                         activations, number_of_activations, clip, direction, hidden_size, linear_before_reset);
  ASSERT_TRUE(norm(answer_0, output_0, 15) <= 1e-5 * norm(answer_0, 15));
}
