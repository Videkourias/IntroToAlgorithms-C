/*
Author: Dean Willavoys
ID: 105003751
Date: 02/03/19
Purpose: Help practice working with pointers
*/

#include<stdio.h>


/*
PrintArray: Prints every value and memory address in order
Input: An integer array and an integer for the size of that array
Output: Prints the contents of the array, with memory addresses
*/
void PrintArray(int size, int array[]);
void PrintArray(int size, int array[]){
	int i; //Iterator
	for(i = 0; i < size; i++){
		printf("array[%d] = %d, %p\n", i, array[i], &array[i]); //Prints every value of array, along with address
	}
}



/*
swap: Swaps the values two pointer variables are pointed at
Input: 2 integer pointer values
Output: No output, swaps existing values
*/
void swap(int *var1, int *var2);
void swap(int *var1, int *var2){
	int temp; //Declares a temporary storage variable

	temp = *var1; //Swaps the values of what var1 and var2 point to
	*var1 = *var2;
	*var2 = temp;
}


/*
SelectionSort: Sorts an array using selection sort
Input: An integer array and an integer for the size of that array
Output: No output, changes the order of the given array
*/
void SelectionSort(int size, int array[]);
void SelectionSort(int size, int array[]){
	int i; //Iterators
	int j;
	int k; //Index value

	//Progressively sorts smaller lists as i gets larger
	for(i = 0; i < size - 1; i++){
	k = i; //Minimum element in unsorted array

		for(j = i + 1; j < size; j++){
			if(array[k] > array[j]){
				k = j; //Checks if any element in smaller list is smaller than k, if so, k becomes the index of that element
			}
		}
	swap(&array[k], &array[i]); //Swaps k and i using previously defined swap function
	}
}





/*
ArrayInfo: Provides various stats about the passed array
Input: An integer array, an integer n for the size of that array, a long integer pointer for sum of array, a float pointer for the average and two integer pointers for the min and max of the array
Output: No output, changes the value of various addresses
*/
void ArrayInfo(int array[], int n, long int *ptrSum, float *ptrAvg, int *ptrMin, int *ptrMax);
void ArrayInfo(int array[], int n, long int *ptrSum, float *ptrAvg, int *ptrMin, int *ptrMax){
	int i; //Iterator

	for(i = 0; i < n; i++){
		*ptrSum += array[i]; //Adds each element of the array to the location pointed to by the prtSum variable(sum in main)
	}	
	
	*ptrAvg = (float)*ptrSum/n; //Calculates the value of the average of the array and immediately passes it to the address that ptrAvg points to(avg in main)


	*ptrMin = array[0]; //Min and max are first element by default
	*ptrMax = array[0];

	for(i = 0; i < n; i++){ //Cycles through array
		if(array[i] > *ptrMax){
			*ptrMax = array[i]; //If any element is greater than the largest, that element becomes the larges(changes value of max in main)
		}
		else if(array[i] < *ptrMin){
			*ptrMin = array[i]; //If any element is less than the smalles, that element becomes the smallest(changes value of min in main)
		}
	}
	//Function does not need to return anything as the parameters were directly changed by the function using their memory addresses
}



/*
ReverseArray: Reverses the elements of an array
Input: An integer array and an integer the size of that array
Output: No output, changes order of given array
*/
void ReverseArray(int size, int *ptr2Array);
void ReverseArray(int size, int *ptr2Array){
	int i; //Iterator for for loop
	int temp[size]; //Temporary array of matching size to hold list while copying
	int *start = ptr2Array;	


	for(i = 0; i < size; i++){
		temp[i] = *ptr2Array; //Parses passed array and copies it to a temporary array
		ptr2Array++; //Increments location in memory
	}

	ptr2Array = start; //Resets memory to inital location(start of array)

	for(i = size-1; i >= 0; i--){
		*ptr2Array = temp[i]; //Parses the temp array in reverse and copies its contents to the passed array
		ptr2Array++; //Increments location in memory
	}

}



int main(){
	int data[] = {2, 7, 8,-8, 1, 9, 3, 5};
	int *ptr2Array = data; //Makes a pointer that stores the address of the array "data"

	long sum = 0; //Allocates a memory location for a long representing sum and stores its address in a pointer
	long *ptrSum = &sum; 

	float avg; //Allocates a memory location for a float representing average and stores its address in a pointer
	float *ptrAvg = &avg; 

	int min; //Allocates a memory location for an int representing min and stores its address in a pointer
	int *ptrMin = &min;

	int max; //Allocates a memory location for an int representing max and stores its address in a pointer
	int *ptrMax = &max; 



	SelectionSort(sizeof(data)/sizeof(int), data); //Sorts an array using selection sort

	PrintArray(sizeof(data)/sizeof(int), data); //Outputs array

	ArrayInfo(data, sizeof(data)/sizeof(int), ptrSum, ptrAvg, ptrMin, ptrMax); //Calculates information about given array


	printf("\n\n"); //Spacing

	ReverseArray(sizeof(data)/sizeof(int), ptr2Array); //Reverses array
	PrintArray(sizeof(data)/sizeof(int), data); //Prints the array


	printf("\n\nTest to see if info from ArrayInfo is available to main...\n");
	printf("Sum = %ld\nAverage = %.2f\nMin = %d\nMax = %d\n", sum, avg, min, max);



	return 0;	
}


//Q2.2: Noticed that the addresses are consecutive(4 bytes appart each), meaning they're all next to each other in memory
