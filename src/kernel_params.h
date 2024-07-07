#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define STREAM_LEN_IN1  N_INPUT_1_1//73
#define STREAM_LEN_IN2  N_INPUT_1_8//73
#define STREAM_LEN_OUT  N_OUTPUTS_18//73

#define STREAM_SIZE_IN1  N_INPUT_2_1//70
#define STREAM_SIZE_IN2  N_INPUT_2_8//64
#define STREAM_SIZE_OUT  N_FILT_18//70

typedef ap_fixed<16,6> data_t;

struct group_in1{
    input_t layer[64];
};
struct group_in2{
    input8_t layer[64];
};
struct group_out{
    result_t layer[64];
};
