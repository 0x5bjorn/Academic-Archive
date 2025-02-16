module part21(d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, q);

input d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
output [3:0] q;

assign q[0] = d1 + d3 + d5 + d7 + d9;
assign q[1] = d2 + d3 + d6 + d7;
assign q[2] = d4 + d5 + d6 + d7;
assign q[3] = d8 + d9;

endmodule