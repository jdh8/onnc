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
SKYPAT_F(Operator_ConvTranspose, test_convtranspose)
{
  const float    input_0[]      = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 1, 3, 3};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 4;
  const int32_t  input_1_dims[] = {1, 2, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[50];
  const int32_t  output_0_ndim          = 4;
  const int32_t  output_0_dims[]        = {1, 2, 5, 5};
  const float    answer_0[]             = {0.0,  1.0,  3.0,  3.0,  2.0,  3.0,  8.0,  15.0, 12.0, 7.0,  9.0,  21.0, 36.0,
                            27.0, 15.0, 9.0,  20.0, 33.0, 24.0, 13.0, 6.0,  13.0, 21.0, 15.0, 8.0,  0.0,
                            1.0,  3.0,  3.0,  2.0,  3.0,  8.0,  15.0, 12.0, 7.0,  9.0,  21.0, 36.0, 27.0,
                            15.0, 9.0,  20.0, 33.0, 24.0, 13.0, 6.0,  13.0, 21.0, 15.0, 8.0};
  const int32_t  kernel_shape[]         = {3, 3};
  const int32_t  number_of_kernel_shape = 2;
  const int32_t* output_padding         = nullptr;
  const int32_t  number_of_output_padding = 0;
  const int32_t  dilations[]              = {1, 1, 1, 1};
  const int32_t  number_of_dilations      = 4;
  const int32_t* output_shape             = nullptr;
  const int32_t  number_of_output_shape   = 0;
  const int32_t  strides[]                = {1, 1, 1, 1};
  const int32_t  number_of_strides        = 4;
  const int32_t  pads[]                   = {0, 0, 0, 0, 0, 0, 0, 0};
  const int32_t  number_of_pads           = 8;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 50) <= 1e-5 * norm(answer_0, 50));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_1d)
{
  const float    input_0[]      = {0.0, 1.0, 2.0};
  const int32_t  input_0_ndim   = 3;
  const int32_t  input_0_dims[] = {1, 1, 3};
  const float    input_1[]      = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 3;
  const int32_t  input_1_dims[] = {1, 2, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[10];
  const int32_t  output_0_ndim            = 3;
  const int32_t  output_0_dims[]          = {1, 2, 5};
  const float    answer_0[]               = {0.0, 1.0, 3.0, 3.0, 2.0, 0.0, 1.0, 3.0, 3.0, 2.0};
  const int32_t  kernel_shape[]           = {3};
  const int32_t  number_of_kernel_shape   = 1;
  const int32_t* output_padding           = nullptr;
  const int32_t  number_of_output_padding = 0;
  const int32_t  dilations[]              = {1, 1, 1};
  const int32_t  number_of_dilations      = 3;
  const int32_t* output_shape             = nullptr;
  const int32_t  number_of_output_shape   = 0;
  const int32_t  strides[]                = {1, 1, 1};
  const int32_t  number_of_strides        = 3;
  const int32_t  pads[]                   = {0, 0, 0, 0, 0, 0};
  const int32_t  number_of_pads           = 6;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 10) <= 1e-5 * norm(answer_0, 10));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_3d)
{
  const float    input_0[] = {0.0,  1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0, 11.0, 12.0, 13.0, 14.0,
                           15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,
                           30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0,
                           45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0};
  const int32_t  input_0_ndim   = 5;
  const int32_t  input_0_dims[] = {1, 1, 3, 4, 5};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                           1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                           1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 5;
  const int32_t  input_1_dims[] = {1, 2, 3, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[420];
  const int32_t  output_0_ndim   = 5;
  const int32_t  output_0_dims[] = {1, 2, 5, 6, 7};
  const float    answer_0[]      = {
    0.0,   1.0,   3.0,   6.0,   9.0,   7.0,   4.0,   5.0,   12.0,  21.0,  27.0,  33.0,  24.0,  13.0,  15.0,  33.0,
    54.0,  63.0,  72.0,  51.0,  27.0,  30.0,  63.0,  99.0,  108.0, 117.0, 81.0,  42.0,  25.0,  52.0,  81.0,  87.0,
    93.0,  64.0,  33.0,  15.0,  31.0,  48.0,  51.0,  54.0,  37.0,  19.0,  20.0,  42.0,  66.0,  72.0,  78.0,  54.0,
    28.0,  50.0,  104.0, 162.0, 174.0, 186.0, 128.0, 66.0,  90.0,  186.0, 288.0, 306.0, 324.0, 222.0, 114.0, 120.0,
    246.0, 378.0, 396.0, 414.0, 282.0, 144.0, 90.0,  184.0, 282.0, 294.0, 306.0, 208.0, 106.0, 50.0,  102.0, 156.0,
    162.0, 168.0, 114.0, 58.0,  60.0,  123.0, 189.0, 198.0, 207.0, 141.0, 72.0,  135.0, 276.0, 423.0, 441.0, 459.0,
    312.0, 159.0, 225.0, 459.0, 702.0, 729.0, 756.0, 513.0, 261.0, 270.0, 549.0, 837.0, 864.0, 891.0, 603.0, 306.0,
    195.0, 396.0, 603.0, 621.0, 639.0, 432.0, 219.0, 105.0, 213.0, 324.0, 333.0, 342.0, 231.0, 117.0, 60.0,  122.0,
    186.0, 192.0, 198.0, 134.0, 68.0,  130.0, 264.0, 402.0, 414.0, 426.0, 288.0, 146.0, 210.0, 426.0, 648.0, 666.0,
    684.0, 462.0, 234.0, 240.0, 486.0, 738.0, 756.0, 774.0, 522.0, 264.0, 170.0, 344.0, 522.0, 534.0, 546.0, 368.0,
    186.0, 90.0,  182.0, 276.0, 282.0, 288.0, 194.0, 98.0,  40.0,  81.0,  123.0, 126.0, 129.0, 87.0,  44.0,  85.0,
    172.0, 261.0, 267.0, 273.0, 184.0, 93.0,  135.0, 273.0, 414.0, 423.0, 432.0, 291.0, 147.0, 150.0, 303.0, 459.0,
    468.0, 477.0, 321.0, 162.0, 105.0, 212.0, 321.0, 327.0, 333.0, 224.0, 113.0, 55.0,  111.0, 168.0, 171.0, 174.0,
    117.0, 59.0,  0.0,   1.0,   3.0,   6.0,   9.0,   7.0,   4.0,   5.0,   12.0,  21.0,  27.0,  33.0,  24.0,  13.0,
    15.0,  33.0,  54.0,  63.0,  72.0,  51.0,  27.0,  30.0,  63.0,  99.0,  108.0, 117.0, 81.0,  42.0,  25.0,  52.0,
    81.0,  87.0,  93.0,  64.0,  33.0,  15.0,  31.0,  48.0,  51.0,  54.0,  37.0,  19.0,  20.0,  42.0,  66.0,  72.0,
    78.0,  54.0,  28.0,  50.0,  104.0, 162.0, 174.0, 186.0, 128.0, 66.0,  90.0,  186.0, 288.0, 306.0, 324.0, 222.0,
    114.0, 120.0, 246.0, 378.0, 396.0, 414.0, 282.0, 144.0, 90.0,  184.0, 282.0, 294.0, 306.0, 208.0, 106.0, 50.0,
    102.0, 156.0, 162.0, 168.0, 114.0, 58.0,  60.0,  123.0, 189.0, 198.0, 207.0, 141.0, 72.0,  135.0, 276.0, 423.0,
    441.0, 459.0, 312.0, 159.0, 225.0, 459.0, 702.0, 729.0, 756.0, 513.0, 261.0, 270.0, 549.0, 837.0, 864.0, 891.0,
    603.0, 306.0, 195.0, 396.0, 603.0, 621.0, 639.0, 432.0, 219.0, 105.0, 213.0, 324.0, 333.0, 342.0, 231.0, 117.0,
    60.0,  122.0, 186.0, 192.0, 198.0, 134.0, 68.0,  130.0, 264.0, 402.0, 414.0, 426.0, 288.0, 146.0, 210.0, 426.0,
    648.0, 666.0, 684.0, 462.0, 234.0, 240.0, 486.0, 738.0, 756.0, 774.0, 522.0, 264.0, 170.0, 344.0, 522.0, 534.0,
    546.0, 368.0, 186.0, 90.0,  182.0, 276.0, 282.0, 288.0, 194.0, 98.0,  40.0,  81.0,  123.0, 126.0, 129.0, 87.0,
    44.0,  85.0,  172.0, 261.0, 267.0, 273.0, 184.0, 93.0,  135.0, 273.0, 414.0, 423.0, 432.0, 291.0, 147.0, 150.0,
    303.0, 459.0, 468.0, 477.0, 321.0, 162.0, 105.0, 212.0, 321.0, 327.0, 333.0, 224.0, 113.0, 55.0,  111.0, 168.0,
    171.0, 174.0, 117.0, 59.0};
  const int32_t  kernel_shape[]           = {3, 3, 3};
  const int32_t  number_of_kernel_shape   = 3;
  const int32_t* output_padding           = nullptr;
  const int32_t  number_of_output_padding = 0;
  const int32_t  dilations[]              = {1, 1, 1, 1, 1};
  const int32_t  number_of_dilations      = 5;
  const int32_t* output_shape             = nullptr;
  const int32_t  number_of_output_shape   = 0;
  const int32_t  strides[]                = {1, 1, 1, 1, 1};
  const int32_t  number_of_strides        = 5;
  const int32_t  pads[]                   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const int32_t  number_of_pads           = 10;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 420) <= 1e-5 * norm(answer_0, 420));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_output_shape)
{
  const float    input_0[]      = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 1, 3, 3};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 4;
  const int32_t  input_1_dims[] = {1, 2, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[160];
  const int32_t  output_0_ndim   = 4;
  const int32_t  output_0_dims[] = {1, 2, 10, 8};
  const float    answer_0[]      = {
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0,
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0};
  const int32_t  output_shape[]           = {1, 2, 10, 8};
  const int32_t  number_of_output_shape   = 4;
  const int32_t  strides[]                = {3, 2};
  const int32_t  number_of_strides        = 2;
  const int32_t  kernel_shape[]           = {3, 3};
  const int32_t  number_of_kernel_shape   = 2;
  const int32_t* output_padding           = nullptr;
  const int32_t  number_of_output_padding = 0;
  const int32_t  dilations[]              = {1, 1, 1, 1};
  const int32_t  number_of_dilations      = 4;
  const int32_t  pads[]                   = {0, 0, 0, 0, 0, 0, 0, 0};
  const int32_t  number_of_pads           = 8;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 160) <= 1e-5 * norm(answer_0, 160));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_pad)
{
  const float    input_0[]      = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 1, 3, 3};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 4;
  const int32_t  input_1_dims[] = {1, 2, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[160];
  const int32_t  output_0_ndim   = 4;
  const int32_t  output_0_dims[] = {1, 2, 10, 8};
  const float    answer_0[]      = {
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0,
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0};
  const int32_t  output_padding[]         = {1, 1};
  const int32_t  number_of_output_padding = 2;
  const int32_t  strides[]                = {3, 2};
  const int32_t  number_of_strides        = 2;
  const int32_t  kernel_shape[]           = {3, 3};
  const int32_t  number_of_kernel_shape   = 2;
  const int32_t  dilations[]              = {1, 1, 1, 1};
  const int32_t  number_of_dilations      = 4;
  const int32_t* output_shape             = nullptr;
  const int32_t  number_of_output_shape   = 0;
  const int32_t  pads[]                   = {0, 0, 0, 0, 0, 0, 0, 0};
  const int32_t  number_of_pads           = 8;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 160) <= 1e-5 * norm(answer_0, 160));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_kernel_shape)
{
  const float    input_0[]      = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 1, 3, 3};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 4;
  const int32_t  input_1_dims[] = {1, 2, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[160];
  const int32_t  output_0_ndim   = 4;
  const int32_t  output_0_dims[] = {1, 2, 10, 8};
  const float    answer_0[]      = {
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0,
    0.0,  0.0, 1.0, 1.0, 3.0, 2.0, 2.0,  0.0, 0.0,  0.0, 1.0,  1.0, 3.0,  2.0, 2.0, 0.0, 0.0, 0.0, 1.0,  1.0,
    3.0,  2.0, 2.0, 0.0, 3.0, 3.0, 7.0,  4.0, 9.0,  5.0, 5.0,  0.0, 3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0,
    3.0,  3.0, 7.0, 4.0, 9.0, 5.0, 5.0,  0.0, 6.0,  6.0, 13.0, 7.0, 15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0,
    15.0, 8.0, 8.0, 0.0, 6.0, 6.0, 13.0, 7.0, 15.0, 8.0, 8.0,  0.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0};
  const int32_t kernel_shape[]           = {3, 3};
  const int32_t number_of_kernel_shape   = 2;
  const int32_t output_padding[]         = {1, 1};
  const int32_t number_of_output_padding = 2;
  const int32_t output_shape[]           = {10, 8};
  const int32_t number_of_output_shape   = 2;
  const int32_t strides[]                = {3, 2};
  const int32_t number_of_strides        = 2;
  const int32_t dilations[]              = {1, 1, 1, 1};
  const int32_t number_of_dilations      = 4;
  const int32_t pads[]                   = {0, 0, 0, 0, 0, 0, 0, 0};
  const int32_t number_of_pads           = 8;
  const int32_t group                    = 1;
  const char    auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 160) <= 1e-5 * norm(answer_0, 160));
}

SKYPAT_F(Operator_ConvTranspose, test_convtranspose_pads)
{
  const float    input_0[]      = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 1, 3, 3};
  const float    input_1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  const int32_t  input_1_ndim   = 4;
  const int32_t  input_1_dims[] = {1, 2, 3, 3};
  const float*   input_2        = nullptr;
  const int32_t  input_2_ndim   = 0;
  const int32_t* input_2_dims   = nullptr;
  float          output_0[42];
  const int32_t  output_0_ndim          = 4;
  const int32_t  output_0_dims[]        = {1, 2, 7, 3};
  const float    answer_0[]             = {1.0, 1.0,  3.0, 1.0,  1.0,  3.0, 7.0,  4.0, 9.0,  7.0, 4.0,  9.0,  7.0, 4.0,
                            9.0, 13.0, 7.0, 15.0, 13.0, 7.0, 15.0, 1.0, 1.0,  3.0, 1.0,  1.0,  3.0, 7.0,
                            4.0, 9.0,  7.0, 4.0,  9.0,  7.0, 4.0,  9.0, 13.0, 7.0, 15.0, 13.0, 7.0, 15.0};
  const int32_t  pads[]                 = {1, 2, 1, 2};
  const int32_t  number_of_pads         = 4;
  const int32_t  strides[]              = {3, 2};
  const int32_t  number_of_strides      = 2;
  const int32_t  kernel_shape[]         = {3, 3};
  const int32_t  number_of_kernel_shape = 2;
  const int32_t* output_padding         = nullptr;
  const int32_t  number_of_output_padding = 0;
  const int32_t  dilations[]              = {1, 1, 1, 1};
  const int32_t  number_of_dilations      = 4;
  const int32_t* output_shape             = nullptr;
  const int32_t  number_of_output_shape   = 0;
  const int32_t  group                    = 1;
  const char     auto_pad[]               = "NOTSET";
  using dragonite::norm;

  ONNC_RUNTIME_convtranspose_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, output_0, output_0_ndim, output_0_dims, auto_pad, const_cast<int32_t*>(dilations),
    number_of_dilations, group, const_cast<int32_t*>(kernel_shape), number_of_kernel_shape,
    const_cast<int32_t*>(output_padding), number_of_output_padding, const_cast<int32_t*>(output_shape),
    number_of_output_shape, const_cast<int32_t*>(pads), number_of_pads, const_cast<int32_t*>(strides),
    number_of_strides);
  ASSERT_TRUE(norm(answer_0, output_0, 42) <= 1e-5 * norm(answer_0, 42));
}
