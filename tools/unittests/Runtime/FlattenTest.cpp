#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Flatten, test_flatten_axis0) {
  const float input_0[2][3][4][5] = {
      {{{0.475782573223114, 0.17737644910812378, 0.2686356008052826,
         0.13434721529483795, 0.6576226949691772},
        {0.7030077576637268, 0.9209692478179932, 0.9242821931838989,
         0.8460663557052612, 0.7890874147415161},
        {0.6322358846664429, 0.23658999800682068, 0.36220094561576843,
         0.33706915378570557, 0.0775298923254013},
        {0.5300828218460083, 0.5354111790657043, 0.8545095920562744,
         0.5338646769523621, 0.37087297439575195}},
       {{0.5252850651741028, 0.13006305694580078, 0.27607348561286926,
         0.29916810989379883, 0.5018289685249329},
        {0.15546941757202148, 0.8042718768119812, 0.5045357346534729,
         0.4063466489315033, 0.18431293964385986},
        {0.39942383766174316, 0.769119143486023, 0.3223990201950073,
         0.9254138469696045, 0.4391845464706421},
        {0.8436281085014343, 0.26444512605667114, 0.3205794394016266,
         0.28365275263786316, 0.9028468132019043}},
       {{0.9950684309005737, 0.07097373157739639, 0.6037342548370361,
         0.8829789757728577, 0.3247211277484894},
        {0.8993489146232605, 0.2146441489458084, 0.27531322836875916,
         0.5409069061279297, 0.5658105611801147},
        {0.08075195550918579, 0.9044844508171082, 0.986808180809021,
         0.21508102118968964, 0.1619407832622528},
        {0.6783815026283264, 0.10092660039663315, 0.4767557680606842,
         0.031327057629823685, 0.1487768441438675}}},
      {{{0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
         0.6458512544631958, 0.8537090420722961},
        {0.9656611084938049, 0.31318214535713196, 0.6329669952392578,
         0.772528350353241, 0.35660672187805176},
        {0.6847124695777893, 0.876224935054779, 0.5572085380554199,
         0.804850697517395, 0.4376949369907379},
        {0.6456229090690613, 0.7696112394332886, 0.03618588671088219,
         0.8575048446655273, 0.5548474788665771}},
       {{0.2269730567932129, 0.7364659309387207, 0.27601030468940735,
         0.9168832302093506, 0.627094566822052},
        {0.35735565423965454, 0.16407112777233124, 0.5200456976890564,
         0.14997746050357819, 0.31148043274879456},
        {0.8584154844284058, 0.7192798256874084, 0.6552888751029968,
         0.45744556188583374, 0.30065035820007324},
        {0.8243831396102905, 0.40757670998573303, 0.9683871865272522,
         0.0344025194644928, 0.8810514211654663}},
       {{0.15895137190818787, 0.8111627101898193, 0.7949113249778748,
         0.05331829562783241, 0.31034180521965027},
        {0.7896537184715271, 0.12723813951015472, 0.38409972190856934,
         0.3256235420703888, 0.32709842920303345},
        {0.8023419976234436, 0.7965673208236694, 0.281536728143692,
         0.45081040263175964, 0.9933833479881287},
        {0.5719109177589417, 0.22103622555732727, 0.4951089024543762,
         0.49796757102012634, 0.8491216897964478}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[1][120];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {1, 120};
  const float answer_0[1][120] = {
      {0.475782573223114,   0.17737644910812378,  0.2686356008052826,
       0.13434721529483795, 0.6576226949691772,   0.7030077576637268,
       0.9209692478179932,  0.9242821931838989,   0.8460663557052612,
       0.7890874147415161,  0.6322358846664429,   0.23658999800682068,
       0.36220094561576843, 0.33706915378570557,  0.0775298923254013,
       0.5300828218460083,  0.5354111790657043,   0.8545095920562744,
       0.5338646769523621,  0.37087297439575195,  0.5252850651741028,
       0.13006305694580078, 0.27607348561286926,  0.29916810989379883,
       0.5018289685249329,  0.15546941757202148,  0.8042718768119812,
       0.5045357346534729,  0.4063466489315033,   0.18431293964385986,
       0.39942383766174316, 0.769119143486023,    0.3223990201950073,
       0.9254138469696045,  0.4391845464706421,   0.8436281085014343,
       0.26444512605667114, 0.3205794394016266,   0.28365275263786316,
       0.9028468132019043,  0.9950684309005737,   0.07097373157739639,
       0.6037342548370361,  0.8829789757728577,   0.3247211277484894,
       0.8993489146232605,  0.2146441489458084,   0.27531322836875916,
       0.5409069061279297,  0.5658105611801147,   0.08075195550918579,
       0.9044844508171082,  0.986808180809021,    0.21508102118968964,
       0.1619407832622528,  0.6783815026283264,   0.10092660039663315,
       0.4767557680606842,  0.031327057629823685, 0.1487768441438675,
       0.24404151737689972, 0.6688364744186401,   0.4016159474849701,
       0.6458512544631958,  0.8537090420722961,   0.9656611084938049,
       0.31318214535713196, 0.6329669952392578,   0.772528350353241,
       0.35660672187805176, 0.6847124695777893,   0.876224935054779,
       0.5572085380554199,  0.804850697517395,    0.4376949369907379,
       0.6456229090690613,  0.7696112394332886,   0.03618588671088219,
       0.8575048446655273,  0.5548474788665771,   0.2269730567932129,
       0.7364659309387207,  0.27601030468940735,  0.9168832302093506,
       0.627094566822052,   0.35735565423965454,  0.16407112777233124,
       0.5200456976890564,  0.14997746050357819,  0.31148043274879456,
       0.8584154844284058,  0.7192798256874084,   0.6552888751029968,
       0.45744556188583374, 0.30065035820007324,  0.8243831396102905,
       0.40757670998573303, 0.9683871865272522,   0.0344025194644928,
       0.8810514211654663,  0.15895137190818787,  0.8111627101898193,
       0.7949113249778748,  0.05331829562783241,  0.31034180521965027,
       0.7896537184715271,  0.12723813951015472,  0.38409972190856934,
       0.3256235420703888,  0.32709842920303345,  0.8023419976234436,
       0.7965673208236694,  0.281536728143692,    0.45081040263175964,
       0.9933833479881287,  0.5719109177589417,   0.22103622555732727,
       0.4951089024543762,  0.49796757102012634,  0.8491216897964478}};
  const int32_t axis = 0;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 1 * 120; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis1) {
  const float input_0[2][3][4][5] = {
      {{{0.475782573223114, 0.17737644910812378, 0.2686356008052826,
         0.13434721529483795, 0.6576226949691772},
        {0.7030077576637268, 0.9209692478179932, 0.9242821931838989,
         0.8460663557052612, 0.7890874147415161},
        {0.6322358846664429, 0.23658999800682068, 0.36220094561576843,
         0.33706915378570557, 0.0775298923254013},
        {0.5300828218460083, 0.5354111790657043, 0.8545095920562744,
         0.5338646769523621, 0.37087297439575195}},
       {{0.5252850651741028, 0.13006305694580078, 0.27607348561286926,
         0.29916810989379883, 0.5018289685249329},
        {0.15546941757202148, 0.8042718768119812, 0.5045357346534729,
         0.4063466489315033, 0.18431293964385986},
        {0.39942383766174316, 0.769119143486023, 0.3223990201950073,
         0.9254138469696045, 0.4391845464706421},
        {0.8436281085014343, 0.26444512605667114, 0.3205794394016266,
         0.28365275263786316, 0.9028468132019043}},
       {{0.9950684309005737, 0.07097373157739639, 0.6037342548370361,
         0.8829789757728577, 0.3247211277484894},
        {0.8993489146232605, 0.2146441489458084, 0.27531322836875916,
         0.5409069061279297, 0.5658105611801147},
        {0.08075195550918579, 0.9044844508171082, 0.986808180809021,
         0.21508102118968964, 0.1619407832622528},
        {0.6783815026283264, 0.10092660039663315, 0.4767557680606842,
         0.031327057629823685, 0.1487768441438675}}},
      {{{0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
         0.6458512544631958, 0.8537090420722961},
        {0.9656611084938049, 0.31318214535713196, 0.6329669952392578,
         0.772528350353241, 0.35660672187805176},
        {0.6847124695777893, 0.876224935054779, 0.5572085380554199,
         0.804850697517395, 0.4376949369907379},
        {0.6456229090690613, 0.7696112394332886, 0.03618588671088219,
         0.8575048446655273, 0.5548474788665771}},
       {{0.2269730567932129, 0.7364659309387207, 0.27601030468940735,
         0.9168832302093506, 0.627094566822052},
        {0.35735565423965454, 0.16407112777233124, 0.5200456976890564,
         0.14997746050357819, 0.31148043274879456},
        {0.8584154844284058, 0.7192798256874084, 0.6552888751029968,
         0.45744556188583374, 0.30065035820007324},
        {0.8243831396102905, 0.40757670998573303, 0.9683871865272522,
         0.0344025194644928, 0.8810514211654663}},
       {{0.15895137190818787, 0.8111627101898193, 0.7949113249778748,
         0.05331829562783241, 0.31034180521965027},
        {0.7896537184715271, 0.12723813951015472, 0.38409972190856934,
         0.3256235420703888, 0.32709842920303345},
        {0.8023419976234436, 0.7965673208236694, 0.281536728143692,
         0.45081040263175964, 0.9933833479881287},
        {0.5719109177589417, 0.22103622555732727, 0.4951089024543762,
         0.49796757102012634, 0.8491216897964478}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[2][60];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {2, 60};
  const float answer_0[2][60] = {
      {0.475782573223114,   0.17737644910812378,  0.2686356008052826,
       0.13434721529483795, 0.6576226949691772,   0.7030077576637268,
       0.9209692478179932,  0.9242821931838989,   0.8460663557052612,
       0.7890874147415161,  0.6322358846664429,   0.23658999800682068,
       0.36220094561576843, 0.33706915378570557,  0.0775298923254013,
       0.5300828218460083,  0.5354111790657043,   0.8545095920562744,
       0.5338646769523621,  0.37087297439575195,  0.5252850651741028,
       0.13006305694580078, 0.27607348561286926,  0.29916810989379883,
       0.5018289685249329,  0.15546941757202148,  0.8042718768119812,
       0.5045357346534729,  0.4063466489315033,   0.18431293964385986,
       0.39942383766174316, 0.769119143486023,    0.3223990201950073,
       0.9254138469696045,  0.4391845464706421,   0.8436281085014343,
       0.26444512605667114, 0.3205794394016266,   0.28365275263786316,
       0.9028468132019043,  0.9950684309005737,   0.07097373157739639,
       0.6037342548370361,  0.8829789757728577,   0.3247211277484894,
       0.8993489146232605,  0.2146441489458084,   0.27531322836875916,
       0.5409069061279297,  0.5658105611801147,   0.08075195550918579,
       0.9044844508171082,  0.986808180809021,    0.21508102118968964,
       0.1619407832622528,  0.6783815026283264,   0.10092660039663315,
       0.4767557680606842,  0.031327057629823685, 0.1487768441438675},
      {0.24404151737689972, 0.6688364744186401,  0.4016159474849701,
       0.6458512544631958,  0.8537090420722961,  0.9656611084938049,
       0.31318214535713196, 0.6329669952392578,  0.772528350353241,
       0.35660672187805176, 0.6847124695777893,  0.876224935054779,
       0.5572085380554199,  0.804850697517395,   0.4376949369907379,
       0.6456229090690613,  0.7696112394332886,  0.03618588671088219,
       0.8575048446655273,  0.5548474788665771,  0.2269730567932129,
       0.7364659309387207,  0.27601030468940735, 0.9168832302093506,
       0.627094566822052,   0.35735565423965454, 0.16407112777233124,
       0.5200456976890564,  0.14997746050357819, 0.31148043274879456,
       0.8584154844284058,  0.7192798256874084,  0.6552888751029968,
       0.45744556188583374, 0.30065035820007324, 0.8243831396102905,
       0.40757670998573303, 0.9683871865272522,  0.0344025194644928,
       0.8810514211654663,  0.15895137190818787, 0.8111627101898193,
       0.7949113249778748,  0.05331829562783241, 0.31034180521965027,
       0.7896537184715271,  0.12723813951015472, 0.38409972190856934,
       0.3256235420703888,  0.32709842920303345, 0.8023419976234436,
       0.7965673208236694,  0.281536728143692,   0.45081040263175964,
       0.9933833479881287,  0.5719109177589417,  0.22103622555732727,
       0.4951089024543762,  0.49796757102012634, 0.8491216897964478}};
  const int32_t axis = 1;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 2 * 60; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis2) {
  const float input_0[2][3][4][5] = {
      {{{0.475782573223114, 0.17737644910812378, 0.2686356008052826,
         0.13434721529483795, 0.6576226949691772},
        {0.7030077576637268, 0.9209692478179932, 0.9242821931838989,
         0.8460663557052612, 0.7890874147415161},
        {0.6322358846664429, 0.23658999800682068, 0.36220094561576843,
         0.33706915378570557, 0.0775298923254013},
        {0.5300828218460083, 0.5354111790657043, 0.8545095920562744,
         0.5338646769523621, 0.37087297439575195}},
       {{0.5252850651741028, 0.13006305694580078, 0.27607348561286926,
         0.29916810989379883, 0.5018289685249329},
        {0.15546941757202148, 0.8042718768119812, 0.5045357346534729,
         0.4063466489315033, 0.18431293964385986},
        {0.39942383766174316, 0.769119143486023, 0.3223990201950073,
         0.9254138469696045, 0.4391845464706421},
        {0.8436281085014343, 0.26444512605667114, 0.3205794394016266,
         0.28365275263786316, 0.9028468132019043}},
       {{0.9950684309005737, 0.07097373157739639, 0.6037342548370361,
         0.8829789757728577, 0.3247211277484894},
        {0.8993489146232605, 0.2146441489458084, 0.27531322836875916,
         0.5409069061279297, 0.5658105611801147},
        {0.08075195550918579, 0.9044844508171082, 0.986808180809021,
         0.21508102118968964, 0.1619407832622528},
        {0.6783815026283264, 0.10092660039663315, 0.4767557680606842,
         0.031327057629823685, 0.1487768441438675}}},
      {{{0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
         0.6458512544631958, 0.8537090420722961},
        {0.9656611084938049, 0.31318214535713196, 0.6329669952392578,
         0.772528350353241, 0.35660672187805176},
        {0.6847124695777893, 0.876224935054779, 0.5572085380554199,
         0.804850697517395, 0.4376949369907379},
        {0.6456229090690613, 0.7696112394332886, 0.03618588671088219,
         0.8575048446655273, 0.5548474788665771}},
       {{0.2269730567932129, 0.7364659309387207, 0.27601030468940735,
         0.9168832302093506, 0.627094566822052},
        {0.35735565423965454, 0.16407112777233124, 0.5200456976890564,
         0.14997746050357819, 0.31148043274879456},
        {0.8584154844284058, 0.7192798256874084, 0.6552888751029968,
         0.45744556188583374, 0.30065035820007324},
        {0.8243831396102905, 0.40757670998573303, 0.9683871865272522,
         0.0344025194644928, 0.8810514211654663}},
       {{0.15895137190818787, 0.8111627101898193, 0.7949113249778748,
         0.05331829562783241, 0.31034180521965027},
        {0.7896537184715271, 0.12723813951015472, 0.38409972190856934,
         0.3256235420703888, 0.32709842920303345},
        {0.8023419976234436, 0.7965673208236694, 0.281536728143692,
         0.45081040263175964, 0.9933833479881287},
        {0.5719109177589417, 0.22103622555732727, 0.4951089024543762,
         0.49796757102012634, 0.8491216897964478}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[6][20];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {6, 20};
  const float answer_0[6][20] = {
      {0.475782573223114,   0.17737644910812378, 0.2686356008052826,
       0.13434721529483795, 0.6576226949691772,  0.7030077576637268,
       0.9209692478179932,  0.9242821931838989,  0.8460663557052612,
       0.7890874147415161,  0.6322358846664429,  0.23658999800682068,
       0.36220094561576843, 0.33706915378570557, 0.0775298923254013,
       0.5300828218460083,  0.5354111790657043,  0.8545095920562744,
       0.5338646769523621,  0.37087297439575195},
      {0.5252850651741028,  0.13006305694580078, 0.27607348561286926,
       0.29916810989379883, 0.5018289685249329,  0.15546941757202148,
       0.8042718768119812,  0.5045357346534729,  0.4063466489315033,
       0.18431293964385986, 0.39942383766174316, 0.769119143486023,
       0.3223990201950073,  0.9254138469696045,  0.4391845464706421,
       0.8436281085014343,  0.26444512605667114, 0.3205794394016266,
       0.28365275263786316, 0.9028468132019043},
      {0.9950684309005737,   0.07097373157739639, 0.6037342548370361,
       0.8829789757728577,   0.3247211277484894,  0.8993489146232605,
       0.2146441489458084,   0.27531322836875916, 0.5409069061279297,
       0.5658105611801147,   0.08075195550918579, 0.9044844508171082,
       0.986808180809021,    0.21508102118968964, 0.1619407832622528,
       0.6783815026283264,   0.10092660039663315, 0.4767557680606842,
       0.031327057629823685, 0.1487768441438675},
      {0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
       0.6458512544631958,  0.8537090420722961, 0.9656611084938049,
       0.31318214535713196, 0.6329669952392578, 0.772528350353241,
       0.35660672187805176, 0.6847124695777893, 0.876224935054779,
       0.5572085380554199,  0.804850697517395,  0.4376949369907379,
       0.6456229090690613,  0.7696112394332886, 0.03618588671088219,
       0.8575048446655273,  0.5548474788665771},
      {0.2269730567932129,  0.7364659309387207,  0.27601030468940735,
       0.9168832302093506,  0.627094566822052,   0.35735565423965454,
       0.16407112777233124, 0.5200456976890564,  0.14997746050357819,
       0.31148043274879456, 0.8584154844284058,  0.7192798256874084,
       0.6552888751029968,  0.45744556188583374, 0.30065035820007324,
       0.8243831396102905,  0.40757670998573303, 0.9683871865272522,
       0.0344025194644928,  0.8810514211654663},
      {0.15895137190818787, 0.8111627101898193,  0.7949113249778748,
       0.05331829562783241, 0.31034180521965027, 0.7896537184715271,
       0.12723813951015472, 0.38409972190856934, 0.3256235420703888,
       0.32709842920303345, 0.8023419976234436,  0.7965673208236694,
       0.281536728143692,   0.45081040263175964, 0.9933833479881287,
       0.5719109177589417,  0.22103622555732727, 0.4951089024543762,
       0.49796757102012634, 0.8491216897964478}};
  const int32_t axis = 2;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 6 * 20; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Flatten, test_flatten_axis3) {
  const float input_0[2][3][4][5] = {
      {{{0.475782573223114, 0.17737644910812378, 0.2686356008052826,
         0.13434721529483795, 0.6576226949691772},
        {0.7030077576637268, 0.9209692478179932, 0.9242821931838989,
         0.8460663557052612, 0.7890874147415161},
        {0.6322358846664429, 0.23658999800682068, 0.36220094561576843,
         0.33706915378570557, 0.0775298923254013},
        {0.5300828218460083, 0.5354111790657043, 0.8545095920562744,
         0.5338646769523621, 0.37087297439575195}},
       {{0.5252850651741028, 0.13006305694580078, 0.27607348561286926,
         0.29916810989379883, 0.5018289685249329},
        {0.15546941757202148, 0.8042718768119812, 0.5045357346534729,
         0.4063466489315033, 0.18431293964385986},
        {0.39942383766174316, 0.769119143486023, 0.3223990201950073,
         0.9254138469696045, 0.4391845464706421},
        {0.8436281085014343, 0.26444512605667114, 0.3205794394016266,
         0.28365275263786316, 0.9028468132019043}},
       {{0.9950684309005737, 0.07097373157739639, 0.6037342548370361,
         0.8829789757728577, 0.3247211277484894},
        {0.8993489146232605, 0.2146441489458084, 0.27531322836875916,
         0.5409069061279297, 0.5658105611801147},
        {0.08075195550918579, 0.9044844508171082, 0.986808180809021,
         0.21508102118968964, 0.1619407832622528},
        {0.6783815026283264, 0.10092660039663315, 0.4767557680606842,
         0.031327057629823685, 0.1487768441438675}}},
      {{{0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
         0.6458512544631958, 0.8537090420722961},
        {0.9656611084938049, 0.31318214535713196, 0.6329669952392578,
         0.772528350353241, 0.35660672187805176},
        {0.6847124695777893, 0.876224935054779, 0.5572085380554199,
         0.804850697517395, 0.4376949369907379},
        {0.6456229090690613, 0.7696112394332886, 0.03618588671088219,
         0.8575048446655273, 0.5548474788665771}},
       {{0.2269730567932129, 0.7364659309387207, 0.27601030468940735,
         0.9168832302093506, 0.627094566822052},
        {0.35735565423965454, 0.16407112777233124, 0.5200456976890564,
         0.14997746050357819, 0.31148043274879456},
        {0.8584154844284058, 0.7192798256874084, 0.6552888751029968,
         0.45744556188583374, 0.30065035820007324},
        {0.8243831396102905, 0.40757670998573303, 0.9683871865272522,
         0.0344025194644928, 0.8810514211654663}},
       {{0.15895137190818787, 0.8111627101898193, 0.7949113249778748,
         0.05331829562783241, 0.31034180521965027},
        {0.7896537184715271, 0.12723813951015472, 0.38409972190856934,
         0.3256235420703888, 0.32709842920303345},
        {0.8023419976234436, 0.7965673208236694, 0.281536728143692,
         0.45081040263175964, 0.9933833479881287},
        {0.5719109177589417, 0.22103622555732727, 0.4951089024543762,
         0.49796757102012634, 0.8491216897964478}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {2, 3, 4, 5};
  float output_0[24][5];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {24, 5};
  const float answer_0[24][5] = {
      {0.475782573223114, 0.17737644910812378, 0.2686356008052826,
       0.13434721529483795, 0.6576226949691772},
      {0.7030077576637268, 0.9209692478179932, 0.9242821931838989,
       0.8460663557052612, 0.7890874147415161},
      {0.6322358846664429, 0.23658999800682068, 0.36220094561576843,
       0.33706915378570557, 0.0775298923254013},
      {0.5300828218460083, 0.5354111790657043, 0.8545095920562744,
       0.5338646769523621, 0.37087297439575195},
      {0.5252850651741028, 0.13006305694580078, 0.27607348561286926,
       0.29916810989379883, 0.5018289685249329},
      {0.15546941757202148, 0.8042718768119812, 0.5045357346534729,
       0.4063466489315033, 0.18431293964385986},
      {0.39942383766174316, 0.769119143486023, 0.3223990201950073,
       0.9254138469696045, 0.4391845464706421},
      {0.8436281085014343, 0.26444512605667114, 0.3205794394016266,
       0.28365275263786316, 0.9028468132019043},
      {0.9950684309005737, 0.07097373157739639, 0.6037342548370361,
       0.8829789757728577, 0.3247211277484894},
      {0.8993489146232605, 0.2146441489458084, 0.27531322836875916,
       0.5409069061279297, 0.5658105611801147},
      {0.08075195550918579, 0.9044844508171082, 0.986808180809021,
       0.21508102118968964, 0.1619407832622528},
      {0.6783815026283264, 0.10092660039663315, 0.4767557680606842,
       0.031327057629823685, 0.1487768441438675},
      {0.24404151737689972, 0.6688364744186401, 0.4016159474849701,
       0.6458512544631958, 0.8537090420722961},
      {0.9656611084938049, 0.31318214535713196, 0.6329669952392578,
       0.772528350353241, 0.35660672187805176},
      {0.6847124695777893, 0.876224935054779, 0.5572085380554199,
       0.804850697517395, 0.4376949369907379},
      {0.6456229090690613, 0.7696112394332886, 0.03618588671088219,
       0.8575048446655273, 0.5548474788665771},
      {0.2269730567932129, 0.7364659309387207, 0.27601030468940735,
       0.9168832302093506, 0.627094566822052},
      {0.35735565423965454, 0.16407112777233124, 0.5200456976890564,
       0.14997746050357819, 0.31148043274879456},
      {0.8584154844284058, 0.7192798256874084, 0.6552888751029968,
       0.45744556188583374, 0.30065035820007324},
      {0.8243831396102905, 0.40757670998573303, 0.9683871865272522,
       0.0344025194644928, 0.8810514211654663},
      {0.15895137190818787, 0.8111627101898193, 0.7949113249778748,
       0.05331829562783241, 0.31034180521965027},
      {0.7896537184715271, 0.12723813951015472, 0.38409972190856934,
       0.3256235420703888, 0.32709842920303345},
      {0.8023419976234436, 0.7965673208236694, 0.281536728143692,
       0.45081040263175964, 0.9933833479881287},
      {0.5719109177589417, 0.22103622555732727, 0.4951089024543762,
       0.49796757102012634, 0.8491216897964478}};
  const int32_t axis = 3;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 24 * 5; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Flatten, test_flatten_default_axis) {
  const float input_0[5][4][3][2] = {
      {{{0.7874643802642822, 0.826961100101471},
        {0.4889760911464691, 0.8533348441123962},
        {0.2684277594089508, 0.5075528025627136}},
       {{0.8312551379203796, 0.1240934431552887},
        {0.6015661954879761, 0.4117550849914551},
        {0.6014644503593445, 0.9941037893295288}},
       {{0.3728718161582947, 0.5314784049987793},
        {0.8400111198425293, 0.8802127242088318},
        {0.23369723558425903, 0.517283022403717}},
       {{0.4337598979473114, 0.5533458590507507},
        {0.8501245975494385, 0.6507170796394348},
        {0.6608850955963135, 0.6864181756973267}}},
      {{{0.7848676443099976, 0.8343595266342163},
        {0.8358346819877625, 0.3195032477378845},
        {0.5492710471153259, 0.7903628945350647}},
       {{0.21093805134296417, 0.81113201379776},
        {0.9403349161148071, 0.9639745950698853},
        {0.7354574203491211, 0.1630820482969284}},
       {{0.9590049386024475, 0.5042571425437927},
        {0.9316050410270691, 0.6666404604911804},
        {0.18038000166416168, 0.48838573694229126}},
       {{0.998620331287384, 0.9522549510002136},
        {0.6421629190444946, 0.9663634896278381},
        {0.3987271189689636, 0.43605491518974304}}},
      {{{0.5046135187149048, 0.9795458316802979},
        {0.5660498142242432, 0.31091681122779846},
        {0.9798954725265503, 0.4374370872974396}},
       {{0.9960253238677979, 0.9029788970947266},
        {0.8076699376106262, 0.10211065411567688},
        {0.03765075281262398, 0.2630229592323303}},
       {{0.07378960400819778, 0.8075427412986755},
        {0.5237849950790405, 0.6315008997917175},
        {0.3321402966976166, 0.4918510913848877}},
       {{0.8370385766029358, 0.5075196027755737},
        {0.7259325981140137, 0.26132625341415405},
        {0.7427871227264404, 0.6750011444091797}}},
      {{{0.5043496489524841, 0.6024332046508789},
        {0.38010069727897644, 0.49920332431793213},
        {0.959949254989624, 0.7247416973114014}},
       {{0.07340477406978607, 0.5540179014205933},
        {0.20139488577842712, 0.7163391709327698},
        {0.3901835083961487, 0.5478432178497314}},
       {{0.40133780241012573, 0.9867222905158997},
        {0.8804595470428467, 0.8983683586120605},
        {0.8002331852912903, 0.05918857827782631}},
       {{0.6565736532211304, 0.5786442756652832},
        {0.21397332847118378, 0.24463947117328644},
        {0.7003245949745178, 0.23843422532081604}}},
      {{{0.16559471189975739, 0.26223278045654297},
        {0.7970383763313293, 0.7665294408798218},
        {0.2585977613925934, 0.03604928031563759}},
       {{0.03754793852567673, 0.9224205613136292},
        {0.9842529296875, 0.7263095378875732},
        {0.9582913517951965, 0.2813992202281952}},
       {{0.4507465958595276, 0.03474992886185646},
        {0.863563060760498, 0.7630316615104675},
        {0.6623263359069824, 0.6076005697250366}},
       {{0.764974057674408, 0.9818790555000305},
        {0.5663657784461975, 0.22328700125217438},
        {0.3539286255836487, 0.385212242603302}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {5, 4, 3, 2};
  float output_0[5][24];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {5, 24};
  const float answer_0[5][24] = {
      {0.7874643802642822, 0.826961100101471,   0.4889760911464691,
       0.8533348441123962, 0.2684277594089508,  0.5075528025627136,
       0.8312551379203796, 0.1240934431552887,  0.6015661954879761,
       0.4117550849914551, 0.6014644503593445,  0.9941037893295288,
       0.3728718161582947, 0.5314784049987793,  0.8400111198425293,
       0.8802127242088318, 0.23369723558425903, 0.517283022403717,
       0.4337598979473114, 0.5533458590507507,  0.8501245975494385,
       0.6507170796394348, 0.6608850955963135,  0.6864181756973267},
      {0.7848676443099976,  0.8343595266342163,  0.8358346819877625,
       0.3195032477378845,  0.5492710471153259,  0.7903628945350647,
       0.21093805134296417, 0.81113201379776,    0.9403349161148071,
       0.9639745950698853,  0.7354574203491211,  0.1630820482969284,
       0.9590049386024475,  0.5042571425437927,  0.9316050410270691,
       0.6666404604911804,  0.18038000166416168, 0.48838573694229126,
       0.998620331287384,   0.9522549510002136,  0.6421629190444946,
       0.9663634896278381,  0.3987271189689636,  0.43605491518974304},
      {0.5046135187149048,  0.9795458316802979,  0.5660498142242432,
       0.31091681122779846, 0.9798954725265503,  0.4374370872974396,
       0.9960253238677979,  0.9029788970947266,  0.8076699376106262,
       0.10211065411567688, 0.03765075281262398, 0.2630229592323303,
       0.07378960400819778, 0.8075427412986755,  0.5237849950790405,
       0.6315008997917175,  0.3321402966976166,  0.4918510913848877,
       0.8370385766029358,  0.5075196027755737,  0.7259325981140137,
       0.26132625341415405, 0.7427871227264404,  0.6750011444091797},
      {0.5043496489524841,  0.6024332046508789, 0.38010069727897644,
       0.49920332431793213, 0.959949254989624,  0.7247416973114014,
       0.07340477406978607, 0.5540179014205933, 0.20139488577842712,
       0.7163391709327698,  0.3901835083961487, 0.5478432178497314,
       0.40133780241012573, 0.9867222905158997, 0.8804595470428467,
       0.8983683586120605,  0.8002331852912903, 0.05918857827782631,
       0.6565736532211304,  0.5786442756652832, 0.21397332847118378,
       0.24463947117328644, 0.7003245949745178, 0.23843422532081604},
      {0.16559471189975739, 0.26223278045654297, 0.7970383763313293,
       0.7665294408798218,  0.2585977613925934,  0.03604928031563759,
       0.03754793852567673, 0.9224205613136292,  0.9842529296875,
       0.7263095378875732,  0.9582913517951965,  0.2813992202281952,
       0.4507465958595276,  0.03474992886185646, 0.863563060760498,
       0.7630316615104675,  0.6623263359069824,  0.6076005697250366,
       0.764974057674408,   0.9818790555000305,  0.5663657784461975,
       0.22328700125217438, 0.3539286255836487,  0.385212242603302}};
  const int32_t axis = 0;
  ONNC_RUNTIME_flatten_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                             (float *)output_0, output_0_ndim, output_0_dims,
                             axis);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 5 * 24; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}