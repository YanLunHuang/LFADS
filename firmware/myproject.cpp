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
    hls::stream<input_t> input_1[N_INPUT_2_1],
    hls::stream<result_t> layer2_out[N_OUT_2]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS INTERFACE axis port=input_1,layer2_out 

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
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************
    #pragma HLS DATAFLOW
    //hls-fpga-machine-learning insert layers
    nnet::bidirectional<input_t, result_t, config2>(input_1, layer2_out, backward_gru_1_gru_cell_1_weight2, backward_gru_1_gru_cell_1_recurrent_weight2, backward_gru_1_gru_cell_1_bias2, backward_gru_recurrent_bias2,forward_gru_gru_cell_2_weight2,forward_gru_gru_cell_2_recurrent_weight2, forward_gru_gru_cell_2_bias2, forward_gru_recurrent_bias2); // Encoder_BidirectionalGRU


}
