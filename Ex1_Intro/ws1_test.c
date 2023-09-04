#include "ws1.h"

/* Implemented by Snir Holland at 16/3/23
   Reviewed by Yakov Polykovsky     */

int main()
{
	int x = 4729;
    int y = 99823175;
    int z = 83838;
    int a,b;
    
	/* EX3: Hello World */
	say_hello();
	printf("----------------------\n");
	
	/* EX4: Powers of Ten */
    printf("10^3  = %f \n" , powTen(3));
    printf("10^-5 = %f \n" , powTen(-5));
    printf("10^0  = %f \n" , powTen(0));
    printf("----------------------\n");
    
    /* EX5: Reversing an integer */
    printf("%d in reverse is :  %d\n" , x , reverseNum(x));
    printf("%d in reverse is :  %d\n" , y , reverseNum(y));
    printf("%d in reverse is :  %d\n" , z , reverseNum(z));
    printf("----------------------\n");
    
    /* EX6: Swapping int variables */
    a = 7;
    b = 3; 
    printf("Before calling swap : a = %d , b = %d \n" , a , b);
    swap(&a , &b);
    printf("After calling swap : a = %d , b = %d \n" , a , b);
    printf("----------------------\n");
    
    return 0;
}
