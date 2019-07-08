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
SKYPAT_F(Operator_Cast, test_identity_cast) {
  const float input_0[] = {0.3079004,  0.45125893, 0.5288134,  0.2997578,
                           0.31268665, 0.34973314, 0.4201415,  0.37873438,
                           0.9730773,  0.16072883, 0.84374803, 0.9887417};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.3079004,  0.45125893, 0.5288134,  0.2997578,
                            0.31268665, 0.34973314, 0.4201415,  0.37873438,
                            0.9730773,  0.16072883, 0.84374803, 0.9887417};
  const int32_t to = 1;
  ONNC_RUNTIME_cast_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, to);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}
