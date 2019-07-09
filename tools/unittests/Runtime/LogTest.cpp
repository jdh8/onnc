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
SKYPAT_F(Operator_Log, test_log_example)
{
  const float   input_0[]      = {1.0, 10.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {2};
  float         output_0[2];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {2};
  const float   answer_0[]      = {0.0, 2.3025851};
  using dragonite::norm;

  ONNC_RUNTIME_log_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 2) <= 1e-5 * norm(answer_0, 2));
}

SKYPAT_F(Operator_Log, test_log)
{
  const float input_0[] = {
    1.6907245, 4.8359447,  0.80369085, 0.6107199,   0.24820942, 1.5050381,  1.7831534,  0.8784368,  0.77337545,
    2.1009557, 2.146831,   0.5419564,  3.7944174,   0.57963765, 0.6605329,  1.5414994,  2.3104665,  0.46210268,
    0.3678018, 1.3881712,  0.83037645, 0.4547308,   0.31319556, 0.26523322, 0.61135817, 0.47750232, 0.7578742,
    1.0092689, 0.43827045, 0.41924602, 1.9879131,   0.71747136, 3.268311,   0.28602445, 0.43069792, 0.39745647,
    1.0985676, 2.1102521,  2.0471694,  1.4055884,   1.0630653,  0.2745923,  0.6086725,  1.1394075,  2.046251,
    0.769554,  1.76057,    0.14873455, 0.107907824, 1.6216795,  0.61520004, 0.829563,   1.3845246,  0.60989624,
    5.010369,  1.5589542,  3.242785,   2.4551609,   0.77463174, 8.181467};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.52515715,  1.5760765,  -0.2185406,  -0.49311683, -1.3934824,  0.40881824,  0.5783834,   -0.12961131, -0.25699064,
    0.74239236,  0.76399285, -0.6125697,  1.3335309,   -0.5453521,  -0.41470835, 0.43275556,  0.8374495,   -0.7719682,
    -1.0002111,  0.3279872,  -0.18587613, -0.78804964, -1.1609275,  -1.3271458,  -0.49207228, -0.7391863,  -0.2772379,
    0.009226187, -0.8249191, -0.8692974,  0.6870854,   -0.33202225, 1.1842734,   -1.251678,   -0.84234834, -0.9226699,
    0.09400716,  0.74680746, 0.7164581,   0.340456,    0.06115652,  -1.2924678,  -0.49647492, 0.13050841,  0.7160094,
    -0.26194412, 0.56563765, -1.9055921,  -2.2264779,  0.48346236,  -0.4858078,  -0.1868562,  0.3253568,   -0.49446642,
    1.6115096,   0.44401523, 1.1764325,   0.8981923,   -0.25536755, 2.1018715};
  using dragonite::norm;

  ONNC_RUNTIME_log_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
