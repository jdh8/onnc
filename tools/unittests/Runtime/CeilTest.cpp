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
SKYPAT_F(Operator_Ceil, test_ceil_example)
{
  const float   input_0[]      = {-1.5, 1.2};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {-1.0, 2.0};
  using dragonite::norm;

  ONNC_RUNTIME_ceil_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_Ceil, test_ceil)
{
  const float   input_0[]    = {-0.62570953, 1.5038661,  0.7640843,    -0.30335107, 0.93182844,  0.7958858,   0.0156944,
                           -0.8517502,  1.027754,   -0.9683663,   -0.3813998,  1.6041071,   -1.5635489,  0.7992253,
                           -1.0148742,  1.319775,   -0.22813076,  -0.77204716, -1.8308418,  0.95056444,  -0.18971139,
                           0.95921713,  0.757848,   -0.088560656, -1.8759845,  -0.73429394, -0.6180225,  1.1465452,
                           -0.06142981, 0.5096739,  -1.4545399,   -0.8795726,  -1.385671,   0.93072134,  -0.33945352,
                           0.42733204,  -1.1587467, 0.74799466,   1.075383,    -2.310082,   -0.52665675, -0.7393321,
                           -0.90235144, 1.342023,   0.321275,     1.6229383,   -1.3479812,  -0.73660624, 0.59926444,
                           1.0017334,   1.2911106,  2.8412082,    1.3923782,   -0.520014,   -2.4214816,  0.34726074,
                           0.6103141,   -0.3909978, 0.61465085,   0.21777147};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[] = {-0.0, 2.0,  1.0,  -0.0, 1.0,  1.0,  1.0,  -0.0, 2.0,  -0.0, -0.0, 2.0,  -1.0, 1.0,  -1.0,
                            2.0,  -0.0, -0.0, -1.0, 1.0,  -0.0, 1.0,  1.0,  -0.0, -1.0, -0.0, -0.0, 2.0,  -0.0, 1.0,
                            -1.0, -0.0, -1.0, 1.0,  -0.0, 1.0,  -1.0, 1.0,  2.0,  -2.0, -0.0, -0.0, -0.0, 2.0,  1.0,
                            2.0,  -1.0, -0.0, 1.0,  2.0,  2.0,  3.0,  2.0,  -0.0, -2.0, 1.0,  1.0,  -0.0, 1.0,  1.0};
  using dragonite::norm;

  ONNC_RUNTIME_ceil_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
