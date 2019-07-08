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
SKYPAT_F(Operator_BatchNormalization, test_batchnorm_example) {
  const float input_0[] = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 2, 1, 3};
  const float input_1[] = {1.0, 1.5};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  const float input_2[] = {0.0, 1.0};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {2};
  const float input_3[] = {0.0, 3.0};
  const int32_t input_3_ndim = 1;
  const int32_t input_3_dims[] = {2};
  const float input_4[] = {1.0, 1.5};
  const int32_t input_4_ndim = 1;
  const int32_t input_4_dims[] = {2};
  float output_0[6];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 2, 1, 3};
  const float answer_0[] = {-0.999995,   0.0, 0.999995,
                            -0.22474074, 1.0, 2.2247407};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  float *output_2 = nullptr;
  const int32_t output_2_ndim = 0;
  const int32_t *output_2_dims = nullptr;
  float *output_3 = nullptr;
  const int32_t output_3_ndim = 0;
  const int32_t *output_3_dims = nullptr;
  float *output_4 = nullptr;
  const int32_t output_4_ndim = 0;
  const int32_t *output_4_dims = nullptr;
  const float momentum = 0.9;
  const float epsilon = 1e-05;
  const int32_t spatial = 1;
  ONNC_RUNTIME_batchnormalization_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, output_0,
      output_0_ndim, output_0_dims, output_1, output_1_ndim, output_1_dims,
      output_2, output_2_ndim, output_2_dims, output_3, output_3_ndim,
      output_3_dims, output_4, output_4_ndim, output_4_dims, epsilon, momentum,
      spatial);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}

SKYPAT_F(Operator_BatchNormalization, test_batchnorm_epsilon) {
  const float input_0[] = {
      0.12720749,   0.24011827,   0.41554886,   1.1089969,   0.37565812,
      0.35067886,   1.6400052,    -0.020686155, 0.113805585, 0.6595625,
      -0.4697461,   -0.21400325,  -1.2813069,   -0.27434728, 0.31804737,
      -0.49228933,  -1.5201946,   -0.56937575,  1.0642467,   -1.0146477,
      0.48463553,   0.717592,     0.37175968,   -0.21955496, -0.9694688,
      -1.3218777,   -0.069124706, 0.43547347,   1.3544043,   -0.6818406,
      0.6706589,    -0.25754258,  0.7888503,    0.6066892,   -0.12892482,
      -1.515976,    -2.1773229,   -0.68057746,  0.064037345, -1.0445164,
      -0.51915276,  -2.3026764,   -0.2065071,   1.053149,    0.94363886,
      1.3124249,    -0.45423606,  -0.8652938,   -0.5129792,  0.72240144,
      0.9247332,    -0.902032,    1.472125,     0.38777274,  0.50526184,
      1.235763,     0.3783654,    -0.859544,    0.91754115,  1.7952868,
      -0.3122873,   1.2230458,    0.63667345,   -0.99439085, 0.97975254,
      -2.574016,    0.13151146,   0.16448632,   -0.9646202,  0.595002,
      0.34924948,   -2.0126672,   0.05899725,   1.3334204,   0.07755805,
      0.06199347,   -1.3674537,   -0.41596422,  0.6219352,   -0.8253829,
      -0.066026255, -0.711218,    -0.64055145,  -0.48707798, 0.9184056,
      3.0148377,    -0.35512352,  -0.19357726,  -0.26136437, -1.3107945,
      0.9858395,    1.7711403,    0.029979357,  0.7948592,   -0.9444986,
      0.3704488,    0.17649686,   -1.6922626,   0.8019865,   2.2666566,
      -0.2687776,   1.5937047,    -0.31786177,  -2.0791116,  0.062043175,
      -0.023485726, -0.7747892,   -0.07478719,  1.3114692,   1.4714106,
      -0.35753003,  0.04850378,   0.15614873,   0.19668114,  -0.0110038,
      -2.8637824,   1.2981112,    0.8541351,    0.48897058,  -0.58150893};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  const float input_1[] = {2.5602775, -1.5908637, 0.024780162};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  const float input_2[] = {0.76993835, -1.8030912, -0.16378976};
  const int32_t input_2_ndim = 1;
  const int32_t input_2_dims[] = {3};
  const float input_3[] = {-0.13326642, 0.7655654, 1.2776277};
  const int32_t input_3_ndim = 1;
  const int32_t input_3_dims[] = {3};
  const float input_4[] = {0.5060962, 0.10985571, 0.25181925};
  const int32_t input_4_ndim = 1;
  const int32_t input_4_dims[] = {3};
  float output_0[120];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {2, 3, 4, 5};
  const float answer_0[] = {
      1.6982332,   2.1006324,   2.725844,    5.1972017,   2.5836787,
      2.4946558,   7.0896463,   1.1711596,   1.6504705,   3.5954766,
      -0.42923117, 0.4822029,   -3.321527,   0.26714468,  2.3783615,
      -0.50957227, -4.1728916,  -0.7842982,  5.0377183,   -2.371189,
      -0.5121647,  -1.5826442,  0.006521344, 2.7237253,   6.169723,
      7.789109,    2.0324693,   -0.28625548, -4.508919,   4.8480167,
      -1.3669776,  2.8982859,   -1.9100897,  -1.0730247,  2.307263,
      8.681028,    11.720044,   4.842212,    1.4205648,   6.5145817,
      -0.25080562, -0.33717945, -0.23566458, -0.174661,   -0.17996442,
      -0.16210458, -0.24766177, -0.2675688,  -0.25050664, -0.19067869,
      -0.18088001, -0.269348,   -0.1543705,  -0.20688434, -0.2011945,
      -0.16581722, -0.20733993, -0.26729035, -0.18122831, -0.13872017,
      0.13193142,  5.6036577,   3.5139031,   -2.298996,   4.7365923,
      -7.9285736,  1.713572,    1.8310901,   -2.1928978,  3.3653913,
      2.4895616,   -5.927999,   1.4551408,   5.997018,    1.5212891,
      1.4658189,   -3.628543,   -0.23755956, 3.4613776,   -1.6966742,
      2.0182319,   4.9830117,   4.6582847,   3.953045,    -2.5054212,
      -12.138927,  3.3466892,   2.6043534,   2.9158478,   7.738179,
      -2.8152928,  -6.4239,     1.5770675,   -1.9377017,  6.05498,
      0.012545228, 0.90379155,  9.491099,    -1.9704531,  -8.700892,
      -0.23868026, -0.14848255, -0.24105734, -0.32635248, -0.22265902,
      -0.22680107, -0.26318577, -0.22928554, -0.16215086, -0.1544051,
      -0.24297842, -0.22331472, -0.2181016,  -0.21613866, -0.22619659,
      -0.36435312, -0.16279778, -0.18429899, -0.20198345, -0.25382543};
  float *output_1 = nullptr;
  const int32_t output_1_ndim = 0;
  const int32_t *output_1_dims = nullptr;
  float *output_2 = nullptr;
  const int32_t output_2_ndim = 0;
  const int32_t *output_2_dims = nullptr;
  float *output_3 = nullptr;
  const int32_t output_3_ndim = 0;
  const int32_t *output_3_dims = nullptr;
  float *output_4 = nullptr;
  const int32_t output_4_ndim = 0;
  const int32_t *output_4_dims = nullptr;
  const float epsilon = 0.009999999776482582;
  const float momentum = 0.9;
  const int32_t spatial = 1;
  ONNC_RUNTIME_batchnormalization_float(
      nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim,
      input_1_dims, input_2, input_2_ndim, input_2_dims, input_3, input_3_ndim,
      input_3_dims, input_4, input_4_ndim, input_4_dims, output_0,
      output_0_ndim, output_0_dims, output_1, output_1_ndim, output_1_dims,
      output_2, output_2_ndim, output_2_dims, output_3, output_3_ndim,
      output_3_dims, output_4, output_4_ndim, output_4_dims, epsilon, momentum,
      spatial);
  ASSERT_TRUE(relative_error(output_0, answer_0, 120) < 1e-5f);
}
