module ALU(IN2,IN2,CONTROL,RESULT,N,Z,C,V);

//inputs
input [3:0] IN1, IN2;
input [2:0] CONTROL;

//outputs
output reg [3:0] RESULT;
output N,Z,C,V;


//declaring wires

wire [3:0] and_out;
wire [3:0] or_out;
wire [3:0] inv_out;
wire [3:0] sum;
wire cout;

//logic
 
assign and_out = IN1 & IN2;
assign or_out = IN1 | IN2;
assign inv_out = ~IN1;

//declaring wire for neg IN2 for substract

wire [3:0] neg_in2;
assign neg_in2 = ~IN2 + 1; //2's complement

//declaring the wire output of mux for selecting 
//IN2 depending on add or sub operation

wire [3:0] mux_in2;
assign mux_in2 = CONTROL[0]? neg_in2: IN2;

//declare wire for sum

assign {cout,sum} = IN1 + mux_in2;

//write code for result here
always @(*)begin
	case(CONTROL[2:0])
		3'b000: RESULT = sum;
		3'b001: RESULT = sum;
		3'b010: RESULT = and_out;
		3'b011: RESULT = or_out;
		3'b100: RESULT = inv_out;
		default: RESULT = 4'b0000;
	endcase
end

//wire [3:0] mux_result;
//
//assign mux_result = CONTROL[2:0] == 3'b000 ? sum:
//       			CONTROL[2:0] == 3'b001 ? sum:
//			CONTROL[2:0] == 3'b010 ? and_out:
//			CONTROL[2:0] == 3'b011 ? or_out:
//			CONTROL[2:0] == 3'b100 ? inv_out: 4'b0000;
//			
//assign RESULT = mux_result;
					

//flag assignment

assign Z = ~|RESULT; //zero flag

assign N = RESULT[3]; //negative flag

//carry assignment

wire control_bit_2_1; 
assign control_bit_2_1 = |(CONTROL[2:1]);
assign C = cout & (~control_bit_2_1);	//carry flag

//overflow assignment

wire ov1,ov2,ov3, wire_V;

assign ov1 = ~control_bit_2_1;
assign ov2 = IN1[3] ^ sum[3];
assign ov3 = ~( IN1[3] ^ IN2[3] ^ CONTROL[0]);

assign wire_V = ov1 & ov2 & ov3;
assign V = wire_V; //overflow flag

endmodule









