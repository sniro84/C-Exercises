/************************************************ 
EXERCISE 10   : Word Boundary
Implmented by : Snir Holland
Reviewed by   : Yehonathan Zarkovian
Date          : 11/4/2023
File          : ws10.h
*************************************************/

#ifndef WS10_H
#define WS10_H

#include <stddef.h>  /* size_t */

/************************************************************* 
Function: Memset
	* Description :      This function fills the first n bytes
                         of the memory area pointed to by s 
                         with the constant byte c.  
	* Arguments :        s: pointer to memory area.
	                     c: the byte to be copied.
	                     n: number of bytes to be copied.
    * Returned Value :   pointer to memory area s.                       
**************************************************************/
void *Memset(void *s , int c , size_t n); 


/************************************************************* 
Function: Memcpy
	* Description :      copies n bytes from memory area
                         src to memory area dest.  
	* Arguments :        dest: pointer to dest memory area.
	                     src: pointer to source memory area.
	                     n: number of bytes to be copied.
    * Returned Value :   pointer to memory area dest.
    * Restrictions   :   src and dest must not overlap.                       
**************************************************************/
void *Memcpy(void *dest ,const  void *src , size_t n);



/************************************************************* 
Function: Memmove
	* Description :      copies n bytes from memory area
                         src to memory area dest.  
	* Arguments :        dest: pointer to dest memory area.
	                     src: pointer to source memory area.
	                     n: number of bytes to be copied.
    * Returned Value :   pointer to memory area dest.
    * Remark :           The memory areas may overlap.                     
**************************************************************/
void *Memmove(void *dest ,const  void *src , size_t n);

#endif
