/************************************************ 
EXERCISE 11   : atoi / iota
Implmented by : Snir Holland
Reviewed by   : 
Date          : 13/4/2023
File          : ws11.h
*************************************************/

#ifndef WS11_H
#define WS11_H

#include <stddef.h> /* size_t */

/************************************************************* 
Function: Itoa_Dec 
	* Description : Transforms an int (base 10) to string
	* Arguments :   value: the integer to be coverted.
	                str: pointer to buffer for result string.              
    * Returned Value : pointer to the first byte in the string
    * Remarks : argument must be a valid int.
                buffer must be large enough for output string.            
**************************************************************/
char *ItoaDec(int value , char *str);

/************************************************************* 
Function: Atoi_Dec 
	* Description : Transforms a string to an integer (base 10)
	* Arguments :   nptr: pointer to the first byte of the string.              
    * Returned Value : The converted value or 0 on error.           
**************************************************************/
int AtoiDec(const char *nptr);

/************************************************************* 
Function: Itoa 
	* Description : Transforms an int to string.
	* Arguments :   value: the integer to be coverted.
	                str: pointer to buffer for result string.
	                radix: any base from 2 to 36.              
    * Returned Value : pointer to the first byte in the result string
    * Remarks : argument must be a valid int.
                buffer must be large enough for output string.            
**************************************************************/
char *Itoa (int value, char *str, int radix);

/************************************************************* 
Function: Atoi 
	* Description : Transforms a string to an integer.
	* Arguments :   nptr: pointer to the first byte of the string.
	                radix: any base from 2 to 36.               
    * Returned Value : The converted value or 0 on error (fisrt
                       character is non alpha numeric).
             
**************************************************************/
int Atoi(const char *nptr, int radix);

/************************************************************* 
Function: TestAtoi 
	* Description : Compares between the system's atoi to my atoi
                    (decimal radix version).
	* Arguments :   nptr: pointer to the first byte of the string.                        
**************************************************************/
void TestAtoi(const char *nptr);

/************************************************************* 
Function: RunTestAtoi 
	* Description : Running the TestAtoi function with several inputs                                      
**************************************************************/
void RunTestAtoi();

/************************************************************* 
Function: PrintSpecialChars
	* Description : Prints characters which are in 
                    arrays 1 and 2 but not in array 3.
	* Arguments :   a1 , len1 : first array and its size
	                a2 , len2 : second array and its size
	                a3 , len3 : third array and its size                                            
**************************************************************/
void PrintSpecialChars(char a1[] , size_t len1 , char a2[] , size_t len2 , char a3[] , size_t len3);

/************************************************************* 
Function: IsLittleEndian
	* Description : checks the system's endianess	                          
    * Returned Value : 0/1 if the system is big/little endian.                                     
**************************************************************/
int IsLittleEndian();

/************************************************************* 
Function: IsLittleEndianMacro
	* Description : Calls a macro which determines the system's
                    Endianess.              
    * Returned Value : 0/1 if the system is big/little endian.
**************************************************************/
int IsLittleEndianMacro(); 




#endif
