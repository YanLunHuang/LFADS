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
    std::cout<<"==========host_normal_4CU.cpp==========="<<std::endl;
    std::cout<<"4CU"<<std::endl;
    std::cout<<"Normal method"<<std::endl;
    std::cout<<"========================================"<<std::endl;
    int nevents = 1;
    cl_int err;
    std::string datadir = STRINGIFY(HLS4ML_DATA_DIR);
    std::string xclbinFilename = "";
    std::string print_or_not = "true";
    if (argc > 1) xclbinFilename = argv[1];
    if (argc > 2) nevents = atoi(argv[2]);
    if (argc > 3) print_or_not = argv[3];
    if (argc > 4) datadir = argv[4];
    std::cout << "Will run " << nevents << " time(s)" << std::endl;
    std::cout << "Choose to print out the prediction: " << print_or_not <<std::endl;
    std::cout << "Using " << datadir << " to get input features and output predictions (tb_input_features.dat and tb_output_predictions.dat)" << std::endl;



//=====================================================
//Find device & Load xclbin file & Program device
//=====================================================

    // OPENCL HOST CODE AREA START
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    cl::Kernel alveo_hls4ml_1,alveo_hls4ml_2,alveo_hls4ml_3,alveo_hls4ml_4;
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q1(context, device, CL_QUEUE_PROFILING_ENABLE);
    cl::CommandQueue q2(context, device, CL_QUEUE_PROFILING_ENABLE);
    cl::CommandQueue q3(context, device, CL_QUEUE_PROFILING_ENABLE);
    cl::CommandQueue q4(context, device, CL_QUEUE_PROFILING_ENABLE);
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
        alveo_hls4ml_3 = cl::Kernel(program,"alveo_hls4ml:{alveo_hls4ml_3}");
        alveo_hls4ml_4 = cl::Kernel(program,"alveo_hls4ml:{alveo_hls4ml_4}");
        valid_device = true;
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }


    size_t vector_size_in1_bytes = sizeof(group_in1) *STREAM_LEN_IN1*DATA_SET;
    size_t vector_size_in2_bytes = sizeof(group_in2) *STREAM_LEN_IN2*DATA_SET;
    size_t vector_size_out_bytes = sizeof(group_out) *STREAM_LEN_OUT*DATA_SET;
    // Allocate Memory in Host Memory
    // When creating a buffer with user pointer (CL_MEM_USE_HOST_PTR), under the hood user ptr 
    // is used if it is properly aligned. when not aligned, runtime had no choice but to create
    // its own host side buffer. So it is recommended to use this allocator if user wish to
    // create buffer using CL_MEM_USE_HOST_PTR to align user buffer to page boundary. It will 
    // ensure that user buffer is used when user create Buffer/Mem object with CL_MEM_USE_HOST_PTR 
    std::vector<group_in1,aligned_allocator<group_in1>> source_in1_1(STREAM_LEN_IN1*DATA_SET);
    std::vector<group_in2,aligned_allocator<group_in2>> source_in1_2(STREAM_LEN_IN2*DATA_SET);
    std::vector<group_out,aligned_allocator<group_out>> source_hw_results1(STREAM_LEN_OUT*DATA_SET);

    std::vector<group_in1,aligned_allocator<group_in1>> source_in2_1(STREAM_LEN_IN1*DATA_SET);
    std::vector<group_in2,aligned_allocator<group_in2>> source_in2_2(STREAM_LEN_IN2*DATA_SET);
    std::vector<group_out,aligned_allocator<group_out>> source_hw_results2(STREAM_LEN_OUT*DATA_SET);

    std::vector<group_in1,aligned_allocator<group_in1>> source_in3_1(STREAM_LEN_IN1*DATA_SET);
    std::vector<group_in2,aligned_allocator<group_in2>> source_in3_2(STREAM_LEN_IN2*DATA_SET);
    std::vector<group_out,aligned_allocator<group_out>> source_hw_results3(STREAM_LEN_OUT*DATA_SET);

    std::vector<group_in1,aligned_allocator<group_in1>> source_in4_1(STREAM_LEN_IN1*DATA_SET);
    std::vector<group_in2,aligned_allocator<group_in2>> source_in4_2(STREAM_LEN_IN2*DATA_SET);
    std::vector<group_out,aligned_allocator<group_out>> source_hw_results4(STREAM_LEN_OUT*DATA_SET);

    //Reset the input data
    for(int i0 = 0; i0 < STREAM_LEN_IN1*DATA_SET; i0++) {
        for(int i1 = 0; i1 < STREAM_SIZE_IN1; i1++) {
            source_in1_1[i0].layer[i1] = 0;
            source_in2_1[i0].layer[i1] = 0;
            source_in3_1[i0].layer[i1] = 0;
            source_in4_1[i0].layer[i1] = 0;
        }
    }
    for(int i0 = 0; i0 < STREAM_LEN_IN2*DATA_SET; i0++) {
        for(int i1 = 0; i1 < STREAM_SIZE_IN2; i1++) {
            source_in1_2[i0].layer[i1] = 0;
            source_in2_2[i0].layer[i1] = 0;
            source_in3_2[i0].layer[i1] = 0;
            source_in4_2[i0].layer[i1] = 0;
        }
    }
    //Reset the output result
    for(int i0 = 0 ; i0 < STREAM_LEN_OUT*DATA_SET; i0++){
        for(int i1 = 0 ; i1 < STREAM_SIZE_OUT; i1++){
            source_hw_results1[i0].layer[i1] = 0;
            source_hw_results2[i0].layer[i1] = 0;
            source_hw_results3[i0].layer[i1] = 0;
            source_hw_results4[i0].layer[i1] = 0;
        }
    }


//=====================
//Create buffer
//=====================

    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and 
    // Device-to-host communication
/////////////////////////////////////////////////////////////////////////////////////////
    cl::Buffer buffer_in1_1   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in1_bytes, source_in1_1.data());
    cl::Buffer buffer_in1_2   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in2_bytes, source_in1_2.data());
    cl::Buffer buffer_output1(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            vector_size_out_bytes, source_hw_results1.data());

    int narg1 = 0;
    alveo_hls4ml_1.setArg(narg1++, buffer_in1_1);
    alveo_hls4ml_1.setArg(narg1++, buffer_in1_2);
    alveo_hls4ml_1.setArg(narg1++, buffer_output1);
/////////////////////////////////////////////////////////////////////////////////////////

    cl::Buffer buffer_in2_1   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in1_bytes, source_in2_1.data());
    cl::Buffer buffer_in2_2   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in2_bytes, source_in2_2.data());
    cl::Buffer buffer_output2(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            vector_size_out_bytes, source_hw_results2.data());

    int narg2 = 0;
    alveo_hls4ml_2.setArg(narg2++, buffer_in2_1);
    alveo_hls4ml_2.setArg(narg2++, buffer_in2_2);
    alveo_hls4ml_2.setArg(narg2++, buffer_output2);

/////////////////////////////////////////////////////////////////////////////////////////

    cl::Buffer buffer_in3_1   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in1_bytes, source_in3_1.data());
    cl::Buffer buffer_in3_2   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in2_bytes, source_in3_2.data());
    cl::Buffer buffer_output3(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            vector_size_out_bytes, source_hw_results3.data());

    int narg3 = 0;
    alveo_hls4ml_3.setArg(narg3++, buffer_in3_1);
    alveo_hls4ml_3.setArg(narg3++, buffer_in3_2);
    alveo_hls4ml_3.setArg(narg3++, buffer_output3);

/////////////////////////////////////////////////////////////////////////////////////////

    cl::Buffer buffer_in4_1   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in1_bytes, source_in4_1.data());
    cl::Buffer buffer_in4_2   (context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_in2_bytes, source_in4_2.data());
    cl::Buffer buffer_output4(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            vector_size_out_bytes, source_hw_results4.data());

    int narg4 = 0;
    alveo_hls4ml_4.setArg(narg4++, buffer_in4_1);
    alveo_hls4ml_4.setArg(narg4++, buffer_in4_2);
    alveo_hls4ml_4.setArg(narg4++, buffer_output4);

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
        for(int i0 = 0; i0 < DATA_SET; i0++) {
			std::cout <<"send input 1 \n";
            for(int i1 = 0; i1 < STREAM_LEN_IN1; i1++) {
                for(int i2 = 0; i2 < STREAM_SIZE_IN1; i2++) {
                    source_in1_1[i0*STREAM_LEN_IN1+i1].layer[i2] = in[i1*STREAM_SIZE_IN1+i2];
                    source_in2_1[i0*STREAM_LEN_IN1+i1].layer[i2] = in[i1*STREAM_SIZE_IN1+i2];
                    source_in3_1[i0*STREAM_LEN_IN1+i1].layer[i2] = in[i1*STREAM_SIZE_IN1+i2];
                    source_in4_1[i0*STREAM_LEN_IN1+i1].layer[i2] = in[i1*STREAM_SIZE_IN1+i2];
                }
            }
			std::cout <<"send input 2 \n";
            for(int i1 = 0; i1 < STREAM_LEN_IN2; i1++) {
                for(int i2 = 0; i2 < STREAM_SIZE_IN2; i2++) {
                    source_in1_2[i0*STREAM_LEN_IN2+i1].layer[i2] = in[i1*STREAM_SIZE_IN2+i2];
                    source_in2_2[i0*STREAM_LEN_IN2+i1].layer[i2] = in[i1*STREAM_SIZE_IN2+i2];
                    source_in3_2[i0*STREAM_LEN_IN2+i1].layer[i2] = in[i1*STREAM_SIZE_IN2+i2];
                    source_in4_2[i0*STREAM_LEN_IN2+i1].layer[i2] = in[i1*STREAM_SIZE_IN2+i2];
                }
            }
        //Reset the output result
		std::cout <<"reset output \n";
            for(int i1 = 0 ; i1 < STREAM_LEN_OUT ; i1++){
                for(int i2 = 0 ; i2 < STREAM_SIZE_OUT ; i2++){
                    source_hw_results1[i0*STREAM_LEN_OUT+i1].layer[i2] = 0;
                    source_hw_results2[i0*STREAM_LEN_OUT+i1].layer[i2] = 0;
                    source_hw_results3[i0*STREAM_LEN_OUT+i1].layer[i2] = 0;
                    source_hw_results4[i0*STREAM_LEN_OUT+i1].layer[i2] = 0;
                }
            }
        }

//========================
//Start to run on FPGA
//========================
    auto t1 = Clock::now();
    auto t5 = Clock::now();
    uint64_t duration_total = 0;
    cl::Event Task1,Task2,Task3,Task4;
    std::cout << "start computation" << std::endl;
    for(int i=0; i<nevents; i++){
        t1 = Clock::now();

        q1.enqueueMigrateMemObjects({buffer_in1_1,buffer_in1_2},0/* 0 means from host*/);
        q1.enqueueTask(alveo_hls4ml_1,NULL,&Task1);
        q1.enqueueMigrateMemObjects({buffer_output1},CL_MIGRATE_MEM_OBJECT_HOST);

        q2.enqueueMigrateMemObjects({buffer_in2_1,buffer_in2_2},0/* 0 means from host*/);
        q2.enqueueTask(alveo_hls4ml_2,NULL,&Task2);
        q2.enqueueMigrateMemObjects({buffer_output2},CL_MIGRATE_MEM_OBJECT_HOST);

        q3.enqueueMigrateMemObjects({buffer_in3_1,buffer_in3_2},0/* 0 means from host*/);
        q3.enqueueTask(alveo_hls4ml_3,NULL,&Task3);
        q3.enqueueMigrateMemObjects({buffer_output3},CL_MIGRATE_MEM_OBJECT_HOST);

        q4.enqueueMigrateMemObjects({buffer_in4_1,buffer_in4_2},0/* 0 means from host*/);
        q4.enqueueTask(alveo_hls4ml_4,NULL,&Task4);
        q4.enqueueMigrateMemObjects({buffer_output4},CL_MIGRATE_MEM_OBJECT_HOST);

        q1.finish();
        q2.finish();
        q3.finish();
        q4.finish();
        t5 = Clock::now();
        if(i!=0)duration_total += std::chrono::duration_cast<std::chrono::nanoseconds>(t5 - t1).count();
        uint64_t execution1 = get_duration_ns(Task1); 
        uint64_t execution2 = get_duration_ns(Task2); 
        uint64_t execution3 = get_duration_ns(Task3); 
        uint64_t execution4 = get_duration_ns(Task4); 
        std::cout << "computation: " << i << std::endl;
        std::cout << "t5 - t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t5 - t1).count() << " ns" <<std::endl;
        std::cout << "execution1: " << execution1 << " ns" << std::endl;
        std::cout << "execution2: " << execution2 << " ns" << std::endl;
        std::cout << "execution3: " << execution3 << " ns" << std::endl;
        std::cout << "execution4: " << execution4 << " ns" << std::endl;
        std::cout << "duration_total: " << duration_total << " ns" << std::endl;
    }
        //print timing
        std::cout << "FPGA average time: " << duration_total/(nevents-1) << " ns" << std::endl;
        fout << "FPGA average time: " << duration_total/(nevents-1) << " ns \n";
//=====================
//Output result
//=====================
    if(print_or_not=="true"){
        std::cout<<"Predictions: \n";
        fout <<"Predictions:  \n";
        for(int i=0;i<DATA_SET;i++){
            for(int j=0;j<STREAM_LEN_OUT*STREAM_SIZE_OUT ;j++){
                //std::cout << pr[j] << " ";
                fout << pr[j] << " ";
            }
        }
        std::cout << std::endl;
        fout<<"\n";

        std::cout<<"Quantized predictions1: \n";
        fout <<"Quantized predictions1: \n";
        for(int i=0;i<STREAM_LEN_OUT*DATA_SET;i++){
            for(int j=0;j<STREAM_SIZE_OUT;j++){
                //std::cout << source_hw_results[i].layer[j] << " ";
                fout << source_hw_results1[i].layer[j] << " "; 
            }
        }
        std::cout << std::endl;
        fout << "\n\n";

        std::cout<<"Quantized predictions2: \n";
        fout <<"Quantized predictions2: \n";
        for(int i=0;i<STREAM_LEN_OUT*DATA_SET;i++){
            for(int j=0;j<STREAM_SIZE_OUT;j++){
                //std::cout << source_hw_results[i].layer[j] << " ";
                fout << source_hw_results2[i].layer[j] << " "; 
            }
        }
        std::cout << std::endl;
        fout << "\n\n";

        std::cout<<"Quantized predictions3: \n";
        fout <<"Quantized predictions3: \n";
        for(int i=0;i<STREAM_LEN_OUT*DATA_SET;i++){
            for(int j=0;j<STREAM_SIZE_OUT;j++){
                //std::cout << source_hw_results[i].layer[j] << " ";
                fout << source_hw_results3[i].layer[j] << " "; 
            }
        }
        std::cout << std::endl;
        fout << "\n\n";

        std::cout<<"Quantized predictions4: \n";
        fout <<"Quantized predictions4: \n";
        for(int i=0;i<STREAM_LEN_OUT*DATA_SET;i++){
            for(int j=0;j<STREAM_SIZE_OUT;j++){
                //std::cout << source_hw_results[i].layer[j] << " ";
                fout << source_hw_results4[i].layer[j] << " "; 
            }
        }
        std::cout << std::endl;
        fout << "\n\n";

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
