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
SKYPAT_F(Operator_Floor, test_floor_example)
{
  const float   input_0[]      = {-1.5, 1.2, 2.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-2.0, 1.0, 2.0};
  using dragonite::norm;

  ONNC_RUNTIME_floor_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Floor, test_floor)
{
  const float input_0[] = {
    -1.461132,   -0.31795096, 0.84445935, 0.5079457,   2.3881729,   -0.6780156, 1.2917769,   -1.2893934,  0.61905086,
    1.6932256,   -0.20864756, 0.79699874, -0.8534618,  1.9506932,   0.49944407, -0.76607263, 1.0182759,   0.41620168,
    -0.9619912,  0.45729795,  -1.8192499, 0.32868797,  0.26070616,  0.06020447, 1.1920274,   -0.23420429, 0.13932885,
    0.118088365, 0.07571658,  0.09149596, -0.57611483, -0.10964773, -0.8658647, -0.331915,   -0.22016054, 0.55522484,
    -1.574692,   1.5085229,   0.7177963,  -0.8513607,  1.324727,    -0.327406,  1.1974589,   0.33213785,  0.351831,
    -0.99494386, 0.35944164,  -0.9730411, 0.48647943,  0.29717043,  -1.2035067, 1.2663465,   -0.35874036, 0.057243623,
    0.5232361,   1.6442299,   0.47752506, 0.043387365, 2.0922623,   0.20530196};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[] = {-2.0, -1.0, 0.0,  0.0,  2.0,  -1.0, 1.0,  -2.0, 0.0, 1.0,  -1.0, 0.0,  -1.0, 1.0, 0.0,
                            -1.0, 1.0,  0.0,  -1.0, 0.0,  -2.0, 0.0,  0.0,  0.0, 1.0,  -1.0, 0.0,  0.0,  0.0, 0.0,
                            -1.0, -1.0, -1.0, -1.0, -1.0, 0.0,  -2.0, 1.0,  0.0, -1.0, 1.0,  -1.0, 1.0,  0.0, 0.0,
                            -1.0, 0.0,  -1.0, 0.0,  0.0,  -2.0, 1.0,  -1.0, 0.0, 0.0,  1.0,  0.0,  0.0,  2.0, 0.0};
  using dragonite::norm;

  ONNC_RUNTIME_floor_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
