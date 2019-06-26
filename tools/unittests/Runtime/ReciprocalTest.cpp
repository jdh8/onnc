#include "dragonite.hpp"
SKYPAT_F(Operator_Reciprocal, test_reciprocal_example) {
  const float input_0[] = {-4.0, 2.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {2};
  float output_0[2];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {2};
  const float answer_0[] = {-0.25, 0.5};
  ONNC_RUNTIME_reciprocal_float(NULL, (float *)input_0, input_0_ndim,
                                input_0_dims, (float *)output_0, output_0_ndim,
                                output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 2);
}

SKYPAT_F(Operator_Reciprocal, test_reciprocal) {
  const float input_0[] = {
      1.3748894,  1.2731409,  1.2611154,  0.6197882,  1.4356575, 1.3131111,
      0.73509383, 0.62394965, 1.3928361,  1.0044365,  1.3895389, 1.4209903,
      1.0018065,  1.3920631,  0.6621817,  0.6905248,  1.002002,  0.9270839,
      1.2343609,  0.60351944, 0.85743356, 1.4225336,  0.5802534, 1.4543121,
      0.5834221,  1.0424988,  1.3748609,  0.7852664,  0.725887,  0.62128985,
      1.0577286,  0.6976978,  1.2337382,  0.6959813,  1.3279824, 1.3798978,
      0.9614538,  1.379973,   1.0184119,  0.7048249,  1.0654342, 1.4445755,
      1.3208418,  1.4084744,  1.4419968,  0.51387024, 1.2196655, 1.0645411,
      1.4274409,  1.128139,   1.349505,   0.5203149,  1.0559132, 0.9335525,
      0.599116,   0.9087634,  1.2255479,  0.6689464,  1.0055107, 0.66386676};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[60];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[] = {
      0.7273312,  0.78545904, 0.79294884, 1.6134543, 0.69654495, 0.7615502,
      1.3603705,  1.6026934,  0.7179596,  0.9955831, 0.7196632,  0.7037346,
      0.9981968,  0.7183582,  1.5101596,  1.4481739, 0.998002,   1.0786511,
      0.81013584, 1.6569475,  1.1662711,  0.7029711, 1.723385,   0.6876103,
      1.7140248,  0.9592337,  0.7273463,  1.2734532, 1.3776249,  1.6095546,
      0.94542205, 1.4332852,  0.8105447,  1.4368201, 0.753022,   0.72469133,
      1.0400916,  0.7246518,  0.981921,   1.418792,  0.93858445, 0.6922449,
      0.75709295, 0.70998806, 0.6934828,  1.9460166, 0.81989694, 0.9393719,
      0.70055443, 0.8864156,  0.74101245, 1.9219131, 0.94704753, 1.071177,
      1.6691258,  1.1003964,  0.8159616,  1.4948881, 0.99451953, 1.5063263};
  ONNC_RUNTIME_reciprocal_float(NULL, (float *)input_0, input_0_ndim,
                                input_0_dims, (float *)output_0, output_0_ndim,
                                output_0_dims);
  (dragonite::verify)(reinterpret_cast<float *>(output_0),
                      reinterpret_cast<const float *>(answer_0), 60);
}
