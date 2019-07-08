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
SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_random) {
  const float input_0[] = {
      8.435711,   -1.1295203, -3.4878623, -6.527683, -3.140497,  9.731917,
      -5.6662865, 1.9648325,  9.648947,   -8.753647, -7.1173553, 5.3425627,
      -2.8315675, 1.8433671,  -6.676951,  -1.072245, -9.538525,  3.5827794,
      -1.6333739, 0.5836068,  1.0911437,  6.7816877, 2.6894364,  4.9808316};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {1, 2, 2, 0, 1, 0, 0, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[] = {1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_random) {
  const float input_0[] = {
      -8.488436,  -8.301342, 9.657309,   -7.481117,  -7.1244693, -4.4248796,
      -3.7669787, 6.033591,  5.09823,    5.571755,   5.236641,   -8.742535,
      -7.7370763, 2.7235477, -1.6805363, 8.508835,   4.0892544,  8.007424,
      3.5082245,  1.0496303, -9.3902025, -0.5500252, 3.522235,   6.2025857};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[] = {0, 0, 1, 2, 2, 2, 0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[] = {0, 0};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_random) {
  const float input_0[] = {
      -1.4711057, -6.5344834, -9.730243, -5.345624,   -0.15964517, -1.9733837,
      6.5203557,  3.1507702,  7.912064,  3.5703049,   8.681772,    -3.7243218,
      2.814305,   -2.1062737, -9.807642, -6.846598,   -9.012886,   3.168027,
      3.2381935,  -4.3505697, -9.765868, -0.48494193, -4.7363048,  7.5645256};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[] = {0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}
