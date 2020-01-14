#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5 //Length of list constant


void linearSort(int list[]){ //Linear Sort Algorithm
	int i,j,temp;

	for(i = 0; i < LEN - 1; i++){
		for(j = i + 1; j < LEN; j++){
			if(list[i] > list[j]){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		} 
	}
}


int linearSearch(int list[],int query){
	for(int i = 0; i < LEN; i++){
		if(list[i] == query) return i;
	}
	return -1;	

}


int binarySearch(int list[],int src){
	int start = 0;
	int end = LEN - 1, mid = 0;
	while(start != end){
		mid = start + (end - start)/2;
		if(src >list[mid])
			start = mid + 1;
		else if(src <list[mid])
			end = mid;
		else return -1;
	}
	return mid;
}



int main(){
	srand(time(NULL));
	int list[LEN];
	int i, num;

	for(i = 0; i < LEN; i++){ //Populates list with random elements
		list[i] = rand() % 501;
	}
	
	for(i = 0; i < LEN; i++){ //Displays unsorted list
		printf("[%d]", list[i]);
	}

	linearSort(list); //Sorts list
	printf("\n");

	for(i = 0; i < LEN; i++){ //Displays sorted list
		printf("[%d]", list[i]);
	}

	printf("\nEnter an integer to search the list for\n");
	scanf("%d", &num);

	int element = linearSearch(list,num);
	if (element != -1) printf("%d is located at element %d\n", num, element);
	else printf("%d is not present in this list\n");


	printf("Enter an integer to search the list for\n");
	scanf("%d", &num);

	element = binarySearch(list,num);
	if (element != -1) printf("%d is located at element %d\n", num, element);
	else printf("%d is not present in this list\n");


	return 0;
}
