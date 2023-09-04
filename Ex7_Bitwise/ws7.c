#include <stdio.h>
#include <stddef.h>
#include "ws7.h"

#define FOUND          1
#define NOT_FOUND      0
#define TRUE           1
#define FALSE          0
#define BIT_AMOUNT     3
#define BITS_IN_BYTE   8
#define BITS_IN_FLOAT  32
#define ZERO_BITS      0
#define ONE_BIT        1
#define TWO_BITS       2
#define FOUR_BITS      4
#define FIVE_BITS      5
#define EIGHT_BITS     8
#define BINARY_ONE     1

#define HEX_PATTERN_0x5      0x55555555
#define HEX_PATTERN_0x3      0x33333333
#define HEX_PATTERN_0x0F     0x0F0F0F0F
#define HEX_PATTERN_0x00FF   0x00FF00FF

/* This utility function returns true if a x has 3 bits which are on */
static size_t HasThreeOnBits(unsigned int x);


/* EX1: This function returns the result of x*(2^y)  */
long Pow2(unsigned int x , unsigned int y)
{
	return (long)(x << y);
}

/* EX2.a: This function returns true if n is a power of two (with loop) */
size_t IsPowOf2Loop(unsigned int n)
{
	size_t mask = BINARY_ONE;
	while(mask < n)
	{
		mask <<= ONE_BIT;
	}
	return !(n ^ mask);	
}

/* EX2.b: This function returns true if n is a power of two (without loop) */
size_t IsPowOf2(unsigned int n)
{
	return !(n & (n - 1));
}

/* EX3: This function returns n + 1 with only bitwise operators */
int AddOne(int n)
{
	return -(~n);
}

/* EX4: This functions prints all the numbers which have 3 bits which are on */
void DisplayThreeBitNumbers(unsigned int *numbers , size_t numbers_len)
{
	size_t index = 0;
	
	while(index < numbers_len)
	{
		if ( HasThreeOnBits( numbers[index]) )
		{
			printf("%d " , numbers[index] ); 
		}
		index = AddOne(index); 
	}
	printf("\n");
}

/* EX4: This utility function returns true if a x has 3 bits which are on */
static size_t HasThreeOnBits(unsigned int x)
{
	size_t mask = BINARY_ONE;
	size_t on_bits = 0;
	while (mask <= x)
	{
		if (x & mask)
		{
			on_bits = AddOne(on_bits);
		}
		mask = mask << ONE_BIT;	
	}
	return (BIT_AMOUNT == on_bits);
}

/* EX5A: This function returns a character after mirroring its bits */
unsigned char MirrorByteLoop(unsigned char ch)
{
	unsigned char result = 0;
	size_t src_bit = 0;
	size_t dest_bit = BITS_IN_BYTE - ONE_BIT;
	
	size_t i = 0;
	while ( i < BITS_IN_BYTE)
	{
		/* examine the i'th bit from the right */
		src_bit = (ch >> i) & BINARY_ONE; 
		
		/* examine the i'th bit from the left and turn on if needed */
		dest_bit = src_bit << (BITS_IN_BYTE - ONE_BIT - i);
		result = result | dest_bit;

		i = AddOne(i);
	} 
	
	return result;
}

/* EX5B: This function returns a character after mirroring its bits (Non-Loop Version) */
unsigned char MirrorByte(unsigned char b) 
{
   b = (b & 0xF0) >> FOUR_BITS | (b & 0x0F) << FOUR_BITS;  
   b = (b & 0xCC) >> TWO_BITS  | (b & 0x33) << TWO_BITS ;
   b = (b & 0xAA) >> ONE_BIT   | (b & 0x55) << ONE_BIT;
   return b;
}

/* EX6A: This function returns true if both 2nd and 6th bits turned on, false otherwise */
size_t TwoAndSixBits(unsigned char ch)
{
	return ( ((ch >> ONE_BIT) & BINARY_ONE)  &  ((ch >> FIVE_BITS) & BINARY_ONE) ); 
} 

/* EX6B: This function returns true if at least  one of the 2nd/6th bits turned on, false otherwise */
size_t TwoOrSixBits(unsigned char ch)
{
	return ( ((ch >> ONE_BIT) & BINARY_ONE)  |  ((ch >> FIVE_BITS) & BINARY_ONE) ); 
}

/* EX6C: This function returns the new charater after swapping 3rd and 5th bits */
unsigned char SwapBits(unsigned char data)
{
	/* get the bits with indices 2 and 4 */
	unsigned char bit_3 = (data >> TWO_BITS)  & BINARY_ONE;
	unsigned char bit_5 = (data >> FOUR_BITS) & BINARY_ONE;
	
	/* xor these bits */ 
	unsigned char xor_res = bit_3 ^ bit_5;
	
	/* create pattern for swapping */
	unsigned char pattern = (xor_res << TWO_BITS ) | (xor_res << FOUR_BITS);
	
	/* xor pattern with data and send back result */
	return (data ^ pattern);
}

/* EX7: This function return the closest (smaller) positive number to num which is dividible by 16 */
unsigned int ClosestTo16(unsigned int num)
{
	/* create a msk of 16 */
	unsigned int mask = BINARY_ONE;
	mask <<= FOUR_BITS; 
	
	while (mask <= num)
	{
		mask <<= ONE_BIT;
	}
	
	mask >>= ONE_BIT;
	return mask; 	
}

/* EX8: This function swaps the values of 2 variables with bitwise operations */
void SwapValues(int* p1 , int* p2)
{
	if( p1 != p2)
	{
		*p1 = *p1 ^ *p2;
		*p2 = *p1 ^ *p2;
		*p1 = *p1 ^ *p2;
	}
}

/* EX9A: This function counts the number of set bits in an integer (Loop Version) */
size_t CountSetBitsLoop(int num)
{
	size_t on_bits = 0;
	
	while (0 != num)
	{
		num = num & (num - 1);       /* unset bit from the right */
		on_bits = AddOne(on_bits);
	}
	return on_bits;
}

/* EX9B: This function counts the number of set bits in an integer (Hamming Weight) */
size_t CountSetBits(int num)
{
	unsigned int b0 = (num >> ZERO_BITS) & HEX_PATTERN_0x5;    /* masking with 0101 */
	unsigned int b1 = (num >> ONE_BIT)   & HEX_PATTERN_0x5;  
	unsigned int c = b0 + b1;
	
	unsigned int d0 = (c >> ZERO_BITS) & HEX_PATTERN_0x3;      /* masking with 0011 */
	unsigned int d2 = (c >> TWO_BITS)  & HEX_PATTERN_0x3;
	unsigned int e = d0 + d2;
	
	unsigned int f0 = (e >> ZERO_BITS) & HEX_PATTERN_0x0F;     /* masking with 00001111 */
	unsigned int f4 = (e >> FOUR_BITS) & HEX_PATTERN_0x0F;
	unsigned int g = f0 + f4;
	
	unsigned int h0 = (g >> ZERO_BITS)  & HEX_PATTERN_0x00FF;  /* masking with 0000 0000 1111 1111 */
	unsigned int h8 = (g >> EIGHT_BITS) & HEX_PATTERN_0x00FF;
	unsigned int res = h0 + h8;
	
	return res;
	
}

/* EX10: This function prints the binary representation of a float */
void PrintFloatBinary(float num)
{
	unsigned int* ptr = (unsigned int*)&num;   
	unsigned int mask = BINARY_ONE << (BITS_IN_FLOAT - ONE_BIT);
	while (mask)
	{
		if (*ptr & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask >>= ONE_BIT;
	}
	printf("\n");
}

