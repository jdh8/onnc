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
SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {1, 0};
  const int32_t axis            = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_random)
{
  const float   input_0[]      = {0.6447141, 3.4821982,     -3.8642926, -6.832577,  -9.100915, -8.349545,
                           9.428497,  0.98817515,    -5.858277,  2.7313304,  7.5159082, -9.789601,
                           1.5363626, 5.116311,      3.4900117,  -5.7574553, 8.057887,  5.2123647,
                           2.391684,  -0.0009357114, -8.751088,  -5.9339805, -5.097382, 3.7397482};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[8];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float   answer_0[]      = {1, 1, 0, 2, 2, 2, 2, 0};
  const int32_t axis            = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 8) <= 1e-5 * norm(answer_0, 8));
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float   answer_0[]      = {1, 0};
  const int32_t axis            = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_random)
{
  const float   input_0[] = {-4.6517925, -6.5708117, 7.6106606,  -4.6445985, -5.1116753, 6.38832,   -9.321501, 6.152799,
                           0.45370436, 7.7413573,  8.851936,   -1.2576491, 2.7659814,  -5.646147, 2.1520987, 9.555886,
                           0.5286066,  -6.855102,  -0.3682072, -5.0433764, 3.806478,   3.3542109, -5.114248, -4.744011};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[8];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float   answer_0[]      = {1, 0, 1, 0, 1, 1, 2, 1};
  const int32_t axis            = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 8) <= 1e-5 * norm(answer_0, 8));
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_example)
{
  const float   input_0[]      = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 2};
  float         output_0[2];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float   answer_0[]      = {0, 0};
  const int32_t keepdims        = 1;
  const int32_t axis            = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_random)
{
  const float   input_0[] = {4.9688897,   -4.307016, -3.601365, -7.134936,  0.6723678, 6.7263794, -1.592139, 1.5565715,
                           8.868909,    -8.650216, 7.3581614, 0.37253144, 9.792805,  2.7446942, -8.336577, -6.6450014,
                           -0.45864516, 2.4873939, -9.520075, 1.319186,   -6.298208, 4.8129306, 5.2597904, 4.378782};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[12];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float   answer_0[]      = {0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0};
  const int32_t keepdims        = 1;
  const int32_t axis            = 0;
  using dragonite::norm;

  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}
