#include <stdio.h>  /* printf */
#include "ws6.h"

/* Implmented by: Snir Holland at 29/3/2023
   Reviewed by :  Asaf Talker
*/

int main(void)
{
	/* EX1: structure of function pointers */
	printf("EX1 - Printing with function pointers:\n");
	FunctionPointers();
	printf("\n------End of Exercise 1------\n\n");
	
	/* EX2:  */
	printf("EX2 - Logger:\n");
	RunLogger(); 
	printf("\n------End of Exercise 2------\n");
	
	return 0;
}






