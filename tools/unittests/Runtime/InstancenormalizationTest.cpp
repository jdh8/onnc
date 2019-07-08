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
SKYPAT_F(Operator_InstanceNormalization, test_instancenorm_example) {
  const float input_0[] = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 2, 1, 3};
  const float input_1[] = {1.0, 1.5};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  const float input_2[] = {0.0, 1.0};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {2};
  float output_0[6];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 2, 1, 3};
  const float answer_0[] = {-1.2247356, 0.0, 1.2247356,
                            -0.8371035, 1.0, 2.8371034};
  const float epsilon = 1e-05;
  ONNC_RUNTIME_instancenormalization_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, output_0,
      output_0_ndim, output_0_dims, epsilon);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_InstanceNormalization, test_instancenorm_epsilon) {
  const float input_0[] = {
      1.0510308,   1.2297375,    1.6725864,   -0.64482,    0.042433765,
      1.2632117,   -0.3152549,   0.0444087,   0.3915154,   2.2682996,
      0.16562653,  -0.026165247, 0.7597847,   1.0356836,   0.41195557,
      -0.5353858,  1.502626,     0.10690676,  0.025658287, -0.99528813,
      -0.13127723, 1.3085359,    0.4677552,   0.24429333,  0.4861019,
      -0.75760937, -0.3155761,   -2.0553787,  -0.34209502, -0.1430969,
      0.5726065,   1.0832129,    -0.14145772, 0.32906994,  0.76495105,
      -0.3600762,  0.24623917,   0.7150433,   -0.78509957, 1.5152411,
      -0.42648193, 0.6929977,    0.27049416,  -2.1944146,  -1.7767987,
      -0.9393034,  -0.325785,    -0.22566307, 0.8073435,   -0.93059176,
      0.25845125,  -0.13468139,  0.06774277,  0.44450274,  0.10771031,
      0.25314596,  0.6693777,    -1.2773093,  0.48651034,  1.3931651,
      -0.1275577,  -1.3190933,   0.20822945,  1.3829441,   -0.8227755,
      0.46395758,  -0.49344355,  -1.0246917,  -2.488373,   1.8095195,
      0.23781648,  -0.6035608,   -0.39796546, 1.2794304,   -1.1091526,
      0.9851416,   -0.54001486,  0.44312698,  -0.9731915,  -0.11452087,
      0.7032017,   -0.17807665,  -0.25608745, 0.76411164,  1.0240593,
      1.1507744,   -0.14187637,  -0.9080463,  -2.0915425,  -1.154717,
      -0.42767358, 0.5327739,    0.8687991,   0.6559156,   0.1315044,
      0.9485843,   -0.077130094, 0.033996582, 2.3819256,   2.160515,
      1.3426266,   1.2679306,    0.057944793, -0.30517957, 0.95233214,
      0.085474,    -1.982348,    0.68581593,  2.3186634,   0.18885791,
      0.51167554,  0.26244962,   0.5005166,   -0.50186574, 0.48549107,
      0.7989358,   -0.21876524,  0.5762244,   0.9815551,   0.0933528};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  const float input_1[] = {1.0828874, 0.110543445, 1.3826895};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  const float input_2[] = {0.6056767, 0.37274417, 0.22193934};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {3};
  float output_0[120];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {2, 3, 4, 5};
  const float answer_0[] = {
      1.35543,    1.5871181,    2.161259,    -0.8431912,  0.047813237,
      1.6305165,  -0.41591972,  0.050373673, 0.50038743,  2.9335837,
      0.20752907, -0.04112339,  0.9778379,   1.3355329,   0.52688754,
      -0.7013131, 1.9409101,    0.13140059,  0.026064277, -1.2975631,
      0.33614537, 0.53399086,   0.41845873,  0.3877527,   0.42097977,
      0.25008076, 0.31082076,   0.07175362,  0.3071768,   0.33452123,
      0.4328664,  0.5030291,    0.33474648,  0.3994019,   0.45929655,
      0.30470598, 0.3880201,    0.4524387,   0.2463033,   0.5623943,
      -0.2267553, 1.5203755,    0.8609897,   -2.985903,   -2.3341453,
      -1.027097,  -0.06960134,  0.086655304, 1.6988307,   -1.013501,
      0.8421948,  0.22864707,   0.54456306,  1.1325586,   0.60693896,
      0.83391505, 1.4835125,    -1.5546104,  1.1981182,   2.6131012,
      0.6402512,  -0.6214786,   0.9958198,   2.2397377,   -0.09592235,
      1.266613,   0.25281078,   -0.3097335,  -1.8596413,  2.691443,
      1.0271499,  0.13620642,   0.35391358,  2.1301258,   -0.39916998,
      1.8185005,  0.20349592,   1.2445552,   -0.25519943, 0.6540561,
      0.41524065, 0.32094097,   0.31259358,  0.4217582,   0.44957346,
      0.46313238, 0.32481453,   0.24283186,  0.11619392,  0.2164373,
      0.2942333,  0.3970043,    0.4329601,   0.41018087,  0.35406715,
      0.4414974,  0.33174258,   0.3436335,   0.59486955,  0.5711779,
      1.7598468,  1.6373185,    -0.34749478, -0.9431498,  1.1196232,
      -0.302337,  -3.6943111,   0.6824404,   3.3608992,   -0.13275005,
      0.3967873,  -0.012033105, 0.37848264,  -1.265786,   0.35383534,
      0.8679977,  -0.8013991,   0.5026707,   1.1675594,   -0.28941292};
  const float epsilon = 0.009999999776482582;
  ONNC_RUNTIME_instancenormalization_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, output_0,
      output_0_ndim, output_0_dims, epsilon);
  ASSERT_TRUE(relative_error(output_0, answer_0, 120) < 1e-5f);
}
