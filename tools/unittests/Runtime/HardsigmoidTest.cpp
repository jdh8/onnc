#include "dragonite.hpp"
SKYPAT_F(Operator_HardSigmoid, test_hardsigmoid_example) {
  const float input_0[] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {0.100000024, 0.6, 1.0};
  const float alpha = 0.5;
  const float beta = 0.6000000238418579;
  ONNC_RUNTIME_hardsigmoid_float(NULL, (float *)input_0, input_0_ndim,
                                 input_0_dims, (float *)output_0, output_0_ndim,
                                 output_0_dims, alpha, beta);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_HardSigmoid, test_hardsigmoid) {
  const float input_0[] = {
      0.47694665,  0.32020637,  -0.92721003,  1.1580427,    -0.22977878,
      0.8487123,   -0.7710159,  -1.1680149,   0.12120893,   0.5653172,
      1.0914445,   1.798554,    -0.83633655,  -0.754881,    -0.35259175,
      -0.65851974, 1.6788988,   0.33028892,   -0.082275584, 0.56499577,
      1.0230483,   0.30836678,  -0.73040247,  0.52583784,   2.2271135,
      -0.80095834, 0.5253291,   0.15668176,   -0.13454267,  -1.4589181,
      -1.1553236,  0.6125777,   -0.884542,    0.030511204,  1.415013,
      1.181231,    -0.7153091,  0.31564292,   0.3293097,    -0.924366,
      -0.95982665, -0.5617243,  0.057641644,  0.40537837,   0.1381077,
      0.10267059,  -0.12674603, -0.078101754, -0.730711,    -2.7226846,
      -1.7180854,  -0.28480187, 0.30858052,   -0.63490146,  0.9155537,
      1.3535998,   -1.7905152,  0.042214993,  -0.17712748,  -0.29807663};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.8384733,   0.7601032,   0.136395,   1.0,        0.48511064, 1.0,
      0.21449208,  0.015992582, 0.6606045,  0.8826586,  1.0,        1.0,
      0.18183175,  0.22255951,  0.42370415, 0.27074015, 1.0,        0.76514447,
      0.5588622,   0.8824979,   1.0,        0.7541834,  0.23479879, 0.862919,
      1.0,         0.19952086,  0.8626646,  0.6783409,  0.5327287,  0.0,
      0.022338212, 0.90628886,  0.15772903, 0.61525565, 1.0,        1.0,
      0.24234548,  0.7578215,   0.7646549,  0.13781703, 0.1200867,  0.31913787,
      0.62882084,  0.8026892,   0.66905385, 0.6513353,  0.536627,   0.56094915,
      0.23464453,  0.0,         0.0,        0.4575991,  0.7542903,  0.2825493,
      1.0,         1.0,         0.0,        0.6211075,  0.5114363,  0.4509617};
  const float alpha = 0.5;
  const float beta = 0.6000000238418579;
  ONNC_RUNTIME_hardsigmoid_float(NULL, (float *)input_0, input_0_ndim,
                                 input_0_dims, (float *)output_0, output_0_ndim,
                                 output_0_dims, alpha, beta);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_HardSigmoid, test_hardsigmoid_default) {
  const float input_0[] = {
      -1.5808558,  0.3228555,   0.75991553,  0.23716624,  -0.034546003,
      -0.4666155,  1.560917,    0.66013914,  0.72147924,  -0.5498639,
      0.82468086,  1.5300249,   -0.7395853,  0.25129834,  -0.046354756,
      -0.4350197,  -0.34678173, -0.20951219, 0.7272616,   -1.1353674,
      1.150008,    -0.7356186,  0.5884748,   -0.6642897,  -0.007912348,
      -0.58212805, 0.7719116,   0.67225295,  1.5610034,   0.1204402,
      0.086112246, 0.16330285,  1.1153042,   -0.10390937, 1.1217041,
      0.28394288,  0.25107935,  -0.42797744, 0.60714537,  0.904648,
      -0.67044497, 1.1994874,   0.8810788,   -0.6150449,  1.6763815,
      1.2829558,   1.1263721,   -0.2462358,  -0.66466016, -1.8747984,
      -0.6719843,  -0.7965138,  0.09117919,  -0.22060083, -0.49260986,
      0.34235284,  0.43510628,  -0.6425177,  1.0064261,   1.6644766};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.18382883, 0.5645711,  0.65198314, 0.54743326, 0.4930908,  0.4066769,
      0.8121834,  0.63202786, 0.6442959,  0.39002723, 0.6649362,  0.806005,
      0.35208294, 0.55025965, 0.49072903, 0.41299605, 0.43064365, 0.45809758,
      0.6454523,  0.2729265,  0.73000157, 0.35287628, 0.617695,   0.36714205,
      0.49841753, 0.3835744,  0.65438235, 0.6344506,  0.81220067, 0.524088,
      0.51722246, 0.53266054, 0.72306085, 0.47921813, 0.7243408,  0.55678856,
      0.55021584, 0.4144045,  0.6214291,  0.6809296,  0.365911,   0.7398975,
      0.67621577, 0.37699103, 0.8352763,  0.7565912,  0.72527444, 0.45075285,
      0.36706796, 0.12504032, 0.36560315, 0.34069723, 0.51823586, 0.45587984,
      0.40147802, 0.5684706,  0.58702123, 0.37149644, 0.70128524, 0.83289534};
  const float alpha = 0;
  const float beta = 0;
  ONNC_RUNTIME_hardsigmoid_float(NULL, (float *)input_0, input_0_ndim,
                                 input_0_dims, (float *)output_0, output_0_ndim,
                                 output_0_dims, alpha, beta);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
