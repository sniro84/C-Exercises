#include <stdio.h>
#include "ws7.h"

/* Implmented by: Snir Holland at 31/3/2023
   Reviewed by :  Yonathan Zarkovian
*/

int main()
{
	size_t index = 0;	
	
	/* EX1: */
	unsigned int x = 5;
	unsigned int y = 4;
	
	/* EX2: */
	unsigned int numbers_A[4] = {64,100,7,4096}; 

	/* EX3: */
	int z = 9;
	int w = -7;
	
	/* EX4: */
	unsigned int numbers_B[7] = {22 , 1 , 7 , 28 , 37, 64 , 129};
	
	/* EX5: */
	unsigned char c = 175;
	
	/* EX6: */
	unsigned char chars_A[5] = {'2','b','a','E','?'};
	unsigned char chars_B[5] = {'B','5','0','P','X'};
	unsigned char ch = 'R';
	
	/* EX7: */
	unsigned int numbers_C[4] = {33 , 17, 64 , 100};
	
	/* EX8: */
	int val1 = 4;
	int val2 = 17;
	
	/* EX9: */
	int p = 4096;
	int q = 15;
	int u = 28;
	int v = 27834;
	
	/* EX10: */
	float f = 0.0;
	
	/*-------------End of Variables------------------ */
	
	/* EX1: Testers */
	printf("EX1:\n");
	printf("Result: %i * 2 ^ %i = %ld\n" , x , y , Pow2(x,y) );
	printf("---------End of EX1------------\n\n");
	
	/* EX2 (Part A): Testers  */
	printf("EX2A: \n");
	for(index = 0; index<4; index++)
	{
		size_t res = IsPowOf2Loop(numbers_A[index]);
		printf("Number: %d , Answer: " , numbers_A[index]);
		if (res)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		  
	}
	
	/* EX2 (Part B): Testers  */
	printf("EX2B:\n");
	for(index = 0; index<4; index++)
	{
		size_t res = IsPowOf2(numbers_A[index]);
		printf("Number: %d , Answer: " , numbers_A[index]);
		if (res)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}		  
	}
	printf("---------End of EX2------------\n\n");
	
	/* EX3: Testers */
	printf("EX3:\n");	
	printf("%d + 1 = %d.\n" , z , AddOne(z));
	printf("%d + 1 = %d.\n" , w , AddOne(w));
	printf("---------End of EX3------------\n\n");
	
	/* EX4: Testers */
	printf("EX4:\n");
	DisplayThreeBitNumbers(numbers_B, 7);
	printf("---------End of EX4------------\n\n");  
	
	/* EX5: Testers */
	printf("EX5: \n");
	printf("10101111 in binary is 175.\n");
	printf("11110101 in binary is 245.\n");
	printf("MirrorByteLoop(%d) = %d.\n" , c , MirrorByteLoop(c)); 
	printf("MirrorByte(%d) = %d.\n" , c , MirrorByte(c));
	printf("---------End of EX5------------\n\n"); 
	
	/* EX6: Testers */
	printf("EX6A: \n");
	printf("Characters with second AND six bits on : '2' , 'b' , '?' . \n");
	printf("Characters without second AND six bits on : 'a' , 'E' . \n");
	for(index = 0; index < 5; index++)
	{
		if ( TwoAndSixBits(chars_A[index])  )
		{
			printf("'%c' have both of these bits on.\n" , chars_A[index] ); 
		}
		else
		{
			printf("'%c' doesn't have both of these bits on.\n" , chars_A[index]); 
		}
	}
	
	printf("EX6B: \n");
	printf("Characters with second OR six bits on : 'B' , '5', '0' . \n");
	printf("Characters without second OR six bits on : 'P' , 'X' . \n");
	for(index = 0; index < 5; index++)
	{
		if ( TwoOrSixBits(chars_B[index])  )
		{
			printf("'%c' have at least one of these bits on.\n" , chars_B[index] ); 
		}
		else
		{
			printf("'%c' have neither one of these bits on.\n" , chars_B[index]); 
		}
	}
	
	printf("EX6C: \n");
	printf("The binary representation of 'R' is 01010010 (82) .\n");
	printf("The binary representation of 'F' is 01000110 (70) .\n");
	printf("SwapBits('%c') = %d.\n" , ch , SwapBits(ch));
	printf("---------End of EX6------------\n\n");
	  
	printf("EX7: \n");
	for(index = 0; index < 4; index++)
	{
		printf("ClosestTo16(%d) = %d.\n" , numbers_C[index] , ClosestTo16(numbers_C[index] )); 
	}
	printf("---------End of EX7------------\n\n");
	
	printf("EX8: \n");
	printf("Values before swap : val1 = %d , val2 = %d\n" , val1 , val2);
	SwapValues(&val1 , &val2);
	printf("Values before swap : val1 = %d , val2 = %d\n" , val1 , val2);
	printf("---------End of EX8------------\n\n");
	
	printf("EX9: \n");
	printf("%d has %lu bits on. \n" , p , CountSetBitsLoop(p) );
	printf("%d has %lu bits on. \n" , q , CountSetBitsLoop(q) );
	printf("%d has %lu bits on. \n" , u , CountSetBitsLoop(u) );
	printf("Using hamming weight: the integer %d has %lu bits on. \n" , v , CountSetBits(v) );
	printf("---------End of EX9------------\n\n");  
	
	printf("EX10: \n");
	printf("Please enter a float number : ");
	scanf("%f" , &f);
	printf("Binary representation of %f is : " , f);
	PrintFloatBinary(f);
	printf("---------End of EX10------------\n\n");
	   	
	return 0;
}
