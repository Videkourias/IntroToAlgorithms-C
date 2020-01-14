/*
Author: Dean Willavoys
Date: 09/29/18
Purpose: Provides sum, product, difference, quotient, and remainder of 2 inputed numbers
*/
#include <stdio.h>

int main(void){
	int num1, num2;
	printf("Input 2 numbers: "); //Gets integers from user
	scanf("%d %d", &num1, &num2);
	
	printf("\nThe sum is: %d", num1 + num2); //Performs and prints operations
	printf("\nThe product is: %d", num1 * num2);
	printf("\nThe difference is: %d", num1 - num2);
	printf("\nThe quotient is: %d", num1 / num2);
	printf("\nThe remainder is: %d", num1 % num2);
	return 0;
}