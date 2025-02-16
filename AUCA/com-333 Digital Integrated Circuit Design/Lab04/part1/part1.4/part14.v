module part14(clk, r, shift, d, q, step);

input clk, r, shift;
input [7:0] d;
input [3:0] step;
output reg [15:0] q;
reg [15:0] temp;

integer i;

always@(posedge clk or posedge r)
 begin

  if(r)
   q <= 16'b01;
  else if(shift)
   begin
    temp = q;
    
    for (i=0; i<step; i=i+1)
    begin
     temp[16+i-step] = q[i];
    end

    for (i=0; i<16-step; i=i+1)
    begin
     temp[i] = q[i+step];
    end

    q = temp;
   end
  else
   q <= {q[15:8], d};

 end

endmodule
