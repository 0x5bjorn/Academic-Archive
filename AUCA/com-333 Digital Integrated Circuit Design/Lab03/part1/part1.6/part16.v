module part16(en, s0, s1, s2, d, q0, q1, q2, q3, q4, q5, q6, q7);

input en, s0, s1, s2;
input d;
output q0, q1, q2, q3, q4, q5, q6, q7;

assign q0 = en ? (~s2&~s1&~s0 ? d : 0) : 0;
assign q1 = en ? (~s2&~s1&s0 ? d : 0) : 0;
assign q2 = en ? (~s2&s1&~s0 ? d : 0) : 0;
assign q3 = en ? (~s2&s1&s0 ? d : 0) : 0;
assign q4 = en ? (s2&~s1&~s0 ? d : 0) : 0;
assign q5 = en ? (s2&~s1&s0 ? d : 0) : 0;
assign q6 = en ? (s2&s1&~s0 ? d : 0) : 0;
assign q7 = en ? (s2&s1&s0 ? d : 0) : 0;

endmodule