#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Dropout, test_dropout_default) {
  const float input_0[3] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {-1.0, 0.0, 1.0};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float ratio = 0;
  ONNC_RUNTIME_dropout_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             (float *)output_1, output_1_ndim, output_1_dims,
                             ratio);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Dropout, test_dropout_random) {
  const float input_0[3][4][5] = {
      {{1.0395766496658325, -1.120259165763855, 0.30909398198127747,
        -1.4860572814941406, -0.4386932849884033},
       {0.8881357908248901, 0.8389769792556763, -0.3953520655632019,
        1.2173590660095215, 0.4812641739845276},
       {-0.4764184057712555, 1.2216839790344238, -0.18691928684711456,
        0.8753741979598999, -0.1646784543991089},
       {1.8916668891906738, -0.7987159490585327, 0.7308586239814758,
        -0.41535621881484985, -0.5114907026290894}},
      {{-2.1547772884368896, 0.41771361231803894, -1.238251805305481,
        -1.2258930206298828, 1.426041603088379},
       {-0.04362143203616142, -0.1841108798980713, 1.5576618909835815,
        -1.0725681781768799, -1.2992875576019287},
       {0.20173963904380798, -0.6260353326797485, -0.446896493434906,
        0.3736107349395752, 2.108001232147217},
       {-0.6241313815116882, -1.214677333831787, 0.5562111735343933,
        0.28421077132225037, 1.2540210485458374}},
      {{-0.3124641478061676, 0.6849225163459778, 0.07270880043506622,
        -0.9750255942344666, 0.2111501395702362},
       {-0.4176826775074005, -2.009343147277832, -0.2461218386888504,
        0.6983822584152222, -0.5378592014312744},
       {-1.6092946529388428, 0.2398306280374527, 0.6819636821746826,
        0.43695178627967834, -1.7709465026855469},
       {1.0063220262527466, 1.5092822313308716, 0.8792771100997925,
        -0.7256238460540771, 0.16403518617153168}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {
      {{1.0395766496658325, -1.120259165763855, 0.30909398198127747,
        -1.4860572814941406, -0.4386932849884033},
       {0.8881357908248901, 0.8389769792556763, -0.3953520655632019,
        1.2173590660095215, 0.4812641739845276},
       {-0.4764184057712555, 1.2216839790344238, -0.18691928684711456,
        0.8753741979598999, -0.1646784543991089},
       {1.8916668891906738, -0.7987159490585327, 0.7308586239814758,
        -0.41535621881484985, -0.5114907026290894}},
      {{-2.1547772884368896, 0.41771361231803894, -1.238251805305481,
        -1.2258930206298828, 1.426041603088379},
       {-0.04362143203616142, -0.1841108798980713, 1.5576618909835815,
        -1.0725681781768799, -1.2992875576019287},
       {0.20173963904380798, -0.6260353326797485, -0.446896493434906,
        0.3736107349395752, 2.108001232147217},
       {-0.6241313815116882, -1.214677333831787, 0.5562111735343933,
        0.28421077132225037, 1.2540210485458374}},
      {{-0.3124641478061676, 0.6849225163459778, 0.07270880043506622,
        -0.9750255942344666, 0.2111501395702362},
       {-0.4176826775074005, -2.009343147277832, -0.2461218386888504,
        0.6983822584152222, -0.5378592014312744},
       {-1.6092946529388428, 0.2398306280374527, 0.6819636821746826,
        0.43695178627967834, -1.7709465026855469},
       {1.0063220262527466, 1.5092822313308716, 0.8792771100997925,
        -0.7256238460540771, 0.16403518617153168}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const float ratio = 0.20000000298023224;
  ONNC_RUNTIME_dropout_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             (float *)output_1, output_1_ndim, output_1_dims,
                             ratio);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4 * 5; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}