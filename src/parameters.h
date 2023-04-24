#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_int.h"
#include "ap_fixed.h"

#include "nnet_utils/nnet_helpers.h"
//hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_bidirectional.h"
#include "nnet_utils/nnet_conv1d.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_merge_stream.h"
#include "nnet_utils/nnet_recurrent.h"
#include "nnet_utils/nnet_sepconv1d_stream.h"
#include "nnet_utils/nnet_stream.h"
 
//hls-fpga-machine-learning insert weights
#include "weights/backward_gru_1_gru_cell_1_weight2.h"
#include "weights/forward_gru_gru_cell_2_bias2.h"
#include "weights/forward_gru_recurrent_bias2.h"
#include "weights/backward_gru_1_gru_cell_1_bias2.h"
#include "weights/backward_gru_recurrent_bias2.h"
#include "weights/backward_gru_1_gru_cell_1_recurrent_weight2.h"
#include "weights/forward_gru_gru_cell_2_weight2.h"
#include "weights/forward_gru_gru_cell_2_recurrent_weight2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w6.h"
#include "weights/wr6.h"
#include "weights/b6.h"
#include "weights/br6.h"
#include "weights/w12.h"
#include "weights/b12.h"
#include "weights/w13.h"
#include "weights/b13.h"

//hls-fpga-machine-learning insert layer-config
// Encoder_BidirectionalGRU
struct config2_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_1;
    static const unsigned n_out = 192;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 13440;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config2_2 : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 192;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 64;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 12288;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct sigmoid_config2_recr : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 1;
    typedef ap_fixed<18,8> table_t;
};

struct tanh_config2 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 1;
    typedef ap_fixed<18,8> table_t;
};

struct config2_f : nnet::gru_config {
    typedef model_default_t accum_t;
    typedef model_default_t weight_t;  // Matrix
    typedef model_default_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::sigmoid<x_T, y_T, config_T>;
    typedef tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = N_INPUT_1_1;
    static const unsigned io_type = nnet::resource;
    static const unsigned use_initial = 0;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
};

struct config2_b : nnet::gru_config {
    typedef model_default_t accum_t;
    typedef model_default_t weight_t;  // Matrix
    typedef model_default_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::sigmoid<x_T, y_T, config_T>;
    typedef tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = N_INPUT_1_1;
    static const unsigned io_type = nnet::resource;
    static const unsigned use_initial = 0;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
};

struct config2 : nnet::bidirectional_config {
    typedef model_default_t accum_t;
    typedef model_default_t weight_t; 
    typedef model_default_t bias_t; 

    typedef config2_f config_rnn_layer_f;
    typedef config2_b config_rnn_layer_b;

    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::sigmoid<x_T, y_T, config_T>;
    typedef tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::tanh<x_T, y_T, config_T>;

    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = N_OUT_2;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = N_INPUT_1_1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const unsigned use_initial = 0;
    static const bool store_weights_in_bram = false;

};

// dense_mean
struct config4 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 8192;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef layer4_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// decoder_GRU
struct config6_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_3;
    static const unsigned n_out = N_OUT_6 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_3;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 12288;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config6_2 : nnet::dense_config {
    static const unsigned n_in = N_OUT_6;
    static const unsigned n_out = N_OUT_6 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_OUT_6;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 12288;
    static const bool store_weights_in_bram = false;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct sigmoid_config6_recr : nnet::activ_config {
    static const unsigned n_in = N_OUT_6 * 2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 1;
    typedef ap_fixed<18,8> table_t;
};

struct tanh_config6 : nnet::activ_config {
    static const unsigned n_in = N_OUT_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_stream;
    static const unsigned reuse_factor = 1;
    typedef ap_fixed<18,8> table_t;
};

struct config6 : nnet::gru_config {
    typedef model_default_t accum_t;
    typedef model_default_t weight_t;  // Matrix
    typedef model_default_t bias_t;  // Vector
    typedef config6_1 mult_config1;
    typedef config6_2 mult_config2;
    typedef sigmoid_config6_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::sigmoid<x_T, y_T, config_T>;
    typedef tanh_config6 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_3;
    static const unsigned n_out = N_OUT_6;
    static const unsigned n_state = N_OUT_6;
    static const unsigned n_sequence = N_INPUT_1_3;
    static const unsigned n_sequence_out = N_TIME_STEPS_6;
    static const unsigned io_type = nnet::resource;
    static const unsigned use_initial = 1;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
};

// dense
struct config12_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 4;
    static const unsigned reuse_factor = 64;
    static const unsigned strategy = nnet::resource;
    typedef model_default_t accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config12 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_width = 73;
    static const unsigned n_chan = 64;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_width;
    static const unsigned n_filt = 4;
    static const unsigned stride_width = 1;
    static const unsigned dilation = 1;
    static const unsigned out_width = 73;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_width = 1;
    static const ap_uint<filt_width> pixels[min_width];
    typedef model_default_t accum_t;
    typedef bias12_t bias_t;
    typedef model_default_t weight_t;
    typedef config12_mult mult_config;
};
const ap_uint<config12::filt_width> config12::pixels[] = {1};

// nerual_dense
struct config13_mult : nnet::dense_config {
    static const unsigned n_in = 4;
    static const unsigned n_out = 70;
    static const unsigned reuse_factor = 4;
    static const unsigned strategy = nnet::resource;
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config13 : nnet::conv1d_config {
    static const unsigned pad_left = 0;
    static const unsigned pad_right = 0;
    static const unsigned in_width = 73;
    static const unsigned n_chan = 4;
    static const unsigned filt_width = 1;
    static const unsigned kernel_size = filt_width;
    static const unsigned n_filt = 70;
    static const unsigned stride_width = 1;
    static const unsigned dilation = 1;
    static const unsigned out_width = 73;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    static const unsigned strategy = nnet::resource;
    static const nnet::conv_implementation implementation = nnet::conv_implementation::linebuffer;
    static const unsigned min_width = 1;
    static const ap_uint<filt_width> pixels[min_width];
    typedef model_default_t accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef config13_mult mult_config;
};
const ap_uint<config13::filt_width> config13::pixels[] = {1};

// concatenate
struct config11 : nnet::concat_config {
    static const unsigned n_elem1_0 = 73;
    static const unsigned n_elem1_1 = 4;
    static const unsigned n_elem1_2 = 0;
    static const unsigned n_elem2_0 = 73;
    static const unsigned n_elem2_1 = 70;
    static const unsigned n_elem2_2 = 0;

    static const int axis = -1;
};


#endif
