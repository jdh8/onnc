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
SKYPAT_F(Operator_Acos, test_acos_example)
{
  const float   input_0[]      = {-0.5, 0.0, 0.5};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {2.0943952, 1.5707964, 1.0471976};
  using dragonite::norm;

  ONNC_RUNTIME_acos_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Acos, test_acos)
{
  const float input_0[] = {
    0.73113567,  0.26416343, 0.6920659,  0.33569285, 0.34443334,   0.51768905, 0.19671594,  0.2059253,  0.672038,
    0.9834207,   0.03886664, 0.4614788,  0.57371217, 0.0058804164, 0.14355917, 0.051053125, 0.17305413, 0.2582185,
    0.88770694,  0.7583922,  0.7841127,  0.564184,   0.28347254,   0.9350743,  0.9873869,   0.26016983, 0.82358336,
    0.632567,    0.67686945, 0.16534552, 0.29346997, 0.07074824,   0.73356766, 0.37798387,  0.4806514,  0.35177773,
    0.4680412,   0.18070352, 0.9680137,  0.5503872,  0.84283143,   0.48478314, 0.09665174,  0.6294559,  0.9660135,
    0.024701698, 0.3862894,  0.21556823, 0.6538985,  0.6705687,    0.5682154,  0.9992177,   0.19298105, 0.03580451,
    0.21308793,  0.93244976, 0.33234328, 0.59875345, 0.54648995,   0.49367672};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.7508112,  1.3034599,  0.8064492,  1.2284557,  1.2191613, 1.0266486,  1.372789,   1.3633871,  0.8338388,
    0.18234739, 1.53192,    1.0911349,  0.9597654,  1.5649159, 1.4267395,  1.519721,   1.3968666,  1.3096186,
    0.4784558,  0.7099534,  0.6695312,  0.97135174, 1.2833831, 0.3623276,  0.1589951,  1.3075982,  0.6030963,
    0.8859332,  0.82729495, 1.404688,   1.2729417,  1.4999889, 0.74723965, 1.1831787,  1.0693989,  1.2113268,
    1.0837234,  1.3890946,  0.25360712, 0.9879684,  0.5682734, 1.064681,   1.4739934,  0.88994354, 0.26146045,
    1.5460922,  1.174191,   1.3535227,  0.85807055, 0.8358212, 0.96646076, 0.03955788, 1.3765969,  1.5349841,
    1.3560619,  0.36966133, 1.2320093,  0.9288525,  0.9926291, 1.0544838};
  using dragonite::norm;

  ONNC_RUNTIME_acos_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
