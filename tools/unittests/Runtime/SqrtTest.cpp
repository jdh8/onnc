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
SKYPAT_F(Operator_Sqrt, test_sqrt_example)
{
  const float   input_0[]      = {1.0, 4.0, 9.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {1.0, 2.0, 3.0};
  using dragonite::norm;

  ONNC_RUNTIME_sqrt_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Sqrt, test_sqrt)
{
  const float input_0[] = {
    0.47967753,  0.052484382, 0.42495623, 1.4199098, 0.9928178,  2.147696,   1.4090632,  0.5979967,   0.08998327,
    0.90034145,  0.07663384,  0.2795975,  1.0154328, 1.4965589,  0.9676178,  0.07295763, 1.7337228,   0.6292923,
    0.1593145,   1.0035269,   1.5564618,  0.3649674, 0.69452494, 0.39554825, 0.25538763, 0.96573746,  0.7212981,
    0.16763943,  1.2125415,   1.088771,   0.2266421, 1.8492863,  1.65087,    1.3577591,  0.75476134,  0.017927352,
    0.011733018, 0.6884337,   1.7974502,  0.9137745, 0.63886255, 0.44554538, 0.15289749, 0.7512438,   2.1164749,
    0.14417766,  2.4904697,   0.9793969,  1.1948265, 1.2097864,  0.3850134,  1.4390509,  0.033209402, 0.37516075,
    0.29280216,  0.8081525,   0.6964534,  0.6669508, 1.618673,   1.2784843};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    0.69258755, 0.2290947,  0.65188664, 1.1915997,  0.99640244, 1.465502,   1.1870397,  0.7733025,  0.29997212,
    0.94886327, 0.27682817, 0.5287698,  1.0076869,  1.2233392,  0.98367566, 0.2701067,  1.316709,   0.79327947,
    0.3991422,  1.0017619,  1.2475824,  0.6041253,  0.83338165, 0.6289263,  0.50535893, 0.9827194,  0.8492927,
    0.40943795, 1.1011546,  1.0434419,  0.47606942, 1.3598846,  1.2848618,  1.1652292,  0.86877,    0.13389306,
    0.10831906, 0.82971907, 1.3406901,  0.9559155,  0.79928875, 0.66749185, 0.3910211,  0.8667432,  1.454811,
    0.37970734, 1.5781223,  0.9896448,  1.0930812,  1.0999029,  0.6204945,  1.1996045,  0.18223447, 0.61250365,
    0.54111195, 0.89897305, 0.8345378,  0.8166706,  1.2722708,  1.1307008};
  using dragonite::norm;

  ONNC_RUNTIME_sqrt_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
