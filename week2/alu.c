#include<stdio.h>

int main(){
	u_int8_t num1, num2, choice, result;
	u_int8_t cin,cout; /*for addition and substraction*/
	//printf("4-bit ALU\n");
	//printf("Choose the operation:\n");
	//printf("1. Addition\n2. Substraction\n3. Logical AND\n4. Logical OR\n5. Negation\n");
	//scanf("%hhd",&choice);
	//printf("Enter the 4-bit numbers( 0<=n<16) , num1, num2- \n");
	//scanf("%hhd,%hhd",&num1,&num2);
	if(num1>15 || num2>15){
		//printf("Only 4-bits will be read\n");
		num1 &= 0x0f;
		num2 &= 0x0f;
	}

	switch(choice){
		case 1: {
				//printf("Enter the Carry-in bit- ");
				//scanf("%hhd",&cin);
				cin = cin & 0x01;
				result = num1 + num2 + cin;
				cout = result & 0x10;
				cout = cout>>4; 
				result = result & 0x0f;
				//printf("Carry Out: %hhd\n",cout);
			}
				break;
		case 2: {
				result = num1 - num2;
				if(num1>=num2)
					cout = 1; /*no borrow bit*/
				else
					cout = 0;
				//printf("Carry Out: %hhd\n",cout);
			}
			break;
		case 3: result = num1 &  num2;
			break;
		case 4: result = num1 | num2;
			break;
		case 5: {
				result = ~num1;
				result = result & 0x0f;
			}
			break;
		default: //printf("Incorrect choice. Exit!!!\n");
			 //exit(0);
			 break;
	}
	//printf("num1: %hhd, num2: %hhd \nResult=%hhd",num1,num2,result);
	return 0;
}
