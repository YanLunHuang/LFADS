#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/YL_HUANG/3_31/GRU/gru_layer_stream_init/myproject_prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
