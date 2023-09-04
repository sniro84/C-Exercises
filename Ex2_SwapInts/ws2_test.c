#include "ws2.h"

/* Implemented by : Snir Holland, at 19/3/23
   Reviewed by    : Lee Sharvit 
*/


int main()
{
	int a = 3 , b = 7;
	int srcArr[] = {1, 2, 9, 4, 5};
    int destArr[25];
    int j, size = 5;
    static int s_i = 7;
	int i = 7;
	int* ptr = &i;
	int* ptr2 = (int*)malloc(sizeof(int));
	size_t c = 3 , d = 7;
	size_t* pc = &c;
    size_t* pd = &d;
        	
	/* EX1: Swapping values of two integers */
    printf("Values Before Swap : a = %d , b = %d \n", a , b);
    swap_ints(&a , &b);
    printf("Values After Swap  : a = %d , b = %d \n", a , b);
    printf("----------------------\n");
    
    
    /* EX2: Copy Array */
    printf("Printing original array : ");
    for(j=0; j<size; j++)
    	printf("%d " , srcArr[j]);
    printf("\n");

    copyArr(srcArr , destArr , 5 , 25);

    printf("Printing new copy of array : ");
    for(j=0; j<size; j++)
    	printf("%d " , destArr[j]);
    printf("\n");
    printf("----------------------\n");
    
    
    /* EX3: Printing Addresses */	
	if (ptr)
	{
		int** ptr3 = &ptr;
		printf("The address of ptr3    : %p\n" , (void*)*ptr3);
	}
	
	printf("The address of s_i  is : %p\n" , (void*)&s_i);
	printf("The address of i    is : %p\n" , (void*)&i);
	printf("The address of ptr  is : %p\n" , (void*)ptr);
	printf("The address of ptr2 is : %p\n" , (void*)ptr2);
	
	free(ptr2);
	printf("----------------------\n");
    
    
    /* EX4: Swapping values of two size_t's and their pointers */
    printf("Values Before Swap : c = %lu , d = %lu \n", c , d);
    swap(&c , &d);
    printf("Values After Swap  : c = %lu , d = %lu \n", c , d);
    
    printf("Adresses Before Swap Pointers: &c = %p , &d = %p \n", (void*)pc , (void*)pd);
    swap_pointers(&pc,&pd);
    printf("Adresses After  Swap Pointers: &c = %p , &d = %p \n", (void*)pc , (void*)pd);
    printf("----------------------\n");
    
    
    /* EX5: StrLen */
    printf("Lenght of an empty string     : %ld \n" , StrLen(""));
	printf("Lenght of the string 'Blah'   : %ld \n" , StrLen("Blah"));
	printf("----------------------\n");

	/* EX6: StrCmp */
	printf("StrCmp(abcde,abcde) = %d \n" , StrCmp("abcde","abcde") );
	printf("StrCmp(abcd,abcde) = %d \n" , StrCmp("abcd","abcde") );
	printf("StrCmp(abcde,abcd) = %d \n" , StrCmp("abcde","abcd") );
	printf("----------------------\n");
    
    return 0;
}
