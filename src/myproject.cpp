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

template<class data_T, class data_T2, class res_T, typename CONFIG_T>
void  concatenate1d(data_T data[CONFIG_T::n_elem1_0],data_T2 data2[CONFIG_T::n_elem2_0], res_T res[CONFIG_T::n_out])
{
    #pragma HLS PIPELINE

    for (int ii=0; ii<CONFIG_T::n_elem1_0; ii++) {
        #pragma HLS UNROLL
        res[ii] = data[ii];
    }

    for (int ii=0; ii<CONFIG_T::n_elem2_0; ii++) {
        #pragma HLS UNROLL
        res[ii+CONFIG_T::n_elem1_0] = data2[ii];
    }
}



void myproject(
    input_t input_1[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1], input2_t input_2[N_INPUT_1_2*N_INPUT_2_2*N_INPUT_3_2],
    result_t layer9_out[OUT_CONCAT_9]
) {

    //hls-fpga-machine-learning insert IO
    #pragma HLS DATAFLOW 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        //hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<model_default_t, 162>(w3, "w3.txt");
        nnet::load_weights_from_txt<model_default_t, 6>(b3, "b3.txt");
        nnet::load_weights_from_txt<model_default_t, 180>(w5, "w5.txt");
        nnet::load_weights_from_txt<model_default_t, 4>(b5, "b5.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    //hls-fpga-machine-learning insert layers

    layer3_t layer3_out[OUT_HEIGHT_3*OUT_WIDTH_3*N_FILT_3];
    #pragma HLS ARRAY_PARTITION variable=layer3_out complete dim=0
    nnet::conv_2d_cl<input_t, layer3_t, config3>(input_1, layer3_out, w3, b3); // conv2d

    layer4_t layer4_out[OUT_HEIGHT_3*OUT_WIDTH_3*N_FILT_3];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0
    nnet::linear<layer3_t, layer4_t, linear_config4>(layer3_out, layer4_out); // conv2d_linear

    layer5_t layer5_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::conv_2d_cl<input2_t, layer5_t, config5>(input_2, layer5_out, w5, b5); // conv2d_1

    layer6_t layer6_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
    nnet::linear<layer5_t, layer6_t, linear_config6>(layer5_out, layer6_out); // conv2d_1_linear

    concatenate1d<layer4_t, layer6_t, result_t, config9>(layer4_out, layer6_out, layer9_out); // concatenate_1
}
