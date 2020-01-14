/*
	Name: lab01.c
	Author: Dean Willavoys
	Date: 1/14/19
	Purpose: To better understand and expand learning of functions in C	
*/
#include <stdio.h>

/*
fun1Re: Calculates the sum of integers up to and including n
Input: A positive integer, n
Output: Returns a positive long integer, the sum up to n 
*/
long fun1Re(int n);
long fun1Re(int n){
	if(n == 1){
		 return 1; //Basis step at 0
	}
	else{
		 return n + fun1Re(n-1); //Recursive step for sum
	}
}



/*
fun1It: Calculates the sum of integers up to and including n
Input: A positive integer, n
Output: Returns a positive long integer, sum, the sum up to n
*/
long fun1It(int n);
long fun1It(int n){
	int i; //Iterator for for loop
	long sum = 0; //Sum of numbers up to n
	for (i = 1; i <= n; i++){ //For loop for the sum of numbers up to n
		sum += i;
	}
	return sum; //Returns the calculated sum
}



/*
fun2Re: Calculates the sum of squares up to n + 1(starting at (1 + 1)^2)
Input: A positive integer n
Output: Returns a positive long integer, the calculated sum
*/
long fun2Re(int n);
long fun2Re(int n){
	if(n == 1){
		 return 4; //Base case at n=1
	}
	else{
		 return (n+1) * (n+1) + fun2Re(n-1); //Recursive step for sum of squares
	}
}



/*
fun2It: Calculates the sum of squares up to n + 1(starting at (1 + 1)^2)
Input: A positive integer, n
Output: Returns a positive long integer, sum, the calculated sum
*/
long fun2It(int n);
long fun2It(int n){
	int i; //Iterator for for loop
	long sum = 0; //Sum of squares
	for(i = 1; i <= n; i++){ //For loop for the sum of squares up to n + 1
		sum += (i + 1) * (i + 1);
	}
	return sum; //Returns the calculated sum of squares
}



/*
fibonacciRe: Calculates the nth element of the fibonacci sequence
Input: An integer n where n >= 0
Output: Returns a positive long integer,the nth element of fibonacci sequence
*/
long fibonacciRe(int n);
long fibonacciRe(int n){
	if(n==0 || n == 1){
		 return n; //Base step's of fibonacci sequence
	}
	else{
		 return fibonacciRe(n-1) + fibonacciRe(n-2); //Recursive step of fibonacci sequence
	}
}



/*
fibonacciIt: Calculates the nth element of the fibonacci sequence
Input: An integer n where n >= 0
Output: Returns a positive long integer, num3, the nth elemnt of the fibonacci sequence
*/
long fibonacciIt(int n);
long fibonacciIt(int n){
	long num1 = 0; //Initializes first 2 steps of fibonacci sequence
	long num2 = 1;
	long num3 = 1; //Initializes a third num to act as the current element in sequence
	for(int i = 1; i <  n; i++){ //Loops to the nth element
		num3 = num1 + num2; //Finds current value of element i
		num1 = num2; //Moves up num1 and num2
		num2 = num3;
	}
	return num3; //Returns requested element in fibonacci sequence
}



/*
gcdRe: Calculates the greatest common denominator between two integers x and y
Input: 2 integers, x and y, where x,y >= 0
Output: Returns a positive integer, the calculated gcd
*/
int gcdRe(int x, int y);
int gcdRe(int x, int y){
	if(y == 0){
		 return x; //Base step, GCD at y=0
	}
	else{
		 return gcdRe(y, x % y); //Recursive step for calculating remainder
	}
}



/*
gcdIt: Calculates the greatest common denominator between two integers x and y
Input: 2 integers, x and y, where x,y >= 0
Output: Returns a positive integer, x, the calculated gcd
*/
int gcdIt(int x, int y);
int gcdIt(int x, int y){
	int prevx = x; //Stores x value prior to re-assignment
	while(1){ //While loop to repeatedly calculate remainder and reduce values
		if(y == 0){
			 return x; //Outputs remainder when y reaches 0
		}
		else{
			x = y; //Swaps integers and reduces them
			y = prevx % y;
			prevx = x;
		}
	}
}



/*
powerRe: Calculates a to the power of b
Input: Two positive integers, a and b
Output: Returns a positive long integer, a^b
*/
long powerRe(int a, int b);
long powerRe(int a, int b){
	if(b == 1){
		 return a; //Base case, a to the power of 1
	}
	else{
		 return a * powerRe(a, b - 1); //Recursive step, a times the previous power until the power is reduced to 1
	}
}



/*
powerIt: Calculates a to the power of b
Input: Two positive integers, a and b
Output: Returns a positive long integer, product, a^b
*/
long powerIt(int a, int b);
long powerIt(int a, int b){
	long int product = 1; //Initializes an initial product value
	int i; //Iterator for for loop
	for(i = 1; i <= b; i++) //Multiplies product by a b times
		product *= a;
	return product; 
}



/*
divRe: Prints to the screen any integer less than n that is divisible by m
Input: Two positive integers m and n
Output: Prints positive integers
*/
void divRe(int n, int m);
void divRe(int n, int m){
	n-=1; //Reduces n by one as this only pretains to integers less than n, also serves to remove need to decrement n when calling the function recursively
	if(n == 0){
		 return; //Base step, returns void if there are no more numbers to check
	}
	if(n % m == 0){
		 printf("%d ", n); //Tests if n is divisible by m, if so, prints n 
	}
	divRe(n, m); //Loops function
}



/*
divit: Prints to the screen any integer less than n that is divisible by m
Input: Two positive integers m and n
Output: Prints positive integers
*/
void divIt(int n, int m);
void divIt(int n, int m){
	for(n -= 1;n > 0 ; n--){ //Loop descending from n to 0, starts at n-=1 as n is not included
		if(n % m == 0){ //Checks divisibility
			printf("%d ", n); //Prints if divisible
		}
	}
}



/*
drawTriangleRe: Prints a triangle of n height and width at it's peak. From zero each level gains a * until n height is reached
Input: A positive integer n
Output: Prints asterisks to the screen
*/
void drawTriangleRe(int n);
void drawTriangleRe(int n){
	if(n == 1){
		 printf("*\n"); //Base case, one star in width
	}
	else{
		drawTriangleRe(n - 1); //Calls to smallest level first, then builds up
		for(int i = 1; i <= n; i++){ //Loops to print the entire n wide width
	        	printf("*");
		}
		printf("\n"); //New line for new layer
	}
}




/*
drawTriangleIt: Prints a triangle of n height and width at it's peak. From zero each level gains a * until n height is reached
Input: A positive integer n
Output: Prints asterisks to the screen
*/
void drawTriangleIt(int n);
void drawTriangleIt(int n){
	int i; //Iterator for height of triangle
	int j; //Iterator for width of layers of triangle
	for(i = 0; i < n; i++){ //Loops up to n for height
		for(j = 0; j <= i; j++){ //Loops up to n for width
			printf("*"); //Prints shape
		}
		printf("\n");
	}

}







int main(){
	int choice = -1; //Initializes users choice of function (-1 to quit)
	int x = 0; //Initializes a set of variables that may be passed to a function
	int y = 0;
 
	while(1){ //User menu loop
		printf("1. Function 1 (Recursive)\t2. Function 1 (Iterative)\n3. Function 2 (Recursive)\t4. Function 2 (Iterative)\n");//Lists user's options
		printf("5. Fibonacci (Recursive)\t6. Fibonacci (Iterative)\n7. GCD (Recursive)\t\t8. GCD (Iterative)\n");
		printf("9. Power (Recursive)\t\t10. Power (Iterative)\n11. Divisibility (Recursive)\t12. Divisibility (Iterative)\n");
		printf("13. Draw Triangle (Recursive)\t14. Draw Triangle (Iterative)\n");
		printf("Please choose a function(-1 to exit): ");
		scanf("%d", &choice); //Gets user's choice
	
		switch(choice){ //Switch-statement to allow for multi-choice menu
			case -1://Option to exit program
				return 0; //Returns to main
			case 1: //Option 1 from the menu
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);  
				printf("\nSum of %d is %d\n\n", x, fun1Re(x)); //Prints sum
				break;
			case 2: //Option 2 from the menu
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);  
				printf("\nSum of %d is %d\n\n", x, fun1It(x)); //Prints sum
				break;
			case 3: //Option 3 from the menu
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);  
				printf("\nSum is %d\n\n", fun2Re(x)); //Prints sum
				break;
			case 4:	//Option 4 from the menu		
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);
				printf("\nSum is %d\n\n", fun2It(x)); //Prints sum
				break;
			case 5:	//Option 5 from the menu		
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);
				printf("\nElement %d from the fibonacci sequence is %d\n\n", x, fibonacciRe(x)); //Prints nth element of fib. sequence
				break;
			case 6:	//Option 6 from the menu		
				printf("\nEnter a positive n value: "); //Gets input from user and passes it to function
				scanf("%d", &x);
				printf("\nElement %d from the fibonacci sequence is %d\n\n", x, fibonacciIt(x)); //Prints nth element of fib. sequence
				break;
			case 7:	//Option 7 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);
				printf("\nThe greatest common denominator is %d\n\n", gcdRe(x,y)); //Prints greatest common denominator of x and y
				break;
			case 8:	//Option 8 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);
				printf("\nThe greatest common denominator is %d\n\n", gcdIt(x,y)); //Prints greatest common denominator of x and y
				break;
			case 9:	//Option 9 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);
				printf("\n%d to the power of %d is %d\n\n", x, y,  powerRe(x,y)); //Prints x to the power of y
				break;
			case 10: //Option 10 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);
				printf("\n%d to the power of %d is %d\n\n", x, y,  powerIt(x,y)); //Prints x to the power of y
				break;
			case 11: //Option 11 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);
				printf("\nNumber(s) less than %d and divisible by %d are:\n", x, y); //Prints explenation
				divRe(x,y); //Function outside of printf as there is no return value from it 
				printf("\n\n"); //Formatting
				break;
			case 12: //Option 12 from the menu		
				printf("\nEnter two positive integers: "); //Gets input from user and passes it to function
				scanf("%d%d", &x, &y);	
				printf("\nNumber(s) less than %d and divisible by %d are:\n", x, y); //Prints explenation
				divIt(x,y); //Function prints calculated values 
				printf("\n\n"); //Formatting
				break;
			case 13: //Option 13 from the menu
				printf("\nEnter an n value: "); //Gets input from user and passes it to function
				scanf("%d", &x); 
				drawTriangleRe(x); //Function prints n sized triangle
				break;
			case 14: //Option 14 from the menu
				printf("\nEnter an n value: "); //Gets input from user and passes it to function
				scanf("%d", &x); 
				drawTriangleIt(x); //Function prints n sized triangle
				break;
			default: //Case for invalid entries
				printf("\nInvalid Entry!\n\n");
				break;			
		}
	}
	return 0;
}

