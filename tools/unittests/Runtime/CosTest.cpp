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
SKYPAT_F(Operator_Cos, test_cos_example)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {0.5403023, 1.0, 0.5403023};
  using dragonite::norm;

  ONNC_RUNTIME_cos_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Cos, test_cos)
{
  const float input_0[] = {
    0.631348,   0.13776618, -0.057062495, 2.8796277,   0.7571142,   0.48048946,   0.31170294,  -0.98461485, 0.06251539,
    1.18286,    1.0732192,  1.1264396,    1.8408056,   -0.0450846,  0.36607817,   0.11159369,  -0.32730016, -0.97940004,
    1.3745649,  1.7475704,  0.95669776,   -0.27857736, -1.1180946,  -0.19588572,  -0.20117944, 1.1782969,   -0.7721386,
    0.409711,   -1.1120569, -0.8862935,   2.3307037,   -0.5867325,  -0.9629998,   -0.69374937, -0.97898746, -0.49063814,
    0.5304364,  -1.564379,  2.473167,     0.038405154, -0.2070096,  -0.116721004, -0.28842777, 1.5234691,   -0.79231983,
    0.86313725, 1.5510412,  0.18936796,   0.14580543,  -0.85226715, -1.3497621,   -0.16721876, -1.5137478,  0.39959294,
    -2.367598,  -0.9814644, -0.08134883,  -1.8012376,  0.15831845,  -0.9945298};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.8072326,  0.99052525,  0.9983724,  -0.96588296, 0.7268211,  0.8867688,  0.9518127,  0.55318403,  0.9980466,
    0.37827888, 0.47729787,  0.4298772,  -0.2667404,  0.99898386, 0.93373835, 0.9937799,  0.9469138,   0.5575207,
    0.1949745,  -0.17585483, 0.576222,   0.9614476,   0.43739673, 0.9808757,  0.9798316,  0.38249895,  0.7164203,
    0.917236,   0.44281825,  0.6322879,  -0.68885434, 0.83275414, 0.57106,    0.76885396, 0.5578632,   0.88203233,
    0.8625864,  0.006417306, -0.7847983, 0.99926263,  0.9786499,  0.99319583, 0.95869225, 0.04730957,  0.7021955,
    0.6500567,  0.019753797, 0.9821234,  0.9893892,   0.65827817, 0.21923882, 0.9860515,  0.057017576, 0.9212194,
    -0.7151242, 0.5558058,   0.996693,   -0.22840714, 0.9874938,  0.5448972};
  using dragonite::norm;

  ONNC_RUNTIME_cos_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
