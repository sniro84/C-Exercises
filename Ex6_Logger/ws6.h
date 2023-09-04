#ifndef WS6_H
#define WS6_H

#define PRINT_LEN           10
#define BUF_LEN             100
#define FILE_LEN            20
#define NUM_OF_OPERATIONS   5
#define CLOSE_SUCCESS       0
#define TRUE                1
#define FALSE               0
#define OPER_FOUND          0
#define OPER_NOT_FOUND      -1 

/* EX1: Definition of function pointer */
typedef void (*Func_ptr)(int);

/* EX1: Structure of an integer and a function pointer */
typedef struct print_me
{
    int num;
    Func_ptr func_ptr;
   
} print_me;

/* EX1: This function recieves an integer and prints it */
void PrintVal(int num);

/* EX1: Run  */
void FunctionPointers(void);

/* EX2: Operations enum */
typedef enum oper_code {REMOVE ,COUNT,EXIT,INJECT,APPEND} oper_code;

/* EX2: Pointer to a comparison function */
typedef int (*Comparison_ptr)(char* , char*);

/* EX2: Pointer to an operation selcetor function */
typedef oper_code (*Operation_ptr)(char* , char*);

/* EX2: Structure that handles files */
typedef struct file_handler
{
    char flag[BUF_LEN];
    Comparison_ptr comp_ptr;
    Operation_ptr oper_ptr;
} file_handler;

/* EX2: Run  */
int RunLogger(void);

#endif  /* WS6_H */
