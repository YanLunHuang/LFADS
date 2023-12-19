#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define STREAM_LEN_IN1  N_INPUT_1_1//73
#define STREAM_LEN_IN2  N_INPUT_1_17//73
#define STREAM_LEN_OUT  N_OUTPUTS_27//73

#define STREAM_SIZE_IN1  N_INPUT_2_1//70
#define STREAM_SIZE_IN2  N_INPUT_2_17//64
#define STREAM_SIZE_OUT  N_FILT_27//70
typedef ap_fixed<16,6> data_t;
