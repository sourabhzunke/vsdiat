# WEEK0 

## Contents
* Counter 
* 2x2 matrix multiplier

##Counter

*Program to run a seconds counter in C.*

Understanding the RISC-V GCC code

void delay(int n) {
    int us = n; // microseconds
    clock_t start_time = clock();
    while (clock() < start_time + (us * CLOCKS_PER_SEC / 1000000));
}

delay(int):
        addi    sp,sp,-16
        sw      ra,12(sp)
        sw      s0,8(sp)
        mv      s0,a0
        call    clock
        add     s0,s0,a0
.L2:
        call    clock
        blt     a0,s0,.L2
        lw      ra,12(sp)
        lw      s0,8(sp)
        addi    sp,sp,16
        jr      ra


* addi sp,sp.-16
is add immediate, adding -16 to the sp(stack pointer)
This basically deducts the stack pointer value by 16 and assigns memory for the funtion

* sw ra,12(sp) 
sw(store word) store the return address. Whenever a function is called the ra needs to be saved in order to return after function completion

* sw s0,8(sp)
save register s0 (int us)

* mv s0,a0
copy the *delay* argument a0 to s0 (us = n) 

* call clock
call a predefined function clock 

* add s0,s0,a0
start_time+(us * CLOCKS_PRE_SEC/1000...)


.L2: (while loop)

* call clock
get the current time

* blt a0,s0,.L2 (branch if less than)
??? compares the start_time+delay argument to the current time.
If the current time is less, loop back to L2

* lw ra,12(sp)
load the return address. Each address is 4 byte or 32-bit.
Hence the value 12 (16-12 = 4) 

* lw s0,8(sp)
??? restore the register. deallocate memory I guess

* addi sp,sp,16
restore the stack pointer value to its original before starting the function call

* jr ra
jump back to the return address


## 2x2 matrix multiplier

*refer to matrix_multiplication.asm for the assembly code*

#Need more time to understand this assembly code. Will leave it for now and move on to next week assignment#



