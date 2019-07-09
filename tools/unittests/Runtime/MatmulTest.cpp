#if defined(__GNUC__) || defined(_MSC_VER)
#  define restrict __restrict
#else
#  define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "norm.hpp"
#include <skypat/skypat.h>
SKYPAT_F(Operator_MatMul, test_matmul_2d)
{
  const float   input_0[]      = {-0.008294905, -0.63457507,   -0.83644974, -1.1903107, 0.58942336, -0.34685987,
                           -0.20703343,  -0.0048542777, -0.7245176,  0.7261179,  1.765979,   1.1180466};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {3, 4};
  const float   input_1[]      = {-0.7394892, -1.9920754, 0.53761566, -1.5022421,  0.69265175, 0.37760183,
                           -1.3882775, 1.352577,   -0.5169479, -0.17916866, 0.3557394,  0.75503236};
  const int32_t input_1_ndim   = 2;
  const int32_t input_1_dims[] = {4, 3};
  float         output_0[9];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 3};
  const float   answer_0[]      = {2.3339102,  -1.9778186, -0.7103983, 0.37348488, -1.6961844,
                            0.28926867, -3.2070198, 4.7325964,  -0.18408632};
  using dragonite::norm;

  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 9) <= 1e-5 * norm(answer_0, 9));
}

SKYPAT_F(Operator_MatMul, test_matmul_3d)
{
  const float   input_0[]      = {-0.5453607,  -1.1388996, 0.01280704, 0.9979778,   -0.34908712, 0.6629648,
                           -0.49933523, -0.1290609, -0.6041059, 0.29752067,  -0.55545527, 0.5039275,
                           -1.6360711,  -0.5152972, -0.7070577, -0.25371286, -0.07051506, -0.14115863,
                           -1.1116796,  0.3600579,  -2.0484624, -0.26342133, -0.2657422,  -0.34349093};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float   input_1[]      = {-1.0433068,   1.1382184,   -2.394284,   -0.7989753, -0.81662756, 0.64114434,
                           -0.056231525, -0.70690477, -0.81555504, -0.6326619, 0.57774013,  -0.12134374,
                           0.14853188,   0.20065041,  -0.26198277, 0.7879915,  0.49142462,  1.7277789,
                           -1.0514793,   -0.99894506, -1.3430707,  -1.3588917, 2.2248862,   -1.5897866};
  const int32_t input_1_ndim   = 3;
  const int32_t input_1_dims[] = {2, 4, 3};
  float         output_0[18];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {2, 3, 3};
  const float   answer_0[]      = {0.8468285,  0.8768357,   0.44400617, -0.055757258, -0.66031396, 1.683766,
                            0.10497448, -0.24677482, 2.0290108,  0.43916637,   -0.43967846, 0.8912807,
                            0.5579229,  1.828077,    0.6952319,  0.23435368,   -1.0392429,  0.98451596};
  using dragonite::norm;

  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 18) <= 1e-5 * norm(answer_0, 18));
}

SKYPAT_F(Operator_MatMul, test_matmul_4d)
{
  const float   input_0[]      = {2.068653,   1.7012184,  -0.19271667, 0.8974684, -1.4228466,   1.8088626,
                           1.0567559,  1.7644281,  -0.07419261, 0.9066494, -0.013879086, 0.37155458,
                           0.01567543, -1.6299242, -0.15278281, 1.7150968, -0.18101579,  -0.23841661,
                           0.50333625, 3.709961,   0.12664104,  -0.270319, -0.67654234,  -0.83327883};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 2, 3, 4};
  const float   input_1[]      = {-1.1081797, -0.5698983,  0.111943185, -0.45830956, -0.40401804, 0.12926868,
                           1.2145712,  0.117842056, -0.06284722, 0.4740816,   -0.582744,   -0.47095633,
                           -1.47947,   0.37879986,  0.25821328,  -1.4235415,  -1.3822632,  0.36049825,
                           -0.7115287, -0.30264148, -1.0752355,  -0.59398043, -0.11819958, 0.0039658025};
  const int32_t input_1_ndim   = 4;
  const int32_t input_1_dims[] = {1, 2, 4, 3};
  float         output_0[18];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 2, 3, 3};
  const float   answer_0[]      = {-2.880719,   -2.4119494,  0.04092915,  2.867739,  -0.8236149, -0.82283145,
                            -0.17401731, -0.54217726, -0.06521771, 1.3870487, 2.1024368,  -0.412458,
                            -1.954579,   -0.3298605,  -0.6591815,  1.1737794, 0.7248666,  0.6593886};
  using dragonite::norm;

  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 18) <= 1e-5 * norm(answer_0, 18));
}
