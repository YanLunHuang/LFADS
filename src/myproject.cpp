#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    hls::stream<input_t> encoder_input[70], hls::stream<input17_t> decoder_input[64],
    hls::stream<result_t> layer27_out[70]
) {

    // hls-fpga-machine-learning insert IO
	 #pragma HLS DATAFLOW

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        // hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<forward_weight2_t, 13440>(fw2, "fw2.txt");
        nnet::load_weights_from_txt<backward_weight2_t, 13440>(bw2, "bw2.txt");
        nnet::load_weights_from_txt<forward_recurrent_weight2_t, 12288>(fwr2, "fwr2.txt");
        nnet::load_weights_from_txt<backward_recurrent_weight2_t, 12288>(bwr2, "bwr2.txt");
        nnet::load_weights_from_txt<forward_bias2_t, 192>(fb2, "fb2.txt");
        nnet::load_weights_from_txt<forward_recurrent_bias2_t, 192>(fbr2, "fbr2.txt");
        nnet::load_weights_from_txt<backward_bias2_t, 192>(bb2, "bb2.txt");
        nnet::load_weights_from_txt<backward_recurrent_bias2_t, 192>(bbr2, "bbr2.txt");
        nnet::load_weights_from_txt<weight4_t, 8192>(w4, "w4.txt");
        nnet::load_weights_from_txt<bias4_t, 64>(b4, "b4.txt");
        nnet::load_weights_from_txt<weight6_t, 8192>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 64>(b6, "b6.txt");
        nnet::load_weights_from_txt<weight19_t, 12288>(w19, "w19.txt");
        nnet::load_weights_from_txt<recurrent_weight19_t, 12288>(wr19, "wr19.txt");
        nnet::load_weights_from_txt<bias19_t, 192>(b19, "b19.txt");
        nnet::load_weights_from_txt<recurrent_bias19_t, 192>(br19, "br19.txt");
        nnet::load_weights_from_txt<dense_factor_weight_t, 256>(w26, "w26.txt");
        nnet::load_weights_from_txt<dense_factor_bias_t, 4>(b26, "b26.txt");
        nnet::load_weights_from_txt<nerual_dense_weight_t, 280>(w27, "w27.txt");
        nnet::load_weights_from_txt<nerual_dense_bias_t, 70>(b27, "b27.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************
	
    // hls-fpga-machine-learning insert layers

    hls::stream<layer2_t> layer2_out[128];
    #pragma HLS STREAM variable=layer2_out depth=1
    nnet::bidirectional_array<input_t, layer2_t, config2>(encoder_input, layer2_out, bw2, bwr2, bb2, bbr2, fw2, fwr2, fb2, fbr2); // Encoder_BidirectionalGRU

    hls::stream<layer3_t> layer3_out[128];
    #pragma HLS STREAM variable=layer3_out depth=1
    nnet::linear<layer2_t, layer3_t, linear_config3>(layer2_out, layer3_out); // q_act_postencoder

    hls::stream<layer28_t> layer28_cpy1[128];
    #pragma HLS STREAM variable=layer28_cpy1 depth=1
    hls::stream<layer28_t> layer28_cpy2[128];
    #pragma HLS STREAM variable=layer28_cpy2 depth=1
    nnet::clone_stream<layer3_t, layer28_t, 128>(layer3_out, layer28_cpy1, layer28_cpy2); // clone_q_act_postencoder

    hls::stream<layer4_t> layer4_out[64];
    #pragma HLS STREAM variable=layer4_out depth=1
    nnet::dense<layer28_t, layer4_t, config4>(layer28_cpy1, layer4_out, w4, b4); // dense_mean

    hls::stream<layer6_t> layer6_out[64];
    #pragma HLS STREAM variable=layer6_out depth=1
    nnet::dense<layer28_t, layer6_t, config6>(layer28_cpy2, layer6_out, w6, b6); // dense_logvar

    hls::stream<layer8_t> layer8_out[64];
    #pragma HLS STREAM variable=layer8_out depth=1
    nnet::linear<layer4_t, layer8_t, linear_config8>(layer4_out, layer8_out); // q_activation_30

    hls::stream<layer29_t> layer29_cpy1[64];
    #pragma HLS STREAM variable=layer29_cpy1 depth=1
    hls::stream<layer29_t> layer29_cpy2[64];
    #pragma HLS STREAM variable=layer29_cpy2 depth=1
    nnet::clone_stream<layer8_t, layer29_t, 64>(layer8_out, layer29_cpy1, layer29_cpy2); // clone_q_activation_30

    hls::stream<layer9_t> layer9_out[64];
    #pragma HLS STREAM variable=layer9_out depth=1
    nnet::linear<layer6_t, layer9_t, linear_config9>(layer6_out, layer9_out); // q_activation_32

    hls::stream<layer10_t> layer10_out[64];
    #pragma HLS STREAM variable=layer10_out depth=1
    nnet::explogvar<layer9_t, layer10_t, config10>(layer9_out, layer10_out); // exponent_logvar_5

    hls::stream<layer11_t> layer11_out[64];
    #pragma HLS STREAM variable=layer11_out depth=1
    nnet::srn<layer29_t, layer11_t, config11>(layer29_cpy1, layer11_out, normal); // standard_random_normal_5

    hls::stream<layer12_t> layer12_out[64];
    #pragma HLS STREAM variable=layer12_out depth=1
    nnet::linear<layer10_t, layer12_t, linear_config12>(layer10_out, layer12_out); // q_activation_33

    hls::stream<layer13_t> layer13_out[64];
    #pragma HLS STREAM variable=layer13_out depth=1
    nnet::linear<layer11_t, layer13_t, linear_config13>(layer11_out, layer13_out); // q_activation_31

    hls::stream<layer14_t> layer14_out[64];
    #pragma HLS STREAM variable=layer14_out depth=1
    nnet::multiply<layer12_t, layer13_t, layer14_t, config14>(layer12_out, layer13_out, layer14_out); // multiply_5

    hls::stream<layer15_t> layer15_out[64];
    #pragma HLS STREAM variable=layer15_out depth=1
    nnet::linear<layer14_t, layer15_t, linear_config15>(layer14_out, layer15_out); // q_activation_34

    hls::stream<layer16_t> layer16_out[64];
    #pragma HLS STREAM variable=layer16_out depth=1
    nnet::add<layer29_t, layer15_t, layer16_t, config16>(layer29_cpy2, layer15_out, layer16_out); // add_5

    hls::stream<layer18_t> layer18_out[64];
    #pragma HLS STREAM variable=layer18_out depth=1
    nnet::linear<layer16_t, layer18_t, linear_config18>(layer16_out, layer18_out); // q_activation_35

    hls::stream<layer19_t> layer19_out[64];
    #pragma HLS STREAM variable=layer19_out depth=73
    nnet::gru_stack_array<input17_t, layer18_t, layer19_t, config19>(decoder_input, layer18_out, layer19_out, w19, wr19, b19, br19); // DecoderGRU

    hls::stream<layer20_t> layer20_out[64];
    #pragma HLS STREAM variable=layer20_out depth=73
    nnet::linear<layer19_t, layer20_t, linear_config20>(layer19_out, layer20_out); // q_act_postdecoder

    hls::stream<layer26_t> layer26_out[4];
    #pragma HLS STREAM variable=layer26_out depth=73
    nnet::pointwise_conv_1d_cl<layer20_t, layer26_t, config26>(layer20_out, layer26_out, w26, b26); // dense_factor

    hls::stream<layer23_t> layer23_out[4];
    #pragma HLS STREAM variable=layer23_out depth=73
    nnet::linear<layer26_t, layer23_t, linear_config23>(layer26_out, layer23_out); // q_act3_postfactor

    nnet::pointwise_conv_1d_cl<layer23_t, result_t, config27>(layer23_out, layer27_out, w27, b27); // nerual_dense

}
