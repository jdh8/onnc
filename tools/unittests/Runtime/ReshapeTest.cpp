#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Reshape, test_reshape_reordered_dims) {
  const float input_0[2][3][4] = {{{0.6629225015640259, 0.7903203964233398,
                                    0.5819759368896484, 0.6221379041671753},
                                   {0.5091242790222168, 0.9403435587882996,
                                    0.01868925616145134, 0.8477417826652527},
                                   {0.9383321404457092, 0.9039480686187744,
                                    0.7934683561325073, 0.5283330678939819}},
                                  {{0.6679678559303284, 0.6007908582687378,
                                    0.9962767958641052, 0.5708685517311096},
                                   {0.9497292637825012, 0.446055144071579,
                                    0.1316518485546112, 0.7494239211082458},
                                   {0.12591566145420074, 0.9612222909927368,
                                    0.747750997543335, 0.6554921865463257}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[3] = {4, 2, 3};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[4][2][3];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 2, 3};
  const float answer_0[4][2][3] = {
      {{0.6629225015640259, 0.7903203964233398, 0.5819759368896484},
       {0.6221379041671753, 0.5091242790222168, 0.9403435587882996}},
      {{0.01868925616145134, 0.8477417826652527, 0.9383321404457092},
       {0.9039480686187744, 0.7934683561325073, 0.5283330678939819}},
      {{0.6679678559303284, 0.6007908582687378, 0.9962767958641052},
       {0.5708685517311096, 0.9497292637825012, 0.446055144071579}},
      {{0.1316518485546112, 0.7494239211082458, 0.12591566145420074},
       {0.9612222909927368, 0.747750997543335, 0.6554921865463257}}};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 4 * 2 * 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Reshape, test_reshape_reduced_dims) {
  const float input_0[2][3][4] = {{{0.6629225015640259, 0.7903203964233398,
                                    0.5819759368896484, 0.6221379041671753},
                                   {0.5091242790222168, 0.9403435587882996,
                                    0.01868925616145134, 0.8477417826652527},
                                   {0.9383321404457092, 0.9039480686187744,
                                    0.7934683561325073, 0.5283330678939819}},
                                  {{0.6679678559303284, 0.6007908582687378,
                                    0.9962767958641052, 0.5708685517311096},
                                   {0.9497292637825012, 0.446055144071579,
                                    0.1316518485546112, 0.7494239211082458},
                                   {0.12591566145420074, 0.9612222909927368,
                                    0.747750997543335, 0.6554921865463257}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[2] = {3, 8};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[3][8];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 8};
  const float answer_0[3][8] = {
      {0.6629225015640259, 0.7903203964233398, 0.5819759368896484,
       0.6221379041671753, 0.5091242790222168, 0.9403435587882996,
       0.01868925616145134, 0.8477417826652527},
      {0.9383321404457092, 0.9039480686187744, 0.7934683561325073,
       0.5283330678939819, 0.6679678559303284, 0.6007908582687378,
       0.9962767958641052, 0.5708685517311096},
      {0.9497292637825012, 0.446055144071579, 0.1316518485546112,
       0.7494239211082458, 0.12591566145420074, 0.9612222909927368,
       0.747750997543335, 0.6554921865463257}};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 8; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Reshape, test_reshape_extended_dims) {
  const float input_0[2][3][4] = {{{0.6629225015640259, 0.7903203964233398,
                                    0.5819759368896484, 0.6221379041671753},
                                   {0.5091242790222168, 0.9403435587882996,
                                    0.01868925616145134, 0.8477417826652527},
                                   {0.9383321404457092, 0.9039480686187744,
                                    0.7934683561325073, 0.5283330678939819}},
                                  {{0.6679678559303284, 0.6007908582687378,
                                    0.9962767958641052, 0.5708685517311096},
                                   {0.9497292637825012, 0.446055144071579,
                                    0.1316518485546112, 0.7494239211082458},
                                   {0.12591566145420074, 0.9612222909927368,
                                    0.747750997543335, 0.6554921865463257}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[4] = {3, 2, 2, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {4};
  float output_0[3][2][2][2];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {3, 2, 2, 2};
  const float answer_0[3][2][2][2] = {
      {{{0.6629225015640259, 0.7903203964233398},
        {0.5819759368896484, 0.6221379041671753}},
       {{0.5091242790222168, 0.9403435587882996},
        {0.01868925616145134, 0.8477417826652527}}},
      {{{0.9383321404457092, 0.9039480686187744},
        {0.7934683561325073, 0.5283330678939819}},
       {{0.6679678559303284, 0.6007908582687378},
        {0.9962767958641052, 0.5708685517311096}}},
      {{{0.9497292637825012, 0.446055144071579},
        {0.1316518485546112, 0.7494239211082458}},
       {{0.12591566145420074, 0.9612222909927368},
        {0.747750997543335, 0.6554921865463257}}}};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2 * 2 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Reshape, test_reshape_one_dim) {
  const float input_0[2][3][4] = {{{0.6629225015640259, 0.7903203964233398,
                                    0.5819759368896484, 0.6221379041671753},
                                   {0.5091242790222168, 0.9403435587882996,
                                    0.01868925616145134, 0.8477417826652527},
                                   {0.9383321404457092, 0.9039480686187744,
                                    0.7934683561325073, 0.5283330678939819}},
                                  {{0.6679678559303284, 0.6007908582687378,
                                    0.9962767958641052, 0.5708685517311096},
                                   {0.9497292637825012, 0.446055144071579,
                                    0.1316518485546112, 0.7494239211082458},
                                   {0.12591566145420074, 0.9612222909927368,
                                    0.747750997543335, 0.6554921865463257}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[1] = {24};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {1};
  float output_0[24];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {24};
  const float answer_0[24] = {
      0.6629225015640259,  0.7903203964233398, 0.5819759368896484,
      0.6221379041671753,  0.5091242790222168, 0.9403435587882996,
      0.01868925616145134, 0.8477417826652527, 0.9383321404457092,
      0.9039480686187744,  0.7934683561325073, 0.5283330678939819,
      0.6679678559303284,  0.6007908582687378, 0.9962767958641052,
      0.5708685517311096,  0.9497292637825012, 0.446055144071579,
      0.1316518485546112,  0.7494239211082458, 0.12591566145420074,
      0.9612222909927368,  0.747750997543335,  0.6554921865463257};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 24; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Reshape, test_reshape_negative_dim) {
  const float input_0[2][3][4] = {{{0.6629225015640259, 0.7903203964233398,
                                    0.5819759368896484, 0.6221379041671753},
                                   {0.5091242790222168, 0.9403435587882996,
                                    0.01868925616145134, 0.8477417826652527},
                                   {0.9383321404457092, 0.9039480686187744,
                                    0.7934683561325073, 0.5283330678939819}},
                                  {{0.6679678559303284, 0.6007908582687378,
                                    0.9962767958641052, 0.5708685517311096},
                                   {0.9497292637825012, 0.446055144071579,
                                    0.1316518485546112, 0.7494239211082458},
                                   {0.12591566145420074, 0.9612222909927368,
                                    0.747750997543335, 0.6554921865463257}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[3] = {6, -1, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[6][2][2];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {6, 2, 2};
  const float answer_0[6][2][2] = {{{0.6629225015640259, 0.7903203964233398},
                                    {0.5819759368896484, 0.6221379041671753}},
                                   {{0.5091242790222168, 0.9403435587882996},
                                    {0.01868925616145134, 0.8477417826652527}},
                                   {{0.9383321404457092, 0.9039480686187744},
                                    {0.7934683561325073, 0.5283330678939819}},
                                   {{0.6679678559303284, 0.6007908582687378},
                                    {0.9962767958641052, 0.5708685517311096}},
                                   {{0.9497292637825012, 0.446055144071579},
                                    {0.1316518485546112, 0.7494239211082458}},
                                   {{0.12591566145420074, 0.9612222909927368},
                                    {0.747750997543335, 0.6554921865463257}}};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 6 * 2 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}