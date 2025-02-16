module part22(clk, rst, up, q);

input clk, rst, up;
output reg [3:0] q;

always@(posedge clk or posedge rst)
 begin
  if (rst)
   q <= 0;
  else
   q <= up ? (q+1) : (q-1);
 end

endmodule
