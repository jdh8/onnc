#include "dragonite.hpp"
SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu_example) {
  const float input_0[] = {-1.5, 0.0, 1.2, 2.0, 2.2};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {5};
  float output_0[5];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {5};
  const float answer_0[] = {0.0, 0.0, 0.0, 0.0, 2.2};
  const float alpha = 2.0;
  ONNC_RUNTIME_thresholdedrelu_float(NULL, (float *)input_0, input_0_ndim,
                                     input_0_dims, (float *)output_0,
                                     output_0_ndim, output_0_dims, alpha);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 5);
}

SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu) {
  const float input_0[] = {
      -0.033670384, 0.6307308,   -1.5886127,  -2.049998,   0.48139718,
      -0.17858055,  -0.33069506, -0.87215215, -0.40104613, 0.10088636,
      0.3145667,    0.6069505,   -0.62005305, -0.3160946,  0.1939844,
      -0.048541103, 0.3503502,   -1.6753752,  0.5363228,   -1.6291784,
      0.51649857,   -0.40193588, -0.798374,   0.56656575,  0.35158613,
      -0.52559453,  -0.2919002,  0.8205491,   -0.06566683, -1.7714858,
      -0.72244906,  -0.47833514, -1.1848544,  1.928386,    -1.0603518,
      -0.051368874, -0.8458007,  -0.2243624,  2.3764358,   -0.06926383,
      -0.8093261,   1.3266203,   0.07391125,  0.7550951,   -0.23468919,
      0.2636073,    -2.5937285,  0.6284602,   -1.007757,   0.3746332,
      -1.3345093,   -0.73827714, -0.40751815, -1.3061124,  0.5018572,
      -0.012377044, 0.49299917,  -1.0370551,  -1.39785,    -0.6070187};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.0, 0.0, 0.0,       0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,       0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,       0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 2.3764358, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0,       0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const float alpha = 2.0;
  ONNC_RUNTIME_thresholdedrelu_float(NULL, (float *)input_0, input_0_ndim,
                                     input_0_dims, (float *)output_0,
                                     output_0_ndim, output_0_dims, alpha);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_ThresholdedRelu, test_thresholdedrelu_default) {
  const float input_0[] = {
      0.68378764,  0.09171509,  2.0222912,   0.56393105,   -1.3698022,
      -1.5716664,  -1.8627979,  0.8267089,   -0.069147706, -0.37335047,
      -1.512045,   -0.01916363, -0.305926,   0.51322764,   -1.3774017,
      1.5191826,   -2.3416572,  -1.5114585,  -0.47988066,  0.5602322,
      1.4418638,   0.72556573,  -0.981036,   0.15845454,   0.79404896,
      -1.5902517,  -1.3016347,  -2.0771582,  -0.27495155,  -0.34789628,
      -0.5502664,  0.6831919,   2.4758773,   -0.5123359,   -0.7992984,
      1.4318929,   0.6469138,   0.084133625, -1.6547405,   -1.4005108,
      0.6776396,   0.27165967,  -0.34116822, -0.7904407,   -1.357647,
      -0.21689783, 1.3223611,   -0.04767157, -1.2309182,   1.6931027,
      -0.34473532, 1.1261737,   2.0562408,   -0.8991903,   0.2742629,
      -0.7832055,  -0.40409616, -2.378203,   -1.6409367,   -1.7125579};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.0,       0.0,       2.0222912, 0.0,       0.0,       0.0, 0.0,
      0.0,       0.0,       0.0,       0.0,       0.0,       0.0, 0.0,
      0.0,       1.5191826, 0.0,       0.0,       0.0,       0.0, 1.4418638,
      0.0,       0.0,       0.0,       0.0,       0.0,       0.0, 0.0,
      0.0,       0.0,       0.0,       0.0,       2.4758773, 0.0, 0.0,
      1.4318929, 0.0,       0.0,       0.0,       0.0,       0.0, 0.0,
      0.0,       0.0,       0.0,       0.0,       1.3223611, 0.0, 0.0,
      1.6931027, 0.0,       1.1261737, 2.0562408, 0.0,       0.0, 0.0,
      0.0,       0.0,       0.0,       0.0};
  const float alpha = 0;
  ONNC_RUNTIME_thresholdedrelu_float(NULL, (float *)input_0, input_0_ndim,
                                     input_0_dims, (float *)output_0,
                                     output_0_ndim, output_0_dims, alpha);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
