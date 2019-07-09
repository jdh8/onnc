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
SKYPAT_F(Operator_LSTM, test_lstm_defaults)
{
  const float    input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 3, 2};
  const float    input_1[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 12, 2};
  const float    input_2[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 12, 3};
  const float*   input_3        = nullptr;
  const int32_t  input_3_ndim   = 0;
  const int32_t* input_3_dims   = nullptr;
  const float*   input_4        = nullptr;
  const int32_t  input_4_ndim   = 0;
  const int32_t* input_4_dims   = nullptr;
  const float*   input_5        = nullptr;
  const int32_t  input_5_ndim   = 0;
  const int32_t* input_5_dims   = nullptr;
  const float*   input_6        = nullptr;
  const int32_t  input_6_ndim   = 0;
  const int32_t* input_6_dims   = nullptr;
  const float*   input_7        = nullptr;
  const int32_t  input_7_ndim   = 0;
  const int32_t* input_7_dims   = nullptr;
  float          output_0[9];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 3, 3};
  const float    answer_0[]                 = {0.09524119, 0.09524119, 0.09524119, 0.25606444, 0.25606444,
                            0.25606444, 0.40323776, 0.40323776, 0.40323776};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  float*         output_2                   = nullptr;
  const int32_t  output_2_ndim              = 0;
  const int32_t* output_2_dims              = nullptr;
  const int32_t  hidden_size                = 3;
  const char     direction[]                = "forward";
  const int32_t  input_forget               = 0;
  const float    activation_beta[]          = {0, 0, 0};
  const int32_t  number_of_activation_beta  = 3;
  const float    activation_alpha[]         = {1, 1, 1};
  const int32_t  number_of_activation_alpha = 3;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh", "Tanh"};
  const int32_t  number_of_activations      = 3;
  using dragonite::norm;

  ONNC_RUNTIME_lstm_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
    input_5_dims, input_6, input_6_ndim, input_6_dims, input_7, input_7_ndim, input_7_dims, output_0, output_0_ndim,
    output_0_dims, output_1, output_1_ndim, output_1_dims, output_2, output_2_ndim, output_2_dims,
    const_cast<float*>(activation_alpha), number_of_activation_alpha, const_cast<float*>(activation_beta),
    number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size, input_forget);
  ASSERT_TRUE(norm(answer_0, output_0, 9) <= 1e-5 * norm(answer_0, 9));
}

SKYPAT_F(Operator_LSTM, test_lstm_with_initial_bias)
{
  const float    input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 3, 3};
  const float    input_1[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 16, 3};
  const float    input_2[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 16, 4};
  const float    input_3[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t  input_3_ndim   = 2;
  const int32_t  input_3_dims[] = {1, 32};
  const float*   input_4        = nullptr;
  const int32_t  input_4_ndim   = 0;
  const int32_t* input_4_dims   = nullptr;
  const float*   input_5        = nullptr;
  const int32_t  input_5_ndim   = 0;
  const int32_t* input_5_dims   = nullptr;
  const float*   input_6        = nullptr;
  const int32_t  input_6_ndim   = 0;
  const int32_t* input_6_dims   = nullptr;
  const float*   input_7        = nullptr;
  const int32_t  input_7_ndim   = 0;
  const int32_t* input_7_dims   = nullptr;
  float          output_0[12];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 3, 4};
  const float    answer_0[]                 = {0.25606444, 0.25606444, 0.25606444, 0.25606444, 0.5367278, 0.5367278,
                            0.5367278,  0.5367278,  0.6672132,  0.6672132,  0.6672132, 0.6672132};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  float*         output_2                   = nullptr;
  const int32_t  output_2_ndim              = 0;
  const int32_t* output_2_dims              = nullptr;
  const int32_t  hidden_size                = 4;
  const char     direction[]                = "forward";
  const int32_t  input_forget               = 0;
  const float    activation_beta[]          = {0, 0, 0};
  const int32_t  number_of_activation_beta  = 3;
  const float    activation_alpha[]         = {1, 1, 1};
  const int32_t  number_of_activation_alpha = 3;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh", "Tanh"};
  const int32_t  number_of_activations      = 3;
  using dragonite::norm;

  ONNC_RUNTIME_lstm_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
    input_5_dims, input_6, input_6_ndim, input_6_dims, input_7, input_7_ndim, input_7_dims, output_0, output_0_ndim,
    output_0_dims, output_1, output_1_ndim, output_1_dims, output_2, output_2_ndim, output_2_dims,
    const_cast<float*>(activation_alpha), number_of_activation_alpha, const_cast<float*>(activation_beta),
    number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size, input_forget);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}

SKYPAT_F(Operator_LSTM, test_lstm_with_peepholes)
{
  const float    input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 2, 4};
  const float    input_1[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 12, 4};
  const float    input_2[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1,
                           0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_2_ndim   = 3;
  const int32_t  input_2_dims[] = {1, 12, 3};
  const float    input_3[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                           0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t  input_3_ndim   = 2;
  const int32_t  input_3_dims[] = {1, 24};
  const float    input_4[]      = {1, 1};
  const int32_t  input_4_ndim   = 1;
  const int32_t  input_4_dims[] = {2};
  const float    input_5[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t  input_5_ndim   = 3;
  const int32_t  input_5_dims[] = {1, 2, 3};
  const float    input_6[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t  input_6_ndim   = 3;
  const int32_t  input_6_dims[] = {1, 2, 3};
  const float    input_7[]      = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
  const int32_t  input_7_ndim   = 2;
  const int32_t  input_7_dims[] = {1, 9};
  float          output_0[6];
  const int32_t  output_0_ndim              = 3;
  const int32_t  output_0_dims[]            = {1, 2, 3};
  const float    answer_0[]                 = {0.3750691, 0.3750691, 0.3750691, 0.68013096, 0.68013096, 0.68013096};
  float*         output_1                   = nullptr;
  const int32_t  output_1_ndim              = 0;
  const int32_t* output_1_dims              = nullptr;
  float*         output_2                   = nullptr;
  const int32_t  output_2_ndim              = 0;
  const int32_t* output_2_dims              = nullptr;
  const int32_t  hidden_size                = 3;
  const char     direction[]                = "forward";
  const int32_t  input_forget               = 0;
  const float    activation_beta[]          = {0, 0, 0};
  const int32_t  number_of_activation_beta  = 3;
  const float    activation_alpha[]         = {1, 1, 1};
  const int32_t  number_of_activation_alpha = 3;
  const float    clip                       = INFINITY;
  const char*    activations[]              = {"Sigmoid", "Tanh", "Tanh"};
  const int32_t  number_of_activations      = 3;
  using dragonite::norm;

  ONNC_RUNTIME_lstm_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim, input_4_dims, input_5, input_5_ndim,
    input_5_dims, input_6, input_6_ndim, input_6_dims, input_7, input_7_ndim, input_7_dims, output_0, output_0_ndim,
    output_0_dims, output_1, output_1_ndim, output_1_dims, output_2, output_2_ndim, output_2_dims,
    const_cast<float*>(activation_alpha), number_of_activation_alpha, const_cast<float*>(activation_beta),
    number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size, input_forget);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}
