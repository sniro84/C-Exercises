/************************************************ 
EXERCISE 10   : Word Boundary
Implmented by : Snir Holland
Reviewed by   : Yehonathan Zarkovian
Date          : 11/4/2023
File          : ws10_test.c
*************************************************/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strlen */
#include "ws10.h" 

static void RunMemcpyExamples(); 
static void RunMemsetExamples();
static void RunMemmoveExamples();  

int main(void)
{
	/* EX1: Memcpy */
	RunMemcpyExamples();
	
	/* EX2: Memset */
	RunMemsetExamples();
		
	/* EX3: Memmove */
	RunMemmoveExamples();  
	
	return (0);
}


static void RunMemcpyExamples()
{
	char* src1 = (char*)malloc(sizeof(char) * 20);
	char dest1[40];
	char dest2[40];
	printf("---EX1: Memcpy---\n" );
	strcpy(src1 , "ThisIsBullShit");
	printf("src1: %s\n" , src1);
	 
	Memcpy(dest1 , src1 , 9 );
	printf("After Memcpy(dest1 , src1 , 9 )    : %s\n" , dest1); 
	Memcpy(dest2 , src1+4 , 6 );
	printf("After Memcpy(dest2 , src1+4 , 6 )  : %s\n" , dest2);
	
	free(src1);
	
	printf("----------------------------------------------\n" );
	
}

static void RunMemsetExamples()
{
	char dest2[40];
	
	printf("---EX2: Memset---\n" );
	strcpy(dest2 , "AAAAAAAAAAAAA");	
	printf("dest2: %s\n" , dest2);
	Memset(dest2 + 3 , 'B' , 5 );
	printf("After Memset(dest2 + 3 , 'B' , 5 ): %s\n" , dest2);
	printf("---------------------------------------------\n" );
}

static void RunMemmoveExamples()  
{
	int numbers[15] = {1,2,3,4,5,6,7,8,9,10};
	int numbers_again[15] = {1,2,3,4,5,6,7,8,9,10};
	char* strA = (char*)malloc(sizeof(char) * 10);
	char* strB = (char*)malloc(sizeof(char) * 10);
	size_t i = 0;
	
	printf("---EX3: Memmove---\n" );
	printf("Original Array :\n");
	for(i=0; i<15; i++)
	{
		printf("%d " , numbers[i]);	
	}
	printf("\n");
	
	Memmove(numbers+3 , numbers , sizeof(int) * 6 );
	printf("After Memmove(numbers+3 , numbers , sizeof(int) * 6 ) :\n"); 
	
	for(i=0; i<15; i++)
	{
		printf("%d " , numbers[i]);	
	}
	printf("\n");
	
	Memmove(numbers_again+10 , numbers_again , sizeof(int) * 3 );
	printf("After Memmove(numbers_again+10 , numbers_again , sizeof(int) * 3 ) :\n"); 
	for(i=0; i<15; i++)
	{
		printf("%d " , numbers_again[i]);	
	}
	printf("\n");
		
	strcpy(strA , "MyStory");	
	printf("strA: %s\n" , strA);
	Memmove(strA+2 , strA , sizeof(char) * 3 );
	printf("After Memmove(strA+2 , strA , sizeof(char) * 3 ) :\n");
	printf("strA: %s\n" , strA);
	
	printf("\n");
	
	strcpy(strB , "MyStory");	
	printf("strB: %s\n" , strB);
	Memmove(strB , strB+3 , sizeof(char) * 4 );
	printf("After Memmove(strB , strB+3 , sizeof(char) * 4 ) :\n");
	printf("strB: %s\n" , strB);
	
	free(strA);
	free(strB);
	
	printf("\n---------------------------------------------\n" );
}
