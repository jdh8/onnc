#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Equal, test_equal) {
  const float input_0[3][4][5] = {{{9, 10, 7, -6, 17},
                                   {-11, 5, 0, 18, 10},
                                   {2, 4, 10, -1, 2},
                                   {-9, -16, -16, -7, 18}},
                                  {{12, 9, 4, -8, -8},
                                   {-12, 13, -17, -5, 8},
                                   {-11, -8, 8, -5, 9},
                                   {0, 4, -15, 0, 16}},
                                  {{1, 8, 22, -8, -2},
                                   {-7, -6, 1, 23, -8},
                                   {8, -1, -4, 6, -2},
                                   {-1, 10, 5, 10, 7}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[3][4][5] = {{{-4, 12, 33, -12, -12},
                                   {11, -7, 9, -5, 11},
                                   {-12, 16, -4, -3, 0},
                                   {-6, -14, -8, -1, 0}},
                                  {{-10, -12, -5, 11, 17},
                                   {15, 12, -8, -12, 3},
                                   {0, -1, 2, 2, 0},
                                   {-8, 0, 0, 5, -6}},
                                  {{-12, -4, 9, 17, 4},
                                   {-5, -1, -11, -11, 7},
                                   {3, -5, -24, 0, 17},
                                   {-5, 0, -7, -10, -5}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {{{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0}},
                                   {{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0}},
                                   {{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0}}};
  ONNC_RUNTIME_equal_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
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

SKYPAT_F(Operator_Equal, test_equal_bcast) {
  const float input_0[3][4][5] = {{{-5, 6, 1, -16, 1},
                                   {-13, -13, 12, 1, 9},
                                   {-14, -1, -20, 25, 7},
                                   {11, -8, 0, 0, 0}},
                                  {{0, -7, 6, -19, 5},
                                   {15, 4, 7, 12, 11},
                                   {-1, -17, 0, 0, -22},
                                   {9, 1, -3, -7, -5}},
                                  {{0, -15, -12, 0, -1},
                                   {19, -5, -2, -10, 6},
                                   {0, 0, -5, 6, -5},
                                   {-6, 11, 6, 6, -6}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[5] = {-2, 7, 11, 6, 0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {{{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 1.0}},
                                   {{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0}},
                                   {{0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 1.0, 0.0},
                                    {0.0, 0.0, 0.0, 1.0, 0.0}}};
  ONNC_RUNTIME_equal_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
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
