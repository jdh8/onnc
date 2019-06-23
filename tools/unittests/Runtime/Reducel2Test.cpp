#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_ReduceL2, test_reduce_l2_do_not_keepdims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 2};
  const float answer_0[3][2] = {{2.2360680103302, 5.0},
                                {7.8102498054504395, 10.630146026611328},
                                {13.45362377166748, 16.278820037841797}};
  const int32_t axes[] = {2};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_do_not_keepdims_random) {
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
  const float answer_0[3][2] = {{4.4131269454956055, 2.2427494525909424},
                                {3.2932465076446533, 7.934266090393066},
                                {9.561779022216797, 5.863050937652588}};
  const int32_t axes[] = {2};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_keep_dims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 2, 1};
  const float answer_0[3][2][1] = {{{2.2360680103302}, {5.0}},
                                   {{7.8102498054504395}, {10.630146026611328}},
                                   {{13.45362377166748}, {16.278820037841797}}};
  const int32_t axes[] = {2};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_keep_dims_random) {
  const float input_0[3][2][2] = {{{0.9762700796127319, 4.3037872314453125},
                                   {2.055267572402954, 0.8976636528968811}},
                                  {{-1.5269039869308472, 2.917882204055786},
                                   {-1.248255729675293, 7.835460186004639}},
                                  {{9.273255348205566, -2.331169605255127},
                                   {5.834500789642334, 0.577898383140564}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[3][2][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 2, 1};
  const float answer_0[3][2][1] = {{{4.4131269454956055}, {2.2427494525909424}},
                                   {{3.2932465076446533}, {7.934266090393066}},
                                   {{9.561779022216797}, {5.863050937652588}}};
  const int32_t axes[] = {2};
  const int32_t number_of_axes = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 2 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_default_axes_keepdims_example) {
  const float input_0[3][2][2] = {{{1.0, 2.0}, {3.0, 4.0}},
                                  {{5.0, 6.0}, {7.0, 8.0}},
                                  {{9.0, 10.0}, {11.0, 12.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 2, 2};
  float output_0[1][1][1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[1][1][1] = {{{25.495098114013672}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 1 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ReduceL2, test_reduce_l2_default_axes_keepdims_random) {
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
  const float answer_0[1][1][1] = {{{14.970191955566406}}};
  const int32_t keepdims = 1;
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  ONNC_RUNTIME_reducel2_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 1 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
