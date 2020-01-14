/*
Author: Dean Willavoys
Date: 10/06/18
Purpose: Prints largest and smallest integers of 3 entered
*/
#include<stdio.h>

int main(void){
	int num1, num2, num3, largest, smallest;
	printf("Enter 3 integers: "); //Gets 3 integers
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if(num1 > num2 && num1 > num3){ // Determines the largest and smallest integers
		largest = num1;
		if(num2 > num3){
			smallest = num3;
		}
		else
			smallest = num2;
	}
	else if (num1 > num2 && num1 < num3){
	    largest = num3;
		smallest = num2;
	}
	else if (num1 < num2 && num1 > num3){
		largest = num2;
		smallest = num3;
	}
	else if (num1 < num2 && num1 < num3){
		smallest = num1;
		if (num2>num3){
			largest = num2;
		}
		else
			largest = num3;
	}
	
	printf("The largest number is: %d\nThe smallest number is: %d", largest, smallest); //Prints largest and smallest
		

	return 0;
}