#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Constant, test_constant) {
  float output_0[5][5];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {5, 5};
  const float answer_0[5][5] = {
      {-0.1499820053577423, -0.09867852181196213, -0.7552003264427185,
       -0.5017821788787842, 0.14125250279903412},
      {0.15424101054668427, 1.2302496433258057, 0.6493132710456848,
       1.2770658731460571, 0.6403850317001343},
      {0.12610860168933868, -0.24432356655597687, -0.19105002284049988,
       1.6796523332595825, -0.19935275614261627},
      {0.51890629529953, 1.3465241193771362, 0.4374382495880127,
       0.859891414642334, -1.2525581121444702},
      {-0.08401434868574142, 0.5284765362739563, -0.4616284668445587,
       1.0063412189483643, -1.2763981819152832}};
  ONNC_RUNTIME_constant_float(NULL, (float *)output_0, output_0_ndim,
                              output_0_dims, value);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 5 * 5; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
