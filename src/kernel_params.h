#include "ap_fixed.h"
#include "defines.h"

//how many consecutive sets of inputs to run over per kernel execution

#define IN1 (N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1) //192
#define IN1_axi 256
#define IN2 (N_INPUT_1_2*N_INPUT_2_2*N_INPUT_3_2) //500
#define IN2_axi 512
#define OUT1 OUT_CONCAT_9
#define OUT1_axi 1024

#define DATA_SET 2

typedef ap_fixed<16,14> bigdata_t;

struct input_group1{
    bigdata_t addr[IN1_axi];
};

struct input_group2{
    bigdata_t addr[IN2_axi];
};

struct output_group1{
    bigdata_t addr[OUT1_axi];
};