
/*
Author: Dean Willavoys
ID: 105003751
Date: 3/18/19
Purpose: To work with structures and dynamic memory allocation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Structure for the details of a product
typedef struct ProductDescription{

	char productName[25]; //The name of the product
	float productPrice; //The price of the product
	float productWeight; //The weight of the prodcut

} Product;


//Prototypes
void CreateProductList(Product **productList, unsigned int size);
void ResizeProductList(Product **productList, unsigned int newSize);
Product SetProductInfo();
void SortProductList(Product *productList, unsigned int size, char sortOption);
void AddProductToProductList(Product *productList, unsigned int size);
void PrintProductList(Product *productList, unsigned int size);
void swap(Product *product1, Product *product2);


/*
CreateProductList: Allocates enough memory to store requested number of product entries
Input: A pointer to an array pointer and a positive integer size
Output: No return or print, allocates memory
*/
void CreateProductList(Product **productList, unsigned int size){
	*productList = (Product *)malloc(sizeof(Product) * size); //Allocates enough memory for an array of size Products
}



/*
ResizeProductList: Resizes the exisiting memory allocated to fit user request
Input: A pointer to an array pointer and a positive integer size
Output: No return or print, allocates memory
*/
void ResizeProductList(Product **productList, unsigned int newSize){
    *productList = (Product*) realloc(*productList, sizeof(Product) *  newSize); //Reallocates enough memory to accommodate an array of Producs of size newSize
}


/*
SetProductInfo: Allows user to set data for a single product
Input: Function has no input parameters
Output: Returns a complete product data structure
*/
Product SetProductInfo(){
	Product product; //Blank Product
	
	printf("\nPlease Enter the Product Name: "); //Fills Product with user entered data
	scanf(" %[^\n]s", product.productName);

	printf("\nPlease Enter the Product Price: ");
	scanf(" %f", &product.productPrice);

	printf("\nPlease Enter the Product Weight: ");
	scanf(" %f", &product.productWeight);

	return product;

}



/*
swap: Swaps the Products' values at the pointers
Input: Two structure pointers
Output: No return or print, swaps values in memory
*/
void swap(Product *product1, Product *product2){
	Product temp; //Blank Product for swapping

	temp = *product1; //Swap
	*product1 = *product2;
	*product2 = temp;
}



/*
SortProductList: Allows user to sort product list based on a sort option
Input: A pointer to the product list, a positive integer size and a character for sort option
Output: Prints if invalid option is selected, else, changes values at memory addresses. (valid: p,w,n)
*/
void SortProductList(Product *productList, unsigned int size, char sortOption){
	int i;
	int j;
	int min;
	switch(sortOption){ //Switch case for 3 possibilities
		case 'p': //Sort by price
			for(i = 0; i < size - 1; i++){ //Selection sort of product prices
				min = i;
				for(j = i + 1; j < size; j++){
					if(productList[j].productPrice < productList[min].productPrice){
						min = j;
					} 
				}
				swap(&productList[i], &productList[min]);
			}
			break;
		case 'w': //Sort by weight
			for(i = 0; i < size - 1; i++){ //Selection sort of product weights
				min = i;
				for(j = i + 1; j < size; j++){
					if(productList[j].productWeight < productList[min].productWeight){
						min = j;
					} 
				}
				swap(&productList[i], &productList[min]);
			}
			break;

		case 'n': //Sort by name
			for(i = 0; i < size - 1; i++){ //Selection sort of product names
				min = i;
				for(j = i + 1; j < size; j++){
					if(strcmp(productList[j].productName,  productList[min].productName) > 0){
						min = j;
					} 
				}
				swap(&productList[i], &productList[min]);
			}
			break;

		default: //Invalid option
			printf("Invalid Sort Option\n");
			break;


	}

}


/*
AddProductToProductList: Allows user to create the product list
Input: A Product array pointer and a positive integer size
Output: No return or print, changes values at memory addresses
*/
void AddProductToProductList(Product *productList, unsigned int size){

    for(int i=0; i< size; i++){
        printf("\nPlease enter product info for product %d: \n", i);
        *(productList+i) = SetProductInfo(); //Fills a Product from user input and appends it to productList
    }

}


/*
PrintProductList: Prints the product list to the screen
Input: A Product array pointer and a positive integer size
Output: Prints the data of the Products stored in productlist
*/
void PrintProductList(Product *productList, unsigned int size){

    for(int i=0; i< size; i++){

       printf("\n Product ID: %d Name: %s", i, (productList+i)->productName); //Prints data of current product
       printf("\n Product ID: %d Price: %f", i, (productList+i)->productPrice);
       printf("\n Product ID: %d Weight: %f", i, (productList+i)->productWeight);
       printf("\n----------------------------------------------------------------\n");
    }

}

int main() {

	Product *list; //List of Product structures
 	unsigned int listSize; //Size of that list
 	char sortOption; //Method of sorting
 	char resize; //Boolean for resizing


	printf("Please Enter the size of the list: ");
	scanf("%d", &listSize); //Gets list size from user




   	CreateProductList(&list, listSize); //Creates Product list, adds entries

	AddProductToProductList(list, listSize);

	PrintProductList(list, listSize); //Outputs Product list

	printf("\n\nTo sort the product list press: \n'p' to sort by price, or 'w' to sort by weight, or 'n' to sort by name  : ");

	scanf(" %c", &sortOption);

	SortProductList(list,listSize, sortOption); //Sorts Product list by user choice

	PrintProductList(list,listSize); //Outputs Product list

	printf("\n\nTo resize the product list press 'y' or any other key to escape: "); //Prompts user on whether or not they want to resize
	scanf(" %c", &resize);

	if(resize == 'y' || resize == 'Y'){ //Resizes and prints the new Product list
        	printf("Please Enter the new size of the list: ");
        	scanf("%d", &listSize);
        	ResizeProductList(&list, listSize);
        	PrintProductList(list, listSize);
    	}

    return 0;
}





/*
BONUS:
	3) Double pointers are used so that the function can work with the address of the pointer, call by reference, 
	rather than a copy of the pointer, call by value. This is so any changes made to it are reflected globally, rather than just locally. 

	4) nah

*/
