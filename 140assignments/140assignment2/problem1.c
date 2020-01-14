/*
Author: Dean Willavoys
Date: 10/06/18
Purpose: To determine whether an integer is even or odd
*/
#include<stdio.h>

int main(void){
	int var;
	printf("Enter an integer: "); //Gets integer
	scanf("%d", &var);
	
	if ((var % 2) == 0) //Determines whether integer is odd or even and the prints the outcome
		printf("%d is an even integer", var);
	else
		printf("%d is an odd integer", var);

	return 0;
}