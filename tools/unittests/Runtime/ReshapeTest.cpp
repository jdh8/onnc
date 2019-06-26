#include "dragonite.hpp"
SKYPAT_F(Operator_Reshape, test_reshape_reordered_dims) {
  const float input_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {4, 2, 3};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 2, 3};
  const float answer_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Reshape, test_reshape_reduced_dims) {
  const float input_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {3, 8};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {2};
  float output_0[24];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 8};
  const float answer_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Reshape, test_reshape_extended_dims) {
  const float input_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {3, 2, 2, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {4};
  float output_0[24];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {3, 2, 2, 2};
  const float answer_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Reshape, test_reshape_one_dim) {
  const float input_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {24};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {1};
  float output_0[24];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {24};
  const float answer_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Reshape, test_reshape_negative_dim) {
  const float input_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {6, -1, 2};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {6, 2, 2};
  const float answer_0[] = {
      0.42802656, 0.059519134, 0.56735414, 0.91112614,  0.76809007, 0.94705147,
      0.71525353, 0.4733967,   0.32751182, 0.040127836, 0.21830331, 0.63501596,
      0.81942964, 0.55322605,  0.4713199,  0.035757024, 0.89796126, 0.9393275,
      0.55003357, 0.7005113,   0.665309,   0.27943468,  0.7552847,  0.13886626};
  ONNC_RUNTIME_reshape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)input_1, input_1_ndim, input_1_dims,
                             (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}
