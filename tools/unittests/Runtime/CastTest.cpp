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
SKYPAT_F(Operator_Cast, test_identity_cast)
{
  const float   input_0[]      = {0.7301344,  0.089777224, 0.71269053, 0.26896393, 0.8853903,  0.51661456,
                           0.54408824, 0.5291632,   0.854892,   0.95170516, 0.36219966, 0.36777648};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {3, 4};
  float         output_0[12];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float   answer_0[]      = {0.7301344,  0.089777224, 0.71269053, 0.26896393, 0.8853903,  0.51661456,
                            0.54408824, 0.5291632,   0.854892,   0.95170516, 0.36219966, 0.36777648};
  const int32_t to              = 1;
  using dragonite::norm;

  ONNC_RUNTIME_cast_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, to);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}
