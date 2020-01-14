/*
Author: Dean Willavoys
ID: 105003751
Date: 02/03/19
Purpose: Help practice working with pointers
*/
#include<stdio.h>

int main(){
	int a = 7;
	int *aPtr;
	aPtr = &a;

	//This statement will print the value of a, 7
	printf("stat 01: %d \n", a);

	//This statement will print the location of a in memory
	printf("stat 02: %p \n", &a);

	//This statement will print the location of a in memory
	printf("stat 03: %p \n", aPtr);

	//This statement will print the location of aPtr in memory
	printf("stat 04: %p \n", &aPtr);

	//This statement will print the value of a, 7
	printf("stat 05: %d \n", a);

	//This statement will print the value of a, 7
	printf("stat 06: %d \n", *aPtr);

	//This statement will print the location of a in memory
	printf("stat 07: %p \n", *&aPtr);

	//This statement will print the location of a in memory
	printf("stat 08: %p \n", &*aPtr);

	//This statement will print the value of a, 7
	printf("stat 09: %d \n", *&a);


	return 0;
}
