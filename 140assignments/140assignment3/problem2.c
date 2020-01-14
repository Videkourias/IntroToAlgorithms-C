/*
Author: Dean Willavoys
Date: 10/29/18
Purpose: Calculates pi from infinite series
*/
#include<stdio.h>

int main(void){
	/*
	float pi = 4, divisor;//Declares variables
	int counter = 1, i;
	printf("1.\tpi = 4\n");
	divisor = 3; //Variable divisor used in infinite series
		for(i=1; i<148478; i++){
			if (counter % 2 == 0) //If statment creates effect where pi is added to every other iteration
				printf("%d.\tpi = %f\n",counter + 1, pi += (4/divisor));
			else
				printf("%d.\tpi = %f\n",counter + 1, pi -= (4/divisor));
			counter++;
			divisor += 2; //Divisor increases to make pi more percise
	}
	*/
	printf("How many terms of computation of pi you need: 150000\n"); //Outputs answer to questions given
	printf("3.14 = 628 terms\n");
	printf("3.141 = 1694 terms\n");
	printf("3.1415 = 10126 terms\n");
	printf("3.14159 = 148472 terms\n");
	printf("Note: The code used to calculate these terms is still present in\n");
	printf("this file, just needs to be uncommented for use.");
	
	
	return 0;
}
