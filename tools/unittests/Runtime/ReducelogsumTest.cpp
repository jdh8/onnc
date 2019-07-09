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
SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_desc_axes)
{
  const float input_0[] = {
    0.56804454, 0.92559665, 0.071036056, 0.0871293,  0.020218397, 0.83261985, 0.77815676, 0.87001216, 0.9786183,
    0.7991586,  0.46147937, 0.7805292,   0.11827443, 0.639921,    0.14335328, 0.9446689,  0.5218483,  0.41466194,
    0.2645556,  0.7742337,  0.45615032,  0.56843394, 0.0187898,   0.6176355,  0.6120957,  0.616934,   0.94374806,
    0.6818203,  0.3595079,  0.43703195,  0.6976312,  0.06022547,  0.6667667,  0.67063785, 0.21038257, 0.12892629,
    0.31542835, 0.36371076, 0.57019675,  0.43860152, 0.9883738,   0.10204481, 0.20887676, 0.16130951, 0.6531083,
    0.2532916,  0.46631077, 0.2444256,   0.15896958, 0.11037514,  0.6563296,  0.13818295, 0.19658236, 0.36872518,
    0.82099324, 0.09710128, 0.8379449,   0.09609841, 0.97645944,  0.4686512};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {2.3973603, 2.2443895, 2.0799606};
  const int32_t axes[]          = {2, 1};
  const int32_t number_of_axes  = 2;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducelogsum_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                                  const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_asc_axes)
{
  const float input_0[] = {
    0.9767611,   0.6048455,   0.7392636,  0.039187793, 0.28280696, 0.12019656, 0.2961402,  0.11872772,  0.31798318,
    0.41426298,  0.064147495, 0.6924721,  0.56660146,  0.2653895,  0.5232481,  0.09394051, 0.5759465,   0.9292962,
    0.31856894,  0.6674104,   0.13179787, 0.7163272,   0.2894061,  0.18319136, 0.5865129,  0.020107547, 0.82894003,
    0.004695476, 0.6778165,   0.27000797, 0.735194,    0.96218854, 0.24875315, 0.57615733, 0.5920419,   0.5722519,
    0.22308163,  0.952749,    0.44712538, 0.84640867,  0.6994793,  0.29743695, 0.81379783, 0.39650574,  0.8811032,
    0.5812729,   0.8817354,   0.6925316,  0.7252543,   0.50132436, 0.95608366, 0.6439902,  0.42385504,  0.6063932,
    0.019193199, 0.30157483,  0.66017354, 0.2900776,   0.6180154,  0.4287687};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[5];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {5};
  const float   answer_0[]      = {1.6587627, 1.9992177, 1.8033181, 1.6431799, 1.7939386};
  const int32_t axes[]          = {0, 1};
  const int32_t number_of_axes  = 2;
  const int32_t keepdims        = 0;
  using dragonite::norm;

  ONNC_RUNTIME_reducelogsum_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                                  const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 5) <= 1e-5 * norm(answer_0, 5));
}

SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_default)
{
  const float input_0[] = {
    0.13547407,  0.29828233, 0.5699649,  0.59087276, 0.57432526,  0.6532008,   0.65210325, 0.43141845,  0.8965466,
    0.36756188,  0.43586493, 0.89192337, 0.806194,   0.7038886,   0.10022689,  0.9194826,  0.7142413,   0.998847,
    0.1494483,   0.86812603, 0.16249293, 0.6155596,  0.123819984, 0.8480082,   0.807319,   0.56910074,  0.4071833,
    0.069166996, 0.69742876, 0.45354268, 0.7220556,  0.8663823,   0.9755215,   0.8558034,  0.011714084, 0.35997805,
    0.72999054,  0.17162968, 0.5210366,  0.05433799, 0.19999653,  0.018521795, 0.7936977,  0.22392468,  0.34535167,
    0.9280813,   0.7044144,  0.03183893, 0.16469416, 0.6214784,   0.5772286,   0.23789282, 0.934214,    0.6139659,
    0.5356328,   0.58991,    0.730122,   0.311945,   0.39822108,  0.20984375};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[1];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float   answer_0[]      = {3.4324067};
  const int32_t keepdims        = 1;
  const int32_t axes[]          = {0, 1, 2};
  const int32_t number_of_axes  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_reducelogsum_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                                  const_cast<int32_t*>(axes), number_of_axes, keepdims);
  ASSERT_TRUE(norm(answer_0, output_0, 1) <= 1e-5 * norm(answer_0, 1));
}
