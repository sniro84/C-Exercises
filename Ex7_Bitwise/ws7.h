#ifndef WS7_H
#define WS7_H

/* EX1: This function returns the result of x*(2^y)  */
long Pow2(unsigned int x , unsigned int y);

/* EX2.a: This function returns true if n is a power of two (with loop) */
size_t IsPowOf2Loop(unsigned int n);

/* EX2.b: This function returns true if n is a power of two (without loop) */
size_t IsPowOf2(unsigned int n);

/* EX3: This function returns n + 1 with only bitwise operators */
int AddOne(int n);

/* EX4: This functions prints all the numbers which have 3 bits which are on */
void DisplayThreeBitNumbers(unsigned int numbers[] , size_t numbers_len);

/* EX5A: This function returns a character after mirroring its bits (with loop) */
unsigned char MirrorByteLoop(unsigned char ch);

/* EX5B: This function returns a character after mirroring its bits (Non-Loop Version) */
unsigned char MirrorByte(unsigned char b);

/* EX6A: This function returns true if both 2nd and 6th bits turned on, false otherwise */
size_t TwoAndSixBits(unsigned char b);

/* EX6B: This function returns true if at least  one of the 2nd/6th bits turned on, false otherwise */
size_t TwoOrSixBits(unsigned char b);

/* EX6C: This function returns the new charater after swapping 3rd and 5th bits */
unsigned char SwapBits(unsigned char data);

/* EX7: This function return the closest (smaller) positive number to num which is dividible by 16 */
unsigned int ClosestTo16(unsigned int num);

/* EX8: This function swaps the values of 2 variables with bitwise operations */
void SwapValues(int* p1 , int* p2);

/* EX9A: This function counts the number of set bits in an integer (Loop Version) */
size_t CountSetBitsLoop(int num);

/* EX9B: This function counts the number of set bits in an integer (Hamming Weight) */
size_t CountSetBits(int num);

/* EX10: This function prints the binary representation of a float */
void PrintFloatBinary(float num);

#endif
