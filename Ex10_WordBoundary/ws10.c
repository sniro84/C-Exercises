/************************************************ 
EXERCISE 10   : Word Boundary
Implmented by : Snir Holland
Reviewed by   : Yehonathan Zarkovian
Date          : 11/4/2023
File          : ws10.c
*************************************************/

#include "ws10.h"
#include <stddef.h> /* size_t */ 
#include <assert.h> /* assert */

#define WORD_LEN sizeof(size_t)
 
void *Memcpy(void *dest, const void *src, size_t n)
{
	char *runner_dest = (char*)dest;
	char *runner_src = (char*)src;
	
	assert(dest);
	assert(src);
	
	while ( (size_t)(runner_dest) % WORD_LEN != 0  &&  n > 0)
	{
		*runner_dest = *runner_src;
		++runner_dest;
		++runner_src;
		--n;	
	}
	
	while (n >= WORD_LEN)
	{
		*(size_t*)runner_dest = *(size_t*)runner_src;
		n -= WORD_LEN;
		runner_dest += WORD_LEN;
		runner_src += WORD_LEN;
	}
	
	while (n > 0)
	{
		*runner_dest = *runner_src;
		++runner_dest;
		++runner_src;
		--n;
	}
	
	return dest;
}

void *Memset(void *s , int c , size_t n)
{
	char *runner = s;
	char buf[WORD_LEN] = {0};
	size_t i = 0;
	
	assert(s);
	
	for(i=0; i<WORD_LEN; i++)
	{
		buf[i] = (char)c;
	}
	
	while (n > 0)
	{
		if ( 0 == (size_t)(runner) % WORD_LEN  &&  n >= WORD_LEN)
		{
			 *(size_t*)runner = *(size_t*)buf;
			 n -= WORD_LEN;
			 runner += WORD_LEN;
		}
		else
		{
			*runner = (char)c;
			n--;
			runner++;
		}	
	}
	
	return s;
}

void *Memmove(void *dest ,const  void *src , size_t n)
{
	char *runner_dst = dest;
	char const *runner_src = src;	
	
	assert(dest);
	assert(src);
	
	if (dest < src)
	{
		Memcpy(dest , src , n);
	}
	else
	{
		/* the bytes are copied in reverse */
		runner_dst += n;
		runner_src += n;
		
		while (n > 0)
		{
			--runner_dst;
			--runner_src;	
			*runner_dst = *runner_src;
			--n;
		}
	}
	return dest;
}


