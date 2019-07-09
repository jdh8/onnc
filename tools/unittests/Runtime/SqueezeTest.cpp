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
SKYPAT_F(Operator_Squeeze, test_squeeze)
{
  const float input_0[] = {
    0.07778859,  0.8289537,   -1.9951898,  -0.53638077, 1.1895761,   0.6079182,   0.7392492,    0.76079094, -1.462957,
    0.45277345,  -1.0094764,  1.4711999,   -0.93643606, -1.4212593,  1.5097857,   -0.801289,    -0.422365,  0.8975764,
    0.25067422,  -1.046149,   2.7574675,   -0.48941353, -0.25578105, -1.2681224,  -0.60215193,  1.0701586,  -1.2894542,
    -0.16775511, 0.14560606,  1.1161523,   -1.0294628,  -0.60081685, -0.46980622, 0.0013923007, 2.0395317,  0.40908757,
    -0.2860101,  -0.58073014, -0.38105837, 1.534022,    0.8280142,   0.23406377,  -0.15177697,  -1.5188656, -0.17915837,
    -0.1028241,  0.006853452, 0.14033575,  0.031414967, 0.9452563,   -0.6444756,  0.7187488,    -2.3468862, -1.1623235,
    -0.6787126,  0.23454374,  0.66575676,  -0.14732346, 0.6971758,   2.639299};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.07778859,  0.8289537,   -1.9951898,  -0.53638077, 1.1895761,   0.6079182,   0.7392492,    0.76079094, -1.462957,
    0.45277345,  -1.0094764,  1.4711999,   -0.93643606, -1.4212593,  1.5097857,   -0.801289,    -0.422365,  0.8975764,
    0.25067422,  -1.046149,   2.7574675,   -0.48941353, -0.25578105, -1.2681224,  -0.60215193,  1.0701586,  -1.2894542,
    -0.16775511, 0.14560606,  1.1161523,   -1.0294628,  -0.60081685, -0.46980622, 0.0013923007, 2.0395317,  0.40908757,
    -0.2860101,  -0.58073014, -0.38105837, 1.534022,    0.8280142,   0.23406377,  -0.15177697,  -1.5188656, -0.17915837,
    -0.1028241,  0.006853452, 0.14033575,  0.031414967, 0.9452563,   -0.6444756,  0.7187488,    -2.3468862, -1.1623235,
    -0.6787126,  0.23454374,  0.66575676,  -0.14732346, 0.6971758,   2.639299};
  const int32_t axes[]         = {0};
  const int32_t number_of_axes = 1;
  using dragonite::norm;

  ONNC_RUNTIME_squeeze_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             const_cast<int32_t*>(axes), number_of_axes);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
