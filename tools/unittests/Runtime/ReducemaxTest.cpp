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
SKYPAT_F(Operator_ReduceMax, test_reduce_max_do_not_keepdims_example) {
  const float input_0[] = {5.0,  1.0, 20.0, 2.0, 30.0, 1.0,
                           40.0, 2.0, 55.0, 1.0, 60.0, 2.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[6];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[] = {20.0, 2.0, 40.0, 2.0, 60.0, 2.0};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_ReduceMax, test_reduce_max_do_not_keepdims_random) {
  const float input_0[] = {0.9762701, 4.303787,   2.0552676,  0.89766365,
                           -1.526904, 2.9178822,  -1.2482557, 7.83546,
                           9.273255,  -2.3311696, 5.834501,   0.5778984};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[6];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[] = {2.0552676, 4.303787, -1.2482557,
                            7.83546,   9.273255, 0.5778984};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_ReduceMax, test_reduce_max_keepdims_example) {
  const float input_0[] = {5.0,  1.0, 20.0, 2.0, 30.0, 1.0,
                           40.0, 2.0, 55.0, 1.0, 60.0, 2.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[6];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float answer_0[] = {20.0, 2.0, 40.0, 2.0, 60.0, 2.0};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_ReduceMax, test_reduce_max_keepdims_random) {
  const float input_0[] = {0.9762701, 4.303787,   2.0552676,  0.89766365,
                           -1.526904, 2.9178822,  -1.2482557, 7.83546,
                           9.273255,  -2.3311696, 5.834501,   0.5778984};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[6];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float answer_0[] = {2.0552676, 4.303787, -1.2482557,
                            7.83546,   9.273255, 0.5778984};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_ReduceMax, test_reduce_max_default_axes_keepdim_example) {
  const float input_0[] = {5.0,  1.0, 20.0, 2.0, 30.0, 1.0,
                           40.0, 2.0, 55.0, 1.0, 60.0, 2.0};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[] = {60.0};
  const int32_t keepdims = 1;
  const int32_t axes[] = {0, 1, 2};
  const int32_t number_of_axes = 3;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 1) < 1e-5f);
}

SKYPAT_F(Operator_ReduceMax, test_reduce_max_default_axes_keepdims_random) {
  const float input_0[] = {0.9762701, 4.303787,   2.0552676,  0.89766365,
                           -1.526904, 2.9178822,  -1.2482557, 7.83546,
                           9.273255,  -2.3311696, 5.834501,   0.5778984};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[] = {9.273255};
  const int32_t keepdims = 1;
  const int32_t axes[] = {0, 1, 2};
  const int32_t number_of_axes = 3;
  ONNC_RUNTIME_reducemax_float(
      nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
      output_0_dims, const_cast<int32_t *>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 1) < 1e-5f);
}
