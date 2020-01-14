/*
Author: Dean Willavoys
ID: 105003751
Date: 3/21/19
Purpose: To work with structures and arrays
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5


//Structure for a timed event
struct event{
	unsigned int hour; //The hour of the event, between [0,23]
	unsigned int minute; //The minute of the even, between [0,59]
	char description[41]; //The event description
};

typedef struct event Event; //Alias for event structure


//Prototypes
int InputRange(int min, int max);
Event *InputEvent(Event *newEvent);
int AddEventAtIndex(Event list[], Event e, int i);
int InsertionSortEvent(Event list[], int *p_size, Event e);
void DisplayEvent(Event e);
void DisplayEventList(Event list[], int size);
int DeleteEvent(Event list[], int i, int *p_size);
int SaveEventList(char *filename, Event List[], int size);
int LoadEventList(char *filename, Event List[], int *p_size);
char *encode(char *s);
char *decode(char *s);


/*
InputRange: Prompts the user for an integer within the specified range
Input: 2 integers
Output: Returns the user entered integer
*/
int InputRange(int min, int max){
	int input = max + 1; //User input

	while(input > max || input < min){ //Loop while number is invalid
		printf("Enter an integer between %d and %d: ", min, max);
		scanf("%d", &input); //Gets user input
		if(input > max ||input < min){ //Invalid input condition
			printf("Invalid input\n");
		} 
	}
	return input;
}



/*
InputEvent: Populates an event structure with valid user input
Input: A non-NULL Event pointer
Output: A pointer to the populated Event structure, or NULL if the passed pointer was empty
*/
Event *InputEvent(Event *newEvent){
	if(newEvent == NULL){ //Pointer null check
		fprintf(stderr, "Invalid pointer\n");
		return newEvent;
	}

	int hour; //User entered data
	int min;
	char desc[41];	

	printf("\nEnter the event time:\n"); //Prompts user for Event data
	hour = InputRange(0,23); 
	min = InputRange(0,59);

	printf("Enter the event description: ");
	scanf(" %[^\n]s", desc);


	newEvent->hour = hour; //Fills event with user entered data
	newEvent->minute = min;
	strcpy(newEvent->description, desc);
	return newEvent;
}



/*
AddEventAtIndex: Stores the passed Event at index i of the passed array
Input: An Event array, an Event, an integer index
Output: Returns the index the Event was stored at
*/
int AddEventAtIndex(Event list[], Event e, int i){
	list[i] = e; //Overwrites Event at index i with new event
	return i;
}



/*
InsertionSortEvent: Inserts Events into an array while maintaining an ascending order, using insertion sort
Input: An Event array, an integer pointer to the size of the array, an Event
Output: Returns the index the Event is stored at upon finishing
*/
int InsertionSortEvent(Event list[], int *p_size, Event e){	
	AddEventAtIndex(list, e, *p_size); //Adds Event to list
	*(p_size) += 1; //Updates size of Event list
	
	int hour, min;
	hour = list[*p_size].hour;
	min = list[*p_size].minute;

	int i, j; //Iterators
	Event event; //An event structure
	int val; //A value of the array to be compared
	int val2; //A value of the array to be compared

	for(i = 1; i < *p_size; i++){ //Modified insertion sort to account for hour and minute
		event = list[i];
		val = list[i].hour;
		val2 = list[i].minute;
		j = i - 1;

		while(j >= 0 && (list[j].hour > val || (list[j].hour == val && list[j].minute > val2))){
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = event;
	}
	
	for(i = 0; i < *p_size; i++){ //Returns new position of inserted Event
		if(list[i].hour == hour && list[i].minute == min){
			return i;
		}
	}

}



/*
DisplayEvent: Displays an Event in formatted form
Input: An event
Output: Prints the contents of the event
*/
void DisplayEvent(Event e){
	printf("%.2d:%.2d %s\n", e.hour, e.minute, e.description); //Outputs formatted info
}



/*
DisplayEventList: Displays all Events in the Event list, iteratively, along with their indexes
Input: An Event array, an integer size
Output: Prints the contents of each event along with their index values
*/
void DisplayEventList(Event list[], int size){
	printf("\n");
	if(size == 0){
		printf("You need to add entries to the list first...");
	}
	for(int i = 0; i < size; i++){ //Displays all entries in Event list, iteratively
		printf("[%d] ", i);
		DisplayEvent(list[i]);
	}
}



/*
DeleteEvent: Deletes Event from Event list at index i
Input: An Event array, an integer index, an integer size
Output: Returns -1 on failure or exit, otherwise returns the index of the removed Event 
*/
int DeleteEvent(Event list[], int i, int *p_size){
	if(i <= -1 || i > *p_size - 1){ //Checks for valid index value
		printf("EXITING\n");
		return -1;
	}
	else if(i == *(p_size) - 1){ //Case for array to delete being the last case
		*(p_size) -= 1;
		return i;
	}
	else{
		while(i < *(p_size) - 1){
			list[i] = list[i + 1]; //Shifts entire array over by one, overwritting entry at i
			i++;
		}
		*(p_size) -= 1; //Decreases size of array
		return i;
	}
}



/*
SaveEventList: Saves the Event list to a file
Input: A pointe to a file name, an Event list, an integer size
Output: Returns the number of records saved, or -1 if failure occurs
*/
int SaveEventList(char *filename, Event List[], int size){
	FILE *fp; //Opens file
	fp = fopen(filename, "w");
	unsigned int entry = 0; //The number of entries successfully saved
	char encoded[41]; //Temp string

	if(fp != NULL){
		for(int i = 0; i < size; i++, entry++){ //Saves all entries to file in formatted form
			strcpy(encoded, List[i].description);
			fprintf(fp, "%d %d %s\n", List[i].hour, List[i].minute, encode(encoded));
		}
		fclose(fp); //Closes file
		return entry;
	}
	else{	
		fclose(fp);
		return -1;
	}
}



/*
LoadEventList: Overwrites contents of Event list with contents of file
Input: A filename, an Event array, an integer pointer to the size of the Event array
Output: Returns the number of records retrieved, or -1 if error occurs
*/
int LoadEventList(char *filename, Event List[], int *p_size){
	FILE *fp;
	fp = fopen(filename, "r"); //Opens file

	int i = 0; //Iterator
	char s[41]; //Temp string	


	if(fp != NULL){ //If file opened correctly
		while(!feof(fp)){
			fscanf(fp, "%d %d %s\n", &List[i].hour, &List[i].minute, s); //Scans for desired entries before eof
			strcpy(List[i].description, decode(s));
			i++;			
		} 
		fclose(fp); //Closes file
		return (*p_size = i); //Returns amount of entries, and assigns that number to the size
	}
	else{
		fclose(fp); //Case for file opened incorrectly
		return -1;
	}
}



/*
encode: Replaces all blank space in the passed string with underscores
Input: A character pointer (string)
Output: An encoded characrer pointer (string)
*/
char *encode(char *s){
	char *p = s;
	while(*p != '\0'){ //Replaces spaces with underscores
		if(*p == ' '){
			*p = '_';
		}
	p++;
	}
	return s;	
}



/*
decode: Replaces all underscores in the passed string with spaces
Input: A character pointer (string)
Output: A decoded characrer pointer (string)
*/
char *decode(char *s){
	char *p = s;
	while(*p != '\0'){ //Replaces underscores with spaces
		if(*p == '_'){
			*p = ' ';
		}
	p++;
	}	
	return s;
}





int main(){
	Event EventList[MAX]; //A list of Events
	int eventListSize = 0; //The number of events in the event list

	unsigned int option; //Users menu choice
	int delete; //Index to delete
	int events; //The number of events successfully loaded

	char name[20]; //Name of file to read/write

	Event temp; //Temporary event

	do{
		printf("\n\n__= Scheduler v1.0 =__\n"); //Interactive menu for user
		printf("1. Schedule an event.\n2. Delete an event.\n3. Display schedule.\n");
		printf("4. Save schedule.\n5. Load schedule.\n6. Exit\n");
		printf("==> Please enter an integer between 1 and 6: ");
		scanf("%u", &option); 

		switch(option){ //Case based on user entry
			case 1: //Add an entry
				if(eventListSize > MAX - 1){
					printf("The max number of events you can add to the schedule has been reached\n");
					break;
				}
				InputEvent(&temp);
				InsertionSortEvent(EventList, &eventListSize, temp); 
				break;
			case 2: //Delete an entry
				printf("Which even would you like to delete?(-1 to cancel)\nEnter a number from -1 to %d: ", eventListSize - 1);
				scanf("%d", &delete);
				DeleteEvent(EventList, delete, &eventListSize);
				break;
			case 3: //Display the Event list
				DisplayEventList(EventList, eventListSize);
				break;
			case 4: //Save to file
				printf("\nFile Name: ");
				scanf("%s", name);
				events = SaveEventList(name, EventList, eventListSize);
				printf("%d events saved to %s", events, name);
				break;
			case 5: //Load from file
				printf("This action will replace the current schedule.\n");
				printf("File Name (or \"abort\" to cancel operation): ");
				scanf("%s", name);
				if(strcmp("abort", name) == 0){
					printf("Aborting....");
					break;
				}
				else{
					events = LoadEventList(name, EventList, &eventListSize);
					printf("%d events successfully loaded from schedule file %s", events, name); 
				}
				break;
			case 6: //Exit
				printf("Goodbye...\n");
				return 0;
			default: //Invalid Option
				printf("Invalid option");
				break;
		}
	}while(option != 6); //Menu loop


	return 0;
}
