#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_int.h"
#include "ap_fixed.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 73
#define N_INPUT_2_1 64
#define N_TIME_STEPS_2 73
#define N_OUT_2 64

//hls-fpga-machine-learning insert layer-precision
typedef nnet::array<ap_fixed<16,8>, 64*1> input_t;
typedef ap_fixed<16,8> model_default_t;
typedef nnet::array<ap_fixed<16,8>, 64*1> result_t;

#endif
