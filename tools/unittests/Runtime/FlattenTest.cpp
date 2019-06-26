#include "dragonite.hpp"
SKYPAT_F(Operator_Flatten, test_flatten_axis0) {
  const float input_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 120};
  const float answer_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t axis = 0;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis1) {
  const float input_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 60};
  const float answer_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t axis = 1;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis2) {
  const float input_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {6, 20};
  const float answer_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t axis = 2;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis3) {
  const float input_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {24, 5};
  const float answer_0[] = {
      0.48843998,   0.78152716,  0.396502,    0.2770537,   0.85614336,
      0.0053997906, 0.9516462,   0.94981647,  0.31753758,  0.76578355,
      0.54385066,   0.24702127,  0.5653383,   0.50303996,  0.75387514,
      0.64670557,   0.91317016,  0.77890027,  0.7674491,   0.34720224,
      0.5622583,    0.23742777,  0.78052884,  0.2305104,   0.42151898,
      0.15120296,   0.0525574,   0.008200097, 0.6885983,   0.31832084,
      0.15072006,   0.4612759,   0.36590344,  0.04998588,  0.048226714,
      0.20414865,   0.036405034, 0.4439704,   0.73833394,  0.7557953,
      0.98379016,   0.49500436,  0.6928098,   0.8613642,   0.2785282,
      0.89162886,   0.13169147,  0.08127193,  0.79187924,  0.039822847,
      0.43193305,   0.9304574,   0.27305022,  0.16521733,  0.7451254,
      0.5858848,    0.9680353,   0.6532818,   0.8871093,   0.6960115,
      0.097917594,  0.62669164,  0.42233285,  0.679611,    0.18218063,
      0.65208125,   0.57246065,  0.037715584, 0.28474408,  0.43000627,
      0.56391346,   0.28477052,  0.70326644,  0.701349,    0.6399198,
      0.9734264,    0.92553383,  0.66888726,  0.08087935,  0.2852327,
      0.89859843,   0.5269712,   0.92033005,  0.09408771,  0.86889845,
      0.2634648,    0.10579509,  0.5040826,   0.45233688,  0.79501885,
      0.31750286,   0.5191643,   0.9129224,   0.039347533, 0.6576252,
      0.9332673,    0.84343725,  0.6028853,   0.5515687,   0.9057978,
      0.37011915,   0.12146635,  0.2846,      0.8156244,   0.51155305,
      0.6987658,    0.8469775,   0.18442915,  0.9863774,   0.19030571,
      0.7413883,    0.6176829,   0.41014487,  0.7020909,   0.4250128,
      0.39792418,   0.1187741,   0.16963013,  0.5664798,   0.6755137};
  const int32_t axis = 3;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}

SKYPAT_F(Operator_Flatten, test_flatten_default_axis) {
  const float input_0[] = {
      0.05561918, 0.17613861,  0.9549768,   0.24543482,  0.7857538,
      0.6310523,  0.47985464,  0.51341164,  0.29768676,  0.45308718,
      0.7726394,  0.39279836,  0.19243875,  0.87383366,  0.17905247,
      0.81187975, 0.6391179,   0.65674347,  0.9991364,   0.68864954,
      0.68936986, 0.041168854, 0.4047472,   0.3394014,   0.3801155,
      0.5720582,  0.4532514,   0.9025874,   0.62763005,  0.9860229,
      0.9818195,  0.84880817,  0.34019962,  0.3689464,   0.115404725,
      0.3833899,  0.80714405,  0.69230866,  0.3604232,   0.31572154,
      0.44033718, 0.807457,    0.7273027,   0.40204272,  0.6700362,
      0.20585003, 0.83711946,  0.29952878,  0.32716507,  0.51416886,
      0.68553156, 0.011780135, 0.2546251,   0.35513216,  0.23615022,
      0.6061807,  0.33817527,  0.69825435,  0.3935166,   0.13004857,
      0.9535991,  0.23971649,  0.019354213, 0.036389574, 0.39298865,
      0.9902029,  0.7576412,   0.2788745,   0.9934526,   0.4319844,
      0.5026003,  0.13572414,  0.39079845,  0.070271745, 0.10599014,
      0.71852,    0.51435,     0.040228512, 0.791387,    0.8650007,
      0.83672893, 0.3491531,   0.25034645,  0.9905244,   0.4062862,
      0.13062192, 0.24021852,  0.7433154,   0.028225277, 0.5374344,
      0.2880071,  0.99266165,  0.35529172,  0.554403,    0.6881921,
      0.53026295, 0.27992618,  0.83637804,  0.077219605, 0.39888453,
      0.3660927,  0.28717247,  0.2739316,   0.26899216,  0.34829026,
      0.4618529,  0.44191784,  0.5639386,   0.67814964,  0.27953503,
      0.36117435, 0.95149326,  0.7201945,   0.39751247,  0.9564544,
      0.36129612, 0.47133616,  0.5482152,   0.7599922,   0.5127826};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {5, 4, 3, 2};
  float output_0[120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {5, 24};
  const float answer_0[] = {
      0.05561918, 0.17613861,  0.9549768,   0.24543482,  0.7857538,
      0.6310523,  0.47985464,  0.51341164,  0.29768676,  0.45308718,
      0.7726394,  0.39279836,  0.19243875,  0.87383366,  0.17905247,
      0.81187975, 0.6391179,   0.65674347,  0.9991364,   0.68864954,
      0.68936986, 0.041168854, 0.4047472,   0.3394014,   0.3801155,
      0.5720582,  0.4532514,   0.9025874,   0.62763005,  0.9860229,
      0.9818195,  0.84880817,  0.34019962,  0.3689464,   0.115404725,
      0.3833899,  0.80714405,  0.69230866,  0.3604232,   0.31572154,
      0.44033718, 0.807457,    0.7273027,   0.40204272,  0.6700362,
      0.20585003, 0.83711946,  0.29952878,  0.32716507,  0.51416886,
      0.68553156, 0.011780135, 0.2546251,   0.35513216,  0.23615022,
      0.6061807,  0.33817527,  0.69825435,  0.3935166,   0.13004857,
      0.9535991,  0.23971649,  0.019354213, 0.036389574, 0.39298865,
      0.9902029,  0.7576412,   0.2788745,   0.9934526,   0.4319844,
      0.5026003,  0.13572414,  0.39079845,  0.070271745, 0.10599014,
      0.71852,    0.51435,     0.040228512, 0.791387,    0.8650007,
      0.83672893, 0.3491531,   0.25034645,  0.9905244,   0.4062862,
      0.13062192, 0.24021852,  0.7433154,   0.028225277, 0.5374344,
      0.2880071,  0.99266165,  0.35529172,  0.554403,    0.6881921,
      0.53026295, 0.27992618,  0.83637804,  0.077219605, 0.39888453,
      0.3660927,  0.28717247,  0.2739316,   0.26899216,  0.34829026,
      0.4618529,  0.44191784,  0.5639386,   0.67814964,  0.27953503,
      0.36117435, 0.95149326,  0.7201945,   0.39751247,  0.9564544,
      0.36129612, 0.47133616,  0.5482152,   0.7599922,   0.5127826};
  const int32_t axis = 0;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 120);
}
