#ifndef WS3_H
#define WS3_H

#define TRUE 1
#define FALSE 0 

/* This function returns 1 if the string is a palindrom and zero otherwise */ 
int is_palindrom(char* str);

/* This function prints all the numbers in a range that are not containing 7 or are devisible by 7,  
   The other numbers are replaced by the word BOOM! */
void seven_boom(int from,int to);

/* This helper funtion returns 1 (True) if the digit 7 is contained in num, and 0 (False) otherwise */
int include_seven(int num);

#endif
