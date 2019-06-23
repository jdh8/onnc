#include <skypat/skypat.h>
#include <cstring>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Conv, test_basic_conv_with_padding) {
  const float input_0[1][1][5][5] = {{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                       {5.0, 6.0, 7.0, 8.0, 9.0},
                                       {10.0, 11.0, 12.0, 13.0, 14.0},
                                       {15.0, 16.0, 17.0, 18.0, 19.0},
                                       {20.0, 21.0, 22.0, 23.0, 24.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 5, 5};
  const float input_1[1][1][3][3] = {
      {{{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}}};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 1, 3, 3};
  const float input_2[] = {};
  const int32_t input_2_ndim = 0;
  const int32_t input_2_dims[] = {};
  float output_0[1][1][5][5];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 5, 5};
  const float answer_0[1][1][5][5] = {{{{12.0, 21.0, 27.0, 33.0, 24.0},
                                        {33.0, 54.0, 63.0, 72.0, 51.0},
                                        {63.0, 99.0, 108.0, 117.0, 81.0},
                                        {93.0, 144.0, 153.0, 162.0, 111.0},
                                        {72.0, 111.0, 117.0, 123.0, 84.0}}}};
  const int32_t kernel_shape[] = {3, 3};
  const int32_t number_of_kernel_shape = 2;
  const int32_t pads[] = {1, 1, 1, 1};
  const int32_t number_of_pads = 4;
  const int32_t group = 0;
  const auto auto_pad = "NOTSET";
  const int32_t dilations[] = {};
  const int32_t number_of_dilations = 0;
  const int32_t strides[] = {};
  const int32_t number_of_strides = 0;
  ONNC_RUNTIME_conv_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)output_0, output_0_ndim, output_0_dims, auto_pad,
      (int32_t *)dilations, number_of_dilations, group, (int32_t *)kernel_shape,
      number_of_kernel_shape, (int32_t *)pads, number_of_pads,
      (int32_t *)strides, number_of_strides);

  ASSERT_FALSE(std::memcmp(output_0, answer_0, 1 * 1 * 5 * 5 * sizeof(float)));
}

SKYPAT_F(Operator_Conv, test_basic_conv_without_padding) {
  const float input_0[1][1][5][5] = {{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                       {5.0, 6.0, 7.0, 8.0, 9.0},
                                       {10.0, 11.0, 12.0, 13.0, 14.0},
                                       {15.0, 16.0, 17.0, 18.0, 19.0},
                                       {20.0, 21.0, 22.0, 23.0, 24.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 5, 5};
  const float input_1[1][1][3][3] = {
      {{{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}}};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 1, 3, 3};
  const float input_2[] = {};
  const int32_t input_2_ndim = 0;
  const int32_t input_2_dims[] = {};
  float output_0[1][1][3][3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 3, 3};
  const float answer_0[1][1][3][3] = {
      {{{54.0, 63.0, 72.0}, {99.0, 108.0, 117.0}, {144.0, 153.0, 162.0}}}};
  const int32_t kernel_shape[] = {3, 3};
  const int32_t number_of_kernel_shape = 2;
  const int32_t pads[] = {0, 0, 0, 0};
  const int32_t number_of_pads = 4;
  const int32_t group = 0;
  const auto auto_pad = "NOTSET";
  const int32_t dilations[] = {};
  const int32_t number_of_dilations = 0;
  const int32_t strides[] = {};
  const int32_t number_of_strides = 0;
  ONNC_RUNTIME_conv_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)output_0, output_0_ndim, output_0_dims, auto_pad,
      (int32_t *)dilations, number_of_dilations, group, (int32_t *)kernel_shape,
      number_of_kernel_shape, (int32_t *)pads, number_of_pads,
      (int32_t *)strides, number_of_strides);

  ASSERT_FALSE(std::memcmp(output_0, answer_0, 1 * 1 * 3 * 3 * sizeof(float)));
}

SKYPAT_F(Operator_Conv, test_conv_with_strides_padding) {
  const float input_0[1][1][7][5] = {{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                       {5.0, 6.0, 7.0, 8.0, 9.0},
                                       {10.0, 11.0, 12.0, 13.0, 14.0},
                                       {15.0, 16.0, 17.0, 18.0, 19.0},
                                       {20.0, 21.0, 22.0, 23.0, 24.0},
                                       {25.0, 26.0, 27.0, 28.0, 29.0},
                                       {30.0, 31.0, 32.0, 33.0, 34.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 7, 5};
  const float input_1[1][1][3][3] = {
      {{{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}}};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 1, 3, 3};
  const float input_2[] = {};
  const int32_t input_2_ndim = 0;
  const int32_t input_2_dims[] = {};
  float output_0[1][1][4][3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 4, 3};
  const float answer_0[1][1][4][3] = {{{{12.0, 27.0, 24.0},
                                        {63.0, 108.0, 81.0},
                                        {123.0, 198.0, 141.0},
                                        {112.0, 177.0, 124.0}}}};
  const int32_t kernel_shape[] = {3, 3};
  const int32_t number_of_kernel_shape = 2;
  const int32_t pads[] = {1, 1, 1, 1};
  const int32_t number_of_pads = 4;
  const int32_t strides[] = {2, 2};
  const int32_t number_of_strides = 2;
  const int32_t group = 0;
  const auto auto_pad = "NOTSET";
  const int32_t dilations[] = {};
  const int32_t number_of_dilations = 0;
  ONNC_RUNTIME_conv_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)output_0, output_0_ndim, output_0_dims, auto_pad,
      (int32_t *)dilations, number_of_dilations, group, (int32_t *)kernel_shape,
      number_of_kernel_shape, (int32_t *)pads, number_of_pads,
      (int32_t *)strides, number_of_strides);

  ASSERT_FALSE(std::memcmp(output_0, answer_0, 1 * 1 * 4 * 3 * sizeof(float)));
}

SKYPAT_F(Operator_Conv, test_conv_with_strides_no_padding) {
  const float input_0[1][1][7][5] = {{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                       {5.0, 6.0, 7.0, 8.0, 9.0},
                                       {10.0, 11.0, 12.0, 13.0, 14.0},
                                       {15.0, 16.0, 17.0, 18.0, 19.0},
                                       {20.0, 21.0, 22.0, 23.0, 24.0},
                                       {25.0, 26.0, 27.0, 28.0, 29.0},
                                       {30.0, 31.0, 32.0, 33.0, 34.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 7, 5};
  const float input_1[1][1][3][3] = {
      {{{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}}};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 1, 3, 3};
  const float input_2[] = {};
  const int32_t input_2_ndim = 0;
  const int32_t input_2_dims[] = {};
  float output_0[1][1][3][2];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 3, 2};
  const float answer_0[1][1][3][2] = {
      {{{54.0, 72.0}, {144.0, 162.0}, {234.0, 252.0}}}};
  const int32_t kernel_shape[] = {3, 3};
  const int32_t number_of_kernel_shape = 2;
  const int32_t pads[] = {0, 0, 0, 0};
  const int32_t number_of_pads = 4;
  const int32_t strides[] = {2, 2};
  const int32_t number_of_strides = 2;
  const int32_t group = 0;
  const auto auto_pad = "NOTSET";
  const int32_t dilations[] = {};
  const int32_t number_of_dilations = 0;
  ONNC_RUNTIME_conv_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)output_0, output_0_ndim, output_0_dims, auto_pad,
      (int32_t *)dilations, number_of_dilations, group, (int32_t *)kernel_shape,
      number_of_kernel_shape, (int32_t *)pads, number_of_pads,
      (int32_t *)strides, number_of_strides);

  ASSERT_FALSE(std::memcmp(output_0, answer_0, 1 * 1 * 3 * 2 * sizeof(float)));
}

SKYPAT_F(Operator_Conv, test_conv_with_strides_and_asymmetric_padding) {
  const float input_0[1][1][7][5] = {{{{0.0, 1.0, 2.0, 3.0, 4.0},
                                       {5.0, 6.0, 7.0, 8.0, 9.0},
                                       {10.0, 11.0, 12.0, 13.0, 14.0},
                                       {15.0, 16.0, 17.0, 18.0, 19.0},
                                       {20.0, 21.0, 22.0, 23.0, 24.0},
                                       {25.0, 26.0, 27.0, 28.0, 29.0},
                                       {30.0, 31.0, 32.0, 33.0, 34.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 7, 5};
  const float input_1[1][1][3][3] = {
      {{{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}}};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 1, 3, 3};
  const float input_2[] = {};
  const int32_t input_2_ndim = 0;
  const int32_t input_2_dims[] = {};
  float output_0[1][1][4][2];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 4, 2};
  const float answer_0[1][1][4][2] = {
      {{{21.0, 33.0}, {99.0, 117.0}, {189.0, 207.0}, {171.0, 183.0}}}};
  const int32_t kernel_shape[] = {3, 3};
  const int32_t number_of_kernel_shape = 2;
  const int32_t pads[] = {1, 0, 1, 0};
  const int32_t number_of_pads = 4;
  const int32_t strides[] = {2, 2};
  const int32_t number_of_strides = 2;
  const int32_t group = 0;
  const auto auto_pad = "NOTSET";
  const int32_t dilations[] = {};
  const int32_t number_of_dilations = 0;
  ONNC_RUNTIME_conv_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)output_0, output_0_ndim, output_0_dims, auto_pad,
      (int32_t *)dilations, number_of_dilations, group, (int32_t *)kernel_shape,
      number_of_kernel_shape, (int32_t *)pads, number_of_pads,
      (int32_t *)strides, number_of_strides);

  ASSERT_FALSE(std::memcmp(output_0, answer_0, 1 * 1 * 4 * 2 * sizeof(float)));
}
