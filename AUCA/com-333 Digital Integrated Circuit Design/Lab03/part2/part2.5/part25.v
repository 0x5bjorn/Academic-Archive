module part25(d0, d1, d2, d3, q);

input d0, d1, d2, d3;
output [9:0] q;

assign q[0] = ~d3 * ~d2 * ~d1 * ~d0;
assign q[1] = ~d3 * ~d2 * ~d1 * d0;
assign q[2] = ~d3 * ~d2 * d1 * ~d0;
assign q[3] = ~d3 * ~d2 * d1 * d0;
assign q[4] = ~d3 * d2 * ~d1 * ~d0;
assign q[5] = ~d3 * d2 * ~d1 * d0;
assign q[6] = ~d3 * d2 * d1 * ~d0;
assign q[7] = ~d3 * d2 * d1 * d0;
assign q[8] = d3 * ~d2 * ~d1 * ~d0;
assign q[9] = d3 * ~d2 * ~d1 * d0;

endmodule
