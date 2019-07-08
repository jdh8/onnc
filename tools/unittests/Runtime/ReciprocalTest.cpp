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
SKYPAT_F(Operator_Reciprocal, test_reciprocal_example) {
  const float input_0[] = {-4.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {-0.25, 0.5};
  ONNC_RUNTIME_reciprocal_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 2) < 1e-5f);
}

SKYPAT_F(Operator_Reciprocal, test_reciprocal) {
  const float input_0[] = {
      0.7043161,  1.1726638,  0.535114,   1.4612079,  0.5973051,  0.51330286,
      1.1821969,  1.1360636,  0.60912436, 0.92437524, 1.0920944,  0.5874524,
      0.81923485, 0.8700363,  1.0449173,  1.4053395,  1.3779474,  0.84334874,
      1.3142265,  1.4251661,  1.4845588,  0.536191,   0.69409317, 0.97071576,
      1.1980057,  1.388376,   1.2689383,  1.0342368,  1.1631274,  0.58476126,
      0.88112354, 0.72417694, 1.349417,   1.2559218,  0.74172497, 0.6496314,
      1.033494,   1.0915451,  0.9934772,  0.8713408,  0.757287,   1.2238955,
      0.5475508,  1.437523,   0.69151616, 1.4975557,  0.72244954, 0.77814007,
      1.1471597,  1.3325132,  0.7922039,  1.2398959,  0.7299435,  1.0910242,
      1.1543303,  0.99683565, 1.3866749,  0.56356937, 0.54324996, 0.53337795};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      1.4198171,  0.8527593,  1.8687607,  0.68436533, 1.6741862,  1.9481676,
      0.84588283, 0.88023245, 1.6417009,  1.0818118,  0.91567177, 1.7022655,
      1.2206511,  1.1493773,  0.9570135,  0.7115718,  0.72571707, 1.185749,
      0.76090384, 0.70167255, 0.6736008,  1.8650072,  1.4407288,  1.0301677,
      0.8347206,  0.720266,   0.78806037, 0.9668966,  0.85975105, 1.7100996,
      1.1349146,  1.380878,   0.7410608,  0.7962279,  1.3482087,  1.5393345,
      0.9675915,  0.91613257, 1.0065656,  1.1476566,  1.3205032,  0.8170632,
      1.8263146,  0.69564104, 1.4460979,  0.66775477, 1.3841797,  1.2851157,
      0.8717182,  0.7504616,  1.2623013,  0.80651927, 1.369969,   0.91657,
      0.8663032,  1.0031744,  0.72114956, 1.7744044,  1.8407732,  1.8748431};
  ONNC_RUNTIME_reciprocal_float(nullptr, input_0, input_0_ndim, input_0_dims,
                                output_0, output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 60) < 1e-5f);
}
