#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Identity, test_identity) {
  const float input_0[1][1][2][2] = {{{{1.0, 2.0}, {3.0, 4.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 1, 2, 2};
  float output_0[1][1][2][2];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 1, 2, 2};
  const float answer_0[1][1][2][2] = {{{{1.0, 2.0}, {3.0, 4.0}}}};
  ONNC_RUNTIME_identity_float(NULL, (float *)input_0, input_0_ndim,
                              input_0_dims, (float *)output_0, output_0_ndim,
                              output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 1 * 2 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
