#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Shape, test_shape_example) {
  const float input_0[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {2, 3};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[2] = {2, 3};
  ONNC_RUNTIME_shape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Shape, test_shape) {
  const float input_0[3][4][5] = {
      {{0.9845293760299683, 0.264349102973938, -0.010137218981981277,
        0.3213636577129364, 0.28916773200035095},
       {0.10961603373289108, -0.4745383560657501, 1.0356535911560059,
        -0.09716206043958664, -1.472784161567688},
       {-0.5154834389686584, -2.1243951320648193, -1.2877402305603027,
        0.8116641640663147, 0.34823668003082275},
       {-0.14546096324920654, 1.6329822540283203, -0.4836365580558777,
        0.6662614345550537, -0.015560767613351345}},
      {{1.9756417274475098, 0.3782581388950348, -0.3621477484703064,
        -2.1717007160186768, -0.4624321758747101},
       {0.15561656653881073, -1.874893069267273, -1.6140024662017822,
        -0.1699608564376831, 3.2728288173675537},
       {0.7834771275520325, -0.49782395362854004, -0.060945965349674225,
        0.955822765827179, 0.354866623878479},
       {0.3804665803909302, -0.663848876953125, 0.7743737101554871,
        -0.8113270401954651, -1.12050461769104}},
      {{-0.2200598567724228, -0.5132883191108704, -0.6277086734771729,
        -0.2920261025428772, 0.14790214598178864},
       {-0.9835309982299805, -1.4393330812454224, 0.610305905342102,
        -2.164851188659668, -0.4683055579662323},
       {0.8852458000183105, -0.08441325277090073, 1.0959404706954956,
        0.7358961701393127, -1.2204610109329224},
       {-0.3587956130504608, 1.1650687456130981, -0.7322959303855896,
        0.8974599838256836, 0.3569093346595764}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {3, 4, 5};
  ONNC_RUNTIME_shape_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                           (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
