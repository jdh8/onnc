#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[2] = {0, 1};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMax, test_argmax_no_keepdims_random) {
  const float input_0[2][3][4] = {{{-4.161064624786377, -0.9484439492225647,
                                    -3.4496707916259766, 0.08960416913032532},
                                   {-1.1302967071533203, -4.677112102508545,
                                    -1.544519305229187, 7.782342433929443},
                                   {-7.159712791442871, 3.2435498237609863,
                                    -2.956920623779297, -3.115990161895752}},
                                  {{6.209433555603027, -9.58924388885498,
                                    5.432360649108887, -4.438661575317383},
                                   {-7.984988689422607, -3.713932752609253,
                                    8.274628639221191, -6.674544811248779},
                                   {6.240407466888428, -8.802353858947754,
                                    -1.2635892629623413, 5.503859519958496}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[2][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 4};
  const float answer_0[2][4] = {{1, 2, 1, 1}, {2, 1, 1, 2}};
  const int32_t axis = 1;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[2][1];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 1};
  const float answer_0[2][1] = {{0}, {1}};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 1; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMax, test_argmax_keepdims_random) {
  const float input_0[2][3][4] = {{{-1.0090230703353882, 8.661270141601562,
                                    -8.41781234741211, -1.3912568092346191},
                                   {-3.6067912578582764, 8.826355934143066,
                                    -9.669211387634277, -9.46104907989502},
                                   {-2.40744686126709, -4.741912364959717,
                                    7.5588507652282715, -6.765323162078857}},
                                  {{3.03826642036438, 8.147594451904297,
                                    5.911610126495361, 9.02561092376709},
                                   {-3.102365255355835, -6.656824588775635,
                                    2.6258726119995117, -4.56792688369751},
                                   {-7.42033576965332, 8.277228355407715,
                                    1.3292993307113647, 5.334455490112305}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[2][1][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 1, 4};
  const float answer_0[2][1][4] = {{{0, 1, 2, 0}}, {{0, 2, 0, 0}}};
  const int32_t axis = 1;
  const int32_t keepdims = 1;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 1 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_example) {
  const float input_0[2][2] = {{2.0, 1.0}, {3.0, 10.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 2};
  float output_0[1][2];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 2};
  const float answer_0[1][2] = {{1, 1}};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 2; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_ArgMax, test_argmax_default_axis_random) {
  const float input_0[2][3][4] = {{{1.0452238321304321, -2.3456976413726807,
                                    2.2880799770355225, 6.925357341766357},
                                   {7.737130165100098, 2.2890405654907227,
                                    5.045838832855225, -2.7824082374572754},
                                   {-4.785099506378174, -2.568950891494751,
                                    6.928551197052002, -6.533916473388672}},
                                  {{1.0276724100112915, 9.40451717376709,
                                    -8.951014518737793, 9.489995956420898},
                                   {-4.22593355178833, 3.258622407913208,
                                    -2.767998695373535, -6.110668182373047},
                                   {-9.506040573120117, -7.959628582000732,
                                    -9.93812370300293, 8.519405364990234}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[1][3][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[1][3][4] = {{{0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 1}}};
  const int32_t keepdims = 1;
  const int32_t axis = 0;
  ONNC_RUNTIME_argmax_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)output_0, output_0_ndim, output_0_dims,
                            axis, keepdims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
