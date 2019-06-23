#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[2] = {1, 0};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMin, test_argmin_no_keepdims_random) {
  const float input_0[2][3][4] = {{{-5.212480545043945, -5.932551860809326,
                                    -4.440053462982178, -9.87150764465332},
                                   {5.754096508026123, -5.236068248748779,
                                    7.332681179046631, 5.005091667175293},
                                   {-2.453352212905884, -7.877349376678467,
                                    3.904751777648926, 7.671276569366455}},
                                  {{8.400087356567383, 4.02393913269043,
                                    0.04143378511071205, 5.616342544555664},
                                   {3.246438980102539, 3.5887954235076904,
                                    -6.471562385559082, 2.763096809387207},
                                   {-8.953320503234863, 5.186042785644531,
                                    4.494019031524658, -5.612167835235596}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[2][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[2][4] = {{0, 2, 0, 0}, {2, 1, 1, 2}};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2][1];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[2][1] = {{1}, {0}};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMin, test_argmin_keepdims_random) {
  const float input_0[2][3][4] = {{{6.329629421234131, -0.29236531257629395,
                                    6.260229587554932, -9.322911262512207},
                                   {-0.2570730149745941, 5.984583854675293,
                                    -4.203712463378906, -0.9266616106033325},
                                   {5.639059066772461, -9.022263526916504,
                                    -5.09410285949707, -3.354240894317627}},
                                  {{2.7715752124786377, -2.2062082290649414,
                                    -3.288693428039551, -1.9266713857650757},
                                   {5.029782772064209, -7.989380359649658,
                                    -1.3362966775894165, -3.357750177383423},
                                   {9.005533218383789, 6.339470863342285,
                                    9.479151725769043, 2.5514447689056396}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[2][1][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[2][1][4] = {{{1, 2, 2, 0}}, {{0, 1, 0, 1}}};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 1 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[1][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[1][2] = {{0, 0}};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMin, test_argmin_default_axis_random) {
  const float input_0[2][3][4] = {{{-8.9327974319458, 3.7171273231506348,
                                    0.5501256585121155, 7.722576141357422},
                                   {4.567225933074951, -7.540609836578369,
                                    -3.3692750930786133, -7.13131856918335},
                                   {5.023095607757568, -8.593768119812012,
                                    6.672436714172363, -2.8982043266296387}},
                                  {{6.656174659729004, -2.233959197998047,
                                    -7.6782121658325195, 3.08587646484375},
                                   {-2.3404641151428223, -5.091067314147949,
                                    3.518833875656128, -1.9302527904510498},
                                   {-4.625064373016357, -8.579294204711914,
                                    9.477191925048828, -1.685600996017456}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[1][3][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[1][3][4] = {{{0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}}};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmin_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
