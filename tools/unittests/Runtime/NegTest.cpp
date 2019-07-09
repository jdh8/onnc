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
SKYPAT_F(Operator_Neg, test_neg_example)
{
  const float   input_0[]      = {-4.0, 2.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {4.0, -2.0};
  using dragonite::norm;

  ONNC_RUNTIME_neg_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_Neg, test_neg)
{
  const float input_0[] = {
    0.90989757, -0.07027396, -0.5254824,  0.47600374, -0.92017174,  -0.500849,  0.6169583,   1.3652635,   0.5013793,
    -1.689668,  1.1777304,   0.42032868,  1.6209015,  -1.695344,    -0.6846603, -0.46315238, 0.64207673,  0.32290885,
    1.2331544,  0.072145514, -0.29838273, -0.8352747, -0.5569903,   -1.4317734, -1.501548,   0.95596045,  0.15219304,
    -0.5676709, -1.3746724,  -0.42851904, -0.5962777, 1.3852378,    0.24484889, 0.39371893,  -0.98377955, 0.58756995,
    0.6511132,  1.222844,    1.2037582,   0.26658618, -0.031301633, 0.3119203,  -0.72335124, -0.5560939,  -0.9923844,
    1.1257762,  -0.7270129,  0.6446165,   0.6462418,  0.33617216,   0.2946579,  -0.9014112,  -0.08657031, 1.2985245,
    0.07542204, -0.7480966,  -0.11096209, 1.2193989,  -0.16857176,  1.6258348};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[] = {-0.90989757, 0.07027396, 0.5254824,   -0.47600374, 0.92017174,  0.500849,     -0.6169583,
                            -1.3652635,  -0.5013793, 1.689668,    -1.1777304,  -0.42032868, -1.6209015,   1.695344,
                            0.6846603,   0.46315238, -0.64207673, -0.32290885, -1.2331544,  -0.072145514, 0.29838273,
                            0.8352747,   0.5569903,  1.4317734,   1.501548,    -0.95596045, -0.15219304,  0.5676709,
                            1.3746724,   0.42851904, 0.5962777,   -1.3852378,  -0.24484889, -0.39371893,  0.98377955,
                            -0.58756995, -0.6511132, -1.222844,   -1.2037582,  -0.26658618, 0.031301633,  -0.3119203,
                            0.72335124,  0.5560939,  0.9923844,   -1.1257762,  0.7270129,   -0.6446165,   -0.6462418,
                            -0.33617216, -0.2946579, 0.9014112,   0.08657031,  -1.2985245,  -0.07542204,  0.7480966,
                            0.11096209,  -1.2193989, 0.16857176,  -1.6258348};
  using dragonite::norm;

  ONNC_RUNTIME_neg_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
