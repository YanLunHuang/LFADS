/**********
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "xcl2.hpp"
#include <vector>
#include "kernel_params.h"

#define STRINGIFY2(var) #var
#define STRINGIFY(var) STRINGIFY2(var)

static uint64_t get_duration_ns(const cl::Event & events) {
    uint64_t duration = 0;
    //for (size_t i=0; i<events.size(); i++) {
        uint64_t start, end;
        events.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START, &start);
        events.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END, &end);
        duration += end - start;
    //}
    return duration;
}

int main(int argc, char** argv)
{
    std::cout<<"==========host_X_Nbuffer_2CU.cpp==========="<<std::endl;
    std::cout<<"2CU"<<std::endl;
    std::cout<<"N normal buffers"<<std::endl;
    std::cout<<"====================================="<<std::endl;
    int nevents = 100;
    int num_buf = 1;
    cl_int err;
    std::string datadir = STRINGIFY(HLS4ML_DATA_DIR);
    std::string xclbinFilename = "";
    std::string print_or_not = "true";
    if (argc > 1) xclbinFilename = argv[1];
    if (argc > 2) nevents = atoi(argv[2]);
    if (argc > 3) num_buf = atoi(argv[3]);
    if (argc > 4) print_or_not = argv[4];
    if (argc > 5) datadir = argv[5];
    std::cout << "Will run " << nevents << " time(s)" << std::endl;
    std::cout << "Choose to print out the prediction: " << print_or_not <<std::endl;
    std::cout << "Using " << datadir << " to get input features and output predictions (tb_input_features.dat and tb_output_predictions.dat)" << std::endl;

//=====================================================
//Find device & Load xclbin file & Program device
//=====================================================

    // OPENCL HOST CODE AREA START
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    cl::Kernel alveo_hls4ml_1,alveo_hls4ml_2;
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q1(context, device, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE);
    cl::CommandQueue q2(context, device, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Found Device=" << device_name.c_str() << std::endl;
    
    cl::Program::Binaries bins;
    // Load xclbin
    std::cout << "Loading: '" << xclbinFilename << "'\n";
    std::ifstream bin_file(xclbinFilename, std::ifstream::binary);
    bin_file.seekg (0, bin_file.end);
    unsigned nb = bin_file.tellg();
    bin_file.seekg (0, bin_file.beg);
    char *buf = new char [nb];
    bin_file.read(buf, nb);
    // Create Program from Binary File
    bins.push_back({buf,nb});
    
    // Program the device
    bool valid_device = false;
    cl::Program program(context, {device}, bins, nullptr, &err);
    if (err != CL_SUCCESS) {
        std::cout << "Failed to program device with xclbin file!\n";
    }else {
        std::cout <<"program successful!\n";
        std::string cu_id = std::to_string(1);
        std::string krnl_name_full = "alveo_hls4ml";
        printf("Creating a kernel [%s] for CU(%d)\n", krnl_name_full.c_str(), 0);
        alveo_hls4ml_1 = cl::Kernel(program,"alveo_hls4ml:{alveo_hls4ml_1}");
        alveo_hls4ml_2 = cl::Kernel(program,"alveo_hls4ml:{alveo_hls4ml_2}");
        valid_device = true;
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }

//=====================
//Create buffer
//=====================

    size_t vector_size_in1_bytes = sizeof(group_in1) *STREAM_LEN_IN1*DATA_SET;
    size_t vector_size_in2_bytes = sizeof(group_in2) *STREAM_LEN_IN2*DATA_SET;
    size_t vector_size_out_bytes = sizeof(group_out) *STREAM_LEN_OUT*DATA_SET;

    std::vector<group_in1,aligned_allocator<group_in1>> source_in1(STREAM_LEN_IN1*DATA_SET);
    std::vector<group_in2,aligned_allocator<group_in2>> source_in2(STREAM_LEN_IN2*DATA_SET);
    std::vector<group_out,aligned_allocator<group_out>> source_hw_results(STREAM_LEN_OUT*DATA_SET);

    std::vector< std::vector<group_in1,aligned_allocator<group_in1>> >vec_in1;
    std::vector< std::vector<group_in2,aligned_allocator<group_in2>> >vec_in2;
    std::vector< std::vector<group_out,aligned_allocator<group_out>> >vec_output;

    std::vector<cl::Buffer>vec_in_buf1;
    std::vector<cl::Buffer>vec_in_buf2;
    std::vector<cl::Buffer>vec_out_buf1;

    //Reset the input data
    for(int N=0;N<num_buf*2;N++){
        vec_in1.push_back(source_in1);
        std::cout << "Reset the input data1 " << std::endl;
        for(int i0 = 0; i0 < STREAM_LEN_IN1*DATA_SET; i0++) {
            for(int i1 = 0; i1 < STREAM_SIZE_IN1; i1++) {
                vec_in1[N][i0].layer[i1] = 1;
            }
        }
    }
    for(int N=0;N<num_buf*2;N++){
        vec_in2.push_back(source_in2);
        std::cout << "Reset the input data2 " << std::endl;
        for(int i0 = 0; i0 < STREAM_LEN_IN2*DATA_SET; i0++) {
            for(int i1 = 0; i1 < STREAM_SIZE_IN2; i1++) {
                vec_in2[N][i0].layer[i1] = 1;
            }
        }
    }
    //Reset the output result
    for(int N=0;N<num_buf*2;N++){
        vec_output.push_back(source_hw_results);
        std::cout << "Reset the output result " << std::endl;
        for(int i0 = 0 ; i0 < STREAM_LEN_OUT*DATA_SET; i0++){
            for(int i1 = 0 ; i1 < STREAM_SIZE_OUT; i1++){
                vec_output[N][i0].layer[i1] = 1;
            }
        }
    }
    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and 
    // Device-to-host communication
    for(int N=0;N<num_buf*2;N++){
        cl::Buffer buffer_in1   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
                vector_size_in1_bytes, vec_in1[N].data());
        cl::Buffer buffer_in2   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
                vector_size_in2_bytes, vec_in2[N].data());
        cl::Buffer buffer_output(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
                vector_size_out_bytes, vec_output[N].data());

        vec_in_buf1.push_back(buffer_in1);
        vec_in_buf2.push_back(buffer_in2);
        vec_out_buf1.push_back(buffer_output);
    }
//=====================
//Input
//=====================

    // Load input data from text file
    std::ifstream fin(datadir+"/tb_input_features.dat");
    // Load predictions from text file
    std::ifstream fpr(datadir+"/tb_output_predictions.dat");
    // Open output file
    std::ofstream fout;
    fout.open("tb_output_data.dat");
    
    std::string iline;
    std::string pline;
    
    int exp_times = 0;

    // Flag for success/failure of finding data files
    if (!(fin.is_open()) || !(fpr.is_open())) {
        std::cout << "Unable to open input/predictions file, using random input" << std::endl;
        exit(EXIT_FAILURE);
    }
    else std::cout <<"successfully open input and output file"<<std::endl;
    
    // Get inputs/predictions from files
    if(fin.is_open() && fpr.is_open()){
      while(std::getline(fin,iline) && std::getline(fpr,pline)) {
        
        std::cout << "Processing event " << exp_times << std::endl;
        fout << "Processing event " << exp_times << "\n";
        exp_times++;
        
        // Here is input.
        char* cstr=const_cast<char*>(iline.c_str());
        char* current;
        std::vector<float> in;
        current=strtok(cstr," ");
        while(current!=NULL){
            in.push_back(atof(current));
            current=strtok(NULL," ");
        }
        
        //Here is the corresponding output(correct one)
        cstr=const_cast<char*>(pline.c_str());
        std::vector<float> pr;
        current=strtok(cstr," ");
        while(current!=NULL){
            pr.push_back(atof(current));
            current=strtok(NULL," ");
        }
      //Send into buffer
      for(int N = 0; N < num_buf*2; N++) {
        std::cout << "Send into buffer1 " << std::endl;
        for(int i0 = 0; i0 < DATA_SET; i0++) {
            for(int i1 = 0; i1 < STREAM_LEN_IN1; i1++) {
                for(int i2 = 0; i2 < STREAM_SIZE_IN1; i2++) {
                    vec_in1[N][i0*STREAM_LEN_IN1+i1].layer[i2] = in[i1*STREAM_SIZE_IN1+i2];
                }
            }
        }
      }
      for(int N = 0; N < num_buf*2; N++) {
        std::cout << "Send into buffer2 " << std::endl;
        for(int i0 = 0; i0 < DATA_SET; i0++) {
            for(int i1 = 0; i1 < STREAM_LEN_IN2; i1++) {
                for(int i2 = 0; i2 < STREAM_SIZE_IN2; i2++) {
                    vec_in2[N][i0*STREAM_LEN_IN2+i1].layer[i2] = in[i1*STREAM_SIZE_IN2+i2];
                }
            }
        }
      }
//========================
//Start to run on FPGA
//========================
    auto t1 = Clock::now();
    auto t5 = Clock::now();
    uint64_t current_total = 0;
    std::vector<cl::Event> Read1,Read2,Read3,Read4;
    std::vector<cl::Event> Kernel1,Kernel2,Kernel3,Kernel4;
    std::vector<cl::Event> Write1,Write2,Write3,Write4;
    cl::Event Task1_R,Task1_K,Task1_W;
    cl::Event Task2_R,Task2_K,Task2_W;
    std::cout << "start computation" << std::endl;
    for(int i=0; i<nevents; i++){
        t1 = Clock::now();
        for(int N=0; N<num_buf; N++){
            //vec_in_buf1[0]~vec_in_buf1[N-1] -> for CU1
            alveo_hls4ml_1.setArg(0, vec_in_buf1[N]);
            alveo_hls4ml_1.setArg(1, vec_in_buf2[N]);
            alveo_hls4ml_1.setArg(2, vec_out_buf1[N]);
            q1.enqueueMigrateMemObjects({vec_in_buf1[N],vec_in_buf2[N]},0/* 0 means from host*/,&Read1,&Task1_W);
            Read1.push_back(Task1_W);
            q1.enqueueTask(alveo_hls4ml_1,&Read1,&Task1_K);
            Kernel1.push_back(Task1_K);
            q1.enqueueMigrateMemObjects({vec_out_buf1[N]},CL_MIGRATE_MEM_OBJECT_HOST,&Kernel1,&Task1_R);
            Write1.push_back(Task1_R);

            //vec_in_buf1[N]~vec_in_buf1[2N-1] -> for CU2
            alveo_hls4ml_2.setArg(0, vec_in_buf1[num_buf+N]);
            alveo_hls4ml_2.setArg(1, vec_in_buf2[num_buf+N]);
            alveo_hls4ml_2.setArg(2, vec_out_buf1[num_buf+N]);
            q2.enqueueMigrateMemObjects({vec_in_buf1[num_buf+N],vec_in_buf2[num_buf+N]},0/* 0 means from host*/,&Read2,&Task2_R);
            Read2.push_back(Task2_R);
            q2.enqueueTask(alveo_hls4ml_2,&Read2,&Task2_K);
            Kernel2.push_back(Task2_K);
            q2.enqueueMigrateMemObjects({vec_out_buf1[num_buf+N]},CL_MIGRATE_MEM_OBJECT_HOST,&Kernel2,&Task2_W);
            Write2.push_back(Task2_W);

        }
        for(int N=0; N<num_buf; N++){
            Write1[N].wait();
            Write2[N].wait();
        }
        t5 = Clock::now();
        Read1.clear();
        Read2.clear();
        Kernel1.clear();
        Kernel2.clear();
        Write1.clear();
        Write2.clear();
        if(i!=0)current_total += std::chrono::duration_cast<std::chrono::nanoseconds>(t5 - t1).count();
        //uint64_t execution1 = get_duration_ns(Task1_K1); 
        //uint64_t execution2 = get_duration_ns(Task1_K2); 
        std::cout << "computation: " << i << std::endl;
        std::cout << "t5 - t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t5 - t1).count() << " ns" <<std::endl;
        //std::cout << "execution1: " << execution1 << " ns" << std::endl;
        //std::cout << "execution2: " << execution2 << " ns" << std::endl;
        std::cout << "current_total: " << current_total << " ns" << std::endl;
        std::cout << "prediction: " << std::endl; 
        for(int N=0;N<num_buf*2;N++){
            if(N<num_buf)fout << "1CU buffer"<<N<< "\n";
            else fout << "2CU buffer"<<N-num_buf<< "\n";
            for(int j=0;j<STREAM_SIZE_OUT;j++){
                fout << vec_output[N][STREAM_LEN_OUT*DATA_SET-1].layer[j] << " "; 
            }
            fout << "\n";
        }
        fout << "\n"; 
        fout << "================================="; 
        if(i!=nevents-1){
            fout << " reset \n"; 
            for(int N=0;N<num_buf*2;N++){
                for(int j=0;j<STREAM_SIZE_OUT;j++){
                    vec_output[N][STREAM_LEN_OUT*DATA_SET-1].layer[j] = 1; 
                }
            }
            for(int N=0;N<num_buf*2;N++){
                if(N<num_buf)fout << "1CU buffer"<<N<< "\n";
                else fout << "2CU buffer"<<N-num_buf<< "\n";
                for(int j=0;j<STREAM_SIZE_OUT;j++){
                    fout << vec_output[N][STREAM_LEN_OUT*DATA_SET-1].layer[j] << " "; 
                }
                fout << "\n";
            }
        }
    }
        //print timing
        std::cout << "=========================================" <<std::endl;
        std::cout << "FPGA average time: " << current_total/(nevents-1) << " ns" << std::endl;
        fout << "FPGA average time: " << current_total/(nevents-1) << " ns \n";
//=====================
//Output result
//=====================
        if(print_or_not=="true"){
            std::cout<<"Predictions: \n";
            fout <<"Predictions:  \n";
            for(int i=0;i<DATA_SET;i++){
                for(int j=0;j<STREAM_LEN_OUT*STREAM_SIZE_OUT ;j++){
                    fout << pr[j] << " ";
                }
            }
            std::cout << std::endl;
            fout<<"\n\n";

            for(int N=0;N<num_buf*2;N++){
                if(N<num_buf)std::cout<<"Quantized predictions(1CU) buf"<<N<<": \n";
                else std::cout<<"Quantized predictions(2CU) buf"<<N-num_buf<<": \n";
                if(N<num_buf)fout <<"Quantized predictions(1CU) buf"<<N<<": \n";
                else fout <<"Quantized predictions(2CU) buf"<<N-num_buf<<": \n";
                for(int i=0;i<STREAM_LEN_OUT*DATA_SET;i++){
                    for(int j=0;j<STREAM_SIZE_OUT;j++){
                        fout << vec_output[N][i].layer[j] << " "; 
                    }
                }
                std::cout << std::endl;
                fout << "\n\n";
            }

        }
        std::cout<<"---- END EVENT "<<" ----"<<std::endl;
      }
    }

// OPENCL HOST CODE AREA END
    fin.close();
    fpr.close();
    fout.close();

    return EXIT_SUCCESS;
}