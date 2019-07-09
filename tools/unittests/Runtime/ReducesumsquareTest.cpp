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
SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_do_not_keepdims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float   answer_0[]      = {10.0, 20.0, 74.0, 100.0, 202.0, 244.0};
  const int32_t axes[]          = {1};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_do_not_keepdims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float   answer_0[]      = {5.177228, 19.328384, 3.889578, 69.90847, 120.03467, 5.7683187};
  const int32_t axes[]          = {1};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_keepdims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float   answer_0[]      = {10.0, 20.0, 74.0, 100.0, 202.0, 244.0};
  const int32_t axes[]          = {1};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_keepdims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[6];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float   answer_0[]      = {5.177228, 19.328384, 3.889578, 69.90847, 120.03467, 5.7683187};
  const int32_t axes[]          = {1};
  const int32_t number_of_axes  = 1;
  const int32_t keepdims        = 1;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_default_axes_keepdims_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[1];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float   answer_0[]      = {650.0};
  const int32_t keepdims        = 1;
  const int32_t axes[]          = {0, 1, 2};
  const int32_t number_of_axes  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_default_axes_keepdims_random)
{
  const float   input_0[]      = {0.9762701,  4.303787, 2.0552676, 0.89766365, -1.526904, 2.9178822,
                           -1.2482557, 7.83546,  9.273255,  -2.3311696, 5.834501,  0.5778984};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float         output_0[1];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float   answer_0[]      = {224.10666};
  const int32_t keepdims        = 1;
  const int32_t axes[]          = {0, 1, 2};
  const int32_t number_of_axes  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_reducesumsquare_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}
