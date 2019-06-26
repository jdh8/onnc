#include "dragonite.hpp"
SKYPAT_F(Operator_Gemm, test_gemm_broadcast) {
  const float input_0[] = {
      0.9846647,   0.41222116, 0.4132404,  0.84322864, 0.8971509, 0.397122,
      0.07958793,  0.8045958,  0.68694323, 0.15938434, 0.7684066, 0.65495163,
      0.025296818, 0.66772777, 0.24758904, 0.2993065,  0.851995,  0.6836684};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {6, 3};
  const float input_1[] = {
      0.590627,   0.51895994, 0.64928883, 0.13320155, 0.46908915, 0.7478581,
      0.6242087,  0.03219522, 0.1334937,  0.8251022,  0.6702302,  0.30658883,
      0.91595304, 0.35950398, 0.6583853,  0.538852,   0.8218876,  0.67839795,
      0.8955349,  0.32043648, 0.49136254, 0.7694568,  0.20773448, 0.9968269};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {4, 6};
  const float input_2[] = {0.88694143};
  const int32_t input_2_ndim = 2;
  const int32_t input_2_dims[] = {1, 1};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {1.107362,  0.8897886, 1.2270582, 1.252151,
                            1.5855795, 1.3116517, 1.8288132, 1.7590926,
                            1.2488981, 1.0826633, 1.440351,  1.479346};
  const float alpha = 0.5;
  const float beta = 0.5;
  const int32_t transA = 1;
  const int32_t transB = 1;
  ONNC_RUNTIME_gemm_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)input_1, input_1_ndim, input_1_dims,
                          (float *)input_2, input_2_ndim, input_2_dims,
                          (float *)output_0, output_0_ndim, output_0_dims,
                          alpha, beta, transA, transB);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Gemm, test_gemm_nobroadcast) {
  const float input_0[] = {
      0.048550863, 0.038253393, 0.5028614,  0.80091286, 0.62644327, 0.08322072,
      0.2280164,   0.06600759,  0.40633157, 0.61880034, 0.3978933,  0.5919173,
      0.2367972,   0.97442883,  0.520165,   0.88901824, 0.91364247, 0.3485419};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 6};
  const float input_1[] = {
      0.52383524, 0.9135216,  0.2021727,   0.15064569, 0.3857679,  0.633115,
      0.20874088, 0.35856307, 0.6470875,   0.93046755, 0.15542641, 0.48396268,
      0.90474707, 0.61256987, 0.054745022, 0.13538757, 0.68729836, 0.070637584,
      0.52751756, 0.5827395,  0.21985686,  0.53799474, 0.20967595, 0.31740355};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {6, 4};
  const float input_2[] = {0.29799432, 0.16262197,  0.043119293, 0.7365098,
                           0.48975602, 0.9070603,   0.8825669,   0.2838883,
                           0.56895345, 0.055248644, 0.52655536,  0.8384052};
  const int32_t input_2_ndim = 2;
  const int32_t input_2_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.9185264,  0.6393635, 0.26541656, 0.75040376,
                            0.93053055, 1.13042,   0.68674076, 0.52103895,
                            1.4572015,  1.0845636, 0.73119617, 1.1193092};
  const float alpha = 0.5;
  const float beta = 0.5;
  const int32_t transA = 0;
  const int32_t transB = 0;
  ONNC_RUNTIME_gemm_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)input_1, input_1_ndim, input_1_dims,
                          (float *)input_2, input_2_ndim, input_2_dims,
                          (float *)output_0, output_0_ndim, output_0_dims,
                          alpha, beta, transA, transB);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}
