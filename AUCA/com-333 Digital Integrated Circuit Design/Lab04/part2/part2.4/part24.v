module part24(clk, r, q);

input clk, r;
reg [2:0] temp;
output wire [2:0] q;

always@(posedge clk or posedge r)
 begin

  if(r)
   temp <= 3'b0;
  else
   temp <= temp + 1;

 end

assign q = { temp[2], temp[2]^temp[1], temp[1]^temp[0] };

endmodule