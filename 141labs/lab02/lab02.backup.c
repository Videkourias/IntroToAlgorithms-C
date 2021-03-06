
/*
	Author: Dean Willavoys
	ID: 105003751
	Date: 01/22/19
	Purpose: To practice working with arrays and mainly focus on 2D arrays
*/

#include <stdio.h>
#define MAX 100
#define DEBUG 0



/*
setMatrixData: Sets the values of a 2d array
Input: A positive integer value for the order of a matrix and a 2d integer array(a matrix with that order)
Output: Edits the values of the entered array, no print or return occurs
*/
void setMatrixData(unsigned int order, int mat[][order]);
void setMatrixData(unsigned int order, int mat[][order]){
   	int i; //Iterators for for loops
	int j;
	int userValue = 0; //Integer for user value
	for(i = 0; i < order; i++){ //Loops through rows
		for(j = 0; j < order; j++){ //Loops through columns
			printf("Enter a value for entry %d,%d of the matrix: ", i + 1, j + 1);  //Gets entry i,j from user
			scanf("%d", &userValue);
			mat[i][j] = userValue; //Assigns entry i,j to user's entry
		}
	}	
}



/*
printMatrixData: Outputs the entries of the entered 2d array in tabular form
Input: A positive integer value for the order of a matrix and a 2d integer array(a matrix with that order)
Output: Prints a table containing the values of the entered array
*/
void printMatrixData(unsigned int order, const int mat[][order]);
void printMatrixData(unsigned int order, const int mat[][order]){
	int i; //Iterators for for loops
	int j;
	for(i = 0; i < order; i++){ //Loops through rows
		for(j = 0; j < order; j++){ //Loops through columns
			printf("\t%d", mat[i][j]); //Prints element i,j of the entered array
		}
		printf("\n"); //New line for new row
	}
}



/*
isMagicSquare: Determines whether or not the entered matrix is a magic square
Input: A positive integer value for the order of a matrix and a 2d integer array(a matrix with that order)
Output: Returns an integer value based on whether or not matrix is magic(0 for false, 1 for true) 
*/
int isMagicSquare(unsigned int order, const int mat[][order]);
int isMagicSquare(unsigned int order, const int mat[][order]){
    int i; //Iterators for for loops
	int j;
	int index = 0; //Current index in the sum array
	long int sum[((order * 2) + 2)]; //Array of sums for each row, column, and diagonal. Number of sums = (order * 2) + 2
	
	int z; //Iterator for debugging loops
	
	//Set sum array's elements to 0
	for(i = 0; i < ((order * 2) + 2); i++){
		sum[i] = 0;
	}
	
	
	//Sum of rows
	for(i = 0; i < order; i++){ //Loops through rows
		for(j = 0; j < order; j++){ //Loops through columns
			sum[index] += mat[i][j]; //Enters the sum of row i in the matrix
		}
		index++; //Moves up to next element in sum array
	}
	
	if(DEBUG){
		for(z = 0; z < 3; z++)
			printf("Line %d has a sum of %ld\n", z, sum[z]); //Prints sums of rows
	}
	
	
	
	//Sum of columns
	for(i = 0; i < order; i++){ //Loops through columns
		for(j = 0; j < order; j++){ //Loops through rows
			sum[index] += mat[i][j]; //Enters the sum of column j in the matrix
		}
		index++; //Moves up to next element in sum array
	}
	
	if(DEBUG){
		for(; z < 6; z++)
			printf("Line %d has a sum of %ld\n", z, sum[z]); //Prints sums of columns
	}
		
	
	//Sum of diagonals
	for(i = 0; i < order; i++){
		sum[index] += mat[i][i]; //Sums top left to bottom right
	}
	
	index++; //Moves to the next element in the sum array

	for(j = order - 1, i = 0; j >= 0; j--, i++){
		sum[index] += mat[i][j]; //Sums top right to bottom left
	}
	
	
	if(DEBUG){
		for(; z < 8; z++)
			printf("Line %d has a sum of %ld\n", z, sum[z]); //Prints sums of diagonals
	}
	
	
	//Sum matching?
	for(i = 1; i < ((order * 2) + 2); i++){
		if(sum[0] != sum[i]){ //Checks if any sum is not equal to the first, if so, not magic square
			return 0;
		}
	}
	
	
    return 1; // if the matrix is a magic square
}



/*
isDistinctSquare: Determines whether or not the entered matrix is distinct square
Input: A positive integer value for the order of a matrix and a 2d integer array(a matrix with that order)
Output: Returns an integer value based on whether or not matrix is distinct(0 for false, 1 for true) 
*/
int isDistinctSquare(unsigned int order, const int mat[][order]);
int isDistinctSquare(unsigned int order, const int mat[][order]){
	int i; //Iterators for for loops
	int j;
	int index = 0; //A current index value
	int nums[order * order]; //A 1d array of size equal to number of elements in the matrix
	

	for(i = 0; i < order; i++){ //For loops loop through 2d array
		for(j = 0; j < order; j++){
			nums[index] = mat[i][j]; //Converts the entered 2d array into a 1d array
			index++; //Increments the current index in 1d array	
		}
	}

	for(i = 0; i < (order * order) - 1; i++){ //Loops from second element to last
		for(j = i + 1; j < order * order; j++){ //Loops though every element after i
				if(nums[i] == nums[j]){ //Compares every element of the matrix with every other value in the matrix
				return 0; //If 2 values match, return 0(false)
			}
		}
	}
	return 1; // if the matrix has no duplicates all values are unique
}



/*
sort: Sorts a 1d array from smallest to largest using selection sort
Input: A positive integer order(the size of the array), and a 1d integer matrix
Output: Doesn't output, just edits an existing array
*/
void sort(unsigned int order, int row[]);
void sort(unsigned int order, int row[]){
	int i; //Iterators / index values
	int j;
	int k;
	int temp; //Temp variable for swapping
	
	for(i = 0; i < order - 1; i++){ //Loops through first to 2nd last element
		k = i; //k starts at first element in array		
		for(j = i + 1; j < order; j++){ //Cycles through remaining elements
			if(row[j] < row[k]){
				k = j; //Gives k the value of smallest element
			}
		}
		
		temp = row[i]; //Swaps element i with the lowest value element found, k
		row[i] = row[k];
		row[k] = temp;
	}
}



/*
sortRowWise: Sorts the square matrix using row-wise approach
Input: A positive integer value for the order of a matrix and a 2d integer array(a matrix with that order)
Output: Doesn't output anything, just sorts the entered matrix
*/
void sortRowWise(unsigned int order, int mat[][order]);
void sortRowWise(unsigned int order, int mat[][order]){
	int i; //Iterators for for loops
	int j;
	int temp[order]; //Temporary array that will facilitate sorting of each row
	for(i = 0; i < order; i++){ //Loops through rows
		for(j = 0; j < order; j++){ //Loops through columns
			temp[j] = mat[i][j]; //Copies one row to temp array
		}

		sort(order, temp); //Passes row contained in temp to a sort function
		
		for(j = 0; j < order; j++){ //Loops through columns
			mat[i][j] = temp[j]; //Copies sorted row ontop of old row	
		}
	}
}



/*
getTranspose: Calculates the transpose matrix for a square matrix
Input: A positive integer value for the order of a matrix and 2 2d integer arrays(matrices with that order)
Output: Edits the values of array tran, doesn't print or return anything
*/
void getTranspose(unsigned int order, const int mat[][order], int tran[][order]);
void getTranspose(unsigned int order, const int mat[][order], int tran[][order]){
    int i; //Iterators for for loops
	int j;
	
	for(i = 0; i < order; i++){ //Loops through rows
		for(j = 0; j < order; j++){ //Loops through sections
			tran[i][j] = mat[j][i]; //Copies element j,i of original matrix to position i,j in the transpose matrix
		}
	}
}



int main()
{
    int matrix[MAX][MAX]; //Initializes two arrays with arbitrary values so that they can be manipulated
    int transpose[MAX][MAX];

    unsigned int order = 0; //Initializes the order of the matrix
	printf("Enter an order for the matrix: "); //Gets an order from the user
	scanf("%u", &order);


	setMatrixData(order, matrix); //Allows user to set values in the matrix
	
	printf("\nThe matrix is: \n\n");

	printMatrixData(order, matrix); //Outputs data of unedited matrix in tabular form

	
	if(isDistinctSquare(order, matrix)){ //Case for when matrix is distinct
		printf("\nThis matrix is a distinct matrix ");

		if(isMagicSquare(order, matrix)){ //Case for when matrix is magic square
			printf("and is a magic square\n\n");
		}
		else{ //Case for when matrix isn't magic square
			printf("but is not a magic square\n\n");
		}
	}
	else{ //Case when matrix is not distinct
		printf("\nThis matrix is not a distinct matrix nor a magic square\n\n");
	}

	
	getTranspose(order, matrix, transpose); //Gets transpose first as row-wise sort will change the original matrix
	
	
	printf("The original matrix sorted row-wise is: \n\n");
	
	sortRowWise(order, matrix); //Sorts the matrix row wise
	printMatrixData(order, matrix); //Outputs the sorted matrix
	
	printf("\nThe transpose of the original matrix is: \n\n");
	
	printMatrixData(order, transpose); //Prints the transpose matrix

	return 0;  
}

