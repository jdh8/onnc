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
SKYPAT_F(Operator_Hardmax, test_hardmax_example)
{
  const float   input_0[]      = {3.0, 0.0, 1.0, 2.0, 2.0, 5.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0, 0.0, 1.0, 2.0, 3.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {4, 4};
  float         output_0[16];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {4, 4};
  const float   answer_0[]      = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  const int32_t axis            = 1;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 16) <= 1e-5 * norm(answer_0, 16));
}

SKYPAT_F(Operator_Hardmax, test_hardmax_one_hot)
{
  const float   input_0[]      = {3.0, 3.0, 3.0, 1.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {1, 4};
  float         output_0[4];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {1, 4};
  const float   answer_0[]      = {1.0, 0.0, 0.0, 0.0};
  const int32_t axis            = 1;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 4) <= 1e-5 * norm(answer_0, 4));
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_0)
{
  const float input_0[] = {
    0.7555146,   -1.2220299,  -1.0092077,  0.5461298,   -1.2571529, 2.637772,    0.8239977,  -0.9808041, -0.5837255,
    1.3204993,   0.6173801,   -0.2504949,  -0.94966274, -1.0147859, 1.5039381,   -1.2344719, 0.19058684, -0.4765908,
    0.50713086,  -0.39702353, 0.6626875,   -2.1393485,  -0.6461381, 1.1344111,   1.3513979,  1.24134,    0.5521407,
    0.67783535,  -1.8488021,  1.2143315,   -0.50284797, -1.1803603, -1.9157468,  -0.5661646, 0.5335342,  0.67380506,
    0.7474762,   0.18526098,  -1.2848785,  -1.0715148,  0.8060344,  -0.26709542, -1.4719692, 1.6967707,  -0.7200085,
    -0.10863107, 1.1658612,   -0.17353009, -0.23584168, 0.6569154,  0.41698486,  1.2859385,  -0.2432887, -0.9329677,
    -1.5587016,  -0.52437913, 0.44369102,  -0.3658608,  1.6270592,  -0.017222155};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t axis            = 0;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_1)
{
  const float input_0[] = {
    0.7555146,   -1.2220299,  -1.0092077,  0.5461298,   -1.2571529, 2.637772,    0.8239977,  -0.9808041, -0.5837255,
    1.3204993,   0.6173801,   -0.2504949,  -0.94966274, -1.0147859, 1.5039381,   -1.2344719, 0.19058684, -0.4765908,
    0.50713086,  -0.39702353, 0.6626875,   -2.1393485,  -0.6461381, 1.1344111,   1.3513979,  1.24134,    0.5521407,
    0.67783535,  -1.8488021,  1.2143315,   -0.50284797, -1.1803603, -1.9157468,  -0.5661646, 0.5335342,  0.67380506,
    0.7474762,   0.18526098,  -1.2848785,  -1.0715148,  0.8060344,  -0.26709542, -1.4719692, 1.6967707,  -0.7200085,
    -0.10863107, 1.1658612,   -0.17353009, -0.23584168, 0.6569154,  0.41698486,  1.2859385,  -0.2432887, -0.9329677,
    -1.5587016,  -0.52437913, 0.44369102,  -0.3658608,  1.6270592,  -0.017222155};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t axis            = 1;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Hardmax, test_hardmax_default_axis)
{
  const float input_0[] = {
    0.7555146,   -1.2220299,  -1.0092077,  0.5461298,   -1.2571529, 2.637772,    0.8239977,  -0.9808041, -0.5837255,
    1.3204993,   0.6173801,   -0.2504949,  -0.94966274, -1.0147859, 1.5039381,   -1.2344719, 0.19058684, -0.4765908,
    0.50713086,  -0.39702353, 0.6626875,   -2.1393485,  -0.6461381, 1.1344111,   1.3513979,  1.24134,    0.5521407,
    0.67783535,  -1.8488021,  1.2143315,   -0.50284797, -1.1803603, -1.9157468,  -0.5661646, 0.5335342,  0.67380506,
    0.7474762,   0.18526098,  -1.2848785,  -1.0715148,  0.8060344,  -0.26709542, -1.4719692, 1.6967707,  -0.7200085,
    -0.10863107, 1.1658612,   -0.17353009, -0.23584168, 0.6569154,  0.41698486,  1.2859385,  -0.2432887, -0.9329677,
    -1.5587016,  -0.52437913, 0.44369102,  -0.3658608,  1.6270592,  -0.017222155};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const int32_t axis            = 1;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_2)
{
  const float input_0[] = {
    0.7555146,   -1.2220299,  -1.0092077,  0.5461298,   -1.2571529, 2.637772,    0.8239977,  -0.9808041, -0.5837255,
    1.3204993,   0.6173801,   -0.2504949,  -0.94966274, -1.0147859, 1.5039381,   -1.2344719, 0.19058684, -0.4765908,
    0.50713086,  -0.39702353, 0.6626875,   -2.1393485,  -0.6461381, 1.1344111,   1.3513979,  1.24134,    0.5521407,
    0.67783535,  -1.8488021,  1.2143315,   -0.50284797, -1.1803603, -1.9157468,  -0.5661646, 0.5335342,  0.67380506,
    0.7474762,   0.18526098,  -1.2848785,  -1.0715148,  0.8060344,  -0.26709542, -1.4719692, 1.6967707,  -0.7200085,
    -0.10863107, 1.1658612,   -0.17353009, -0.23584168, 0.6569154,  0.41698486,  1.2859385,  -0.2432887, -0.9329677,
    -1.5587016,  -0.52437913, 0.44369102,  -0.3658608,  1.6270592,  -0.017222155};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
                            0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  const int32_t axis            = 2;
  using dragonite::norm;

  ONNC_RUNTIME_hardmax_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                             axis);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
