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
SKYPAT_F(Operator_Floor, test_floor_example) {
  const float input_0[] = {-1.5, 1.2, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-2.0, 1.0, 2.0};
  ONNC_RUNTIME_floor_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Floor, test_floor) {
  const float input_0[] = {
      -0.046118148, 2.0707996,   -0.07085607, 1.0874408,   0.60686517,
      0.37390977,   -0.45002946, -0.1381446,  -3.1849163,  -1.4443145,
      1.016837,     -0.42912075, 0.5769709,   1.0344977,   0.20927685,
      -0.5709123,   -0.33659938, -1.0659368,  -1.1340747,  0.12573391,
      1.0124482,    -0.50588316, 0.16567229,  1.3456547,   -0.9647905,
      0.9443618,    -0.38092506, -1.2759326,  0.38294575,  0.071080826,
      -0.3944588,   1.088456,    0.93442863,  0.47304147,  1.0139484,
      -0.04454469,  0.9966729,   0.07899745,  0.99627876,  0.026844617,
      0.934547,     0.8454652,   -0.9306946,  -0.87019694, 1.3192223,
      0.2506086,    -0.9255042,  1.6857938,   -0.5308915,  -1.6095247,
      -0.6907218,   0.20312688,  1.4536638,   0.5201511,   -1.0354036,
      -0.27028552,  -1.2360173,  -0.6082802,  1.9300473,   1.5259855};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.0, 2.0,  -1.0, 1.0,  0.0,  0.0,  -1.0, -1.0, -4.0, -2.0, 1.0,  -1.0,
      0.0,  1.0,  0.0,  -1.0, -1.0, -2.0, -2.0, 0.0,  1.0,  -1.0, 0.0,  1.0,
      -1.0, 0.0,  -1.0, -2.0, 0.0,  0.0,  -1.0, 1.0,  0.0,  0.0,  1.0,  -1.0,
      0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  -1.0, -1.0, 1.0,  0.0,  -1.0, 1.0,
      -1.0, -2.0, -1.0, 0.0,  1.0,  0.0,  -2.0, -1.0, -2.0, -1.0, 1.0,  1.0};
  ONNC_RUNTIME_floor_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
