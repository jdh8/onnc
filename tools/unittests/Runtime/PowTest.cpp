#include "dragonite.hpp"
SKYPAT_F(Operator_Pow, test_pow_example) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {4.0, 5.0, 6.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {1.0, 32.0, 729.0};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Pow, test_pow) {
  const float input_0[] = {
      0.47091252,  0.5579589,  0.73811615, 0.5763894,  0.7486305,   0.5353635,
      0.29455265,  0.38971752, 0.35880652, 0.4990178,  0.9947136,   0.6972461,
      0.040994544, 0.37653518, 0.34597304, 0.8064927,  0.8549,      0.14749503,
      0.165989,    0.9578264,  0.1493346,  0.79041606, 0.27476037,  0.8267266,
      0.33034036,  0.87839943, 0.5735558,  0.13335857, 0.71285945,  0.017152777,
      0.72104496,  0.03865536, 0.9476301,  0.47510234, 0.14729546,  0.09910579,
      0.9084177,   0.19703606, 0.3455918,  0.6837372,  0.3569415,   0.59261143,
      0.6729352,   0.30757096, 0.46734118, 0.65022284, 0.30613652,  0.9010934,
      0.5386131,   0.8806984,  0.62043864, 0.5812713,  0.079777546, 0.52735645,
      0.16935967,  0.33685094, 0.66179603, 0.63466954, 0.80715317,  0.84041697};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {
      1.7086855,    1.5459019,   0.5375574,   -0.5508467,  -1.0731336,
      0.07417402,   0.6710186,   0.2767722,   2.1806316,   0.5204766,
      0.09520119,   2.2952726,   0.86788577,  -0.6893376,  -0.91970575,
      -0.059255913, 0.6520528,   0.8518343,   0.3084092,   -1.0125563,
      -0.35970443,  0.32386786,  -0.55151373, 0.7577202,   0.30286583,
      -0.2760293,   0.8918075,   1.1947271,   0.29890126,  -0.58531284,
      -0.98321855,  0.15907429,  1.01975,     0.2743738,   -1.1620457,
      0.45386818,   -0.20364442, 0.45760527,  0.3609397,   -2.269642,
      0.44273734,   -1.9856858,  -0.4509873,  -2.1813457,  -0.30678758,
      0.30134964,   0.7118247,   -0.32261664, 0.53853387,  1.5795918,
      -0.92320305,  -1.4734614,  -0.53675336, -0.14964074, -1.4995192,
      0.7344604,    -1.3108997,  -0.8611159,  0.30802724,  -0.20851299};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.27615806, 0.40576246, 0.8493945,   1.354593,   1.364356,   0.95471287,
      0.44035047, 0.77042603, 0.106982894, 0.6964284,  0.9994955,  0.4370472,
      0.06251794, 1.9607092,  2.6542723,   1.0128251,  0.90282834, 0.19585563,
      0.5747318,  1.0445956,  1.9817924,   0.9266565,  2.0390344,  0.86573195,
      0.71500635, 1.0364363,  0.60911036,  0.09008217, 0.9037799,  10.801068,
      1.3792851,  0.59602076, 0.9466239,   0.81530267, 9.259809,   0.35023642,
      1.0197529,  0.4755327,  0.6814739,   2.3699675,  0.63375,    2.8262289,
      1.195589,   13.090862,  1.2628511,   0.8783475,  0.43058777, 1.0341702,
      0.7166111,  0.8181812,  1.5537498,   2.2242246,  3.8852525,  1.100486,
      14.3355465, 0.4496988,  1.7179585,   1.4792084,  0.93613803, 1.0369166};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Pow, test_pow_bcast_scalar) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {2.0};
  const int32_t input_1_ndim = 0;
  const int32_t input_1_dims[] = {};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {1.0, 4.0, 9.0};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Pow, test_pow_bcast_array) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 3};
  const float input_1[] = {1.0, 2.0, 3.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[6];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 3};
  const float answer_0[] = {1.0, 4.0, 27.0, 4.0, 25.0, 216.0};
  ONNC_RUNTIME_pow_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 6);
}
