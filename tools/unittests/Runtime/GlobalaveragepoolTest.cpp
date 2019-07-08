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
SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool) {
  const float input_0[] = {
      1.6401407,    0.13088968,  -1.7248006,  -0.5246704,  0.99952954,
      0.2900597,    0.45887282,  0.5196645,   -0.5758081,  -0.54961014,
      -0.028943341, -1.24119,    -0.30307594, -1.1159651,  1.2983557,
      -0.593217,    -0.36083367, -0.852769,   -0.52732015, 0.17490217,
      -0.7696541,   0.27141672,  2.0218093,   0.72446114,  -0.19528002,
      2.2217653,    1.4480901,   -0.79936427, 0.94528776,  0.9498039,
      -0.49650326,  -0.73415035, -1.2013701,  -0.9932719,  1.1291307,
      0.24714912,   0.47308603,  -0.5543239,  -1.2204233,  0.80585176,
      -0.16192402,  -2.1681156,  0.9881891,   -0.49794716, 1.0227717,
      1.6700189,    2.5943403,   -2.4973605,  1.0013971,   -0.6953411,
      1.6683215,    0.8725899,   0.60791445,  0.25763068,  -0.46957275,
      -0.3900968,   -1.1024469,  1.2371362,   -0.24951705, -0.14969225,
      0.7895383,    1.2417343,   0.16107766,  1.0747708,   -0.31111073,
      1.5004884,    1.9278221,   -0.43635896, -1.4578547,  1.1790007,
      -0.370716,    -0.17857827, 1.894683,    -1.1158268,  -1.2674353};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 3, 5, 5};
  float output_0[3];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 3, 1, 1};
  const float answer_0[] = {-0.033321436, 0.13907146, 0.27654007};
  ONNC_RUNTIME_globalaveragepool_float(nullptr, input_0, input_0_ndim,
                                       input_0_dims, output_0, output_0_ndim,
                                       output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_GlobalAveragePool, test_globalaveragepool_precomputed) {
  const float input_0[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 3, 3};
  float output_0[1];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 1, 1};
  const float answer_0[] = {5.0};
  ONNC_RUNTIME_globalaveragepool_float(nullptr, input_0, input_0_ndim,
                                       input_0_dims, output_0, output_0_ndim,
                                       output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 1) < 1e-5f);
}
