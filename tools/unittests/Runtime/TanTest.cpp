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
SKYPAT_F(Operator_Tan, test_tan_example)
{
  const float   input_0[]      = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim   = 1;
  const int32_t input_0_dims[] = {3};
  float         output_0[3];
  const int32_t output_0_ndim   = 1;
  const int32_t output_0_dims[] = {3};
  const float   answer_0[]      = {-1.5574077, 0.0, 1.5574077};
  using dragonite::norm;

  ONNC_RUNTIME_tan_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 3) <= 1e-5 * norm(answer_0, 3));
}

SKYPAT_F(Operator_Tan, test_tan)
{
  const float input_0[] = {0.8644818,   -0.5064334,   0.89856833,  0.54074556,   0.97972655,   0.4720979,   0.38396323,
                           0.6433239,   -0.054721713, 1.6637475,   0.5924185,    -0.66575515,  -0.27006888, -1.7129656,
                           1.8139739,   -0.06713542,  -3.2256477,  -1.8886553,   -0.030591168, -0.4944273,  2.811036,
                           0.6944971,   -1.3367306,   0.57645637,  -0.86809987,  1.5268162,    -1.7484306,  -1.2797323,
                           0.1018532,   -0.9116166,   0.25373316,  0.0052462337, 1.396746,     1.8283365,   -0.45318723,
                           -0.21507978, -0.2128064,   -1.111966,   -0.5335259,   0.09776486,   -2.7481403,  -2.175313,
                           -1.9549748,  0.9404193,    1.1847184,   -1.0062846,   -0.5500889,   -1.0476199,  1.2069412,
                           -0.39628145, -0.8198819,   -1.0598944,  0.079849005,  1.5450809,    0.6907964,   1.8673749,
                           -1.0493712,  1.6188267,    -0.60811424, 0.7561128};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float         output_0[60];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float   answer_0[]      = {
    1.1721398,    -0.55468553, 1.2564597,   0.60044354, 1.4900774,    0.51060796, 0.4040155,   0.74972314,  -0.0547764,
    -10.727329,   0.67306405,  -0.7853681,  -0.2768323, 6.9864144,    -4.030841,  -0.06723647, -0.08425355, 3.0393755,
    -0.030600714, -0.5390885,  -0.34314683, 0.8329248,  -4.193996,    0.65011543, -1.1807653,  22.722906,   5.5702076,
    -3.338097,    0.10220688,  -1.29067,    0.2593223,  0.0052462816, 5.6873317,  -3.796661,   -0.4869921,  -0.2184588,
    -0.2160781,   -2.024321,   -0.59066314, 0.09807753, 0.4150963,    1.447622,   2.4736195,   1.3704406,   2.4601605,
    -1.5791488,   -0.6132275,  -1.7337416,  2.6259778,  -0.41841683,  -1.07146,   -1.7839832,  0.08001914,  38.87859,
    0.82667583,   -3.2723436,  -1.7407784,  -20.804127, -0.6961156,   0.94307995};
  using dragonite::norm;

  ONNC_RUNTIME_tan_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(norm(answer_0, output_0, 60) <= 1e-5 * norm(answer_0, 60));
}
