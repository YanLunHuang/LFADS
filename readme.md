# LFADs
## Target platform : Alveo U55C (NRP)
## Vitis version 2022.2
## Activate the tool 
```bash
source ~/setup_vitis_2022_2.sh 
```
## Compile project
```bash
make cleanall # clean all of the related files
make check TARGET=sw_emu DEVICE=xilinx_u55c_gen3x16_xdma_3_202210_1 all  # software emulation
make check TARGET=hw_emu DEVICE=xilinx_u55c_gen3x16_xdma_3_202210_1 all  # hardware emulation
make TARGET=hw DEVICE=xilinx_u55c_gen3x16_xdma_3_202210_1 all # build
```
## Run project
```bash
XCL_EMULATION_MODE=sw_emu ./host ./build_dir.sw_emu.xilinx_u55c_gen3x16_xdma_3_202210_1/alveo_hls4ml.xclbin  # software emulation
XCL_EMULATION_MODE=hw_emu ./host ./build_dir.hw_emu.xilinx_u55c_gen3x16_xdma_3_202210_1/alveo_hls4ml.xclbin  # hardware emulation
./host build_dir.hw.xilinx_u55c_gen3x16_xdma_3_202210_1/alveo_hls4ml.xclbin  # run on U50
```
## Some detail
```bash
Full LFADS model(with Gaussian sampling) 
The running frequency is 199 MHZ, and the target frequency is 199 MHZ.
Precision: 16 bits
For batch 1:
Total time: 0.451 ms
FPGA execution time: 0.37 ms
```
