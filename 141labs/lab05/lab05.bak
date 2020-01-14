/*
Author: Dean Willavoys
ID: 105003751
Date: 2/27/19
Purpose: To practice advanced string manipulation
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200


/*
ParseSentence: Extracts each word from the passed string and then re-prints the words in alphabetical order
Input: A null terminated string S
Output: Prints the individual words of the passed string, in alphbetical order
*/
void ParseSentence(char *S);
void ParseSentence(char *S){
	int i, j; //Iterators for for loops
	char *ptrS = S; //A pointer to point to individual word strings, will double as temp variable for swapping
	char *words[strlen(S)]; //An array made up of the words in the passed string, its length is the # of characters in S, which will always exceed # words in S 
	unsigned int index = 0; //Current index in array


	words[index] = strtok(S, " ,;."); //Splits firsts token off, assigning S as the string to be worked by strtok
	while(words[index] != NULL){ //Loops so long as there are more tokens
		index++;
		words[index] = strtok(NULL, " ,;."); //Assigns a portion of the word array to a token of S
	}


	for(i = 0; i < index; i++){ //Bubble sort format
		for(j = i + 1; j < index-1; j++){
			if(strcmp(words[i],words[j]) > 0){ //Using strcmp from string.h to compare as it scans characters
				ptrS = words[i]; //Re-inserts tokens into words array in alphabetical order
				words[i] = words[j];
				words[j] = ptrS;
			}	
		}
	}

	puts(""); //New line for formatting	
	for(i = 0; i < index ; i++){ //Outputs the words entered, in alphabetical token form
		puts(words[i]);
	}

}


int main(){
	char sentence[MAX]; //Declares a string of MAX size

	puts("Input a string to test ParseSentence with:"); 
	fgets(sentence, MAX, stdin);

	ParseSentence(sentence); //Sorts words in passed string alphabetically
	return 0;
}
