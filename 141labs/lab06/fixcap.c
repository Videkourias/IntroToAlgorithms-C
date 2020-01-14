/*
Author: Dean Willavoys
ID: 105003751
Date: 3/5/18
Purpose: To practice with structures and file manipulation
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>



//Structure that contains employee information
struct employee{
	char firstname[40]; //The first name of the employee
	char lastname[40]; //The last name of the employee
	int id;	 //The ID of the employee
};
typedef struct employee Employee; //Alias for structure




/*
WordCap: Capitalizes the first letter of the passed word
Input: A pointer to a string
Output: Doesn't return or print, only changes value of passed string
*/
void WordCap(char *word){
	*word = toupper(*word); //Changes the first character of a string into its capitalized version
}


int main(){
	int i; //Iterator for for loop
	FILE *fp; //File pointer
	Employee EmployeeList[3]; //Makes an array of Employee structures
	char first[40], last[40]; //Temporary stirage to hold first and last name before they are transferred to sttuct
	int id; //Temporary storage to hold id before it is transferred to struct
	int entry = 0; //Keeps track of which employee record is being parsed
	char buffer[22];

	fp = fopen("employee.dat", "r"); //Opens file

	if(fp == NULL){ //Tests that file opened correctly
		printf("Error opening file\n");
	}
	else{
		fgets(buffer, 22, fp);
		while((fscanf(fp, "%d %s %s", &id, first, last) != EOF)){ //Loops while there is still employee information available 
			EmployeeList[entry].id = id; 
 
			strcpy(EmployeeList[entry].firstname, first); //Stores the first name in a structure
			WordCap(EmployeeList[entry].firstname); //Capitalizes first name

			strcpy(EmployeeList[entry].lastname, last); //Stores the last name in a structure
			WordCap(EmployeeList[entry].lastname); //Capitalizes last name
			entry++;
		}
		fclose(fp); //Closes file
	}


	fp = fopen("employee.dat", "w"); //Re-opens file with writing permissions 

	if(fp == NULL){ //Tests that file opened correctly
		printf("Error opening file\n");
	}
	else{
		fprintf(fp, "ID FIRSTNAME LASTNAME\n");
		for(i = 0; i < 3; i++){
			fprintf(fp, "%d %s %s\n", EmployeeList[i].id,EmployeeList[i].firstname, EmployeeList[i].lastname); //Overwrites current data with capitalized data
		}
		fclose(fp); //Closes file
	}

	return 0;
}


