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
SKYPAT_F(Operator_Expand, test_expand_dim_changed) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[] = {2, 1, 6};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[36];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 6};
  const float answer_0[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0,
                            2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
                            1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0,
                            2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
  ONNC_RUNTIME_expand_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 36) < 1e-5f);
}

SKYPAT_F(Operator_Expand, test_expand_dim_unchanged) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[] = {3, 4};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
                            2.0, 2.0, 3.0, 3.0, 3.0, 3.0};
  ONNC_RUNTIME_expand_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}
