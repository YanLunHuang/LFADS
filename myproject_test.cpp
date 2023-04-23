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
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "firmware/myproject.h"
#include "firmware/nnet_utils/nnet_helpers.h"

//hls-fpga-machine-learning insert bram

#define CHECKPOINT 5000

namespace nnet {
    bool trace_enabled = true;
    std::map<std::string, void *> *trace_outputs = NULL;
    size_t trace_type_size = sizeof(double);
}

int main(int argc, char **argv)
{
  //load input data from text file
  std::ifstream fin("tb_data/tb_input_features.dat");
  //load predictions from text file
  std::ifstream fpr("tb_data/tb_output_predictions.dat");

#ifdef RTL_SIM
  std::string RESULTS_LOG = "tb_data/rtl_cosim_results.log";
#else
  std::string RESULTS_LOG = "tb_data/csim_results.log";
#endif
  std::ofstream fout(RESULTS_LOG);

  std::string iline;
  std::string pline;
  int e = 0;

  if (fin.is_open() && fpr.is_open()) {
    while ( std::getline(fin,iline) && std::getline (fpr,pline) ) {
      if (e % CHECKPOINT == 0) std::cout << "Processing input " << e << std::endl;
      char* cstr=const_cast<char*>(iline.c_str());
      char* current;
      std::vector<float> in;
      current=strtok(cstr," ");
      while(current!=NULL) {
        in.push_back(atof(current));
        current=strtok(NULL," ");
      }
      cstr=const_cast<char*>(pline.c_str());
      std::vector<float> pr;
      current=strtok(cstr," ");
      while(current!=NULL) {
        pr.push_back(atof(current));
        current=strtok(NULL," ");
      }

      //hls-fpga-machine-learning insert data
      hls::stream<input_t> input_1[70];
      nnet::copy_data_switch<float, input_t, 0, N_INPUT_1_1*N_INPUT_2_1,N_INPUT_2_1>(in, input_1);
      hls::stream<input3_t> input_2[64];
      nnet::copy_data_switch<float, input3_t, 5110, N_INPUT_1_3*N_INPUT_2_3,N_INPUT_2_3>(in, input_2);
      hls::stream<result_t> layer11_out[74];

      //hls-fpga-machine-learning insert top-level-function
      myproject(input_1,input_2,layer11_out);

      if (e % CHECKPOINT == 0) {
        std::cout << "Predictions" << std::endl;
        //hls-fpga-machine-learning insert predictions
        for(int i = 0; i < OUT_CONCAT_0_11*OUT_CONCAT_1_11; i++) {
          std::cout << pr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Quantized predictions" << std::endl;
        //hls-fpga-machine-learning insert quantized
        nnet::print_result_switch<result_t, OUT_CONCAT_0_11*OUT_CONCAT_1_11,OUT_CONCAT_1_11>(layer11_out, std::cout, true);
      }
      e++;

      //hls-fpga-machine-learning insert tb-output
      nnet::print_result_switch<result_t, OUT_CONCAT_0_11*OUT_CONCAT_1_11,OUT_CONCAT_1_11>(layer11_out, fout);

    }
    fin.close();
    fpr.close();
  } else {
    std::cout << "INFO: Unable to open input/predictions file, using default input." << std::endl;

    //hls-fpga-machine-learning insert zero
    hls::stream<input_t> input_1[70];
    nnet::fill_zero_switch<input_t, N_INPUT_1_1*N_INPUT_2_1, N_INPUT_2_1>(input_1);
    hls::stream<input3_t> input_2[64];
    nnet::fill_zero_switch<input3_t, N_INPUT_1_3*N_INPUT_2_3, N_INPUT_2_3>(input_2);
    hls::stream<result_t> layer11_out[74];
std::cout <<"start computation"<<std::endl;
    //hls-fpga-machine-learning insert top-level-function
    myproject(input_1,input_2,layer11_out);
std::cout <<"end computation"<<std::endl;
    //hls-fpga-machine-learning insert output
    nnet::print_result_switch<result_t, OUT_CONCAT_0_11*OUT_CONCAT_1_11,OUT_CONCAT_1_11>(layer11_out, std::cout, true);

    //hls-fpga-machine-learning insert tb-output
    nnet::print_result_switch<result_t, OUT_CONCAT_0_11*OUT_CONCAT_1_11,OUT_CONCAT_1_11>(layer11_out, fout);

  }

  fout.close();
  std::cout << "INFO: Saved inference results to file: " << RESULTS_LOG << std::endl;

  return 0;
}