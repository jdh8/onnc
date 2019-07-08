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
SKYPAT_F(Operator_Softplus, test_softplus_example) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {0.31326166, 0.6931472, 1.3132616};
  ONNC_RUNTIME_softplus_float(nullptr, input_0, input_0_ndim, input_0_dims,
                              output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Softplus, test_softplus) {
  const float input_0[] = {
      -0.99418634,  0.1693081,   -0.9317143,  -0.95436317, -0.6126065,
      0.32647568,   -0.8015695,  1.0485463,   -0.78157854, 1.3674835,
      -1.021426,    -0.20091408, 0.10255211,  -0.9636094,  -0.7346326,
      0.2468835,    -0.4661616,  -0.56726515, -0.4167721,  0.18280222,
      -0.83941734,  1.6634212,   -1.8836457,  0.039070506, -0.14878485,
      -0.35617557,  -1.401372,   0.61989075,  -1.6715639,  0.5220121,
      -0.10274029,  -0.53899425, -1.2783859,  -0.72132033, -2.3513112,
      0.6171728,    0.13809441,  0.5125415,   -1.2011199,  -0.596415,
      0.5951353,    0.23390697,  1.1006314,   0.4247358,   0.33724296,
      0.13893647,   1.4059438,   -0.4783534,  -0.6449186,  0.013150034,
      -0.037475996, -0.24361414, 0.8794044,   0.38726348,  -0.504255,
      2.1577015,    -0.5692857,  0.5889864,   -0.85190994, -0.540621};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.31482857, 0.78138006, 0.3320897,  0.32574144, 0.43303904,  0.8696496,
      0.37061432, 1.3489819,  0.37684816, 1.5944177,  0.30754432,  0.5977275,
      0.74573725, 0.32317954, 0.39182702, 0.8241886,  0.48698726,  0.4492103,
      0.50631815, 0.7887195,  0.35904562, 1.8369455,  0.14152984,  0.7128732,
      0.62151927, 0.53083384, 0.22014615, 1.0503757,  0.17223155,  0.98783547,
      0.6430959,  0.45953318, 0.24567695, 0.39616194, 0.090977326, 1.0486094,
      0.76457626, 0.98190206, 0.26302332, 0.43875974, 1.0343498,   0.81692415,
      1.387809,   0.92789763, 0.8759184,  0.76502645, 1.6251882,   0.48230466,
      0.42180106, 0.69974387, 0.6745847,  0.5787403,  1.2265552,   0.9054096,
      0.4724726,  2.2670853,  0.4484796,  1.0303909,  0.35529357,  0.45893416};
  ONNC_RUNTIME_softplus_float(nullptr, input_0, input_0_ndim, input_0_dims,
                              output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
