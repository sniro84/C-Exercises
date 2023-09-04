#include "ws1.h"

void say_hello()
{
	printf( "%c%c%c%c%c%c%c%c%c%c%c%c\n" ,
            0x48 , 0x65 , 0x6c , 0x6c , 0x6f , 0x20 ,
            0x57 , 0x6f , 0x72 , 0x6c , 0x64 , 0x21  );
}

float powTen(int n)
{
	int i;
	float factor;
	float res = 1;
	if (n >= 0)
		factor = 10;
	else
	{
		n = -n;
		factor = 0.1;
	}
	
	for (i=0; i<n; i++)
		res = res * factor;
	return res;
}

int reverseNum(int x)
{
    int last_digit;
    int reverse_x = 0;
    while (x != 0)
    {
        last_digit = x % 10;
        reverse_x = reverse_x * 10 + last_digit;
        x = x / 10;
    }
    return reverse_x;
}

void swap(int* a , int* b)
{				
	*a = *a + *b;   
	*b = *a - *b;   
	*a = *a - *b;   
}



