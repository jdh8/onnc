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
SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {0, 1};
  const int32_t axis            = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_random)
{
  const float   input_0[] = {7.916196,  -5.050213, -6.5481505, -2.372179,  3.4055011,  -5.259473, -5.876902, 9.181546,
                           3.8622417, 3.1683996, -4.334476,  -7.461097,  8.506922,   5.0490994, 7.3549848, 0.19403115,
                           9.845381,  4.322886,  8.492865,   -3.9024255, -3.6774218, -7.866902, 9.484194,  4.339801};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[8];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float   answer_0[]      = {0, 2, 2, 1, 1, 0, 2, 2};
  const int32_t axis            = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 8) <= 1e-5 * norm(answer_0, 8));
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float   answer_0[]      = {0, 1};
  const int32_t axis            = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_random)
{
  const float input_0[] = {-2.8666658, -9.930011, 8.533137,  9.542501,   2.6286595,  6.1863194,  0.39168122, 3.0457706,
                           -8.771415,  9.400704,  1.3585372, -1.9816046, -0.8143469, -2.7263594, -8.583799,  -5.656237,
                           7.053225,   7.5800247, -9.178458, 2.4859655,  0.41899338, 5.0151973,  -4.177078,  -8.727053};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[8];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float   answer_0[]      = {1, 2, 0, 0, 1, 1, 2, 1};
  const int32_t axis            = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 8) <= 1e-5 * norm(answer_0, 8));
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float   answer_0[]      = {1, 1};
  const int32_t keepdims        = 1;
  const int32_t axis            = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_random)
{
  const float   input_0[]      = {-9.826185,   -7.196741,  7.7552886, -7.4781475,  -1.815236,  -5.1710205,
                           3.1197412,   -5.936099,  9.407172,  1.4273096,   -1.4433477, -7.499204,
                           0.024073577, -6.7123213, 8.195043,  -6.8797135,  -7.130009,  -9.179616,
                           -2.3986602,  9.803744,   5.5405087, -0.44200945, -1.0355306, -2.874489};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[12];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float   answer_0[]      = {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1};
  const int32_t keepdims        = 1;
  const int32_t axis            = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}
