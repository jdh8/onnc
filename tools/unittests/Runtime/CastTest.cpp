#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Cast, test_cast_FLOAT_to_FLOAT16) {
  const float input_0[3][4] = {{0.3022019863128662, 0.8063466548919678,
                                0.864998459815979, 0.03227711096405983},
                               {0.3946835696697235, 0.9809305667877197,
                                0.33763837814331055, 0.7908293008804321},
                               {0.22062817215919495, 0.7196412682533264,
                                0.7306746244430542, 0.7435911893844604}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {0.30224609375, 0.80615234375, 0.865234375, 0.03228759765625},
      {0.394775390625, 0.98095703125, 0.337646484375, 0.791015625},
      {0.2205810546875, 0.7197265625, 0.73046875, 0.74365234375}};
  const int32_t to = 10;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT_to_DOUBLE) {
  const float input_0[3][4] = {{0.16069738566875458, 0.19041688740253448,
                                0.9013904929161072, 0.2974350154399872},
                               {0.6953126788139343, 0.7173351645469666,
                                0.0355803407728672, 0.8799872994422913},
                               {0.40472230315208435, 0.21204793453216553,
                                0.43738842010498047, 0.4469706416130066}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {{0.16069738566875458, 0.19041688740253448,
                                 0.9013904929161072, 0.2974350154399872},
                                {0.6953126788139343, 0.7173351645469666,
                                 0.0355803407728672, 0.8799872994422913},
                                {0.40472230315208435, 0.21204793453216553,
                                 0.43738842010498047, 0.4469706416130066}};
  const int32_t to = 11;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT16_to_FLOAT) {
  const float input_0[3][4] = {
      {0.269287109375, 0.483154296875, 0.471923828125, 0.39111328125},
      {0.2281494140625, 0.0029659271240234375, 0.6455078125, 0.291015625},
      {0.8095703125, 0.9365234375, 0.9375, 0.59326171875}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {0.269287109375, 0.483154296875, 0.471923828125, 0.39111328125},
      {0.2281494140625, 0.0029659271240234375, 0.6455078125, 0.291015625},
      {0.8095703125, 0.9365234375, 0.9375, 0.59326171875}};
  const int32_t to = 1;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT16_to_DOUBLE) {
  const float input_0[3][4] = {
      {0.08538818359375, 0.38232421875, 0.81884765625, 0.3388671875},
      {0.744140625, 0.98974609375, 0.42919921875, 0.71923828125},
      {0.53564453125, 0.7978515625, 0.156982421875, 0.91064453125}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {0.08538818359375, 0.38232421875, 0.81884765625, 0.3388671875},
      {0.744140625, 0.98974609375, 0.42919921875, 0.71923828125},
      {0.53564453125, 0.7978515625, 0.156982421875, 0.91064453125}};
  const int32_t to = 11;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Cast, test_cast_DOUBLE_to_FLOAT) {
  const float input_0[3][4] = {{0.979248256531373, 0.7674158088902245,
                                0.7338262213818313, 0.5728263337823365},
                               {0.7613365427978532, 0.8453067033710155,
                                0.10403720501538949, 0.2987458731179419},
                               {0.41440073878532924, 0.6654138628518861,
                                0.557902675240545, 0.29407621177293486}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {{0.9792482852935791, 0.7674158215522766,
                                 0.733826220035553, 0.5728263258934021},
                                {0.7613365650177002, 0.8453066945075989,
                                 0.10403720289468765, 0.29874587059020996},
                                {0.41440072655677795, 0.6654138565063477,
                                 0.5579026937484741, 0.29407620429992676}};
  const int32_t to = 1;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Cast, test_cast_DOUBLE_to_FLOAT16) {
  const float input_0[3][4] = {{0.5273264140697544, 0.6128622955323463,
                                0.04858055110487125, 0.8476013971097167},
                               {0.6419881317104794, 0.47940684694127556,
                                0.2708854643220123, 0.9503757700002671},
                               {0.7175971696938099, 0.46565814522058746,
                                0.8553219365443595, 0.402006478789698}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {0.52734375, 0.61279296875, 0.048583984375, 0.84765625},
      {0.64208984375, 0.4794921875, 0.27099609375, 0.9501953125},
      {0.7177734375, 0.465576171875, 0.85546875, 0.402099609375}};
  const int32_t to = 10;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
