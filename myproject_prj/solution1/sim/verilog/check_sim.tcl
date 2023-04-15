# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc sc_sim_check {ret err logfile} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set errfile "err.log"
    if {[file exists $errfile] && [file size $errfile] != 0} {
        set fl [open $errfile r]
        while {[gets $fl line] >= 0} {
            if {[string first "AESL_mErrNo = " $line] == 0} {
                set mismatch_num [string range $line [string length "AESL_mErrNo = "] end]
                if {$mismatch_num != 0} {
                    ::AP::printMsg ERR COSIM 403 COSIM_403_986 ${mismatch_num}
                    break
                }
            }
        }
    }
    if {$ret || $err != ""} {
        if { [lindex $::errorCode 0] eq "CHILDSTATUS"} {
            set status [lindex $::errorCode 2]
            if {$status != ""} {
                ::AP::printMsg ERR COSIM 404 COSIM_404_987 $status
            } else {
                ::AP::printMsg ERR COSIM 405 COSIM_405_988
            }
        } else {
            ::AP::printMsg ERR COSIM 405 COSIM_405_989
        }
    }
    if {[file exists $logfile]} {
        set cmdret [catch {eval exec "grep \"Error:\" $logfile"} err]
        file delete -force $logfile
        if {$cmdret == 0} {
            ::AP::printMsg ERR COSIM 405 COSIM_405_990
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
}

proc rtl_sim_check {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set errfile "err.log"
    if {[file exists $errfile] && [file size $errfile] != 0} {
        set fl [open $errfile r]
        set unmatch_num 0
        while {[gets $fl line] >= 0} {
            if {[string first "unmatched" $line] != -1} {
                set unmatch_num [expr $unmatch_num + 1]
            }
        }
        if {$unmatch_num != 0} {
            ::AP::printMsg ERR COSIM 406 COSIM_406_991 ${unmatch_num}
        }
    }
    if {[file exists ".aesl_error"]} {
        set errfl [open ".aesl_error" r]
        gets $errfl line
        if {$line != 0} {
            ::AP::printMsg ERR COSIM 407 COSIM_407_992 $line
        }
    }
    if {[file exists ".exit.err"]} {
        ::AP::printMsg ERR COSIM 405 COSIM_405_993
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
}

proc check_tvin_file {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set rtlfilelist {
         "c.myproject.autotvin_input_1_0_V_V.dat"
         "c.myproject.autotvin_input_1_1_V_V.dat"
         "c.myproject.autotvin_input_1_2_V_V.dat"
         "c.myproject.autotvin_input_1_3_V_V.dat"
         "c.myproject.autotvin_input_1_4_V_V.dat"
         "c.myproject.autotvin_input_1_5_V_V.dat"
         "c.myproject.autotvin_input_1_6_V_V.dat"
         "c.myproject.autotvin_input_1_7_V_V.dat"
         "c.myproject.autotvin_input_1_8_V_V.dat"
         "c.myproject.autotvin_input_1_9_V_V.dat"
         "c.myproject.autotvin_input_1_10_V_V.dat"
         "c.myproject.autotvin_input_1_11_V_V.dat"
         "c.myproject.autotvin_input_1_12_V_V.dat"
         "c.myproject.autotvin_input_1_13_V_V.dat"
         "c.myproject.autotvin_input_1_14_V_V.dat"
         "c.myproject.autotvin_input_1_15_V_V.dat"
         "c.myproject.autotvin_input_1_16_V_V.dat"
         "c.myproject.autotvin_input_1_17_V_V.dat"
         "c.myproject.autotvin_input_1_18_V_V.dat"
         "c.myproject.autotvin_input_1_19_V_V.dat"
         "c.myproject.autotvin_input_1_20_V_V.dat"
         "c.myproject.autotvin_input_1_21_V_V.dat"
         "c.myproject.autotvin_input_1_22_V_V.dat"
         "c.myproject.autotvin_input_1_23_V_V.dat"
         "c.myproject.autotvin_input_1_24_V_V.dat"
         "c.myproject.autotvin_input_1_25_V_V.dat"
         "c.myproject.autotvin_input_1_26_V_V.dat"
         "c.myproject.autotvin_input_1_27_V_V.dat"
         "c.myproject.autotvin_input_1_28_V_V.dat"
         "c.myproject.autotvin_input_1_29_V_V.dat"
         "c.myproject.autotvin_input_1_30_V_V.dat"
         "c.myproject.autotvin_input_1_31_V_V.dat"
         "c.myproject.autotvin_input_1_32_V_V.dat"
         "c.myproject.autotvin_input_1_33_V_V.dat"
         "c.myproject.autotvin_input_1_34_V_V.dat"
         "c.myproject.autotvin_input_1_35_V_V.dat"
         "c.myproject.autotvin_input_1_36_V_V.dat"
         "c.myproject.autotvin_input_1_37_V_V.dat"
         "c.myproject.autotvin_input_1_38_V_V.dat"
         "c.myproject.autotvin_input_1_39_V_V.dat"
         "c.myproject.autotvin_input_1_40_V_V.dat"
         "c.myproject.autotvin_input_1_41_V_V.dat"
         "c.myproject.autotvin_input_1_42_V_V.dat"
         "c.myproject.autotvin_input_1_43_V_V.dat"
         "c.myproject.autotvin_input_1_44_V_V.dat"
         "c.myproject.autotvin_input_1_45_V_V.dat"
         "c.myproject.autotvin_input_1_46_V_V.dat"
         "c.myproject.autotvin_input_1_47_V_V.dat"
         "c.myproject.autotvin_input_1_48_V_V.dat"
         "c.myproject.autotvin_input_1_49_V_V.dat"
         "c.myproject.autotvin_input_1_50_V_V.dat"
         "c.myproject.autotvin_input_1_51_V_V.dat"
         "c.myproject.autotvin_input_1_52_V_V.dat"
         "c.myproject.autotvin_input_1_53_V_V.dat"
         "c.myproject.autotvin_input_1_54_V_V.dat"
         "c.myproject.autotvin_input_1_55_V_V.dat"
         "c.myproject.autotvin_input_1_56_V_V.dat"
         "c.myproject.autotvin_input_1_57_V_V.dat"
         "c.myproject.autotvin_input_1_58_V_V.dat"
         "c.myproject.autotvin_input_1_59_V_V.dat"
         "c.myproject.autotvin_input_1_60_V_V.dat"
         "c.myproject.autotvin_input_1_61_V_V.dat"
         "c.myproject.autotvin_input_1_62_V_V.dat"
         "c.myproject.autotvin_input_1_63_V_V.dat"
         "c.myproject.autotvin_initial_state_0_V_V.dat"
         "c.myproject.autotvin_initial_state_1_V_V.dat"
         "c.myproject.autotvin_initial_state_2_V_V.dat"
         "c.myproject.autotvin_initial_state_3_V_V.dat"
         "c.myproject.autotvin_initial_state_4_V_V.dat"
         "c.myproject.autotvin_initial_state_5_V_V.dat"
         "c.myproject.autotvin_initial_state_6_V_V.dat"
         "c.myproject.autotvin_initial_state_7_V_V.dat"
         "c.myproject.autotvin_initial_state_8_V_V.dat"
         "c.myproject.autotvin_initial_state_9_V_V.dat"
         "c.myproject.autotvin_initial_state_10_V_V.dat"
         "c.myproject.autotvin_initial_state_11_V_V.dat"
         "c.myproject.autotvin_initial_state_12_V_V.dat"
         "c.myproject.autotvin_initial_state_13_V_V.dat"
         "c.myproject.autotvin_initial_state_14_V_V.dat"
         "c.myproject.autotvin_initial_state_15_V_V.dat"
         "c.myproject.autotvin_initial_state_16_V_V.dat"
         "c.myproject.autotvin_initial_state_17_V_V.dat"
         "c.myproject.autotvin_initial_state_18_V_V.dat"
         "c.myproject.autotvin_initial_state_19_V_V.dat"
         "c.myproject.autotvin_initial_state_20_V_V.dat"
         "c.myproject.autotvin_initial_state_21_V_V.dat"
         "c.myproject.autotvin_initial_state_22_V_V.dat"
         "c.myproject.autotvin_initial_state_23_V_V.dat"
         "c.myproject.autotvin_initial_state_24_V_V.dat"
         "c.myproject.autotvin_initial_state_25_V_V.dat"
         "c.myproject.autotvin_initial_state_26_V_V.dat"
         "c.myproject.autotvin_initial_state_27_V_V.dat"
         "c.myproject.autotvin_initial_state_28_V_V.dat"
         "c.myproject.autotvin_initial_state_29_V_V.dat"
         "c.myproject.autotvin_initial_state_30_V_V.dat"
         "c.myproject.autotvin_initial_state_31_V_V.dat"
         "c.myproject.autotvin_initial_state_32_V_V.dat"
         "c.myproject.autotvin_initial_state_33_V_V.dat"
         "c.myproject.autotvin_initial_state_34_V_V.dat"
         "c.myproject.autotvin_initial_state_35_V_V.dat"
         "c.myproject.autotvin_initial_state_36_V_V.dat"
         "c.myproject.autotvin_initial_state_37_V_V.dat"
         "c.myproject.autotvin_initial_state_38_V_V.dat"
         "c.myproject.autotvin_initial_state_39_V_V.dat"
         "c.myproject.autotvin_initial_state_40_V_V.dat"
         "c.myproject.autotvin_initial_state_41_V_V.dat"
         "c.myproject.autotvin_initial_state_42_V_V.dat"
         "c.myproject.autotvin_initial_state_43_V_V.dat"
         "c.myproject.autotvin_initial_state_44_V_V.dat"
         "c.myproject.autotvin_initial_state_45_V_V.dat"
         "c.myproject.autotvin_initial_state_46_V_V.dat"
         "c.myproject.autotvin_initial_state_47_V_V.dat"
         "c.myproject.autotvin_initial_state_48_V_V.dat"
         "c.myproject.autotvin_initial_state_49_V_V.dat"
         "c.myproject.autotvin_initial_state_50_V_V.dat"
         "c.myproject.autotvin_initial_state_51_V_V.dat"
         "c.myproject.autotvin_initial_state_52_V_V.dat"
         "c.myproject.autotvin_initial_state_53_V_V.dat"
         "c.myproject.autotvin_initial_state_54_V_V.dat"
         "c.myproject.autotvin_initial_state_55_V_V.dat"
         "c.myproject.autotvin_initial_state_56_V_V.dat"
         "c.myproject.autotvin_initial_state_57_V_V.dat"
         "c.myproject.autotvin_initial_state_58_V_V.dat"
         "c.myproject.autotvin_initial_state_59_V_V.dat"
         "c.myproject.autotvin_initial_state_60_V_V.dat"
         "c.myproject.autotvin_initial_state_61_V_V.dat"
         "c.myproject.autotvin_initial_state_62_V_V.dat"
         "c.myproject.autotvin_initial_state_63_V_V.dat"
         "c.myproject.autotvin_layer2_out_0_V_V.dat"
         "c.myproject.autotvin_layer2_out_1_V_V.dat"
         "c.myproject.autotvin_layer2_out_2_V_V.dat"
         "c.myproject.autotvin_layer2_out_3_V_V.dat"
         "c.myproject.autotvin_layer2_out_4_V_V.dat"
         "c.myproject.autotvin_layer2_out_5_V_V.dat"
         "c.myproject.autotvin_layer2_out_6_V_V.dat"
         "c.myproject.autotvin_layer2_out_7_V_V.dat"
         "c.myproject.autotvin_layer2_out_8_V_V.dat"
         "c.myproject.autotvin_layer2_out_9_V_V.dat"
         "c.myproject.autotvin_layer2_out_10_V_V.dat"
         "c.myproject.autotvin_layer2_out_11_V_V.dat"
         "c.myproject.autotvin_layer2_out_12_V_V.dat"
         "c.myproject.autotvin_layer2_out_13_V_V.dat"
         "c.myproject.autotvin_layer2_out_14_V_V.dat"
         "c.myproject.autotvin_layer2_out_15_V_V.dat"
         "c.myproject.autotvin_layer2_out_16_V_V.dat"
         "c.myproject.autotvin_layer2_out_17_V_V.dat"
         "c.myproject.autotvin_layer2_out_18_V_V.dat"
         "c.myproject.autotvin_layer2_out_19_V_V.dat"
         "c.myproject.autotvin_layer2_out_20_V_V.dat"
         "c.myproject.autotvin_layer2_out_21_V_V.dat"
         "c.myproject.autotvin_layer2_out_22_V_V.dat"
         "c.myproject.autotvin_layer2_out_23_V_V.dat"
         "c.myproject.autotvin_layer2_out_24_V_V.dat"
         "c.myproject.autotvin_layer2_out_25_V_V.dat"
         "c.myproject.autotvin_layer2_out_26_V_V.dat"
         "c.myproject.autotvin_layer2_out_27_V_V.dat"
         "c.myproject.autotvin_layer2_out_28_V_V.dat"
         "c.myproject.autotvin_layer2_out_29_V_V.dat"
         "c.myproject.autotvin_layer2_out_30_V_V.dat"
         "c.myproject.autotvin_layer2_out_31_V_V.dat"
         "c.myproject.autotvin_layer2_out_32_V_V.dat"
         "c.myproject.autotvin_layer2_out_33_V_V.dat"
         "c.myproject.autotvin_layer2_out_34_V_V.dat"
         "c.myproject.autotvin_layer2_out_35_V_V.dat"
         "c.myproject.autotvin_layer2_out_36_V_V.dat"
         "c.myproject.autotvin_layer2_out_37_V_V.dat"
         "c.myproject.autotvin_layer2_out_38_V_V.dat"
         "c.myproject.autotvin_layer2_out_39_V_V.dat"
         "c.myproject.autotvin_layer2_out_40_V_V.dat"
         "c.myproject.autotvin_layer2_out_41_V_V.dat"
         "c.myproject.autotvin_layer2_out_42_V_V.dat"
         "c.myproject.autotvin_layer2_out_43_V_V.dat"
         "c.myproject.autotvin_layer2_out_44_V_V.dat"
         "c.myproject.autotvin_layer2_out_45_V_V.dat"
         "c.myproject.autotvin_layer2_out_46_V_V.dat"
         "c.myproject.autotvin_layer2_out_47_V_V.dat"
         "c.myproject.autotvin_layer2_out_48_V_V.dat"
         "c.myproject.autotvin_layer2_out_49_V_V.dat"
         "c.myproject.autotvin_layer2_out_50_V_V.dat"
         "c.myproject.autotvin_layer2_out_51_V_V.dat"
         "c.myproject.autotvin_layer2_out_52_V_V.dat"
         "c.myproject.autotvin_layer2_out_53_V_V.dat"
         "c.myproject.autotvin_layer2_out_54_V_V.dat"
         "c.myproject.autotvin_layer2_out_55_V_V.dat"
         "c.myproject.autotvin_layer2_out_56_V_V.dat"
         "c.myproject.autotvin_layer2_out_57_V_V.dat"
         "c.myproject.autotvin_layer2_out_58_V_V.dat"
         "c.myproject.autotvin_layer2_out_59_V_V.dat"
         "c.myproject.autotvin_layer2_out_60_V_V.dat"
         "c.myproject.autotvin_layer2_out_61_V_V.dat"
         "c.myproject.autotvin_layer2_out_62_V_V.dat"
         "c.myproject.autotvin_layer2_out_63_V_V.dat"
         "c.myproject.autotvout_layer2_out_0_V_V.dat"
         "c.myproject.autotvout_layer2_out_1_V_V.dat"
         "c.myproject.autotvout_layer2_out_2_V_V.dat"
         "c.myproject.autotvout_layer2_out_3_V_V.dat"
         "c.myproject.autotvout_layer2_out_4_V_V.dat"
         "c.myproject.autotvout_layer2_out_5_V_V.dat"
         "c.myproject.autotvout_layer2_out_6_V_V.dat"
         "c.myproject.autotvout_layer2_out_7_V_V.dat"
         "c.myproject.autotvout_layer2_out_8_V_V.dat"
         "c.myproject.autotvout_layer2_out_9_V_V.dat"
         "c.myproject.autotvout_layer2_out_10_V_V.dat"
         "c.myproject.autotvout_layer2_out_11_V_V.dat"
         "c.myproject.autotvout_layer2_out_12_V_V.dat"
         "c.myproject.autotvout_layer2_out_13_V_V.dat"
         "c.myproject.autotvout_layer2_out_14_V_V.dat"
         "c.myproject.autotvout_layer2_out_15_V_V.dat"
         "c.myproject.autotvout_layer2_out_16_V_V.dat"
         "c.myproject.autotvout_layer2_out_17_V_V.dat"
         "c.myproject.autotvout_layer2_out_18_V_V.dat"
         "c.myproject.autotvout_layer2_out_19_V_V.dat"
         "c.myproject.autotvout_layer2_out_20_V_V.dat"
         "c.myproject.autotvout_layer2_out_21_V_V.dat"
         "c.myproject.autotvout_layer2_out_22_V_V.dat"
         "c.myproject.autotvout_layer2_out_23_V_V.dat"
         "c.myproject.autotvout_layer2_out_24_V_V.dat"
         "c.myproject.autotvout_layer2_out_25_V_V.dat"
         "c.myproject.autotvout_layer2_out_26_V_V.dat"
         "c.myproject.autotvout_layer2_out_27_V_V.dat"
         "c.myproject.autotvout_layer2_out_28_V_V.dat"
         "c.myproject.autotvout_layer2_out_29_V_V.dat"
         "c.myproject.autotvout_layer2_out_30_V_V.dat"
         "c.myproject.autotvout_layer2_out_31_V_V.dat"
         "c.myproject.autotvout_layer2_out_32_V_V.dat"
         "c.myproject.autotvout_layer2_out_33_V_V.dat"
         "c.myproject.autotvout_layer2_out_34_V_V.dat"
         "c.myproject.autotvout_layer2_out_35_V_V.dat"
         "c.myproject.autotvout_layer2_out_36_V_V.dat"
         "c.myproject.autotvout_layer2_out_37_V_V.dat"
         "c.myproject.autotvout_layer2_out_38_V_V.dat"
         "c.myproject.autotvout_layer2_out_39_V_V.dat"
         "c.myproject.autotvout_layer2_out_40_V_V.dat"
         "c.myproject.autotvout_layer2_out_41_V_V.dat"
         "c.myproject.autotvout_layer2_out_42_V_V.dat"
         "c.myproject.autotvout_layer2_out_43_V_V.dat"
         "c.myproject.autotvout_layer2_out_44_V_V.dat"
         "c.myproject.autotvout_layer2_out_45_V_V.dat"
         "c.myproject.autotvout_layer2_out_46_V_V.dat"
         "c.myproject.autotvout_layer2_out_47_V_V.dat"
         "c.myproject.autotvout_layer2_out_48_V_V.dat"
         "c.myproject.autotvout_layer2_out_49_V_V.dat"
         "c.myproject.autotvout_layer2_out_50_V_V.dat"
         "c.myproject.autotvout_layer2_out_51_V_V.dat"
         "c.myproject.autotvout_layer2_out_52_V_V.dat"
         "c.myproject.autotvout_layer2_out_53_V_V.dat"
         "c.myproject.autotvout_layer2_out_54_V_V.dat"
         "c.myproject.autotvout_layer2_out_55_V_V.dat"
         "c.myproject.autotvout_layer2_out_56_V_V.dat"
         "c.myproject.autotvout_layer2_out_57_V_V.dat"
         "c.myproject.autotvout_layer2_out_58_V_V.dat"
         "c.myproject.autotvout_layer2_out_59_V_V.dat"
         "c.myproject.autotvout_layer2_out_60_V_V.dat"
         "c.myproject.autotvout_layer2_out_61_V_V.dat"
         "c.myproject.autotvout_layer2_out_62_V_V.dat"
         "c.myproject.autotvout_layer2_out_63_V_V.dat"
    }
    foreach rtlfile $rtlfilelist {
        if {[file isfile $rtlfile]} {
        } else {
            ::AP::printMsg ERR COSIM 320 COSIM_320_994
            return 1
        }
        set ret [catch {eval exec "grep /runtime $rtlfile"} err]
        if { $ret } {
            ::AP::printMsg ERR COSIM 320 COSIM_320_995
            return 1
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
    return 0
}

proc check_tvout_file {} {
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] start...";
	}
    set rtlfilelist {
         "rtl.myproject.autotvout_layer2_out_0_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_1_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_2_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_3_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_4_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_5_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_6_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_7_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_8_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_9_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_10_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_11_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_12_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_13_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_14_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_15_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_16_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_17_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_18_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_19_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_20_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_21_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_22_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_23_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_24_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_25_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_26_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_27_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_28_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_29_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_30_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_31_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_32_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_33_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_34_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_35_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_36_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_37_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_38_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_39_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_40_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_41_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_42_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_43_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_44_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_45_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_46_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_47_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_48_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_49_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_50_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_51_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_52_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_53_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_54_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_55_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_56_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_57_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_58_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_59_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_60_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_61_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_62_V_V.dat"
         "rtl.myproject.autotvout_layer2_out_63_V_V.dat"
    }
    foreach rtlfile $rtlfilelist {
        if {[file isfile $rtlfile]} {
        } else {
            ::AP::printMsg ERR COSIM 303 COSIM_303_996
            return 1
        }
        set ret [catch {eval exec "grep /runtime $rtlfile"} err]
        if { $ret } {
            ::AP::printMsg ERR COSIM 303 COSIM_303_997
            return 1
        }
    }
	if {$::AESL_AUTOSIM::gDebug == 1} {
		puts stdout "[debug_prompt arg check_sim.tcl] finish...";
	}
    return 0
}
