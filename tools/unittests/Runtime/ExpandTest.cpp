#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Expand, test_expand_dim_changed) {
  const float input_0[3][1] = {{1.0}, {2.0}, {3.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[3] = {2, 1, 6};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[2][3][6];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 6};
  const float answer_0[2][3][6] = {{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
                                    {2.0, 2.0, 2.0, 2.0, 2.0, 2.0},
                                    {3.0, 3.0, 3.0, 3.0, 3.0, 3.0}},
                                   {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
                                    {2.0, 2.0, 2.0, 2.0, 2.0, 2.0},
                                    {3.0, 3.0, 3.0, 3.0, 3.0, 3.0}}};
  ONNC_RUNTIME_expand_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 3 * 6; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Expand, test_expand_dim_unchanged) {
  const float input_0[3][1] = {{1.0}, {2.0}, {3.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 1};
  const float input_1[2] = {3, 4};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {1.0, 1.0, 1.0, 1.0}, {2.0, 2.0, 2.0, 2.0}, {3.0, 3.0, 3.0, 3.0}};
  ONNC_RUNTIME_expand_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
