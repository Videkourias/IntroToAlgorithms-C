/*
Author: Dean Willavoys
Date: 10/06/18
Purpose: Determines how many digits a number has
*/
#include <stdio.h>

int main(void){
	int number;
	printf("Please enter a positive integer number: "); //Gets positive integer number
	scanf("%d", &number);
	
	if (number>999)
		printf("%d has four or more digits", number);
	else
		if (number>99)
		    printf("%d has three digits", number);
		else
			if (number>9)
				printf("%d has two digits", number);
			else
				printf("%d has one digit", number);
			
			
	printf("\nGood bye...!");
	

	return 0;
}