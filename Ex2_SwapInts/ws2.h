#ifndef WS2_H
#define WS2_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

/* This function swaps the values of two integers */
void swap_ints(int* a , int* b);

/* This function copies the contents of one int array to another */
void copyArr(int src[] , int dest[] , int srcLen, int destLen);

/* This function swaps the values of two size_t's  */
void swap(size_t* a , size_t* b);

/* This function swaps the values of two size_t*'s  */
void swap_pointers(size_t** p1 , size_t** p2);

/* This function gets a string  and returns its length */
size_t StrLen(const char* c);

/* This function returns -1 , 0 or 1 if str1 is lexicographically smaller/equal or greater than str2 */
int StrCmp(const char* str1, const char* str2);


#endif
