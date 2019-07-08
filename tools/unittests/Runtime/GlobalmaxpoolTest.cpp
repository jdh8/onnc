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
SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool) {
  const float input_0[] = {
      -0.60048956, -0.3716759,   0.09686587,   0.65437484,  -0.6850437,
      0.4780829,   0.12327978,   -0.010199084, -0.2776904,  -0.5138352,
      -0.12905546, 0.4055289,    0.64954036,   -2.5811522,  -0.9236393,
      -0.19717097, 0.9036997,    0.7412384,    -0.69870496, 0.15720206,
      -0.26742136, -0.67631567,  -0.62528664,  0.8614552,   0.6357043,
      0.62112105,  -0.088566944, 0.25622255,   0.62810016,  -0.039971128,
      0.6799171,   0.2152898,    -1.1749362,   -0.55478823, 1.5063831,
      -0.98560816, -0.35703638,  0.7106753,    1.2965134,   0.9380299,
      1.4703128,   0.78813547,   -0.6837286,   -0.40982845, 0.8719,
      -0.32820192, 1.4308844,    0.64265925,   1.3501347,   -2.0160997,
      -0.7270879,  -0.26440874,  -0.962425,    -1.3569583,  -1.8202405,
      -0.4793852,  0.014338666,  0.7384035,    0.4146642,   -1.2434458,
      0.9588446,   -1.356443,    -0.8003409,   0.76651335,  0.700837,
      -1.5830505,  1.1334488,    -1.2265819,   -0.2647046,  -0.928538,
      -0.7889352,  -0.053240415, 0.07711309,   -2.2553563,  -0.35298777};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float output_0[3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float answer_0[] = {0.9036997, 1.5063831, 1.1334488};
  ONNC_RUNTIME_globalmaxpool_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                   output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool_precomputed) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float output_0[1];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float answer_0[] = {9.0};
  ONNC_RUNTIME_globalmaxpool_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                   output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 1) < 1e-5f);
}
