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
SKYPAT_F(Operator_Sigmoid, test_sigmoid_example) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {0.26894143, 0.5, 0.7310586};
  ONNC_RUNTIME_sigmoid_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Sigmoid, test_sigmoid) {
  const float input_0[] = {
      -0.7196044,  -0.812993,   0.27451634, -0.8909151,  -1.1573553,
      -0.31229225, -0.15766701, 2.2567234,  -0.7047003,  0.9432607,
      0.7471883,   -1.1889449,  0.77325296, -1.1838807,  -2.6591723,
      0.60631955,  -1.7558906,  0.45093447, -0.6840109,  1.6595508,
      1.0685093,   -0.4533858,  -0.6878376, -1.2140774,  -0.44092262,
      -0.28035548, -0.36469355, 0.15670386, 0.5785215,   0.34965447,
      -0.76414394, -1.4377915,  1.3645319,  -0.6894492,  -0.6522936,
      -0.52118933, -1.8430696,  -0.477974,  -0.4796558,  0.6203583,
      0.6984571,   0.003770889, 0.93184835, 0.339965,    -0.015682112,
      0.16092817,  -0.19065349, -0.3948495, -0.26773354, -1.1280113,
      0.2804417,   -0.9931236,  0.8416313,  -0.24945858, 0.04949498,
      0.4938368,   0.6433145,   -1.5706234, -0.20690368, 0.8801789};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.3274801,  0.30725306, 0.5682013,   0.290921,   0.23914817, 0.42255533,
      0.4606647,  0.9052289,  0.33077094,  0.71975785, 0.67856574, 0.23344767,
      0.6842241,  0.23435517, 0.065425925, 0.64710075, 0.14730576, 0.6108614,
      0.3353667,  0.8401777,  0.74431336,  0.38855603, 0.3345143,  0.22898042,
      0.39152113, 0.4303666,  0.4098239,   0.539096,   0.6407271,  0.5865338,
      0.31774724, 0.19188757, 0.7964952,   0.33415562, 0.34247285, 0.37257418,
      0.13668866, 0.38273066, 0.38233343,  0.6503001,  0.6678456,  0.5009427,
      0.71745014, 0.58418196, 0.49607956,  0.54014546, 0.45248047, 0.40255043,
      0.4334636,  0.24452831, 0.5696545,   0.27029556, 0.69880867, 0.43795675,
      0.5123712,  0.6210099,  0.6555023,   0.17212754, 0.4484578,  0.7068593};
  ONNC_RUNTIME_sigmoid_float(nullptr, input_0, input_0_ndim, input_0_dims,
                             output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
