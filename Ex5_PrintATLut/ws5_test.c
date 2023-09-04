#include <stdio.h>
#include "ws5.h"

/* Implmented by: Snir Holland at 26/3/2023
   Reviewed by : Yakov Polykovsky
*/

int main()
{
	/* Functions Ex: Recieve input from keyboard  */
	
	DisableTerminal();
	
	/* 1. if-else implementation  */
	printf("If-Else:\n");
	IfElseSol(); 
	
	
	/* 2. switch-case implementation  */
	printf("Switch-Case:\n");
	SwitchCaseSol();  
	
	/* 3. LUT implementation  */
	printf("LUT:\n");
	LutSol();
	
	EnableTerminal();
	
	printf("Goodbye.  :-) \n" );
	
	return (0);
}
