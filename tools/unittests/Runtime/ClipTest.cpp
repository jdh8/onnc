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
SKYPAT_F(Operator_Clip, test_clip_example) {
  const float input_0[] = {-2.0, 0.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float max = 1.0;
  const float min = -1.0;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip) {
  const float input_0[] = {
      -1.5021884,  0.81836003, 0.6717688,   0.2792652,   2.123575,
      0.038950108, 2.0840065,  -1.5626985,  -0.9994479,  1.4185332,
      -0.16292474, 0.55694956, -0.9022163,  -0.5673375,  2.9012036,
      -0.3468768,  -0.7017166, -0.70906216, 1.4808172,   -0.52651745,
      -0.7137295,  0.08764534, 0.044156794, 0.13787481,  0.27974486,
      0.58804995,  0.4954502,  0.5883212,   -0.66456574, -0.39530197,
      1.1908611,   0.21389124, -0.8622066,  -0.18057287, -0.50383306,
      -0.34767598, 0.38076988, -0.28297386, -0.94455045, 2.4593334,
      0.6078858,   -1.3282175, 0.9926832,   0.00901042,  0.64988273,
      -0.3737667,  2.131744,   -0.11746429, 0.5938905,   -0.2071204,
      1.2524531,   0.7307911,  -0.97322834, 0.014263037, 1.040024,
      0.5911448,   1.5903113,  -1.1054935,  -0.7744629,  -1.1329361};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.0,        0.81836003, 0.6717688,   0.2792652,   1.0,
      0.038950108, 1.0,        -1.0,        -0.9994479,  1.0,
      -0.16292474, 0.55694956, -0.9022163,  -0.5673375,  1.0,
      -0.3468768,  -0.7017166, -0.70906216, 1.0,         -0.52651745,
      -0.7137295,  0.08764534, 0.044156794, 0.13787481,  0.27974486,
      0.58804995,  0.4954502,  0.5883212,   -0.66456574, -0.39530197,
      1.0,         0.21389124, -0.8622066,  -0.18057287, -0.50383306,
      -0.34767598, 0.38076988, -0.28297386, -0.94455045, 1.0,
      0.6078858,   -1.0,       0.9926832,   0.00901042,  0.64988273,
      -0.3737667,  1.0,        -0.11746429, 0.5938905,   -0.2071204,
      1.0,         0.7307911,  -0.97322834, 0.014263037, 1.0,
      0.5911448,   1.0,        -1.0,        -0.7744629,  -1.0};
  const float max = 1.0;
  const float min = -1.0;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_inbounds) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_outbounds) {
  const float input_0[] = {-6.0, 0.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-5.0, 0.0, 5.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_splitbounds) {
  const float input_0[] = {-1.0, 0.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 5.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_default_min) {
  const float input_0[] = {
      -0.48840928,  -0.24249378, 2.6772094,   -0.7578987, 2.8744106,
      0.44515365,   0.71681225,  -0.9324065,  1.098823,   0.23939352,
      0.32894486,   0.9194968,   -1.1469102,  0.16528873, 1.5482329,
      -0.044772908, 0.5749013,   -1.6553117,  -0.9150704, -0.5904618,
      0.60078734,   1.4314536,   1.4719085,   -0.9949201, -0.35667887,
      0.64157385,   -0.38318822, 0.32676074,  0.13856418, -0.3348666,
      -1.3211603,   -0.81699216, -0.4737644,  -1.4399902, -0.70830846,
      0.19892102,   0.481347,    0.91866773,  -0.6875523, 0.17710955,
      0.15240164,   0.095453754, 1.0071925,   -0.3267339, -0.39726382,
      -1.1622847,   -0.6795435,  -0.45344847, -1.569639,  0.17313509,
      -0.4312965,   0.052317254, -0.5380142,  0.432076,   -0.40656188,
      0.0018329645, 1.5312364,   0.4121968,   0.73963165, -0.074801214};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.0,          0.0,         2.6772094,  0.0,        2.8744106,
      0.44515365,   0.71681225,  0.0,        1.098823,   0.23939352,
      0.32894486,   0.9194968,   0.0,        0.16528873, 1.5482329,
      0.0,          0.5749013,   0.0,        0.0,        0.0,
      0.60078734,   1.4314536,   1.4719085,  0.0,        0.0,
      0.64157385,   0.0,         0.32676074, 0.13856418, 0.0,
      0.0,          0.0,         0.0,        0.0,        0.0,
      0.19892102,   0.481347,    0.91866773, 0.0,        0.17710955,
      0.15240164,   0.095453754, 1.0071925,  0.0,        0.0,
      0.0,          0.0,         0.0,        0.0,        0.17313509,
      0.0,          0.052317254, 0.0,        0.432076,   0.0,
      0.0018329645, 1.5312364,   0.4121968,  0.73963165, 0.0};
  const float min = 0.0;
  const float max = 3.4028234663852886e+38;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_default_max) {
  const float input_0[] = {
      -2.1944678,  0.86131996,  -1.0660269,  -1.2455608,  -0.4373265,
      0.19005544,  0.6825165,   -0.24224643, -1.5026972,  -1.0868584,
      -0.57713556, -0.1436181,  2.35713,     0.24814418,  0.67784786,
      0.53181314,  -0.6177823,  2.273046,    1.4022415,   -0.61018044,
      0.5781129,   1.05802,     -1.5045617,  1.0166656,   0.9575512,
      0.18481645,  0.93744653,  0.19820996,  -1.5290668,  0.52473515,
      0.52539235,  -0.13437633, -0.139112,   0.22797008,  -0.9505306,
      -0.8633978,  -0.87727153, -0.54159766, -0.5641031,  -2.7367792,
      0.26768214,  -0.9006675,  -0.29998696, -0.9476934,  0.74258554,
      0.33072686,  0.39222828,  -0.32584044, 1.2887931,   1.5753629,
      0.37920433,  -0.1064586,  -0.8060885,  -0.44758394, 0.20758742,
      0.8371807,   0.23991793,  0.7452847,   0.04286811,  -0.33858952};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -2.1944678,  0.0,         -1.0660269,  -1.2455608,  -0.4373265,
      0.0,         0.0,         -0.24224643, -1.5026972,  -1.0868584,
      -0.57713556, -0.1436181,  0.0,         0.0,         0.0,
      0.0,         -0.6177823,  0.0,         0.0,         -0.61018044,
      0.0,         0.0,         -1.5045617,  0.0,         0.0,
      0.0,         0.0,         0.0,         -1.5290668,  0.0,
      0.0,         -0.13437633, -0.139112,   0.0,         -0.9505306,
      -0.8633978,  -0.87727153, -0.54159766, -0.5641031,  -2.7367792,
      0.0,         -0.9006675,  -0.29998696, -0.9476934,  0.0,
      0.0,         0.0,         -0.32584044, 0.0,         0.0,
      0.0,         -0.1064586,  -0.8060885,  -0.44758394, 0.0,
      0.0,         0.0,         0.0,         0.0,         -0.33858952};
  const float max = 0.0;
  const float min = -3.4028234663852886e+38;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_Clip, test_clip_default_inbounds) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float min = -3.4028234663852886e+38;
  const float max = 3.4028234663852886e+38;
  ONNC_RUNTIME_clip_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims, max, min);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}
