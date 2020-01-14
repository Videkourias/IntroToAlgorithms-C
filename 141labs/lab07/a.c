#include<stdio.h>
#include<stdlib.h>

typedef struct record{
	int num;
}Record;

main(){
	Record *list;
	int num;
	Record *startpoint = list;

	for(int i = 0; i < 3; i++){
		(list) = malloc(sizeof(Record));
		printf("\nEnter num: ");
		scanf(" &d", &num);
		list->num = num;
		list++;

	}
	

	return 0;
}
