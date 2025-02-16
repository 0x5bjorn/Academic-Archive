module part23(nd5, nd4, nd3, nd2, nd1, d0, d1, d2, d3, d4, q);

input nd5, nd4, nd3, nd2, nd1, d0, d1, d2, d3, d4;
output [3:0] q;

assign q[0] = nd5 + nd3 + nd1 + d1 + d3;
assign q[1] = nd5 + nd2 + nd1 + d2 + d3;
assign q[2] = nd4 + nd3 + nd2 + nd1 + d4;
assign q[3] = nd5 + nd4 + nd3 + nd2 + nd1;

endmodule