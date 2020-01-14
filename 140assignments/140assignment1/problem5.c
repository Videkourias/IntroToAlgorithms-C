/*
Author: Dean Willavoys
Date: 09/29/18
Purpose: Gets length and width of room, provides square footage and cost of tiles.
*/
#include<stdio.h>

int main(void){
	float length, width, cost;
	
	printf("Enter the length of the room: "); //Gets proportions of room and cost
	scanf("%f", &length);
	
	printf("Enter the width of the room: "); 
	scanf("%f", &width);
	
	printf("Enter the cost per square foot of tile: ");
	scanf("%f", &cost);
	
	float area = width * length, costTot; //Calculates size of room and cost for tile
	costTot = area * cost;
	
	printf("The total cost for a room of %.2f sq. ft is $%.2f", area, costTot); //Outputs size and cost
	
	
	return 0;
}