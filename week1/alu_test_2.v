`timescale 1ns / 1ps

module ALU_tb;

    // Testbench signals
    reg [3:0] IN1, IN2;
    reg [2:0] CONTROL;
    wire [3:0] RESULT;
    wire N, Z, C, V;

    // Instantiate the ALU module
    ALU uut (
        IN1,
        IN2,
        CONTROL,
        RESULT,
        N,
        Z,
        C,
        V
    );

    // Test vectors
    initial begin
        // Test vector 1: Addition (IN1 = 4, IN2 = 3, CONTROL = 000)
        IN1 = 4'b0100; IN2 = 4'b0011; CONTROL = 3'b000;
        #10; // Wait 10 time units
        $display("Test 1 - Addition: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // Test vector 2: Subtraction (IN1 = 4, IN2 = 3, CONTROL = 001)
        IN1 = 4'b0100; IN2 = 4'b0011; CONTROL = 3'b001;
        #10; // Wait 10 time units
        $display("Test 2 - Subtraction: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // Test vector 3: AND operation (IN1 = 5, IN2 = 3, CONTROL = 010)
        IN1 = 4'b0101; IN2 = 4'b0011; CONTROL = 3'b010;
        #10; // Wait 10 time units
        $display("Test 3 - AND: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // Test vector 4: OR operation (IN1 = 5, IN2 = 3, CONTROL = 011)
        IN1 = 4'b0101; IN2 = 4'b0011; CONTROL = 3'b011;
        #10; // Wait 10 time units
        $display("Test 4 - OR: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // Test vector 5: Inversion (IN1 = 5, CONTROL = 100)
        IN1 = 4'b0101; IN2 = 4'bxxxx; CONTROL = 3'b100;
        #10; // Wait 10 time units
        $display("Test 5 - Inversion: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // Test vector 6: Zero result (IN1 = 0, IN2 = 0, CONTROL = 000)
        IN1 = 4'b0000; IN2 = 4'b0000; CONTROL = 3'b000;
        #10; // Wait 10 time units
        $display("Test 6 - Zero result: RESULT=%b, N=%b, Z=%b, C=%b, V=%b", RESULT, N, Z, C, V);

        // End the simulation
        $finish;
    end

endmodule

