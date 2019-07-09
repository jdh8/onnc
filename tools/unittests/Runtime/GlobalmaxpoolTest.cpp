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
SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool)
{
  const float   input_0[] = {-0.6062815,  1.4362555,    0.52714556,  0.07159568,   0.42930377,  0.05578858, 0.7183098,
                           -0.14830601, 1.2808181,    -0.54403645, -0.5361885,   -0.87531483, 0.567358,   -0.4399207,
                           -1.0694721,  1.9753437,    -0.20190112, 0.87089443,   0.29748642,  -0.2197193, 0.46332878,
                           -0.36989146, -0.13565196,  0.16710478,  -0.27869144,  0.52352935,  0.18817471, -0.5850939,
                           0.14844942,  0.7454628,    0.44702587,  -0.9618458,   1.5701599,   0.5241384,  -1.5461886,
                           -0.19279137, 0.6484802,    0.9845887,   -0.061274573, -0.657734,   -1.95687,   -1.7330583,
                           -0.6390515,  -0.014788138, -1.4996163,  0.4248645,    0.07765889,  0.42235002, -1.3694218,
                           0.58408314,  0.43862617,   -0.5726013,  0.8021374,    0.4291844,   0.10577185, 1.0178292,
                           -0.54482263, 0.42526907,   -1.1899137,  -0.44725448,  0.8674406,   0.53526646, -1.1805462,
                           -1.1215435,  0.4034569,    0.09488536,  -1.174029,    -2.525754,   0.23005384, -0.3583217,
                           -0.6252529,  0.023264868,  1.5965581,   0.04414132,   -0.2561759};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float         output_0[3];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float   answer_0[]      = {1.9753437, 1.5701599, 1.5965581};
  using dragonite::norm;

  ONNC_RUNTIME_globalmaxpool_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                   output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool_precomputed)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float         output_0[1];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float   answer_0[]      = {9.0};
  using dragonite::norm;

  ONNC_RUNTIME_globalmaxpool_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim,
                                   output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}
