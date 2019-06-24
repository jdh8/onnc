#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Tanh, test_tanh_example) {
  const float input_0[3] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {-0.7615941762924194, 0.0, 0.7615941762924194};
  ONNC_RUNTIME_tanh_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
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

SKYPAT_F(Operator_Tanh, test_tanh) {
  const float input_0[3][4][5] = {
      {{0.45166558027267456, 2.1424334049224854, 0.03029245138168335,
        0.12168127298355103, 0.33421778678894043},
       {0.016436489298939705, 0.254049152135849, -0.2376382201910019,
        -1.7323367595672607, 0.17626114189624786},
       {1.3408828973770142, -0.8815158009529114, -1.2636075019836426,
        1.1188067197799683, -0.42963090538978577},
       {0.011056468822062016, 0.06309327483177185, 0.6896132826805115,
        -1.9240057468414307, -0.059000108391046524}},
      {{-1.269167184829712, 1.1993123292922974, -0.8779256343841553,
        -0.5742959380149841, -0.45207178592681885},
       {-0.790662944316864, 0.3654269874095917, -0.4085111916065216,
        1.1713671684265137, 0.724579393863678},
       {0.36209413409233093, 0.5412269234657288, -0.8255913257598877,
        0.23602665960788727, 0.7097527980804443},
       {-0.5421715974807739, -1.3282235860824585, 0.42358899116516113,
        1.2864986658096313, 1.0812170505523682}},
      {{0.5321064591407776, 1.7574753761291504, -0.21735252439975739,
        -1.4236702919006348, 0.22035938501358032},
       {0.867919385433197, -0.39340028166770935, -1.2340682744979858,
        0.2019835114479065, -0.053896836936473846},
       {-0.2143237143754959, -1.6208266019821167, -0.21057087182998657,
        -0.42095762491226196, -0.17252859473228455},
       {0.08864283561706543, -0.3019311726093292, -0.0731719359755516,
        -1.16921865940094, 1.3546072244644165}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {
      {{0.42326709628105164, 0.972823441028595, 0.030283188447356224,
        0.12108425796031952, 0.3223055601119995},
       {0.016435008496046066, 0.2487211525440216, -0.23326371610164642,
        -0.9393314719200134, 0.17445819079875946},
       {0.8718841671943665, -0.7071779370307922, -0.8520556092262268,
        0.8071534633636475, -0.4050128161907196},
       {0.011056018061935902, 0.06300968676805496, 0.5977334976196289,
        -0.958246111869812, -0.05893174558877945}},
      {{-0.8535717725753784, 0.8334447145462036, -0.7053785920143127,
        -0.5185073018074036, -0.42360052466392517},
       {-0.6587844491004944, 0.349985271692276, -0.38720783591270447,
        0.824709951877594, 0.6197379231452942},
       {0.3470572829246521, 0.4939161241054535, -0.6781017184257507,
        0.23173926770687103, 0.6105217933654785},
       {-0.49463000893592834, -0.8688144683837891, 0.39994969964027405,
        0.8582067489624023, 0.7936500310897827}},
      {{0.4869896173477173, 0.9422203898429871, -0.21399326622486115,
        -0.8903620839118958, 0.2168605774641037},
       {0.7003154158592224, -0.3742879033088684, -0.8437553644180298,
        0.19928079843521118, -0.05384470894932747},
       {-0.21110127866268158, -0.9247440695762634, -0.20751284062862396,
        -0.39773687720298767, -0.1708368957042694},
       {0.08841139078140259, -0.2930788993835449, -0.07304162532091141,
        -0.8240215182304382, 0.8751363754272461}}};
  ONNC_RUNTIME_tanh_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
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