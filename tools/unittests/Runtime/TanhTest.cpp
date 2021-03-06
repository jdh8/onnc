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
SKYPAT_F(Operator_Tanh, test_tanh_example)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-0.7615942, 0.0, 0.7615942};
  using dragonite::norm;

  ONNC_RUNTIME_tanh_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Tanh, test_tanh)
{
  const float input_0[] = {
    0.98375386,  -1.2820144,  0.13519306,  0.6331491,   -1.5421017,  0.67494166, -0.20721789, -0.5185943,   -0.8349758,
    0.13292639,  -0.82783204, 0.32504863,  -0.19011904, -1.3022875,  -0.8030197, -0.31279936, 0.8481064,    0.63380635,
    -1.7681301,  0.45088434,  -1.9207954,  -0.2770696,  0.5079254,   0.36216995, 1.4516346,   -0.14148682,  0.5839625,
    -0.4693566,  -1.2050556,  -1.5795416,  1.4682328,   -1.7315389,  -1.5170012, -1.2681711,  1.2322577,    0.64322525,
    2.4273458,   -0.9885513,  -0.32979986, 0.9660173,   -0.81667733, 0.07173572, 3.2410848,   0.0029021087, 0.3249057,
    -0.17111921, 0.0084633,   0.8049784,   0.31878135,  0.35305452,  0.74476385, 0.35783708,  1.635966,     0.6395814,
    -1.0041945,  0.94488883,  -1.752978,   0.5872289,   -2.0669909,  0.38325205};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.75468636,  -0.8570207,  0.1343754,   0.56021684,  -0.91247284, 0.5882211,  -0.20430204, -0.4766144,   -0.68313867,
    0.13214897,  -0.6793102,  0.31406474,  -0.18786106, -0.8623109,  -0.6657216, -0.30298164, 0.690079,     0.56066763,
    -0.94340414, 0.4226257,   -0.9579828,  -0.27019078, 0.46832722,  0.34712395, 0.89601564,  -0.1405502,   0.5255395,
    -0.43767932, -0.8351902,  -0.9185303,  0.8992398,   -0.93923753, -0.9081736, -0.85330117, 0.843233,     0.5670916,
    0.984537,    -0.75674385, -0.31834093, 0.74694896,  -0.67325735, 0.07161292, 0.9969437,   0.0029021006, 0.3139359,
    -0.16946833, 0.008463099, 0.6668107,   0.30840456,  0.33908165,  0.63201475, 0.3433074,   0.9269065,    0.5646144,
    -0.7633501,  0.7374604,   -0.9417135,  0.5278997,   -0.9684672,  0.36552837};
  using dragonite::norm;

  ONNC_RUNTIME_tanh_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
