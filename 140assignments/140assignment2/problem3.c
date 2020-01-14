/*
Author: Dean Willavoys
Date: 10/06/18
Purpose: Determines whether or not 3 integers can form the sides of a triangle and if that triangle is a right triangle
*/
#include <stdio.h>

int main(void){
	int a, b, c, triangle, right;
	int sqa, sqb, sqc;
	printf("Enter 3 integers: "); //Gets 3 integers to test
	scanf("%d %d %d", &a, &b, &c);



//Determines if a,b,c form triangle	
	if((((a + b) > c) && (((a - b) < c) && (-(a - b) < c)))){ //Calculates if sum of 2 sides is greater than third side
		triangle = 1;										      //and if difference of 2 sides is less then third side
	}
	else if((((a + c) > b) && (((a - c) < b) && (-(a - c) < b)))){
		triangle = 1;
	}
	else if((((b + c) > a) && (((b - c) < a) && (-(b - c) < a)))){
		triangle = 1;
	}
	else
	    triangle = 0;
	
//Determines if right triangle
	if(triangle){
		sqa = a * a; //Defines the squared values of a, b, and c
		sqb = b * b;
		sqc = c * c;
		if(((sqa + sqb) == sqc) || ((sqa + sqc) == sqb) || ((sqb + sqc) == sqa)) //Determines if Pythagorean theorem holds
			right = 1;
	else
	    right = 0;
	}

	
//Output for user
	if(triangle && right){
		printf("\n%d, %d, and %d can represent the sides of a triangle.\n", a, b, c); //Prints if 3 sides form triangle
		printf("%d, %d, and %d can represent a right triangle.", a, b, c); //and can also be a right triangle
	}
	else if(triangle){
		printf("\n%d, %d, and %d can represent the sides of a triangle.\n", a, b, c); //Prints if 3 sides form triangle
		printf("%d, %d, and %d can not represent a right triangle.", a, b, c); //but not a right triangle
	}
	else{
		printf("\n%d, %d, and %d can not represent the sides of a triangle.", a, b, c); //Prints if 3 sides don't form triangle
	}	

	return 0;
}
		

		
		