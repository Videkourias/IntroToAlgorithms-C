/*
Author: Dean Willavoys
Date: 10/31/18
Purpose: Finds the average a series of numbers
*/
#include<stdio.h>

int main(void){
	int num, cardinal = 0;
	float tot = 0;
	
	while(1){ //Gets integer from user and adds it to sum until '9999' is entered
		printf("Enter an integer: ");
		scanf("%d",&num);
		if (num == 9999)
			break;
		else{
			tot += num;
			cardinal++; //Keeps track of how many numbers were entered
			continue;
		}
	}	
	printf("The average is %.2f", tot/cardinal); //Calculates average from sum and cardinality
	return 0;
}