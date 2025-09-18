set hls_src_files [list execute.cpp \
	dissasemble.cpp \
	decode.cpp \
	fetch.cpp \
	rv32i_npp_ip.cpp \
	type.cpp \
	immediate.cpp \
	print.cpp \
	emulate.cpp
]
set testbench_files [list test_bench_rv32i_npp_ip.cpp ]
open_project rv32i_npp_ip
add_files $hls_src_files
add_files -tb $testbench_files
set_top rv32i_npp_ip
open_solution "solution1"
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
csynth_design
cosim_design
export_design
