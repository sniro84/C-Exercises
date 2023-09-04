#include "ws8.h"
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcpy */

#define MAX_BYTES_INT_STR 11   /* longest signed int : -2147483648 --> 11 bytes */

/* This function adds an integer to an integer */
static exit_status AddToInt(element_t *p_elem , int value);

/* This function adds an integer to a float */
static exit_status AddToFloat(element_t *p_elem , int value);

/* This function appends an integer to a string */
static exit_status AddToString(element_t *p_elem , int value);

/* This function initializes an int */
static exit_status CleanInt(element_t *p_elem);

/* This function initializes a float */
static exit_status CleanFloat(element_t *p_elem);

/* This function frees the memory that was allocated for the string */
static exit_status CleanString(element_t *p_elem);

/* This function prints an integer */
static void PrintInt(element_t *p_elem);

/* This function prints a float */
static void PrintFloat(element_t *p_elem);

/* This function prints a string */
static void PrintString(element_t *p_elem);


void PrintAll(element_t *elem_arr , size_t elem_len)
{
	size_t index = 0;
	
	printf("---Printing array---\n");
	for(index = 0; index<elem_len; index++)
	{
		(elem_arr + index) -> PrintSelf(elem_arr + index);	
	}
	printf("\n");
}

void CleanAll(element_t *elem_arr , size_t elem_len)
{
	size_t index = 0;
	
	for(index = 0; index<elem_len; index++)
	{
		(elem_arr + index) -> CleanUp(elem_arr + index);
	}
	printf("---Array has been cleaned---\n");
}

void AddAll(element_t *elem_arr , size_t elem_len , int value)
{
	size_t index = 0;
	
	for(index = 0; index<elem_len; index++)
	{
		(elem_arr + index) -> Add( elem_arr + index , value );
	}
	printf("---The value %d has been added to all elements---\n" , value);
}

void CreateInt(element_t *elem_arr , size_t index , int data)
{
	*(int*)&((elem_arr + index)->data) = data;
	(elem_arr + index) -> PrintSelf = &PrintInt;
	(elem_arr + index) -> CleanUp = &CleanInt;
	(elem_arr + index) -> Add = &AddToInt;
}  

void CreateFloat(element_t *elem_arr , size_t index, float data)
{
	*(float*)&((elem_arr + index)->data) = data; 	
	(elem_arr + index) -> PrintSelf = &PrintFloat;
	(elem_arr + index) -> CleanUp = &CleanFloat;
	(elem_arr + index) -> Add = &AddToFloat;
}

exit_status CreateString(element_t *elem_arr , size_t index, char *str)
{
	(elem_arr + index) -> data = (char*)malloc( (strlen(str) + 1) * sizeof(char));
	if ( NULL == ((elem_arr + index) -> data) )
	{
		printf("Memory allocation failed.\n");
		return FAILURE; 
	}

	strcpy( (elem_arr + index) -> data , str);
		
	(elem_arr + index) -> PrintSelf = &PrintString;
	(elem_arr + index) -> CleanUp = &CleanString;
	(elem_arr + index) -> Add = &AddToString;
	
	return SUCCESS;
}

static void PrintInt(element_t *p_elem)
{
	printf("%d\n" , *(int*)&(p_elem -> data) );	
}

static void PrintFloat(element_t *p_elem)
{
	printf("%f\n" , *(float*)&(p_elem -> data) ); 
}

static void PrintString(element_t *p_elem)
{
	if (p_elem -> data)
	{
		printf("%s\n" , (char*)(p_elem -> data) );
	}
}

static exit_status CleanInt(element_t *p_elem)
{
	*(int*)&(p_elem -> data) = 0;
	return SUCCESS;
}

static exit_status CleanFloat(element_t *p_elem)
{
	*(float*)&(p_elem -> data) = 0.0;
	return SUCCESS;
}

static exit_status CleanString(element_t *p_elem)
{
	free(p_elem -> data);
	p_elem -> data = NULL;
	return SUCCESS;
}

static exit_status AddToInt(element_t *p_elem , int value)
{
	*(int*)&(p_elem -> data) += value;			
	return SUCCESS;
}

static exit_status AddToFloat(element_t *p_elem , int value)
{
	*(float*)&(p_elem -> data ) += value;	
	return SUCCESS;
}

static exit_status AddToString(element_t *p_elem , int value)
{
	size_t dst_len = 0; 
	
	char *int_str = NULL;  
	
	int_str = (char*)malloc(sizeof(char) * MAX_BYTES_INT_STR);
	if (NULL == int_str)
	{
		printf("Memory allocation failed.\n");
		return FAILURE; 
	}
	 	
	sprintf(int_str , "%d" , value);  
	
	dst_len = strlen(p_elem -> data) + strlen(int_str) + 1;
	
	p_elem -> data = (char*)realloc(p_elem -> data , dst_len);
	if ( NULL == (p_elem -> data) )
	{
		printf("Memory allocation failed.\n");
		return FAILURE; 
	}
	
	strcat(p_elem -> data , int_str);
	
	free(int_str);
	int_str = NULL;
	
	return SUCCESS;	
}
