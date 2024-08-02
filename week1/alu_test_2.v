`timescale 1ns / 1ps

module ALU_tb;

    // Testbench signals
    reg [3:0] A, B;
    reg [2:0] alu_control;
    wire [3:0] res;
    wire n,z,c,v;

    // Instantiate the ALU module
    ALU uut (
        .IN1(A),
        .IN2(B),
        .CONTROL(alu_control),
        .RESULT(res),
        .N(n),
        .Z(z),
        .C(c),
        .V(v)
    );

    // Test vectors
    initial begin

	$dumpfile("waveform.vcd");
	$dumpvars(0,uut);
	    
        // Test vector 1: Addition (A = 4, B = 3, alu_control = 000)
        A = 4'b0100; B = 4'b0011; alu_control = 3'b000;
        #10; // Wait 10 time units
        $display("Test 1 - Addition: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // Test vector 2: Subtraction (A = 4, B = 3, alu_control = 001)
        A = 4'b0100; B = 4'b0011; alu_control = 3'b001;
        #10; // Wait 10 time units
        $display("Test 2 - Subtraction: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // Test vector 3: AND operation (A = 5, B = 3, alu_control = 010)
        A = 4'b0101; B = 4'b0011; alu_control = 3'b010;
        #10; // Wait 10 time units
        $display("Test 3 - AND: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // Test vector 4: OR operation (A = 5, B = 3, alu_control = 011)
        A = 4'b0101; B = 4'b0011; alu_control = 3'b011;
        #10; // Wait 10 time units
        $display("Test 4 - OR: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // Test vector 5: Inversion (A = 5, alu_control = 100)
        A = 4'b0101; B = 4'bxxxx; alu_control = 3'b100;
        #10; // Wait 10 time units
        $display("Test 5 - Inversion: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // Test vector 6: Zero result (A = 0, B = 0, alu_control = 000)
        A = 4'b0000; B = 4'b0000; alu_control = 3'b000;
        #10; // Wait 10 time units
        $display("Test 6 - Zero result: res=%b, n=%b, z=%b, c=%b, v=%b", res, n, z, c, v);

        // End the simulation
        $finish;
    end

endmodule

