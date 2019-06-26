#include "dragonite.hpp"
SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_desc_axes) {
  const float input_0[] = {
      0.5112101,   0.03896502, 0.9666288,  0.42086965,  0.34205732,
      0.5992428,   0.47862098, 0.7632959,  0.66673183,  0.3144362,
      0.893877,    0.22892787, 0.6081481,  0.33180285,  0.25929078,
      0.21808381,  0.90862757, 0.57554287, 0.28611216,  0.9964679,
      0.3799162,   0.14739972, 0.30601007, 0.024637887, 0.03558814,
      0.82843834,  0.48436174, 0.12225105, 0.7396784,   0.21631542,
      0.65043294,  0.19603467, 0.9976745,  0.24127464,  0.42142165,
      0.051277984, 0.7614275,  0.8450379,  0.7116902,   0.70676386,
      0.104693085, 0.43915415, 0.43112227, 0.20932811,  0.83551145,
      0.4842262,   0.8959911,  0.32816154, 0.1370737,   0.075683236,
      0.046342943, 0.22584645, 0.5874194,  0.3560253,   0.42078206,
      0.17823629,  0.36606637, 0.42079392, 0.4625767,   0.28069183};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[] = {2.342665, 2.1824079, 1.9859171};
  const int32_t axes[] = {2, 1};
  const int32_t number_of_axes = 2;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducelogsum_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 3);
}

SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_asc_axes) {
  const float input_0[] = {
      0.5144536,   0.03757005, 0.21952625, 0.2967712,   0.13879201,
      0.22373632,  0.8914645,  0.09772803, 0.5902695,   0.78877914,
      0.084093906, 0.17289717, 0.9490194,  0.55726767,  0.25654042,
      0.6063417,   0.43815836, 0.1538105,  0.9497127,   0.5957572,
      0.44522622,  0.431431,   0.86657554, 0.8583456,   0.12835112,
      0.05078643,  0.23336683, 0.91851306, 0.57056165,  0.19977024,
      0.015126707, 0.97202605, 0.27069435, 0.6470404,   0.5087041,
      0.26629615,  0.05070931, 0.22166246, 0.18451117,  0.54703045,
      0.94540524,  0.24606927, 0.9839562,  0.36515197,  0.7030616,
      0.14359334,  0.504971,   0.6357383,  0.7386382,   0.64086485,
      0.010135576, 0.8151763,  0.70701647, 0.55417925,  0.08886272,
      0.7687362,   0.12025413, 0.42829686, 0.057957523, 0.12178946};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[5];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {5};
  const float answer_0[] = {1.4046085, 1.5921074, 1.8644735, 1.8516634,
                            1.5514493};
  const int32_t axes[] = {0, 1};
  const int32_t number_of_axes = 2;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducelogsum_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 5);
}

SKYPAT_F(Operator_ReduceLogSum, test_reduce_log_sum_default) {
  const float input_0[] = {
      0.60365975, 0.31806707,  0.09253795,  0.9528411,  0.6750225,   0.4722234,
      0.37127823, 0.7896982,   0.521692,    0.7500017,  0.0828514,   0.3924127,
      0.49377465, 0.1104239,   0.05519524,  0.8471306,  0.8022273,   0.68917394,
      0.51484025, 0.75429153,  0.8835515,   0.40915942, 0.86861455,  0.6367641,
      0.5795622,  0.62528205,  0.16796026,  0.35260752, 0.6156317,   0.15987284,
      0.03038283, 0.76125443,  0.020423286, 0.6723424,  0.106790625, 0.7484319,
      0.19602919, 0.42211094,  0.7729481,   0.19322284, 0.11495745,  0.8046739,
      0.36301246, 0.17210922,  0.15463413,  0.360179,   0.60292035,  0.31422734,
      0.6015797,  0.059393615, 0.3427611,   0.30619174, 0.10187309,  0.92660904,
      0.1711264,  0.9753938,   0.41935694,  0.66893,    0.11813063,  0.7821484};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[1];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 1, 1};
  const float answer_0[] = {3.3276403};
  const int32_t axes[] = {};
  const int32_t number_of_axes = 0;
  const int32_t keepdims = 0;
  ONNC_RUNTIME_reducelogsum_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)output_0,
      output_0_ndim, output_0_dims, (int32_t *)axes, number_of_axes, keepdims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 1);
}
