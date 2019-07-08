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
SKYPAT_F(Operator_MatMul, test_matmul_2d) {
  const float input_0[] = {0.38932452, 1.1762323,   0.33422807,  -0.37180346,
                           -1.0846763, -0.14880987, 1.4682455,   -0.033163477,
                           1.0079399,  -1.0457938,  -0.89569384, -1.5052847};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  const float input_1[] = {0.4804459,  -1.9865409, 0.21047328, -1.8652759,
                           -2.7341208, -0.9820303, -0.9484051, 0.10084552,
                           0.85731024, 0.22669736, 0.791421,   -1.8658268};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {4, 3};
  float output_0[9];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 3};
  const float answer_0[] = {-2.408219,  -4.249918,   -0.09289532,
                            -1.6435664, 2.6834376,   1.2384596,
                            2.943191,   -0.42462793, 3.2798586};
  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 9) < 1e-5f);
}

SKYPAT_F(Operator_MatMul, test_matmul_3d) {
  const float input_0[] = {-1.4917614,   -0.27394283, -0.03537286,  0.90952855,
                           -0.8562911,   -1.0894294,  -1.5787278,   0.492808,
                           -0.43583795,  -1.213889,   1.172984,     -1.005649,
                           0.2868166,    -1.8312941,  -0.40857372,  1.8522911,
                           -0.094795175, -1.3002762,  -1.1313345,   1.6838176,
                           -0.106941275, -1.1767647,  -0.062773176, -0.6729188};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {
      1.6545883,  0.6125386,   0.54001045,  1.2509038,  -0.43765518, 0.6231836,
      -1.5284604, -0.30551633, -1.2593968,  1.236164,   0.754799,    0.13758832,
      -0.9654011, 1.1958058,   0.122136354, 0.34388393, -0.81460506, -1.6068372,
      -0.1075643, -1.2049053,  1.2016736,   -0.0132737, -0.05662713, 0.7473676};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {2, 4, 3};
  float output_0[18];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 3};
  const float answer_0[] = {
      -1.6325347, -0.09655073, -0.80659455, 0.24263364,  0.8065812, 0.9147287,
      -5.2755976, -0.85313135, -2.6074505,  -0.88728446, 2.222161,  3.8709922,
      -0.256288,  2.2136562,   1.9766899,   -0.28574497, 0.9444587, 1.2994572};
  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 18) < 1e-5f);
}

SKYPAT_F(Operator_MatMul, test_matmul_4d) {
  const float input_0[] = {
      0.7542962,  -0.18372898, 0.06795105, -0.7653857, 1.1719676,  2.088879,
      -1.7468864, -0.42503574, 1.066608,   0.32233462, -1.5942539, 0.19213948,
      1.7276297,  1.4146574,   -2.0622032, -1.0494744, -0.6602828, -0.97770256,
      -1.4459038, -0.9897286,  1.0168169,  -1.3870683, -1.1350626, 0.4595915};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 2, 3, 4};
  const float input_1[] = {-0.99489903, 0.625782,    0.6371248,   -0.58894944,
                           0.09838709,  0.43866464,  -1.5453622,  -1.0206432,
                           -0.46423298, 0.077516675, -0.86111575, 0.28533322,
                           0.5375422,   -0.6848333,  1.0769969,   0.7684642,
                           0.46932793,  -0.12432339, -1.6186433,  0.97252923,
                           -1.7340163,  -0.27390185, -0.57990307, -0.28323594};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 2, 4, 3};
  float output_0[18];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 2, 3, 3};
  const float answer_0[] = {
      -0.8065806, 1.0436803,  0.15005028, 0.27039108, 3.0878677,  2.3526924,
      1.2275878,  2.1608877,  1.6158881,  5.641212,   -1.9161595, 5.5579195,
      1.5052316,  -0.8389165, 2.197976,   1.1920481,  -2.71774,   3.105598};
  ONNC_RUNTIME_matmul_float(nullptr, input_0, input_0_ndim, input_0_dims,
                            input_1, input_1_ndim, input_1_dims, output_0,
                            output_0_ndim, output_0_dims);
  ASSERT_TRUE(relative_error(output_0, answer_0, 18) < 1e-5f);
}
