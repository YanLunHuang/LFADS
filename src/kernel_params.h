#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution
#define DATA_SET 5000

#define STREAM_LEN_IN1  N_INPUT_1_1
#define STREAM_LEN_IN2  N_INPUT_1_3
#define STREAM_LEN_OUT  OUT_CONCAT_0_11

#define STREAM_SIZE_IN1  N_INPUT_2_1
#define STREAM_SIZE_IN2  N_INPUT_2_3
#define STREAM_SIZE_OUT  OUT_CONCAT_1_11


struct group_in1{
    input_t layer[128];
};
struct group_in2{
    input3_t layer[128];
};
struct group_out{
    result_t layer[128];
};
