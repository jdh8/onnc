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
SKYPAT_F(Operator_Gather, test_gather_0)
{
  const float input_0[] = {
    -0.10268293, -0.7169611,  1.1875722,  0.22667612,  0.9126516,   1.2811111,   0.832058,     0.6153543,   -0.4193261,
    -0.5800812,  -0.13183776, 1.4841567,  -0.20770766, 2.0268471,   0.45761114,  -0.007992363, 1.9810972,   -0.951646,
    -2.1350524,  0.8462616,   1.100182,   0.91574174,  1.7113899,   -0.48977676, 0.450925,     -2.4409926,  -0.09499872,
    -0.43372592, 0.030361392, 0.51383466, 1.1350065,   1.2899282,   -0.24390163, -0.8423005,   0.27592945,  -0.9082181,
    -1.2348262,  1.3201735,   -0.3395294, -0.4952696,  0.42738986,  0.4983957,   -0.82410794,  0.39478034,  -0.28914514,
    -0.49849474, 0.4681068,   1.0797163,  -1.3187307,  0.28639928,  0.41581273,  0.82137203,   -1.6858938,  -0.3923686,
    0.27017435,  -2.0077825,  0.33990988, -0.22633885, -1.1076422,  0.9523425,   0.6564652,    0.21243176,  -0.79371125,
    -0.30722645, -0.9554829,  0.5533366,  -0.21080622, -1.5355725,  -1.0793004,  -0.63904256,  1.7020922,   0.37627378,
    1.0251751,   -0.7663863,  0.74617136, 0.45054835,  -0.69499993, 0.4721112,   0.30872384,   1.4480813,   0.6538331,
    0.06305258,  0.83632195,  1.5118837,  0.8595603,   0.7082937,   -0.32173404, -0.7353698,   -1.7512581,  -0.15220632,
    -1.9569229,  0.6023685,   0.62357736, 0.7819218,   0.9173205,   1.5131284,   0.9594454,    0.35175145,  -0.25385097,
    -2.0249634,  1.0721623,   0.14414309, 0.3413746,   -0.7303392,  -0.42295837, -0.45531368,  -1.0867952,  0.6073552,
    -0.5608745,  0.22470227,  0.43395504, 0.9111605,   0.3255375,   -0.8135702,  1.1282701,    -0.74991953, -0.6428641,
    0.09958677,  0.70353484,  -0.43923563};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {5, 4, 3, 2};
  const float   input_1[]      = {0, 1, 3};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {3};
  float         output_0[72];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {3, 4, 3, 2};
  const float   answer_0[]      = {
    -0.10268293, -0.7169611,  1.1875722,   0.22667612,  0.9126516,  1.2811111,   0.832058,     0.6153543,   -0.4193261,
    -0.5800812,  -0.13183776, 1.4841567,   -0.20770766, 2.0268471,  0.45761114,  -0.007992363, 1.9810972,   -0.951646,
    -2.1350524,  0.8462616,   1.100182,    0.91574174,  1.7113899,  -0.48977676, 0.450925,     -2.4409926,  -0.09499872,
    -0.43372592, 0.030361392, 0.51383466,  1.1350065,   1.2899282,  -0.24390163, -0.8423005,   0.27592945,  -0.9082181,
    -1.2348262,  1.3201735,   -0.3395294,  -0.4952696,  0.42738986, 0.4983957,   -0.82410794,  0.39478034,  -0.28914514,
    -0.49849474, 0.4681068,   1.0797163,   1.0251751,   -0.7663863, 0.74617136,  0.45054835,   -0.69499993, 0.4721112,
    0.30872384,  1.4480813,   0.6538331,   0.06305258,  0.83632195, 1.5118837,   0.8595603,    0.7082937,   -0.32173404,
    -0.7353698,  -1.7512581,  -0.15220632, -1.9569229,  0.6023685,  0.62357736,  0.7819218,    0.9173205,   1.5131284};
  const int32_t axis = 0;
  using dragonite::norm;

  ONNC_RUNTIME_gather_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(norm(answer_0, output_0, 72) <= 1e-5 * norm(answer_0, 72));
}

SKYPAT_F(Operator_Gather, test_gather_1)
{
  const float input_0[] = {
    1.0938363,   -0.9886603,  1.0734742,   1.2562224,    0.5262238,    -1.1192627,  -0.27439436, -0.48804823,
    -0.4727604,  -0.86751956, 1.3797443,   -0.8846253,   0.046781458,  -0.4747237,  -0.94479597, -0.4678798,
    1.1142836,   -1.421299,   -1.3179901,  0.2941768,    0.81266755,   1.0920272,   0.8520862,   -0.026351457,
    -0.32947212, -2.0598404,  -1.0391783,  -1.6360958,   0.72315043,   0.768334,    1.7655375,   -0.21154346,
    1.9006356,   0.40574306,  1.0146531,   0.667152,     -0.8930049,   0.8234272,   0.42671248,  0.48089156,
    -0.06243266, 1.4549319,   0.80071265,  0.6470085,    0.1657334,    -0.28536946, -1.102754,   -0.7982433,
    2.7099047,   0.5003924,   -0.1078263,  1.5244688,    -0.07400639,  0.45933226,  -0.52994573, 0.27066302,
    0.012312409, -0.5909327,  0.012614941, -0.122944,    0.27316597,   -0.6740088,  0.28926662,  1.4248233,
    0.7828141,   -0.7644039,  1.4234623,   -2.627221,    0.99728817,   0.14885332,  0.1896846,   -1.215192,
    -0.16754594, 2.0839577,   0.08998797,  -0.003758059, 1.1908852,    -0.28988627, 1.1665574,   1.5303224,
    1.3737632,   -0.89355886, 0.46519077,  -0.57218194,  0.82182133,   0.040196043, -0.5526352,  1.5854344,
    1.8383642,   -1.161753,   -0.4208953,  -0.7675141,   -0.9761252,   1.2539897,   0.93736964,  1.6723638,
    0.48418564,  0.10147406,  -0.11724389, -0.24646701,  -0.86894745,  1.0874664,   0.8525582,   2.897585,
    -0.6301139,  0.64151293,  0.6247266,   0.4994487,    0.91870296,   0.84895074,  0.6576702,   -0.13829945,
    -0.1407736,  0.5636561,   0.3476379,   -1.4879643,   -0.099510394, 0.5222436,   0.4561482,   -0.83552045};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {5, 4, 3, 2};
  const float   input_1[]      = {0, 1, 3};
  const int32_t input_1_ndim   = 1;
  const int32_t input_1_dims[] = {3};
  float         output_0[90];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {5, 3, 3, 2};
  const float   answer_0[]      = {
    1.0938363,   -0.9886603,   1.0734742,   1.2562224,   0.5262238,   -1.1192627, -0.27439436,  -0.48804823,
    -0.4727604,  -0.86751956,  1.3797443,   -0.8846253,  -1.3179901,  0.2941768,  0.81266755,   1.0920272,
    0.8520862,   -0.026351457, -0.32947212, -2.0598404,  -1.0391783,  -1.6360958, 0.72315043,   0.768334,
    1.7655375,   -0.21154346,  1.9006356,   0.40574306,  1.0146531,   0.667152,   0.80071265,   0.6470085,
    0.1657334,   -0.28536946,  -1.102754,   -0.7982433,  2.7099047,   0.5003924,  -0.1078263,   1.5244688,
    -0.07400639, 0.45933226,   -0.52994573, 0.27066302,  0.012312409, -0.5909327, 0.012614941,  -0.122944,
    1.4234623,   -2.627221,    0.99728817,  0.14885332,  0.1896846,   -1.215192,  -0.16754594,  2.0839577,
    0.08998797,  -0.003758059, 1.1908852,   -0.28988627, 1.1665574,   1.5303224,  1.3737632,    -0.89355886,
    0.46519077,  -0.57218194,  -0.4208953,  -0.7675141,  -0.9761252,  1.2539897,  0.93736964,   1.6723638,
    0.48418564,  0.10147406,   -0.11724389, -0.24646701, -0.86894745, 1.0874664,  0.8525582,    2.897585,
    -0.6301139,  0.64151293,   0.6247266,   0.4994487,   0.3476379,   -1.4879643, -0.099510394, 0.5222436,
    0.4561482,   -0.83552045};
  const int32_t axis = 1;
  using dragonite::norm;

  ONNC_RUNTIME_gather_float(nullptr, input_0, input_0_ndim, input_0_dims, input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims, axis);
  ASSERT_TRUE(norm(answer_0, output_0, 90) <= 1e-5 * norm(answer_0, 90));
}
