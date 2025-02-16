force clk 0 0ns, 1 {50ns} -repeat 100ns;
force cs 0 0ns, 1 200ns;
force wr 1 0ns, 0 100ns, 1 200ns, 0 300ns, 1 400ns, 0 600ns;
force address_w 10#0 0ns, 10#1 400ns, 10#2 500ns;
force address_r 10#0 300ns, 10#1 600ns, 10#2 700ns;
force d 10#1 0ns, 10#2 400ns, 10#3 500ns;