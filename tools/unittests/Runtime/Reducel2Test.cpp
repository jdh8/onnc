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
SKYPAT_F(Operator_ReduceL2, test_reduce_l2_do_not_keepdims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float   answer_0[]      = {2.236068, 5.0, 7.81025, 10.630146, 13.453624, 16.27882};
  const int32_t axes[]          = {2};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_do_not_keepdims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float   answer_0[]      = {4.413127, 2.2427495, 3.2932465, 7.934266, 9.561779, 5.863051};
  const int32_t axes[]          = {2};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_keep_dims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 2, 1};
  const float   answer_0[]      = {2.236068, 5.0, 7.81025, 10.630146, 13.453624, 16.27882};
  const int32_t axes[]          = {2};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_keep_dims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 2, 1};
  const float   answer_0[]      = {4.413127, 2.2427495, 3.2932465, 7.934266, 9.561779, 5.863051};
  const int32_t axes[]          = {2};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_default_axes_keepdims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[1];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float   answer_0[]      = {25.495098};
  const int32_t keepdims        = 1;
  const int32_t axes[]          = {0, 1, 2};
  const int32_t number_of_axes  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_default_axes_keepdims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[1];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float   answer_0[]      = {14.970192};
  const int32_t keepdims        = 1;
  const int32_t axes[]          = {0, 1, 2};
  const int32_t number_of_axes  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_reducel2_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                              const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}
