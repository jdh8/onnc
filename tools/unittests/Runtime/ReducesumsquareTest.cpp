#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_ReduceSumSquare,
         test_reduce_sum_square_do_not_keepdims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[3][2] = {{10.0, 20.0}, {74.0, 100.0}, {202.0, 244.0}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceSumSquare,
         test_reduce_sum_square_do_not_keepdims_random) {
  const float input_0[3][2][2] = {{{0.9762700796127319, 4.3037872314453125},
                                   {2.055267572402954, 0.8976636528968811}},
                                  {{-1.5269039869308472, 2.917882204055786},
                                   {-1.248255729675293, 7.835460186004639}},
                                  {{9.273255348205566, -2.331169605255127},
                                   {5.834500789642334, 0.577898383140564}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[3][2] = {{5.177227973937988, 19.328384399414062},
                                {3.889578104019165, 69.9084701538086},
                                {120.03466796875, 5.7683186531066895}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_keepdims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][1][2];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float answer_0[3][1][2] = {
      {{10.0, 20.0}}, {{74.0, 100.0}}, {{202.0, 244.0}}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 1 * 2; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceSumSquare, test_reduce_sum_square_keepdims_random) {
  const float input_0[3][2][2] = {{{0.9762700796127319, 4.3037872314453125},
                                   {2.055267572402954, 0.8976636528968811}},
                                  {{-1.5269039869308472, 2.917882204055786},
                                   {-1.248255729675293, 7.835460186004639}},
                                  {{9.273255348205566, -2.331169605255127},
                                   {5.834500789642334, 0.577898383140564}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][1][2];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float answer_0[3][1][2] = {{{5.177227973937988, 19.328384399414062}},
                                   {{3.889578104019165, 69.9084701538086}},
                                   {{120.03466796875, 5.7683186531066895}}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 1 * 2; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceSumSquare,
         test_reduce_sum_square_default_axes_keepdims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1][1][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[1][1][1] = {{{650.0}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 1 * 1; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceSumSquare,
         test_reduce_sum_square_default_axes_keepdims_random) {
  const float input_0[3][2][2] = {{{0.9762700796127319, 4.3037872314453125},
                                   {2.055267572402954, 0.8976636528968811}},
                                  {{-1.5269039869308472, 2.917882204055786},
                                   {-1.248255729675293, 7.835460186004639}},
                                  {{9.273255348205566, -2.331169605255127},
                                   {5.834500789642334, 0.577898383140564}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1][1][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[1][1][1] = {{{224.10665893554688}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducesumsquare_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 1 * 1; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
