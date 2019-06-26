#include "dragonite.hpp"
SKYPAT_F(Operator_Transpose, test_transpose_default) {
  const float input_0[] = {
      0.47823536, 0.33798894, 0.23681352,  0.74736303,  0.10555136, 0.7456113,
      0.8644907,  0.7785144,  0.34786403,  0.9167569,   0.6290914,  0.5454781,
      0.18705547, 0.1359344,  0.005183343, 0.8762904,   0.14589703, 0.8410207,
      0.6132695,  0.9989239,  0.3577919,   0.020005528, 0.8182367,  0.2914033};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 3, 2};
  const float answer_0[] = {
      0.47823536, 0.18705547,  0.10555136, 0.14589703, 0.34786403, 0.3577919,
      0.33798894, 0.1359344,   0.7456113,  0.8410207,  0.9167569,  0.020005528,
      0.23681352, 0.005183343, 0.8644907,  0.6132695,  0.6290914,  0.8182367,
      0.74736303, 0.8762904,   0.7785144,  0.9989239,  0.5454781,  0.2914033};
  const int32_t perm[] = {};
  const int32_t number_of_perm = 0;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_0) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 4};
  const float answer_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                            0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                            0.32019392,  0.67122966, 0.17435145, 0.65734667,
                            0.26447648,  0.98057157, 0.75554323, 0.11448738,
                            0.45933247,  0.15212761, 0.7896726,  0.40871048,
                            0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t perm[] = {0, 1, 2};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_1) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 4, 3};
  const float answer_0[] = {0.014320762, 0.41695225,  0.32019392,   0.8875817,
                            0.89284194,  0.67122966,  0.50006396,   0.8694754,
                            0.17435145,  0.077316254, 0.0075976746, 0.65734667,
                            0.26447648,  0.45933247,  0.17704771,   0.98057157,
                            0.15212761,  0.77671266,  0.75554323,   0.7896726,
                            0.621551,    0.11448738,  0.40871048,   0.4295814};
  const int32_t perm[] = {0, 2, 1};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_2) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 2, 4};
  const float answer_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                            0.26447648,  0.98057157, 0.75554323, 0.11448738,
                            0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                            0.45933247,  0.15212761, 0.7896726,  0.40871048,
                            0.32019392,  0.67122966, 0.17435145, 0.65734667,
                            0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t perm[] = {1, 0, 2};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_3) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 2};
  const float answer_0[] = {
      0.014320762, 0.26447648, 0.8875817,    0.98057157, 0.50006396, 0.75554323,
      0.077316254, 0.11448738, 0.41695225,   0.45933247, 0.89284194, 0.15212761,
      0.8694754,   0.7896726,  0.0075976746, 0.40871048, 0.32019392, 0.17704771,
      0.67122966,  0.77671266, 0.17435145,   0.621551,   0.65734667, 0.4295814};
  const int32_t perm[] = {1, 2, 0};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_4) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 2, 3};
  const float answer_0[] = {
      0.014320762, 0.41695225,   0.32019392, 0.26447648, 0.45933247, 0.17704771,
      0.8875817,   0.89284194,   0.67122966, 0.98057157, 0.15212761, 0.77671266,
      0.50006396,  0.8694754,    0.17435145, 0.75554323, 0.7896726,  0.621551,
      0.077316254, 0.0075976746, 0.65734667, 0.11448738, 0.40871048, 0.4295814};
  const int32_t perm[] = {2, 0, 1};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}

SKYPAT_F(Operator_Transpose, test_transpose_all_permutations_5) {
  const float input_0[] = {0.014320762, 0.8875817,  0.50006396, 0.077316254,
                           0.41695225,  0.89284194, 0.8694754,  0.0075976746,
                           0.32019392,  0.67122966, 0.17435145, 0.65734667,
                           0.26447648,  0.98057157, 0.75554323, 0.11448738,
                           0.45933247,  0.15212761, 0.7896726,  0.40871048,
                           0.17704771,  0.77671266, 0.621551,   0.4295814};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  float output_0[24];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {4, 3, 2};
  const float answer_0[] = {
      0.014320762, 0.26447648, 0.41695225,   0.45933247, 0.32019392, 0.17704771,
      0.8875817,   0.98057157, 0.89284194,   0.15212761, 0.67122966, 0.77671266,
      0.50006396,  0.75554323, 0.8694754,    0.7896726,  0.17435145, 0.621551,
      0.077316254, 0.11448738, 0.0075976746, 0.40871048, 0.65734667, 0.4295814};
  const int32_t perm[] = {2, 1, 0};
  const int32_t number_of_perm = 3;
  ONNC_RUNTIME_transpose_float(NULL, (float *)input_0, input_0_ndim,
                               input_0_dims, (float *)output_0, output_0_ndim,
                               output_0_dims, (int32_t *)perm, number_of_perm);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 24);
}
