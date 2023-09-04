#include "ws4.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


static int ValidateMalloc(void*);

void row_sum(int mat[ROWS][COLS], int result[ROWS])
{
	int i,j;
	
	for (i=0; i< ROWS; i++)
	{
		for (j=0; j < COLS; j++)
		{
			result[i] += mat[i][j];  
		}
	}
}

int josephus(int n)
{
	int i = 0;
	
	int* sold = (int*)malloc(sizeof(int) * n);
	if (NULL == sold )
   	{
		printf("Memory allocation failed.\n");
		return -1;
   	}
	
	/* fill soldiers array with the ones they want to kill */
	for(i=0; i<n-1; i++)
	{
		sold[i] = i + 1;
	}
	
	sold[n - 1] = 0;
	
	i = 0;
	
	/* at least one soldier alive */ 
	while (sold[i] != i)
	{
		/* kill closest soldier and snatch his number */
		int temp = sold[sold[i]];
		sold[sold[i]] = -1;
		sold[i] = temp;
		
		/* move on to the neighboor */ 
		i++;
		
		/* move on to the next soldier who is alive */ 
		while(sold[i] == -1)
		{
			i++;
			i = i % n;
		}
	}
	
	free(sold);
	sold = NULL;
	
	return i;
} 

void data_type()
{
	printf("sizeof(short int) is %lu bytes.\n" , sizeof(short int));
	printf("sizeof(unsigned short int) is %lu bytes.\n" , sizeof(unsigned short int));
	printf("sizeof(unsigned int) is %lu bytes.\n" , sizeof(unsigned int));
	printf("sizeof(int) is %lu bytes.\n" , sizeof(int));
	printf("sizeof(long int) is %lu bytes.\n" , sizeof(long int));
	printf("sizeof(unsigned long int) is %lu bytes.\n" , sizeof(unsigned long int));
	printf("sizeof(signed char) is %lu bytes.\n" , sizeof(signed char));
	printf("sizeof(unsigned char) is %lu bytes.\n" , sizeof(unsigned char));
	printf("sizeof(float) is %lu bytes.\n" , sizeof(float));
	printf("sizeof(double) is %lu bytes.\n" , sizeof(double));
	printf("sizeof(long double) is %lu bytes.\n" , sizeof(long double));
}

/* This utility function prints an array */
void print_array(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
}

/* This utility function prints a matrix (2D array version) */
void print_matrix(int mat[ROWS][COLS])
{
	int i,j;
	for (i=0; i<ROWS; i++)
	{
		for (j=0; j<COLS; j++)
		{
			printf("%d " , mat[i][j]);
		}
		printf("\n");
	}
}


/* This utility function prints a matrix (pointers version) */
void print_matrix_pnt(int** mat)
{
	int i,j;
	for (i=0; i<ROWS; i++)
	{
		for (j=0; j<COLS; j++)
		{
			printf("%d ", *( *(mat + i) + j ));
		}
		printf("\n");
	}
}

static int ValidateMalloc(void* ptr)
{
	if (NULL == ptr)
    {
 		printf("Memory allocation failed.\n");
		return -1;
    }
    return 0;
}


size_t CountEnv(char** vector)
{
	size_t index;
	for (index = 0; NULL != vector[index]; index++);
    return index;
}

int AllocateMemory(char*** dest_vec_ptr , char** source_vec , size_t env_counter)
{
	size_t i;
	*dest_vec_ptr = (char**)malloc(sizeof(char*) * env_counter);
	ValidateMalloc( (char**)(*dest_vec_ptr));
    
    for (i=0; i<env_counter; i++)
	{	
		/* memory allocation for each env varaible */
		*(*dest_vec_ptr + i) = (char*)malloc(sizeof(char) * (strlen(source_vec[i]) + 1) );
		ValidateMalloc( (char*) (*(*dest_vec_ptr + i)) );
   	}
   	return 0;
}

void CopyEnvStrings(char** dest_vec , char** source_vec , size_t env_counter)
{
	size_t i,j;
	for (i=0; i<env_counter; i++)
	{ 			
		strcpy(dest_vec[i] , source_vec[i] );
		for(j=0; j < strlen(dest_vec[i]); j++)
		{
			dest_vec[i][j] = tolower(dest_vec[i][j]);
		}			
	 }	 	
}


void PrintEnvStrings(char** dest_vec , size_t env_counter)
{
	size_t i;
	for (i=0; i<env_counter; i++)
	{
		printf("#%lu :  %s\n" , i , dest_vec[i]);
	}
}

void FreeAllocatedMem(char** dest_vec , size_t env_counter) /* this needs to be fixed */
{
	size_t i;
	for (i=0; i<env_counter; i++)
    {
    	free(dest_vec[i]);
    	dest_vec[i] = NULL;
    }
	free(dest_vec);
	dest_vec = NULL; 
}

