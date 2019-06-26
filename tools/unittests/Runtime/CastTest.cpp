#include "dragonite.hpp"
SKYPAT_F(Operator_Cast, test_cast_FLOAT_to_FLOAT16) {
  const float input_0[] = {0.109825745, 0.44542944, 0.95506805, 0.16962087,
                           0.98504305,  0.42342332, 0.52250546, 0.5678486,
                           0.3079766,   0.8096478,  0.71010554, 0.13191335};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.1098, 0.4453, 0.955,  0.1697, 0.985, 0.4233,
                            0.5225, 0.568,  0.3079, 0.8096, 0.71,  0.132};
  const int32_t to = 10;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT_to_DOUBLE) {
  const float input_0[] = {0.36178547, 0.17974962, 0.9538848,  0.5918737,
                           0.7373839,  0.2212825,  0.57944673, 0.930124,
                           0.10459397, 0.26695532, 0.42594588, 0.21010198};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {
      0.3617854714393616,  0.17974962294101715, 0.9538847804069519,
      0.5918737053871155,  0.7373839020729065,  0.221282497048378,
      0.5794467329978943,  0.9301239848136902,  0.10459396988153458,
      0.26695531606674194, 0.42594587802886963, 0.21010197699069977};
  const int32_t to = 11;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT16_to_FLOAT) {
  const float input_0[] = {0.427,  0.269,   0.3672, 0.1667, 0.1787, 0.8003,
                           0.5586, 0.03574, 0.5083, 0.86,   0.1687, 0.3604};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.42700195, 0.26904297, 0.3671875,  0.16674805,
                            0.17871094, 0.80029297, 0.55859375, 0.035736084,
                            0.5083008,  0.8598633,  0.16870117, 0.36035156};
  const int32_t to = 1;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Cast, test_cast_FLOAT16_to_DOUBLE) {
  const float input_0[] = {0.1798, 0.4265,  0.1385, 0.9253, 0.3176, 0.9185,
                           0.8696, 0.07495, 0.808,  0.5093, 0.538,  0.2273};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.1798095703125, 0.426513671875, 0.1385498046875,
                            0.92529296875,   0.317626953125, 0.91845703125,
                            0.86962890625,   0.074951171875, 0.80810546875,
                            0.50927734375,   0.5380859375,   0.227294921875};
  const int32_t to = 11;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Cast, test_cast_DOUBLE_to_FLOAT) {
  const float input_0[] = {
      0.5747099600551578, 0.504053803543167,  0.265001157519381,
      0.8444616339829514, 0.5727141066923586, 0.15670242936270118,
      0.6706993023585412, 0.2979516069599034, 0.12113145604048137,
      0.5967492856873281, 0.7161686746148376, 0.3080275381549953};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.57470995, 0.50405383, 0.26500115, 0.8444616,
                            0.5727141,  0.15670243, 0.6706993,  0.2979516,
                            0.12113146, 0.5967493,  0.7161687,  0.30802754};
  const int32_t to = 1;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}

SKYPAT_F(Operator_Cast, test_cast_DOUBLE_to_FLOAT16) {
  const float input_0[] = {
      0.5994878803452957,  0.500363388638603,  0.2898036111463702,
      0.11799521873266072, 0.8392076261180297, 0.02349228678817028,
      0.47690077651238394, 0.5961995535266793, 0.2273028615178465,
      0.0366973058364628,  0.6506750065689226, 0.21969462775725523};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[12];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[] = {0.5996, 0.5005, 0.2898, 0.118,   0.8394, 0.0235,
                            0.4768, 0.596,  0.2273, 0.03668, 0.651,  0.2197};
  const int32_t to = 10;
  ONNC_RUNTIME_cast_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                          (float *)output_0, output_0_ndim, output_0_dims, to);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 12);
}
