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
SKYPAT_F(Operator_Gemm, test_gemm_broadcast)
{
  const float   input_0[]      = {0.09726671, 0.5526056,   0.30932185, 0.86059046,  0.8516144,  0.76192,
                           0.5594452,  0.44094223,  0.30033663, 0.6920929,   0.78851694, 0.18976663,
                           0.9402294,  0.018920893, 0.29326838, 0.016584922, 0.2939036,  0.08979926};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {6, 3};
  const float   input_1[]      = {0.0708261,  0.46580493, 0.8821366, 0.509595,   0.38246855,  0.12485177,
                           0.10939783, 0.32914594, 0.4156529, 0.8822656,  0.013654842, 0.8975683,
                           0.41210964, 0.35971215, 0.5302765, 0.8888528,  0.3455444,   0.46436903,
                           0.30941764, 0.66593033, 0.9164872, 0.87567854, 0.78986907,  0.23158441};
  const int32_t input_1_ndim   = 2;
  const int32_t input_1_dims[] = {4, 6};
  const float   input_2[]      = {0.29204592};
  const int32_t input_2_ndim   = 2;
  const int32_t input_2_dims[] = {1, 1};
  float         output_0[12];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float   answer_0[]      = {0.95383763, 0.7284081, 0.9430586, 1.3802547,  0.7812988, 0.8879112,
                            0.9519153,  1.1038808, 0.5769398, 0.47676688, 0.5822828, 0.79450506};
  const float   alpha           = 0.5;
  const float   beta            = 0.5;
  const int32_t transA          = 1;
  const int32_t transB          = 1;
  using dragonite::norm;

  ONNC_RUNTIME_gemm_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2,
                          input_2_ndim, input_2_dims, output_0, output_0_ndim, output_0_dims, alpha, beta, transA,
                          transB);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}

SKYPAT_F(Operator_Gemm, test_gemm_nobroadcast)
{
  const float   input_0[]      = {0.21042912, 0.9021981, 0.0022635101, 0.7693435,  0.4019982,  0.33236808,
                           0.12718774, 0.8315533, 0.6404093,    0.52226555, 0.5521724,  0.41300014,
                           0.87771344, 0.9156706, 0.83658886,   0.69985485, 0.35341492, 0.48195487};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {3, 6};
  const float   input_1[]      = {0.43823907, 0.42069238, 0.032467082, 0.6378068,  0.45603573, 0.97489685,
                           0.90468746, 0.64566535, 0.69449663,  0.8083571,  0.06670371, 0.49581495,
                           0.49610436, 0.63419354, 0.30422795,  0.5963361,  0.4646793,  0.7821046,
                           0.51808757, 0.6556823,  0.32782024,  0.16268937, 0.70438206, 0.9371933};
  const int32_t input_1_ndim   = 2;
  const int32_t input_1_dims[] = {6, 4};
  const float   input_2[]      = {0.96119714, 0.5581337, 0.84164995, 0.42694533, 0.6285567, 0.3183158,
                           0.31183082, 0.9428243, 0.33104822, 0.51418436, 0.9545682, 0.6199904};
  const int32_t input_2_ndim   = 2;
  const int32_t input_2_dims[] = {3, 4};
  float         output_0[12];
  const int32_t output_0_ndim   = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float   answer_0[]      = {1.0719268, 1.1922147, 1.1706402, 1.0893312, 1.0796733, 1.2652227,
                            0.9234226, 1.4694659, 1.1918517, 1.6255193, 1.3013799, 1.6432868};
  const float   alpha           = 0.5;
  const float   beta            = 0.5;
  const int32_t transB          = 0;
  const int32_t transA          = 0;
  using dragonite::norm;

  ONNC_RUNTIME_gemm_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, input_2,
                          input_2_ndim, input_2_dims, output_0, output_0_ndim, output_0_dims, alpha, beta, transA,
                          transB);
  ASSERT_TRUE(norm(answer_0, output_0, 12) <= 1e-5 * norm(answer_0, 12));
}
