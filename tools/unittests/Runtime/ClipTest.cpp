#include "dragonite.hpp"
SKYPAT_F(Operator_Clip, test_clip_example) {
  const float input_0[] = {-2.0, 0.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float max = 1.0;
  const float min = -1.0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Clip, test_clip) {
  const float input_0[] = {
      -0.097284995, 1.4035168,   1.604231,     -0.01857569, 0.035718538,
      0.086084105,  -1.2625693,  0.109889284,  -0.14681609, 0.2233651,
      0.4372152,    -1.0207704,  -0.3067885,   1.5544322,   -1.068754,
      -0.36112285,  0.28753182,  -0.048439637, 1.2752683,   0.11753812,
      -0.25573483,  -0.49479836, 1.4287522,    0.550216,    -1.2184592,
      -0.09040343,  0.10797042,  0.70214283,   -0.18447202, -0.24325554,
      -0.9384506,   0.59353364,  1.6613083,    -0.21141283, 1.1763661,
      0.37343347,   -0.2617302,  0.22169974,   -2.119753,   -0.39760432,
      0.5309557,    -0.21965936, 0.5484184,    0.37482378,  0.082797624,
      0.9867178,    -0.401679,   -0.4418462,   0.3323249,   -0.593479,
      0.68827957,   -0.692134,   0.40603855,   0.33020136,  -1.1804452,
      0.4564397,    0.62036455,  -0.66289383,  -0.15586828, -1.9125907};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -0.097284995, 1.0,         1.0,          -0.01857569, 0.035718538,
      0.086084105,  -1.0,        0.109889284,  -0.14681609, 0.2233651,
      0.4372152,    -1.0,        -0.3067885,   1.0,         -1.0,
      -0.36112285,  0.28753182,  -0.048439637, 1.0,         0.11753812,
      -0.25573483,  -0.49479836, 1.0,          0.550216,    -1.0,
      -0.09040343,  0.10797042,  0.70214283,   -0.18447202, -0.24325554,
      -0.9384506,   0.59353364,  1.0,          -0.21141283, 1.0,
      0.37343347,   -0.2617302,  0.22169974,   -1.0,        -0.39760432,
      0.5309557,    -0.21965936, 0.5484184,    0.37482378,  0.082797624,
      0.9867178,    -0.401679,   -0.4418462,   0.3323249,   -0.593479,
      0.68827957,   -0.692134,   0.40603855,   0.33020136,  -1.0,
      0.4564397,    0.62036455,  -0.66289383,  -0.15586828, -1.0};
  const float max = 1.0;
  const float min = -1.0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Clip, test_clip_inbounds) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Clip, test_clip_outbounds) {
  const float input_0[] = {-6.0, 0.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-5.0, 0.0, 5.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Clip, test_clip_splitbounds) {
  const float input_0[] = {-1.0, 0.0, 6.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 5.0};
  const float max = 5.0;
  const float min = -5.0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Clip, test_clip_default_min) {
  const float input_0[] = {
      0.61561185,  0.17848754,   -1.363732,   0.73498774,  -1.4976889,
      0.7183725,   -0.6165364,   0.5213463,   -1.0140219,  0.52055544,
      0.21790993,  -0.090934195, 0.3978978,   -0.73660785, 1.1260245,
      -1.5227324,  0.88249695,   -1.222097,   -0.04160058, 1.2228914,
      -1.9957697,  0.4871925,    -0.04520218, 0.09134163,  0.93604285,
      1.2240924,   0.56457597,   0.09715928,  0.8628421,   -0.44086584,
      1.2812839,   -0.30811122,  -0.7045929,  0.49588993,  0.13818836,
      -0.23194678, 1.7541915,    0.9403252,   -1.4946761,  0.7349496,
      0.80846846,  0.46831575,   0.76866156,  -0.16291127, -0.8995203,
      0.49652153,  -0.7849607,   -0.30586156, -2.7800734,  0.95743793,
      -1.1573584,  0.90545064,   0.11252238,  -0.8342292,  1.4103576,
      -0.8996004,  0.32259354,   -1.6521775,  -0.7228457,  1.8037049};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.61561185, 0.17848754, 0.0,        0.73498774, 0.0,        0.7183725,
      0.0,        0.5213463,  0.0,        0.52055544, 0.21790993, 0.0,
      0.3978978,  0.0,        1.1260245,  0.0,        0.88249695, 0.0,
      0.0,        1.2228914,  0.0,        0.4871925,  0.0,        0.09134163,
      0.93604285, 1.2240924,  0.56457597, 0.09715928, 0.8628421,  0.0,
      1.2812839,  0.0,        0.0,        0.49588993, 0.13818836, 0.0,
      1.7541915,  0.9403252,  0.0,        0.7349496,  0.80846846, 0.46831575,
      0.76866156, 0.0,        0.0,        0.49652153, 0.0,        0.0,
      0.0,        0.95743793, 0.0,        0.90545064, 0.11252238, 0.0,
      1.4103576,  0.0,        0.32259354, 0.0,        0.0,        1.8037049};
  const float min = 0.0;
  const float max = 0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Clip, test_clip_default_max) {
  const float input_0[] = {
      2.8680763,   1.2629522,   0.8386337,    -0.4128632,  1.0171244,
      0.579939,    0.33999768,  -0.056139853, -0.75162786, 1.0810103,
      1.1834533,   -1.6407746,  -1.204921,    1.5920027,   1.7174363,
      -1.4218421,  1.9773065,   -0.5984477,   -0.5968509,  -0.18173915,
      -0.30215943, -0.06374156, -0.47315046,  -1.2098138,  1.3102982,
      0.9498722,   0.7674883,   -1.1460315,   0.70226514,  -0.2274111,
      0.43859574,  -1.8013669,  0.64105684,   -1.1356037,  1.7284172,
      -0.5803323,  0.14695768,  -0.5717276,   -1.1869935,  -1.2636845,
      -0.26949403, -2.069946,   0.13991709,   -0.24619967, -0.3347747,
      -1.4473034,  0.055540025, -0.4075459,   0.52171266,  -0.43554786,
      -1.060476,   1.3590723,   0.7367595,    1.3152773,   0.37555873,
      -1.6982669,  0.50706196,  -2.525931,    1.1522734,   -0.80781657};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.0,         0.0,         0.0,          -0.4128632,  0.0,
      0.0,         0.0,         -0.056139853, -0.75162786, 0.0,
      0.0,         -1.6407746,  -1.204921,    0.0,         0.0,
      -1.4218421,  0.0,         -0.5984477,   -0.5968509,  -0.18173915,
      -0.30215943, -0.06374156, -0.47315046,  -1.2098138,  0.0,
      0.0,         0.0,         -1.1460315,   0.0,         -0.2274111,
      0.0,         -1.8013669,  0.0,          -1.1356037,  0.0,
      -0.5803323,  0.0,         -0.5717276,   -1.1869935,  -1.2636845,
      -0.26949403, -2.069946,   0.0,          -0.24619967, -0.3347747,
      -1.4473034,  0.0,         -0.4075459,   0.0,         -0.43554786,
      -1.060476,   0.0,         0.0,          0.0,         0.0,
      -1.6982669,  0.0,         -2.525931,    0.0,         -0.80781657};
  const float max = 0.0;
  const float min = 0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Clip, test_clip_default_inbounds) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-1.0, 0.0, 1.0};
  const float max = 0;
  const float min = 0;
  ONNC_RUNTIME_clip_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, max,
                          min);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}
