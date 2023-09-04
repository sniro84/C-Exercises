#ifndef WS4_H
#define WS4_H

#define ROWS 4
#define COLS 3

#include <stdio.h>
#include <assert.h>
 

/* This function recieves a matrix and store the sum in result array */
void row_sum(int mat[ROWS][COLS], int result[ROWS]);

/* This function solves the josephus problem */ 
int josephus(int n); 

/* This function prints the sizes of each data type in C */
void data_type();

/* This function prints the matrix elements (2D array version) */
void print_matrix(int mat[ROWS][COLS]);

/* This function prints the matrix elements (doube pointers version)*/
void print_matrix_pnt(int** mat);

/* This utility function prints the contents of an array */
void print_array(int arr[], int size);

/* This utility function returns the number of environment vars */
size_t CountEnv(char** vector);

/* This utility function allocates memory for environment vars vector */
int AllocateMemory(char*** dest_vec_ptr , char** source_vec , size_t env_counter);

/* This utility function copy environment strings into vector and transform them into lower-case */
void CopyEnvStrings(char** dest_vec , char** source_vec , size_t env_counter); 

/* This utility function prints environment variables */
void PrintEnvStrings(char** dest_vec , size_t env_counter);

/* This utility function frees all the allocated memory for the env matrix */
void FreeAllocatedMem(char** dest_vec , size_t env_counter);

#endif
