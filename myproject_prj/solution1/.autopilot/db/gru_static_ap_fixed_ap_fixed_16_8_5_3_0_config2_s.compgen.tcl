# This script segment is generated automatically by AutoPilot

set id 650
set name myproject_mul_mul_16s_16s_24_1_1
set corename simcore_mul
set op mul
set stage_num 1
set max_latency -1
set registered_input 1
set in0_width 16
set in0_signed 1
set in1_width 16
set in1_signed 1
set out_width 24
set exp i0*i1
set arg_lists {i0 {16 1 +} i1 {16 1 +} p {24 1 +} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mul] == "ap_gen_simcore_mul"} {
eval "ap_gen_simcore_mul { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-100\] Cannot find ap_gen_simcore_mul, check your AutoPilot builtin lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler ${name}
}


set op mul
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
}
}


set id 714
set name myproject_mul_mul_17s_16s_24_1_1
set corename simcore_mul
set op mul
set stage_num 1
set max_latency -1
set registered_input 1
set in0_width 17
set in0_signed 1
set in1_width 16
set in1_signed 1
set out_width 24
set exp i0*i1
set arg_lists {i0 {17 1 +} i1 {16 1 +} p {24 1 +} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mul] == "ap_gen_simcore_mul"} {
eval "ap_gen_simcore_mul { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-100\] Cannot find ap_gen_simcore_mul, check your AutoPilot builtin lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler ${name}
}


set op mul
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
}
}


set id 778
set name myproject_mac_muladd_16s_16s_24s_24_1_1
set corename simcore_mac
set op mac
set stage_num 1
set max_latency -1
set registered_input 1
set in0_width 16
set in0_signed 1
set in1_width 16
set in1_signed 1
set in2_width 24
set in2_signed 1
set out_width 24
set exp i0*i1+i2
set arg_lists {i0 {16 1 +} i1 {16 1 +} m {24 1 +} i2 {24 1 +} p {24 1 +} c_reg {1} rnd {0} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mac] == "ap_gen_simcore_mac"} {
eval "ap_gen_simcore_mac { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    in2_width ${in2_width} \
    in2_signed ${in2_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-100\] Cannot find ap_gen_simcore_mac, check your AutoPilot builtin lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler ${name}
}


set op mac
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    max_latency ${max_latency} \
    registered_input ${registered_input} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    in2_width ${in2_width} \
    in2_signed ${in2_signed} \
    out_width ${out_width} \
    exp ${exp} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
}
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 845 \
    name data_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_data_V_read \
    op interface \
    ports { data_V_read { I 1024 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 846 \
    name h_newstate_0_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_0_V_read \
    op interface \
    ports { h_newstate_0_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 847 \
    name h_newstate_1_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_1_V_read \
    op interface \
    ports { h_newstate_1_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 848 \
    name h_newstate_2_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_2_V_read \
    op interface \
    ports { h_newstate_2_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 849 \
    name h_newstate_3_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_3_V_read \
    op interface \
    ports { h_newstate_3_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 850 \
    name h_newstate_4_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_4_V_read \
    op interface \
    ports { h_newstate_4_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 851 \
    name h_newstate_5_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_5_V_read \
    op interface \
    ports { h_newstate_5_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 852 \
    name h_newstate_6_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_6_V_read \
    op interface \
    ports { h_newstate_6_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 853 \
    name h_newstate_7_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_7_V_read \
    op interface \
    ports { h_newstate_7_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 854 \
    name h_newstate_8_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_8_V_read \
    op interface \
    ports { h_newstate_8_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 855 \
    name h_newstate_9_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_9_V_read \
    op interface \
    ports { h_newstate_9_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 856 \
    name h_newstate_10_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_10_V_read \
    op interface \
    ports { h_newstate_10_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 857 \
    name h_newstate_11_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_11_V_read \
    op interface \
    ports { h_newstate_11_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 858 \
    name h_newstate_12_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_12_V_read \
    op interface \
    ports { h_newstate_12_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 859 \
    name h_newstate_13_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_13_V_read \
    op interface \
    ports { h_newstate_13_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 860 \
    name h_newstate_14_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_14_V_read \
    op interface \
    ports { h_newstate_14_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 861 \
    name h_newstate_15_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_15_V_read \
    op interface \
    ports { h_newstate_15_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 862 \
    name h_newstate_16_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_16_V_read \
    op interface \
    ports { h_newstate_16_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 863 \
    name h_newstate_17_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_17_V_read \
    op interface \
    ports { h_newstate_17_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 864 \
    name h_newstate_18_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_18_V_read \
    op interface \
    ports { h_newstate_18_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 865 \
    name h_newstate_19_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_19_V_read \
    op interface \
    ports { h_newstate_19_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 866 \
    name h_newstate_20_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_20_V_read \
    op interface \
    ports { h_newstate_20_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 867 \
    name h_newstate_21_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_21_V_read \
    op interface \
    ports { h_newstate_21_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 868 \
    name h_newstate_22_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_22_V_read \
    op interface \
    ports { h_newstate_22_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 869 \
    name h_newstate_23_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_23_V_read \
    op interface \
    ports { h_newstate_23_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 870 \
    name h_newstate_24_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_24_V_read \
    op interface \
    ports { h_newstate_24_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 871 \
    name h_newstate_25_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_25_V_read \
    op interface \
    ports { h_newstate_25_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 872 \
    name h_newstate_26_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_26_V_read \
    op interface \
    ports { h_newstate_26_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 873 \
    name h_newstate_27_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_27_V_read \
    op interface \
    ports { h_newstate_27_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 874 \
    name h_newstate_28_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_28_V_read \
    op interface \
    ports { h_newstate_28_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 875 \
    name h_newstate_29_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_29_V_read \
    op interface \
    ports { h_newstate_29_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 876 \
    name h_newstate_30_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_30_V_read \
    op interface \
    ports { h_newstate_30_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 877 \
    name h_newstate_31_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_31_V_read \
    op interface \
    ports { h_newstate_31_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 878 \
    name h_newstate_32_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_32_V_read \
    op interface \
    ports { h_newstate_32_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 879 \
    name h_newstate_33_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_33_V_read \
    op interface \
    ports { h_newstate_33_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 880 \
    name h_newstate_34_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_34_V_read \
    op interface \
    ports { h_newstate_34_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 881 \
    name h_newstate_35_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_35_V_read \
    op interface \
    ports { h_newstate_35_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 882 \
    name h_newstate_36_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_36_V_read \
    op interface \
    ports { h_newstate_36_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 883 \
    name h_newstate_37_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_37_V_read \
    op interface \
    ports { h_newstate_37_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 884 \
    name h_newstate_38_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_38_V_read \
    op interface \
    ports { h_newstate_38_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 885 \
    name h_newstate_39_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_39_V_read \
    op interface \
    ports { h_newstate_39_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 886 \
    name h_newstate_40_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_40_V_read \
    op interface \
    ports { h_newstate_40_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 887 \
    name h_newstate_41_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_41_V_read \
    op interface \
    ports { h_newstate_41_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 888 \
    name h_newstate_42_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_42_V_read \
    op interface \
    ports { h_newstate_42_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 889 \
    name h_newstate_43_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_43_V_read \
    op interface \
    ports { h_newstate_43_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 890 \
    name h_newstate_44_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_44_V_read \
    op interface \
    ports { h_newstate_44_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 891 \
    name h_newstate_45_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_45_V_read \
    op interface \
    ports { h_newstate_45_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 892 \
    name h_newstate_46_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_46_V_read \
    op interface \
    ports { h_newstate_46_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 893 \
    name h_newstate_47_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_47_V_read \
    op interface \
    ports { h_newstate_47_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 894 \
    name h_newstate_48_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_48_V_read \
    op interface \
    ports { h_newstate_48_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 895 \
    name h_newstate_49_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_49_V_read \
    op interface \
    ports { h_newstate_49_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 896 \
    name h_newstate_50_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_50_V_read \
    op interface \
    ports { h_newstate_50_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 897 \
    name h_newstate_51_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_51_V_read \
    op interface \
    ports { h_newstate_51_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 898 \
    name h_newstate_52_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_52_V_read \
    op interface \
    ports { h_newstate_52_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 899 \
    name h_newstate_53_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_53_V_read \
    op interface \
    ports { h_newstate_53_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 900 \
    name h_newstate_54_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_54_V_read \
    op interface \
    ports { h_newstate_54_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 901 \
    name h_newstate_55_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_55_V_read \
    op interface \
    ports { h_newstate_55_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 902 \
    name h_newstate_56_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_56_V_read \
    op interface \
    ports { h_newstate_56_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 903 \
    name h_newstate_57_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_57_V_read \
    op interface \
    ports { h_newstate_57_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 904 \
    name h_newstate_58_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_58_V_read \
    op interface \
    ports { h_newstate_58_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 905 \
    name h_newstate_59_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_59_V_read \
    op interface \
    ports { h_newstate_59_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 906 \
    name h_newstate_60_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_60_V_read \
    op interface \
    ports { h_newstate_60_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 907 \
    name h_newstate_61_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_61_V_read \
    op interface \
    ports { h_newstate_61_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 908 \
    name h_newstate_62_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_62_V_read \
    op interface \
    ports { h_newstate_62_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 909 \
    name h_newstate_63_V_read \
    type other \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_h_newstate_63_V_read \
    op interface \
    ports { h_newstate_63_V_read { I 16 vector } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -2 \
    name ap_return \
    type ap_return \
    reset_level 1 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 1 vector } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -4 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


