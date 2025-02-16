module part14(s0, s1, d, q0, q1, q2, q3);

input s0, s1;
input [7:0] d;
output [7:0] q0, q1, q2, q3;

assign q0 = ~s1&~s0 ? d : 0;
assign q1 = ~s1&s0 ? d : 0;
assign q2 = s1&~s0 ? d : 0;
assign q3 = s1&s0 ? d : 0;

endmodule