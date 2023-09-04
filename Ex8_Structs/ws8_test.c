/************************************************ 
EXERCISE 8: Structs 
Implmented by : Snir Holland
Reviewed by   : Lee Sharvit
Date          : 8/4/2023 
*************************************************/

#include "ws8.h"
#include <stdio.h> /* printf */

/* size of array of structs */
#define SIZE 3
							 
int main(void)
{
	/* variables for exercises 5-7 */
	int x = 0;
	double y = 0;
	char z = '\0';
	
	/* Init araay of structs */
	element_t elem_arr[SIZE];

	/* Headline in terminal */
	printf("Part I:\n");
	printf("Implementing a union:\n\n");
	 
	
	/* Creating the structs */	
	CreateInt(elem_arr , 0 , 7);		
	CreateFloat(elem_arr , 1 , 6.83);
	CreateString(elem_arr , 2 , "Blah");  
	
	/* Printing the structs */
	PrintAll(elem_arr , SIZE);
	
	/* Add an integer to each of the structs */
	AddAll(elem_arr , SIZE , 30);
	
	/* Printing the updated structs */ 
	PrintAll(elem_arr , SIZE);
	
	/* Clean structs */
	CleanAll(elem_arr , SIZE);
	
	/* Printing the updated structs */ 
	PrintAll(elem_arr , SIZE); 
	 	 	
	printf("\nPart II:\n");	
	printf("Testing function-like macros:\n\n");
	printf("MAX2(7,19) = %d\n" , MAX2(7,19));
	printf("MAX2(36,36) = %d\n" , MAX2(36,36));
	printf("MAX3(4,1,7) = %d\n" , MAX3(4,1,7));
	printf("MAX3(5,5,2) = %d\n" , MAX3(5,5,2));
	printf("MAX3(9,6,3) = %d\n" , MAX3(9,6,3));
	
	printf("\n");	
	
	printf("Testing sizeof macros:\n");
	printf("x ,y and z are of types int , double and char, respectively.\n");
	printf("SIZEOF_VAR(x) = %ld bytes.\n" , SIZEOF_VAR(x) );
	printf("SIZEOF_VAR(y) = %ld bytes.\n" , SIZEOF_VAR(y) );
	printf("SIZEOF_VAR(z) = %ld bytes.\n" , SIZEOF_VAR(z) );
	
	printf("\n");
	
	printf("SIZEOF_TYPE(char)      = %ld bytes.\n" , (size_t)SIZEOF_TYPE(char) );
	printf("SIZEOF_TYPE(int)       = %ld bytes.\n" , (size_t)SIZEOF_TYPE(int) );
	printf("SIZEOF_TYPE(double)    = %ld bytes.\n" , (size_t)SIZEOF_TYPE(double) );
	printf("SIZEOF_TYPE(element_t) = %ld bytes.\n" , (size_t)SIZEOF_TYPE(element_t) );
	
	return 0;	
}

