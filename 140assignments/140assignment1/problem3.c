/*
Author: Dean Willavoys
Date: 10/01/18
Purpose: To take a 5 digit number and output the sum of its digits
*/
#include <stdio.h>

int main(void){
	int num1, num2, num3, num4, num5, tot;
	printf("Enter a 5 digit number: ");
	scanf("%1d%1d%1d%1d%1d", &num1, &num2, &num3, &num4, &num5); //Gets 5 digit number from user
	
	tot = num1 + num2 + num3 + num4 + num5; //Calculates sum of digits
	
	printf("%d + %d + %d + %d + %d = %d", num1, num2, num3, num4, num5, tot); //Outputs sum of digits
	return 0;
}