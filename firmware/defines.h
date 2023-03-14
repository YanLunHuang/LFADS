#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 8
#define N_INPUT_2_1 8
#define N_INPUT_3_1 3
#define N_INPUT_1_2 10
#define N_INPUT_2_2 10
#define N_INPUT_3_2 5
#define OUT_HEIGHT_3 8
#define OUT_WIDTH_3 8
#define N_FILT_3 6
#define OUT_HEIGHT_5 10
#define OUT_WIDTH_5 10
#define N_FILT_5 4
#define OUT_CONCAT_9 (384+400)

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<32,16,AP_RND_CONV,AP_SAT> input_t;
typedef ap_fixed<32,16,AP_RND_CONV,AP_SAT> input2_t;
typedef ap_fixed<32,16> model_default_t;
typedef ap_fixed<32,16> layer3_t;
typedef ap_fixed<32,16> layer4_t;
typedef ap_fixed<32,16,AP_RND_CONV,AP_SAT> result_t;
typedef ap_fixed<18,8> conv2d_linear_table_t;
typedef ap_fixed<32,16> layer5_t;
typedef ap_fixed<32,16> layer6_t;
typedef ap_fixed<18,8> conv2d_1_linear_table_t;

#endif
