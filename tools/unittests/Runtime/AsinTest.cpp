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
SKYPAT_F(Operator_Asin, test_asin_example)
{
  const float   input_0[]      = {-0.5, 0.0, 0.5};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-0.5235988, 0.0, 0.5235988};
  using dragonite::norm;

  ONNC_RUNTIME_asin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Asin, test_asin)
{
  const float input_0[] = {
    0.2591348,  0.6962022,  0.5530887,   0.6072671,  0.11935669, 0.9469431,   0.8423156,  0.35436368,   0.91028184,
    0.16723084, 0.0565022,  0.28290057,  0.8544257,  0.80253464, 0.82402784,  0.31594,    0.77089113,   0.1510076,
    0.9080949,  0.5639672,  0.16313393,  0.5285765,  0.62575114, 0.18588284,  0.6445577,  0.5702136,    0.015201121,
    0.31499347, 0.73189205, 0.14000031,  0.7922691,  0.66498816, 0.91047144,  0.60188866, 0.0007176175, 0.7790881,
    0.47857556, 0.589583,   0.51726633,  0.7411768,  0.26639563, 0.8718645,   0.35211554, 0.5474489,    0.3060445,
    0.41583827, 0.38158628, 0.72110915,  0.57885224, 0.4647303,  0.037141215, 0.8874413,  0.7061364,    0.2843606,
    0.4189519,  0.20287181, 0.002082344, 0.8735851,  0.7516866,  0.124482445};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.2621263,  0.7700933,  0.5860671,    0.65261626, 0.119641915, 1.2435875,  1.0015652,  0.3622335,    1.1439643,
    0.1680203,  0.05653231, 0.28681687,   1.0244446,  0.9315316,   0.9684841,  0.32144722, 0.880239,     0.15158747,
    1.138712,   0.59918207, 0.16386631,   0.5569228,  0.6760941,   0.18697028, 0.70044464, 0.60676587,   0.015201706,
    0.32044977, 0.82109445, 0.14046173,   0.9145189,  0.72747797,  1.1444225,  0.645864,   0.0007176176, 0.8932099,
    0.49903172, 0.63054246, 0.54365367,   0.83482164, 0.2696516,   1.0589966,  0.35983044, 0.5793127,    0.31103536,
    0.42886436, 0.39151183, 0.8054019,    0.6173204,  0.48332998,  0.03714976, 1.0917639,  0.7840268,    0.2883394,
    0.43229073, 0.20428984, 0.0020823453, 1.0625209,  0.8506156,   0.1248062};
  using dragonite::norm;

  ONNC_RUNTIME_asin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
