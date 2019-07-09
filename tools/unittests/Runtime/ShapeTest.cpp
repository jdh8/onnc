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
SKYPAT_F(Operator_Shape, test_shape_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 3};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {2, 3};
  using dragonite::norm;

  ONNC_RUNTIME_shape_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_Shape, test_shape)
{
  const float input_0[] = {
    -1.1888592,  -0.5068163, -0.596314,    -0.052567296, -1.9362798,  0.1887786,   0.52389103,  0.08842209, -0.31088617,
    0.097400166, 0.39904633, -2.7725928,   1.9559124,    0.39009333,  -0.6524086,  -0.39095336, 0.49374178, -0.11610394,
    -2.0306845,  2.064493,   -0.11054066,  1.0201727,    -0.69204986, 1.5363771,   0.2863437,   0.60884386, -1.0452534,
    1.2111453,   0.68981814, 1.3018463,    -0.6280876,   -0.48102713, 2.3039167,   -1.0600158,  -0.1359497, 1.1368914,
    0.09772497,  0.5829537,  -0.39944902,  0.37005588,   -1.3065269,  1.6581306,   -0.11816405, -0.6801782, 0.6663831,
    -0.4607198,  -1.3342584, -1.3467175,   0.69377315,   -0.15957344, -0.13370156, 1.0777438,   -1.1268258, -0.7306777,
    -0.3848798,  0.09435159, -0.042171452, -0.2868872,   -0.0616264,  -0.10730527};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {3, 4, 5};
  using dragonite::norm;

  ONNC_RUNTIME_shape_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}
