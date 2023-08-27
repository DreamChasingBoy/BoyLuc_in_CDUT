onerror {quit -f}
vlib work
vlog -work work FFT_qsim.vo
vlog -work work FFT.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.FFT_vlg_vec_tst
vcd file -direction FFT.msim.vcd
vcd add -internal FFT_vlg_vec_tst/*
vcd add -internal FFT_vlg_vec_tst/i1/*
add wave /*
run -all
