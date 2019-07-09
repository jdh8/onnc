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
SKYPAT_F(Operator_Exp, test_exp_example)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {0.36787945, 1.0, 2.7182817};
  using dragonite::norm;

  ONNC_RUNTIME_exp_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Exp, test_exp)
{
  const float input_0[] = {
    -0.5710943,  -1.250696,   -0.07757468,  -1.1942502,  -0.94803476, -1.299894,  -0.35671315, -1.2897884,  -2.4901674,
    0.6467202,   -0.844235,   0.0056652436, 0.19886078,  1.3302251,   0.7755328,  0.7094818,   -1.6778413,  -0.16315086,
    0.09133747,  1.3515315,   -1.0125288,   -0.27126503, -1.2767107,  -1.5634767, -1.2629913,  1.1474992,   0.07440573,
    0.96901256,  -0.9399083,  0.74330056,   0.83765817,  -0.231163,   0.2239434,  0.6263582,   -0.31202093, -1.3726108,
    -0.61414504, -1.6643239,  1.6314058,    -2.9591546,  -0.82218975, -0.4758615, -0.8165831,  0.3510538,   -2.4107265,
    0.01323338,  -0.87222046, 0.009770191,  -2.0750747,  -0.63840485, 0.64009815, -0.83162236, 0.9250508,   1.1517712,
    -0.7558288,  0.1910058,   -1.2702848,   -0.87277,    -0.4126336,  0.8147346};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.56490695, 0.2863055,  0.92535794, 0.302931,    0.3875018,  0.2725607,  0.6999733,  0.27532905, 0.08289609,
    1.9092685,  0.4298861,  1.0056813,  1.2200121,   3.7818947,  2.1717489,  2.0329375,  0.18677674, 0.84946305,
    1.0956386,  3.8633378,  0.3632991,  0.7624144,   0.27895334, 0.20940676, 0.28280678, 3.1503048,  1.0772438,
    2.635341,   0.39066365, 2.1028647,  2.3109488,   0.7936101,  1.2510002,  1.8707851,  0.7319662,  0.2534444,
    0.5411033,  0.18931861, 5.111055,   0.051862743, 0.43946826, 0.6213495,  0.44193915, 1.4205637,  0.08975007,
    1.0133213,  0.4180223,  1.0098181,  0.12554705,  0.5281342,  1.896667,   0.43534243, 2.5219963,  3.1637917,
    0.46962124, 1.2104665,  0.28075165, 0.41779265,  0.66190475, 2.2585762};
  using dragonite::norm;

  ONNC_RUNTIME_exp_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
