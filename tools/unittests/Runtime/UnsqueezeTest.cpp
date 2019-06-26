#include "dragonite.hpp"
SKYPAT_F(Operator_Unsqueeze, test_unsqueeze) {
  const float input_0[] = {
      0.25103298,   1.9907645,   -0.50649273, -0.41432554, -0.90995455,
      -1.8482025,   1.1760192,   -1.1112282,  -1.0812603,  -1.3037704,
      0.68945444,   1.1012219,   -1.2982657,  -0.1724577,  -0.03848034,
      0.1072734,    0.33251804,  0.36555624,  0.35380596,  0.637341,
      -0.23344769,  1.4356592,   2.7932954,   -0.05010172, -0.51358616,
      -0.13521065,  1.1704459,   -0.8636149,  -0.5207951,  1.1828113,
      -0.092760555, -0.75096923, 1.557112,    0.26666638,  -0.43884456,
      -0.6716278,   -0.777102,   -0.4503863,  -0.20067807, 0.63484424,
      1.1298783,    -0.3281957,  -1.628509,   -1.6414441,  -1.5863247,
      -1.0541013,   0.030719424, 0.45953855,  -0.23724648, 2.5060976,
      1.7848371,    1.4579588,   1.8381162,   -1.8047457,  -1.0535622,
      1.442132,     -0.60355115, 1.1616627,   -0.99438196, -0.5216019};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 3, 4, 5};
  const float answer_0[] = {
      0.25103298,   1.9907645,   -0.50649273, -0.41432554, -0.90995455,
      -1.8482025,   1.1760192,   -1.1112282,  -1.0812603,  -1.3037704,
      0.68945444,   1.1012219,   -1.2982657,  -0.1724577,  -0.03848034,
      0.1072734,    0.33251804,  0.36555624,  0.35380596,  0.637341,
      -0.23344769,  1.4356592,   2.7932954,   -0.05010172, -0.51358616,
      -0.13521065,  1.1704459,   -0.8636149,  -0.5207951,  1.1828113,
      -0.092760555, -0.75096923, 1.557112,    0.26666638,  -0.43884456,
      -0.6716278,   -0.777102,   -0.4503863,  -0.20067807, 0.63484424,
      1.1298783,    -0.3281957,  -1.628509,   -1.6414441,  -1.5863247,
      -1.0541013,   0.030719424, 0.45953855,  -0.23724648, 2.5060976,
      1.7848371,    1.4579588,   1.8381162,   -1.8047457,  -1.0535622,
      1.442132,     -0.60355115, 1.1616627,   -0.99438196, -0.5216019};
  const int32_t axes[] = {0};
  const int32_t number_of_axes = 1;
  ONNC_RUNTIME_unsqueeze_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)axes, number_of_axes);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
