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
SKYPAT_F(Operator_Dropout, test_dropout_default)
{
  const float    input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t  input_0_ndim   = 1;
  const int32_t  input_0_dims[] = {3};
  float          output_0[3];
  const int32_t  output_0_ndim   = 1;
  const int32_t  output_0_dims[] = {3};
  const float    answer_0[]      = {-1.0, 0.0, 1.0};
  float*         output_1        = nullptr;
  const int32_t  output_1_ndim   = 0;
  const int32_t* output_1_dims   = nullptr;
  const float    ratio           = 0.5;
  using dragonite::norm;

  ONNC_RUNTIME_dropout_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             output_1, output_1_ndim, output_1_dims, ratio);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Dropout, test_dropout_random)
{
  const float input_0[] = {0.21913064,   0.422912,     -0.17104515, -1.3605666,   0.14346683,  -1.2587612, -0.85431975,
                           -0.22751275,  -0.64637554,  -0.45032373, -0.10775222,  -0.76326144, 1.0841749,  0.30420542,
                           0.44229716,   0.25023687,   1.0449243,   0.79727334,   -0.6503414,  0.28584188, 1.046587,
                           -0.008671912, -0.37746236,  0.9519747,   0.70915437,   0.25513855,  1.2579945,  1.4754281,
                           0.5708053,    0.20261957,   0.4378326,   -1.6589772,   -0.2461237,  0.235529,   1.531749,
                           0.42461044,   -1.0146405,   -0.3018211,  -1.3695605,   -1.0796733,  0.979188,   1.0406072,
                           -0.37996766,  -0.025551941, 0.2735519,   0.21806403,   -0.82011783, -0.2031602, -0.1936051,
                           -1.1706306,   -0.21356732,  -0.3992815,  -0.114497565, -0.57213366, 0.5060143,  -0.5048138,
                           -1.3871502,   -0.3178443,   -0.73051125, -0.5051671};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.21913064,   0.422912,     -0.17104515, -1.3605666,   0.14346683,  -1.2587612, -0.85431975,
                            -0.22751275,  -0.64637554,  -0.45032373, -0.10775222,  -0.76326144, 1.0841749,  0.30420542,
                            0.44229716,   0.25023687,   1.0449243,   0.79727334,   -0.6503414,  0.28584188, 1.046587,
                            -0.008671912, -0.37746236,  0.9519747,   0.70915437,   0.25513855,  1.2579945,  1.4754281,
                            0.5708053,    0.20261957,   0.4378326,   -1.6589772,   -0.2461237,  0.235529,   1.531749,
                            0.42461044,   -1.0146405,   -0.3018211,  -1.3695605,   -1.0796733,  0.979188,   1.0406072,
                            -0.37996766,  -0.025551941, 0.2735519,   0.21806403,   -0.82011783, -0.2031602, -0.1936051,
                            -1.1706306,   -0.21356732,  -0.3992815,  -0.114497565, -0.57213366, 0.5060143,  -0.5048138,
                            -1.3871502,   -0.3178443,   -0.73051125, -0.5051671};
  float*      output_1   = nullptr;
  const int32_t  output_1_ndim = 0;
  const int32_t* output_1_dims = nullptr;
  const float    ratio         = 0.20000000298023224;
  using dragonite::norm;

  ONNC_RUNTIME_dropout_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             output_1, output_1_ndim, output_1_dims, ratio);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
