#include "ws5.h"
#include <stdlib.h>
#include <stdio.h>

typedef void (*Actions)(char);

/* This function ignores characters which are not A or T */
static void DoNothing(char);

/* This function prints a character if it's 'A' or 'T' */
static void PrintAT(char);

/* If-Else implementation */
void IfElseSol()
{
	char c ='\0';
		
	while (ESC != c )
	{
		
		scanf("%c" , &c );
		
		if (c == A || c == T)
		{
			PrintAT(c);
		}		
	}
}

/* Switch-Case implementation */
void SwitchCaseSol()
{
	char c = '\0';
	
	while (ESC != c)
	{
		scanf("%c" , &c );
		switch (c)
		{
			case  A:
    		case  T:
      			PrintAT(c);
		}
	}
	
}

/* LUT implementation */
void LutSol()
{
	char c = '\0';
	size_t index = 0;
	
	Actions key_actions[ASCII_LEN];
	
	for(index = 0; index<ASCII_LEN; index++)
	{
		key_actions[index] = &DoNothing;	
	}
	 
	key_actions[A] = &PrintAT;
	key_actions[T] = &PrintAT;	 
	
	while (c != ESC)
	{
		scanf("%c" , &c );
		key_actions[(size_t)c](c);		
	}
}

/* Disable terminal echoing and buffering */
void DisableTerminal()
{
	system("stty -icanon -echo"); 
}

/* Disable terminal echoing and buffering */
void EnableTerminal()
{
	system("stty icanon echo");
}

/* Print A or T */
static void PrintAT(char c)
{
	printf("%c-Pressed\n" , c);	
}

/* Ignore characters which are not A or T */
static void DoNothing(char c)
{
	(void)c;			
}

