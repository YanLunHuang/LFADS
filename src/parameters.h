#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "nnet_utils/nnet_code_gen.h"
#include "nnet_utils/nnet_helpers.h"
// hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_SRN_by_cycle.h"
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_activation_array_stream.h"
#include "nnet_utils/nnet_activation_stream.h"
#include "nnet_utils/nnet_bidirectional.h"
#include "nnet_utils/nnet_conv1d.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_array_stream.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"
#include "nnet_utils/nnet_explogvar_stream.h"
#include "nnet_utils/nnet_merge.h"
#include "nnet_utils/nnet_merge_stream.h"
#include "nnet_utils/nnet_recurrent.h"
#include "nnet_utils/nnet_recurrent_array_stream.h"
#include "nnet_utils/nnet_sepconv1d_array_stream.h"
#include "nnet_utils/nnet_sepconv1d_stream.h"
#include "nnet_utils/nnet_stream.h"

// hls-fpga-machine-learning insert weights
#include "weights/fw2.h"
#include "weights/bw2.h"
#include "weights/fwr2.h"
#include "weights/bwr2.h"
#include "weights/fb2.h"
#include "weights/fbr2.h"
#include "weights/bb2.h"
#include "weights/bbr2.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w19.h"
#include "weights/wr19.h"
#include "weights/b19.h"
#include "weights/br19.h"
#include "weights/w26.h"
#include "weights/b26.h"
#include "weights/w27.h"
#include "weights/b27.h"

// hls-fpga-machine-learning insert layer-config
// Encoder_BidirectionalGRU
struct config2_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_1;
    static const unsigned n_out = N_OUT_2 * 3 /2;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_1;
    static const unsigned n_zeros = 150;
    static const unsigned n_nonzeros = 13290;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense2_t accum_t;
    typedef forward_bias2_t bias_t;
    typedef forward_weight2_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config2_2 : nnet::dense_config {
    static const unsigned n_in = N_OUT_2/2;
    static const unsigned n_out = N_OUT_2 * 3 /2;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_OUT_2/2;
    static const unsigned n_zeros = 236;
    static const unsigned n_nonzeros = 12052;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense2_t accum_t;
    typedef forward_bias2_t bias_t;
    typedef forward_weight2_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct hard_sigmoid_config2_recr  : nnet::hard_activ_config {
    static const unsigned n_in = N_OUT_2 * 2 /2;
    static const slope2_t slope;
    static const shift2_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope2_t hard_sigmoid_config2_recr::slope = 0.5;
const shift2_t hard_sigmoid_config2_recr::shift = 0.5;

struct hard_tanh_config2 : nnet::hard_activ_config{
    static const unsigned n_in = N_OUT_2/2;
    static const slope2_t slope;
    static const shift2_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope2_t hard_tanh_config2::slope = 0.5;
const shift2_t hard_tanh_config2::shift = 0.5;

struct config2_f : nnet::gru_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef forward_weight2_t weight_t;  // Matrix
    typedef forward_bias2_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef hard_sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    typedef state2_t state_t;
    typedef act2_t act_t;
    typedef recr_act2_t recr_act_t;
    static const unsigned merge_mode = nnet::concat;
};

struct config2_b : nnet::gru_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef backward_weight2_t weight_t;  // Matrix
    typedef backward_bias2_t bias_t;  // Vector
    typedef config2_1 mult_config1;
    typedef config2_2 mult_config2;
    typedef hard_sigmoid_config2_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config2 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = 64;
    static const unsigned n_state = 64;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    typedef state2_t state_t;
    typedef act2_t act_t;
    typedef recr_act2_t recr_act_t;
    static const unsigned merge_mode = nnet::concat;
};

struct config2 : nnet::bidirectional_config {
    typedef accum_dense2_t accum_dense_t;
    typedef accum2_t accum_t;
    typedef backward_weight2_t weight_t;  // Matrix
    typedef backward_bias2_t bias_t;  // Vector

    typedef config2_f config_rnn_layer_f;
    typedef config2_b config_rnn_layer_b;
    static const unsigned n_in  = N_INPUT_2_1;
    static const unsigned n_out = N_OUT_2;
    static const unsigned n_state = N_OUT_2/2;
    static const unsigned n_sequence = N_INPUT_1_1;
    static const unsigned n_sequence_out = 1;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const unsigned merge_mode = nnet::concat;
};

// q_act_postencoder
struct linear_config3 : nnet::activ_config {
    static const unsigned n_in = 128;
    static const unsigned n_chan = N_OUT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act_postencoder_table_t table_t;
};

// dense_mean
struct config4 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 199;
    static const unsigned n_nonzeros = 7993;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum4_t accum_t;
    typedef bias4_t bias_t;
    typedef weight4_t weight_t;
    typedef layer4_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// dense_logvar
struct config6 : nnet::dense_config {
    static const unsigned n_in = 128;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = 128;
    static const unsigned n_zeros = 199;
    static const unsigned n_nonzeros = 7993;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum6_t accum_t;
    typedef bias6_t bias_t;
    typedef weight6_t weight_t;
    typedef layer6_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_activation_6
struct linear_config8 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_6_table_t table_t;
};

// q_activation_8
struct linear_config9 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_8_table_t table_t;
};

// exponent_logvar_1
struct config10 : nnet::explogvar_config {
    static const unsigned n_elem = 64;
    static const unsigned table_size = 1024;
    typedef exponent_logvar_1_exp_table_t exp_table_t;
};

// standard_random_normal_1
struct config11 : nnet::srn_config {
    static const unsigned n_elem = 64;
    static const unsigned seed = 42;
    static const unsigned n_samples = 4;
    typedef ap_fixed<16,6> seed_t;
};

nnet::GRNGArray<config11::n_elem, config11::n_samples, typename config11::seed_t> normal{config11::seed};
// q_activation_9
struct linear_config12 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_9_table_t table_t;
};

// q_activation_7
struct linear_config13 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_7_table_t table_t;
};

// multiply_1
struct config14 : nnet::merge_config {
    static const unsigned n_elem = N_LAYER_6;
};

// q_activation_10
struct linear_config15 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_10_table_t table_t;
};

// add_1
struct config16 : nnet::merge_config {
    static const unsigned n_elem = N_LAYER_4;
};

// q_activation_11
struct linear_config18 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned n_chan = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_activation_11_table_t table_t;
};

// DecoderGRU
struct config19_1 : nnet::dense_config {
    static const unsigned n_in = N_INPUT_2_17;
    static const unsigned n_out = N_OUT_19 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_INPUT_2_17;
    static const unsigned n_zeros = 194;
    static const unsigned n_nonzeros = 12094;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense19_t accum_t;
    typedef bias19_t bias_t;
    typedef weight19_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config19_2 : nnet::dense_config {
    static const unsigned n_in = N_OUT_19;
    static const unsigned n_out = N_OUT_19 * 3;
    static const unsigned strategy = nnet::resource;
    static const unsigned reuse_factor = N_OUT_19;
    static const unsigned n_zeros = 236;
    static const unsigned n_nonzeros = 12052;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef accum_dense19_t accum_t;
    typedef bias19_t bias_t;
    typedef weight19_t weight_t;
    typedef ap_uint<1> index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct hard_sigmoid_config19_recr  : nnet::hard_activ_config {
    static const unsigned n_in = N_OUT_19 * 2;
    static const slope19_t slope;
    static const shift19_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope19_t hard_sigmoid_config19_recr::slope = 0.5;
const shift19_t hard_sigmoid_config19_recr::shift = 0.5;

struct hard_tanh_config19 : nnet::hard_activ_config{
    static const unsigned n_in = N_OUT_19;
    static const slope19_t slope;
    static const shift19_t shift;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
};
const slope19_t hard_tanh_config19::slope = 0.5;
const shift19_t hard_tanh_config19::shift = 0.5;

struct config19 : nnet::gru_config {
    typedef accum_dense19_t accum_dense_t;
    typedef accum19_t accum_t;
    typedef weight19_t weight_t;  // Matrix
    typedef bias19_t bias_t;  // Vector
    typedef config19_1 mult_config1;
    typedef config19_2 mult_config2;
    typedef hard_sigmoid_config19_recr ACT_CONFIG_GRU;
    template<class x_T, class y_T, class config_T>
    using activation_recr = nnet::activation::hard_sigmoid<x_T, y_T, config_T>;
    typedef hard_tanh_config19 ACT_CONFIG_T;
    template<class x_T, class y_T, class config_T>
    using activation = nnet::activation::hard_tanh<x_T, y_T, config_T>;
    static const unsigned n_in  = N_INPUT_2_17;
    static const unsigned n_out = N_OUT_19;
    static const unsigned n_state = N_OUT_19;
    static const unsigned n_sequence = N_INPUT_1_17;
    static const unsigned n_sequence_out = N_TIME_STEPS_19;
    static const unsigned io_type = nnet::resource;
    static const unsigned reuse_factor = 1;
    static const bool store_weights_in_bram = false;
    static const bool use_static = true;
    static const bool use_initial = 1;
    typedef state19_t state_t;
    typedef act19_t act_t;
    typedef recr_act19_t recr_act_t;
};

// q_act_postdecoder
struct linear_config20 : nnet::activ_config {
    static const unsigned n_in = 4672;
    static const unsigned n_chan = N_OUT_19;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act_postdecoder_table_t table_t;
};

// dense_factor
struct config26_mult : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 4;
    static const unsigned reuse_factor = 64;
    static const unsigned strategy = nnet::resource;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef dense_factor_bias_t bias_t;
    typedef dense_factor_weight_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config26 : nnet::conv1d_config {
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
    static const unsigned min_width = 73;
    static const ap_uint<filt_width> pixels[min_width];
    static const unsigned n_partitions = 73;
    static const unsigned n_pixels = out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv1DBuffer<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef dense_factor_bias_t bias_t;
    typedef dense_factor_weight_t weight_t;
    typedef config26_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index = nnet::scale_index_unscaled<K, S, W>;
};
const ap_uint<config26::filt_width> config26::pixels[] = {0};

// q_act3_postfactor
struct linear_config23 : nnet::activ_config {
    static const unsigned n_in = 292;
    static const unsigned n_chan = N_FILT_26;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_array_stream;
    static const unsigned reuse_factor = 1;
    typedef q_act3_postfactor_table_t table_t;
};

// nerual_dense
struct config27_mult : nnet::dense_config {
    static const unsigned n_in = 4;
    static const unsigned n_out = 70;
    static const unsigned reuse_factor = 4;
    static const unsigned strategy = nnet::resource;
    static const unsigned n_zeros = 0;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    typedef model_default_t accum_t;
    typedef nerual_dense_bias_t bias_t;
    typedef nerual_dense_weight_t weight_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

struct config27 : nnet::conv1d_config {
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
    static const unsigned min_width = 73;
    static const ap_uint<filt_width> pixels[min_width];
    static const unsigned n_partitions = 73;
    static const unsigned n_pixels = out_width / n_partitions;
    template<class data_T, class CONFIG_T>
    using fill_buffer = nnet::FillConv1DBuffer<data_T, CONFIG_T>;
    typedef model_default_t accum_t;
    typedef nerual_dense_bias_t bias_t;
    typedef nerual_dense_weight_t weight_t;
    typedef config27_mult mult_config;
    template<unsigned K, unsigned S, unsigned W>
    using scale_index = nnet::scale_index_unscaled<K, S, W>;
};
const ap_uint<config27::filt_width> config27::pixels[] = {0};


#endif
