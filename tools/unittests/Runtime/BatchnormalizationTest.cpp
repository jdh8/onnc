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
SKYPAT_F(Operator_BatchNormalization, test_batchnorm_example)
{
  const float    input_0[]      = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
  const int32_t  input_0_ndim   = 4;
  const int32_t  input_0_dims[] = {1, 2, 1, 3};
  const float    input_1[]      = {1.0, 1.5};
  const int32_t  input_1_ndim   = 1;
  const int32_t  input_1_dims[] = {2};
  const float    input_2[]      = {0.0, 1.0};
  const int32_t  input_2_ndim   = 1;
  const int32_t  input_2_dims[] = {2};
  const float    input_3[]      = {0.0, 3.0};
  const int32_t  input_3_ndim   = 1;
  const int32_t  input_3_dims[] = {2};
  const float    input_4[]      = {1.0, 1.5};
  const int32_t  input_4_ndim   = 1;
  const int32_t  input_4_dims[] = {2};
  float          output_0[6];
  const int32_t  output_0_ndim   = 4;
  const int32_t  output_0_dims[] = {1, 2, 1, 3};
  const float    answer_0[]      = {-0.999995, 0.0, 0.999995, -0.22474074, 1.0, 2.2247407};
  float*         output_1        = nullptr;
  const int32_t  output_1_ndim   = 0;
  const int32_t* output_1_dims   = nullptr;
  float*         output_2        = nullptr;
  const int32_t  output_2_ndim   = 0;
  const int32_t* output_2_dims   = nullptr;
  float*         output_3        = nullptr;
  const int32_t  output_3_ndim   = 0;
  const int32_t* output_3_dims   = nullptr;
  float*         output_4        = nullptr;
  const int32_t  output_4_ndim   = 0;
  const int32_t* output_4_dims   = nullptr;
  const float    epsilon         = 1e-05;
  const float    momentum        = 0.9;
  const int32_t  spatial         = 1;
  using dragonite::norm;

  ONNC_RUNTIME_batchnormalization_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim, input_4_dims, output_0, output_0_ndim,
    output_0_dims, output_1, output_1_ndim, output_1_dims, output_2, output_2_ndim, output_2_dims, output_3,
    output_3_ndim, output_3_dims, output_4, output_4_ndim, output_4_dims, epsilon, momentum, spatial);
  ASSERT_TRUE(norm(answer_0, output_0, 6) <= 1e-5 * norm(answer_0, 6));
}

SKYPAT_F(Operator_BatchNormalization, test_batchnorm_epsilon)
{
  const float input_0[] = {
    0.65620834, 1.1411203,    0.010076148, -0.50424665, -0.95988095, -0.95881975, -0.6481596,   0.035637554,
    -1.239267,  -0.042601205, 0.1620334,   -0.3764456,  0.104785845, -1.097872,   -0.520775,    -0.16654812,
    0.48378062, 0.90198106,   0.22277218,  -0.83895034, 0.390395,    0.36502534,  -1.3266584,   1.0647157,
    1.0079043,  -0.512285,    -0.45282748, -1.8698128,  0.5142484,   2.078907,    -0.674263,    0.60865664,
    0.74124825, -1.3744068,   0.12625037,  -1.0333214,  0.2149422,   -0.6577934,  -0.05807105,  -0.42117906,
    -0.0338565, -0.09873536,  -0.7983658,  1.1110172,   0.39646375,  0.03426088,  -0.09769724,  -0.342233,
    -0.9602888, 0.99146223,   2.0064921,   0.29574415,  -0.76043457, -0.4042297,  -0.06852524,  0.68717474,
    -1.1067652, -0.98911595,  -0.68288946, 1.5203367,   0.2597866,   0.46546116,  1.0775363,    -1.7710617,
    0.5273842,  -0.64377934,  -1.0309443,  -0.04627042, 1.2220223,   1.8254582,   0.6970838,    0.18010223,
    0.86429316, -0.6759581,   -0.28620937, 2.2211983,   -1.5303863,  0.5095826,   0.36236072,   -0.21973048,
    -1.9044023, -0.31821373,  0.14674422,  0.40328747,  0.27690938,  0.6149634,   -0.28066385,  0.15736076,
    0.95422995, 0.3562017,    -0.14166182, 1.1540555,   -0.5426445,  -0.43441945, 0.3180415,    -0.12374818,
    0.6455082,  -0.6225479,   1.6928207,   -0.31327966, 1.4896542,   0.3247015,   -0.40795425,  -1.7075901,
    0.3071711,  0.9764524,    -1.3549703,  -1.2327824,  0.48862258,  0.2171851,   -0.009159809, 0.2808932,
    -0.9786979, 0.039742116,  -1.5715463,  0.6851614,   -0.858896,   0.5118897,   0.26921532,   -1.0463852};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  const float   input_1[]      = {-0.5163771, -0.2963413, -0.5971344};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {3};
  const float   input_2[]      = {-0.61668396, -1.0835097, -0.72815424};
  const int32_t input_2_ndim   = 1;
  const int32_t input_2_dims[] = {3};
  const float   input_3[]      = {0.48791668, 1.4138474, 0.48301846};
  const int32_t input_3_ndim   = 1;
  const int32_t input_3_dims[] = {3};
  const float   input_4[]      = {0.8149835, 0.5363311, 0.2035179};
  const int32_t input_4_ndim   = 1;
  const int32_t input_4_dims[] = {3};
  float         output_0[120];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {2, 3, 4, 5};
  const float   answer_0[]      = {
    -0.7123608,   -0.98804206, -0.34502295, -0.052621126, 0.2064153,   0.20581198,  0.029196084,  -0.3595551,
    0.3652513,    -0.31507492, -0.4314134,  -0.12527832,  -0.39886713, 0.28486568,  -0.043224454, -0.24460885,
    -0.61433256,  -0.8520871,  -0.4659445,  0.13766402,   -0.67318094, -0.66300964, 0.015230298,  -0.9435337,
    -0.9207565,   -0.31127304, -0.33511114, 0.23299515,   -0.72283703, -1.3501494,  -0.24633187,  -0.7606877,
    -0.8138472,   0.034374,    -0.5672785,  -0.102376044, -0.6028374,  -0.25293493, -0.4933793,   -0.34779984,
    -0.060209632, 0.023631752, 0.9277466,   -1.5397013,   -0.6163018,  -0.14823604, 0.02229017,   0.33829767,
    1.1369956,    -1.3852035,  -2.6969013,  -0.48614433,  0.87872905,  0.4184144,   -0.015408039, -0.9919803,
    1.3262835,    1.1742482,   0.77851933,  -2.0686545,   -0.4869879,  -0.6039176,  -0.95189345,  0.6675863,
    -0.63912195,  0.026705742, 0.2468161,   -0.3129889,   -1.0340363,  -1.3771006,  -0.7355992,   -0.44168586,
    -0.8306608,   0.044999957, -0.17657924, -1.6020861,   0.5307578,   -0.62900144, -0.5453031,   -0.21437371,
    0.24686289,   -0.38908136, -0.57549506, -0.6783499,   -0.6276816,  -0.76321626, -0.404136,    -0.57975155,
    -0.8992371,   -0.659472,   -0.4598655,  -0.97935236,  -0.29910123, -0.34249145, -0.6441726,   -0.46704757,
    -0.7754625,   -0.26706582, -1.1953573,  -0.39105952,  -2.0290043,  -0.5235652,  0.4232275,    2.1027145,
    -0.5009111,   -1.3658066,  1.647033,    1.4891324,    -0.7353963,  -0.38462442, -0.09212452,  -0.46695283,
    1.1607854,    -0.15531927, 1.9269087,   -0.9893786,   1.0059683,   -0.7654638,  -0.45186177,  1.248256};
  float*         output_1      = nullptr;
  const int32_t  output_1_ndim = 0;
  const int32_t* output_1_dims = nullptr;
  float*         output_2      = nullptr;
  const int32_t  output_2_ndim = 0;
  const int32_t* output_2_dims = nullptr;
  float*         output_3      = nullptr;
  const int32_t  output_3_ndim = 0;
  const int32_t* output_3_dims = nullptr;
  float*         output_4      = nullptr;
  const int32_t  output_4_ndim = 0;
  const int32_t* output_4_dims = nullptr;
  const float    epsilon       = 0.009999999776482582;
  const float    momentum      = 0.9;
  const int32_t  spatial       = 1;
  using dragonite::norm;

  ONNC_RUNTIME_batchnormalization_float(
    nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2, input_2_ndim,
    input_2_dims, input_3, input_3_ndim, input_3_dims, input_4, input_4_ndim, input_4_dims, output_0, output_0_ndim,
    output_0_dims, output_1, output_1_ndim, output_1_dims, output_2, output_2_ndim, output_2_dims, output_3,
    output_3_ndim, output_3_dims, output_4, output_4_ndim, output_4_dims, epsilon, momentum, spatial);
  ASSERT_TRUE(norm(answer_0, output_0, 120) <= 1e-5 * norm(answer_0, 120));
}
