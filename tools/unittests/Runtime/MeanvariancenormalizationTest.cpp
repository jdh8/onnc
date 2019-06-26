#include "dragonite.hpp"
SKYPAT_F(Operator_MeanVarianceNormalization, test_mvn) {
  const float input_0[] = {
      0.8439683,  0.5665144,  0.05836735, 0.02916367, 0.12964272, 0.5060197,
      0.79538304, 0.9411346,  0.9546573,  0.17730942, 0.46192095, 0.26480448,
      0.6746842,  0.01665257, 0.62473077, 0.9240844,  0.9722341,  0.11965699,
      0.41356155, 0.9129373,  0.59330076, 0.81929934, 0.7862604,  0.11799799,
      0.69248444, 0.54119414, 0.07513223};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {3, 3, 3, 1};
  float output_0[27];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {3, 3, 3, 1};
  const float answer_0[] = {
      1.3546423,   0.33053496, -1.5450814, -1.2106764, -0.8925952,  0.29888135,
      0.38083088,  0.81808794, 0.85865635, -1.1060555, -0.05552877, -0.78310335,
      0.83281356,  -1.250282,  0.67467856, 0.7669372,  0.9113869,   -1.6463585,
      -0.23402764, 1.6092131,  0.42940593, 1.2906139,  1.1860244,   -0.92945826,
      0.0721334,   -0.38174,   -1.7799333};
  const int32_t normalize_variance = 0;
  const int32_t across_channels = 0;
  ONNC_RUNTIME_meanvariancenormalization_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, across_channels, normalize_variance);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 27);
}
