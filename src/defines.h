#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 73
#define N_INPUT_2_1 70
#define N_OUT_2 128
#define N_OUT_2 128
#define N_OUT_2 128
#define N_LAYER_4 64
#define N_LAYER_6 64
#define N_LAYER_4 64
#define N_LAYER_4 64
#define N_LAYER_6 64
#define N_LAYER_6 64
#define N_LAYER_4 64
#define N_LAYER_6 64
#define N_LAYER_4 64
#define N_LAYER_6 64
#define N_LAYER_6 64
#define N_LAYER_4 64
#define N_INPUT_1_17 73
#define N_INPUT_2_17 64
#define N_LAYER_4 64
#define N_TIME_STEPS_19 73
#define N_OUT_19 64
#define N_TIME_STEPS_19 73
#define N_OUT_19 64
#define N_OUTPUTS_26 73
#define N_FILT_26 4
#define N_LAYER_1_21 73
#define N_LAYER_2_21 4
#define N_OUTPUTS_27 73
#define N_FILT_27 70

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<32,16> accum2_t;
typedef ap_fixed<8,1> forward_weight2_t;
typedef ap_fixed<8,1> backward_weight2_t;
typedef ap_fixed<8,1> forward_recurrent_weight2_t;
typedef ap_fixed<8,1> backward_recurrent_weight2_t;
typedef ap_fixed<8,1> forward_bias2_t;
typedef ap_fixed<8,1> forward_recurrent_bias2_t;
typedef ap_fixed<8,1> backward_bias2_t;
typedef ap_fixed<8,1> backward_recurrent_bias2_t;
typedef ap_fixed<8,1,AP_RND_CONV,AP_SAT> act2_t;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT> recr_act2_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> state2_t;
typedef ap_ufixed<2,0> slope2_t;
typedef ap_ufixed<2,0> shift2_t;
typedef ap_fixed<17,4> layer2_t;
typedef ap_fixed<32,16> accum_dense2_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer3_t;
typedef ap_fixed<18,8> q_act_postencoder_table_t;
typedef ap_fixed<16,6> layer28_t;
typedef ap_fixed<32,16> accum4_t;
typedef ap_fixed<16,6> layer4_t;
typedef ap_fixed<8,1> weight4_t;
typedef ap_fixed<8,1> bias4_t;
typedef ap_uint<1> layer4_index;
typedef ap_fixed<32,16> accum6_t;
typedef ap_fixed<16,6> layer6_t;
typedef ap_fixed<8,1> weight6_t;
typedef ap_fixed<8,1> bias6_t;
typedef ap_uint<1> layer6_index;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer8_t;
typedef ap_fixed<18,8> q_activation_6_table_t;
typedef ap_fixed<16,6> layer29_t;
typedef ap_fixed<10,3,AP_RND_CONV,AP_SAT> layer9_t;
typedef ap_fixed<18,8> q_activation_8_table_t;
typedef ap_fixed<16,6> layer10_t;
typedef ap_fixed<18,8,AP_RND_CONV,AP_SAT> exponent_logvar_1_exp_table_t;
typedef ap_fixed<16,6> layer11_t;
typedef ap_fixed<18,8,AP_RND_CONV,AP_SAT> layer12_t;
typedef ap_fixed<18,8> q_activation_9_table_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer13_t;
typedef ap_fixed<18,8> q_activation_7_table_t;
typedef ap_fixed<16,6> layer14_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer15_t;
typedef ap_fixed<18,8> q_activation_10_table_t;
typedef ap_fixed<16,6> layer16_t;
typedef ap_fixed<16,6> input17_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer18_t;
typedef ap_fixed<18,8> q_activation_11_table_t;
typedef ap_fixed<32,16> accum19_t;
typedef ap_fixed<8,1> weight19_t;
typedef ap_fixed<8,1> recurrent_weight19_t;
typedef ap_fixed<8,1> bias19_t;
typedef ap_fixed<8,1> recurrent_bias19_t;
typedef ap_fixed<8,1,AP_RND_CONV,AP_SAT> act19_t;
typedef ap_ufixed<8,0,AP_RND_CONV,AP_SAT> recr_act19_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> state19_t;
typedef ap_ufixed<2,0> slope19_t;
typedef ap_ufixed<2,0> shift19_t;
typedef ap_fixed<17,4> layer19_t;
typedef ap_fixed<32,16> accum_dense19_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer20_t;
typedef ap_fixed<18,8> q_act_postdecoder_table_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> layer26_t;
typedef ap_fixed<8,1> dense_factor_weight_t;
typedef ap_fixed<8,1> dense_factor_bias_t;
typedef ap_fixed<8,3,AP_RND_CONV,AP_SAT> layer23_t;
typedef ap_fixed<18,8> q_act3_postfactor_table_t;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<8,1> nerual_dense_weight_t;
typedef ap_fixed<8,1> nerual_dense_bias_t;

#endif
