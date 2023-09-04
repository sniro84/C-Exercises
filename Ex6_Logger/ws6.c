#include <string.h>    /* strlen() , strncmp() */
#include <stdlib.h>    /* exit() */
#include <stdio.h>     /* FILE and file handling functions */

#include "ws6.h"

/* This function deletes a file. */
static oper_code RemoveFile(char* , char*);

/* This function returns the number of lines in a file. */
static oper_code CountLines(char* , char*);

/* This function add lines in the beginning of a file. */
static oper_code InjectAtStart(char* , char*);

/* This function add lines in the end of a file. */
static oper_code AppendAtEnd(char* , char*);	

/* This function terminates the program. */
static oper_code Exit(char* , char*);

/* This function returns 0 if operation string matches the user's input. */
static int CompareString(char* , char*);

/* This function initializes the file handler array */
static void InitHandlerArray(file_handler*);

/* This function reads and processes data coming from the user */
static void AnalizeInput(file_handler* , char*);

/* This utility function opens a file in specific mode. */
static void OpenFile(const char*, FILE**, const char*);

/* This utility function closes a file in specific mode. */
static void CloseFile(FILE** fp);

/* This function prints an integer */
void PrintVal(int num)
{
	printf("%d " , num);
}

/* This function demonstrates the use of function pointers */
void FunctionPointers(void)
{
	size_t i;
	
	print_me print_blocks[PRINT_LEN];
	
	for(i = 0; i<PRINT_LEN; i++)
	{
		print_blocks[i].num = i*i;
		print_blocks[i].func_ptr = &PrintVal;	
	}
	
	
	for(i = 0; i<PRINT_LEN; i++)
	{
		print_blocks[i].func_ptr(print_blocks[i].num);
	}

}

/* This function runs the logger */
int RunLogger(void)
{
	char filename[FILE_LEN];
	file_handler handler[NUM_OF_OPERATIONS];
	
	printf("Please enter the file name: ");
	fgets(filename, FILE_LEN , stdin);  
	
	InitHandlerArray(handler);
	
	AnalizeInput(handler, filename); 
	
	return 0;	
}

static void InitHandlerArray(file_handler* handler)
{
	size_t i;
	
	strcpy(handler[0].flag , "-remove");
	strcpy(handler[1].flag , "-count");
	strcpy(handler[2].flag , "-exit");
	strcpy(handler[3].flag , "<");
	
	for(i = 0; i<NUM_OF_OPERATIONS - 1; i++)
	{
		handler[i].comp_ptr = &CompareString;
	}
	
	handler[0].oper_ptr = &RemoveFile;
	handler[1].oper_ptr = &CountLines;
	handler[2].oper_ptr = &Exit;
	handler[3].oper_ptr = &InjectAtStart;
	handler[4].oper_ptr = &AppendAtEnd;
}

static void AnalizeInput(file_handler* handler , char* filename)
{
	char buf[BUF_LEN];
	int comp_result;
	size_t i;
	
	while (TRUE)
	{
		size_t res;
		printf("Enter the line you want to add :");
		fgets(buf, BUF_LEN , stdin); 
		
		comp_result = 1;
		
		for(i = 0; i<NUM_OF_OPERATIONS - 1; ++i)
		{
			comp_result = handler[i].comp_ptr(buf,handler[i].flag);
			if (comp_result == 0)
			{
				res = handler[i].oper_ptr(filename , buf);
				if (EXIT == res)
				{
					exit(0);
				}
				break;
			}
		}
		if (comp_result)
		{
			handler[i].oper_ptr(filename , buf);
		} 
	}
}

static void OpenFile(const char* filename, FILE** fp , const char* mode)
{
	*fp = fopen(filename , mode);

	if (NULL == *fp)
	{
		printf("Error, Cannot open file.\n");
		exit(-1);
	}
}

/* This function closes a file */
static void CloseFile(FILE** fp)
{
	if (fclose(*fp) != CLOSE_SUCCESS)
	{
		printf("Error: failed to close file.\n");
		exit(-1); 
	}
}

static oper_code RemoveFile(char* filename , char* str)
{
	FILE* fp;
	OpenFile(filename , &fp , "r");
	
	(void)str;
	
	if (!remove(filename))
	{
		printf("The file has been deleted successfully!\n");
    }
    else
    {
    	printf("Error, Unable to delete the file!");
   	}
   	CloseFile(&fp);	
   	return REMOVE;
}

static oper_code CountLines(char* filename , char* str)
{
	size_t lines = 0;
	FILE* fp;
	char ch;
	
	(void)str;
	
	OpenFile(filename , &fp , "r");
	while(!feof(fp))
	{
  		ch = fgetc(fp);
  		if(ch == '\n')
  		{
    		lines++;
  		}
	}
	printf("Number of lines in the file : %lu.\n", lines);
	CloseFile(&fp);
	return COUNT;	
}

static oper_code Exit(char* filename , char* str)
{
	(void)str;
	(void)filename;
	
	return EXIT;
}

static oper_code InjectAtStart(char* filename , char* str)
{
	FILE* fp;
	FILE* temp_fp;
	char* tmp_file_name = "temp.txt";
	char c;
	
	++str;
	
	OpenFile(filename , &fp , "r");
	OpenFile(tmp_file_name , &temp_fp , "a"); 
	
	fputs(str , temp_fp);
	
	c = fgetc(fp);
	while(!feof(fp))
	{
		fputc(c,temp_fp);
  		c = fgetc(fp);
	}
	
	CloseFile(&fp);
	CloseFile(&temp_fp);
	
	rename(tmp_file_name,filename);
	return INJECT; 	
}

static oper_code AppendAtEnd(char* filename , char* str)
{
	FILE* fp;	
	OpenFile(filename , &fp , "a"); 
	
	fputs(str , fp);	

	CloseFile(&fp);
	return APPEND;
}

static int CompareString(char* str1 , char* str2)
{
	if ( !(strncmp(str1 , str2 , strlen(str2)) )   || (*str1 == '<' && *str2 == '<'))
	{
		return OPER_FOUND;
	}
	return OPER_NOT_FOUND;	
}		

