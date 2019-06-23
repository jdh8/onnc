#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Pow, test_pow_example) {
  const float input_0[3] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[3] = {4.0, 5.0, 6.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {1.0, 32.0, 729.0};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Pow, test_pow) {
  const float input_0[3][4][5] = {{{0.0, 1.0, 2.0, 3.0, 4.0},
                                   {5.0, 6.0, 7.0, 8.0, 9.0},
                                   {10.0, 11.0, 12.0, 13.0, 14.0},
                                   {15.0, 16.0, 17.0, 18.0, 19.0}},
                                  {{20.0, 21.0, 22.0, 23.0, 24.0},
                                   {25.0, 26.0, 27.0, 28.0, 29.0},
                                   {30.0, 31.0, 32.0, 33.0, 34.0},
                                   {35.0, 36.0, 37.0, 38.0, 39.0}},
                                  {{40.0, 41.0, 42.0, 43.0, 44.0},
                                   {45.0, 46.0, 47.0, 48.0, 49.0},
                                   {50.0, 51.0, 52.0, 53.0, 54.0},
                                   {55.0, 56.0, 57.0, 58.0, 59.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[3][4][5] = {
      {{-0.7236856818199158, -0.2671063542366028, -0.7338399887084961,
        -0.2096351981163025, -1.3152467012405396},
       {2.3056600093841553, -1.6935125589370728, -1.9050525426864624,
        -1.1379075050354004, -2.943333148956299},
       {-0.893483579158783, 1.7674877643585205, -0.05546101927757263,
        -0.9354093074798584, -0.1630098670721054},
       {-0.9711150527000427, -0.3384754955768585, -2.5011489391326904,
        -0.3001476228237152, -0.5763992667198181}},
      {{0.9742920994758606, 0.42075803875923157, -0.06563497334718704,
        -1.2010661363601685, -1.111088752746582},
       {0.40880823135375977, 2.142019748687744, 1.3989909887313843,
        -0.46980488300323486, -0.5076617002487183},
       {1.293447732925415, -0.2956339120864868, -0.2097492814064026,
        -1.741786241531372, -0.36155733466148376},
       {-0.519021213054657, 0.6324273943901062, 0.07197296619415283,
        0.49422070384025574, -0.5423237085342407}},
      {{0.44209805130958557, -0.23803293704986572, 1.3411693572998047,
        0.18221811950206757, 0.7692312002182007},
       {1.1420546770095825, 0.8774710893630981, 0.823503315448761,
        -0.5664593577384949, 0.7814710736274719},
       {-2.478606939315796, 0.8230847716331482, -2.488480567932129,
        0.3167894184589386, -1.1132731437683105},
       {0.33886605501174927, -0.39708608388900757, -0.996900737285614,
        0.41519641876220703, -0.26085641980171204}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {
      {{HUGE_VALF, 1.0, 0.6013013124465942, 0.7942890524864197, 0.1614888608455658},
       {40.887184143066406, 0.04810509458184242, 0.024549566209316254,
        0.0938354879617691, 0.0015536256833001971},
       {0.1277957558631897, 69.28652954101562, 0.8712594509124756,
        0.09078352153301239, 0.6503839492797852},
       {0.07209084182977676, 0.3912324607372284, 0.0008364962413907051,
        0.41998419165611267, 0.18320079147815704}},
      {{18.51753807067871, 3.600264310836792, 0.8163757920265198,
        0.02314594015479088, 0.02927270159125328},
       {3.7281157970428467, 1073.7442626953125, 100.56920623779297,
        0.20898643136024475, 0.18096581101417542},
       {81.39151763916016, 0.3623288571834564, 0.4833880066871643,
        0.0022650265600532293, 0.2794361412525177},
       {0.15797774493694305, 9.643802642822266, 1.2967854738235474,
        6.036174297332764, 0.1371285617351532}},
      {{5.10819673538208, 0.4131467342376709, 150.33226013183594,
        1.9844837188720703, 18.373634338378906},
       {77.27857208251953, 28.775436401367188, 23.82199478149414,
        0.11159510910511017, 20.933380126953125},
       {6.150652188807726e-05, 25.43753433227539, 5.36733896296937e-05,
        3.5174858570098877, 0.01178616564720869},
       {3.8882110118865967, 0.20221756398677826, 0.017765074968338013,
        5.397205829620361, 0.34519290924072266}}};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4 * 5; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Pow, test_pow_bcast_scalar) {
  const float input_0[3] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1 = 2.0;
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {1.0, 4.0, 9.0};
  ONNC_RUNTIME_pow_float(NULL, input_0, input_0_ndim, input_0_dims,
                         &input_1, 0, NULL,
                         output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Pow, test_pow_bcast_array) {
  const float input_0[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 3};
  const float input_1[3] = {1.0, 2.0, 3.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[2][3];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 3};
  const float answer_0[2][3] = {{1.0, 4.0, 27.0}, {4.0, 25.0, 216.0}};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
