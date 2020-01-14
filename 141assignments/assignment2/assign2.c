/*
Author: Dean Willavoys
ID: 105003751
Date: 03/05/18
Purpose: To find and sort anagrams from a set of words
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Structure for each group of anagrams, their size, and the number of anagrams in each group 
typedef struct anagram{
	int sizeWords; //Size of the words in this group
	int numWords; //Number of words in this group
	char *words[100]; //The words in this group	
}anagram;




/*
isAnagram: Checks if 2 strings are anagrams by comparing the frequency of every letter in each word
Input: Two character arrays(strings), an unsigned int for the size of the two strings
Output: Returns an integer, 0 for not anagrams, 1 for anagrams
*/
int isAnagram(const char s1[], const char s2[], const unsigned int size);
int isAnagram(const char s1[], const char s2[], const unsigned int size){
	char alpha1[26]; //2 sets of alphabets recording how many times each letter appears in each word
	char alpha2[26];
	int i; //Iterator for for loop
	int letter; //Integer representing a character's integer value in the alphabet arrays 

	for(i = 0; i < 26; i++){ //Assigns all values in both arrays to zero as no letters have been viewed yet
		alpha1[i] = 0;
		alpha2[i] = 0;
	}


	for(i = 0; i < size; i++){
		letter = s1[i] - 'a'; //Determines what letter is currently being viewed in the parsed word
		alpha1[letter] += 1; //Increments that letter(letters are represented by numerical values here)

		letter = s2[i] - 'a'; //Repeats above but with second word
		alpha2[letter] += 1; 
	}//More info: s1[i] - 'a' is essentially some character of the first word  minus a. a has an integer value of 97, so the entire alphabet can be 
	//represented as 97 plus some other number. ie. 'f' - 'a' = 102 - 97 = 5. Thus, alpha1[5] represents f's # of appearences in s1.


	for(i = 0; i < 26; i++){ //Parses entire alphabet
		if(alpha1[i] != alpha2[i]){ //If different letters or a different quantity of letters appear, return 0 as the words aren't anagrams
			return 0;
		}
	}
	return 1; //Return 1 otherwise as the words are anagrams

}


/*
sortLexicographic: Sorts an array of character pointers(strings) in lexicographical order
Input: An array of character pointers(strings), the number of elements in that array, and the length of the strings in that array
Output: No return or print, sorts and array
*/
void sortLexicographic(char *A[], const int size, const int len);
void sortLexicographic(char *A[], const int size, const int len){
	int i,j,k; //Index values and iterator values
	char temp[len]; //Temporary pointer for swapping


	for(i = 0; i < size - 1; i++){ //Selection sort for a 1D array
		k = i;
		for(j = i + 1; j < size; j++){
			if(strcmp(A[j],A[k]) < 0){ //Modified comparison to work for strings
				k = j;
			}
		}
		strcpy(temp, A[k]); //Modified swap to work for strings
		strcpy(A[k], A[i]);
		strcpy(A[i], temp);
	}

}



int main(){
	int i,j,k; //Iterators for for loops
	unsigned int wordSize; //Size of individual word
	unsigned int numWords = 0; //The number of words entered by user
	unsigned int numAnagramGroups = 0; //The number of anagram groups that are in use
	unsigned int placed; //Boolean for whether or not a word needs a unique anagram group
	anagram temp; //Temporary structure for sorting later


	char *words[100]; //Array of strings inputed by user, at most 100
	char currWord[21]; //The current word entered by the user, at most 21(including \0)



 
	scanf("%s", currWord); //Gets initial word
	while(strcmp(currWord, "STOP") != 0){ 
		words[numWords] = malloc(strlen(currWord) + 1); //Dynamically allocates memory in array for word
		strcpy(words[numWords], currWord); //Copies word into array
		numWords++;
		scanf("%s", currWord); 
	}




	anagram anagramGroups[numWords]; //Words will be placed in anagram groups(worst case is there are no anagrams, so size is the number of words)

	for(i = 0; i < numWords; i++){
		anagramGroups[i].numWords = 0; //Assigns the number of words in each group to 0 initially
	}




	for(i = 0; i < numWords; i++){ //Loops through all words and assigns them to an anagram group
		placed = 0; //Initially, word is not in a group
		wordSize = strlen(words[i]);  
		for (j = 0; j < numAnagramGroups; j++){ //Loops through all existing anagram groups
			if(wordSize == anagramGroups[j].sizeWords && isAnagram(words[i], anagramGroups[j].words[0], wordSize)){ //Checks if word fits critera
				anagramGroups[j].words[anagramGroups[j].numWords] = malloc(wordSize + 1);// 			for current anagram group, if so,
				strcpy(anagramGroups[j].words[anagramGroups[j].numWords], words[i]); //				updates that groups information
				anagramGroups[j].numWords++;
				placed = 1; //Word is now in group, does not need a new one
				break; //Exits as a word can not be in two different groups
			}
		} 
		if(!placed){ //If anagram is not in existing group, create new one
			anagramGroups[numAnagramGroups].words[0] = malloc(wordSize + 1); //Fill new anagram group with information
			strcpy(anagramGroups[numAnagramGroups].words[0], words[i]); 
			anagramGroups[numAnagramGroups].numWords++; 
			anagramGroups[numAnagramGroups].sizeWords = wordSize; 
			numAnagramGroups++; //Increases the total number of groups
		}
	}



	for(i = 0; i < numAnagramGroups - 1; i++){ //Selection sort of the array of anagram groups
		k = i;
		for(j = i + 1; j < numAnagramGroups; j++){
			if(anagramGroups[k].numWords < anagramGroups[j].numWords){ //Sorts largest to smallest by number of words in group
				k = j; 
			}
		}
		temp = anagramGroups[k];
		anagramGroups[k] = anagramGroups[i];
		anagramGroups[i] = temp;
	}



	i = 0;
	while(i < 5 && i < numAnagramGroups){ //Parses top 5 groups, or all groups if less than 5
		sortLexicographic(anagramGroups[i].words, anagramGroups[i].numWords, anagramGroups[i].sizeWords); //Sorts the strings in a group lexicographically
	i++;
	}



	i = 1;
	while(i < 5 && i < numAnagramGroups){ //  Tests current group and previous, swaps them to lexicographical order if they tie in size	
		if(anagramGroups[i].numWords == anagramGroups[i-1].numWords && strcmp(anagramGroups[i].words[0],anagramGroups[i-1].words[0]) < 0){
			temp = anagramGroups[i-1];
			anagramGroups[i-1] = anagramGroups[i];
			anagramGroups[i] = temp;
			i = 0;
 		}
		i++;
	}


	i = 0;
	while(i < 5 && i < numAnagramGroups){ //Displays top 5(or all if less than 5) anagram groups after sanitizing them
		unsigned int initSize = anagramGroups[i].numWords; //Initializes a variable with the initial size of the group as any repeats will reduce the size
		for(j = 1; j < initSize; j++){
			if(strcmp(anagramGroups[i].words[j], anagramGroups[i].words[j-1]) == 0){
				anagramGroups[i].numWords--; //Reduces size of group if are duplicates found				
			}
		}
		printf("Group of size %d: ", anagramGroups[i].numWords);
		for(j = 0; j < initSize; j++){ //Outputs the strings in order
			if(j > 0 && strcmp(anagramGroups[i].words[j], anagramGroups[i].words[j-1]) == 0){
				continue; //Prevents duplicates from being printed
			}
			printf("%s ", anagramGroups[i].words[j]);
		}
		printf("\n");
	i++;
	}

	return 0;
}
