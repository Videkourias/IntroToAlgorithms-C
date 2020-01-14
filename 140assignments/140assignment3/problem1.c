/*
Author: Dean Willavoys
Date: 10/29/18
Purpose: Calculates gross earnings
*/
#include<stdio.h>

int main(void){
	float sales, comission, gross;
	const float BASE = 200;
	while(1){
		printf("Enter sales in dollars (-1 to end): "); //Gets amount in sales from user
		scanf("%f", &sales);
		
		if (sales == -1) break; //Sets break condition
			
		comission = (sales * 0.09); //Calculates sales comission and adds it to gross earnings
		
		gross = comission + BASE;
		printf("Salary is: $%.2f\n", gross); //Outputs gross earnings
		
	}
	
	
	return 0;
}