/*
Author: Dean Willavoys
ID: 105003751
Date: 2/12/19
Purpose: Understanding and manipulating character arrays
*/

#include<stdio.h>


/*
Reverse: Reverses the contents of the passed character array
Input: A character array
Output: Doesn't return or print, changes the elements of an array
*/
void Reverse(char array[]);
void Reverse(char array[]){
	int size = 0; //Tracks number of elments in array
	int i; //Iterator for for loop
	char temp; //Temporary storage for swapping

	while(array[size] != '\0'){ //Exits when null character is reached
		size++; //Increments num of elements in char array
	}
	int end = size - 1; //Index of last element of array, disregarding null
	
	for(i = 0; i < end; i++, end--){ //Converges on array from both sides, swapping values
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
	}
	
}


/*
RecursiveReverse: Reverses the contents of the passed character array, recursively
Input: A character array, an integer for current index value of array, an integer for the end index of an array
Output: Doesn't return or print, changes the elements of an array
*/
void RecursiveReverse(char array[], int index, int end);
void RecursiveReverse(char array[], int index, int end){
	int temp; //Temporary variable for swapping
	if(index >= end){ //If string has been exhausted on both ends, return as reverse is complete
		return;
	}
	else{ //Recursive step
		temp = array[index]; //Swaps the current index and end value
 		array[index] = array[end];
		array[end] = temp;
		return RecursiveReverse(array, index + 1, end - 1); //Increases the index value and decreases the end value
	}	
}



int main(){
	char Buffer1[] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'}; //Initialization of character array
	char Buffer2[] = "this is the second buffer"; //Initialization of character array using second method			   using first method
	char Buffer3[80]; //Decleration of third character array, has arbitrary large size for the sake of having room
	char *pBuffer = Buffer3; //Pointer to Buffer3
	char revArray[80]; //Decleration of array to reverse later
	int count = 0; //Counter for the size of a character array


	printf("Enter buffer 3: "); //Prompts user
	scanf("%s", &Buffer3); //Assigns third char array according to user input

	printf("%s\n%s\n%s\n", Buffer1, Buffer2, Buffer3); //Output of all 3 character arrays

	
	while(*pBuffer != '\0'){ //Exits when null character is reached
		printf("%c", *pBuffer); //Prints the current character in the array
		pBuffer++; //Moves the memory location forward
	}
	printf("\nEnter a string to reverse: ");
	scanf("%s", &revArray); //Prompts for a string to reverse from user

	printf("%s\n", revArray); //Outputs the string normally
	Reverse(revArray); //Reverses the string
	printf("%s\n", revArray); //Outputs the string reversed

	printf("Enter a string to reverse: ");
	scanf("%s", &revArray); //Prompts for a string to reverse from user


	while(revArray[count] != '\0'){ //Exits when null character is reached
		count++; //Increases counter
	}
	count--; //Subtract one for null character

	printf("%s\n", revArray); //Outputs the string normally
	RecursiveReverse(revArray, 0, count); //Reverses the string using recursion
	printf("%s\n", revArray); //Outputs the string reversed



	
	return 0;
}
