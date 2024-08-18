#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int n) {
    int us = n; // microseconds
    clock_t start_time = clock();
    while (clock() < start_time + (us * CLOCKS_PER_SEC / 1000000));
}


typedef enum { false, true } bool;

int main(){

bool IR_input;
bool light_state;
u_int8_t count;


IR_input = false;
count = 0;
light_state = false;

//while loop for continuous operation 	
while(1){
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
			delay(1000000000);   // delay by 1 second
		}
	}
	else
	       count = 0;	
		
}

return 0;
}
