//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
    hls::stream<input_t> input_1[70], hls::stream<input3_t> input_2[64],
    hls::stream<result_t> layer11_out[74]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=input_1,input_2,layer11_out 
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 13440>(backward_gru_1_gru_cell_1_weight2, "backward_gru_1_gru_cell_1_weight2.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(forward_gru_gru_cell_2_bias2, "forward_gru_gru_cell_2_bias2.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(forward_gru_recurrent_bias2, "forward_gru_recurrent_bias2.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(backward_gru_1_gru_cell_1_bias2, "backward_gru_1_gru_cell_1_bias2.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(backward_gru_recurrent_bias2, "backward_gru_recurrent_bias2.txt");
        nnet::load_weights_from_txt<model_default_t, 12288>(backward_gru_1_gru_cell_1_recurrent_weight2, "backward_gru_1_gru_cell_1_recurrent_weight2.txt");
        nnet::load_weights_from_txt<model_default_t, 13440>(forward_gru_gru_cell_2_weight2, "forward_gru_gru_cell_2_weight2.txt");
        nnet::load_weights_from_txt<model_default_t, 12288>(forward_gru_gru_cell_2_recurrent_weight2, "forward_gru_gru_cell_2_recurrent_weight2.txt");
        nnet::load_weights_from_txt<model_default_t, 8192>(w4, "w4.txt");
        nnet::load_weights_from_txt<model_default_t, 64>(b4, "b4.txt");
        nnet::load_weights_from_txt<model_default_t, 12288>(w6, "w6.txt");
        nnet::load_weights_from_txt<model_default_t, 12288>(wr6, "wr6.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(b6, "b6.txt");
        nnet::load_weights_from_txt<model_default_t, 192>(br6, "br6.txt");
        nnet::load_weights_from_txt<model_default_t, 256>(w12, "w12.txt");
        nnet::load_weights_from_txt<bias12_t, 4>(b12, "b12.txt");
        nnet::load_weights_from_txt<model_default_t, 280>(w13, "w13.txt");
        nnet::load_weights_from_txt<model_default_t, 70>(b13, "b13.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers
std::cout <<" 1"<<std::endl;
    hls::stream<layer2_t> layer2_out[128];
    #pragma HLS STREAM variable=layer2_out depth=1
    nnet::bidirectional_array<input_t, layer2_t, config2>(input_1, layer2_out, backward_gru_1_gru_cell_1_weight2, backward_gru_1_gru_cell_1_recurrent_weight2, backward_gru_1_gru_cell_1_bias2, backward_gru_recurrent_bias2,forward_gru_gru_cell_2_weight2,forward_gru_gru_cell_2_recurrent_weight2, forward_gru_gru_cell_2_bias2, forward_gru_recurrent_bias2); // Encoder_BidirectionalGRU
std::cout <<" 2"<<std::endl;
    hls::stream<layer4_t> layer4_out[64];
    #pragma HLS STREAM variable=layer4_out depth=1
    nnet::dense_array<layer2_t, layer4_t, config4>(layer2_out, layer4_out, w4, b4); // dense_mean
std::cout <<" 3"<<std::endl;
    hls::stream<layer6_t> layer6_out[64];
    #pragma HLS STREAM variable=layer6_out depth=73
    nnet::gru_stack_array<input3_t, layer6_t, config6>(input_2, layer4_out, layer6_out, w6, wr6, b6, br6); // decoder_GRU
std::cout <<" 4"<<std::endl;
    hls::stream<layer12_t> layer12_out[4];
    #pragma HLS STREAM variable=layer12_out depth=73
    nnet::pointwise_conv_1d_cl_array<layer6_t, layer12_t, config12>(layer6_out, layer12_out, w12, b12); // dense
std::cout <<" 5"<<std::endl;
    hls::stream<layer14_t> layer14_cpy1[4];
    #pragma HLS STREAM variable=layer14_cpy1 depth=73
    hls::stream<layer14_t> layer14_cpy2[4];
    #pragma HLS STREAM variable=layer14_cpy2 depth=73
    nnet::clone_stream_array<layer12_t, layer14_t, 292>(layer12_out, layer14_cpy1, layer14_cpy2); // clone_dense
std::cout <<" 6"<<std::endl;
    hls::stream<layer13_t> layer13_out[70];
    #pragma HLS STREAM variable=layer13_out depth=73
    nnet::pointwise_conv_1d_cl_array<layer14_t, layer13_t, config13>(layer14_cpy1, layer13_out, w13, b13); // nerual_dense
std::cout <<" 7"<<std::endl;
    nnet::concatenate2d_1_array<layer14_t, layer13_t, result_t, config11>(layer14_cpy2, layer13_out, layer11_out); // concatenate

}
