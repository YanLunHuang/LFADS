// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_H__
#define __sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 10;
  static const unsigned AddressRange = 1024;
  static const unsigned AddressWidth = 10;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in <sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in <sc_lv<AddressWidth> > address2;
sc_core::sc_in <sc_logic> ce2;
sc_core::sc_out <sc_lv<DataWidth> > q2;
sc_core::sc_in <sc_lv<AddressWidth> > address3;
sc_core::sc_in <sc_logic> ce3;
sc_core::sc_out <sc_lv<DataWidth> > q3;
sc_core::sc_in <sc_lv<AddressWidth> > address4;
sc_core::sc_in <sc_logic> ce4;
sc_core::sc_out <sc_lv<DataWidth> > q4;
sc_core::sc_in <sc_lv<AddressWidth> > address5;
sc_core::sc_in <sc_logic> ce5;
sc_core::sc_out <sc_lv<DataWidth> > q5;
sc_core::sc_in <sc_lv<AddressWidth> > address6;
sc_core::sc_in <sc_logic> ce6;
sc_core::sc_out <sc_lv<DataWidth> > q6;
sc_core::sc_in <sc_lv<AddressWidth> > address7;
sc_core::sc_in <sc_logic> ce7;
sc_core::sc_out <sc_lv<DataWidth> > q7;
sc_core::sc_in <sc_lv<AddressWidth> > address8;
sc_core::sc_in <sc_logic> ce8;
sc_core::sc_out <sc_lv<DataWidth> > q8;
sc_core::sc_in <sc_lv<AddressWidth> > address9;
sc_core::sc_in <sc_logic> ce9;
sc_core::sc_out <sc_lv<DataWidth> > q9;
sc_core::sc_in <sc_lv<AddressWidth> > address10;
sc_core::sc_in <sc_logic> ce10;
sc_core::sc_out <sc_lv<DataWidth> > q10;
sc_core::sc_in <sc_lv<AddressWidth> > address11;
sc_core::sc_in <sc_logic> ce11;
sc_core::sc_out <sc_lv<DataWidth> > q11;
sc_core::sc_in <sc_lv<AddressWidth> > address12;
sc_core::sc_in <sc_logic> ce12;
sc_core::sc_out <sc_lv<DataWidth> > q12;
sc_core::sc_in <sc_lv<AddressWidth> > address13;
sc_core::sc_in <sc_logic> ce13;
sc_core::sc_out <sc_lv<DataWidth> > q13;
sc_core::sc_in <sc_lv<AddressWidth> > address14;
sc_core::sc_in <sc_logic> ce14;
sc_core::sc_out <sc_lv<DataWidth> > q14;
sc_core::sc_in <sc_lv<AddressWidth> > address15;
sc_core::sc_in <sc_logic> ce15;
sc_core::sc_out <sc_lv<DataWidth> > q15;
sc_core::sc_in <sc_lv<AddressWidth> > address16;
sc_core::sc_in <sc_logic> ce16;
sc_core::sc_out <sc_lv<DataWidth> > q16;
sc_core::sc_in <sc_lv<AddressWidth> > address17;
sc_core::sc_in <sc_logic> ce17;
sc_core::sc_out <sc_lv<DataWidth> > q17;
sc_core::sc_in <sc_lv<AddressWidth> > address18;
sc_core::sc_in <sc_logic> ce18;
sc_core::sc_out <sc_lv<DataWidth> > q18;
sc_core::sc_in <sc_lv<AddressWidth> > address19;
sc_core::sc_in <sc_logic> ce19;
sc_core::sc_out <sc_lv<DataWidth> > q19;
sc_core::sc_in <sc_lv<AddressWidth> > address20;
sc_core::sc_in <sc_logic> ce20;
sc_core::sc_out <sc_lv<DataWidth> > q20;
sc_core::sc_in <sc_lv<AddressWidth> > address21;
sc_core::sc_in <sc_logic> ce21;
sc_core::sc_out <sc_lv<DataWidth> > q21;
sc_core::sc_in <sc_lv<AddressWidth> > address22;
sc_core::sc_in <sc_logic> ce22;
sc_core::sc_out <sc_lv<DataWidth> > q22;
sc_core::sc_in <sc_lv<AddressWidth> > address23;
sc_core::sc_in <sc_logic> ce23;
sc_core::sc_out <sc_lv<DataWidth> > q23;
sc_core::sc_in <sc_lv<AddressWidth> > address24;
sc_core::sc_in <sc_logic> ce24;
sc_core::sc_out <sc_lv<DataWidth> > q24;
sc_core::sc_in <sc_lv<AddressWidth> > address25;
sc_core::sc_in <sc_logic> ce25;
sc_core::sc_out <sc_lv<DataWidth> > q25;
sc_core::sc_in <sc_lv<AddressWidth> > address26;
sc_core::sc_in <sc_logic> ce26;
sc_core::sc_out <sc_lv<DataWidth> > q26;
sc_core::sc_in <sc_lv<AddressWidth> > address27;
sc_core::sc_in <sc_logic> ce27;
sc_core::sc_out <sc_lv<DataWidth> > q27;
sc_core::sc_in <sc_lv<AddressWidth> > address28;
sc_core::sc_in <sc_logic> ce28;
sc_core::sc_out <sc_lv<DataWidth> > q28;
sc_core::sc_in <sc_lv<AddressWidth> > address29;
sc_core::sc_in <sc_logic> ce29;
sc_core::sc_out <sc_lv<DataWidth> > q29;
sc_core::sc_in <sc_lv<AddressWidth> > address30;
sc_core::sc_in <sc_logic> ce30;
sc_core::sc_out <sc_lv<DataWidth> > q30;
sc_core::sc_in <sc_lv<AddressWidth> > address31;
sc_core::sc_in <sc_logic> ce31;
sc_core::sc_out <sc_lv<DataWidth> > q31;
sc_core::sc_in <sc_lv<AddressWidth> > address32;
sc_core::sc_in <sc_logic> ce32;
sc_core::sc_out <sc_lv<DataWidth> > q32;
sc_core::sc_in <sc_lv<AddressWidth> > address33;
sc_core::sc_in <sc_logic> ce33;
sc_core::sc_out <sc_lv<DataWidth> > q33;
sc_core::sc_in <sc_lv<AddressWidth> > address34;
sc_core::sc_in <sc_logic> ce34;
sc_core::sc_out <sc_lv<DataWidth> > q34;
sc_core::sc_in <sc_lv<AddressWidth> > address35;
sc_core::sc_in <sc_logic> ce35;
sc_core::sc_out <sc_lv<DataWidth> > q35;
sc_core::sc_in <sc_lv<AddressWidth> > address36;
sc_core::sc_in <sc_logic> ce36;
sc_core::sc_out <sc_lv<DataWidth> > q36;
sc_core::sc_in <sc_lv<AddressWidth> > address37;
sc_core::sc_in <sc_logic> ce37;
sc_core::sc_out <sc_lv<DataWidth> > q37;
sc_core::sc_in <sc_lv<AddressWidth> > address38;
sc_core::sc_in <sc_logic> ce38;
sc_core::sc_out <sc_lv<DataWidth> > q38;
sc_core::sc_in <sc_lv<AddressWidth> > address39;
sc_core::sc_in <sc_logic> ce39;
sc_core::sc_out <sc_lv<DataWidth> > q39;
sc_core::sc_in <sc_lv<AddressWidth> > address40;
sc_core::sc_in <sc_logic> ce40;
sc_core::sc_out <sc_lv<DataWidth> > q40;
sc_core::sc_in <sc_lv<AddressWidth> > address41;
sc_core::sc_in <sc_logic> ce41;
sc_core::sc_out <sc_lv<DataWidth> > q41;
sc_core::sc_in <sc_lv<AddressWidth> > address42;
sc_core::sc_in <sc_logic> ce42;
sc_core::sc_out <sc_lv<DataWidth> > q42;
sc_core::sc_in <sc_lv<AddressWidth> > address43;
sc_core::sc_in <sc_logic> ce43;
sc_core::sc_out <sc_lv<DataWidth> > q43;
sc_core::sc_in <sc_lv<AddressWidth> > address44;
sc_core::sc_in <sc_logic> ce44;
sc_core::sc_out <sc_lv<DataWidth> > q44;
sc_core::sc_in <sc_lv<AddressWidth> > address45;
sc_core::sc_in <sc_logic> ce45;
sc_core::sc_out <sc_lv<DataWidth> > q45;
sc_core::sc_in <sc_lv<AddressWidth> > address46;
sc_core::sc_in <sc_logic> ce46;
sc_core::sc_out <sc_lv<DataWidth> > q46;
sc_core::sc_in <sc_lv<AddressWidth> > address47;
sc_core::sc_in <sc_logic> ce47;
sc_core::sc_out <sc_lv<DataWidth> > q47;
sc_core::sc_in <sc_lv<AddressWidth> > address48;
sc_core::sc_in <sc_logic> ce48;
sc_core::sc_out <sc_lv<DataWidth> > q48;
sc_core::sc_in <sc_lv<AddressWidth> > address49;
sc_core::sc_in <sc_logic> ce49;
sc_core::sc_out <sc_lv<DataWidth> > q49;
sc_core::sc_in <sc_lv<AddressWidth> > address50;
sc_core::sc_in <sc_logic> ce50;
sc_core::sc_out <sc_lv<DataWidth> > q50;
sc_core::sc_in <sc_lv<AddressWidth> > address51;
sc_core::sc_in <sc_logic> ce51;
sc_core::sc_out <sc_lv<DataWidth> > q51;
sc_core::sc_in <sc_lv<AddressWidth> > address52;
sc_core::sc_in <sc_logic> ce52;
sc_core::sc_out <sc_lv<DataWidth> > q52;
sc_core::sc_in <sc_lv<AddressWidth> > address53;
sc_core::sc_in <sc_logic> ce53;
sc_core::sc_out <sc_lv<DataWidth> > q53;
sc_core::sc_in <sc_lv<AddressWidth> > address54;
sc_core::sc_in <sc_logic> ce54;
sc_core::sc_out <sc_lv<DataWidth> > q54;
sc_core::sc_in <sc_lv<AddressWidth> > address55;
sc_core::sc_in <sc_logic> ce55;
sc_core::sc_out <sc_lv<DataWidth> > q55;
sc_core::sc_in <sc_lv<AddressWidth> > address56;
sc_core::sc_in <sc_logic> ce56;
sc_core::sc_out <sc_lv<DataWidth> > q56;
sc_core::sc_in <sc_lv<AddressWidth> > address57;
sc_core::sc_in <sc_logic> ce57;
sc_core::sc_out <sc_lv<DataWidth> > q57;
sc_core::sc_in <sc_lv<AddressWidth> > address58;
sc_core::sc_in <sc_logic> ce58;
sc_core::sc_out <sc_lv<DataWidth> > q58;
sc_core::sc_in <sc_lv<AddressWidth> > address59;
sc_core::sc_in <sc_logic> ce59;
sc_core::sc_out <sc_lv<DataWidth> > q59;
sc_core::sc_in <sc_lv<AddressWidth> > address60;
sc_core::sc_in <sc_logic> ce60;
sc_core::sc_out <sc_lv<DataWidth> > q60;
sc_core::sc_in <sc_lv<AddressWidth> > address61;
sc_core::sc_in <sc_logic> ce61;
sc_core::sc_out <sc_lv<DataWidth> > q61;
sc_core::sc_in <sc_lv<AddressWidth> > address62;
sc_core::sc_in <sc_logic> ce62;
sc_core::sc_out <sc_lv<DataWidth> > q62;
sc_core::sc_in <sc_lv<AddressWidth> > address63;
sc_core::sc_in <sc_logic> ce63;
sc_core::sc_out <sc_lv<DataWidth> > q63;
sc_core::sc_in <sc_lv<AddressWidth> > address64;
sc_core::sc_in <sc_logic> ce64;
sc_core::sc_out <sc_lv<DataWidth> > q64;
sc_core::sc_in <sc_lv<AddressWidth> > address65;
sc_core::sc_in <sc_logic> ce65;
sc_core::sc_out <sc_lv<DataWidth> > q65;
sc_core::sc_in <sc_lv<AddressWidth> > address66;
sc_core::sc_in <sc_logic> ce66;
sc_core::sc_out <sc_lv<DataWidth> > q66;
sc_core::sc_in <sc_lv<AddressWidth> > address67;
sc_core::sc_in <sc_logic> ce67;
sc_core::sc_out <sc_lv<DataWidth> > q67;
sc_core::sc_in <sc_lv<AddressWidth> > address68;
sc_core::sc_in <sc_logic> ce68;
sc_core::sc_out <sc_lv<DataWidth> > q68;
sc_core::sc_in <sc_lv<AddressWidth> > address69;
sc_core::sc_in <sc_logic> ce69;
sc_core::sc_out <sc_lv<DataWidth> > q69;
sc_core::sc_in <sc_lv<AddressWidth> > address70;
sc_core::sc_in <sc_logic> ce70;
sc_core::sc_out <sc_lv<DataWidth> > q70;
sc_core::sc_in <sc_lv<AddressWidth> > address71;
sc_core::sc_in <sc_logic> ce71;
sc_core::sc_out <sc_lv<DataWidth> > q71;
sc_core::sc_in <sc_lv<AddressWidth> > address72;
sc_core::sc_in <sc_logic> ce72;
sc_core::sc_out <sc_lv<DataWidth> > q72;
sc_core::sc_in <sc_lv<AddressWidth> > address73;
sc_core::sc_in <sc_logic> ce73;
sc_core::sc_out <sc_lv<DataWidth> > q73;
sc_core::sc_in <sc_lv<AddressWidth> > address74;
sc_core::sc_in <sc_logic> ce74;
sc_core::sc_out <sc_lv<DataWidth> > q74;
sc_core::sc_in <sc_lv<AddressWidth> > address75;
sc_core::sc_in <sc_logic> ce75;
sc_core::sc_out <sc_lv<DataWidth> > q75;
sc_core::sc_in <sc_lv<AddressWidth> > address76;
sc_core::sc_in <sc_logic> ce76;
sc_core::sc_out <sc_lv<DataWidth> > q76;
sc_core::sc_in <sc_lv<AddressWidth> > address77;
sc_core::sc_in <sc_logic> ce77;
sc_core::sc_out <sc_lv<DataWidth> > q77;
sc_core::sc_in <sc_lv<AddressWidth> > address78;
sc_core::sc_in <sc_logic> ce78;
sc_core::sc_out <sc_lv<DataWidth> > q78;
sc_core::sc_in <sc_lv<AddressWidth> > address79;
sc_core::sc_in <sc_logic> ce79;
sc_core::sc_out <sc_lv<DataWidth> > q79;
sc_core::sc_in <sc_lv<AddressWidth> > address80;
sc_core::sc_in <sc_logic> ce80;
sc_core::sc_out <sc_lv<DataWidth> > q80;
sc_core::sc_in <sc_lv<AddressWidth> > address81;
sc_core::sc_in <sc_logic> ce81;
sc_core::sc_out <sc_lv<DataWidth> > q81;
sc_core::sc_in <sc_lv<AddressWidth> > address82;
sc_core::sc_in <sc_logic> ce82;
sc_core::sc_out <sc_lv<DataWidth> > q82;
sc_core::sc_in <sc_lv<AddressWidth> > address83;
sc_core::sc_in <sc_logic> ce83;
sc_core::sc_out <sc_lv<DataWidth> > q83;
sc_core::sc_in <sc_lv<AddressWidth> > address84;
sc_core::sc_in <sc_logic> ce84;
sc_core::sc_out <sc_lv<DataWidth> > q84;
sc_core::sc_in <sc_lv<AddressWidth> > address85;
sc_core::sc_in <sc_logic> ce85;
sc_core::sc_out <sc_lv<DataWidth> > q85;
sc_core::sc_in <sc_lv<AddressWidth> > address86;
sc_core::sc_in <sc_logic> ce86;
sc_core::sc_out <sc_lv<DataWidth> > q86;
sc_core::sc_in <sc_lv<AddressWidth> > address87;
sc_core::sc_in <sc_logic> ce87;
sc_core::sc_out <sc_lv<DataWidth> > q87;
sc_core::sc_in <sc_lv<AddressWidth> > address88;
sc_core::sc_in <sc_logic> ce88;
sc_core::sc_out <sc_lv<DataWidth> > q88;
sc_core::sc_in <sc_lv<AddressWidth> > address89;
sc_core::sc_in <sc_logic> ce89;
sc_core::sc_out <sc_lv<DataWidth> > q89;
sc_core::sc_in <sc_lv<AddressWidth> > address90;
sc_core::sc_in <sc_logic> ce90;
sc_core::sc_out <sc_lv<DataWidth> > q90;
sc_core::sc_in <sc_lv<AddressWidth> > address91;
sc_core::sc_in <sc_logic> ce91;
sc_core::sc_out <sc_lv<DataWidth> > q91;
sc_core::sc_in <sc_lv<AddressWidth> > address92;
sc_core::sc_in <sc_logic> ce92;
sc_core::sc_out <sc_lv<DataWidth> > q92;
sc_core::sc_in <sc_lv<AddressWidth> > address93;
sc_core::sc_in <sc_logic> ce93;
sc_core::sc_out <sc_lv<DataWidth> > q93;
sc_core::sc_in <sc_lv<AddressWidth> > address94;
sc_core::sc_in <sc_logic> ce94;
sc_core::sc_out <sc_lv<DataWidth> > q94;
sc_core::sc_in <sc_lv<AddressWidth> > address95;
sc_core::sc_in <sc_logic> ce95;
sc_core::sc_out <sc_lv<DataWidth> > q95;
sc_core::sc_in <sc_lv<AddressWidth> > address96;
sc_core::sc_in <sc_logic> ce96;
sc_core::sc_out <sc_lv<DataWidth> > q96;
sc_core::sc_in <sc_lv<AddressWidth> > address97;
sc_core::sc_in <sc_logic> ce97;
sc_core::sc_out <sc_lv<DataWidth> > q97;
sc_core::sc_in <sc_lv<AddressWidth> > address98;
sc_core::sc_in <sc_logic> ce98;
sc_core::sc_out <sc_lv<DataWidth> > q98;
sc_core::sc_in <sc_lv<AddressWidth> > address99;
sc_core::sc_in <sc_logic> ce99;
sc_core::sc_out <sc_lv<DataWidth> > q99;
sc_core::sc_in <sc_lv<AddressWidth> > address100;
sc_core::sc_in <sc_logic> ce100;
sc_core::sc_out <sc_lv<DataWidth> > q100;
sc_core::sc_in <sc_lv<AddressWidth> > address101;
sc_core::sc_in <sc_logic> ce101;
sc_core::sc_out <sc_lv<DataWidth> > q101;
sc_core::sc_in <sc_lv<AddressWidth> > address102;
sc_core::sc_in <sc_logic> ce102;
sc_core::sc_out <sc_lv<DataWidth> > q102;
sc_core::sc_in <sc_lv<AddressWidth> > address103;
sc_core::sc_in <sc_logic> ce103;
sc_core::sc_out <sc_lv<DataWidth> > q103;
sc_core::sc_in <sc_lv<AddressWidth> > address104;
sc_core::sc_in <sc_logic> ce104;
sc_core::sc_out <sc_lv<DataWidth> > q104;
sc_core::sc_in <sc_lv<AddressWidth> > address105;
sc_core::sc_in <sc_logic> ce105;
sc_core::sc_out <sc_lv<DataWidth> > q105;
sc_core::sc_in <sc_lv<AddressWidth> > address106;
sc_core::sc_in <sc_logic> ce106;
sc_core::sc_out <sc_lv<DataWidth> > q106;
sc_core::sc_in <sc_lv<AddressWidth> > address107;
sc_core::sc_in <sc_logic> ce107;
sc_core::sc_out <sc_lv<DataWidth> > q107;
sc_core::sc_in <sc_lv<AddressWidth> > address108;
sc_core::sc_in <sc_logic> ce108;
sc_core::sc_out <sc_lv<DataWidth> > q108;
sc_core::sc_in <sc_lv<AddressWidth> > address109;
sc_core::sc_in <sc_logic> ce109;
sc_core::sc_out <sc_lv<DataWidth> > q109;
sc_core::sc_in <sc_lv<AddressWidth> > address110;
sc_core::sc_in <sc_logic> ce110;
sc_core::sc_out <sc_lv<DataWidth> > q110;
sc_core::sc_in <sc_lv<AddressWidth> > address111;
sc_core::sc_in <sc_logic> ce111;
sc_core::sc_out <sc_lv<DataWidth> > q111;
sc_core::sc_in <sc_lv<AddressWidth> > address112;
sc_core::sc_in <sc_logic> ce112;
sc_core::sc_out <sc_lv<DataWidth> > q112;
sc_core::sc_in <sc_lv<AddressWidth> > address113;
sc_core::sc_in <sc_logic> ce113;
sc_core::sc_out <sc_lv<DataWidth> > q113;
sc_core::sc_in <sc_lv<AddressWidth> > address114;
sc_core::sc_in <sc_logic> ce114;
sc_core::sc_out <sc_lv<DataWidth> > q114;
sc_core::sc_in <sc_lv<AddressWidth> > address115;
sc_core::sc_in <sc_logic> ce115;
sc_core::sc_out <sc_lv<DataWidth> > q115;
sc_core::sc_in <sc_lv<AddressWidth> > address116;
sc_core::sc_in <sc_logic> ce116;
sc_core::sc_out <sc_lv<DataWidth> > q116;
sc_core::sc_in <sc_lv<AddressWidth> > address117;
sc_core::sc_in <sc_logic> ce117;
sc_core::sc_out <sc_lv<DataWidth> > q117;
sc_core::sc_in <sc_lv<AddressWidth> > address118;
sc_core::sc_in <sc_logic> ce118;
sc_core::sc_out <sc_lv<DataWidth> > q118;
sc_core::sc_in <sc_lv<AddressWidth> > address119;
sc_core::sc_in <sc_logic> ce119;
sc_core::sc_out <sc_lv<DataWidth> > q119;
sc_core::sc_in <sc_lv<AddressWidth> > address120;
sc_core::sc_in <sc_logic> ce120;
sc_core::sc_out <sc_lv<DataWidth> > q120;
sc_core::sc_in <sc_lv<AddressWidth> > address121;
sc_core::sc_in <sc_logic> ce121;
sc_core::sc_out <sc_lv<DataWidth> > q121;
sc_core::sc_in <sc_lv<AddressWidth> > address122;
sc_core::sc_in <sc_logic> ce122;
sc_core::sc_out <sc_lv<DataWidth> > q122;
sc_core::sc_in <sc_lv<AddressWidth> > address123;
sc_core::sc_in <sc_logic> ce123;
sc_core::sc_out <sc_lv<DataWidth> > q123;
sc_core::sc_in <sc_lv<AddressWidth> > address124;
sc_core::sc_in <sc_logic> ce124;
sc_core::sc_out <sc_lv<DataWidth> > q124;
sc_core::sc_in <sc_lv<AddressWidth> > address125;
sc_core::sc_in <sc_logic> ce125;
sc_core::sc_out <sc_lv<DataWidth> > q125;
sc_core::sc_in <sc_lv<AddressWidth> > address126;
sc_core::sc_in <sc_logic> ce126;
sc_core::sc_out <sc_lv<DataWidth> > q126;
sc_core::sc_in <sc_lv<AddressWidth> > address127;
sc_core::sc_in <sc_logic> ce127;
sc_core::sc_out <sc_lv<DataWidth> > q127;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_ram) {
        for (unsigned i = 0; i < 69 ; i = i + 1) {
            ram[i] = "0b0000000000";
        }
        for (unsigned i = 69; i < 113 ; i = i + 1) {
            ram[i] = "0b0000000001";
        }
        for (unsigned i = 113; i < 139 ; i = i + 1) {
            ram[i] = "0b0000000010";
        }
        for (unsigned i = 139; i < 158 ; i = i + 1) {
            ram[i] = "0b0000000011";
        }
        for (unsigned i = 158; i < 172 ; i = i + 1) {
            ram[i] = "0b0000000100";
        }
        for (unsigned i = 172; i < 184 ; i = i + 1) {
            ram[i] = "0b0000000101";
        }
        for (unsigned i = 184; i < 194 ; i = i + 1) {
            ram[i] = "0b0000000110";
        }
        for (unsigned i = 194; i < 202 ; i = i + 1) {
            ram[i] = "0b0000000111";
        }
        for (unsigned i = 202; i < 210 ; i = i + 1) {
            ram[i] = "0b0000001000";
        }
        for (unsigned i = 210; i < 217 ; i = i + 1) {
            ram[i] = "0b0000001001";
        }
        for (unsigned i = 217; i < 223 ; i = i + 1) {
            ram[i] = "0b0000001010";
        }
        for (unsigned i = 223; i < 229 ; i = i + 1) {
            ram[i] = "0b0000001011";
        }
        for (unsigned i = 229; i < 234 ; i = i + 1) {
            ram[i] = "0b0000001100";
        }
        for (unsigned i = 234; i < 239 ; i = i + 1) {
            ram[i] = "0b0000001101";
        }
        ram[239] = "0b0000001110";
        ram[240] = "0b0000001110";
        ram[241] = "0b0000001110";
        ram[242] = "0b0000001110";
        ram[243] = "0b0000001111";
        ram[244] = "0b0000001111";
        ram[245] = "0b0000001111";
        ram[246] = "0b0000001111";
        ram[247] = "0b0000010000";
        ram[248] = "0b0000010000";
        ram[249] = "0b0000010000";
        ram[250] = "0b0000010000";
        ram[251] = "0b0000010001";
        ram[252] = "0b0000010001";
        ram[253] = "0b0000010001";
        ram[254] = "0b0000010001";
        ram[255] = "0b0000010010";
        ram[256] = "0b0000010010";
        ram[257] = "0b0000010010";
        ram[258] = "0b0000010010";
        ram[259] = "0b0000010011";
        ram[260] = "0b0000010011";
        ram[261] = "0b0000010011";
        ram[262] = "0b0000010100";
        ram[263] = "0b0000010100";
        ram[264] = "0b0000010100";
        ram[265] = "0b0000010101";
        ram[266] = "0b0000010101";
        ram[267] = "0b0000010101";
        ram[268] = "0b0000010110";
        ram[269] = "0b0000010110";
        ram[270] = "0b0000010110";
        ram[271] = "0b0000010111";
        ram[272] = "0b0000010111";
        ram[273] = "0b0000010111";
        ram[274] = "0b0000011000";
        ram[275] = "0b0000011000";
        ram[276] = "0b0000011001";
        ram[277] = "0b0000011001";
        ram[278] = "0b0000011001";
        ram[279] = "0b0000011010";
        ram[280] = "0b0000011010";
        ram[281] = "0b0000011010";
        ram[282] = "0b0000011011";
        ram[283] = "0b0000011011";
        ram[284] = "0b0000011100";
        ram[285] = "0b0000011100";
        ram[286] = "0b0000011101";
        ram[287] = "0b0000011101";
        ram[288] = "0b0000011110";
        ram[289] = "0b0000011110";
        ram[290] = "0b0000011110";
        ram[291] = "0b0000011111";
        ram[292] = "0b0000011111";
        ram[293] = "0b0000100000";
        ram[294] = "0b0000100000";
        ram[295] = "0b0000100001";
        ram[296] = "0b0000100001";
        ram[297] = "0b0000100010";
        ram[298] = "0b0000100010";
        ram[299] = "0b0000100011";
        ram[300] = "0b0000100011";
        ram[301] = "0b0000100100";
        ram[302] = "0b0000100101";
        ram[303] = "0b0000100101";
        ram[304] = "0b0000100110";
        ram[305] = "0b0000100110";
        ram[306] = "0b0000100111";
        ram[307] = "0b0000100111";
        ram[308] = "0b0000101000";
        ram[309] = "0b0000101001";
        ram[310] = "0b0000101001";
        ram[311] = "0b0000101010";
        ram[312] = "0b0000101011";
        ram[313] = "0b0000101011";
        ram[314] = "0b0000101100";
        ram[315] = "0b0000101101";
        ram[316] = "0b0000101101";
        ram[317] = "0b0000101110";
        ram[318] = "0b0000101111";
        ram[319] = "0b0000101111";
        ram[320] = "0b0000110000";
        ram[321] = "0b0000110001";
        ram[322] = "0b0000110010";
        ram[323] = "0b0000110010";
        ram[324] = "0b0000110011";
        ram[325] = "0b0000110100";
        ram[326] = "0b0000110101";
        ram[327] = "0b0000110101";
        ram[328] = "0b0000110110";
        ram[329] = "0b0000110111";
        ram[330] = "0b0000111000";
        ram[331] = "0b0000111001";
        ram[332] = "0b0000111010";
        ram[333] = "0b0000111010";
        ram[334] = "0b0000111011";
        ram[335] = "0b0000111100";
        ram[336] = "0b0000111101";
        ram[337] = "0b0000111110";
        ram[338] = "0b0000111111";
        ram[339] = "0b0001000000";
        ram[340] = "0b0001000001";
        ram[341] = "0b0001000010";
        ram[342] = "0b0001000011";
        ram[343] = "0b0001000100";
        ram[344] = "0b0001000101";
        ram[345] = "0b0001000110";
        ram[346] = "0b0001000111";
        ram[347] = "0b0001001000";
        ram[348] = "0b0001001001";
        ram[349] = "0b0001001010";
        ram[350] = "0b0001001011";
        ram[351] = "0b0001001100";
        ram[352] = "0b0001001101";
        ram[353] = "0b0001001110";
        ram[354] = "0b0001001111";
        ram[355] = "0b0001010001";
        ram[356] = "0b0001010010";
        ram[357] = "0b0001010011";
        ram[358] = "0b0001010100";
        ram[359] = "0b0001010101";
        ram[360] = "0b0001010111";
        ram[361] = "0b0001011000";
        ram[362] = "0b0001011001";
        ram[363] = "0b0001011010";
        ram[364] = "0b0001011100";
        ram[365] = "0b0001011101";
        ram[366] = "0b0001011110";
        ram[367] = "0b0001100000";
        ram[368] = "0b0001100001";
        ram[369] = "0b0001100011";
        ram[370] = "0b0001100100";
        ram[371] = "0b0001100101";
        ram[372] = "0b0001100111";
        ram[373] = "0b0001101000";
        ram[374] = "0b0001101010";
        ram[375] = "0b0001101011";
        ram[376] = "0b0001101101";
        ram[377] = "0b0001101110";
        ram[378] = "0b0001110000";
        ram[379] = "0b0001110001";
        ram[380] = "0b0001110011";
        ram[381] = "0b0001110101";
        ram[382] = "0b0001110110";
        ram[383] = "0b0001111000";
        ram[384] = "0b0001111010";
        ram[385] = "0b0001111011";
        ram[386] = "0b0001111101";
        ram[387] = "0b0001111111";
        ram[388] = "0b0010000000";
        ram[389] = "0b0010000010";
        ram[390] = "0b0010000100";
        ram[391] = "0b0010000110";
        ram[392] = "0b0010001000";
        ram[393] = "0b0010001010";
        ram[394] = "0b0010001011";
        ram[395] = "0b0010001101";
        ram[396] = "0b0010001111";
        ram[397] = "0b0010010001";
        ram[398] = "0b0010010011";
        ram[399] = "0b0010010101";
        ram[400] = "0b0010010111";
        ram[401] = "0b0010011001";
        ram[402] = "0b0010011011";
        ram[403] = "0b0010011101";
        ram[404] = "0b0010011111";
        ram[405] = "0b0010100001";
        ram[406] = "0b0010100100";
        ram[407] = "0b0010100110";
        ram[408] = "0b0010101000";
        ram[409] = "0b0010101010";
        ram[410] = "0b0010101100";
        ram[411] = "0b0010101111";
        ram[412] = "0b0010110001";
        ram[413] = "0b0010110011";
        ram[414] = "0b0010110110";
        ram[415] = "0b0010111000";
        ram[416] = "0b0010111010";
        ram[417] = "0b0010111101";
        ram[418] = "0b0010111111";
        ram[419] = "0b0011000010";
        ram[420] = "0b0011000100";
        ram[421] = "0b0011000111";
        ram[422] = "0b0011001001";
        ram[423] = "0b0011001100";
        ram[424] = "0b0011001110";
        ram[425] = "0b0011010001";
        ram[426] = "0b0011010011";
        ram[427] = "0b0011010110";
        ram[428] = "0b0011011001";
        ram[429] = "0b0011011011";
        ram[430] = "0b0011011110";
        ram[431] = "0b0011100001";
        ram[432] = "0b0011100100";
        ram[433] = "0b0011100110";
        ram[434] = "0b0011101001";
        ram[435] = "0b0011101100";
        ram[436] = "0b0011101111";
        ram[437] = "0b0011110010";
        ram[438] = "0b0011110101";
        ram[439] = "0b0011111000";
        ram[440] = "0b0011111010";
        ram[441] = "0b0011111101";
        ram[442] = "0b0100000000";
        ram[443] = "0b0100000011";
        ram[444] = "0b0100000110";
        ram[445] = "0b0100001010";
        ram[446] = "0b0100001101";
        ram[447] = "0b0100010000";
        ram[448] = "0b0100010011";
        ram[449] = "0b0100010110";
        ram[450] = "0b0100011001";
        ram[451] = "0b0100011100";
        ram[452] = "0b0100100000";
        ram[453] = "0b0100100011";
        ram[454] = "0b0100100110";
        ram[455] = "0b0100101001";
        ram[456] = "0b0100101101";
        ram[457] = "0b0100110000";
        ram[458] = "0b0100110011";
        ram[459] = "0b0100110111";
        ram[460] = "0b0100111010";
        ram[461] = "0b0100111110";
        ram[462] = "0b0101000001";
        ram[463] = "0b0101000101";
        ram[464] = "0b0101001000";
        ram[465] = "0b0101001100";
        ram[466] = "0b0101001111";
        ram[467] = "0b0101010011";
        ram[468] = "0b0101010110";
        ram[469] = "0b0101011010";
        ram[470] = "0b0101011101";
        ram[471] = "0b0101100001";
        ram[472] = "0b0101100101";
        ram[473] = "0b0101101000";
        ram[474] = "0b0101101100";
        ram[475] = "0b0101101111";
        ram[476] = "0b0101110011";
        ram[477] = "0b0101110111";
        ram[478] = "0b0101111011";
        ram[479] = "0b0101111110";
        ram[480] = "0b0110000010";
        ram[481] = "0b0110000110";
        ram[482] = "0b0110001010";
        ram[483] = "0b0110001101";
        ram[484] = "0b0110010001";
        ram[485] = "0b0110010101";
        ram[486] = "0b0110011001";
        ram[487] = "0b0110011101";
        ram[488] = "0b0110100001";
        ram[489] = "0b0110100100";
        ram[490] = "0b0110101000";
        ram[491] = "0b0110101100";
        ram[492] = "0b0110110000";
        ram[493] = "0b0110110100";
        ram[494] = "0b0110111000";
        ram[495] = "0b0110111100";
        ram[496] = "0b0111000000";
        ram[497] = "0b0111000100";
        ram[498] = "0b0111001000";
        ram[499] = "0b0111001100";
        ram[500] = "0b0111010000";
        ram[501] = "0b0111010100";
        ram[502] = "0b0111011000";
        ram[503] = "0b0111011100";
        ram[504] = "0b0111100000";
        ram[505] = "0b0111100100";
        ram[506] = "0b0111101000";
        ram[507] = "0b0111101100";
        ram[508] = "0b0111110000";
        ram[509] = "0b0111110100";
        ram[510] = "0b0111111000";
        ram[511] = "0b0111111100";
        ram[512] = "0b1000000000";
        ram[513] = "0b1000000011";
        ram[514] = "0b1000000111";
        ram[515] = "0b1000001011";
        ram[516] = "0b1000001111";
        ram[517] = "0b1000010011";
        ram[518] = "0b1000010111";
        ram[519] = "0b1000011011";
        ram[520] = "0b1000011111";
        ram[521] = "0b1000100011";
        ram[522] = "0b1000100111";
        ram[523] = "0b1000101011";
        ram[524] = "0b1000101111";
        ram[525] = "0b1000110011";
        ram[526] = "0b1000110111";
        ram[527] = "0b1000111011";
        ram[528] = "0b1000111111";
        ram[529] = "0b1001000011";
        ram[530] = "0b1001000111";
        ram[531] = "0b1001001011";
        ram[532] = "0b1001001111";
        ram[533] = "0b1001010011";
        ram[534] = "0b1001010111";
        ram[535] = "0b1001011011";
        ram[536] = "0b1001011110";
        ram[537] = "0b1001100010";
        ram[538] = "0b1001100110";
        ram[539] = "0b1001101010";
        ram[540] = "0b1001101110";
        ram[541] = "0b1001110010";
        ram[542] = "0b1001110101";
        ram[543] = "0b1001111001";
        ram[544] = "0b1001111101";
        ram[545] = "0b1010000001";
        ram[546] = "0b1010000100";
        ram[547] = "0b1010001000";
        ram[548] = "0b1010001100";
        ram[549] = "0b1010010000";
        ram[550] = "0b1010010011";
        ram[551] = "0b1010010111";
        ram[552] = "0b1010011010";
        ram[553] = "0b1010011110";
        ram[554] = "0b1010100010";
        ram[555] = "0b1010100101";
        ram[556] = "0b1010101001";
        ram[557] = "0b1010101100";
        ram[558] = "0b1010110000";
        ram[559] = "0b1010110011";
        ram[560] = "0b1010110111";
        ram[561] = "0b1010111010";
        ram[562] = "0b1010111110";
        ram[563] = "0b1011000001";
        ram[564] = "0b1011000101";
        ram[565] = "0b1011001000";
        ram[566] = "0b1011001100";
        ram[567] = "0b1011001111";
        ram[568] = "0b1011010010";
        ram[569] = "0b1011010110";
        ram[570] = "0b1011011001";
        ram[571] = "0b1011011100";
        ram[572] = "0b1011011111";
        ram[573] = "0b1011100011";
        ram[574] = "0b1011100110";
        ram[575] = "0b1011101001";
        ram[576] = "0b1011101100";
        ram[577] = "0b1011101111";
        ram[578] = "0b1011110010";
        ram[579] = "0b1011110101";
        ram[580] = "0b1011111001";
        ram[581] = "0b1011111100";
        ram[582] = "0b1011111111";
        ram[583] = "0b1100000010";
        ram[584] = "0b1100000101";
        ram[585] = "0b1100000111";
        ram[586] = "0b1100001010";
        ram[587] = "0b1100001101";
        ram[588] = "0b1100010000";
        ram[589] = "0b1100010011";
        ram[590] = "0b1100010110";
        ram[591] = "0b1100011001";
        ram[592] = "0b1100011011";
        ram[593] = "0b1100011110";
        ram[594] = "0b1100100001";
        ram[595] = "0b1100100100";
        ram[596] = "0b1100100110";
        ram[597] = "0b1100101001";
        ram[598] = "0b1100101100";
        ram[599] = "0b1100101110";
        ram[600] = "0b1100110001";
        ram[601] = "0b1100110011";
        ram[602] = "0b1100110110";
        ram[603] = "0b1100111000";
        ram[604] = "0b1100111011";
        ram[605] = "0b1100111101";
        ram[606] = "0b1101000000";
        ram[607] = "0b1101000010";
        ram[608] = "0b1101000101";
        ram[609] = "0b1101000111";
        ram[610] = "0b1101001001";
        ram[611] = "0b1101001100";
        ram[612] = "0b1101001110";
        ram[613] = "0b1101010000";
        ram[614] = "0b1101010011";
        ram[615] = "0b1101010101";
        ram[616] = "0b1101010111";
        ram[617] = "0b1101011001";
        ram[618] = "0b1101011011";
        ram[619] = "0b1101011110";
        ram[620] = "0b1101100000";
        ram[621] = "0b1101100010";
        ram[622] = "0b1101100100";
        ram[623] = "0b1101100110";
        ram[624] = "0b1101101000";
        ram[625] = "0b1101101010";
        ram[626] = "0b1101101100";
        ram[627] = "0b1101101110";
        ram[628] = "0b1101110000";
        ram[629] = "0b1101110010";
        ram[630] = "0b1101110100";
        ram[631] = "0b1101110101";
        ram[632] = "0b1101110111";
        ram[633] = "0b1101111001";
        ram[634] = "0b1101111011";
        ram[635] = "0b1101111101";
        ram[636] = "0b1101111111";
        ram[637] = "0b1110000000";
        ram[638] = "0b1110000010";
        ram[639] = "0b1110000100";
        ram[640] = "0b1110000101";
        ram[641] = "0b1110000111";
        ram[642] = "0b1110001001";
        ram[643] = "0b1110001010";
        ram[644] = "0b1110001100";
        ram[645] = "0b1110001110";
        ram[646] = "0b1110001111";
        ram[647] = "0b1110010001";
        ram[648] = "0b1110010010";
        ram[649] = "0b1110010100";
        ram[650] = "0b1110010101";
        ram[651] = "0b1110010111";
        ram[652] = "0b1110011000";
        ram[653] = "0b1110011010";
        ram[654] = "0b1110011011";
        ram[655] = "0b1110011100";
        ram[656] = "0b1110011110";
        ram[657] = "0b1110011111";
        ram[658] = "0b1110100001";
        ram[659] = "0b1110100010";
        ram[660] = "0b1110100011";
        ram[661] = "0b1110100101";
        ram[662] = "0b1110100110";
        ram[663] = "0b1110100111";
        ram[664] = "0b1110101000";
        ram[665] = "0b1110101010";
        ram[666] = "0b1110101011";
        ram[667] = "0b1110101100";
        ram[668] = "0b1110101101";
        ram[669] = "0b1110101110";
        ram[670] = "0b1110110000";
        ram[671] = "0b1110110001";
        ram[672] = "0b1110110010";
        ram[673] = "0b1110110011";
        ram[674] = "0b1110110100";
        ram[675] = "0b1110110101";
        ram[676] = "0b1110110110";
        ram[677] = "0b1110110111";
        ram[678] = "0b1110111000";
        ram[679] = "0b1110111001";
        ram[680] = "0b1110111010";
        ram[681] = "0b1110111011";
        ram[682] = "0b1110111100";
        ram[683] = "0b1110111101";
        ram[684] = "0b1110111110";
        ram[685] = "0b1110111111";
        ram[686] = "0b1111000000";
        ram[687] = "0b1111000001";
        ram[688] = "0b1111000010";
        ram[689] = "0b1111000011";
        ram[690] = "0b1111000100";
        ram[691] = "0b1111000101";
        ram[692] = "0b1111000101";
        ram[693] = "0b1111000110";
        ram[694] = "0b1111000111";
        ram[695] = "0b1111001000";
        ram[696] = "0b1111001001";
        ram[697] = "0b1111001010";
        ram[698] = "0b1111001010";
        ram[699] = "0b1111001011";
        ram[700] = "0b1111001100";
        ram[701] = "0b1111001101";
        ram[702] = "0b1111001101";
        ram[703] = "0b1111001110";
        ram[704] = "0b1111001111";
        ram[705] = "0b1111010000";
        ram[706] = "0b1111010000";
        ram[707] = "0b1111010001";
        ram[708] = "0b1111010010";
        ram[709] = "0b1111010010";
        ram[710] = "0b1111010011";
        ram[711] = "0b1111010100";
        ram[712] = "0b1111010100";
        ram[713] = "0b1111010101";
        ram[714] = "0b1111010110";
        ram[715] = "0b1111010110";
        ram[716] = "0b1111010111";
        ram[717] = "0b1111011000";
        ram[718] = "0b1111011000";
        ram[719] = "0b1111011001";
        ram[720] = "0b1111011001";
        ram[721] = "0b1111011010";
        ram[722] = "0b1111011010";
        ram[723] = "0b1111011011";
        ram[724] = "0b1111011100";
        ram[725] = "0b1111011100";
        ram[726] = "0b1111011101";
        ram[727] = "0b1111011101";
        ram[728] = "0b1111011110";
        ram[729] = "0b1111011110";
        ram[730] = "0b1111011111";
        ram[731] = "0b1111011111";
        ram[732] = "0b1111100000";
        ram[733] = "0b1111100000";
        ram[734] = "0b1111100001";
        ram[735] = "0b1111100001";
        ram[736] = "0b1111100001";
        ram[737] = "0b1111100010";
        ram[738] = "0b1111100010";
        ram[739] = "0b1111100011";
        ram[740] = "0b1111100011";
        ram[741] = "0b1111100100";
        ram[742] = "0b1111100100";
        ram[743] = "0b1111100101";
        ram[744] = "0b1111100101";
        ram[745] = "0b1111100101";
        ram[746] = "0b1111100110";
        ram[747] = "0b1111100110";
        ram[748] = "0b1111100110";
        ram[749] = "0b1111100111";
        ram[750] = "0b1111100111";
        ram[751] = "0b1111101000";
        ram[752] = "0b1111101000";
        ram[753] = "0b1111101000";
        ram[754] = "0b1111101001";
        ram[755] = "0b1111101001";
        ram[756] = "0b1111101001";
        ram[757] = "0b1111101010";
        ram[758] = "0b1111101010";
        ram[759] = "0b1111101010";
        ram[760] = "0b1111101011";
        ram[761] = "0b1111101011";
        ram[762] = "0b1111101011";
        ram[763] = "0b1111101100";
        ram[764] = "0b1111101100";
        ram[765] = "0b1111101100";
        ram[766] = "0b1111101101";
        ram[767] = "0b1111101101";
        ram[768] = "0b1111101101";
        ram[769] = "0b1111101101";
        ram[770] = "0b1111101110";
        ram[771] = "0b1111101110";
        ram[772] = "0b1111101110";
        ram[773] = "0b1111101110";
        ram[774] = "0b1111101111";
        ram[775] = "0b1111101111";
        ram[776] = "0b1111101111";
        ram[777] = "0b1111101111";
        ram[778] = "0b1111110000";
        ram[779] = "0b1111110000";
        ram[780] = "0b1111110000";
        ram[781] = "0b1111110000";
        ram[782] = "0b1111110001";
        ram[783] = "0b1111110001";
        ram[784] = "0b1111110001";
        ram[785] = "0b1111110001";
        for (unsigned i = 786; i < 791 ; i = i + 1) {
            ram[i] = "0b1111110010";
        }
        for (unsigned i = 791; i < 796 ; i = i + 1) {
            ram[i] = "0b1111110011";
        }
        for (unsigned i = 796; i < 802 ; i = i + 1) {
            ram[i] = "0b1111110100";
        }
        for (unsigned i = 802; i < 808 ; i = i + 1) {
            ram[i] = "0b1111110101";
        }
        for (unsigned i = 808; i < 815 ; i = i + 1) {
            ram[i] = "0b1111110110";
        }
        for (unsigned i = 815; i < 823 ; i = i + 1) {
            ram[i] = "0b1111110111";
        }
        for (unsigned i = 823; i < 831 ; i = i + 1) {
            ram[i] = "0b1111111000";
        }
        for (unsigned i = 831; i < 841 ; i = i + 1) {
            ram[i] = "0b1111111001";
        }
        for (unsigned i = 841; i < 853 ; i = i + 1) {
            ram[i] = "0b1111111010";
        }
        for (unsigned i = 853; i < 867 ; i = i + 1) {
            ram[i] = "0b1111111011";
        }
        for (unsigned i = 867; i < 886 ; i = i + 1) {
            ram[i] = "0b1111111100";
        }
        for (unsigned i = 886; i < 912 ; i = i + 1) {
            ram[i] = "0b1111111101";
        }
        for (unsigned i = 912; i < 956 ; i = i + 1) {
            ram[i] = "0b1111111110";
        }
        for (unsigned i = 956; i < 1024 ; i = i + 1) {
            ram[i] = "0b1111111111";
        }


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();


SC_METHOD(prc_write_1);
  sensitive<<clk.pos();


SC_METHOD(prc_write_2);
  sensitive<<clk.pos();


SC_METHOD(prc_write_3);
  sensitive<<clk.pos();


SC_METHOD(prc_write_4);
  sensitive<<clk.pos();


SC_METHOD(prc_write_5);
  sensitive<<clk.pos();


SC_METHOD(prc_write_6);
  sensitive<<clk.pos();


SC_METHOD(prc_write_7);
  sensitive<<clk.pos();


SC_METHOD(prc_write_8);
  sensitive<<clk.pos();


SC_METHOD(prc_write_9);
  sensitive<<clk.pos();


SC_METHOD(prc_write_10);
  sensitive<<clk.pos();


SC_METHOD(prc_write_11);
  sensitive<<clk.pos();


SC_METHOD(prc_write_12);
  sensitive<<clk.pos();


SC_METHOD(prc_write_13);
  sensitive<<clk.pos();


SC_METHOD(prc_write_14);
  sensitive<<clk.pos();


SC_METHOD(prc_write_15);
  sensitive<<clk.pos();


SC_METHOD(prc_write_16);
  sensitive<<clk.pos();


SC_METHOD(prc_write_17);
  sensitive<<clk.pos();


SC_METHOD(prc_write_18);
  sensitive<<clk.pos();


SC_METHOD(prc_write_19);
  sensitive<<clk.pos();


SC_METHOD(prc_write_20);
  sensitive<<clk.pos();


SC_METHOD(prc_write_21);
  sensitive<<clk.pos();


SC_METHOD(prc_write_22);
  sensitive<<clk.pos();


SC_METHOD(prc_write_23);
  sensitive<<clk.pos();


SC_METHOD(prc_write_24);
  sensitive<<clk.pos();


SC_METHOD(prc_write_25);
  sensitive<<clk.pos();


SC_METHOD(prc_write_26);
  sensitive<<clk.pos();


SC_METHOD(prc_write_27);
  sensitive<<clk.pos();


SC_METHOD(prc_write_28);
  sensitive<<clk.pos();


SC_METHOD(prc_write_29);
  sensitive<<clk.pos();


SC_METHOD(prc_write_30);
  sensitive<<clk.pos();


SC_METHOD(prc_write_31);
  sensitive<<clk.pos();


SC_METHOD(prc_write_32);
  sensitive<<clk.pos();


SC_METHOD(prc_write_33);
  sensitive<<clk.pos();


SC_METHOD(prc_write_34);
  sensitive<<clk.pos();


SC_METHOD(prc_write_35);
  sensitive<<clk.pos();


SC_METHOD(prc_write_36);
  sensitive<<clk.pos();


SC_METHOD(prc_write_37);
  sensitive<<clk.pos();


SC_METHOD(prc_write_38);
  sensitive<<clk.pos();


SC_METHOD(prc_write_39);
  sensitive<<clk.pos();


SC_METHOD(prc_write_40);
  sensitive<<clk.pos();


SC_METHOD(prc_write_41);
  sensitive<<clk.pos();


SC_METHOD(prc_write_42);
  sensitive<<clk.pos();


SC_METHOD(prc_write_43);
  sensitive<<clk.pos();


SC_METHOD(prc_write_44);
  sensitive<<clk.pos();


SC_METHOD(prc_write_45);
  sensitive<<clk.pos();


SC_METHOD(prc_write_46);
  sensitive<<clk.pos();


SC_METHOD(prc_write_47);
  sensitive<<clk.pos();


SC_METHOD(prc_write_48);
  sensitive<<clk.pos();


SC_METHOD(prc_write_49);
  sensitive<<clk.pos();


SC_METHOD(prc_write_50);
  sensitive<<clk.pos();


SC_METHOD(prc_write_51);
  sensitive<<clk.pos();


SC_METHOD(prc_write_52);
  sensitive<<clk.pos();


SC_METHOD(prc_write_53);
  sensitive<<clk.pos();


SC_METHOD(prc_write_54);
  sensitive<<clk.pos();


SC_METHOD(prc_write_55);
  sensitive<<clk.pos();


SC_METHOD(prc_write_56);
  sensitive<<clk.pos();


SC_METHOD(prc_write_57);
  sensitive<<clk.pos();


SC_METHOD(prc_write_58);
  sensitive<<clk.pos();


SC_METHOD(prc_write_59);
  sensitive<<clk.pos();


SC_METHOD(prc_write_60);
  sensitive<<clk.pos();


SC_METHOD(prc_write_61);
  sensitive<<clk.pos();


SC_METHOD(prc_write_62);
  sensitive<<clk.pos();


SC_METHOD(prc_write_63);
  sensitive<<clk.pos();


SC_METHOD(prc_write_64);
  sensitive<<clk.pos();


SC_METHOD(prc_write_65);
  sensitive<<clk.pos();


SC_METHOD(prc_write_66);
  sensitive<<clk.pos();


SC_METHOD(prc_write_67);
  sensitive<<clk.pos();


SC_METHOD(prc_write_68);
  sensitive<<clk.pos();


SC_METHOD(prc_write_69);
  sensitive<<clk.pos();


SC_METHOD(prc_write_70);
  sensitive<<clk.pos();


SC_METHOD(prc_write_71);
  sensitive<<clk.pos();


SC_METHOD(prc_write_72);
  sensitive<<clk.pos();


SC_METHOD(prc_write_73);
  sensitive<<clk.pos();


SC_METHOD(prc_write_74);
  sensitive<<clk.pos();


SC_METHOD(prc_write_75);
  sensitive<<clk.pos();


SC_METHOD(prc_write_76);
  sensitive<<clk.pos();


SC_METHOD(prc_write_77);
  sensitive<<clk.pos();


SC_METHOD(prc_write_78);
  sensitive<<clk.pos();


SC_METHOD(prc_write_79);
  sensitive<<clk.pos();


SC_METHOD(prc_write_80);
  sensitive<<clk.pos();


SC_METHOD(prc_write_81);
  sensitive<<clk.pos();


SC_METHOD(prc_write_82);
  sensitive<<clk.pos();


SC_METHOD(prc_write_83);
  sensitive<<clk.pos();


SC_METHOD(prc_write_84);
  sensitive<<clk.pos();


SC_METHOD(prc_write_85);
  sensitive<<clk.pos();


SC_METHOD(prc_write_86);
  sensitive<<clk.pos();


SC_METHOD(prc_write_87);
  sensitive<<clk.pos();


SC_METHOD(prc_write_88);
  sensitive<<clk.pos();


SC_METHOD(prc_write_89);
  sensitive<<clk.pos();


SC_METHOD(prc_write_90);
  sensitive<<clk.pos();


SC_METHOD(prc_write_91);
  sensitive<<clk.pos();


SC_METHOD(prc_write_92);
  sensitive<<clk.pos();


SC_METHOD(prc_write_93);
  sensitive<<clk.pos();


SC_METHOD(prc_write_94);
  sensitive<<clk.pos();


SC_METHOD(prc_write_95);
  sensitive<<clk.pos();


SC_METHOD(prc_write_96);
  sensitive<<clk.pos();


SC_METHOD(prc_write_97);
  sensitive<<clk.pos();


SC_METHOD(prc_write_98);
  sensitive<<clk.pos();


SC_METHOD(prc_write_99);
  sensitive<<clk.pos();


SC_METHOD(prc_write_100);
  sensitive<<clk.pos();


SC_METHOD(prc_write_101);
  sensitive<<clk.pos();


SC_METHOD(prc_write_102);
  sensitive<<clk.pos();


SC_METHOD(prc_write_103);
  sensitive<<clk.pos();


SC_METHOD(prc_write_104);
  sensitive<<clk.pos();


SC_METHOD(prc_write_105);
  sensitive<<clk.pos();


SC_METHOD(prc_write_106);
  sensitive<<clk.pos();


SC_METHOD(prc_write_107);
  sensitive<<clk.pos();


SC_METHOD(prc_write_108);
  sensitive<<clk.pos();


SC_METHOD(prc_write_109);
  sensitive<<clk.pos();


SC_METHOD(prc_write_110);
  sensitive<<clk.pos();


SC_METHOD(prc_write_111);
  sensitive<<clk.pos();


SC_METHOD(prc_write_112);
  sensitive<<clk.pos();


SC_METHOD(prc_write_113);
  sensitive<<clk.pos();


SC_METHOD(prc_write_114);
  sensitive<<clk.pos();


SC_METHOD(prc_write_115);
  sensitive<<clk.pos();


SC_METHOD(prc_write_116);
  sensitive<<clk.pos();


SC_METHOD(prc_write_117);
  sensitive<<clk.pos();


SC_METHOD(prc_write_118);
  sensitive<<clk.pos();


SC_METHOD(prc_write_119);
  sensitive<<clk.pos();


SC_METHOD(prc_write_120);
  sensitive<<clk.pos();


SC_METHOD(prc_write_121);
  sensitive<<clk.pos();


SC_METHOD(prc_write_122);
  sensitive<<clk.pos();


SC_METHOD(prc_write_123);
  sensitive<<clk.pos();


SC_METHOD(prc_write_124);
  sensitive<<clk.pos();


SC_METHOD(prc_write_125);
  sensitive<<clk.pos();


SC_METHOD(prc_write_126);
  sensitive<<clk.pos();


SC_METHOD(prc_write_127);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


void prc_write_1()
{
    if (ce1.read() == sc_dt::Log_1) 
    {
            if(address1.read().is_01() && address1.read().to_uint()<AddressRange)
              q1 = ram[address1.read().to_uint()];
            else
              q1 = sc_lv<DataWidth>();
    }
}


void prc_write_2()
{
    if (ce2.read() == sc_dt::Log_1) 
    {
            if(address2.read().is_01() && address2.read().to_uint()<AddressRange)
              q2 = ram[address2.read().to_uint()];
            else
              q2 = sc_lv<DataWidth>();
    }
}


void prc_write_3()
{
    if (ce3.read() == sc_dt::Log_1) 
    {
            if(address3.read().is_01() && address3.read().to_uint()<AddressRange)
              q3 = ram[address3.read().to_uint()];
            else
              q3 = sc_lv<DataWidth>();
    }
}


void prc_write_4()
{
    if (ce4.read() == sc_dt::Log_1) 
    {
            if(address4.read().is_01() && address4.read().to_uint()<AddressRange)
              q4 = ram[address4.read().to_uint()];
            else
              q4 = sc_lv<DataWidth>();
    }
}


void prc_write_5()
{
    if (ce5.read() == sc_dt::Log_1) 
    {
            if(address5.read().is_01() && address5.read().to_uint()<AddressRange)
              q5 = ram[address5.read().to_uint()];
            else
              q5 = sc_lv<DataWidth>();
    }
}


void prc_write_6()
{
    if (ce6.read() == sc_dt::Log_1) 
    {
            if(address6.read().is_01() && address6.read().to_uint()<AddressRange)
              q6 = ram[address6.read().to_uint()];
            else
              q6 = sc_lv<DataWidth>();
    }
}


void prc_write_7()
{
    if (ce7.read() == sc_dt::Log_1) 
    {
            if(address7.read().is_01() && address7.read().to_uint()<AddressRange)
              q7 = ram[address7.read().to_uint()];
            else
              q7 = sc_lv<DataWidth>();
    }
}


void prc_write_8()
{
    if (ce8.read() == sc_dt::Log_1) 
    {
            if(address8.read().is_01() && address8.read().to_uint()<AddressRange)
              q8 = ram[address8.read().to_uint()];
            else
              q8 = sc_lv<DataWidth>();
    }
}


void prc_write_9()
{
    if (ce9.read() == sc_dt::Log_1) 
    {
            if(address9.read().is_01() && address9.read().to_uint()<AddressRange)
              q9 = ram[address9.read().to_uint()];
            else
              q9 = sc_lv<DataWidth>();
    }
}


void prc_write_10()
{
    if (ce10.read() == sc_dt::Log_1) 
    {
            if(address10.read().is_01() && address10.read().to_uint()<AddressRange)
              q10 = ram[address10.read().to_uint()];
            else
              q10 = sc_lv<DataWidth>();
    }
}


void prc_write_11()
{
    if (ce11.read() == sc_dt::Log_1) 
    {
            if(address11.read().is_01() && address11.read().to_uint()<AddressRange)
              q11 = ram[address11.read().to_uint()];
            else
              q11 = sc_lv<DataWidth>();
    }
}


void prc_write_12()
{
    if (ce12.read() == sc_dt::Log_1) 
    {
            if(address12.read().is_01() && address12.read().to_uint()<AddressRange)
              q12 = ram[address12.read().to_uint()];
            else
              q12 = sc_lv<DataWidth>();
    }
}


void prc_write_13()
{
    if (ce13.read() == sc_dt::Log_1) 
    {
            if(address13.read().is_01() && address13.read().to_uint()<AddressRange)
              q13 = ram[address13.read().to_uint()];
            else
              q13 = sc_lv<DataWidth>();
    }
}


void prc_write_14()
{
    if (ce14.read() == sc_dt::Log_1) 
    {
            if(address14.read().is_01() && address14.read().to_uint()<AddressRange)
              q14 = ram[address14.read().to_uint()];
            else
              q14 = sc_lv<DataWidth>();
    }
}


void prc_write_15()
{
    if (ce15.read() == sc_dt::Log_1) 
    {
            if(address15.read().is_01() && address15.read().to_uint()<AddressRange)
              q15 = ram[address15.read().to_uint()];
            else
              q15 = sc_lv<DataWidth>();
    }
}


void prc_write_16()
{
    if (ce16.read() == sc_dt::Log_1) 
    {
            if(address16.read().is_01() && address16.read().to_uint()<AddressRange)
              q16 = ram[address16.read().to_uint()];
            else
              q16 = sc_lv<DataWidth>();
    }
}


void prc_write_17()
{
    if (ce17.read() == sc_dt::Log_1) 
    {
            if(address17.read().is_01() && address17.read().to_uint()<AddressRange)
              q17 = ram[address17.read().to_uint()];
            else
              q17 = sc_lv<DataWidth>();
    }
}


void prc_write_18()
{
    if (ce18.read() == sc_dt::Log_1) 
    {
            if(address18.read().is_01() && address18.read().to_uint()<AddressRange)
              q18 = ram[address18.read().to_uint()];
            else
              q18 = sc_lv<DataWidth>();
    }
}


void prc_write_19()
{
    if (ce19.read() == sc_dt::Log_1) 
    {
            if(address19.read().is_01() && address19.read().to_uint()<AddressRange)
              q19 = ram[address19.read().to_uint()];
            else
              q19 = sc_lv<DataWidth>();
    }
}


void prc_write_20()
{
    if (ce20.read() == sc_dt::Log_1) 
    {
            if(address20.read().is_01() && address20.read().to_uint()<AddressRange)
              q20 = ram[address20.read().to_uint()];
            else
              q20 = sc_lv<DataWidth>();
    }
}


void prc_write_21()
{
    if (ce21.read() == sc_dt::Log_1) 
    {
            if(address21.read().is_01() && address21.read().to_uint()<AddressRange)
              q21 = ram[address21.read().to_uint()];
            else
              q21 = sc_lv<DataWidth>();
    }
}


void prc_write_22()
{
    if (ce22.read() == sc_dt::Log_1) 
    {
            if(address22.read().is_01() && address22.read().to_uint()<AddressRange)
              q22 = ram[address22.read().to_uint()];
            else
              q22 = sc_lv<DataWidth>();
    }
}


void prc_write_23()
{
    if (ce23.read() == sc_dt::Log_1) 
    {
            if(address23.read().is_01() && address23.read().to_uint()<AddressRange)
              q23 = ram[address23.read().to_uint()];
            else
              q23 = sc_lv<DataWidth>();
    }
}


void prc_write_24()
{
    if (ce24.read() == sc_dt::Log_1) 
    {
            if(address24.read().is_01() && address24.read().to_uint()<AddressRange)
              q24 = ram[address24.read().to_uint()];
            else
              q24 = sc_lv<DataWidth>();
    }
}


void prc_write_25()
{
    if (ce25.read() == sc_dt::Log_1) 
    {
            if(address25.read().is_01() && address25.read().to_uint()<AddressRange)
              q25 = ram[address25.read().to_uint()];
            else
              q25 = sc_lv<DataWidth>();
    }
}


void prc_write_26()
{
    if (ce26.read() == sc_dt::Log_1) 
    {
            if(address26.read().is_01() && address26.read().to_uint()<AddressRange)
              q26 = ram[address26.read().to_uint()];
            else
              q26 = sc_lv<DataWidth>();
    }
}


void prc_write_27()
{
    if (ce27.read() == sc_dt::Log_1) 
    {
            if(address27.read().is_01() && address27.read().to_uint()<AddressRange)
              q27 = ram[address27.read().to_uint()];
            else
              q27 = sc_lv<DataWidth>();
    }
}


void prc_write_28()
{
    if (ce28.read() == sc_dt::Log_1) 
    {
            if(address28.read().is_01() && address28.read().to_uint()<AddressRange)
              q28 = ram[address28.read().to_uint()];
            else
              q28 = sc_lv<DataWidth>();
    }
}


void prc_write_29()
{
    if (ce29.read() == sc_dt::Log_1) 
    {
            if(address29.read().is_01() && address29.read().to_uint()<AddressRange)
              q29 = ram[address29.read().to_uint()];
            else
              q29 = sc_lv<DataWidth>();
    }
}


void prc_write_30()
{
    if (ce30.read() == sc_dt::Log_1) 
    {
            if(address30.read().is_01() && address30.read().to_uint()<AddressRange)
              q30 = ram[address30.read().to_uint()];
            else
              q30 = sc_lv<DataWidth>();
    }
}


void prc_write_31()
{
    if (ce31.read() == sc_dt::Log_1) 
    {
            if(address31.read().is_01() && address31.read().to_uint()<AddressRange)
              q31 = ram[address31.read().to_uint()];
            else
              q31 = sc_lv<DataWidth>();
    }
}


void prc_write_32()
{
    if (ce32.read() == sc_dt::Log_1) 
    {
            if(address32.read().is_01() && address32.read().to_uint()<AddressRange)
              q32 = ram[address32.read().to_uint()];
            else
              q32 = sc_lv<DataWidth>();
    }
}


void prc_write_33()
{
    if (ce33.read() == sc_dt::Log_1) 
    {
            if(address33.read().is_01() && address33.read().to_uint()<AddressRange)
              q33 = ram[address33.read().to_uint()];
            else
              q33 = sc_lv<DataWidth>();
    }
}


void prc_write_34()
{
    if (ce34.read() == sc_dt::Log_1) 
    {
            if(address34.read().is_01() && address34.read().to_uint()<AddressRange)
              q34 = ram[address34.read().to_uint()];
            else
              q34 = sc_lv<DataWidth>();
    }
}


void prc_write_35()
{
    if (ce35.read() == sc_dt::Log_1) 
    {
            if(address35.read().is_01() && address35.read().to_uint()<AddressRange)
              q35 = ram[address35.read().to_uint()];
            else
              q35 = sc_lv<DataWidth>();
    }
}


void prc_write_36()
{
    if (ce36.read() == sc_dt::Log_1) 
    {
            if(address36.read().is_01() && address36.read().to_uint()<AddressRange)
              q36 = ram[address36.read().to_uint()];
            else
              q36 = sc_lv<DataWidth>();
    }
}


void prc_write_37()
{
    if (ce37.read() == sc_dt::Log_1) 
    {
            if(address37.read().is_01() && address37.read().to_uint()<AddressRange)
              q37 = ram[address37.read().to_uint()];
            else
              q37 = sc_lv<DataWidth>();
    }
}


void prc_write_38()
{
    if (ce38.read() == sc_dt::Log_1) 
    {
            if(address38.read().is_01() && address38.read().to_uint()<AddressRange)
              q38 = ram[address38.read().to_uint()];
            else
              q38 = sc_lv<DataWidth>();
    }
}


void prc_write_39()
{
    if (ce39.read() == sc_dt::Log_1) 
    {
            if(address39.read().is_01() && address39.read().to_uint()<AddressRange)
              q39 = ram[address39.read().to_uint()];
            else
              q39 = sc_lv<DataWidth>();
    }
}


void prc_write_40()
{
    if (ce40.read() == sc_dt::Log_1) 
    {
            if(address40.read().is_01() && address40.read().to_uint()<AddressRange)
              q40 = ram[address40.read().to_uint()];
            else
              q40 = sc_lv<DataWidth>();
    }
}


void prc_write_41()
{
    if (ce41.read() == sc_dt::Log_1) 
    {
            if(address41.read().is_01() && address41.read().to_uint()<AddressRange)
              q41 = ram[address41.read().to_uint()];
            else
              q41 = sc_lv<DataWidth>();
    }
}


void prc_write_42()
{
    if (ce42.read() == sc_dt::Log_1) 
    {
            if(address42.read().is_01() && address42.read().to_uint()<AddressRange)
              q42 = ram[address42.read().to_uint()];
            else
              q42 = sc_lv<DataWidth>();
    }
}


void prc_write_43()
{
    if (ce43.read() == sc_dt::Log_1) 
    {
            if(address43.read().is_01() && address43.read().to_uint()<AddressRange)
              q43 = ram[address43.read().to_uint()];
            else
              q43 = sc_lv<DataWidth>();
    }
}


void prc_write_44()
{
    if (ce44.read() == sc_dt::Log_1) 
    {
            if(address44.read().is_01() && address44.read().to_uint()<AddressRange)
              q44 = ram[address44.read().to_uint()];
            else
              q44 = sc_lv<DataWidth>();
    }
}


void prc_write_45()
{
    if (ce45.read() == sc_dt::Log_1) 
    {
            if(address45.read().is_01() && address45.read().to_uint()<AddressRange)
              q45 = ram[address45.read().to_uint()];
            else
              q45 = sc_lv<DataWidth>();
    }
}


void prc_write_46()
{
    if (ce46.read() == sc_dt::Log_1) 
    {
            if(address46.read().is_01() && address46.read().to_uint()<AddressRange)
              q46 = ram[address46.read().to_uint()];
            else
              q46 = sc_lv<DataWidth>();
    }
}


void prc_write_47()
{
    if (ce47.read() == sc_dt::Log_1) 
    {
            if(address47.read().is_01() && address47.read().to_uint()<AddressRange)
              q47 = ram[address47.read().to_uint()];
            else
              q47 = sc_lv<DataWidth>();
    }
}


void prc_write_48()
{
    if (ce48.read() == sc_dt::Log_1) 
    {
            if(address48.read().is_01() && address48.read().to_uint()<AddressRange)
              q48 = ram[address48.read().to_uint()];
            else
              q48 = sc_lv<DataWidth>();
    }
}


void prc_write_49()
{
    if (ce49.read() == sc_dt::Log_1) 
    {
            if(address49.read().is_01() && address49.read().to_uint()<AddressRange)
              q49 = ram[address49.read().to_uint()];
            else
              q49 = sc_lv<DataWidth>();
    }
}


void prc_write_50()
{
    if (ce50.read() == sc_dt::Log_1) 
    {
            if(address50.read().is_01() && address50.read().to_uint()<AddressRange)
              q50 = ram[address50.read().to_uint()];
            else
              q50 = sc_lv<DataWidth>();
    }
}


void prc_write_51()
{
    if (ce51.read() == sc_dt::Log_1) 
    {
            if(address51.read().is_01() && address51.read().to_uint()<AddressRange)
              q51 = ram[address51.read().to_uint()];
            else
              q51 = sc_lv<DataWidth>();
    }
}


void prc_write_52()
{
    if (ce52.read() == sc_dt::Log_1) 
    {
            if(address52.read().is_01() && address52.read().to_uint()<AddressRange)
              q52 = ram[address52.read().to_uint()];
            else
              q52 = sc_lv<DataWidth>();
    }
}


void prc_write_53()
{
    if (ce53.read() == sc_dt::Log_1) 
    {
            if(address53.read().is_01() && address53.read().to_uint()<AddressRange)
              q53 = ram[address53.read().to_uint()];
            else
              q53 = sc_lv<DataWidth>();
    }
}


void prc_write_54()
{
    if (ce54.read() == sc_dt::Log_1) 
    {
            if(address54.read().is_01() && address54.read().to_uint()<AddressRange)
              q54 = ram[address54.read().to_uint()];
            else
              q54 = sc_lv<DataWidth>();
    }
}


void prc_write_55()
{
    if (ce55.read() == sc_dt::Log_1) 
    {
            if(address55.read().is_01() && address55.read().to_uint()<AddressRange)
              q55 = ram[address55.read().to_uint()];
            else
              q55 = sc_lv<DataWidth>();
    }
}


void prc_write_56()
{
    if (ce56.read() == sc_dt::Log_1) 
    {
            if(address56.read().is_01() && address56.read().to_uint()<AddressRange)
              q56 = ram[address56.read().to_uint()];
            else
              q56 = sc_lv<DataWidth>();
    }
}


void prc_write_57()
{
    if (ce57.read() == sc_dt::Log_1) 
    {
            if(address57.read().is_01() && address57.read().to_uint()<AddressRange)
              q57 = ram[address57.read().to_uint()];
            else
              q57 = sc_lv<DataWidth>();
    }
}


void prc_write_58()
{
    if (ce58.read() == sc_dt::Log_1) 
    {
            if(address58.read().is_01() && address58.read().to_uint()<AddressRange)
              q58 = ram[address58.read().to_uint()];
            else
              q58 = sc_lv<DataWidth>();
    }
}


void prc_write_59()
{
    if (ce59.read() == sc_dt::Log_1) 
    {
            if(address59.read().is_01() && address59.read().to_uint()<AddressRange)
              q59 = ram[address59.read().to_uint()];
            else
              q59 = sc_lv<DataWidth>();
    }
}


void prc_write_60()
{
    if (ce60.read() == sc_dt::Log_1) 
    {
            if(address60.read().is_01() && address60.read().to_uint()<AddressRange)
              q60 = ram[address60.read().to_uint()];
            else
              q60 = sc_lv<DataWidth>();
    }
}


void prc_write_61()
{
    if (ce61.read() == sc_dt::Log_1) 
    {
            if(address61.read().is_01() && address61.read().to_uint()<AddressRange)
              q61 = ram[address61.read().to_uint()];
            else
              q61 = sc_lv<DataWidth>();
    }
}


void prc_write_62()
{
    if (ce62.read() == sc_dt::Log_1) 
    {
            if(address62.read().is_01() && address62.read().to_uint()<AddressRange)
              q62 = ram[address62.read().to_uint()];
            else
              q62 = sc_lv<DataWidth>();
    }
}


void prc_write_63()
{
    if (ce63.read() == sc_dt::Log_1) 
    {
            if(address63.read().is_01() && address63.read().to_uint()<AddressRange)
              q63 = ram[address63.read().to_uint()];
            else
              q63 = sc_lv<DataWidth>();
    }
}


void prc_write_64()
{
    if (ce64.read() == sc_dt::Log_1) 
    {
            if(address64.read().is_01() && address64.read().to_uint()<AddressRange)
              q64 = ram[address64.read().to_uint()];
            else
              q64 = sc_lv<DataWidth>();
    }
}


void prc_write_65()
{
    if (ce65.read() == sc_dt::Log_1) 
    {
            if(address65.read().is_01() && address65.read().to_uint()<AddressRange)
              q65 = ram[address65.read().to_uint()];
            else
              q65 = sc_lv<DataWidth>();
    }
}


void prc_write_66()
{
    if (ce66.read() == sc_dt::Log_1) 
    {
            if(address66.read().is_01() && address66.read().to_uint()<AddressRange)
              q66 = ram[address66.read().to_uint()];
            else
              q66 = sc_lv<DataWidth>();
    }
}


void prc_write_67()
{
    if (ce67.read() == sc_dt::Log_1) 
    {
            if(address67.read().is_01() && address67.read().to_uint()<AddressRange)
              q67 = ram[address67.read().to_uint()];
            else
              q67 = sc_lv<DataWidth>();
    }
}


void prc_write_68()
{
    if (ce68.read() == sc_dt::Log_1) 
    {
            if(address68.read().is_01() && address68.read().to_uint()<AddressRange)
              q68 = ram[address68.read().to_uint()];
            else
              q68 = sc_lv<DataWidth>();
    }
}


void prc_write_69()
{
    if (ce69.read() == sc_dt::Log_1) 
    {
            if(address69.read().is_01() && address69.read().to_uint()<AddressRange)
              q69 = ram[address69.read().to_uint()];
            else
              q69 = sc_lv<DataWidth>();
    }
}


void prc_write_70()
{
    if (ce70.read() == sc_dt::Log_1) 
    {
            if(address70.read().is_01() && address70.read().to_uint()<AddressRange)
              q70 = ram[address70.read().to_uint()];
            else
              q70 = sc_lv<DataWidth>();
    }
}


void prc_write_71()
{
    if (ce71.read() == sc_dt::Log_1) 
    {
            if(address71.read().is_01() && address71.read().to_uint()<AddressRange)
              q71 = ram[address71.read().to_uint()];
            else
              q71 = sc_lv<DataWidth>();
    }
}


void prc_write_72()
{
    if (ce72.read() == sc_dt::Log_1) 
    {
            if(address72.read().is_01() && address72.read().to_uint()<AddressRange)
              q72 = ram[address72.read().to_uint()];
            else
              q72 = sc_lv<DataWidth>();
    }
}


void prc_write_73()
{
    if (ce73.read() == sc_dt::Log_1) 
    {
            if(address73.read().is_01() && address73.read().to_uint()<AddressRange)
              q73 = ram[address73.read().to_uint()];
            else
              q73 = sc_lv<DataWidth>();
    }
}


void prc_write_74()
{
    if (ce74.read() == sc_dt::Log_1) 
    {
            if(address74.read().is_01() && address74.read().to_uint()<AddressRange)
              q74 = ram[address74.read().to_uint()];
            else
              q74 = sc_lv<DataWidth>();
    }
}


void prc_write_75()
{
    if (ce75.read() == sc_dt::Log_1) 
    {
            if(address75.read().is_01() && address75.read().to_uint()<AddressRange)
              q75 = ram[address75.read().to_uint()];
            else
              q75 = sc_lv<DataWidth>();
    }
}


void prc_write_76()
{
    if (ce76.read() == sc_dt::Log_1) 
    {
            if(address76.read().is_01() && address76.read().to_uint()<AddressRange)
              q76 = ram[address76.read().to_uint()];
            else
              q76 = sc_lv<DataWidth>();
    }
}


void prc_write_77()
{
    if (ce77.read() == sc_dt::Log_1) 
    {
            if(address77.read().is_01() && address77.read().to_uint()<AddressRange)
              q77 = ram[address77.read().to_uint()];
            else
              q77 = sc_lv<DataWidth>();
    }
}


void prc_write_78()
{
    if (ce78.read() == sc_dt::Log_1) 
    {
            if(address78.read().is_01() && address78.read().to_uint()<AddressRange)
              q78 = ram[address78.read().to_uint()];
            else
              q78 = sc_lv<DataWidth>();
    }
}


void prc_write_79()
{
    if (ce79.read() == sc_dt::Log_1) 
    {
            if(address79.read().is_01() && address79.read().to_uint()<AddressRange)
              q79 = ram[address79.read().to_uint()];
            else
              q79 = sc_lv<DataWidth>();
    }
}


void prc_write_80()
{
    if (ce80.read() == sc_dt::Log_1) 
    {
            if(address80.read().is_01() && address80.read().to_uint()<AddressRange)
              q80 = ram[address80.read().to_uint()];
            else
              q80 = sc_lv<DataWidth>();
    }
}


void prc_write_81()
{
    if (ce81.read() == sc_dt::Log_1) 
    {
            if(address81.read().is_01() && address81.read().to_uint()<AddressRange)
              q81 = ram[address81.read().to_uint()];
            else
              q81 = sc_lv<DataWidth>();
    }
}


void prc_write_82()
{
    if (ce82.read() == sc_dt::Log_1) 
    {
            if(address82.read().is_01() && address82.read().to_uint()<AddressRange)
              q82 = ram[address82.read().to_uint()];
            else
              q82 = sc_lv<DataWidth>();
    }
}


void prc_write_83()
{
    if (ce83.read() == sc_dt::Log_1) 
    {
            if(address83.read().is_01() && address83.read().to_uint()<AddressRange)
              q83 = ram[address83.read().to_uint()];
            else
              q83 = sc_lv<DataWidth>();
    }
}


void prc_write_84()
{
    if (ce84.read() == sc_dt::Log_1) 
    {
            if(address84.read().is_01() && address84.read().to_uint()<AddressRange)
              q84 = ram[address84.read().to_uint()];
            else
              q84 = sc_lv<DataWidth>();
    }
}


void prc_write_85()
{
    if (ce85.read() == sc_dt::Log_1) 
    {
            if(address85.read().is_01() && address85.read().to_uint()<AddressRange)
              q85 = ram[address85.read().to_uint()];
            else
              q85 = sc_lv<DataWidth>();
    }
}


void prc_write_86()
{
    if (ce86.read() == sc_dt::Log_1) 
    {
            if(address86.read().is_01() && address86.read().to_uint()<AddressRange)
              q86 = ram[address86.read().to_uint()];
            else
              q86 = sc_lv<DataWidth>();
    }
}


void prc_write_87()
{
    if (ce87.read() == sc_dt::Log_1) 
    {
            if(address87.read().is_01() && address87.read().to_uint()<AddressRange)
              q87 = ram[address87.read().to_uint()];
            else
              q87 = sc_lv<DataWidth>();
    }
}


void prc_write_88()
{
    if (ce88.read() == sc_dt::Log_1) 
    {
            if(address88.read().is_01() && address88.read().to_uint()<AddressRange)
              q88 = ram[address88.read().to_uint()];
            else
              q88 = sc_lv<DataWidth>();
    }
}


void prc_write_89()
{
    if (ce89.read() == sc_dt::Log_1) 
    {
            if(address89.read().is_01() && address89.read().to_uint()<AddressRange)
              q89 = ram[address89.read().to_uint()];
            else
              q89 = sc_lv<DataWidth>();
    }
}


void prc_write_90()
{
    if (ce90.read() == sc_dt::Log_1) 
    {
            if(address90.read().is_01() && address90.read().to_uint()<AddressRange)
              q90 = ram[address90.read().to_uint()];
            else
              q90 = sc_lv<DataWidth>();
    }
}


void prc_write_91()
{
    if (ce91.read() == sc_dt::Log_1) 
    {
            if(address91.read().is_01() && address91.read().to_uint()<AddressRange)
              q91 = ram[address91.read().to_uint()];
            else
              q91 = sc_lv<DataWidth>();
    }
}


void prc_write_92()
{
    if (ce92.read() == sc_dt::Log_1) 
    {
            if(address92.read().is_01() && address92.read().to_uint()<AddressRange)
              q92 = ram[address92.read().to_uint()];
            else
              q92 = sc_lv<DataWidth>();
    }
}


void prc_write_93()
{
    if (ce93.read() == sc_dt::Log_1) 
    {
            if(address93.read().is_01() && address93.read().to_uint()<AddressRange)
              q93 = ram[address93.read().to_uint()];
            else
              q93 = sc_lv<DataWidth>();
    }
}


void prc_write_94()
{
    if (ce94.read() == sc_dt::Log_1) 
    {
            if(address94.read().is_01() && address94.read().to_uint()<AddressRange)
              q94 = ram[address94.read().to_uint()];
            else
              q94 = sc_lv<DataWidth>();
    }
}


void prc_write_95()
{
    if (ce95.read() == sc_dt::Log_1) 
    {
            if(address95.read().is_01() && address95.read().to_uint()<AddressRange)
              q95 = ram[address95.read().to_uint()];
            else
              q95 = sc_lv<DataWidth>();
    }
}


void prc_write_96()
{
    if (ce96.read() == sc_dt::Log_1) 
    {
            if(address96.read().is_01() && address96.read().to_uint()<AddressRange)
              q96 = ram[address96.read().to_uint()];
            else
              q96 = sc_lv<DataWidth>();
    }
}


void prc_write_97()
{
    if (ce97.read() == sc_dt::Log_1) 
    {
            if(address97.read().is_01() && address97.read().to_uint()<AddressRange)
              q97 = ram[address97.read().to_uint()];
            else
              q97 = sc_lv<DataWidth>();
    }
}


void prc_write_98()
{
    if (ce98.read() == sc_dt::Log_1) 
    {
            if(address98.read().is_01() && address98.read().to_uint()<AddressRange)
              q98 = ram[address98.read().to_uint()];
            else
              q98 = sc_lv<DataWidth>();
    }
}


void prc_write_99()
{
    if (ce99.read() == sc_dt::Log_1) 
    {
            if(address99.read().is_01() && address99.read().to_uint()<AddressRange)
              q99 = ram[address99.read().to_uint()];
            else
              q99 = sc_lv<DataWidth>();
    }
}


void prc_write_100()
{
    if (ce100.read() == sc_dt::Log_1) 
    {
            if(address100.read().is_01() && address100.read().to_uint()<AddressRange)
              q100 = ram[address100.read().to_uint()];
            else
              q100 = sc_lv<DataWidth>();
    }
}


void prc_write_101()
{
    if (ce101.read() == sc_dt::Log_1) 
    {
            if(address101.read().is_01() && address101.read().to_uint()<AddressRange)
              q101 = ram[address101.read().to_uint()];
            else
              q101 = sc_lv<DataWidth>();
    }
}


void prc_write_102()
{
    if (ce102.read() == sc_dt::Log_1) 
    {
            if(address102.read().is_01() && address102.read().to_uint()<AddressRange)
              q102 = ram[address102.read().to_uint()];
            else
              q102 = sc_lv<DataWidth>();
    }
}


void prc_write_103()
{
    if (ce103.read() == sc_dt::Log_1) 
    {
            if(address103.read().is_01() && address103.read().to_uint()<AddressRange)
              q103 = ram[address103.read().to_uint()];
            else
              q103 = sc_lv<DataWidth>();
    }
}


void prc_write_104()
{
    if (ce104.read() == sc_dt::Log_1) 
    {
            if(address104.read().is_01() && address104.read().to_uint()<AddressRange)
              q104 = ram[address104.read().to_uint()];
            else
              q104 = sc_lv<DataWidth>();
    }
}


void prc_write_105()
{
    if (ce105.read() == sc_dt::Log_1) 
    {
            if(address105.read().is_01() && address105.read().to_uint()<AddressRange)
              q105 = ram[address105.read().to_uint()];
            else
              q105 = sc_lv<DataWidth>();
    }
}


void prc_write_106()
{
    if (ce106.read() == sc_dt::Log_1) 
    {
            if(address106.read().is_01() && address106.read().to_uint()<AddressRange)
              q106 = ram[address106.read().to_uint()];
            else
              q106 = sc_lv<DataWidth>();
    }
}


void prc_write_107()
{
    if (ce107.read() == sc_dt::Log_1) 
    {
            if(address107.read().is_01() && address107.read().to_uint()<AddressRange)
              q107 = ram[address107.read().to_uint()];
            else
              q107 = sc_lv<DataWidth>();
    }
}


void prc_write_108()
{
    if (ce108.read() == sc_dt::Log_1) 
    {
            if(address108.read().is_01() && address108.read().to_uint()<AddressRange)
              q108 = ram[address108.read().to_uint()];
            else
              q108 = sc_lv<DataWidth>();
    }
}


void prc_write_109()
{
    if (ce109.read() == sc_dt::Log_1) 
    {
            if(address109.read().is_01() && address109.read().to_uint()<AddressRange)
              q109 = ram[address109.read().to_uint()];
            else
              q109 = sc_lv<DataWidth>();
    }
}


void prc_write_110()
{
    if (ce110.read() == sc_dt::Log_1) 
    {
            if(address110.read().is_01() && address110.read().to_uint()<AddressRange)
              q110 = ram[address110.read().to_uint()];
            else
              q110 = sc_lv<DataWidth>();
    }
}


void prc_write_111()
{
    if (ce111.read() == sc_dt::Log_1) 
    {
            if(address111.read().is_01() && address111.read().to_uint()<AddressRange)
              q111 = ram[address111.read().to_uint()];
            else
              q111 = sc_lv<DataWidth>();
    }
}


void prc_write_112()
{
    if (ce112.read() == sc_dt::Log_1) 
    {
            if(address112.read().is_01() && address112.read().to_uint()<AddressRange)
              q112 = ram[address112.read().to_uint()];
            else
              q112 = sc_lv<DataWidth>();
    }
}


void prc_write_113()
{
    if (ce113.read() == sc_dt::Log_1) 
    {
            if(address113.read().is_01() && address113.read().to_uint()<AddressRange)
              q113 = ram[address113.read().to_uint()];
            else
              q113 = sc_lv<DataWidth>();
    }
}


void prc_write_114()
{
    if (ce114.read() == sc_dt::Log_1) 
    {
            if(address114.read().is_01() && address114.read().to_uint()<AddressRange)
              q114 = ram[address114.read().to_uint()];
            else
              q114 = sc_lv<DataWidth>();
    }
}


void prc_write_115()
{
    if (ce115.read() == sc_dt::Log_1) 
    {
            if(address115.read().is_01() && address115.read().to_uint()<AddressRange)
              q115 = ram[address115.read().to_uint()];
            else
              q115 = sc_lv<DataWidth>();
    }
}


void prc_write_116()
{
    if (ce116.read() == sc_dt::Log_1) 
    {
            if(address116.read().is_01() && address116.read().to_uint()<AddressRange)
              q116 = ram[address116.read().to_uint()];
            else
              q116 = sc_lv<DataWidth>();
    }
}


void prc_write_117()
{
    if (ce117.read() == sc_dt::Log_1) 
    {
            if(address117.read().is_01() && address117.read().to_uint()<AddressRange)
              q117 = ram[address117.read().to_uint()];
            else
              q117 = sc_lv<DataWidth>();
    }
}


void prc_write_118()
{
    if (ce118.read() == sc_dt::Log_1) 
    {
            if(address118.read().is_01() && address118.read().to_uint()<AddressRange)
              q118 = ram[address118.read().to_uint()];
            else
              q118 = sc_lv<DataWidth>();
    }
}


void prc_write_119()
{
    if (ce119.read() == sc_dt::Log_1) 
    {
            if(address119.read().is_01() && address119.read().to_uint()<AddressRange)
              q119 = ram[address119.read().to_uint()];
            else
              q119 = sc_lv<DataWidth>();
    }
}


void prc_write_120()
{
    if (ce120.read() == sc_dt::Log_1) 
    {
            if(address120.read().is_01() && address120.read().to_uint()<AddressRange)
              q120 = ram[address120.read().to_uint()];
            else
              q120 = sc_lv<DataWidth>();
    }
}


void prc_write_121()
{
    if (ce121.read() == sc_dt::Log_1) 
    {
            if(address121.read().is_01() && address121.read().to_uint()<AddressRange)
              q121 = ram[address121.read().to_uint()];
            else
              q121 = sc_lv<DataWidth>();
    }
}


void prc_write_122()
{
    if (ce122.read() == sc_dt::Log_1) 
    {
            if(address122.read().is_01() && address122.read().to_uint()<AddressRange)
              q122 = ram[address122.read().to_uint()];
            else
              q122 = sc_lv<DataWidth>();
    }
}


void prc_write_123()
{
    if (ce123.read() == sc_dt::Log_1) 
    {
            if(address123.read().is_01() && address123.read().to_uint()<AddressRange)
              q123 = ram[address123.read().to_uint()];
            else
              q123 = sc_lv<DataWidth>();
    }
}


void prc_write_124()
{
    if (ce124.read() == sc_dt::Log_1) 
    {
            if(address124.read().is_01() && address124.read().to_uint()<AddressRange)
              q124 = ram[address124.read().to_uint()];
            else
              q124 = sc_lv<DataWidth>();
    }
}


void prc_write_125()
{
    if (ce125.read() == sc_dt::Log_1) 
    {
            if(address125.read().is_01() && address125.read().to_uint()<AddressRange)
              q125 = ram[address125.read().to_uint()];
            else
              q125 = sc_lv<DataWidth>();
    }
}


void prc_write_126()
{
    if (ce126.read() == sc_dt::Log_1) 
    {
            if(address126.read().is_01() && address126.read().to_uint()<AddressRange)
              q126 = ram[address126.read().to_uint()];
            else
              q126 = sc_lv<DataWidth>();
    }
}


void prc_write_127()
{
    if (ce127.read() == sc_dt::Log_1) 
    {
            if(address127.read().is_01() && address127.read().to_uint()<AddressRange)
              q127 = ram[address127.read().to_uint()];
            else
              q127 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb) {


static const unsigned DataWidth = 10;
static const unsigned AddressRange = 1024;
static const unsigned AddressWidth = 10;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in <sc_lv<AddressWidth> > address1;
sc_core::sc_in<sc_logic> ce1;
sc_core::sc_out <sc_lv<DataWidth> > q1;
sc_core::sc_in <sc_lv<AddressWidth> > address2;
sc_core::sc_in<sc_logic> ce2;
sc_core::sc_out <sc_lv<DataWidth> > q2;
sc_core::sc_in <sc_lv<AddressWidth> > address3;
sc_core::sc_in<sc_logic> ce3;
sc_core::sc_out <sc_lv<DataWidth> > q3;
sc_core::sc_in <sc_lv<AddressWidth> > address4;
sc_core::sc_in<sc_logic> ce4;
sc_core::sc_out <sc_lv<DataWidth> > q4;
sc_core::sc_in <sc_lv<AddressWidth> > address5;
sc_core::sc_in<sc_logic> ce5;
sc_core::sc_out <sc_lv<DataWidth> > q5;
sc_core::sc_in <sc_lv<AddressWidth> > address6;
sc_core::sc_in<sc_logic> ce6;
sc_core::sc_out <sc_lv<DataWidth> > q6;
sc_core::sc_in <sc_lv<AddressWidth> > address7;
sc_core::sc_in<sc_logic> ce7;
sc_core::sc_out <sc_lv<DataWidth> > q7;
sc_core::sc_in <sc_lv<AddressWidth> > address8;
sc_core::sc_in<sc_logic> ce8;
sc_core::sc_out <sc_lv<DataWidth> > q8;
sc_core::sc_in <sc_lv<AddressWidth> > address9;
sc_core::sc_in<sc_logic> ce9;
sc_core::sc_out <sc_lv<DataWidth> > q9;
sc_core::sc_in <sc_lv<AddressWidth> > address10;
sc_core::sc_in<sc_logic> ce10;
sc_core::sc_out <sc_lv<DataWidth> > q10;
sc_core::sc_in <sc_lv<AddressWidth> > address11;
sc_core::sc_in<sc_logic> ce11;
sc_core::sc_out <sc_lv<DataWidth> > q11;
sc_core::sc_in <sc_lv<AddressWidth> > address12;
sc_core::sc_in<sc_logic> ce12;
sc_core::sc_out <sc_lv<DataWidth> > q12;
sc_core::sc_in <sc_lv<AddressWidth> > address13;
sc_core::sc_in<sc_logic> ce13;
sc_core::sc_out <sc_lv<DataWidth> > q13;
sc_core::sc_in <sc_lv<AddressWidth> > address14;
sc_core::sc_in<sc_logic> ce14;
sc_core::sc_out <sc_lv<DataWidth> > q14;
sc_core::sc_in <sc_lv<AddressWidth> > address15;
sc_core::sc_in<sc_logic> ce15;
sc_core::sc_out <sc_lv<DataWidth> > q15;
sc_core::sc_in <sc_lv<AddressWidth> > address16;
sc_core::sc_in<sc_logic> ce16;
sc_core::sc_out <sc_lv<DataWidth> > q16;
sc_core::sc_in <sc_lv<AddressWidth> > address17;
sc_core::sc_in<sc_logic> ce17;
sc_core::sc_out <sc_lv<DataWidth> > q17;
sc_core::sc_in <sc_lv<AddressWidth> > address18;
sc_core::sc_in<sc_logic> ce18;
sc_core::sc_out <sc_lv<DataWidth> > q18;
sc_core::sc_in <sc_lv<AddressWidth> > address19;
sc_core::sc_in<sc_logic> ce19;
sc_core::sc_out <sc_lv<DataWidth> > q19;
sc_core::sc_in <sc_lv<AddressWidth> > address20;
sc_core::sc_in<sc_logic> ce20;
sc_core::sc_out <sc_lv<DataWidth> > q20;
sc_core::sc_in <sc_lv<AddressWidth> > address21;
sc_core::sc_in<sc_logic> ce21;
sc_core::sc_out <sc_lv<DataWidth> > q21;
sc_core::sc_in <sc_lv<AddressWidth> > address22;
sc_core::sc_in<sc_logic> ce22;
sc_core::sc_out <sc_lv<DataWidth> > q22;
sc_core::sc_in <sc_lv<AddressWidth> > address23;
sc_core::sc_in<sc_logic> ce23;
sc_core::sc_out <sc_lv<DataWidth> > q23;
sc_core::sc_in <sc_lv<AddressWidth> > address24;
sc_core::sc_in<sc_logic> ce24;
sc_core::sc_out <sc_lv<DataWidth> > q24;
sc_core::sc_in <sc_lv<AddressWidth> > address25;
sc_core::sc_in<sc_logic> ce25;
sc_core::sc_out <sc_lv<DataWidth> > q25;
sc_core::sc_in <sc_lv<AddressWidth> > address26;
sc_core::sc_in<sc_logic> ce26;
sc_core::sc_out <sc_lv<DataWidth> > q26;
sc_core::sc_in <sc_lv<AddressWidth> > address27;
sc_core::sc_in<sc_logic> ce27;
sc_core::sc_out <sc_lv<DataWidth> > q27;
sc_core::sc_in <sc_lv<AddressWidth> > address28;
sc_core::sc_in<sc_logic> ce28;
sc_core::sc_out <sc_lv<DataWidth> > q28;
sc_core::sc_in <sc_lv<AddressWidth> > address29;
sc_core::sc_in<sc_logic> ce29;
sc_core::sc_out <sc_lv<DataWidth> > q29;
sc_core::sc_in <sc_lv<AddressWidth> > address30;
sc_core::sc_in<sc_logic> ce30;
sc_core::sc_out <sc_lv<DataWidth> > q30;
sc_core::sc_in <sc_lv<AddressWidth> > address31;
sc_core::sc_in<sc_logic> ce31;
sc_core::sc_out <sc_lv<DataWidth> > q31;
sc_core::sc_in <sc_lv<AddressWidth> > address32;
sc_core::sc_in<sc_logic> ce32;
sc_core::sc_out <sc_lv<DataWidth> > q32;
sc_core::sc_in <sc_lv<AddressWidth> > address33;
sc_core::sc_in<sc_logic> ce33;
sc_core::sc_out <sc_lv<DataWidth> > q33;
sc_core::sc_in <sc_lv<AddressWidth> > address34;
sc_core::sc_in<sc_logic> ce34;
sc_core::sc_out <sc_lv<DataWidth> > q34;
sc_core::sc_in <sc_lv<AddressWidth> > address35;
sc_core::sc_in<sc_logic> ce35;
sc_core::sc_out <sc_lv<DataWidth> > q35;
sc_core::sc_in <sc_lv<AddressWidth> > address36;
sc_core::sc_in<sc_logic> ce36;
sc_core::sc_out <sc_lv<DataWidth> > q36;
sc_core::sc_in <sc_lv<AddressWidth> > address37;
sc_core::sc_in<sc_logic> ce37;
sc_core::sc_out <sc_lv<DataWidth> > q37;
sc_core::sc_in <sc_lv<AddressWidth> > address38;
sc_core::sc_in<sc_logic> ce38;
sc_core::sc_out <sc_lv<DataWidth> > q38;
sc_core::sc_in <sc_lv<AddressWidth> > address39;
sc_core::sc_in<sc_logic> ce39;
sc_core::sc_out <sc_lv<DataWidth> > q39;
sc_core::sc_in <sc_lv<AddressWidth> > address40;
sc_core::sc_in<sc_logic> ce40;
sc_core::sc_out <sc_lv<DataWidth> > q40;
sc_core::sc_in <sc_lv<AddressWidth> > address41;
sc_core::sc_in<sc_logic> ce41;
sc_core::sc_out <sc_lv<DataWidth> > q41;
sc_core::sc_in <sc_lv<AddressWidth> > address42;
sc_core::sc_in<sc_logic> ce42;
sc_core::sc_out <sc_lv<DataWidth> > q42;
sc_core::sc_in <sc_lv<AddressWidth> > address43;
sc_core::sc_in<sc_logic> ce43;
sc_core::sc_out <sc_lv<DataWidth> > q43;
sc_core::sc_in <sc_lv<AddressWidth> > address44;
sc_core::sc_in<sc_logic> ce44;
sc_core::sc_out <sc_lv<DataWidth> > q44;
sc_core::sc_in <sc_lv<AddressWidth> > address45;
sc_core::sc_in<sc_logic> ce45;
sc_core::sc_out <sc_lv<DataWidth> > q45;
sc_core::sc_in <sc_lv<AddressWidth> > address46;
sc_core::sc_in<sc_logic> ce46;
sc_core::sc_out <sc_lv<DataWidth> > q46;
sc_core::sc_in <sc_lv<AddressWidth> > address47;
sc_core::sc_in<sc_logic> ce47;
sc_core::sc_out <sc_lv<DataWidth> > q47;
sc_core::sc_in <sc_lv<AddressWidth> > address48;
sc_core::sc_in<sc_logic> ce48;
sc_core::sc_out <sc_lv<DataWidth> > q48;
sc_core::sc_in <sc_lv<AddressWidth> > address49;
sc_core::sc_in<sc_logic> ce49;
sc_core::sc_out <sc_lv<DataWidth> > q49;
sc_core::sc_in <sc_lv<AddressWidth> > address50;
sc_core::sc_in<sc_logic> ce50;
sc_core::sc_out <sc_lv<DataWidth> > q50;
sc_core::sc_in <sc_lv<AddressWidth> > address51;
sc_core::sc_in<sc_logic> ce51;
sc_core::sc_out <sc_lv<DataWidth> > q51;
sc_core::sc_in <sc_lv<AddressWidth> > address52;
sc_core::sc_in<sc_logic> ce52;
sc_core::sc_out <sc_lv<DataWidth> > q52;
sc_core::sc_in <sc_lv<AddressWidth> > address53;
sc_core::sc_in<sc_logic> ce53;
sc_core::sc_out <sc_lv<DataWidth> > q53;
sc_core::sc_in <sc_lv<AddressWidth> > address54;
sc_core::sc_in<sc_logic> ce54;
sc_core::sc_out <sc_lv<DataWidth> > q54;
sc_core::sc_in <sc_lv<AddressWidth> > address55;
sc_core::sc_in<sc_logic> ce55;
sc_core::sc_out <sc_lv<DataWidth> > q55;
sc_core::sc_in <sc_lv<AddressWidth> > address56;
sc_core::sc_in<sc_logic> ce56;
sc_core::sc_out <sc_lv<DataWidth> > q56;
sc_core::sc_in <sc_lv<AddressWidth> > address57;
sc_core::sc_in<sc_logic> ce57;
sc_core::sc_out <sc_lv<DataWidth> > q57;
sc_core::sc_in <sc_lv<AddressWidth> > address58;
sc_core::sc_in<sc_logic> ce58;
sc_core::sc_out <sc_lv<DataWidth> > q58;
sc_core::sc_in <sc_lv<AddressWidth> > address59;
sc_core::sc_in<sc_logic> ce59;
sc_core::sc_out <sc_lv<DataWidth> > q59;
sc_core::sc_in <sc_lv<AddressWidth> > address60;
sc_core::sc_in<sc_logic> ce60;
sc_core::sc_out <sc_lv<DataWidth> > q60;
sc_core::sc_in <sc_lv<AddressWidth> > address61;
sc_core::sc_in<sc_logic> ce61;
sc_core::sc_out <sc_lv<DataWidth> > q61;
sc_core::sc_in <sc_lv<AddressWidth> > address62;
sc_core::sc_in<sc_logic> ce62;
sc_core::sc_out <sc_lv<DataWidth> > q62;
sc_core::sc_in <sc_lv<AddressWidth> > address63;
sc_core::sc_in<sc_logic> ce63;
sc_core::sc_out <sc_lv<DataWidth> > q63;
sc_core::sc_in <sc_lv<AddressWidth> > address64;
sc_core::sc_in<sc_logic> ce64;
sc_core::sc_out <sc_lv<DataWidth> > q64;
sc_core::sc_in <sc_lv<AddressWidth> > address65;
sc_core::sc_in<sc_logic> ce65;
sc_core::sc_out <sc_lv<DataWidth> > q65;
sc_core::sc_in <sc_lv<AddressWidth> > address66;
sc_core::sc_in<sc_logic> ce66;
sc_core::sc_out <sc_lv<DataWidth> > q66;
sc_core::sc_in <sc_lv<AddressWidth> > address67;
sc_core::sc_in<sc_logic> ce67;
sc_core::sc_out <sc_lv<DataWidth> > q67;
sc_core::sc_in <sc_lv<AddressWidth> > address68;
sc_core::sc_in<sc_logic> ce68;
sc_core::sc_out <sc_lv<DataWidth> > q68;
sc_core::sc_in <sc_lv<AddressWidth> > address69;
sc_core::sc_in<sc_logic> ce69;
sc_core::sc_out <sc_lv<DataWidth> > q69;
sc_core::sc_in <sc_lv<AddressWidth> > address70;
sc_core::sc_in<sc_logic> ce70;
sc_core::sc_out <sc_lv<DataWidth> > q70;
sc_core::sc_in <sc_lv<AddressWidth> > address71;
sc_core::sc_in<sc_logic> ce71;
sc_core::sc_out <sc_lv<DataWidth> > q71;
sc_core::sc_in <sc_lv<AddressWidth> > address72;
sc_core::sc_in<sc_logic> ce72;
sc_core::sc_out <sc_lv<DataWidth> > q72;
sc_core::sc_in <sc_lv<AddressWidth> > address73;
sc_core::sc_in<sc_logic> ce73;
sc_core::sc_out <sc_lv<DataWidth> > q73;
sc_core::sc_in <sc_lv<AddressWidth> > address74;
sc_core::sc_in<sc_logic> ce74;
sc_core::sc_out <sc_lv<DataWidth> > q74;
sc_core::sc_in <sc_lv<AddressWidth> > address75;
sc_core::sc_in<sc_logic> ce75;
sc_core::sc_out <sc_lv<DataWidth> > q75;
sc_core::sc_in <sc_lv<AddressWidth> > address76;
sc_core::sc_in<sc_logic> ce76;
sc_core::sc_out <sc_lv<DataWidth> > q76;
sc_core::sc_in <sc_lv<AddressWidth> > address77;
sc_core::sc_in<sc_logic> ce77;
sc_core::sc_out <sc_lv<DataWidth> > q77;
sc_core::sc_in <sc_lv<AddressWidth> > address78;
sc_core::sc_in<sc_logic> ce78;
sc_core::sc_out <sc_lv<DataWidth> > q78;
sc_core::sc_in <sc_lv<AddressWidth> > address79;
sc_core::sc_in<sc_logic> ce79;
sc_core::sc_out <sc_lv<DataWidth> > q79;
sc_core::sc_in <sc_lv<AddressWidth> > address80;
sc_core::sc_in<sc_logic> ce80;
sc_core::sc_out <sc_lv<DataWidth> > q80;
sc_core::sc_in <sc_lv<AddressWidth> > address81;
sc_core::sc_in<sc_logic> ce81;
sc_core::sc_out <sc_lv<DataWidth> > q81;
sc_core::sc_in <sc_lv<AddressWidth> > address82;
sc_core::sc_in<sc_logic> ce82;
sc_core::sc_out <sc_lv<DataWidth> > q82;
sc_core::sc_in <sc_lv<AddressWidth> > address83;
sc_core::sc_in<sc_logic> ce83;
sc_core::sc_out <sc_lv<DataWidth> > q83;
sc_core::sc_in <sc_lv<AddressWidth> > address84;
sc_core::sc_in<sc_logic> ce84;
sc_core::sc_out <sc_lv<DataWidth> > q84;
sc_core::sc_in <sc_lv<AddressWidth> > address85;
sc_core::sc_in<sc_logic> ce85;
sc_core::sc_out <sc_lv<DataWidth> > q85;
sc_core::sc_in <sc_lv<AddressWidth> > address86;
sc_core::sc_in<sc_logic> ce86;
sc_core::sc_out <sc_lv<DataWidth> > q86;
sc_core::sc_in <sc_lv<AddressWidth> > address87;
sc_core::sc_in<sc_logic> ce87;
sc_core::sc_out <sc_lv<DataWidth> > q87;
sc_core::sc_in <sc_lv<AddressWidth> > address88;
sc_core::sc_in<sc_logic> ce88;
sc_core::sc_out <sc_lv<DataWidth> > q88;
sc_core::sc_in <sc_lv<AddressWidth> > address89;
sc_core::sc_in<sc_logic> ce89;
sc_core::sc_out <sc_lv<DataWidth> > q89;
sc_core::sc_in <sc_lv<AddressWidth> > address90;
sc_core::sc_in<sc_logic> ce90;
sc_core::sc_out <sc_lv<DataWidth> > q90;
sc_core::sc_in <sc_lv<AddressWidth> > address91;
sc_core::sc_in<sc_logic> ce91;
sc_core::sc_out <sc_lv<DataWidth> > q91;
sc_core::sc_in <sc_lv<AddressWidth> > address92;
sc_core::sc_in<sc_logic> ce92;
sc_core::sc_out <sc_lv<DataWidth> > q92;
sc_core::sc_in <sc_lv<AddressWidth> > address93;
sc_core::sc_in<sc_logic> ce93;
sc_core::sc_out <sc_lv<DataWidth> > q93;
sc_core::sc_in <sc_lv<AddressWidth> > address94;
sc_core::sc_in<sc_logic> ce94;
sc_core::sc_out <sc_lv<DataWidth> > q94;
sc_core::sc_in <sc_lv<AddressWidth> > address95;
sc_core::sc_in<sc_logic> ce95;
sc_core::sc_out <sc_lv<DataWidth> > q95;
sc_core::sc_in <sc_lv<AddressWidth> > address96;
sc_core::sc_in<sc_logic> ce96;
sc_core::sc_out <sc_lv<DataWidth> > q96;
sc_core::sc_in <sc_lv<AddressWidth> > address97;
sc_core::sc_in<sc_logic> ce97;
sc_core::sc_out <sc_lv<DataWidth> > q97;
sc_core::sc_in <sc_lv<AddressWidth> > address98;
sc_core::sc_in<sc_logic> ce98;
sc_core::sc_out <sc_lv<DataWidth> > q98;
sc_core::sc_in <sc_lv<AddressWidth> > address99;
sc_core::sc_in<sc_logic> ce99;
sc_core::sc_out <sc_lv<DataWidth> > q99;
sc_core::sc_in <sc_lv<AddressWidth> > address100;
sc_core::sc_in<sc_logic> ce100;
sc_core::sc_out <sc_lv<DataWidth> > q100;
sc_core::sc_in <sc_lv<AddressWidth> > address101;
sc_core::sc_in<sc_logic> ce101;
sc_core::sc_out <sc_lv<DataWidth> > q101;
sc_core::sc_in <sc_lv<AddressWidth> > address102;
sc_core::sc_in<sc_logic> ce102;
sc_core::sc_out <sc_lv<DataWidth> > q102;
sc_core::sc_in <sc_lv<AddressWidth> > address103;
sc_core::sc_in<sc_logic> ce103;
sc_core::sc_out <sc_lv<DataWidth> > q103;
sc_core::sc_in <sc_lv<AddressWidth> > address104;
sc_core::sc_in<sc_logic> ce104;
sc_core::sc_out <sc_lv<DataWidth> > q104;
sc_core::sc_in <sc_lv<AddressWidth> > address105;
sc_core::sc_in<sc_logic> ce105;
sc_core::sc_out <sc_lv<DataWidth> > q105;
sc_core::sc_in <sc_lv<AddressWidth> > address106;
sc_core::sc_in<sc_logic> ce106;
sc_core::sc_out <sc_lv<DataWidth> > q106;
sc_core::sc_in <sc_lv<AddressWidth> > address107;
sc_core::sc_in<sc_logic> ce107;
sc_core::sc_out <sc_lv<DataWidth> > q107;
sc_core::sc_in <sc_lv<AddressWidth> > address108;
sc_core::sc_in<sc_logic> ce108;
sc_core::sc_out <sc_lv<DataWidth> > q108;
sc_core::sc_in <sc_lv<AddressWidth> > address109;
sc_core::sc_in<sc_logic> ce109;
sc_core::sc_out <sc_lv<DataWidth> > q109;
sc_core::sc_in <sc_lv<AddressWidth> > address110;
sc_core::sc_in<sc_logic> ce110;
sc_core::sc_out <sc_lv<DataWidth> > q110;
sc_core::sc_in <sc_lv<AddressWidth> > address111;
sc_core::sc_in<sc_logic> ce111;
sc_core::sc_out <sc_lv<DataWidth> > q111;
sc_core::sc_in <sc_lv<AddressWidth> > address112;
sc_core::sc_in<sc_logic> ce112;
sc_core::sc_out <sc_lv<DataWidth> > q112;
sc_core::sc_in <sc_lv<AddressWidth> > address113;
sc_core::sc_in<sc_logic> ce113;
sc_core::sc_out <sc_lv<DataWidth> > q113;
sc_core::sc_in <sc_lv<AddressWidth> > address114;
sc_core::sc_in<sc_logic> ce114;
sc_core::sc_out <sc_lv<DataWidth> > q114;
sc_core::sc_in <sc_lv<AddressWidth> > address115;
sc_core::sc_in<sc_logic> ce115;
sc_core::sc_out <sc_lv<DataWidth> > q115;
sc_core::sc_in <sc_lv<AddressWidth> > address116;
sc_core::sc_in<sc_logic> ce116;
sc_core::sc_out <sc_lv<DataWidth> > q116;
sc_core::sc_in <sc_lv<AddressWidth> > address117;
sc_core::sc_in<sc_logic> ce117;
sc_core::sc_out <sc_lv<DataWidth> > q117;
sc_core::sc_in <sc_lv<AddressWidth> > address118;
sc_core::sc_in<sc_logic> ce118;
sc_core::sc_out <sc_lv<DataWidth> > q118;
sc_core::sc_in <sc_lv<AddressWidth> > address119;
sc_core::sc_in<sc_logic> ce119;
sc_core::sc_out <sc_lv<DataWidth> > q119;
sc_core::sc_in <sc_lv<AddressWidth> > address120;
sc_core::sc_in<sc_logic> ce120;
sc_core::sc_out <sc_lv<DataWidth> > q120;
sc_core::sc_in <sc_lv<AddressWidth> > address121;
sc_core::sc_in<sc_logic> ce121;
sc_core::sc_out <sc_lv<DataWidth> > q121;
sc_core::sc_in <sc_lv<AddressWidth> > address122;
sc_core::sc_in<sc_logic> ce122;
sc_core::sc_out <sc_lv<DataWidth> > q122;
sc_core::sc_in <sc_lv<AddressWidth> > address123;
sc_core::sc_in<sc_logic> ce123;
sc_core::sc_out <sc_lv<DataWidth> > q123;
sc_core::sc_in <sc_lv<AddressWidth> > address124;
sc_core::sc_in<sc_logic> ce124;
sc_core::sc_out <sc_lv<DataWidth> > q124;
sc_core::sc_in <sc_lv<AddressWidth> > address125;
sc_core::sc_in<sc_logic> ce125;
sc_core::sc_out <sc_lv<DataWidth> > q125;
sc_core::sc_in <sc_lv<AddressWidth> > address126;
sc_core::sc_in<sc_logic> ce126;
sc_core::sc_out <sc_lv<DataWidth> > q126;
sc_core::sc_in <sc_lv<AddressWidth> > address127;
sc_core::sc_in<sc_logic> ce127;
sc_core::sc_out <sc_lv<DataWidth> > q127;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_ram* meminst;


SC_CTOR(sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb) {
meminst = new sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_ram("sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->address1(address1);
meminst->ce1(ce1);
meminst->q1(q1);

meminst->address2(address2);
meminst->ce2(ce2);
meminst->q2(q2);

meminst->address3(address3);
meminst->ce3(ce3);
meminst->q3(q3);

meminst->address4(address4);
meminst->ce4(ce4);
meminst->q4(q4);

meminst->address5(address5);
meminst->ce5(ce5);
meminst->q5(q5);

meminst->address6(address6);
meminst->ce6(ce6);
meminst->q6(q6);

meminst->address7(address7);
meminst->ce7(ce7);
meminst->q7(q7);

meminst->address8(address8);
meminst->ce8(ce8);
meminst->q8(q8);

meminst->address9(address9);
meminst->ce9(ce9);
meminst->q9(q9);

meminst->address10(address10);
meminst->ce10(ce10);
meminst->q10(q10);

meminst->address11(address11);
meminst->ce11(ce11);
meminst->q11(q11);

meminst->address12(address12);
meminst->ce12(ce12);
meminst->q12(q12);

meminst->address13(address13);
meminst->ce13(ce13);
meminst->q13(q13);

meminst->address14(address14);
meminst->ce14(ce14);
meminst->q14(q14);

meminst->address15(address15);
meminst->ce15(ce15);
meminst->q15(q15);

meminst->address16(address16);
meminst->ce16(ce16);
meminst->q16(q16);

meminst->address17(address17);
meminst->ce17(ce17);
meminst->q17(q17);

meminst->address18(address18);
meminst->ce18(ce18);
meminst->q18(q18);

meminst->address19(address19);
meminst->ce19(ce19);
meminst->q19(q19);

meminst->address20(address20);
meminst->ce20(ce20);
meminst->q20(q20);

meminst->address21(address21);
meminst->ce21(ce21);
meminst->q21(q21);

meminst->address22(address22);
meminst->ce22(ce22);
meminst->q22(q22);

meminst->address23(address23);
meminst->ce23(ce23);
meminst->q23(q23);

meminst->address24(address24);
meminst->ce24(ce24);
meminst->q24(q24);

meminst->address25(address25);
meminst->ce25(ce25);
meminst->q25(q25);

meminst->address26(address26);
meminst->ce26(ce26);
meminst->q26(q26);

meminst->address27(address27);
meminst->ce27(ce27);
meminst->q27(q27);

meminst->address28(address28);
meminst->ce28(ce28);
meminst->q28(q28);

meminst->address29(address29);
meminst->ce29(ce29);
meminst->q29(q29);

meminst->address30(address30);
meminst->ce30(ce30);
meminst->q30(q30);

meminst->address31(address31);
meminst->ce31(ce31);
meminst->q31(q31);

meminst->address32(address32);
meminst->ce32(ce32);
meminst->q32(q32);

meminst->address33(address33);
meminst->ce33(ce33);
meminst->q33(q33);

meminst->address34(address34);
meminst->ce34(ce34);
meminst->q34(q34);

meminst->address35(address35);
meminst->ce35(ce35);
meminst->q35(q35);

meminst->address36(address36);
meminst->ce36(ce36);
meminst->q36(q36);

meminst->address37(address37);
meminst->ce37(ce37);
meminst->q37(q37);

meminst->address38(address38);
meminst->ce38(ce38);
meminst->q38(q38);

meminst->address39(address39);
meminst->ce39(ce39);
meminst->q39(q39);

meminst->address40(address40);
meminst->ce40(ce40);
meminst->q40(q40);

meminst->address41(address41);
meminst->ce41(ce41);
meminst->q41(q41);

meminst->address42(address42);
meminst->ce42(ce42);
meminst->q42(q42);

meminst->address43(address43);
meminst->ce43(ce43);
meminst->q43(q43);

meminst->address44(address44);
meminst->ce44(ce44);
meminst->q44(q44);

meminst->address45(address45);
meminst->ce45(ce45);
meminst->q45(q45);

meminst->address46(address46);
meminst->ce46(ce46);
meminst->q46(q46);

meminst->address47(address47);
meminst->ce47(ce47);
meminst->q47(q47);

meminst->address48(address48);
meminst->ce48(ce48);
meminst->q48(q48);

meminst->address49(address49);
meminst->ce49(ce49);
meminst->q49(q49);

meminst->address50(address50);
meminst->ce50(ce50);
meminst->q50(q50);

meminst->address51(address51);
meminst->ce51(ce51);
meminst->q51(q51);

meminst->address52(address52);
meminst->ce52(ce52);
meminst->q52(q52);

meminst->address53(address53);
meminst->ce53(ce53);
meminst->q53(q53);

meminst->address54(address54);
meminst->ce54(ce54);
meminst->q54(q54);

meminst->address55(address55);
meminst->ce55(ce55);
meminst->q55(q55);

meminst->address56(address56);
meminst->ce56(ce56);
meminst->q56(q56);

meminst->address57(address57);
meminst->ce57(ce57);
meminst->q57(q57);

meminst->address58(address58);
meminst->ce58(ce58);
meminst->q58(q58);

meminst->address59(address59);
meminst->ce59(ce59);
meminst->q59(q59);

meminst->address60(address60);
meminst->ce60(ce60);
meminst->q60(q60);

meminst->address61(address61);
meminst->ce61(ce61);
meminst->q61(q61);

meminst->address62(address62);
meminst->ce62(ce62);
meminst->q62(q62);

meminst->address63(address63);
meminst->ce63(ce63);
meminst->q63(q63);

meminst->address64(address64);
meminst->ce64(ce64);
meminst->q64(q64);

meminst->address65(address65);
meminst->ce65(ce65);
meminst->q65(q65);

meminst->address66(address66);
meminst->ce66(ce66);
meminst->q66(q66);

meminst->address67(address67);
meminst->ce67(ce67);
meminst->q67(q67);

meminst->address68(address68);
meminst->ce68(ce68);
meminst->q68(q68);

meminst->address69(address69);
meminst->ce69(ce69);
meminst->q69(q69);

meminst->address70(address70);
meminst->ce70(ce70);
meminst->q70(q70);

meminst->address71(address71);
meminst->ce71(ce71);
meminst->q71(q71);

meminst->address72(address72);
meminst->ce72(ce72);
meminst->q72(q72);

meminst->address73(address73);
meminst->ce73(ce73);
meminst->q73(q73);

meminst->address74(address74);
meminst->ce74(ce74);
meminst->q74(q74);

meminst->address75(address75);
meminst->ce75(ce75);
meminst->q75(q75);

meminst->address76(address76);
meminst->ce76(ce76);
meminst->q76(q76);

meminst->address77(address77);
meminst->ce77(ce77);
meminst->q77(q77);

meminst->address78(address78);
meminst->ce78(ce78);
meminst->q78(q78);

meminst->address79(address79);
meminst->ce79(ce79);
meminst->q79(q79);

meminst->address80(address80);
meminst->ce80(ce80);
meminst->q80(q80);

meminst->address81(address81);
meminst->ce81(ce81);
meminst->q81(q81);

meminst->address82(address82);
meminst->ce82(ce82);
meminst->q82(q82);

meminst->address83(address83);
meminst->ce83(ce83);
meminst->q83(q83);

meminst->address84(address84);
meminst->ce84(ce84);
meminst->q84(q84);

meminst->address85(address85);
meminst->ce85(ce85);
meminst->q85(q85);

meminst->address86(address86);
meminst->ce86(ce86);
meminst->q86(q86);

meminst->address87(address87);
meminst->ce87(ce87);
meminst->q87(q87);

meminst->address88(address88);
meminst->ce88(ce88);
meminst->q88(q88);

meminst->address89(address89);
meminst->ce89(ce89);
meminst->q89(q89);

meminst->address90(address90);
meminst->ce90(ce90);
meminst->q90(q90);

meminst->address91(address91);
meminst->ce91(ce91);
meminst->q91(q91);

meminst->address92(address92);
meminst->ce92(ce92);
meminst->q92(q92);

meminst->address93(address93);
meminst->ce93(ce93);
meminst->q93(q93);

meminst->address94(address94);
meminst->ce94(ce94);
meminst->q94(q94);

meminst->address95(address95);
meminst->ce95(ce95);
meminst->q95(q95);

meminst->address96(address96);
meminst->ce96(ce96);
meminst->q96(q96);

meminst->address97(address97);
meminst->ce97(ce97);
meminst->q97(q97);

meminst->address98(address98);
meminst->ce98(ce98);
meminst->q98(q98);

meminst->address99(address99);
meminst->ce99(ce99);
meminst->q99(q99);

meminst->address100(address100);
meminst->ce100(ce100);
meminst->q100(q100);

meminst->address101(address101);
meminst->ce101(ce101);
meminst->q101(q101);

meminst->address102(address102);
meminst->ce102(ce102);
meminst->q102(q102);

meminst->address103(address103);
meminst->ce103(ce103);
meminst->q103(q103);

meminst->address104(address104);
meminst->ce104(ce104);
meminst->q104(q104);

meminst->address105(address105);
meminst->ce105(ce105);
meminst->q105(q105);

meminst->address106(address106);
meminst->ce106(ce106);
meminst->q106(q106);

meminst->address107(address107);
meminst->ce107(ce107);
meminst->q107(q107);

meminst->address108(address108);
meminst->ce108(ce108);
meminst->q108(q108);

meminst->address109(address109);
meminst->ce109(ce109);
meminst->q109(q109);

meminst->address110(address110);
meminst->ce110(ce110);
meminst->q110(q110);

meminst->address111(address111);
meminst->ce111(ce111);
meminst->q111(q111);

meminst->address112(address112);
meminst->ce112(ce112);
meminst->q112(q112);

meminst->address113(address113);
meminst->ce113(ce113);
meminst->q113(q113);

meminst->address114(address114);
meminst->ce114(ce114);
meminst->q114(q114);

meminst->address115(address115);
meminst->ce115(ce115);
meminst->q115(q115);

meminst->address116(address116);
meminst->ce116(ce116);
meminst->q116(q116);

meminst->address117(address117);
meminst->ce117(ce117);
meminst->q117(q117);

meminst->address118(address118);
meminst->ce118(ce118);
meminst->q118(q118);

meminst->address119(address119);
meminst->ce119(ce119);
meminst->q119(q119);

meminst->address120(address120);
meminst->ce120(ce120);
meminst->q120(q120);

meminst->address121(address121);
meminst->ce121(ce121);
meminst->q121(q121);

meminst->address122(address122);
meminst->ce122(ce122);
meminst->q122(q122);

meminst->address123(address123);
meminst->ce123(ce123);
meminst->q123(q123);

meminst->address124(address124);
meminst->ce124(ce124);
meminst->q124(q124);

meminst->address125(address125);
meminst->ce125(ce125);
meminst->q125(q125);

meminst->address126(address126);
meminst->ce126(ce126);
meminst->q126(q126);

meminst->address127(address127);
meminst->ce127(ce127);
meminst->q127(q127);

meminst->reset(reset);
meminst->clk(clk);
}
~sigmoid_ap_fixed_ap_fixed_sigmoid_config2_recr_s_sigmoid_bkb() {
    delete meminst;
}


};//endmodule
#endif
