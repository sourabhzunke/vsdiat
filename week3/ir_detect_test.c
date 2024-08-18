#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Mock function to simulate delay
void delay(int dummy) {
    // Do nothing (or optionally, implement a real delay for embedded systems)
}

int main(){

    bool IR_input;
    bool light_state;
    uint8_t count;

    IR_input = false;
    count = 0;
    light_state = false;

    // Simulate a fixed number of iterations for testing
    for (int i = 0; i < 1000; i++) {
//        if (i == 5 || i == 20 || i == 40) {
//            IR_input = true; // Simulate IR input at specific iterations
//        } else {
//            IR_input = false;
//        }
//
	if((i%50) == 0 || 
	   (i>50 && ((i-33)%50 >=18) && ((i-33)%50 <= 49) ))
		IR_input = true;
	else
		IR_input = false;

        if(IR_input == true){
            count++;
            if(count >= 32){
                count = 0;
                if(light_state == true){
                    light_state = false;
                    printf("Iteration %d: light switched OFF\n", i);
                }
                else{
                    light_state = true;
                    printf("Iteration %d: light switched ON\n", i);
                }
                delay(1000000000);   // delay by 1 second (mocked)
            }
        }
        else {
            count = 0;
        }
    }

    return 0;
}

