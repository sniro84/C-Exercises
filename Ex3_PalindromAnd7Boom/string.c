#include "string.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>


char* StrnCpy(char* dest, const char* src, size_t n)
{
	size_t i = 0;
	
	assert(src);
	assert(dest);
	
	while (i < n  &&  '\0' != *src)
	{
		*dest = *src;
		++src;
		++dest;
		++i;
	}
	
	/* assign extra null bytes for a total of n bytes*/ 
	while (i < n)
	{
		*dest = '\0';
		++i;
		++dest;			
	}
	  
	return dest;
}

char* StrCpy(char* dest, const char* src)
{
	return StrnCpy(dest , src , StrLen(src) + 1);
}

int StrnCmp(const char* str1, const char* str2, size_t n)
{
	size_t i = 0;
	
	assert(str1);
	assert(str2);
	assert(StrLen(str1) >= n);
	assert(StrLen(str2) >= n); 
	
	while ( ('\0' != *str1) && ('\0' != *str2) && (i < n)  &&  (*str1 == *str2) )
	{
			i++;
			str1++;
			str2++;	
	}
	
	if (i == n)
	{
		return 0;
	}
	
	return *str1 - *str2;
}

int StrCaseCmp(const char* str1, const char* str2)
{	
	assert(str1);
	assert(str2);
	
	while ( ('\0' != *str1) && ('\0' != *str2)  &&  (tolower(*str1) == tolower(*str2)) )
	{
		++str1;
		++str2;
	}

	return *str1 - *str2;					
}

char* StrDup(const char* s)
{
	char* copy;

	assert(s);
	
	copy = (char*)malloc(sizeof(char) * StrLen(s) + 1 );
	if (copy == NULL)
	{
		printf("Memory allocation failed.\n");
		return NULL;
	}
	
	StrCpy(copy , s);
	return copy;
}

char* StrChr(const char* str, int c)
{
	assert(str);

	while ('\0' != *str  &&  *str != c)
	{
		++str;
	}
	
	if (*str =='\0')
	{
		return NULL;
	}
	return (char*)str;
}


char* StrnCat(char *dest, const char *src , size_t n)
{
	StrnCpy(dest + StrLen(dest) , src , n);
	return dest;
}

char* StrCat(char *dest, const char *src)
{
	return StrnCat(dest , src , StrLen(src) );
}

char* StrStr(const char* haystack, const char* needle)
{
	assert(needle);
	assert(haystack);
	
	while ('\0' != *haystack)
	{
		if (0 == StrnCmp(needle , haystack , StrLen(needle)))
		{
			return (char*)haystack;
		}
		++haystack;
	}
	return NULL;
}

size_t StrSpn(const char* s, const char* accept)
{
	size_t res = 0;
	
	assert(s);
	assert(accept);
	while ('\0' != *s  &&  NULL == StrChr(accept, *s) )
	{
		++s;
	} 
	
	if ('\0' != *s)
	{
		while (NULL != StrChr(accept, *s))
		{
			++s;
			++res;
		}
	}
	
	return res;
}

size_t StrLen(const char* str)
{
	const char* runner;
	
	assert(str);
	
	runner = (char*) str;
	while ('\0' != *runner)
	{
		++runner;
	}	
	return runner - str;	
}

