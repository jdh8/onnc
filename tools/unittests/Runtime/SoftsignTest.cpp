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
SKYPAT_F(Operator_Softsign, test_softsign_example) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-0.5, 0.0, 0.5};
  ONNC_RUNTIME_softsign_float(nullptr, input_0, input_0_ndim, input_0_dims,
                              output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Softsign, test_softsign) {
  const float input_0[] = {
      -0.35125846, 1.8592058,   0.107127845,  0.1881215,   -1.4387773,
      0.2278479,   -1.0301719,  -0.6761962,   0.44399557,  -0.47115913,
      1.5134399,   1.2920711,   0.18505065,   0.07243496,  -0.18096443,
      0.3238141,   0.47004437,  -0.25432622,  -1.1642213,  0.25672945,
      0.17687148,  -0.67412215, -0.054402582, -0.8167593,  0.60266304,
      0.15716736,  0.18483591,  0.7246238,    2.1916342,   0.03952924,
      0.58853,     1.0862365,   -0.09334516,  0.89742255,  1.2546049,
      0.012417097, 2.8417673,   -1.74725,     -0.77271074, -1.1648754,
      1.1488867,   0.27840653,  -0.74882793,  0.7987616,   -0.29160014,
      2.6300569,   -0.5040947,  1.0890872,    -1.007032,   0.5389986,
      -0.44990212, -1.30063,    -2.0500238,   -0.28523704, 0.98187065,
      0.039205875, -1.4161588,  1.4106215,    0.42475486,  0.7822275};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -0.25994912, 0.6502526,   0.09676194,   0.15833522,  -0.5899584,
      0.18556687,  -0.50743085, -0.40341112,  0.3074771,   -0.3202639,
      0.6021389,   0.5637134,   0.15615422,   0.06754252,  -0.15323444,
      0.24460691,  0.31974843,  -0.20275924,  -0.53794,    0.20428379,
      0.15028954,  -0.40267202, -0.051595647, -0.44956934, 0.37603852,
      0.13582078,  0.15600127,  0.4201634,    0.6866809,   0.038026102,
      0.37048715,  0.52066797,  -0.08537574,  0.47296926,  0.55646336,
      0.012264804, 0.7397031,   -0.6359996,   -0.43589216, -0.5380796,
      0.53464276,  0.21777621,  -0.42818844,  0.44406196,  -0.22576658,
      0.72452223,  -0.33514825, 0.5213221,    -0.5017519,  0.35022682,
      -0.3102983,  -0.5653364,  -0.6721337,   -0.22193341, 0.4954262,
      0.037726764, -0.58611995, 0.5851692,    0.29812488,  0.4389044};
  ONNC_RUNTIME_softsign_float(nullptr, input_0, input_0_ndim, input_0_dims,
                              output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
