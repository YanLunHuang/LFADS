#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define IN_STREAM_LEN  N_INPUT_1_1
#define OUT_STREAM_LEN  1

#define DATA_SIZE_IN  N_INPUT_2_1
#define DATA_SIZE_OUT  N_OUT_2

typedef ap_fixed<16,8> bigdata_t;
