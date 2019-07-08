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
SKYPAT_F(Operator_Atan, test_atan_example) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-0.7853982, 0.0, 0.7853982};
  ONNC_RUNTIME_atan_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Atan, test_atan) {
  const float input_0[] = {
      0.64958566,  -0.59490407,  -0.3001877,  0.0929556,    -1.582007,
      -1.1836756,  0.8041273,    -0.83402246, -1.0211961,   0.708909,
      0.65428513,  -0.045954082, 3.2878065,   -1.0249038,   -1.2357826,
      0.98331285,  1.018461,     1.8137531,   -0.11160565,  -1.5910296,
      -0.20220296, 0.64329326,   -0.5834191,  1.5712059,    0.07615746,
      -0.859962,   -0.836217,    -1.3218805,  -0.62911165,  0.078853115,
      -0.28819337, -0.1822017,   1.1692663,   -0.122548826, 0.027974958,
      -0.8812421,  1.2557086,    -0.62221324, -1.9836886,   1.7698716,
      -0.2890374,  -1.0812049,   0.3621462,   -0.7963175,   -1.1366776,
      -0.45007294, -0.71892166,  -0.4039285,  -0.82006305,  0.8604987,
      -0.40179777, -0.850726,    0.6468476,   -1.1700919,   0.5595208,
      1.0014089,   0.96894395,   0.014934174, 0.3468043,    1.318654};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.5760839,   -0.53666407,  -0.291629,   0.09268924,   -1.0071017,
      -0.8693137,  0.67725253,   -0.69514483, -0.7958847,   0.61668015,
      0.5793817,   -0.045921776, 1.2755327,   -0.7976963,   -0.8904685,
      0.7769846,   0.794544,     1.0669227,   -0.111145705, -1.009667,
      -0.19951288, 0.571646,     -0.5281384,  1.0040029,    0.076010734,
      -0.7102492,  -0.6964377,   -0.9231494,  -0.56155056,  0.07869029,
      -0.28059015, -0.18022472,  0.8632697,   -0.12194081,  0.027967663,
      -0.7223544,  0.8982769,    -0.5565928,  -1.103865,    1.0565001,
      -0.28136927, -0.8243966,   0.34745425,  -0.6724915,   -0.8492785,
      -0.4229146,  -0.6233125,   -0.38388842, -0.6868554,   0.71055764,
      -0.38205522, -0.7049154,   0.5741559,   -0.86361825,  0.51012343,
      0.7861021,   0.7696265,    0.014933064, 0.33382502,   0.92197317};
  ONNC_RUNTIME_atan_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
