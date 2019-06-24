#include <cmath>
#include <cstdlib>
#include <ctime>
#include <skypat/skypat.h>
#include <vector>

#define restrict
extern "C" {
#include <onnc/Runtime/onnc-runtime.h>
}
SKYPAT_F(Operator_Not, test_not_2d) {
  const float input_0[3][4] = {
      {1.0, 1.0, 1.0, 1.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}};
  const int32_t input_0_ndim = 2;
  const int32_t input_0_dims[] = {3, 4};
  float output_0[3][4];
  const int32_t output_0_ndim = 2;
  const int32_t output_0_dims[] = {3, 4};
  const float answer_0[3][4] = {
      {0.0, 0.0, 0.0, 0.0}, {1.0, 0.0, 1.0, 1.0}, {1.0, 1.0, 0.0, 1.0}};
  ONNC_RUNTIME_not_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}

SKYPAT_F(Operator_Not, test_not_3d) {
  const float input_0[3][4][5] = {{{0.0, 0.0, 1.0, 1.0, 1.0},
                                   {0.0, 1.0, 0.0, 1.0, 1.0},
                                   {0.0, 0.0, 0.0, 0.0, 0.0},
                                   {0.0, 1.0, 1.0, 0.0, 1.0}},
                                  {{1.0, 0.0, 1.0, 1.0, 1.0},
                                   {0.0, 0.0, 1.0, 1.0, 0.0},
                                   {1.0, 0.0, 1.0, 0.0, 0.0},
                                   {0.0, 0.0, 0.0, 1.0, 1.0}},
                                  {{0.0, 1.0, 0.0, 1.0, 1.0},
                                   {0.0, 0.0, 0.0, 0.0, 1.0},
                                   {1.0, 0.0, 1.0, 1.0, 0.0},
                                   {1.0, 0.0, 0.0, 0.0, 1.0}}};
  const int32_t input_0_ndim = 3;
  const int32_t input_0_dims[] = {3, 4, 5};
  float output_0[3][4][5];
  const int32_t output_0_ndim = 3;
  const int32_t output_0_dims[] = {3, 4, 5};
  const float answer_0[3][4][5] = {{{1.0, 1.0, 0.0, 0.0, 0.0},
                                    {1.0, 0.0, 1.0, 0.0, 0.0},
                                    {1.0, 1.0, 1.0, 1.0, 1.0},
                                    {1.0, 0.0, 0.0, 1.0, 0.0}},
                                   {{0.0, 1.0, 0.0, 0.0, 0.0},
                                    {1.0, 1.0, 0.0, 0.0, 1.0},
                                    {0.0, 1.0, 0.0, 1.0, 1.0},
                                    {1.0, 1.0, 1.0, 0.0, 0.0}},
                                   {{1.0, 0.0, 1.0, 0.0, 0.0},
                                    {1.0, 1.0, 1.0, 1.0, 0.0},
                                    {0.0, 1.0, 0.0, 0.0, 1.0},
                                    {0.0, 1.0, 1.0, 1.0, 0.0}}};
  ONNC_RUNTIME_not_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
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

SKYPAT_F(Operator_Not, test_not_4d) {
  const float input_0[3][4][5][6] = {{{{1.0, 0.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
                                       {0.0, 1.0, 0.0, 1.0, 1.0, 0.0},
                                       {1.0, 0.0, 0.0, 1.0, 0.0, 0.0},
                                       {1.0, 0.0, 1.0, 0.0, 0.0, 0.0}},
                                      {{1.0, 0.0, 0.0, 1.0, 0.0, 1.0},
                                       {1.0, 0.0, 1.0, 0.0, 1.0, 0.0},
                                       {1.0, 1.0, 1.0, 1.0, 0.0, 1.0},
                                       {1.0, 0.0, 1.0, 1.0, 0.0, 1.0},
                                       {1.0, 0.0, 1.0, 0.0, 0.0, 1.0}},
                                      {{0.0, 0.0, 0.0, 0.0, 1.0, 1.0},
                                       {1.0, 0.0, 1.0, 1.0, 1.0, 1.0},
                                       {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                       {0.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                       {0.0, 0.0, 1.0, 1.0, 0.0, 1.0}},
                                      {{0.0, 0.0, 0.0, 1.0, 1.0, 1.0},
                                       {0.0, 0.0, 1.0, 1.0, 0.0, 0.0},
                                       {1.0, 1.0, 1.0, 1.0, 0.0, 1.0},
                                       {1.0, 0.0, 0.0, 1.0, 0.0, 0.0},
                                       {0.0, 1.0, 1.0, 0.0, 1.0, 1.0}}},
                                     {{{0.0, 1.0, 0.0, 1.0, 0.0, 0.0},
                                       {0.0, 1.0, 1.0, 0.0, 1.0, 0.0},
                                       {1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                       {0.0, 1.0, 0.0, 0.0, 0.0, 0.0},
                                       {1.0, 0.0, 1.0, 0.0, 1.0, 1.0}},
                                      {{1.0, 0.0, 1.0, 1.0, 0.0, 0.0},
                                       {0.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                       {0.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                       {1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                       {1.0, 1.0, 0.0, 0.0, 1.0, 1.0}},
                                      {{1.0, 0.0, 1.0, 1.0, 1.0, 1.0},
                                       {1.0, 0.0, 0.0, 0.0, 0.0, 1.0},
                                       {1.0, 0.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 0.0, 1.0, 0.0, 1.0, 1.0},
                                       {0.0, 1.0, 1.0, 0.0, 1.0, 0.0}},
                                      {{1.0, 0.0, 0.0, 0.0, 1.0, 1.0},
                                       {0.0, 0.0, 1.0, 0.0, 1.0, 1.0},
                                       {1.0, 0.0, 1.0, 1.0, 0.0, 0.0},
                                       {0.0, 0.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 1.0, 1.0, 0.0, 0.0, 0.0}}},
                                     {{{0.0, 1.0, 1.0, 1.0, 0.0, 0.0},
                                       {1.0, 0.0, 1.0, 1.0, 1.0, 1.0},
                                       {1.0, 0.0, 1.0, 1.0, 0.0, 0.0},
                                       {0.0, 1.0, 0.0, 1.0, 1.0, 0.0},
                                       {1.0, 0.0, 0.0, 1.0, 0.0, 0.0}},
                                      {{1.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                                       {1.0, 1.0, 0.0, 1.0, 0.0, 0.0},
                                       {0.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                                       {0.0, 1.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 1.0, 1.0, 0.0, 0.0, 0.0}},
                                      {{1.0, 0.0, 1.0, 1.0, 0.0, 1.0},
                                       {1.0, 1.0, 0.0, 0.0, 1.0, 1.0},
                                       {1.0, 0.0, 0.0, 0.0, 1.0, 0.0},
                                       {1.0, 0.0, 1.0, 0.0, 0.0, 0.0},
                                       {1.0, 1.0, 1.0, 1.0, 0.0, 0.0}},
                                      {{1.0, 1.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 0.0, 1.0, 0.0, 1.0, 1.0},
                                       {1.0, 0.0, 0.0, 0.0, 0.0, 1.0},
                                       {0.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                       {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}}}};
  const int32_t input_0_ndim = 4;
  const int32_t input_0_dims[] = {3, 4, 5, 6};
  float output_0[3][4][5][6];
  const int32_t output_0_ndim = 4;
  const int32_t output_0_dims[] = {3, 4, 5, 6};
  const float answer_0[3][4][5][6] = {{{{0.0, 1.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 1.0, 0.0, 1.0, 0.0, 1.0},
                                        {1.0, 0.0, 1.0, 0.0, 0.0, 1.0},
                                        {0.0, 1.0, 1.0, 0.0, 1.0, 1.0},
                                        {0.0, 1.0, 0.0, 1.0, 1.0, 1.0}},
                                       {{0.0, 1.0, 1.0, 0.0, 1.0, 0.0},
                                        {0.0, 1.0, 0.0, 1.0, 0.0, 1.0},
                                        {0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
                                        {0.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                                        {0.0, 1.0, 0.0, 1.0, 1.0, 0.0}},
                                       {{1.0, 1.0, 1.0, 1.0, 0.0, 0.0},
                                        {0.0, 1.0, 0.0, 0.0, 0.0, 0.0},
                                        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
                                        {1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                        {1.0, 1.0, 0.0, 0.0, 1.0, 0.0}},
                                       {{1.0, 1.0, 1.0, 0.0, 0.0, 0.0},
                                        {1.0, 1.0, 0.0, 0.0, 1.0, 1.0},
                                        {0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
                                        {0.0, 1.0, 1.0, 0.0, 1.0, 1.0},
                                        {1.0, 0.0, 0.0, 1.0, 0.0, 0.0}}},
                                      {{{1.0, 0.0, 1.0, 0.0, 1.0, 1.0},
                                        {1.0, 0.0, 0.0, 1.0, 0.0, 1.0},
                                        {0.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                        {1.0, 0.0, 1.0, 1.0, 1.0, 1.0},
                                        {0.0, 1.0, 0.0, 1.0, 0.0, 0.0}},
                                       {{0.0, 1.0, 0.0, 0.0, 1.0, 1.0},
                                        {1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                        {1.0, 0.0, 0.0, 1.0, 1.0, 0.0},
                                        {0.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                        {0.0, 0.0, 1.0, 1.0, 0.0, 0.0}},
                                       {{0.0, 1.0, 0.0, 0.0, 0.0, 0.0},
                                        {0.0, 1.0, 1.0, 1.0, 1.0, 0.0},
                                        {0.0, 1.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 1.0, 0.0, 1.0, 0.0, 0.0},
                                        {1.0, 0.0, 0.0, 1.0, 0.0, 1.0}},
                                       {{0.0, 1.0, 1.0, 1.0, 0.0, 0.0},
                                        {1.0, 1.0, 0.0, 1.0, 0.0, 0.0},
                                        {0.0, 1.0, 0.0, 0.0, 1.0, 1.0},
                                        {1.0, 1.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 0.0, 0.0, 1.0, 1.0, 1.0}}},
                                      {{{1.0, 0.0, 0.0, 0.0, 1.0, 1.0},
                                        {0.0, 1.0, 0.0, 0.0, 0.0, 0.0},
                                        {0.0, 1.0, 0.0, 0.0, 1.0, 1.0},
                                        {1.0, 0.0, 1.0, 0.0, 0.0, 1.0},
                                        {0.0, 1.0, 1.0, 0.0, 1.0, 1.0}},
                                       {{0.0, 0.0, 1.0, 1.0, 0.0, 1.0},
                                        {0.0, 0.0, 1.0, 0.0, 1.0, 1.0},
                                        {1.0, 0.0, 1.0, 1.0, 0.0, 1.0},
                                        {1.0, 0.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 0.0, 0.0, 1.0, 1.0, 1.0}},
                                       {{0.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                                        {0.0, 0.0, 1.0, 1.0, 0.0, 0.0},
                                        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0},
                                        {0.0, 1.0, 0.0, 1.0, 1.0, 1.0},
                                        {0.0, 0.0, 0.0, 0.0, 1.0, 1.0}},
                                       {{0.0, 0.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 1.0, 0.0, 1.0, 0.0, 0.0},
                                        {0.0, 1.0, 1.0, 1.0, 1.0, 0.0},
                                        {1.0, 1.0, 1.0, 0.0, 0.0, 1.0},
                                        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}};
  ONNC_RUNTIME_not_float(NULL, (float *)input_0, input_0_ndim, input_0_dims,
                         (float *)output_0, output_0_ndim, output_0_dims);
  bool is_correct;
  is_correct = true;
  for (int32_t i = 0; i < 3 * 4 * 5 * 6; ++i) {
    if (std::abs(((float *)output_0)[i] - ((float *)answer_0)[i]) > 1.0e-7) {
      is_correct = false;
      break;
    }
  }
  ASSERT_TRUE(is_correct);
}