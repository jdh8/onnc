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
SKYPAT_F(Operator_Reciprocal, test_reciprocal_example)
{
  const float   input_0[]      = {-4.0, 2.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {-0.25, 0.5};
  using dragonite::norm;

  ONNC_RUNTIME_reciprocal_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_Reciprocal, test_reciprocal)
{
  const float input_0[] = {
    1.3102992, 0.96277857, 1.059715,  1.0599895,  1.4077175,  1.4463723, 1.3520099, 0.6120683, 0.8786311, 1.4067597,
    1.0227447, 1.2468648,  0.9669444, 0.5436329,  0.8291521,  0.521611,  1.059617,  1.1867384, 0.8472421, 1.2659658,
    1.0859764, 1.4747889,  1.37291,   1.0180821,  1.2344463,  1.4388261, 1.4265463, 1.1710182, 1.0904195, 1.1968063,
    1.1974022, 0.93592227, 1.2604253, 0.8946516,  0.5253912,  1.3448533, 1.2420329, 1.4886194, 0.7409185, 0.6459692,
    1.2194581, 0.85114515, 1.0890089, 1.4761894,  0.89204663, 1.2683386, 0.866965,  1.3792251, 0.7153911, 1.4095509,
    1.069972,  0.9376675,  0.596967,  0.61165106, 0.7701222,  0.5749765, 1.4734433, 0.5919296, 1.1044598, 0.6235012};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.7631845,  1.0386604,  0.9436499,  0.9434056,  0.7103698, 0.6913849, 0.7396396, 1.6338046,  1.138134,   0.71085346,
    0.97776115, 0.80201155, 1.0341856,  1.8394765,  1.2060513, 1.9171376, 0.9437372, 0.8426457,  1.1803001,  0.78991073,
    0.92083037, 0.67806315, 0.72837985, 0.982239,   0.8100798, 0.695011,  0.7009937, 0.85395765, 0.9170782,  0.8355571,
    0.83514124, 1.0684648,  0.793383,   1.1177535,  1.9033436, 0.7435755, 0.8051317, 0.67176336, 1.3496761,  1.5480614,
    0.82003635, 1.1748878,  0.9182661,  0.67741984, 1.1210176, 0.788433,  1.153449,  0.7250448,  1.3978368,  0.70944583,
    0.93460387, 1.0664761,  1.6751345,  1.634919,   1.2984953, 1.7392015, 0.6786824, 1.6893901,  0.90542006, 1.6038462};
  using dragonite::norm;

  ONNC_RUNTIME_reciprocal_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
