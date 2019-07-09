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
SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool)
{
  const float input_0[] = {
    0.17660125,   1.3598105,   -1.923946,   2.1930025,    -1.8580122, -1.7987932, 0.5927288,   1.045912,    0.9851497,
    0.3081411,    -1.1877971,  0.8874025,   -0.13935246,  -0.3240187, 0.0265809,  -1.2539549,  -1.386376,   1.1529082,
    -0.052184086, -1.567076,   -1.7382251,  0.61808294,   0.39387813, 0.64208317, 0.5575081,   -0.46277848, 0.64798903,
    1.180924,     0.13674593,  -0.50936764, -0.67017525,  0.3372634,  -0.5375231, 0.85237455,  -0.37197703, -1.0222396,
    -0.6654254,   0.23435381,  0.011527448, -1.094045,    0.40193158, 0.6657374,  -0.76965135, 1.2513183,   0.48994756,
    1.1688676,    -0.59899825, -0.11187892, -0.004003528, -1.0665513, 0.46064863, 0.86277884,  -1.6383408,  0.77582455,
    0.71362245,   -1.7937495,  0.33494717,  -0.9625672,   0.33872712, 0.3257969,  0.083482444, 0.9314502,   0.93421346,
    -0.4864009,   -1.1199211,  -0.8934599,  -1.7748134,   -1.4102342, 0.38253367, -0.501686,   -0.06337701, 2.1910758,
    0.6010047,    -1.2771852,  0.59277266};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float         output_0[3];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float   answer_0[]      = {-0.091597825, -0.020225368, -0.09571427};
  using dragonite::norm;

  ONNC_RUNTIME_globalaveragepool_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                       output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool_precomputed)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float         output_0[1];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float   answer_0[]      = {5.0};
  using dragonite::norm;

  ONNC_RUNTIME_globalaveragepool_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                       output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}
