#include "dragonite.hpp"
SKYPAT_F(Operator_Sub, test_sub_example) {
  const float input_0[] = {1.0, 2.0, 3.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  const float input_1[] = {3.0, 2.0, 1.0};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {-2.0, 0.0, 2.0};
  ONNC_RUNTIME_sub_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_Sub, test_sub) {
  const float input_0[] = {
      1.3734189,   -0.9516626,  -0.3432235,  0.10086306,  1.0996612,
      -1.9407214,  -0.82559466, 0.4924278,   -0.42231652, 0.59954756,
      0.95558864,  -1.1633328,  -1.5569774,  0.35791638,  0.87997997,
      1.7754022,   1.2653202,   -0.19259006, -0.13126004, -0.089729175,
      0.30199465,  -0.8418149,  1.0873438,   1.6213616,   -0.49471498,
      0.67560554,  0.49692166,  -0.43051216, -2.0570943,  0.2307219,
      0.49259657,  2.0295208,   -1.5276669,  0.2813559,   -0.657103,
      0.56608385,  1.5001882,   -1.4000081,  -0.3597998,  2.8724964,
      -0.93255055, 0.10335969,  0.108145975, -0.90139145, 0.0505579,
      0.7833189,   -0.42217895, -1.457789,   1.6639138,   1.6726711,
      0.5054574,   -1.9642898,  1.3975827,   -0.29708955, 0.23372915,
      -1.1444778,  0.6438796,   -1.1966587,  -1.7425561,  -2.0485172};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {
      -0.6802956,  -1.5365702,  -0.5629008,  0.42007533,   0.9291774,
      -1.0056045,  1.3304864,   -0.13449238, 2.1607287,    1.3807425,
      0.50304776,  -1.3585079,  0.7597808,   -0.7725575,   -1.0661516,
      -0.45585594, 0.09709802,  1.5569023,   1.6304966,    -0.1949908,
      0.23686276,  0.22270906,  -0.3937665,  -0.45932543,  2.1023571,
      -0.4427943,  0.05794514,  -0.8500769,  0.3237975,    -0.34721786,
      -1.0501546,  -0.16178633, -1.0025624,  -1.497695,    -0.5608552,
      0.9296828,   -0.77492625, 1.4296796,   1.9846112,    0.1022258,
      -0.1886862,  1.5979702,   -1.2308687,  1.6779437,    2.0250998,
      -0.08212207, 1.6766977,   -0.7577666,  -0.054329503, -0.8607251,
      0.12350076,  1.151294,    1.2579217,   -0.46523827,  -1.6067437,
      0.48465824,  0.43712732,  0.18966685,  1.4466658,    0.013638948};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      2.0537145,   0.5849076,  0.21967727,  -0.31921226, 0.17048383,
      -0.9351169,  -2.1560812, 0.62692016,  -2.5830452,  -0.781195,
      0.45254087,  0.19517505, -2.3167582,  1.1304739,   1.9461316,
      2.2312582,   1.1682222,  -1.7494924,  -1.7617567,  0.105261624,
      0.06513189,  -1.0645239, 1.4811103,   2.080687,    -2.5970721,
      1.1183999,   0.43897653, 0.41956475,  -2.3808918,  0.57793975,
      1.5427511,   2.191307,   -0.5251045,  1.7790508,   -0.09624779,
      -0.36359894, 2.2751145,  -2.8296876,  -2.344411,   2.7702706,
      -0.74386436, -1.4946105, 1.3390146,   -2.5793352,  -1.9745419,
      0.86544096,  -2.0988767, -0.70002234, 1.7182434,   2.5333962,
      0.38195664,  -3.115584,  0.13966095,  0.16814873,  1.8404728,
      -1.6291361,  0.20675227, -1.3863256,  -3.1892219,  -2.0621562};
  ONNC_RUNTIME_sub_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}

SKYPAT_F(Operator_Sub, test_sub_bcast) {
  const float input_0[] = {
      -0.27074814, 1.2596797,   0.6452691,   1.0007696,   -0.59499663,
      -1.5236818,  0.5212796,   -0.92868334, 1.7784307,   0.7013108,
      -0.47433043, -0.6488488,  -0.3294827,  0.4213994,   0.1223686,
      -1.0594126,  2.551423,    0.37900493,  0.43693584,  0.57613206,
      0.5759566,   -1.1540474,  -0.6049246,  -1.4048842,  0.42140064,
      -1.9701391,  0.14712317,  -0.2571364,  -1.9174345,  0.14205028,
      0.7154896,   1.7181188,   -0.52604175, -0.6106208,  0.13275349,
      -0.67274094, 0.97354126,  -0.8521468,  0.2587317,   -0.7728172,
      -0.15771134, 0.1118232,   -0.8354157,  -1.2005459,  -0.06258419,
      0.119956955, -0.36506635, 0.7625702,   0.024167718, -0.5517888,
      -0.3928664,  1.6986843,   -0.03058628, -2.4412067,  1.1234295,
      -0.5541199,  -0.50191814, -0.3532096,  -0.72978336, 0.49013782};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  const float input_1[] = {0.33734232, -0.5784825, 0.6802659, 1.2168983,
                           -0.2731737};
  const int32_t input_1_ndim = 1;
  const int32_t input_1_dims[] = {5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      -0.60809046, 1.8381622,   -0.034996808, -0.2161287, -0.32182294,
      -1.8610241,  1.0997621,   -1.6089492,   0.5615324,  0.9744845,
      -0.81167275, -0.07036626, -1.0097486,   -0.7954989, 0.3955423,
      -1.396755,   3.1299057,   -0.30126098,  -0.7799625, 0.84930575,
      0.23861426,  -0.57556486, -1.2851906,   -2.6217825, 0.69457436,
      -2.3074815,  0.72560567,  -0.9374023,   -3.1343327, 0.41522396,
      0.3781473,   2.2966013,   -1.2063076,   -1.8275192, 0.40592718,
      -1.0100832,  1.5520238,   -1.5324128,   -0.9581666, -0.4996435,
      -0.49505365, 0.6903057,   -1.5156816,   -2.4174442, 0.2105895,
      -0.21738537, 0.21341616,  0.0823043,    -1.1927305, -0.27861512,
      -0.73020875, 2.2771668,   -0.7108522,   -3.658105,  1.3966032,
      -0.8914622,  0.07656437,  -1.0334755,   -1.9466817, 0.7633115};
  ONNC_RUNTIME_sub_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)input_1, input_1_ndim, input_1_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
