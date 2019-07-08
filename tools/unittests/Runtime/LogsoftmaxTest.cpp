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
SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_example_1) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {1, 3};
  float output_0[3];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 3};
  const float answer_0[] = {-2.407606, -1.4076059, -0.4076059};
  const int32_t axis = 1;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_large_number) {
  const float input_0[] = {0.0,     1.0,     2.0,     3.0,
                           10000.0, 10001.0, 10002.0, 10003.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 4};
  float output_0[8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[] = {-3.4401896, -2.4401896, -1.4401897, -0.4401897,
                            -3.4401896, -2.4401896, -1.4401897, -0.4401897};
  const int32_t axis = 1;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 8) < 1e-5f);
}

SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_axis_0) {
  const float input_0[] = {
      1.0372663,  0.02160892, 1.1700815,  0.39337638, 1.3652107,  0.9864765,
      1.120635,   1.1605799,  0.6034555,  1.037547,   0.86782396, 0.74858665,
      1.0034207,  0.3286037,  0.3149428,  0.382287,   0.44025028, 0.21267797,
      0.6103402,  0.37571853, 0.33354867, 1.2585534,  0.08349494, 0.70831877,
      1.4359695,  1.5807045,  0.6798585,  1.2789601,  1.2590562,  1.3137203,
      1.8956214,  1.197613,   0.19855975, 1.9032404,  0.6394003,  0.94808567,
      0.87129956, 0.76591355, 0.69300765, 0.9375275,  1.0523623,  1.9021956,
      0.22006299, 0.49186644, 0.36595732, 1.2934281,  0.8424463,  2.3614812,
      2.1568866,  0.61293334, 0.8028648,  2.5344162,  1.5449874,  0.17388576,
      0.38094696, 0.60950565, 1.4419667,  0.7988912,  0.48248342, 0.31094524};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -4.152201,  -5.1678586, -4.019386,  -4.796091,  -3.824257,  -4.202991,
      -4.0688324, -4.0288877, -4.586012,  -4.1519203, -4.3216434, -4.440881,
      -4.1860466, -4.8608637, -4.8745246, -4.8071804, -4.749217,  -4.9767895,
      -4.5791273, -4.813749,  -4.855919,  -3.930914,  -5.1059723, -4.4811487,
      -3.753498,  -3.608763,  -4.509609,  -3.9105072, -3.9304113, -3.8757472,
      -3.2938461, -3.9918544, -4.9909077, -3.286227,  -4.550067,  -4.2413816,
      -4.3181677, -4.423554,  -4.49646,   -4.25194,   -4.137105,  -3.287272,
      -4.969404,  -4.6976013, -4.82351,   -3.8960395, -4.347021,  -2.8279862,
      -3.0325809, -4.5765343, -4.3866024, -2.6550512, -3.64448,   -5.0155816,
      -4.8085203, -4.579962,  -3.747501,  -4.3905764, -4.706984,  -4.878522};
  const int32_t axis = 0;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_axis_1) {
  const float input_0[] = {
      1.0372663,  0.02160892, 1.1700815,  0.39337638, 1.3652107,  0.9864765,
      1.120635,   1.1605799,  0.6034555,  1.037547,   0.86782396, 0.74858665,
      1.0034207,  0.3286037,  0.3149428,  0.382287,   0.44025028, 0.21267797,
      0.6103402,  0.37571853, 0.33354867, 1.2585534,  0.08349494, 0.70831877,
      1.4359695,  1.5807045,  0.6798585,  1.2789601,  1.2590562,  1.3137203,
      1.8956214,  1.197613,   0.19855975, 1.9032404,  0.6394003,  0.94808567,
      0.87129956, 0.76591355, 0.69300765, 0.9375275,  1.0523623,  1.9021956,
      0.22006299, 0.49186644, 0.36595732, 1.2934281,  0.8424463,  2.3614812,
      2.1568866,  0.61293334, 0.8028648,  2.5344162,  1.5449874,  0.17388576,
      0.38094696, 0.60950565, 1.4419667,  0.7988912,  0.48248342, 0.31094524};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -2.7375736, -3.753231,  -2.6047585, -3.3814635, -2.4096293, -2.7883635,
      -2.6542048, -2.6142602, -3.1713846, -2.737293,  -2.907016,  -3.0262532,
      -2.7714193, -3.4462361, -3.459897,  -3.3925529, -3.3345897, -3.562162,
      -3.1644998, -3.3991215, -3.7833915, -2.8583865, -4.0334454, -3.4086213,
      -2.6809707, -2.5362356, -3.4370816, -2.8379798, -2.857884,  -2.8032198,
      -2.2213187, -2.919327,  -3.9183803, -2.2136996, -3.4775398, -3.1688542,
      -3.2456405, -3.3510265, -3.4239323, -3.1794126, -3.2572453, -2.407412,
      -4.089545,  -3.8177414, -3.9436502, -3.0161796, -3.4671612, -1.9481264,
      -2.152721,  -3.6966743, -3.506743,  -1.7751914, -2.7646203, -4.1357217,
      -3.9286609, -3.7001019, -2.867641,  -3.5107164, -3.827124,  -3.9986625};
  const int32_t axis = 1;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_default_axis) {
  const float input_0[] = {
      1.0372663,  0.02160892, 1.1700815,  0.39337638, 1.3652107,  0.9864765,
      1.120635,   1.1605799,  0.6034555,  1.037547,   0.86782396, 0.74858665,
      1.0034207,  0.3286037,  0.3149428,  0.382287,   0.44025028, 0.21267797,
      0.6103402,  0.37571853, 0.33354867, 1.2585534,  0.08349494, 0.70831877,
      1.4359695,  1.5807045,  0.6798585,  1.2789601,  1.2590562,  1.3137203,
      1.8956214,  1.197613,   0.19855975, 1.9032404,  0.6394003,  0.94808567,
      0.87129956, 0.76591355, 0.69300765, 0.9375275,  1.0523623,  1.9021956,
      0.22006299, 0.49186644, 0.36595732, 1.2934281,  0.8424463,  2.3614812,
      2.1568866,  0.61293334, 0.8028648,  2.5344162,  1.5449874,  0.17388576,
      0.38094696, 0.60950565, 1.4419667,  0.7988912,  0.48248342, 0.31094524};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -2.7375736, -3.753231,  -2.6047585, -3.3814635, -2.4096293, -2.7883635,
      -2.6542048, -2.6142602, -3.1713846, -2.737293,  -2.907016,  -3.0262532,
      -2.7714193, -3.4462361, -3.459897,  -3.3925529, -3.3345897, -3.562162,
      -3.1644998, -3.3991215, -3.7833915, -2.8583865, -4.0334454, -3.4086213,
      -2.6809707, -2.5362356, -3.4370816, -2.8379798, -2.857884,  -2.8032198,
      -2.2213187, -2.919327,  -3.9183803, -2.2136996, -3.4775398, -3.1688542,
      -3.2456405, -3.3510265, -3.4239323, -3.1794126, -3.2572453, -2.407412,
      -4.089545,  -3.8177414, -3.9436502, -3.0161796, -3.4671612, -1.9481264,
      -2.152721,  -3.6966743, -3.506743,  -1.7751914, -2.7646203, -4.1357217,
      -3.9286609, -3.7001019, -2.867641,  -3.5107164, -3.827124,  -3.9986625};
  const int32_t axis = 1;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}

SKYPAT_F(Operator_LogSoftmax, test_logsoftmax_axis_2) {
  const float input_0[] = {
      1.0372663,  0.02160892, 1.1700815,  0.39337638, 1.3652107,  0.9864765,
      1.120635,   1.1605799,  0.6034555,  1.037547,   0.86782396, 0.74858665,
      1.0034207,  0.3286037,  0.3149428,  0.382287,   0.44025028, 0.21267797,
      0.6103402,  0.37571853, 0.33354867, 1.2585534,  0.08349494, 0.70831877,
      1.4359695,  1.5807045,  0.6798585,  1.2789601,  1.2590562,  1.3137203,
      1.8956214,  1.197613,   0.19855975, 1.9032404,  0.6394003,  0.94808567,
      0.87129956, 0.76591355, 0.69300765, 0.9375275,  1.0523623,  1.9021956,
      0.22006299, 0.49186644, 0.36595732, 1.2934281,  0.8424463,  2.3614812,
      2.1568866,  0.61293334, 0.8028648,  2.5344162,  1.5449874,  0.17388576,
      0.38094696, 0.60950565, 1.4419667,  0.7988912,  0.48248342, 0.31094524};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.4855876, -2.501245,  -1.3527724, -2.1294775, -1.1576432, -1.622936,
      -1.4887775, -1.4488326, -2.0059571, -1.5718656, -1.4330133, -1.5522506,
      -1.2974166, -1.9722335, -1.9858944, -1.6396327, -1.5816693, -1.8092418,
      -1.4115795, -1.6462011, -2.1709654, -1.2459607, -2.421019,  -1.7961953,
      -1.0685446, -1.2909918, -2.1918378, -1.5927361, -1.61264,   -1.5579759,
      -1.0896294, -1.7876378, -2.7866912, -1.0820104, -2.3458505, -1.5093743,
      -1.5861604, -1.6915464, -1.7644522, -1.5199325, -1.5786927, -0.72885936,
      -2.410992,  -2.1391885, -2.2650976, -2.0047755, -2.4557571, -0.9367223,
      -1.1413169, -2.68527,   -2.2964387, -0.5648873, -1.554316,  -2.9254177,
      -2.7183566, -1.8132071, -0.9807462, -1.6238217, -1.9402294, -2.1117675};
  const int32_t axis = 2;
  ONNC_RUNTIME_logsoftmax_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
