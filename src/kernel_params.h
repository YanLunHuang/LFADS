#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define STREAM_LEN_IN1  N_INPUT_1_1
#define STREAM_LEN_IN2  N_INPUT_1_3
#define STREAM_LEN_OUT  OUT_CONCAT_0_11

#define STREAM_SIZE_IN1  N_INPUT_2_1
#define STREAM_SIZE_IN2  N_INPUT_2_3
#define STREAM_SIZE_OUT  OUT_CONCAT_1_11
typedef ap_fixed<32,16> bigdata_t;