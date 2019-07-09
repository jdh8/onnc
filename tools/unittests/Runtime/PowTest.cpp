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
SKYPAT_F(Operator_Pow, test_pow_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  const float   input_1[]      = {4.0, 5.0, 6.0};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {1.0, 32.0, 729.0};
  using dragonite::norm;

  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                         output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Pow, test_pow)
{
  const float input_0[] = {
    0.31100795, 0.27400425,  0.7654217,  0.5560881,  0.50632834,  0.06403357, 0.934882,   0.04646228, 0.33790275,
    0.46083075, 0.8989158,   0.13347715, 0.6586091,  0.057237107, 0.7238848,  0.23105648, 0.5493025,  0.7210664,
    0.05184538, 0.43681365,  0.64791685, 0.26402912, 0.21715684,  0.96721715, 0.9318778,  0.04487318, 0.6134649,
    0.3932346,  0.630477,    0.60661006, 0.26264155, 0.62204933,  0.36305207, 0.24488148, 0.57635576, 0.44211107,
    0.07475836, 0.33526322,  0.92708325, 0.47479954, 0.30360097,  0.604705,   0.33858615, 0.16421796, 0.8490698,
    0.1294049,  0.18734266,  0.18725342, 0.33533674, 0.9588882,   0.86919606, 0.5102082,  0.02702575, 0.24020953,
    0.39013785, 0.011272415, 0.94318044, 0.13477278, 0.4987753,   0.37908673};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float   input_1[]      = {
    -6.5085464, -3.231985,  9.266393,   4.069364,   3.4906852,  4.409999,   -5.096386,  -1.4147401,  -5.585597,
    -8.440679,  0.27477035, -0.7267917, 5.9662347,  -7.8648505, 5.748658,   7.911044,   0.104361944, 0.72947973,
    3.2453,     1.7821848,  1.7566204,  -4.7659054, -7.899381,  -3.4568014, 9.253858,   3.9168947,   -6.12258,
    8.619014,   0.4661637,  7.3450937,  -5.7822456, 7.263121,   -1.8207533, 4.501512,   -1.6675446,  3.1053474,
    -0.8760549, 8.731957,   -7.0691257, -7.434528,  -2.68793,   -3.3319597, -2.6223247, 6.4599595,   6.9849496,
    9.732223,   1.0124649,  0.43386808, 9.586951,   -3.0232444, -6.331959,  9.520901,   2.562972,    8.746953,
    4.9937644,  9.157869,   -3.049877,  -3.599257,  2.449387,   8.667887};
  const int32_t input_1_ndim   = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    2001.3373,   65.63871,      0.08398058,    0.091811374,  0.09295355,   5.4482784E-06, 1.4094013,   76.86105,
    428.5283,    691.733,       0.9711434,     4.321624,     0.08277333,   5897655300.0,  0.15605861,  9.254357E-06,
    0.93939066,  0.7877635,     6.7429275E-05, 0.22852902,   0.46656367,   570.6275,      173411.86,   1.1221236,
    0.52053773,  5.2477667E-06, 19.919317,     0.0003208468, 0.8065162,    0.025436113,   2277.1062,   0.03180715,
    6.3268576,   0.0017757337,  2.50645,       0.079296105,  9.699199,     7.172822E-05,  1.7078187,   254.09332,
    24.633886,   5.3442664,     17.114338,     8.543764E-06, 0.31891364,   2.2767055E-09, 0.18347216,  0.48342654,
    2.82365E-05, 1.1353242,     2.4294274,     0.0016500315, 9.565115E-05, 3.8198996E-06, 0.009091581, 1.447524E-18,
    1.1953161,   1357.6426,     0.181992,      0.00022312785};
  using dragonite::norm;

  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                         output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Pow, test_pow_bcast_scalar)
{
  const float   input_0[]      = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  const float   input_1[]      = {2.0};
  const int32_t input_1_ndim   = 0;
  const int32_t input_1_dims[] = {};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {1.0, 4.0, 9.0};
  using dragonite::norm;

  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                         output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Pow, test_pow_bcast_array)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 3};
  const float   input_1[]      = {1.0, 2.0, 3.0};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {3};
  float         output_0[6];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {2, 3};
  const float   answer_0[]      = {1.0, 4.0, 27.0, 4.0, 25.0, 216.0};
  using dragonite::norm;

  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                         output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}
