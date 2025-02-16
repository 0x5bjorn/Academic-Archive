module part23(clk, r, shift, q);

input clk, r, shift;
output reg [3:0] q;

always@(posedge clk or posedge r)
 begin

  if(r)
   q <= 4'b00;
  else if(shift)
   q <= {~q[0], q[3:1]};

 end

endmodule