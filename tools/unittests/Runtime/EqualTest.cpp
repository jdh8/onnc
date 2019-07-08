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
SKYPAT_F(Operator_Equal, test_equal) {
  const float input_0[] = {
      -3, 1,   -12, -11, -4,  1,   12,  -8, -11, 0,   -1,  19,  7,   -5,  4,
      1,  9,   1,   15,  3,   -19, 7,   15, 6,   4,   -10, 4,   -3,  -15, -10,
      13, -12, 0,   -9,  -14, -5,  -32, 4,  -15, -15, 0,   0,   -6,  4,   10,
      11, -7,  -20, -26, 13,  0,   -6,  13, 4,   6,   5,   -14, -10, -9,  10};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {9,   -6, 16, 3,   4,  13,  13,  11, -5, 5,  0,   -9,
                           -10, 5,  -6, -16, 0,  15,  14,  -3, 0,  39, -8,  0,
                           11,  0,  13, -10, -8, 6,   -8,  0,  16, -7, -2,  3,
                           -9,  11, 11, -3,  14, -11, -2,  -2, -7, -8, 8,   0,
                           6,   3,  -6, 2,   -6, 1,   -10, 1,  5,  2,  -15, 6};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  ONNC_RUNTIME_equal_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           input_1, input_1_ndim, input_1_dims, output_0,
                           output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_Equal, test_equal_bcast) {
  const float input_0[] = {3,   1,  -8, 11, 3,  1,  -6, 11,  -11, 8,   5,  7,
                           -11, -2, 10, 3,  -1, -4, -6, 9,   -6,  -21, 0,  -10,
                           -9,  -3, 2,  5,  0,  0,  2,  0,   7,   -8,  -9, 22,
                           -16, 5,  9,  11, -3, -5, -6, -14, 10,  2,   -1, -9,
                           12,  -8, 1,  -1, -1, 24, 5,  0,   0,   3,   2,  15};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {-8, -11, 0, 7, 10};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  ONNC_RUNTIME_equal_float(nullptr, input_0, input_0_ndim, input_0_dims,
                           input_1, input_1_ndim, input_1_dims, output_0,
                           output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
