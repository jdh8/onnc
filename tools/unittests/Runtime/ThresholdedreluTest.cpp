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
SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu_example) {
  const float input_0[] = {-1.5, 0.0, 1.2, 2.0, 2.2};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {5};
  float output_0[5];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 2.2};
  const float alpha = 2.0;
  ONNC_RUNTIME_thresholdedrelu_float(nullptr, input_0, input_0_ndim,
                                     input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, alpha);
  ASSERT_TRUE(relative_error(output_0, answer_0, 5) < 1e-5f);
}

SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu) {
  const float input_0[] = {
      0.21423075,  0.57657355,  -1.8547573,  -0.8500002,  0.060944397,
      0.43557775,  -1.2167801,  -1.5766822,  1.2148885,   0.028928969,
      0.1918903,   0.9989549,   0.47813082,  -1.5469549,  -0.47584814,
      -1.9677067,  -1.8656365,  -2.249562,   2.136569,    0.8647131,
      1.384897,    -0.36452702, -0.47320056, -0.4766638,  1.6474631,
      -1.1601381,  0.058719125, -0.41217947, -0.57758427, 0.84789705,
      -1.3276623,  0.6632438,   0.31653306,  -1.6390399,  -0.40199798,
      -0.90098387, -0.595655,   0.2456188,   0.67684776,  0.96017057,
      0.4947312,   0.112789825, -1.1980505,  -0.7434318,  0.11577587,
      0.42383873,  -0.15296389, -1.170487,   -0.33135945, -0.786478,
      0.45893106,  0.09485839,  1.1061679,   -1.8740942,  0.35094595,
      -0.39261857, 0.36892596,  -2.7280962,  -1.8433111,  1.2063535};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,      0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.136569, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,      0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,      0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,      0.0, 0.0, 0.0, 0.0, 0.0};
  const float alpha = 2.0;
  ONNC_RUNTIME_thresholdedrelu_float(nullptr, input_0, input_0_ndim,
                                     input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, alpha);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu_default) {
  const float input_0[] = {
      2.3215153,    -1.423698,    -0.4330719, 0.6820417,   -1.1255771,
      -0.5938637,   -0.024779253, 1.7354594,  -1.1139344,  -0.67678076,
      1.5768787,    -2.227987,    1.6381338,  0.015416619, -0.5073756,
      1.1787288,    2.6767986,    0.34425083, 0.45481917,  -1.1567918,
      -2.0661614,   -1.8255149,   -1.2889614, 0.32418287,  0.22920783,
      -0.033721548, 0.72769356,   0.7453348,  -0.3157284,  -0.29635897,
      1.2158725,    -0.2789848,   -1.4484673, 0.5800386,   0.15674913,
      0.6397241,    0.02904278,   0.8224962,  1.1513681,   2.028758,
      -2.9727926,   0.00381509,   -0.9046218, -0.13992074, -0.5509295,
      -1.6972061,   0.10209715,   -1.0561042, 0.14662066,  -1.6664861,
      1.4962829,    1.7211843,    -0.3272475, 0.20301424,  1.2989386,
      0.25008965,   -0.23001327,  0.36008865, 1.3941981,   0.60605645};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      2.3215153, 0.0,       0.0,       0.0,       0.0,      0.0,       0.0,
      1.7354594, 0.0,       0.0,       1.5768787, 0.0,      1.6381338, 0.0,
      0.0,       1.1787288, 2.6767986, 0.0,       0.0,      0.0,       0.0,
      0.0,       0.0,       0.0,       0.0,       0.0,      0.0,       0.0,
      0.0,       0.0,       1.2158725, 0.0,       0.0,      0.0,       0.0,
      0.0,       0.0,       0.0,       1.1513681, 2.028758, 0.0,       0.0,
      0.0,       0.0,       0.0,       0.0,       0.0,      0.0,       0.0,
      0.0,       1.4962829, 1.7211843, 0.0,       0.0,      1.2989386, 0.0,
      0.0,       0.0,       1.3941981, 0.0};
  const float alpha = 1;
  ONNC_RUNTIME_thresholdedrelu_float(nullptr, input_0, input_0_ndim,
                                     input_0_dims, output_0, output_0_ndim,
                                     output_0_dims, alpha);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
