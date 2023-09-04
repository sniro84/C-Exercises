/************************************************ 
EXERCISE 11   : atoi / iota
Implmented by : Snir Holland
Reviewed by   : 
Date          : 13/4/2023
File          : ws11_test.c
*************************************************/

#include <stdio.h>
#include <string.h>
#include "ws11.h"

static void RunItoaDecExamples();
static void RunAtoiDecExamples();
static void RunItoaExamples();
static void RunAtoiExamples();
static void CallRunTestAtoi();
static void RunPrintSpecialChars();
static void RunIsLittleEndianFunction();
static void RunIsLittleEndianMacro();

int main(void)
{
	/* EX1.a : Itoa in decimal base */
	RunItoaDecExamples();
	
	/* EX1.b : Atoi in decimal base */
	RunAtoiDecExamples(); 
	
	/* EX1.c : Itoa/Atoi in any base [2...36] */
	RunItoaExamples();      
	RunAtoiExamples();
	
	/* EX1.de : Atoi vs atoi */
	CallRunTestAtoi();
	
	/* EX2 : Characters in three arrays */
	RunPrintSpecialChars();
	
	/* EX3 : Little Endian (function) */
	RunIsLittleEndianFunction();
	
	/* EX3 : Little Endian (macro) */
	RunIsLittleEndianMacro();
	
	return (0);
}

static void RunItoaDecExamples()
{
	char buf1[12] = {'\0'};
	printf("-----------------EX1.a--------------------\n");
	printf("ItoaDec(9876) = %s\n"  , ItoaDec(9876 , buf1));
	printf("ItoaDec(-48273) = %s\n"  , ItoaDec(-48273 , buf1));
	printf("ItoaDec(+3333) = %s\n"  , ItoaDec(+3333 , buf1));
	printf("------------------------------------------\n");
}

static void RunAtoiDecExamples()
{
	char *myStr1 = "82947";
	char *myStr2 = "-316";
	char *myStr3 = "937m5";
	char *myStr4 = "bb0666";
	char *myStr5 = "-93U16";
	char *myStr6 = "+48733";
	printf("-----------------EX1.b--------------------\n");
	printf("AtoiDec(%s) = %d\n" , myStr1 , AtoiDec(myStr1));
	printf("AtoiDec(%s) = %d\n" , myStr2 , AtoiDec(myStr2));
	printf("AtoiDec(%s) = %d\n" , myStr3 , AtoiDec(myStr3));
	printf("AtoiDec(%s) = %d\n" , myStr4 , AtoiDec(myStr4));
	printf("AtoiDec(%s) = %d\n" , myStr5 , AtoiDec(myStr5));
	printf("AtoiDec(%s) = %d\n" , myStr6 , AtoiDec(myStr6));
	printf("------------------------------------------\n");
}


static void RunItoaExamples()
{
	char buf[100] = {'\0'};
	int num3 = 54325;
	size_t base = 2;
	printf("----------------- EX1.c : Itoa() --------------------\n");
	for(base = 2; base<=36; base++)
	{
		printf("Itoa on %d with base %lu = %s\n" , num3 , base , Itoa(num3 , buf , base));
	}
	printf("------------------------------------------\n");
}

static void RunAtoiExamples()
{
	printf("----------------- EX1.c : Atoi() --------------------\n");
	printf("Atoi(10 , 36) = %d\n" , Atoi("10" , 36) );
	printf("Atoi(FFFF ,16) = %d\n" , Atoi("FFFF" , 16) );
	printf("Atoi(83794 , 10) = %d\n" , Atoi("83794" , 10) );
	printf("Atoi(0101110 , 2) = %d\n" , Atoi("0101110" , 2) );
	
	printf("------------------------------------------\n");	
}

static void CallRunTestAtoi()
{
	printf("----------------- EX1.de --------------------\n");
	RunTestAtoi();
	printf("------------------------------------------\n");	
}

static void RunPrintSpecialChars()
{
	char a1[8] = {'A','B','C','D','E','F','G','H'};	
	char a2[8] = {'A','y','C','D','a','a','C','p'};
	char a3[8] = {'B','y','C','E','a','a','C','p'};
	printf("----------------- EX2 --------------------\n");
	PrintSpecialChars(a1,8,a2,8,a3,8);
	printf("------------------------------------------\n");
}

static void RunIsLittleEndianFunction()
{
	printf("----------------- EX3 --------------------\n");
	if (IsLittleEndian())
	{
		printf("System is Little-Endian (function).\n");
	}
	else
	{
		printf("System is Big-Endian (function).\n");
	}
	printf("------------------------------------------\n");
}

static void RunIsLittleEndianMacro()
{
	printf("----------------- EX4 --------------------\n");
	if (IsLittleEndianMacro())
	{
		printf("System is Little-Endian (macro).\n");
	} 
	else
	{
		printf("System is Big-Endian (macro).\n");
	}
	printf("------------------------------------------\n");
}



