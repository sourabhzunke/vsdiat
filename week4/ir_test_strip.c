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

// GPIO bits
const int TRUE = 1;
const int FALSE = 0;


int main(){

int IR_input;
int light_state;
u_int8_t count;
u_int8_t seconds = 1;



IR_input = 0;
count = 0;
light_state = 0;


/*Read the IR input at x30[31]*/
int read_IR_input()
{
 int input;
 int mask = 0x7FFFFFFE;
 // using x30[31] bit for reading the input of the IR sensor
 asm volatile("and x30, x30, %1\n\t"	//%1 is the mask value: 2nd variable
	      "srli x10 ,x30 ,31\n\t"	
	      "andi %0, x10, 1\n\t "	//%0 is the input value: 1st variable
	      : "=r"(input)
	      : "r" (mask)
	      : "x10");
 return input;
}


/* Set the Light status at x30[0]			*/
/* This is a toggle function, the light state will be 	*/
/* toggled everytime this function is called        	*/

void sw_light(int GPIO)
{
 int mask_GPIO = GPIO & 0x1;
 int mask = 0xFFFFFFFE;
 asm volatile("and x30, x30, %1\n\t"  // mask the 0th bit, to set the bit 0 ready for light status
	      "or x30, x30, %0\n\t"  // Logical XOR the x30 register with GPIO (%0). If 0 set to 1 or otherwise.
	      :
	      :"r"(mask_GPIO),"r"(mask)
	      :"x30");     
}



//while loop for continuous operation 	
while(1){
	/*
	 * The operator has to wave the hand over the IR sensor for some time so as 
	 * the IR sensor is not activated by a random noise or spurious reading of 
	 * the sensor. Here the IR_input has to be continuously high for count of 32,
	 * otherwise the count will reset to 0 and the IR input count has to resume 
	 * from 0. 
	 * */

	IR_input = read_IR_input();
	if(IR_input==TRUE){
		count++;
		if(count >= 32){
			count = 0;
			light_state = !light_state & 0x1;

			sw_light(light_state);

			// Delay to avoid excessive button readings
   			 for (i = 0; i < seconds * 1000000; i++) {
      				asm volatile("nop");
    			}
		}
	}
	else
	       count = 0;	
		
}

return 0;
}
