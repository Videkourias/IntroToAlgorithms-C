/*
Author: Dean Willavoys
ID: 105003751
Date: 3/5/19
Purpose: To practice using structures and manipulating files
*/

#include<stdio.h>
#include<string.h>
#define NUM 3 //The number of employee files

//Data type for the details of a given employee
struct employee{
	char firstname[40]; //The first name of the employee
	char lastname[40];  //The last name of the employee
	int id;	//The ID of the employee
};
typedef struct employee Employee; //Alias for the structure



/*
InputEmployeeRecord: Input the employee data interactively from the keyboard
Input: A pointer to an employee data structure
Output: No return or print, edits the contents of a file
*/
void InputEmployeeRecord(Employee *ptrEmp);
void InputEmployeeRecord(Employee *ptrEmp){
	char first[40]; //Employee first name
	char last[40]; //Employee last name
	int id; //Employee id

	//Gets info from user
	printf("Employee first name: ");
	scanf("%s", first);

	printf("Employee last name: ");
	scanf("%s", last);

	printf("Employee ID: ");
	scanf("%d", &id);

	//Changes the information of the passed employee structure
	strcpy(ptrEmp->firstname, first);
	strcpy(ptrEmp->lastname, last);
	ptrEmp->id = id;

}



/*
PrintEmployeeRecord: Display the contents of a given employee record
Input: An employee data structure
Output: Prints the information in an employee data structure 
*/
void PrintEmployeeRecord(const Employee e);
void PrintEmployeeRecord(const Employee e){
	printf("%d %s %s\n", e.id, e.firstname, e.lastname);
}



/*
SaveEmployeeRecord: Save the contents of the employee record list to the newly created text file specified by FileName
Input: An array of employee data structures, a file name
Output: No return or print, creates a new file with the contents of the passed array 
*/
void SaveEmployeeRecord(const Employee e[], const char *FileName);
void SaveEmployeeRecord(const Employee e[], const char *FileName){
	int i; //Iterator for for loop
	FILE *fp; //Pointer to file
	fp = fopen(FileName, "w"); //Opens the file to write to
	
	if(fp == NULL){ //Tests if file opened correctly
		printf("Error opening file");
	}
	else{
		fprintf(fp, "ID FIRSTNAME LASTNAME\n");
		for(i = 0; i < NUM; i++){
			fprintf(fp, "%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname); //Prints the stored employee info to file
		}	
		fclose(fp); //Closes file
	}
}

void main(){
	int i; //Iterator for for loop
	Employee e[NUM]; //An array of 3 employee structures

	for(i = 0; i < NUM; i++){ //Gets employee info and stores it
		InputEmployeeRecord(&e[i]);
	}

	for(i = 0; i < NUM; i++){ //Outputs employee info
		PrintEmployeeRecord(e[i]);
	}

		

	SaveEmployeeRecord(e, "employee.dat");

}

