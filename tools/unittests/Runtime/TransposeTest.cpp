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
SKYPAT_F(Operator_Transpose, test_transpose_default)
{
  const float   input_0[]      = {0.22805642, 0.3003442,  0.19453843, 0.44306207,  0.5043461,  0.89922696,
                           0.7707544,  0.715345,   0.57266974, 0.3285802,   0.07007694, 0.2588076,
                           0.19468726, 0.22789727, 0.22677489, 0.43054667,  0.3807149,  0.33704677,
                           0.88123757, 0.20273742, 0.16365367, 0.076002896, 0.9248602,  0.19434631};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {4, 3, 2};
  const float   answer_0[]      = {0.22805642, 0.19468726, 0.5043461,  0.3807149,  0.57266974, 0.16365367,
                            0.3003442,  0.22789727, 0.89922696, 0.33704677, 0.3285802,  0.076002896,
                            0.19453843, 0.22677489, 0.7707544,  0.88123757, 0.07007694, 0.9248602,
                            0.44306207, 0.43054667, 0.715345,   0.20273742, 0.2588076,  0.19434631};
  const int32_t perm[]          = {2, 1, 0};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_0)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {2, 3, 4};
  const float   answer_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                            0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                            0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                            0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t perm[]          = {0, 1, 2};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_1)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {2, 4, 3};
  const float   answer_0[]      = {0.572268,   0.84007704, 0.606817,   0.3737178,  0.507263,    0.1320044,
                            0.55529976, 0.3272407,  0.8558071,  0.6425663,  0.18107992,  0.027789488,
                            0.84529984, 0.7841668,  0.34402606, 0.21924663, 0.4017798,   0.26157886,
                            0.48785785, 0.49945477, 0.39006907, 0.7305207,  0.029572658, 0.30089337};
  const int32_t perm[]          = {0, 2, 1};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_2)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 2, 4};
  const float   answer_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,   0.84529984, 0.21924663,
                            0.48785785, 0.7305207,   0.84007704, 0.507263,    0.3272407,  0.18107992,
                            0.7841668,  0.4017798,   0.49945477, 0.029572658, 0.606817,   0.1320044,
                            0.8558071,  0.027789488, 0.34402606, 0.26157886,  0.39006907, 0.30089337};
  const int32_t perm[]          = {1, 0, 2};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_3)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {3, 4, 2};
  const float   answer_0[]      = {0.572268,  0.84529984, 0.3737178,  0.21924663,  0.55529976,  0.48785785,
                            0.6425663, 0.7305207,  0.84007704, 0.7841668,   0.507263,    0.4017798,
                            0.3272407, 0.49945477, 0.18107992, 0.029572658, 0.606817,    0.34402606,
                            0.1320044, 0.26157886, 0.8558071,  0.39006907,  0.027789488, 0.30089337};
  const int32_t perm[]          = {1, 2, 0};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_4)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {4, 2, 3};
  const float   answer_0[]      = {0.572268,   0.84007704, 0.606817,    0.84529984, 0.7841668,   0.34402606,
                            0.3737178,  0.507263,   0.1320044,   0.21924663, 0.4017798,   0.26157886,
                            0.55529976, 0.3272407,  0.8558071,   0.48785785, 0.49945477,  0.39006907,
                            0.6425663,  0.18107992, 0.027789488, 0.7305207,  0.029572658, 0.30089337};
  const int32_t perm[]          = {2, 0, 1};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_5)
{
  const float   input_0[]      = {0.572268,   0.3737178,   0.55529976, 0.6425663,  0.84007704, 0.507263,
                           0.3272407,  0.18107992,  0.606817,   0.1320044,  0.8558071,  0.027789488,
                           0.84529984, 0.21924663,  0.48785785, 0.7305207,  0.7841668,  0.4017798,
                           0.49945477, 0.029572658, 0.34402606, 0.26157886, 0.39006907, 0.30089337};
  const int32_t input_0_ndim   = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float         output_0[24];
  const int32_t output_0_ndim   = 3;
  const int32_t output_0_dims[] = {4, 3, 2};
  const float   answer_0[]      = {0.572268,   0.84529984, 0.84007704, 0.7841668,   0.606817,    0.34402606,
                            0.3737178,  0.21924663, 0.507263,   0.4017798,   0.1320044,   0.26157886,
                            0.55529976, 0.48785785, 0.3272407,  0.49945477,  0.8558071,   0.39006907,
                            0.6425663,  0.7305207,  0.18107992, 0.029572658, 0.027789488, 0.30089337};
  const int32_t perm[]          = {2, 1, 0};
  const int32_t number_of_perm  = 3;
  using dragonite::norm;

  ONNC_RUNTIME_transpose_float(nullptr, input_0, input_0_ndim, input_0_dims, output_0, output_0_ndim, output_0_dims,
                               const_cast<int32_t*>(perm), number_of_perm);
  ASSERT_TRUE(norm(answer_0, output_0, 24) <= 1e-5 * norm(answer_0, 24));
}
