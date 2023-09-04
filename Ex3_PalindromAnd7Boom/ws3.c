#include "ws3.h"
#include <stdio.h>
#include <assert.h>

int is_palindrom(char* str)
{
	char* start;
	char* end;
	
	assert(str);
	
	start = str;
	while (*str != '\0')
	{
		++str;
	}
	end = str - 1;
	
	while (start <= end)
	{
		if (*start != *end)
		{
			return FALSE;
		}
		start++;
		end--;				
	}
	
	return TRUE;	
}

void seven_boom(int from,int to)
{
	int i;
	for(i=from; i<=to; i++)
	{
		if (i%7 == 0 || include_seven(i) == TRUE )
		{
			printf("%s " , "BOOM!");	
		}
		else
		{
			printf("%d " , i);	
		}
	}
	printf("End.\n");
}

int include_seven(int num)
{
	int result = FALSE;
	while (num != 0)
	{
		if (num % 10 == 7)
		{
			result = TRUE;
			break;
		}
		num = num / 10;
	}
	return result;
} 

