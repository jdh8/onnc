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
SKYPAT_F(Operator_Identity, test_identity)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 1, 2, 2};
  float         output_0[4];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 1, 2, 2};
  const float   answer_0[]      = {1.0, 2.0, 3.0, 4.0};
  using dragonite::norm;

  ONNC_RUNTIME_identity_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 4) <= 1e-5 * norm(answer_0, 4));
}
