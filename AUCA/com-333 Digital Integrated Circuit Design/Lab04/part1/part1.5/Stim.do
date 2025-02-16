force clk 0 0ns, 1 {50ns} -repeat 100ns;
force rst 1 0ns, 0 100ns;
force rd 0 0ns, 1 600ns, 0 700ns, 1 800ns, 0 900ns;
force wr 0 0ns, 1 100ns, 0 200ns, 1 300ns, 0 400ns, 1 500ns, 0 600ns, 1 900ns, 0 1000ns, 1 1100ns, 0 1200ns, 1 1300ns, 0 1400ns, 1 1500ns, 0 1600ns, 1 1700ns, 0 1800ns, 1 1900ns;
force d 10#1 0ns, 10#2 200ns, 10#3 400ns, 10#4 800ns, 10#5 1000ns, 10#6 1200ns, 10#7 1400ns, 10#8 1600ns, 10#9 1800ns;