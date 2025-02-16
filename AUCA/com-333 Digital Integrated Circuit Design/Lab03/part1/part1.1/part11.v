module part11(s0, s1, d0, d1, d2, d3, q);

input s0, s1;
input [7:0] d0;
input [7:0] d1;
input [7:0] d2;
input [7:0] d3;
output [7:0] q;

assign q = s1 ? (s0 ? d3 : d2) : (s0 ? d1 : d0);

endmodule