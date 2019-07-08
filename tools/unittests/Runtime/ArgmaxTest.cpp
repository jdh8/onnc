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
SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_random) {
  const float input_0[] = {
      6.691105, 8.622023,   -9.4149275, 8.967378,   -9.756551, 1.1895254,
      4.973867, 3.32874,    -2.3934813, -5.826562,  7.5353203, 3.8179379,
      5.671311, 5.4769053,  4.969029,   -9.5161705, 3.4563103, 5.834528,
      5.444251, -3.2157888, -7.345147,  4.855532,   5.1540017, -4.161073};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {0, 0, 2, 0, 0, 1, 1, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[] = {0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_random) {
  const float input_0[] = {
      -2.4499667, 8.797492,   -6.0353527, 6.744987,    3.4000275,  -9.854716,
      -8.8846855, 3.1345434,  4.2990713,  -0.79077107, 7.207363,   3.13858,
      0.20723702, -2.1299865, -3.5681002, -0.4381767,  -2.2579908, 7.089941,
      1.2736448,  -7.0713444, -5.7228446, 7.5169835,   0.73666036, -5.9291186};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[8];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[] = {2, 0, 2, 0, 0, 2, 1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_example) {
  const float input_0[] = {2.0, 1.0, 3.0, 10.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[] = {1, 1};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_random) {
  const float input_0[] = {
      9.229823,   -6.5093665, 6.1206374,  -9.479706,  -4.7342377, -1.5301152,
      -5.8352923, 1.8410127,  1.7024198,  -5.112853,  -5.5208416, 7.4790645,
      -9.915015,  -3.1675928, 9.237893,   -3.5102909, -5.3102536, 9.287009,
      -9.446119,  -1.6128069, -0.6865576, -6.3975925, 2.3503275,  -5.7277484};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[] = {0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            output_0, output_0_ndim, output_0_dims, axis,
                            keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 12) < 1e-5f);
}
