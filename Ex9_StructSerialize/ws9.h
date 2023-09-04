/************************************************ 
EXERCISE 9    : Struct Serialize
Implmented by : Snir Holland
Reviewed by   : Yehuda Tarona
Date          : 8/4/2023
File          : ws9.h
*************************************************/

#define MAX_BUF_LEN 20

/* status for file closing and openning */
typedef enum {
	ERROR_OPEN_FILE = -4 ,
	ERROR_CLOSE_FILE = -3 ,
	ERROR_WRITE_DATA = -2 ,
	ERROR_READ_DATA = -1 ,
	SUCCESS = 0
} status_t; 

/* science structure */
typedef struct science
{
	float physics;
	float biology;
} science_t;

/* engineering structure */			
typedef struct engineering
{
	float math;
	float coding;
} engineering_t;

/* realist structure */
typedef struct realist
{
	science_t science;
	engineering_t engineering;					
} realist_t;

/* humanist structure */
typedef struct humanist
{
	float literature;
	float history;
} humanist_t;  

/* grades structure */
typedef struct grades
{
	humanist_t humanist;
	realist_t realist;
	float sports;	
} grades_t;

/* student structure (outermost struct) */
typedef struct student
{
	char first_name[MAX_BUF_LEN];
	char last_name[MAX_BUF_LEN];
	grades_t grades;		
} student_t;

/************************************************************* 
Function: SerializeStudent 
	* Description : This function reads a student record
                    from struct and store it in a binary file.
	* Arguments : String of binary filename 
                  Pointer to a student struct
    * Returned Value : Status of serialization process.
    * Remarks : File name should contain legal characters.               
**************************************************************/
status_t SerializeStudent(const char *filename , student_t *stud_p);


/************************************************************* 
Function: DeSerializeStudent 
	* Description : This function reads a student record
	                from a binary file and store it in a struct.
	* Arguments : String of binary filename 
                  Pointer to a student struct
    * Returned Value : Status of deserialization process.
    * Remarks : File name should contain legal characters.               
**************************************************************/
status_t DeSerializeStudent(const char * filename , student_t *stud_p); 


