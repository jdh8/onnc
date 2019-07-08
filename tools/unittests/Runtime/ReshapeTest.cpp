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
SKYPAT_F(Operator_Reshape, test_reshape_reordered_dims) {
  const float input_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {4, 2, 3};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 2, 3};
  const float answer_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  ONNC_RUNTIME_reshape_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             input_1, input_1_ndim, input_1_dims, output_0,
                             output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 24) < 1e-5f);
}

SKYPAT_F(Operator_Reshape, test_reshape_reduced_dims) {
  const float input_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {3, 8};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[24];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 8};
  const float answer_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  ONNC_RUNTIME_reshape_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             input_1, input_1_ndim, input_1_dims, output_0,
                             output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 24) < 1e-5f);
}

SKYPAT_F(Operator_Reshape, test_reshape_extended_dims) {
  const float input_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {3, 2, 2, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {4};
  float output_0[24];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {3, 2, 2, 2};
  const float answer_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  ONNC_RUNTIME_reshape_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             input_1, input_1_ndim, input_1_dims, output_0,
                             output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 24) < 1e-5f);
}

SKYPAT_F(Operator_Reshape, test_reshape_one_dim) {
  const float input_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {24};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {1};
  float output_0[24];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {24};
  const float answer_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  ONNC_RUNTIME_reshape_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             input_1, input_1_ndim, input_1_dims, output_0,
                             output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 24) < 1e-5f);
}

SKYPAT_F(Operator_Reshape, test_reshape_negative_dim) {
  const float input_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {6, -1, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {6, 2, 2};
  const float answer_0[] = {
      0.31856894, 0.6674104,   0.13179787, 0.7163272,   0.2894061, 0.18319136,
      0.5865129,  0.020107547, 0.82894003, 0.004695476, 0.6778165, 0.27000797,
      0.735194,   0.96218854,  0.24875315, 0.57615733,  0.5920419, 0.5722519,
      0.22308163, 0.952749,    0.44712538, 0.84640867,  0.6994793, 0.29743695};
  ONNC_RUNTIME_reshape_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             input_1, input_1_ndim, input_1_dims, output_0,
                             output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 24) < 1e-5f);
}
