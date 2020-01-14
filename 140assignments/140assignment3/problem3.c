/*
Author: Dean Willavoys
Date: 10/30/18
Purpose: Draw diamonds
*/
#include<stdio.h>

int main(void){
int height,space,star, i ,j,k; //Declares variable for height of star, space before first star appears in a line, and 3 iterators

while(1){
	printf("Enter a height value(terminate with -1): "); //Gets height value from user
	scanf("%d",&height);
	if ((height % 2 == 0) || (height > 20))
		continue; //Verifies that entered height is an acceptable value
	else if(height==-1) //Creates break condition
		break;
	
	
	space = height/2; //Sets the initial number of spaces
	
	
	for (i = 1; i <= (height/2) + 1; i++){ //Iterates through the rows, from top to middle
		for(j = 1; j <= space; j++) //Produces a number of spaces based on space value
			printf(" ");
		for(k = 1; k <= (2 * i - 1); k++) //Produces a number of stars based on what row(i) is being printed to
			printf("*");
		space -= 1; //Reduces number of spaces and creates new line for next row
		printf("\n");
	}
	
	space = 0; //Starts from middle of star with no sace
	star = height - 2; //Number of stars one row after the centermost row
	for (i = 1; i <= height/2; i++){ //Iterates through final half of height
		for(j = 0; j <= space;j++) //Same as previous block, creates space and star based on current row, space and star are then increased
			printf(" ");
		for(k = 1; k <= star;k++)
			printf("*");
		printf("\n");
		space +=1;
		star -=2;
	}
}
	return 0;
}