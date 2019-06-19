#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_RNN, test_simple_rnn_defaults) {
  const float input_0[1][3][2] = {{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 2};
  const float input_1[1][4][2] = {{{0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 4, 2};
  const float input_2[1][4][4] = {{{0.10000000149011612, 0.10000000149011612,
                                    0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612,
                                    0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612,
                                    0.10000000149011612, 0.10000000149011612},
                                   {0.10000000149011612, 0.10000000149011612,
                                    0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 4, 4};
  const float input_3[] = {};
  const int32_t input_3_ndim = 0;
  const int32_t input_3_dims[] = {};
  const float input_4[] = {};
  const int32_t input_4_ndim = 0;
  const int32_t input_4_dims[] = {};
  const float input_5[] = {};
  const int32_t input_5_ndim = 0;
  const int32_t input_5_dims[] = {};
  float output_0[1][3][4];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 4};
  const float answer_0[1][3][4] = {{{0.2913126051425934, 0.2913126051425934,
                                     0.2913126051425934, 0.2913126051425934},
                                    {0.6043677926063538, 0.6043677926063538,
                                     0.6043677926063538, 0.6043677926063538},
                                    {0.8004990220069885, 0.8004990220069885,
                                     0.8004990220069885, 0.8004990220069885}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const int32_t hidden_size = 4;
  const auto direction = "NOTSET";
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_rnn_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)output_0, output_0_ndim, output_0_dims, (float *)output_1,
      output_1_ndim, output_1_dims, (float *)activation_alpha,
      number_of_activation_alpha, (float *)activation_beta,
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 4; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_RNN, test_simple_rnn_with_initial_bias) {
  const float input_0[1][3][3] = {
      {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {1, 3, 3};
  const float input_1[1][5][3] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 5, 3};
  const float input_2[1][5][5] = {
      {{0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612, 0.10000000149011612},
       {0.10000000149011612, 0.10000000149011612, 0.10000000149011612,
        0.10000000149011612, 0.10000000149011612}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 5, 5};
  const float input_3[1][10] = {{0.10000000149011612, 0.10000000149011612,
                                 0.10000000149011612, 0.10000000149011612,
                                 0.10000000149011612, 0.0, 0.0, 0.0, 0.0, 0.0}};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 10};
  const float input_4[] = {};
  const int32_t input_4_ndim = 0;
  const int32_t input_4_dims[] = {};
  const float input_5[] = {};
  const int32_t input_5_ndim = 0;
  const int32_t input_5_dims[] = {};
  float output_0[1][3][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[1][3][5] = {
      {{0.6043677926063538, 0.6043677926063538, 0.6043677926063538,
        0.6043677926063538, 0.6043677926063538},
       {0.921668529510498, 0.921668529510498, 0.921668529510498,
        0.921668529510498, 0.921668529510498},
       {0.9866142868995667, 0.9866142868995667, 0.9866142868995667,
        0.9866142868995667, 0.9866142868995667}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const int32_t hidden_size = 5;
  const auto direction = "NOTSET";
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_rnn_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)output_0, output_0_ndim, output_0_dims, (float *)output_1,
      output_1_ndim, output_1_dims, (float *)activation_alpha,
      number_of_activation_alpha, (float *)activation_beta,
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 5; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_RNN, test_rnn_seq_length) {
  const float input_0[2][3][3] = {
      {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}},
      {{10.0, 11.0, 12.0}, {13.0, 14.0, 15.0}, {16.0, 17.0, 18.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {2, 3, 3};
  const float input_1[1][5][3] = {
      {{-0.7535048127174377, -1.032403588294983, 0.7908216714859009},
       {-0.4019339978694916, 0.12476959824562073, -1.5757571458816528},
       {1.3801883459091187, -0.8079874515533447, 0.5594021677970886},
       {-0.11904758214950562, 0.5086569786071777, 0.10401233285665512},
       {-0.36065998673439026, 0.005338471848517656, -0.5952719449996948}}};
  const int32_t input_1_ndim = 3;
  const int32_t input_1_dims[] = {1, 5, 3};
  const float input_2[1][5][5] = {
      {{1.6799794435501099, -0.7546226978302002, -1.3208976984024048,
        -0.7343467473983765, 0.8522335290908813},
       {0.16981345415115356, -0.537855863571167, -0.35208404064178467,
        0.30601567029953003, 0.5849159955978394},
       {0.24974142014980316, -0.33888712525367737, 0.7688305974006653,
        0.6310318112373352, -0.41030561923980713},
       {1.1538225412368774, -0.1017393097281456, 0.9972646832466125,
        0.8868469595909119, 1.4344691038131714},
       {1.6324089765548706, 1.2191252708435059, 0.05821453779935837,
        -0.30858877301216125, -0.40339282155036926}}};
  const int32_t input_2_ndim = 3;
  const int32_t input_2_dims[] = {1, 5, 5};
  const float input_3[1][10] = {{1.002077579498291, -0.11721217632293701,
                                 2.245359420776367, -0.5789663791656494,
                                 0.40179675817489624, -0.620101809501648,
                                 1.5944396257400513, 0.8073360323905945,
                                 0.4594634473323822, -1.3110263347625732}};
  const int32_t input_3_ndim = 2;
  const int32_t input_3_dims[] = {1, 10};
  const float input_4[] = {};
  const int32_t input_4_ndim = 0;
  const int32_t input_4_dims[] = {};
  const float input_5[] = {};
  const int32_t input_5_ndim = 0;
  const int32_t input_5_dims[] = {};
  float output_0[1][3][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {1, 3, 5};
  const float answer_0[1][3][5] = {
      {{-1.0, -1.0, 1.0, 0.999983012676239, -1.0},
       {-1.0, -1.0, 1.0, 0.9999945759773254, -1.0},
       {-1.0, -1.0, 1.0, 0.9999997019767761, -1.0}}};
  const float output_1[] = {};
  const int32_t output_1_ndim = 0;
  const int32_t output_1_dims[] = {};
  const int32_t hidden_size = 5;
  const auto direction = "NOTSET";
  const float clip = 0;
  const float activation_beta[] = {};
  const int32_t number_of_activation_beta = 0;
  const float activation_alpha[] = {};
  const int32_t number_of_activation_alpha = 0;
  ONNC_RUNTIME_rnn_float(
      NULL, (float *)input_0, input_0_ndim, input_0_dims, (float *)input_1,
      input_1_ndim, input_1_dims, (float *)input_2, input_2_ndim, input_2_dims,
      (float *)input_3, input_3_ndim, input_3_dims, (float *)input_4,
      input_4_ndim, input_4_dims, (float *)input_5, input_5_ndim, input_5_dims,
      (float *)output_0, output_0_ndim, output_0_dims, (float *)output_1,
      output_1_ndim, output_1_dims, (float *)activation_alpha,
      number_of_activation_alpha, (float *)activation_beta,
      number_of_activation_beta, activations, number_of_activations, clip,
      direction, hidden_size);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 3 * 5; ++i) {
    if (abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
