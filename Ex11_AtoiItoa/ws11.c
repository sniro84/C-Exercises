/************************************************ 
EXERCISE 11   : atoi / iota
Implmented by : Snir Holland
Reviewed by   : 
Date          : 13/4/2023
File          : ws11.c
*************************************************/

#define ASCII_0        (48)
#define UCHARS_AMNT    (128)
#define BUF_LEN        (60) 
#define TEN            (10)

#define NOT_FOUND      (0)
#define FOUND_IN_A     (1)
#define FOUND_IN_A_B   (2)
#define UNWANTED       (3)

#define TRUE           (1)
#define FALSE          (0)

#define IS_LITTLE_ENDIAN ( *(short*)&("\0\xff") < 0x0100 ? 1 : 0 )

#include "ws11.h"
#include <stddef.h> /* size_t */
#include <assert.h> /* assert */
#include <string.h> /* strlen */
#include <ctype.h>  /* isdigit , isalpha */
#include <stdlib.h> /* atoi */
#include <stdio.h>  /* printf */ 

/* This utility function returns base to the power of exp */
static int Power(int base , int exp);

/* This utility function gets a char and return its integer value in base 36 
   Examples: '4' --> 4 , 'F' --> 15 , 'z' --> 35  */
static int CharToInt(char c);

/* This utility function gets an integer and return its char value (uppercase) in base 36 
   Examples: 4 --> '4' , 15 --> 'F' , 35 --> 'Z'  */
static char IntToChar(int c);

char *ItoaDec(int value , char *str)
{
	/* indicate number is negative */
	int is_negative = (value < 0);

	size_t digit = 0;
	
	assert(str);
	
	/* if number is negative, make it positive temporarily */
	if (is_negative)
	{
		value *= -1;	
	}

	/* fill string in reverse */
	while (value != 0)
	{
		digit = value % TEN;
		*str = IntToChar(digit);
		--str; 
		value /= TEN;		
	}
	
	/* if value is negative: add minus, else: move forward one spot */
	if (is_negative)
	{
		*str = '-';
	}
	else
	{
		++str;
	}
	
	return str;		
}

int AtoiDec(const char *nptr)
{
	int result = 0;
	size_t exp = 0;
	int is_negative = FALSE;
		
	assert(nptr);
	
	/* skip the spaces at the beginning if present */
	while ( isspace(*nptr) )
	{
		++nptr;
	}
	
	/* first character is a sign --> move forward */
	is_negative = (*nptr == '-');	
	if ('-' == *nptr  || '+' == *nptr)
	{
		++nptr;
	}
	
	/* go to last digit */
	while ( isdigit(*nptr) )
	{
		++nptr;
	}
	--nptr;
	
	/* copy string in reverse */		
	while ( isdigit(*nptr) )
	{
		result += CharToInt(*nptr) * Power(TEN, exp);
		++exp;
		--nptr;
	}
	
	if (is_negative)
	{
		result *= -1;
	}
	
	return result;
}

char *Itoa(int value, char *str, int radix)
{
	int remainder = 0;
	
	assert(str);
	
	str += BUF_LEN - 1;

	/* fill string in reverse */
	while (value != 0)
	{
		remainder = value % radix;
		*str = IntToChar(remainder);
		
		--str; 
		value /= radix;		
	}
	++str;
	
	return str;	
}


int Atoi(const char *nptr, int radix)
{
	int result = 0;
	const char *runner = NULL;
	size_t exp = 0;
	
	assert(nptr);
	
	runner = nptr;
	
	if ('-' == *runner || '+' == *runner)
	{
		++runner;
	}
	
	while ( *runner != '\0' && isalnum(*runner) )
	{				
		++runner;
	}
	--runner;
	
	while ( runner >= nptr)
	{
		result += (CharToInt(*runner) * Power(radix , exp));
		--runner;
		++exp;
	}
	
	if ('-' == *runner)
	{
		result *= (-1);
	}
	
	return result;
}

void TestAtoi(const char *nptr)
{
	printf("AtoiDec(%s) = %d , atoi(%s) = %d\n" , nptr , AtoiDec(nptr) , nptr , atoi(nptr));
}

void RunTestAtoi()
{
	TestAtoi("3785");
	TestAtoi("-3789");
	TestAtoi("29B31");
	TestAtoi("--3785");
	TestAtoi("?63");
	TestAtoi("6182?5");
	TestAtoi("-12?34");
	TestAtoi("1234567890000000");
	TestAtoi("-1234567890000000");
	TestAtoi("123 456");
	TestAtoi("  123456");
	TestAtoi(" 1 2 3");
	TestAtoi("+9173");
	TestAtoi("  +2100");
	TestAtoi("  -2100");
}

void PrintSpecialChars(char a[] , size_t len_a , char b[] , size_t len_b , char c[] , size_t len_c)
{
	size_t lut[UCHARS_AMNT] = {NOT_FOUND};
	size_t i = 0;
	 
	for(i=0; i<len_a; i++)
	{ 
		lut[ (size_t)(a[i]) ] = FOUND_IN_A;
	}
	
	for(i=0; i<len_b; i++)
	{ 
		if (lut[ (size_t)(b[i]) ] == FOUND_IN_A)
		{
			lut[ (size_t)(b[i]) ] = FOUND_IN_A_B;
		}
	}
	
	for(i=0; i<len_c; i++)
	{ 
		if (lut[ (size_t)(c[i]) ] == FOUND_IN_A_B)
		{
			lut[ (size_t)(c[i]) ] = UNWANTED;
		}
	}
	
	printf("Characters which are in the first two arrays but not in the third:\n");
	for(i=0; i<UCHARS_AMNT; i++)
	{ 
		if (lut[i] == FOUND_IN_A_B)
		{
			printf("%c " , (char)(i));
		}
	}
	printf("\n");
}

int IsLittleEndian()
{
	int n = 1;
		
	if (1 == *(char*)&n)
	{
		return TRUE;
	}
	return FALSE;
} 

int IsLittleEndianMacro()
{
	return IS_LITTLE_ENDIAN;	
} 

/* utility functions */

static int Power(int base , int exp)
{
	int result = 1;
	
	while (exp > 0)
	{
		result *= base;
		--exp; 
	}
	
	return result;
}

static int CharToInt(char c)
{
	int res = 0;
	
	res = (isalpha(c))  ?  toupper(c - 'A' + TEN)  :  c - ASCII_0;     
	
	return (int)res;
}

static char IntToChar(int num)
{
	char res = '\0';
	
	res = (num >= TEN)  ?  num + 'A' - TEN  :  num + ASCII_0;    
	
	return (char)res;
}
