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
SKYPAT_F(Operator_Equal, test_equal)
{
  const float   input_0[]      = {2,  -8, 17, -7, -13, -12, 0, -9,  -7,  2, 2,   2,  -17, -6, -8, 12, 21, 4,  4,  -14,
                           13, 14, 5,  22, 14,  -11, 5, -13, 0,   1, -4,  3,  -10, 12, -2, 13, -1, 14, 21, 7,
                           19, 8,  14, 2,  -2,  10,  0, 1,   -11, 0, -15, 10, -8,  16, 0,  4,  0,  2,  0,  -16};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float   input_1[]    = {0,   -10, -11, 10, -4,  -12, -5,  -5, 1,  -3, 4,  -5,  9, 31,  8,  -1, -10, -2,  6,   7,
                           -11, -2,  15,  -4, 1,   7,   -16, -7, -5, -2, -4, 15,  1, 3,   11, 4,  14,  -12, 2,   -3,
                           2,   2,   -6,  -4, -18, -3,  23,  -7, 8,  5,  1,  -19, 1, -14, 10, 1,  1,   0,   -24, -12};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  using dragonite::norm;

  ONNC_RUNTIME_equal_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                           output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Equal, test_equal_bcast)
{
  const float   input_0[]      = {-4, 8,  -14, 4,  2,   -2, -10, -11, 7,  -3, -10, 1,  9,   2,  0,  0,  -7, 0,  1, -12,
                           8,  -4, -3,  12, 7,   20, 0,   -2,  17, 14, 5,   -3, 6,   13, 4,  4,  0,  14, 0, -1,
                           -3, 8,  0,   3,  -16, 3,  9,   1,   -9, 19, -9,  2,  -18, 0,  10, 12, 14, -1, 2, 8};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float   input_1[]      = {4, 11, 3, -15, -13};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  using dragonite::norm;

  ONNC_RUNTIME_equal_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                           output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
