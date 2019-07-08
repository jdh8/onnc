#if defined(__GNUC__) || defined(_MSC_VER)
#define restrict __restrict
#else
#define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "relative-error.hpp"
#include <skypat/skypat.h>
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
  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                         input_1_ndim, input_1_dims, output_0, output_0_ndim,
                         output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Pow, test_pow) {
  const float input_0[] = {
      0.7187216,   0.83636355,  0.4566662,  0.8083297,  0.38499862,
      0.8835876,   0.54020095,  0.09374585, 0.7898192,  0.22988552,
      0.60719264,  0.28467217,  0.9033413,  0.3727576,  0.6613447,
      0.86066276,  0.010724311, 0.13556401, 0.4880369,  0.39412993,
      0.4538708,   0.49318,     0.37646568, 0.19849896, 0.8070761,
      0.9870278,   0.47417292,  0.36241168, 0.87530035, 0.059916887,
      0.1965397,   0.083527215, 0.6928565,  0.17467432, 0.21440557,
      0.9942929,   0.7397368,   0.6272373,  0.6418514,  0.43002114,
      0.33250096,  0.06775431,  0.5161105,  0.99360174, 0.81369334,
      0.010537519, 0.4796869,   0.99624485, 0.3219183,  0.39630836,
      0.70691967,  0.6285696,   0.21758434, 0.9487333,  0.4357995,
      0.14027199,  0.6019191,   0.4870104,  0.6209268,  0.1957459};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {
      -2.1371045, -3.6073236, -4.2200613, 9.436621,   5.865093,   0.50167066,
      3.3570468,  6.0752845,  -9.97372,   -3.8456316, -5.591248,  0.23955156,
      -4.768462,  9.189757,   -9.148638,  6.206083,   4.950026,   8.32568,
      -1.2121348, 1.8534042,  -3.8747149, 3.462381,   -7.6170135, -2.0875578,
      -9.437669,  3.1105638,  -5.7957945, 8.122358,   -8.461665,  -0.4118515,
      -5.717552,  3.1987474,  9.175223,   0.17398097, -7.038374,  -6.1988435,
      4.5543447,  -1.0924938, 3.4769402,  -6.9189296, 6.78438,    -9.314884,
      1.9313705,  6.042848,   -2.1081753, 6.62078,    -5.731315,  -4.8501215,
      -7.074959,  6.171658,   -9.522131,  0.86035174, 5.4426117,  1.935661,
      -4.4659214, -6.8130984, -7.0538316, -6.5621705, 4.8858337,  -8.413992};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      2.0255582,     1.9052237,     27.322073,     0.13426045,    0.0037040717,
      0.9397991,     0.12652484,    5.6795807E-07, 10.52035,      285.3587,
      16.273289,     0.740095,      1.6237483,     0.00011521625, 43.937996,
      0.39406538,    1.7794148E-10, 5.9499367E-08, 2.3858185,     0.17805591,
      21.344683,     0.08651033,    1704.9255,     29.239521,     7.559799,
      0.96019894,    75.5447,       0.0002628344,  3.0863647,     3.1876318,
      10958.09,      0.00035579523, 0.034503773,   0.73818,       50934.344,
      1.0361155,     0.25335678,    1.6645789,     0.21402343,    343.44583,
      0.00056971994, 77568780000.0, 0.27874026,    0.96195465,    1.5444164,
      8.109346E-14,  67.38002,      1.0184147,     3038.6387,     0.0033052065,
      27.184288,     0.67067635,    0.00024829298, 0.9031478,     40.824142,
      648292.2,      35.90053,      112.31233,     0.09746077,    911364.5};
  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                         input_1_ndim, input_1_dims, output_0, output_0_ndim,
                         output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
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
  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                         input_1_ndim, input_1_dims, output_0, output_0_ndim,
                         output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
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
  ONNC_RUNTIME_pow_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1,
                         input_1_ndim, input_1_dims, output_0, output_0_ndim,
                         output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 6) < 1e-5f);
}
