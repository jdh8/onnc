#include "dragonite.hpp"
SKYPAT_F(Operator_MatMul, test_matmul_2d) {
  const float input_0[] = {1.5970869,   0.5700245,  -0.9924177,  -1.102506,
                           0.4443646,   -1.6320412, -0.17033572, -0.6852744,
                           -0.41731808, -0.3951829, 1.3125838,   -1.75089};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  const float input_1[] = {-1.6448452,  0.054153673, 0.5230634,  0.74079114,
                           -0.41725868, 0.37499288,  -1.1457133, -1.4568381,
                           -0.41222018, -1.4422321,  1.5516766,  0.27876097};
  const int32_t input_1_ndim = 2;
  const int32_t input_1_dims[] = {4, 3};
  float output_0[9];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 3};
  const float answer_0[] = {0.5224042,   -0.41630045, 1.1508918,
                            -0.75643206, -0.11012534, -0.5003849,
                            1.4150208,   -4.486743,   -1.395628};
  ONNC_RUNTIME_matmul_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 9);
}

SKYPAT_F(Operator_MatMul, test_matmul_3d) {
  const float input_0[] = {-0.35935652, -0.42114124, 0.17842864,   -0.41377723,
                           0.83724034,  0.08996058,  -1.1821073,   -1.207386,
                           -1.1013,     0.46579877,  -0.11030024,  -0.34330583,
                           -0.8419565,  -1.1897916,  -2.5824773,   0.7261288,
                           -0.5749214,  0.90427566,  -0.076770864, -0.45637167,
                           0.562091,    -0.06214223, 0.095363215,  1.4614567};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 4};
  const float input_1[] = {
      0.7651236,  1.836241,   0.09377481, 1.0007886,   0.5074843,  0.36114845,
      0.0811165,  -2.1014297, -0.6702664, 0.30814728,  0.1512426,  0.1727031,
      0.71544796, -1.4547821, 0.15894406, -1.3075743,  -1.7499357, 1.6990155,
      -0.8097276, -0.2776204, 1.6527284,  -0.42778584, -1.1614431, -0.9992926};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {2, 4, 3};
  float output_0[18];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {2, 3, 3};
  const float answer_0[] = {
      -0.80945635, -1.3111237, -0.3768484, 0.26268268,  3.8845358,  0.69480866,
      -0.49120048, -1.606001,  0.07958887, 2.7338402,   3.1805131,  -7.149047,
      -1.3363411,  -0.194676,  1.7741655,  -0.21900627, -2.4328485, -1.3190529};
  ONNC_RUNTIME_matmul_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 18);
}

SKYPAT_F(Operator_MatMul, test_matmul_4d) {
  const float input_0[] = {-0.5044314,  -0.047049575, -1.1811986, 0.34107274,
                           -0.95406026, -0.94840217,  0.7902696,  0.6790108,
                           0.46498367,  0.06862673,   -2.5453594, 0.3529695,
                           0.5269424,   0.535199,     -1.4037958, 0.3943483,
                           0.22552824,  -0.7023365,   0.39657137, -0.66778857,
                           -0.39797226, -0.33801436,  -1.1724232, 0.15573765};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {1, 2, 3, 4};
  const float input_1[] = {-0.5780848,  1.3849621,   -0.4571063,  0.9710251,
                           -0.7132903,  -0.7165883,  1.2734983,   -1.0834506,
                           -0.18598975, -0.16113843, 0.6203156,   -1.2389466,
                           0.24583286,  -0.4023484,  -1.0291328,  0.3274599,
                           -1.317037,   -0.395478,   0.14809431,  -0.40024465,
                           -1.036705,   0.6214503,   -0.12276652, 1.0138401};
  const int32_t input_1_ndim = 4;
  const int32_t input_1_dims[] = {1, 2, 4, 3};
  float output_0[18];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {1, 2, 3, 3};
  const float answer_0[] = {
      -1.3132964, 0.8262846, 0.061413903, 0.52759767, -1.0798683,  0.12748069,
      -3.5005496, 3.5717573, -0.22562367, 0.34196964, -0.40344226, 1.1011752,
      -0.5308122, 0.7575187, -1.0424982,  -0.2853668, 1.0554377,   1.9165937};
  ONNC_RUNTIME_matmul_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                            (float *)input_1, input_1_ndim, input_1_dims,
                            (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 18);
}
