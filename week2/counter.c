#include<time.h>
void delay(int n) {
    int us = n; // microseconds
    clock_t start_time = clock();
    while (clock() < start_time + (us * CLOCKS_PER_SEC / 1000000));
}

void display(int count) // Function to display the data on the four Led's
{
}

int main()
{
	int count = 0x00000000;
	while (1)
	{
		display(count);
		count++;
        if(count==16){
            count=0;
        }
		delay(500000);   // delay by 0.5 microseconds
	}
}
