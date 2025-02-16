module part26(d0, d1, d2, d3, q);

input d0, d1, d2, d3;
output [6:0] q;
wire n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, a, b, c, d, e, f;

assign n0 = ~d3 * ~d2 * ~d1 * ~d0;
assign n1 = ~d3 * ~d2 * ~d1 * d0;
assign n2 = ~d3 * ~d2 * d1 * ~d0;
assign n3 = ~d3 * ~d2 * d1 * d0;
assign n4 = ~d3 * d2 * ~d1 * ~d0;
assign n5 = ~d3 * d2 * ~d1 * d0;
assign n6 = ~d3 * d2 * d1 * ~d0;
assign n7 = ~d3 * d2 * d1 * d0;
assign n8 = d3 * ~d2 * ~d1 * ~d0;
assign n9 = d3 * ~d2 * ~d1 * d0;
assign a = d3 * ~d2 * d1 * ~d0;
assign b = d3 * ~d2 * d1 * d0;
assign c = d3 * d2 * ~d1 * ~d0;
assign d = d3 * d2 * ~d1 * d0;
assign e = d3 * d2 * d1 * ~d0;
assign f = d3 * d2 * d1 * d0;

assign q[0] = n0 | n2 | n3 | n5 | n6 | n7 | n8 | n9 | a | c | e | f;
assign q[1] = n0 | n1 | n2 | n3 | n4 | n7 | n8 | n9 | a | d;
assign q[2] = n0 | n1 | n3 | n4 | n5 | n6 | n7 | n8 | n9 | a | b | d;
assign q[3] = n0 | n2 | n3 | n5 | n6 | n8 | n9 | b | c | d | e;
assign q[4] = n0 | n2 | n6 | n8 | a | b | c | d | e | f;
assign q[5] = n0 | n4 | n5 | n6 | n8 | n9 | a | b | c |  e | f;
assign q[6] = n2 | n3 | n4 | n5 | n6 | n8 | n9 | a | b | d | e | f;

endmodule
