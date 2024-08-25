#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int n) {
    int us = n; // microseconds
    clock_t start_time = clock();
    while (clock() < start_time + (us * CLOCKS_PER_SEC / 1000000));
}

// bool enum
// false = 0
// true = 1
typedef enum { false, true } bool;

int main(){

bool IR_input;
bool light_state;
u_int8_t count;
u_int8_t seconds = 1;


IR_input = false;
count = 0;
light_state = false;


//while loop for continuous operation 	
while(1){
	/*
	 * The operator has to wave the hand over the IR sensor for some time so as 
	 * the IR sensor is not activated by a random noise or spurious reading of 
	 * the sensor. Here the IR_input has to be continuously high for count of 32,
	 * otherwise the count will reset to 0 and the IR input count has to resume 
	 * from 0. 
	 * */
	if(IR_input==true){
		count++;
		if(count >= 32){
			count = 0;
			if(light_state == true){
				light_state = false;
				printf("light switched OFF\n");
			}
			else{
				light_state = true;
				printf("light switched ON\n");
			}
			//delay(1000000000);   // delay by 1 second

			// Delay to avoid excessive button readings
   			 for (int i = 0; i < seconds * 1000000; i++) {
      				asm volatile("nop");
    			}
		}
	}
	else
	       count = 0;	
		
}

return 0;
}
