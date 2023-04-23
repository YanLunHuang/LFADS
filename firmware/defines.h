#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 73
#define N_INPUT_2_1 70
#define N_OUT_2 128
#define N_INPUT_1_3 73
#define N_INPUT_2_3 64
#define N_LAYER_4 64
#define N_TIME_STEPS_6 73
#define N_OUT_6 64
#define N_OUTPUTS_12 73
#define N_FILT_12 4
#define N_OUTPUTS_13 73
#define N_FILT_13 70
#define OUT_CONCAT_0_11 73
#define OUT_CONCAT_1_11 74
/*
//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<32,16> model_default_t;
typedef nnet::array<ap_fixed<32,16>, 70*1> input_t;
typedef nnet::array<ap_fixed<32,16>, 128*1> layer2_t;
typedef nnet::array<ap_fixed<32,16>, 64*1> input3_t;
typedef nnet::array<ap_fixed<32,16>, 64*1> layer4_t;
typedef ap_uint<1> layer4_index;
typedef nnet::array<ap_fixed<32,16>, 64*1> layer6_t;
typedef nnet::array<ap_fixed<32,16>, 4*1> layer12_t;
typedef ap_uint<1> bias12_t;
typedef nnet::array<ap_fixed<32,16>, 4*1> layer14_t;
typedef nnet::array<ap_fixed<32,16>, 70*1> layer13_t;
typedef nnet::array<ap_fixed<32,16>, 74*1> result_t;
*/
//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,8> model_default_t;
typedef ap_fixed<16,8> input_t;
typedef ap_fixed<16,8> layer2_t;
typedef ap_fixed<16,8> input3_t;
typedef ap_fixed<16,8> layer4_t;
typedef ap_uint<1> layer4_index;
typedef ap_fixed<16,8> layer6_t;
typedef ap_fixed<16,8> layer12_t;
typedef ap_uint<1> bias12_t;
typedef ap_fixed<16,8> layer14_t;
typedef ap_fixed<16,8> layer13_t;
typedef ap_fixed<16,8> result_t;

#endif
