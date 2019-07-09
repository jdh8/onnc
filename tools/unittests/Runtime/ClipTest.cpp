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
SKYPAT_F(Operator_Clip, test_clip_example)
{
  const float   input_0[]      = {-2.0, 0.0, 2.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-1.0, 0.0, 1.0};
  const float   max             = 1.0;
  const float   min             = -1.0;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Clip, test_clip)
{
  const float input_0[] = {
    -1.9226638,  0.037736747, -0.47873202, -2.3626666, -1.452496,   1.0355289,   0.01368711,  -0.77815855, -2.690025,
    -1.2229133,  1.5918517,   0.37726197,  0.03218782, 0.37240967,  0.32993165,  0.892804,    -1.0530704,  -1.687135,
    -0.53232133, -0.8045805,  0.034033433, -1.526617,  -0.08374233, 0.48877126,  1.4119611,   -0.15999147, -0.9965593,
    -0.32458782, -2.1988537,  0.54462165,  0.43870178, 1.2867061,   -0.23258895, -1.2282492,  0.37849924,  0.7969726,
    -1.2450156,  -0.88423836, 0.37373197,  0.03133411, -0.30433217, 0.8642478,   0.6081181,   0.9213503,   -1.2149225,
    -0.1068271,  0.08697758,  -0.23202935, -1.1379001, 1.3047986,   0.22594747,  -0.54565126, -0.6649694,  -1.0706555,
    0.8633887,   0.44747448,  1.8298367,   -0.8966518, 0.50396687,  -0.7053744};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    -1.0,        0.037736747, -0.47873202, -1.0,       -1.0,        1.0,         0.01368711,  -0.77815855, -1.0,
    -1.0,        1.0,         0.37726197,  0.03218782, 0.37240967,  0.32993165,  0.892804,    -1.0,        -1.0,
    -0.53232133, -0.8045805,  0.034033433, -1.0,       -0.08374233, 0.48877126,  1.0,         -0.15999147, -0.9965593,
    -0.32458782, -1.0,        0.54462165,  0.43870178, 1.0,         -0.23258895, -1.0,        0.37849924,  0.7969726,
    -1.0,        -0.88423836, 0.37373197,  0.03133411, -0.30433217, 0.8642478,   0.6081181,   0.9213503,   -1.0,
    -0.1068271,  0.08697758,  -0.23202935, -1.0,       1.0,         0.22594747,  -0.54565126, -0.6649694,  -1.0,
    0.8633887,   0.44747448,  1.0,         -0.8966518, 0.50396687,  -0.7053744};
  const float max = 1.0;
  const float min = -1.0;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Clip, test_clip_inbounds)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-1.0, 0.0, 1.0};
  const float   max             = 5.0;
  const float   min             = -5.0;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Clip, test_clip_outbounds)
{
  const float   input_0[]      = {-6.0, 0.0, 6.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-5.0, 0.0, 5.0};
  const float   max             = 5.0;
  const float   min             = -5.0;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Clip, test_clip_splitbounds)
{
  const float   input_0[]      = {-1.0, 0.0, 6.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-1.0, 0.0, 5.0};
  const float   max             = 5.0;
  const float   min             = -5.0;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Clip, test_clip_default_min)
{
  const float input_0[] = {
    1.432087,    -0.82094866, 1.1028023,   0.00708847,  -0.84984034, -0.21907134, -0.6194535, 0.117260195, 1.4477043,
    -0.29696617, 1.6856686,   0.6793776,   0.24997382,  0.5755009,   -1.3822881,  -2.077067,  0.67383677,  0.7032762,
    -1.6383933,  0.67665356,  1.4185745,   -0.63998383, 1.0887034,   0.8326136,   0.5217048,  -0.5249237,  -1.7508837,
    0.5977544,   1.3829861,   1.6240438,   0.422191,    0.48245755,  0.7335197,   -1.7904865, -1.2513127,  -0.8394098,
    0.43628508,  -0.96459156, 0.10322627,  -0.6524923,  -0.66813624, 1.4496588,   1.2872846,  0.31384668,  -1.3121336,
    -1.7030454,  -0.20719965, 0.9853862,   -0.2008195,  -0.19402434, -0.01330597, -0.3682147, 0.71667993,  0.21259841,
    0.83849865,  0.8695076,   -0.63379616, 0.054452315, -0.80993986, -0.2918875};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    1.432087,   0.0,        1.1028023,  0.00708847,  0.0,        0.0,       0.0,       0.117260195, 1.4477043,
    0.0,        1.6856686,  0.6793776,  0.24997382,  0.5755009,  0.0,       0.0,       0.67383677,  0.7032762,
    0.0,        0.67665356, 1.4185745,  0.0,         1.0887034,  0.8326136, 0.5217048, 0.0,         0.0,
    0.5977544,  1.3829861,  1.6240438,  0.422191,    0.48245755, 0.7335197, 0.0,       0.0,         0.0,
    0.43628508, 0.0,        0.10322627, 0.0,         0.0,        1.4496588, 1.2872846, 0.31384668,  0.0,
    0.0,        0.0,        0.9853862,  0.0,         0.0,        0.0,       0.0,       0.71667993,  0.21259841,
    0.83849865, 0.8695076,  0.0,        0.054452315, 0.0,        0.0};
  const float min = 0.0;
  const float max = 3.4028234663852886e+38;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Clip, test_clip_default_max)
{
  const float input_0[] = {
    0.767893,   0.09959915,  -0.7920895,  -0.7084449, 0.081120916, -0.7088667,   -1.1804086,  -1.3284787,  0.91982937,
    1.2278854,  -0.46085343, 1.737479,    -2.4468544, 1.1196238,   1.3022277,    0.1050835,   -1.0568743,  -0.53077453,
    -1.1286724, 0.63563305,  -0.68583477, 0.9660226,  -1.193457,   0.069037385,  0.26626134,  0.8566715,   -0.48344052,
    0.47819704, -1.3533295,  1.2421168,   -0.6161104, -1.7249465,  -0.052377805, 1.1094599,   -0.50428826, 1.0049735,
    0.5329762,  -0.44193336, -0.2913508,  0.16909392, -0.13904324, 1.4017639,    -0.76561725, -0.18829228, -0.93789333,
    -1.174747,  -1.1820844,  -2.347632,   1.9171302,  0.8250364,   1.133502,     1.0454731,   -0.8035571,  -0.8294301,
    0.1658978,  0.2053967,   0.17401208,  0.83541656, 0.13207087,  0.42653206};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.0,        0.0,         -0.7920895,  -0.7084449, 0.0,         -0.7088667,   -1.1804086,  -1.3284787,  0.0,
    0.0,        -0.46085343, 0.0,         -2.4468544, 0.0,         0.0,          0.0,         -1.0568743,  -0.53077453,
    -1.1286724, 0.0,         -0.68583477, 0.0,        -1.193457,   0.0,          0.0,         0.0,         -0.48344052,
    0.0,        -1.3533295,  0.0,         -0.6161104, -1.7249465,  -0.052377805, 0.0,         -0.50428826, 0.0,
    0.0,        -0.44193336, -0.2913508,  0.0,        -0.13904324, 0.0,          -0.76561725, -0.18829228, -0.93789333,
    -1.174747,  -1.1820844,  -2.347632,   0.0,        0.0,         0.0,          0.0,         -0.8035571,  -0.8294301,
    0.0,        0.0,         0.0,         0.0,        0.0,         0.0};
  const float max = 0.0;
  const float min = -3.4028234663852886e+38;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Clip, test_clip_default_inbounds)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-1.0, 0.0, 1.0};
  const float   max             = 3.4028234663852886e+38;
  const float   min             = -3.4028234663852886e+38;
  using dragonite::norm;

  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims, max,
                          min);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}
