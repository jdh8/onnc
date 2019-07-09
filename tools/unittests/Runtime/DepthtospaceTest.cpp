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
SKYPAT_F(Operator_DepthToSpace, test_depthtospace)
{
  const float input_0[] = {
    0.03723034, 0.90121377,  0.5031516,  0.1668142,   0.17022245, 0.24142878, 0.023274116, 0.27854484, 0.63969344,
    0.55163735, 0.61832994,  0.5188614,  0.6284918,   0.35917673, 0.3827855,  0.2707874,   0.23928145, 0.082790434,
    0.19605094, 0.62423205,  0.42011347, 0.016393043, 0.06328605, 0.4483997,  0.25987354,  0.9699631,  0.18580808,
    0.64959615, 0.625051,    0.82715666, 0.40593606,  0.97935134, 0.2937956,  0.72371465,  0.765329,   0.5760877,
    0.12941799, 0.5405175,   0.91951895, 0.030624669, 0.27861565, 0.68963104, 0.4178536,   0.1960915,  0.8396884,
    0.38157544, 0.7955023,   0.4293156,  0.12859212,  0.4040895,  0.22842602, 0.9880453,   0.02717486, 0.5382365,
    0.5576062,  0.28574833,  0.654864,   0.7315335,   0.5027532,  0.7378745,  0.37932587,  0.6812233,  0.28209653,
    0.60209125, 0.5100452,   0.27040488, 0.7174716,   0.82233626, 0.5651524,  0.8036432,   0.42728058, 0.7326123,
    0.5929123,  0.047043793, 0.29099235, 0.37301084,  0.49576142, 0.19093826, 0.3047,      0.6385204,  0.5117761,
    0.7948615,  0.7606457,   0.4164714,  0.6135479,   0.3104499,  0.42574844, 0.41517037,  0.6416248,  0.6727608,
    0.8793549,  0.71094745,  0.6456236,  0.040176548, 0.3954366,  0.8793766,  0.11374735,  0.74450624, 0.59698266,
    0.21698861, 0.5998655,   0.14978346, 0.41582295,  0.55668825, 0.8020957,  0.3927829,   0.5830362,  0.7276716,
    0.13159819, 0.8605022,   0.8924898,  0.027349772, 0.52425754, 0.868685,   0.78769493,  0.19613932, 0.31555116,
    0.4680006,  0.1757374,   0.3518847,  0.3736186,   0.15037593, 0.8915074,  0.17878208,  0.27599725, 0.121665515,
    0.6370619,  0.77326345,  0.6602265,  0.9699743,   0.16117889, 0.9696074,  0.78719234,  0.40445474, 0.8768775,
    0.9090356,  0.05274747,  0.63932174, 0.27225196,  0.52157944, 0.80366963, 0.57607627,  0.51589006, 0.4438584};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {2, 8, 3, 3};
  float         output_0[144];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {2, 2, 6, 6};
  const float   answer_0[]      = {
    0.03723034,  0.19605094,  0.90121377,  0.62423205, 0.5031516,   0.42011347, 0.12941799,  0.5576062,   0.5405175,
    0.28574833,  0.91951895,  0.654864,    0.1668142,  0.016393043, 0.17022245, 0.06328605,  0.24142878,  0.4483997,
    0.030624669, 0.7315335,   0.27861565,  0.5027532,  0.68963104,  0.7378745,  0.023274116, 0.25987354,  0.27854484,
    0.9699631,   0.63969344,  0.18580808,  0.4178536,  0.37932587,  0.1960915,  0.6812233,   0.8396884,   0.28209653,
    0.55163735,  0.64959615,  0.61832994,  0.625051,   0.5188614,   0.82715666, 0.38157544,  0.60209125,  0.7955023,
    0.5100452,   0.4293156,   0.27040488,  0.6284918,  0.40593606,  0.35917673, 0.97935134,  0.3827855,   0.2937956,
    0.12859212,  0.7174716,   0.4040895,   0.82233626, 0.22842602,  0.5651524,  0.2707874,   0.72371465,  0.23928145,
    0.765329,    0.082790434, 0.5760877,   0.9880453,  0.8036432,   0.02717486, 0.42728058,  0.5382365,   0.7326123,
    0.5929123,   0.8793549,   0.047043793, 0.71094745, 0.29099235,  0.6456236,  0.13159819,  0.6370619,   0.8605022,
    0.77326345,  0.8924898,   0.6602265,   0.37301084, 0.040176548, 0.49576142, 0.3954366,   0.19093826,  0.8793766,
    0.027349772, 0.9699743,   0.52425754,  0.16117889, 0.868685,    0.9696074,  0.3047,      0.11374735,  0.6385204,
    0.74450624,  0.5117761,   0.59698266,  0.78769493, 0.78719234,  0.19613932, 0.40445474,  0.31555116,  0.8768775,
    0.7948615,   0.21698861,  0.7606457,   0.5998655,  0.4164714,   0.14978346, 0.4680006,   0.9090356,   0.1757374,
    0.05274747,  0.3518847,   0.63932174,  0.6135479,  0.41582295,  0.3104499,  0.55668825,  0.42574844,  0.8020957,
    0.3736186,   0.27225196,  0.15037593,  0.52157944, 0.8915074,   0.80366963, 0.41517037,  0.3927829,   0.6416248,
    0.5830362,   0.6727608,   0.7276716,   0.17878208, 0.57607627,  0.27599725, 0.51589006,  0.121665515, 0.4438584};
  const int32_t blocksize = 2;
  using dragonite::norm;

  ONNC_RUNTIME_depthtospace_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                                  blocksize);
  ASSERT_TRUE(norm(answer_0, output_0, 144) <= 1e-5 * norm(answer_0, 144));
}

SKYPAT_F(Operator_DepthToSpace, test_depthtospace_example)
{
  const float   input_0[]      = {0.0,  1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0, 11.0,
                           12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0};
  const int32_t input_0_ndim   = 4;
  const int32_t input_0_dims[] = {1, 4, 2, 3};
  float         output_0[24];
  const int32_t output_0_ndim   = 4;
  const int32_t output_0_dims[] = {1, 1, 4, 6};
  const float   answer_0[]      = {0.0, 6.0, 1.0, 7.0,  2.0, 8.0,  12.0, 18.0, 13.0, 19.0, 14.0, 20.0,
                            3.0, 9.0, 4.0, 10.0, 5.0, 11.0, 15.0, 21.0, 16.0, 22.0, 17.0, 23.0};
  const int32_t blocksize       = 2;
  using dragonite::norm;

  ONNC_RUNTIME_depthtospace_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                                  blocksize);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}
