# WEEK2

**Week2 Assignments**

## CONTENTS
* [RISCV Compiler](#RISCV_Disassembler)
* [Scrapper Script](#Scrapper_Script)
* [Counter Disassembly](#Counter_Disassembly)
* [Matrix Multiplication Disassemly](#Matrix_Multiplication_Disassemly)
* [ALU Disassembly](#ALU_Disassembly)

##RISCV_Disassembler

    * Use Risc-V compiler to convert the C-code to 32/64-bit assembly code for RISC-V
    * For each code, comment out the printf and scanf statements and remove the stdlib library.
    * The following command given and obj file-
       - riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -nostdlib -o alu.o alu.c
    * The following command converts the obj file into assembly code-
       - riscv64-unknown-elf-objdump -d -r alu.o > alu.asm.txt 
![installer](installer)
![spike](spike)
![disassembly](disassembly)
		
## Scraper Script
    I wrote a python script to calculate the total cycles for each C code. The script has a dictionary of opcodes and the assumed cycles for each opcode. The script extracts the opcode from each line, looks for these opcodes in the dictionary and gets the cycle for that opcode. This cycle for each opcode is then summed up to get the total number of cycles that will be taken by the C program. 

## Counter Disassembly
    Total cycles taken by counter.c = 897 
## Matrix Multiplication Disassemly
    Total cycles taken by matrix multiplication.c = 1112 
## ALU Disassembly
    Total cycles taken by ALU.c = 172 



