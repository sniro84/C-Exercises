#include "ws4.h"

#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[], char * envp[])
{
	size_t env_count = 0;
	char** env_vec = NULL;	
	 
	/* EX1: Sum of rows in a matrix */
	int mat[ROWS][COLS] = { {3,7,4} , {2,1,9} , {5,5,5} , {8,2,5} };
	
	int sums[ROWS];
	
	/* displaying the matrix */
	printf("The matrix : \n");
	print_matrix(mat);
	
	/* calculate sum of rows and show result*/
	row_sum(mat , sums);
	printf("\nSum of each row : \n");
	print_array(sums, ROWS);
	
	printf("\n\n");	
	/*-----------------------------------*/
	
	/* EX2: Josephus problem */
	printf("The Josephus problem :\n");	
	printf("josephus(4) = %d\n" , josephus(4));
	printf("josephus(6) = %d\n" , josephus(6));
	printf("josephus(100) = %d\n" , josephus(100));
	
	printf("\n");		
	/*-----------------------------------*/
	
	/* EX3: Data type in C and their size */
	printf("Data types and their size : \n");
	data_type();
	
	printf("\n");	
	/*-----------------------------------*/
	
	/* EX4: Print enviroment variable */
    printf("Enviroment variables :\n");
   
    /* turn off annoying warnings*/
    if (argc){};
    if (argv){};	  
   
	/* counting enviroment vars */
	env_count = CountEnv(envp);
   
    /* memory allocation for env_vec matrix*/
    AllocateMemory(&env_vec , envp , env_count);
    
    /* copy env strings to vector and transform them into lowercase */ 
    CopyEnvStrings(env_vec , envp , env_count);  
   
    
	/* print the env variables */
	PrintEnvStrings(env_vec , env_count);
	 
	/* free allocated memory */ 
	FreeAllocatedMem(env_vec , env_count); 
	   
	printf("\n\n");	
	/*-----------------------------------*/
	
	printf("Done...\n");
    return 0;
}

