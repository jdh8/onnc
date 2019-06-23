#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Elu, test_elu_example) {
  const float input_0[3] = {-1.0, 0.0, 1.0};
  const int32_t input_0_ndim = 1;
  const int32_t input_0_dims[] = {3};
  float output_0[3];
  const int32_t output_0_ndim = 1;
  const int32_t output_0_dims[] = {3};
  const float answer_0[3] = {-1.264241099357605, 0.0, 1.0};
  const float alpha = 2.0;
  ONNC_RUNTIME_elu_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims,
                         alpha);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Elu, test_elu) {
  const float input_0[3][4][5] = {
      {{1.298768162727356, 0.7844391465187073, -0.046952828764915466,
        -0.6950499415397644, 0.7041059732437134},
       {-0.9078470468521118, -1.6209343671798706, 0.21780620515346527,
        0.2138770967721939, 1.5595426559448242},
       {0.8147783279418945, 1.529232382774353, 1.6489167213439941,
        1.1591976881027222, -0.7163100838661194},
       {-0.8865781426429749, 1.2219195365905762, -1.6003729104995728,
        0.3214840590953827, 0.7215641140937805}},
      {{-0.6932557225227356, 0.12839871644973755, 0.7474334239959717,
        -0.8617329001426697, 0.1852080523967743},
       {-0.8663742542266846, 1.453031301498413, -0.719021201133728,
        -0.7010961771011353, -1.107582449913025},
       {0.19481424987316132, 0.6236795783042908, -0.08117087930440903,
        -0.3580367863178253, -0.06347435712814331},
       {-0.09789600968360901, 0.2630636990070343, -0.26379454135894775,
        -0.882407546043396, 1.1518827676773071}},
      {{-0.4541504681110382, 0.8964971303939819, -0.081151083111763,
        -0.5229401588439941, 0.2215297371149063},
       {0.19273759424686432, 1.191772222518921, 0.38367417454719543,
        0.5714437365531921, 0.268279492855072},
       {-1.3499034643173218, 0.853847861289978, 1.2055295705795288,
        0.9031747579574585, -2.7321157455444336},
       {0.15282660722732544, -0.07998786866664886, -1.6578142642974854,
        0.16833224892616272, -1.0264555215835571}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {
      {{1.298768162727356, 0.7844391465187073, -0.09173524379730225,
        -1.0019009113311768, 0.7041059732437134},
       {-1.1932164430618286, -1.6045722961425781, 0.21780620515346527,
        0.2138770967721939, 1.5595426559448242},
       {0.8147783279418945, 1.529232382774353, 1.6489167213439941,
        1.1591976881027222, -1.0228967666625977},
       {-1.1758732795715332, 1.2219195365905762, -1.5963575839996338,
        0.3214840590953827, 0.7215641140937805}},
      {{-1.0001084804534912, 0.12839871644973755, 0.7474334239959717,
        -1.1551411151885986, 0.1852080523967743},
       {-1.1590533256530762, 1.453031301498413, -1.025542140007019,
        -1.0079174041748047, -1.3392866849899292},
       {0.19481424987316132, 0.6236795783042908, -0.15592777729034424,
        -0.6019052267074585, -0.12300360202789307},
       {-0.18651366233825684, 0.2630636990070343, -0.4637373685836792,
        -1.1724289655685425, 1.1518827676773071}},
      {{-0.7300256490707397, 0.8964971303939819, -0.1558912992477417,
        -0.8144497871398926, 0.2215297371149063},
       {0.19273759424686432, 1.191772222518921, 0.38367417454719543,
        0.5714437365531921, 0.268279492855072},
       {-1.4814693927764893, 0.853847861289978, 1.2055295705795288,
        0.9031747579574585, -1.8698370456695557},
       {0.15282660722732544, -0.15374493598937988, -1.6188899278640747,
        0.16833224892616272, -1.2834508419036865}}};
  const float alpha = 2.0;
  ONNC_RUNTIME_elu_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims,
                         alpha);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4 * 5; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Elu, test_elu_default) {
  const float input_0[3][4][5] = {
      {{-1.3205854892730713, 0.6715666651725769, -0.8783376216888428,
        -0.09955281019210815, -1.521297812461853},
       {-0.5533450245857239, -1.412691593170166, -1.1978733539581299,
        -0.7068461179733276, 1.6171237230300903},
       {0.4733845591545105, -0.8912200927734375, 0.5154598355293274,
        1.3845233917236328, -0.6343504786491394},
       {0.3834548592567444, 0.4599809944629669, 0.9176491498947144,
        0.08791236579418182, 0.017484400421380997}},
      {{-0.2953641712665558, -0.33190661668777466, -0.03867181017994881,
        0.15323874354362488, -0.2256619781255722},
       {0.04982777684926987, 0.5065223574638367, -0.6805880665779114,
        0.9789365530014038, 2.080406427383423},
       {-0.01846585050225258, -0.7031064629554749, -0.28309187293052673,
        0.5243366956710815, -0.08151920139789581},
       {1.9050594568252563, 1.5348073244094849, 0.6169315576553345,
        0.8156124949455261, 1.1824811697006226}},
      {{0.2280139923095703, -1.2701143026351929, 0.27720630168914795,
        -0.6199722290039062, -0.27192872762680054},
       {1.1627302169799805, -0.6637595295906067, -0.07891689985990524,
        0.539936900138855, 0.14263111352920532},
       {0.07191050797700882, -1.2969168424606323, -0.07990901172161102,
        -0.8176324367523193, 1.0240259170532227},
       {-0.7360738515853882, 1.2736852169036865, 0.6288952231407166,
        0.11681514233350754, -0.6340362429618835}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {
      {{-0.7330210208892822, 0.6715666651725769, -0.5845270156860352,
        -0.09475785493850708, -0.7815717458724976},
       {-0.4249768853187561, -0.7565129995346069, -0.6981645822525024,
        -0.5068027973175049, 1.6171237230300903},
       {0.4733845591545105, -0.5898449420928955, 0.5154598355293274,
        1.3845233917236328, -0.46972018480300903},
       {0.3834548592567444, 0.4599809944629669, 0.9176491498947144,
        0.08791236579418182, 0.017484400421380997}},
      {{-0.2557395100593567, -0.28244566917419434, -0.0379335880279541,
        0.15323874354362488, -0.20201218128204346},
       {0.04982777684926987, 0.5065223574638367, -0.49368083477020264,
        0.9789365530014038, 2.080406427383423},
       {-0.018296420574188232, -0.5049549341201782, -0.24654942750930786,
        0.5243366956710815, -0.07828497886657715},
       {1.9050594568252563, 1.5348073244094849, 0.6169315576553345,
        0.8156124949455261, 1.1824811697006226}},
      {{0.2280139923095703, -0.7192004919052124, 0.27720630168914795,
        -0.46204060316085815, -0.23809140920639038},
       {1.1627302169799805, -0.4850881099700928, -0.07588326930999756,
        0.539936900138855, 0.14263111352920532},
       {0.07191050797700882, -0.7266266345977783, -0.07679963111877441,
        -0.5585243701934814, 1.0240259170532227},
       {-0.5210092067718506, 1.2736852169036865, 0.6288952231407166,
        0.11681514233350754, -0.46955353021621704}}};
  const float alpha = 0;
  ONNC_RUNTIME_elu_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims,
                         alpha);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4 * 5; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}
