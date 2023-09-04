#include "string.h"
#include <stdio.h>

/* Implemented by : Snir Holland, at 21/3/23
   Reviewed by    : Yaron Margalit , Kfir Rapoport */

int main()
{
	char* myStr1 = "When";
	char* myStr2 = "Whenever";
	char* myStr3 = "Whegever";	
	char* myStr4 = "When";
	char* myStr5 = "WhEn";
	char* myStr6 = "WheNever";
	char* myStr7;	
	char* myStr8 = "ThisIsMyHartaString";
	char* myStr666 = "BlueSky";

	char buf1[40];
	char buf2[50];
	char buf3[30] = "Snir";
	char buf6[40] = "MangoBananaVeMelon";
	char* mySource = "DvashVekinamon";
	const char haystack[20] = "TutorialsPoint";
   	const char needle[10] = "als";
	char* mySrc = "Holland";
   	char password[] = "M29811thrre4";
  	char digits[] = "1234567890";

	
	printf("Source string :  %s\n", myStr1);
	
	
	/* StrCpy */
	StrCpy(buf1 , myStr1);
	printf("StrCpy with %s ---> Output: %s\n", myStr1 , buf1);
	
	/* StrnCpy */
	StrnCpy(buf2 , myStr3 , 6);
	printf("StrnCpy with %s and 6 ---> Output: %s\n", myStr3 , buf2);
	
	StrnCpy(buf2 , myStr666 , 4);
	printf("StrnCpy with %s and 4 ---> Output: %s\n", myStr666 , buf2);
	StrnCpy(buf2 , myStr666 , 11);
	printf("StrnCpy with %s and 11 ---> Output: %s\n", myStr666 , buf2);
	
	/* StrnCmp */
	printf("StrnCmp(%s,%s,3) = %d \n" , myStr1 , myStr2 , StrnCmp(myStr1,myStr2,3) );
	printf("StrnCmp(%s,%s,5) = %d \n" , myStr2 , myStr3 , StrnCmp(myStr2,myStr3,5) );
	printf("StrnCmp(%s,%s,5) = %d \n" , myStr3 , myStr2 , StrnCmp(myStr3,myStr2,5) );
	
	/* StrCaseCmp */
	printf("StrCaseCmp(%s,%s) = %d \n" , myStr4 , myStr5 , StrCaseCmp(myStr4,myStr5) );
	printf("StrCaseCmp(%s,%s) = %d \n" , myStr5 , myStr6 , StrCaseCmp(myStr5,myStr6) );
	printf("StrCaseCmp(%s,%s) = %d \n" , myStr4 , myStr6 , StrCaseCmp(myStr4,myStr6) );
	printf("StrCaseCmp(%s,%s) = %d \n" , myStr3 , myStr6 , StrCaseCmp(myStr3,myStr6) );
	
	/* StrDup */
	myStr7 = StrDup(myStr6);
	printf("StrDup(%s) = %s \n" , myStr6 , myStr7 );
	
	/* StrChr */
	printf("StrChr(%s,%c) = %s\n" , myStr8 , 'H' , StrChr(myStr8 , 'H'));
	printf("StrChr(%s,%c) = %s\n" , "Shokolad-Banana" , 'k' , StrChr("Shokolad-Banana" , 'k'));  
	
	/* StrCat */
	printf("StrCat(%s,%s) = " , buf3 , mySrc);
	printf("%s\n", StrCat(buf3 , mySrc)); 
	
	
	/* StrnCat */
	printf("StrnCat(%s,%s,%d) = " , buf6 , mySource,7);
	printf("%s\n", StrnCat(buf6 , mySource,7)); 
	
	/* StrStr */
   	printf("StrStr(%s,%s) = %s\n" , haystack , needle , StrStr(haystack ,needle )); 
   	
   	/* StrSpn */
 	printf("StrSpn(%s,%s) = %lu\n" , password , digits , StrSpn(password,digits));	
	
	return 0;
}

