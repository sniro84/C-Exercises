#include "ws3.h"
#include <stdio.h>

/* Implemented by : Snir Holland, at 21/3/23
   Reviewed by    : Yaron Margalit , Kfir Rapoport */

int main()
{
	char* str1 = "ababa";
	char* str2 = "ppgp";
	char* str3 = "FearraeF";
	if (is_palindrom(str1))
		printf("%s is a palindrom.\n" , str1);
	if (!is_palindrom(str2))
		printf("%s is a NOT a palindrom.\n" , str2);
	if (is_palindrom(str3))
		printf("%s is a palindrom.\n" , str3);	
		
	seven_boom(1,20);		
	return 0;
}
