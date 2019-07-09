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
SKYPAT_F(Operator_Size, test_size_example)
{
  const float   input_0[]      = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  const int32_t input_0_ndim   = 2;
  const int32_t input_0_dims[] = {2, 3};
  float         output_0[1];
  const int32_t output_0_ndim   = 0;
  const int32_t output_0_dims[] = {};
  const float   answer_0[]      = {6};
  using dragonite::norm;

  ONNC_RUNTIME_size_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 1.0) <= 1e-5 * norm(answer_0, 1.0));
}

SKYPAT_F(Operator_Size, test_size)
{
  const float   input_0[] = {-0.39522898, -1.1594205,  -0.085930765, 0.19429293,  0.87583274,  -0.11510747,  0.4574156,
                           -0.964612,   -0.78262913, -0.1103893,   -1.0546285,  0.8202478,   0.46313033,   0.27909577,
                           0.3389041,   2.0210435,   -0.4688642,   -2.2014413,  0.1993002,   -0.050603542, -0.51751906,
                           -0.97882986, -0.43918952, 0.18133843,   -0.5028167,  2.4124537,   -0.96050435,  -0.79311734,
                           -2.28862,    0.25148442,  -2.0164065,   -0.53945464, -0.27567053, -0.70972794,  1.7388726,
                           0.99439436,  1.3191369,   -0.8824188,   1.128594,    0.49600095,  0.77140594,   1.0294389,
                           -0.90876323, -0.42431763, 0.86259604,   -2.6556191,  1.5133281,   0.55313206,   -0.045703962,
                           0.22050765,  -1.0299352,  -0.34994337,  1.1002843,   1.298022,    2.696224,     -0.07392467,
                           -0.65855294, -0.51423395, -1.0180418,   -0.07785475};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[1];
  const int32_t output_0_ndim   = 0;
  const int32_t output_0_dims[] = {};
  const float   answer_0[]      = {60};
  using dragonite::norm;

  ONNC_RUNTIME_size_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 1.0) <= 1e-5 * norm(answer_0, 1.0));
}
