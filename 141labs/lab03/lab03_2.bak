/*
Author: Dean Willavoys
ID: 105003751
Date: 02/03/19
Purpose: To help practice working with pointers
*/

#include<stdio.h>

int main(){
	float b = 3.7f;
	float * bPtr;

	//This statement will print the value of b, 3.700000
	printf("stat 01: value of b = %f \n", b);

	//This statement will print the unsigned int presentation of the adress
	//that bPtr is pointing at in memory(0 as it points at nothing)
	printf("stat 02: %u \n", bPtr);

	//let bPtr point to the address of variable b in memory
	bPtr = &b;

	//Write down the value you will get from this print statement, call it var1 
	printf("stat 03: %u \n", bPtr); //Gives memory adress of b in integer form

	//this statement will print the memory address of b in integer form
	printf("stat 04: %u \n", &b); 

	printf("stat 05: currently bPtr stores the address of variable b which is %u in unsigned int format or %p in hexadecimal format \n", bPtr, bPtr); //Will print the same integer as before along with its hexadecimal equivalent

	//this statement will print the size of a float variable in memory, 4 bytes
	printf("stat 06: the size of b in memory is %d \n", sizeof(b));


	//this statement is going to increment the address stored in bPtr
	bPtr++;

	//Write down the value you will get from this print statement, call it var2
	printf("stat 07: %u \n", bPtr); //Will print the previous integer memory address plus four


	//Q3: var2 - var1 is the difference between one memory address and the address before it, given that the previous address is for a float of size 4 btyes, then difference between var2 and var1 is 4 bytes
	//as represented by the address' integer values having a difference of 4

	return 0;
}
