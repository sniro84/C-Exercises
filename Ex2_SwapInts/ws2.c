#include "ws2.h"

void swap_ints(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void copyArr(int src[] , int dest[] , int srcLen, int destLen)
{
	int i;
	assert(src);
	assert(dest);
	assert(destLen >= srcLen);
	
	for(i=0; i<srcLen; i++)
	{
		*(dest+i) = *(src+i);
	}
		
}

void swap(size_t* a, size_t* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap_pointers(size_t** p1 , size_t** p2)
{	
	swap(  (size_t*)p1 , (size_t*)p2  );
}

size_t StrLen(const char* str)
{
	const char* runner;
	
	assert(str);
	
	runner = (char*) str;
	while ('\0' != *runner)
		++runner;
		
	return runner - str;	
}

int StrCmp(const char *str1, const char *str2)
{
	int res = 0;
	assert(str1);
	assert(str2);
	
	while( ('\0' != *str1) || ('\0' != *str2) )
	{
		if (*str1 != *str2)
		{
			res = (*str1) - (*str2);
			break;
		}
		else
		{
			str1++;
			str2++;
		} 	
	}
	return res;		
}
