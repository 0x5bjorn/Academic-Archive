module part13(clk, r, shift, d, q);

input clk, r, shift;
input d;
output reg [7:0] q;
reg [7:0] temp;
reg counter;

always@(posedge clk or posedge r)
 begin

  if(r)
   temp <= 8'b0;
  else if(shift)
   temp <= {temp[6:0], d};
   cpunter = counter+1;
  if (counter == 8)
   q <= temp;
   counter = 0;

 end

endmodule
