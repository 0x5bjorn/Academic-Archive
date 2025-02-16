module part12(clk, r, shift, d, q);

input clk, r, shift;
input [15:0] d;
output reg q;
reg [15:0] temp;

always@(posedge clk or posedge r)
 begin

  if(r)
   temp <= 16'b0;
  else if(shift)
   begin
    q <= temp[0];
    temp <= temp >> 1;
   end
  else
   temp <= d;

 end

endmodule
