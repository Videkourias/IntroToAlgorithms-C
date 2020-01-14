/*
Author: Dean Willavoys
Date: 10/02/18
Purpose: To convert coin quantity into dollar value
*/
#include <stdio.h>

int main(void){
	int quarter, dime, nickle, penny, cent, dollar;
	printf("Tell me how many quarters, dimes, nickles, and pennies you have. \nI will tell you how many dollars and cents are in your pocket"); //Description of program
	
	printf("\nNumber of quarters: "); //Gets number of coins 
	scanf("%d", &quarter);  
	
	printf("Number of dimes: "); 
	scanf("%d", &dime);
	
	printf("Number of nickles: "); 
	scanf("%d", &nickle);
	
	printf("Number of pennies: "); 
	scanf("%d", &penny);
	
	cent = (quarter * 25) + (dime * 10) + (nickle * 5) + penny; //Determines cent value of coins
	dollar = (cent - cent % 100) /100; //Determines dollar value based on cents	
	cent = cent % 100; //Determines left over cent value
	
	printf("You have %d dollars and %d cents in your pocket", dollar, cent); //Outputs dollar and cent value to user
	return 0;
}