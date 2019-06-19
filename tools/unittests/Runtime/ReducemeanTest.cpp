#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_ReduceMean, test_reduce_mean_do_not_keepdims_example) {
  const float input_0[3][2][2] = {{{5.0, 1.0}, {20.0, 2.0}},
                                  {{30.0, 1.0}, {40.0, 2.0}},
                                  {{55.0, 1.0}, {60.0, 2.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[3][2] = {{12.5, 1.5}, {35.0, 1.5}, {57.5, 1.5}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducemean_float(
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

SKYPAT_F(Operator_ReduceMean, test_reduce_mean_do_not_keepdims_random) {
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
  const float answer_0[3][2] = {{1.5157687664031982, 2.6007254123687744},
                                {-1.3875799179077148, 5.376671314239502},
                                {7.553877830505371, -0.8766356110572815}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducemean_float(
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

SKYPAT_F(Operator_ReduceMean, test_reduce_mean_keepdims_example) {
  const float input_0[3][2][2] = {{{5.0, 1.0}, {20.0, 2.0}},
                                  {{30.0, 1.0}, {40.0, 2.0}},
                                  {{55.0, 1.0}, {60.0, 2.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][1][2];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 1, 2};
  const float answer_0[3][1][2] = {{{12.5, 1.5}}, {{35.0, 1.5}}, {{57.5, 1.5}}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducemean_float(
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

SKYPAT_F(Operator_ReduceMean, test_reduce_mean_keepdims_random) {
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
  const float answer_0[3][1][2] = {{{1.5157687664031982, 2.6007254123687744}},
                                   {{-1.3875799179077148, 5.376671314239502}},
                                   {{7.553877830505371, -0.8766356110572815}}};
  const int32_t axes[] = {1};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducemean_float(
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

SKYPAT_F(Operator_ReduceMean, test_reduce_mean_default_axes_keepdims_example) {
  const float input_0[3][2][2] = {{{5.0, 1.0}, {20.0, 2.0}},
                                  {{30.0, 1.0}, {40.0, 2.0}},
                                  {{55.0, 1.0}, {60.0, 2.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1][1][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[1][1][1] = {{{18.25}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducemean_float(
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

SKYPAT_F(Operator_ReduceMean, test_reduce_mean_default_axes_keepdims_random) {
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
  const float answer_0[1][1][1] = {{{2.4638044834136963}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducemean_float(
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
