#include "dragonite.hpp"
SKYPAT_F(Operator_Squeeze, test_squeeze) {
  const float input_0[] = {
      -1.0381724,  0.4956069,    0.11083887,  -0.6853112,   0.19874889,
      -0.10599323, -1.113229,    -1.2634276,  0.18231235,   -0.5584282,
      -1.4822329,  0.8337081,    -1.183899,   -0.15408282,  -0.9909485,
      2.6176524,   0.44801223,   1.5105166,   -0.09716444,  -0.7111858,
      0.053202175, -0.7121265,   -1.4674125,  -1.6173884,   -0.45028162,
      -0.75942117, 0.13748944,   -0.5579511,  0.46887374,   1.37525,
      0.69760484,  -1.4801731,   2.0290856,   1.3359835,    0.29077026,
      1.6883172,   -0.87793195,  0.8778989,   -0.7700269,   -0.9246355,
      1.3252969,   0.051304106,  -1.5843589,  0.0066239526, 0.35127482,
      -1.3136128,  -0.038673855, 0.37181345,  -0.31691346,  -0.99084705,
      0.28769755,  0.20534128,   -0.09486767, 0.5756317,    -1.2029047,
      -0.60863054, -0.4666339,   -1.3360726,  -0.3810428,   -0.41002372};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -1.0381724,  0.4956069,    0.11083887,  -0.6853112,   0.19874889,
      -0.10599323, -1.113229,    -1.2634276,  0.18231235,   -0.5584282,
      -1.4822329,  0.8337081,    -1.183899,   -0.15408282,  -0.9909485,
      2.6176524,   0.44801223,   1.5105166,   -0.09716444,  -0.7111858,
      0.053202175, -0.7121265,   -1.4674125,  -1.6173884,   -0.45028162,
      -0.75942117, 0.13748944,   -0.5579511,  0.46887374,   1.37525,
      0.69760484,  -1.4801731,   2.0290856,   1.3359835,    0.29077026,
      1.6883172,   -0.87793195,  0.8778989,   -0.7700269,   -0.9246355,
      1.3252969,   0.051304106,  -1.5843589,  0.0066239526, 0.35127482,
      -1.3136128,  -0.038673855, 0.37181345,  -0.31691346,  -0.99084705,
      0.28769755,  0.20534128,   -0.09486767, 0.5756317,    -1.2029047,
      -0.60863054, -0.4666339,   -1.3360726,  -0.3810428,   -0.41002372};
  const int32_t axes[] = {0};
  const int32_t number_of_axes = 1;
  ONNC_RUNTIME_squeeze_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             (int32_t *)axes, number_of_axes);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
