#if defined(__GNUC__) || defined(_MSC_VER)
#define restrict __restrict
#else
#define restrict
#endif

extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}

#undef restrict

#include "relative-error.hpp"
#include <skypat/skypat.h>
SKYPAT_F(Operator_Acos, test_acos_example) {
  const float input_0[] = {-0.5, 0.0, 0.5};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {2.0943952, 1.5707964, 1.0471976};
  ONNC_RUNTIME_acos_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 3) < 1e-5f);
}

SKYPAT_F(Operator_Acos, test_acos) {
  const float input_0[] = {
      0.31811786,  0.37387,    0.13741885, 0.0044502807, 0.21092416,
      0.7362431,   0.56395924, 0.3821146,  0.5610824,    0.056866262,
      0.007544494, 0.5795446,  0.8082987,  0.3082684,    0.57577956,
      0.72157043,  0.8459279,  0.19503091, 0.33560017,   0.35534492,
      0.06306715,  0.81442076, 0.5098989,  0.74475986,   0.7983099,
      0.8824752,   0.81188685, 0.5137256,  0.7175955,    0.83801264,
      0.6904085,   0.02133331, 0.53070927, 0.066181526,  0.924052,
      0.16242856,  0.68445516, 0.4907995,  0.61515677,   0.563447,
      0.64786106,  0.27508998, 0.54423153, 0.14294364,   0.85147345,
      0.4025721,   0.41672495, 0.43906075, 0.44415686,   0.7385183,
      0.99891,     0.51287615, 0.78709537, 0.51366764,   0.43812412,
      0.9730247,   0.18347323, 0.23081686, 0.6538151,    0.013296331};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      1.2470528,  1.1876183,  1.4329412,   1.566346,   1.358276,   0.7432945,
      0.9716239,  1.1787128,  0.97510344,  1.5138993,  1.5632517,  0.9526266,
      0.62953955, 1.2574241,  0.95723903,  0.76472837, 0.5624936,  1.3745073,
      1.228554,   1.2075133,  1.5076873,   0.61906606, 1.035729,   0.7306214,
      0.64631265, 0.48969746, 0.6234195,   1.0312748,  0.7704526,  0.57716554,
      0.8087427,  1.5494614,  1.0113591,   1.5045664,  0.39224815, 1.407645,
      0.81694025, 1.0577892,  0.9082115,   0.9722441,  0.8660231,  1.2921131,
      0.9953235,  1.4273614,  0.5520076,   1.1564714,  1.1409568,  1.1162434,
      1.1105633,  0.7399262,  0.046694502, 1.0322645,  0.6647105,  1.0313423,
      1.1172855,  0.2327979,  1.3862778,   1.3378792,  0.85818076, 1.5574996};
  ONNC_RUNTIME_acos_float(nullptr, input_0, input_0_ndim, input_0_dims,
                          output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
