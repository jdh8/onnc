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
SKYPAT_F(Operator_Sin, test_sin_example)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-0.84147096, 0.0, 0.84147096};
  using dragonite::norm;

  ONNC_RUNTIME_sin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Sin, test_sin)
{
  const float input_0[] = {
    -1.6981058,  0.38728046,  -2.2555642, -1.0225068,  0.038630553, -1.6567152,  -0.98551077, -1.471835,  1.648135,
    0.16422775,  0.5672903,   -0.2226751, -0.35343176, -1.6164742,  -0.29183736, -0.7614922,  0.8579239,  1.1411018,
    1.4665787,   0.85255194,  -0.5986539, -1.1158969,  0.7666632,   0.3562928,   -1.7685385,  0.3554818,  0.8145198,
    0.058925588, -0.18505368, -0.8076485, -1.4465348,  0.800298,    -0.30911446, -0.23346666, 1.7327212,  0.6845011,
    0.370825,    0.1420618,   1.5199949,  1.7195894,   0.9295051,   0.5822246,   -2.094603,   0.12372191, -0.13010696,
    0.09395323,  0.9430461,   -2.7396772, -0.56931204, 0.26990435,  -0.46684554, -1.4169061,  0.8689635,  0.27687192,
    -0.97110456, 0.3148172,   0.8215857,  0.005292646, 0.8005648,   0.078260176};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    -0.99190706, 0.3776717,  -0.7745659,  -0.85341734,  0.038620945, -0.99631125, -0.8335544,  -0.99510735, 0.9970109,
    0.16349052,  0.53734875, -0.22083946, -0.3461195,   -0.998957,   -0.2877124,  -0.69000226, 0.7564864,   0.9090931,
    0.99457425,  0.7529622,  -0.563531,   -0.89830524,  0.69373584,  0.34880227,  -0.9805126,  0.3480421,   0.7273962,
    0.058891494, -0.1839993, -0.7226638,  -0.9922895,   0.7175637,   -0.3042152,  -0.23135151, 0.9869188,   0.6322866,
    0.36238447,  0.14158444, 0.99870986,  0.9889507,    0.801324,    0.54988337,  -0.8659214,  0.123406515, -0.1297402,
    0.093815066, 0.8093509,  -0.3911819,  -0.5390527,   0.26663923,  -0.45007163, -0.98818225, 0.76366013,  0.27334803,
    -0.8255096,  0.30964264, 0.7322267,   0.0052926214, 0.7177495,   0.07818031};
  using dragonite::norm;

  ONNC_RUNTIME_sin_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
