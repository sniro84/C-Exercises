#ifndef WS8_H
#define WS8_H

#include <stddef.h>   /* size_t */

/* macros for exercises 5 to 7 */
#define MAX2(a,b)          ( (a) > (b) ? (a) : (b) )
#define MAX3(a,b,c)        ( MAX2(a,b) > MAX2(b,c) ? MAX2(a,b) : MAX2(b,c) )
#define SIZEOF_VAR(var)    ( (size_t)(&var + 1) - (size_t)(&var) )
#define SIZEOF_TYPE(type)  ( (type*)(NULL) + 1)

/* determines if memory allocation was successful or not */
typedef enum {SUCCESS , FAILURE} exit_status;

/* the structured element */
typedef struct element
{
	void *data;
	void (*PrintSelf)(struct element *);
	exit_status (*CleanUp)(struct element *);
	exit_status (*Add)(struct element * , int);
} element_t;

/* This function "adds" an int to each element in array */
void AddAll(element_t * , size_t , int);

/* This function frees dynamic memory which has been allocated for elements in array */
void CleanAll(element_t * , size_t);

/* This function prints all elements in array */
void PrintAll(element_t * , size_t);

/* This function creates an integer */
void CreateInt(element_t * , size_t , int);

/* This function creates a float */
void CreateFloat(element_t * , size_t , float);

/* This function creates a string */
exit_status CreateString(element_t * , size_t , char *);   

#endif

