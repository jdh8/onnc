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
SKYPAT_F(Operator_Gemm, test_gemm_broadcast) {
  const float input_0[] = {0.22312777,  0.23150592,  0.09712194,   0.56898665,
                           0.027058031, 0.77833915,  0.52660453,   0.54812884,
                           0.06893414,  0.59060514,  0.92518306,   0.7702066,
                           0.5480127,   0.025578925, 0.0019006024, 0.71772593,
                           0.24566254,  0.7418983};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {6, 3};
  const float input_1[] = {
      0.64321744,  0.5189654,   0.15376584, 0.3809103,  0.7027051, 0.8181692,
      0.085290916, 0.11697551,  0.4943885,  0.14907348, 0.7296801, 0.033814617,
      0.58706635,  0.27234018,  0.630503,   0.47218844, 0.8997227, 0.23078799,
      0.72444135,  0.060256176, 0.30520287, 0.75890076, 0.8322442, 0.41969562};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {4, 6};
  const float input_2[] = {0.76684994};
  const int32_t input_2_ndim = 2;
  const int32_t input_2_dims[] = {1, 1};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {1.241954,  0.8124863, 1.1612016,  1.1645083,
                            0.792732,  0.6128203, 0.88614786, 0.9649985,
                            1.0727824, 0.5207758, 0.8079585,  0.9013057};
  const float alpha = 0.5;
  const float beta = 0.5;
  const int32_t transA = 1;
  const int32_t transB = 1;
  ONNC_RUNTIME_gemm_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                          input_1_ndim, input_1_dims, input_2, input_2_ndim,
                          input_2_dims, output_0, output_0_ndim, output_0_dims,
                          alpha, beta, transA, transB);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}

SKYPAT_F(Operator_Gemm, test_gemm_nobroadcast) {
  const float input_0[] = {
      0.2836221,  0.44631746, 0.840007,   0.8039922,  0.61284494, 0.33969662,
      0.19262998, 0.13106087, 0.46343297, 0.93607354, 0.30602285, 0.08378214,
      0.1881105,  0.5103931,  0.9529358,  0.2829104,  0.4307777,  0.93986344};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 6};
  const float input_1[] = {
      0.908622,   0.28591964, 0.96591485, 0.7096039,  0.018301018, 0.40913314,
      0.4478458,  0.3564258,  0.91462654, 0.34151885, 0.069378965, 0.47709087,
      0.5329583,  0.35884598, 0.6747385,  0.9000542,  0.42513716,  0.7279334,
      0.24231969, 0.9308684,  0.7882367,  0.3754562,  0.71097964,  0.011795827};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {6, 4};
  const float input_2[] = {0.2040662,  0.12247819, 0.44614524, 0.8516667,
                           0.10367551, 0.24069467, 0.8468275,  0.48670757,
                           0.15492749, 0.23786247, 0.8510444,  0.46253115};
  const int32_t input_2_ndim = 2;
  const int32_t input_2_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {1.0975156, 0.76760685, 0.9553833,  1.4554433,
                            0.7,       0.5488954,  0.94453347, 1.009792,
                            1.140762,  0.7969438,  1.1454673,  0.94964397};
  const float alpha = 0.5;
  const float beta = 0.5;
  const int32_t transA = 0;
  const int32_t transB = 0;
  ONNC_RUNTIME_gemm_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                          input_1_ndim, input_1_dims, input_2, input_2_ndim,
                          input_2_dims, output_0, output_0_ndim, output_0_dims,
                          alpha, beta, transA, transB);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}
