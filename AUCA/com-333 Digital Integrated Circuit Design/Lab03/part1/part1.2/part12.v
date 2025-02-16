module part12(s0, s1, s2, d0, d1, d2, d3, d4, q);

input s0, s1, s2;
input [3:0] d0, d1, d2, d3, d4;
output [3:0] q;

assign q = s2 ? d4 : (s1 ? (s0 ? d3 : d2) : (s0 ? d1 : d0));

endmodule