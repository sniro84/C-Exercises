#ifndef WS3_H
#define WS3_H

#include <stddef.h>

/* This function copies a string from src to dest */
char* StrCpy(char* dest, const char* src);

/* This function copies a string from src to dest */
char* StrnCpy(char* dest, const char* src, size_t n);

/* This function compares between the first n bytes of two strings */
int StrnCmp(const char* str1, const char* str2, size_t n);

/* This function compares between two strings, without considering case */
int StrCaseCmp(const char* str1, const char* str2);

/* This function is used to dynamically allocate a string */
char* StrDup(const char* s); 

/* This function returns a pointer to the first occourence*/
char* StrChr(const char* str, int c);

/* This function concatnates dest string to source string */
char* StrCat(char* dest, const char* src);

/* This function concatinates dest string to source string */
char* StrnCat(char *dest, const char *src , size_t n);

/* This function returns the first occurence of a substring (needle) in a string (haystack) */
char* StrStr(const char* haystack, const char* needle);

/* This function returns The length of the initial portion
   of string s containing only characters that appear in accept. */
size_t StrSpn(const char* s, const char* accept);

/* This helper function returns the length of the string */
size_t StrLen(const char* str);

#endif
