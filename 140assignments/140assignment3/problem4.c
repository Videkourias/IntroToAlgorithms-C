/*
Author: Dean Willavoys
Date: 10/31/18
Purpose: Sums a series of numbers
*/
#include<stdio.h>

int main(void){
	int numInit, counter = 1;
	float num, sum = 0;
	
	printf("Enter total number of values: "); //Gets initial value from user
	scanf("%d", &numInit);
	
	while(counter <= numInit){ //Asks for number from user and adds it to sum until counter reaches the initial number
		printf("Enter number: ");
		scanf("%f", &num);
		sum += num;
		counter++;
	}
	printf("The sum is: %.2f", sum); //Prints sum

	return 0;
}