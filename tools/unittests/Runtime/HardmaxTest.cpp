#include "dragonite.hpp"
SKYPAT_F(Operator_Hardmax, test_hardmax_example) {
  const float input_0[] = {3.0, 0.0, 1.0, 2.0, 2.0, 5.0, 1.0, 0.0,
                           0.0, 1.0, 3.0, 2.0, 0.0, 1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {4, 4};
  float output_0[16];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {4, 4};
  const float answer_0[] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  const int32_t axis = 0;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 16);
}

SKYPAT_F(Operator_Hardmax, test_hardmax_one_hot) {
  const float input_0[] = {3.0, 3.0, 3.0, 1.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {1, 4};
  float output_0[4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 4};
  const float answer_0[] = {1.0, 0.0, 0.0, 0.0};
  const int32_t axis = 0;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 4);
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_0) {
  const float input_0[] = {
      0.5891188,   0.93310857,   1.7355325,   0.7187048,   -0.49747163,
      -0.51466537, -0.18281569,  -0.91330546, 1.8250471,   0.6454337,
      0.89416075,  -0.026212992, 1.0652802,   0.68068254,  -0.039965652,
      -0.61366034, 1.051813,     1.8772513,   -0.8199832,  -0.5256658,
      0.6201198,   -0.11874606,  -0.6158453,  -0.84978276, -0.73880005,
      0.40499383,  -0.6744098,   -1.1113315,  -1.6114513,  -0.04820468,
      -0.3376543,  0.30022287,   0.06910295,  0.38015565,  0.04694947,
      1.8615648,   -0.6116324,   -0.37764725, 0.7060984,   0.20334688,
      1.0085456,   -0.679099,    0.87942386,  -1.2265062,  0.848612,
      -0.16141996, -0.7864848,   -0.7228651,  -0.34819475, -0.2233158,
      1.6267247,   -0.3108181,   -1.6610461,  1.0064051,   0.50837195,
      -0.38790694, 0.30552998,   0.3489994,   2.3155596,   1.1161721};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  const int32_t axis = 0;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_1) {
  const float input_0[] = {
      0.5891188,   0.93310857,   1.7355325,   0.7187048,   -0.49747163,
      -0.51466537, -0.18281569,  -0.91330546, 1.8250471,   0.6454337,
      0.89416075,  -0.026212992, 1.0652802,   0.68068254,  -0.039965652,
      -0.61366034, 1.051813,     1.8772513,   -0.8199832,  -0.5256658,
      0.6201198,   -0.11874606,  -0.6158453,  -0.84978276, -0.73880005,
      0.40499383,  -0.6744098,   -1.1113315,  -1.6114513,  -0.04820468,
      -0.3376543,  0.30022287,   0.06910295,  0.38015565,  0.04694947,
      1.8615648,   -0.6116324,   -0.37764725, 0.7060984,   0.20334688,
      1.0085456,   -0.679099,    0.87942386,  -1.2265062,  0.848612,
      -0.16141996, -0.7864848,   -0.7228651,  -0.34819475, -0.2233158,
      1.6267247,   -0.3108181,   -1.6610461,  1.0064051,   0.50837195,
      -0.38790694, 0.30552998,   0.3489994,   2.3155596,   1.1161721};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  const int32_t axis = 1;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Hardmax, test_hardmax_default_axis) {
  const float input_0[] = {
      0.5891188,   0.93310857,   1.7355325,   0.7187048,   -0.49747163,
      -0.51466537, -0.18281569,  -0.91330546, 1.8250471,   0.6454337,
      0.89416075,  -0.026212992, 1.0652802,   0.68068254,  -0.039965652,
      -0.61366034, 1.051813,     1.8772513,   -0.8199832,  -0.5256658,
      0.6201198,   -0.11874606,  -0.6158453,  -0.84978276, -0.73880005,
      0.40499383,  -0.6744098,   -1.1113315,  -1.6114513,  -0.04820468,
      -0.3376543,  0.30022287,   0.06910295,  0.38015565,  0.04694947,
      1.8615648,   -0.6116324,   -0.37764725, 0.7060984,   0.20334688,
      1.0085456,   -0.679099,    0.87942386,  -1.2265062,  0.848612,
      -0.16141996, -0.7864848,   -0.7228651,  -0.34819475, -0.2233158,
      1.6267247,   -0.3108181,   -1.6610461,  1.0064051,   0.50837195,
      -0.38790694, 0.30552998,   0.3489994,   2.3155596,   1.1161721};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  const int32_t axis = 0;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Hardmax, test_hardmax_axis_2) {
  const float input_0[] = {
      0.5891188,   0.93310857,   1.7355325,   0.7187048,   -0.49747163,
      -0.51466537, -0.18281569,  -0.91330546, 1.8250471,   0.6454337,
      0.89416075,  -0.026212992, 1.0652802,   0.68068254,  -0.039965652,
      -0.61366034, 1.051813,     1.8772513,   -0.8199832,  -0.5256658,
      0.6201198,   -0.11874606,  -0.6158453,  -0.84978276, -0.73880005,
      0.40499383,  -0.6744098,   -1.1113315,  -1.6114513,  -0.04820468,
      -0.3376543,  0.30022287,   0.06910295,  0.38015565,  0.04694947,
      1.8615648,   -0.6116324,   -0.37764725, 0.7060984,   0.20334688,
      1.0085456,   -0.679099,    0.87942386,  -1.2265062,  0.848612,
      -0.16141996, -0.7864848,   -0.7228651,  -0.34819475, -0.2233158,
      1.6267247,   -0.3108181,   -1.6610461,  1.0064051,   0.50837195,
      -0.38790694, 0.30552998,   0.3489994,   2.3155596,   1.1161721};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
                            1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
                            1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
  const int32_t axis = 2;
  ONNC_RUNTIME_hardmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
