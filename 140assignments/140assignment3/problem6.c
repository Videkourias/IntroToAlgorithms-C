/*
Author: Dean Willavoys
Date: 10/31/18
Purpose: Finds factorials of numbers up to 10, and then from 15 to 20
*/
#include<stdio.h>

int main(void){
	int i, j, factorial;
	
	
	for (i = 1;i <= 10; i++){ //Outer loop, dictates what number were finding factorial of
		factorial = 1;
		for (j = 1; j<= i;j++) //Inner loop, dictates how many numbers should be multiplied successively
			factorial *= j;
		printf("%d! = %d\n", i, factorial); //Prints the number i and its factorial
	}
	
	
	printf("\n\n-----------\n\n\n");
	
	for (i = 15;i <= 20; i++){ //Outer loop, dictates what number were finding factorial of
		factorial = 1;
		for (j = 1; j<= i;j++) //Inner loop, dictates how many numbers should be multiplied successively
			factorial *= j;
		printf("%d! = %d\n", i, factorial); //Prints the number i and its factorial
	}
	
	
	printf("\n\nA problem occurs when we try to calculate the factorial of large numbers like 15-20\n"); //Explanation of difficulty of finding numbers like 20!
	printf("becuase of the type of integer that is used. A regular integer does not have\n");
    printf("the necessary range to hold numbers as large as 15! to 20!, whereas a long long int would.");
	return 0;
}