#include "dragonite.hpp"
SKYPAT_F(Operator_Shape, test_shape_example) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 3};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {2, 3};
  ONNC_RUNTIME_shape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_Shape, test_shape) {
  const float input_0[] = {
      -0.27020895, -0.3368473, 1.4482629,   -1.250352,   0.6832783,
      0.22915003,  2.1718554,  0.117759295, -0.06217433, -0.69441384,
      0.9643481,   -0.2812136, -1.2346522,  1.0559924,   0.092566915,
      -0.7005651,  2.4513535,  1.3264627,   -1.4323947,  0.055936232,
      1.1565071,   -1.3905009, 0.5088351,   0.3627538,   0.59624034,
      1.8282002,   0.444331,   -0.6819063,  -0.38698116, 0.27155623,
      0.66394657,  0.15712784, -0.09431352, 1.2035366,   0.26209533,
      0.31010932,  1.610613,   1.5494205,   -0.63629985, -0.098678306,
      -0.9409592,  -3.049581,  -0.55394614, -0.13521536, -0.77464306,
      0.6220127,   0.15027,    -0.52923954, -0.16341515, 1.693823,
      -1.1168956,  2.3427658,  0.54069865,  0.20307669,  -0.48165748,
      -0.6570333,  -0.5915634, -0.11655856, -0.31214324, 0.7497531};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {3, 4, 5};
  ONNC_RUNTIME_shape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}
