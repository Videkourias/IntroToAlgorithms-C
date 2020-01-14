/*
Author: Dean Willavoys
ID: 105003751
Date: 1/29/19
Purpose: To create and test various 2d array manipulating functions
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COL 20
#define ROW 20



/*
LinearSearch: Uses exhaustive method to find if integer key is in passed array
Input: An integer array, a size for that array, a key to search for
Output: An integer 0 for success(found), 1 for failure(not found)
*/
int LinearSearch(int array[], int size, int key);
int LinearSearch(int array[], int size, int key){
	int i; //Iterator for for loop

	for(i = 0; i < size; i++){
		if(array[i] == key) return 0; //Case for key found in array
	}
	return 1; //Case for key not found
}



/*
PopulateArray2DUnique: Populates the 2D Array of size rowsize x colsize with unique random integers ranging between min and max inclusive.
Input: A 2d integer array, 2 positive integers for row size and column size of that array, and 2 integers for the minimum random value and the maximum random value respectively
Output: Doesn't print or return, changes the values of the passed array
*/
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max){
	int i; //Iterators for for loops
	int j;	
	srand(time(NULL)); //Seeds randint based on current time
	int used[rowsize * colsize]; //A 1d array keeping track of used values
	int index = 0; //Current index in used array
	int num; //Random number



	for(i = 0; i < rowsize * colsize; i++){
		used[i] = min - 1; //Populates array with integers that won't be generated later
	}



	for(i = 0; i < rowsize; i++){ //Loops through rows
		for(j = 0; j < colsize; j++){ //Loops through columns
			num =  min + (rand() % (max - min + 1)); //Chooses random number
			if(LinearSearch(used, rowsize * colsize, num)){ //Case for number not having been used before
				A[i][j] = num; //Assigns current element in A to that num
				used[index] = num; //Adds num to the used num array
				index++; //Moves to the next element of the used array
			}
			else{ //Number seen before
				j--; //In case num is invalid/ not unique, element is not skipped
			}
		}
	}
}



/*
DisplayArray2D: Display the contents of a 2d array of size rowsize x colsize in a table format; that is each line will display one row where the numbers are separated by a single space character.
Input: A 2d integer array, 2 unsigned integers that represent the row and column size of that same 2d integer
Output: Prints the 2d array in tabular format
*/
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize);
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize){
	int i; //Iterators for for loops
	int j;
	for(i = 0; i < rowsize; i++){ //Loops through rows
		for(j = 0; j < colsize; j++){ //Loops through columns
			printf("%d ", A[i][j]); //Prints element i,j of the entered array
		}
		printf("\n"); //New line for new row
	}
}



/*
FindLargest: Given a 2d array A of rowsize x colsize, return the largest integer number it contains
Input: A 2d integer array, 2 unsigned integers that represent the row and column size of that same 2d array
Output: Returns the largest element in the array
*/
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize){
	int i; //Iterators for for loops
	int j;
	int largest = A[0][0]; //Starts with first integer as largest
	for(i = 0; i < rowsize; i++){ //Loops through rows
		for(j = 0; j < colsize; j++){ //Loops through columns
			if(largest < A[i][j]){ //Checks if current number is larger than current largest
				largest = A[i][j]; //Exchanges if it is larger
			}
		}
	}
	return largest; //Returns largest integer
}



/*
FindColSum: Calculate the sum of a given column of a 2d array of size rowsize x colsize
Input: A 2d integer array, two unsigned integers for the row size and column size of that array, an unsigned int for which column to sum(colsize - 1 at most)
Output: Returns the sum of the chosen column 
*/
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum){
	int i; //Iterator for for loop
	int sum = 0; //Sum of the column

	for(i = 0; i < rowsize; i++){ //Cycles through all elements of specified columns
		sum += A[i][col_to_sum]; //Adds each entry to the sum
	}
	return sum; //Returns the calculated
}



/*
sort: Sorts a 1d array from smallest to largest using selection sort
Input: A positive integer order(the size of the array), and a 1d integer array
Output: Doesn't output, just edits an existing array
*/
void sort(unsigned int len, int A[]);
void sort(unsigned int len, int A[]){
	int i; //Iterators / index values
	int j;
	int k; //Minimum index value
	int temp; //Temp variable for swapping
	
	for(i = 0; i < len - 1; i++){ //Loops through first to 2nd last element
		k = i; //k starts at first element in current array		
		for(j = i + 1; j < len; j++){ //Cycles through remaining elements
			if(A[j] < A[k]){
				k = j; //Gives k the value of smallest element
			}
		}
		
		temp = A[i]; //Swaps element i with the lowest value element found, k
		A[i] = A[k];
		A[k] = temp;
	}
}



/*
Sort2DArray: Sort a 2d array of size colsize x rowsize in ascending order(order = 1) or descending order(order = 2)
Input: A 2d integer array, 2 unsigned integers for the row and column size of that array, an integer for order(only 1 or 2)
Output: Returns integer, 0 for success
*/
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order){
	int i; //Iterators for for loops
	int j;
	int oneD[rowsize * colsize]; //1d integer array for all values from passed 2d array
	int index = 0; //Current position in oneD
	for(i = 0; i < rowsize; i++){
		for(j = 0; j < colsize; j++){
			oneD[index] = A[i][j]; //Assigns every value of A to a 1d matrix
			index++; //Increments current index in oneD
		}
	}
	sort(rowsize * colsize, oneD); //Sorts 1d array

	if(order == 1){ //Case for ascending sort
		index = 0; //Resets index value
		for(i = 0; i < rowsize; i++){ 
			for(j = 0; j < colsize; j++){ 
				A[i][j] = oneD[index]; //Assigns array A to values from sorted oneD in ascending order
				index++; //Increments index value in oneD			
			}
		}
	}
	else{ //Case for descending sort
		index--; //Lowers index by one as previous for loop would put index out of range of oneD
		for(i = 0; i < rowsize; i++){ 
			for(j = 0; j < colsize; j++){ 
				A[i][j] = oneD[index]; //Assigns array A to values from sorted oneD in descending order
				index--; //Decrements index value in oneD
			}
		}
	}
	return 0; //Successful execution
}



/*
CopyArray2D: Copies the contents of array A into array B of the same size such that the contents of B are exactly the same as A
Input: Two 2d integer arrays of matching size, two unsigned integers for the row and column size of those arrays
Output: Returns integer, 0 for success
*/
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize){
	int i; //Iterators for for loops
	int j;
	
	for(i = 0; i < rowsize; i++){
		for(j = 0; j < colsize; j++){
			B[i][j] = A[i][j]; //Copies every value from A to B, preserving their position in the array
		}
	}
	return 0; //Successful execution
}



/*
CopyArray2DSpiral: Copies the contents of array A into array B of the same size such that the contents of B are the contents of A in sorted clockwise spiral order
Input: Two 2d integer arrays of matching size, two unsigned integers for the row and column size of those arrays
Output: Returns integer, 0 for success
*/
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize){
	int i; //Iterators for for loops
	int j;
	int currRow = 0; //Start position for row looping
	int currCol = 0; //Start position for col looping
	int spiral[rowsize * colsize]; //A 1d array of all elements of A in sorted order
	int index = 0; //An index value

	for(i = 0; i < rowsize; i++){
		for(j = 0; j < colsize; j++){
			spiral[index] = A[i][j]; //Fills array with elements in sorted order
			index++;
		}
	}

	index = 0; //Resets index value for re-use


	while(currRow < rowsize && currCol < colsize){ //Will only run when the array is not depleted of values(row size has not been reached or col size has not been reached)
		//HORIZONTAL RIGHT FILLING	
		for(i = currCol; i < colsize; i++){ //From leftmost column of current array to rightmost column of current array
			B[currRow][i] = spiral[index]; //Copies elements from spiral onto horizontal component of B
			index++;
		}
		currRow++; //Shrinks array/matrix vertically(from top)
	

 
		//VERTICAL DOWN FILLING
		for(i = currRow; i < rowsize; i++){ //From lowest row of current array to highest row of current array
			B[i][colsize - 1] = spiral[index]; //Copies elements from spiral onto a vertical component of B
			index++;
		}
		colsize--; //Shrinks array/matrix horizontally(from right)



		//HORIZONTAL LEFT FILLING
		if(currRow < rowsize){ //Only executes if the lowest row in current array is less than the highest row(ie. wouldn't run if rows were depleted) 	
			for(i = colsize - 1; i >= currCol; i--){ //From leftmost column of current array to rightmost column of current array
				B[rowsize - 1][i] = spiral[index]; //Copies elements from spiral onto a horizontal component of B
				index++;
			}
			rowsize--; //Shrinks array/matrix vertically(from bottom)
		}



		//VERTICAL UP FILLING
		if(currCol < colsize){  //Only executes if the lowest column in current array is less than the highest column(ie. wouldn't run if columns were depleted)
			for(i = rowsize - 1; i >= currRow; i--){ //From lowest row of current array to highest row of current array
				B[i][currCol] = spiral[index]; //Copies elements from spiral onto a vertical component of B
				index++;
			}
			currCol++; //Shrinks array/matrix horizontally(from left)
		}

	}
	return 0; //Successful array execution
}


int main(){
	int array[ROW][COL]; //Declares an array of max size
	int arrayCopy[ROW][COL]; //Array for copying to later
	int arraySpiral[ROW][COL]; //Array for copying spiral sort to later
	unsigned int rowsize; //unsigned integers for row and column size
	unsigned int colsize;
	int min; //Declares minimum and maximum values for array population function
	int max;
	unsigned int col; //Column chosen to sum
	int order; //Order for sorting

	do{ //Gets a user entered row size and column size, ensures it's within bounds
		printf("Testing an array of size: ");
		scanf("%u x %u", &rowsize, &colsize);
	}
	while(rowsize > 20 || colsize > 20); //Has to be less than 20


	printf("Populate Array with unique random integers between "); //Gets a min and max value from user
	scanf("%d%d", &min, &max);


	PopulateArray2DUnique(array, rowsize, colsize, min, max); //Populates array with random numbers between min and max

	
	printf("DisplayArray2D: \n");
	DisplayArray2D(array, rowsize, colsize); //Displays the populated array


	printf("FindLargest: %d\n", FindLargest(array, rowsize, colsize)); //Finds and prints largest integer in array


	printf("Column to sum: "); //Gets which column user wants to sum
	scanf("%u", &col);

	
	printf("FindColSum of col %d: %d\n", col, FindColSum(array, rowsize, colsize, col)); //Calculates and prints column col


	printf("Enter order of sorting: "); //Gets order of sort from user
	scanf("%d", &order);	

	
	Sort2DArray(array, rowsize, colsize, order); //Sorts the 2d array
	printf("Sort2DArray order %d followed by DisplayArray2D: \n", order);
	DisplayArray2D(array, rowsize, colsize); //Displays the sorted array


	CopyArray2D(array, arrayCopy, rowsize, colsize); //Copies contents of array to arrayCopy
	printf("CopyArray2D from A to B, then Display B:\n");
	DisplayArray2D(arrayCopy, rowsize, colsize); //Prints the array copy 



	CopyArray2DSpiral(array, arraySpiral, rowsize, colsize); //Copies contents of array to a spiraled version
	printf("CopyArray2DSpiral from A to B, then Display B:\n");
	DisplayArray2D(arraySpiral, rowsize, colsize); //Prints the spiraled copy



	return 0;
}
