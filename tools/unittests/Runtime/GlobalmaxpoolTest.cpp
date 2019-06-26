#include "dragonite.hpp"
SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool) {
  const float input_0[] = {
      1.1108521,    -0.50862503, -1.9040097,   0.1331632,   -0.8712103,
      -0.56641287,  0.30302185,  0.60263467,   0.17543401,  1.1548538,
      0.12736987,   0.14465179,  -0.3660881,   -1.2313704,  -1.7279515,
      -0.11797951,  0.20669039,  -0.104380004, -1.3352494,  0.91737807,
      0.4346684,    0.6458108,   1.0684626,    0.6599948,   -1.7442441,
      0.89103776,   -0.22473164, -1.3528008,   -1.5692697,  -0.5895785,
      -1.1487094,   2.3246582,   0.29465395,   -1.2847518,  -0.066621855,
      0.9597055,    1.9399793,   0.30650204,   0.041833814, -0.77056676,
      0.0018871854, -0.14570256, -0.96206015,  -0.43955913, -0.15048596,
      0.5083416,    0.34059465,  -0.16138114,  2.9060051,   0.087026924,
      -1.7481132,   0.73722845,  -0.5751749,   -0.39055324, -0.8327984,
      0.09218807,   0.6879098,   0.03604427,   0.13612105,  -0.2114216,
      -3.3439965,   -2.256245,   -1.3305064,   -0.8161114,  -0.22423926,
      0.080074415,  -1.261829,   0.1633435,    -0.91764873, 1.3786488,
      -0.32507843,  -1.3298937,  -0.7056289,   0.3046201,   1.1106795};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float output_0[3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float answer_0[] = {1.1548538, 2.9060051, 1.3786488};
  ONNC_RUNTIME_globalmaxpool_float(NULL, (float *)input_0, input_0_ndim,
                                   input_0_dims, (float *)output_0,
                                   output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_GlobalMaxPool, test_globalmaxpool_precomputed) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float output_0[1];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float answer_0[] = {9.0};
  ONNC_RUNTIME_globalmaxpool_float(NULL, (float *)input_0, input_0_ndim,
                                   input_0_dims, (float *)output_0,
                                   output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 1);
}
