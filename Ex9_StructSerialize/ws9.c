/************************************************ 
EXERCISE 9    : Struct Serialize
Implmented by : Snir Holland
Reviewed by   : Yehuda Tarona
Date          : 8/4/2023
File          : ws9.c
*************************************************/

#include "ws9.h" 
 
#include <stdio.h>   /* FILE */
#include <string.h>  /* strlen , strncpy , memset*/

#define ONE_ITEM  (1)
#define NULL_TERM (1)

static status_t SerializeStudentName(FILE *fp , student_t *stud_p);
static status_t SerializeGrades(FILE *fp , grades_t *grades_p);
static status_t SerializeHumanist(FILE *fp , humanist_t *humanist_p);
static status_t SerializeRealist(FILE *fp , realist_t *realist_p);
static status_t SerializeSubject(FILE *fp , float *grade_p);
static status_t SerializeScience(FILE *fp , science_t *science_p);
static status_t SerializeEngineering(FILE *fp , engineering_t *engineering_p);

static status_t DeSerializeStudentName(FILE *fp , student_t *stud_p);
static status_t DeSerializeGrades(FILE *fp , grades_t *grades_p);
static status_t DeSerializeHumanist(FILE *fp , humanist_t *humanist_p);
static status_t DeSerializeRealist(FILE *fp , realist_t *realist_p);
static status_t DeSerializeSubject(FILE *fp , float *grade_p);
static status_t DeSerializeScience(FILE *fp , science_t *science_p);
static status_t DeSerializeEngineering(FILE *fp , engineering_t *engineering_p);

/* This function reads a student record from struct and store it in a binary file */
status_t SerializeStudent(const char *filename , student_t *stud_p)
{
	FILE *fp = NULL;
	
	status_t is_valid_name = SUCCESS;
	status_t is_valid_grades = SUCCESS;
		
	fp = fopen(filename , "wb");
	if (NULL == fp)
	{
		return ERROR_OPEN_FILE;
	}
	
	is_valid_name = SerializeStudentName(fp , stud_p);
	is_valid_grades = SerializeGrades(fp , &(stud_p->grades) );
	if (is_valid_grades != SUCCESS || is_valid_name != SUCCESS)
	{
		return ERROR_WRITE_DATA;
	}
	
	if (fclose(fp))
	{
		return ERROR_CLOSE_FILE;
	}
	
	return SUCCESS;
}

static status_t SerializeStudentName(FILE *fp , student_t *stud_p)
{
	size_t first_name_len = strlen(stud_p->first_name);
	size_t last_name_len = strlen(stud_p->last_name);
	
	/* store length of first name string and then string in file */
	fwrite(&first_name_len , sizeof(size_t) , ONE_ITEM , fp); 
	if ( !(fwrite(stud_p->first_name , sizeof(char) , first_name_len , fp)) )
	{
		return ERROR_WRITE_DATA;
	}
	
	/* store length of last name string and then string in file */
	fwrite(&last_name_len , sizeof(size_t) , ONE_ITEM , fp); 
	if ( !(fwrite(stud_p->last_name , sizeof(char) , last_name_len , fp)) )
	{
		return ERROR_WRITE_DATA;
	}
	
	return SUCCESS;	
}

static status_t SerializeGrades(FILE *fp , grades_t *grades_p)
{
	status_t res_human = SerializeHumanist(fp , &(grades_p->humanist) );  
	status_t res_real = SerializeRealist(fp , &(grades_p->realist) );
	status_t res_sports = SerializeSubject(fp , &(grades_p->sports) );
	
	if (res_human == SUCCESS && res_real == SUCCESS && res_sports == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;
}

static status_t SerializeSubject(FILE *fp , float *grade_p)
{
	if ( !(fwrite(grade_p , sizeof(float) , ONE_ITEM , fp)) )
	{
		return ERROR_WRITE_DATA;
	}
	return SUCCESS;
}

static status_t SerializeHumanist(FILE *fp , humanist_t *humanist_p)
{
	status_t res_literature = SerializeSubject(fp , &(humanist_p->literature) );
	status_t res_history = SerializeSubject(fp , &(humanist_p->history) );
	
	if (res_literature == SUCCESS && res_history == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;
}

static status_t SerializeRealist(FILE *fp , realist_t *realist_p)
{
	status_t res_science = SerializeScience(fp , &(realist_p->science) );
	status_t res_engineering = SerializeEngineering(fp , &(realist_p->engineering) );
	
	if (res_science == SUCCESS && res_engineering == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;
}

static status_t SerializeScience(FILE *fp , science_t *science_p)
{
	status_t res_biology = SerializeSubject(fp , &(science_p->biology) );
	status_t res_physics = SerializeSubject(fp , &(science_p->physics) );
	
	if (res_biology == SUCCESS && res_physics == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;	
}

static status_t SerializeEngineering(FILE *fp , engineering_t *engineering_p)
{
	status_t res_math = SerializeSubject(fp , &(engineering_p->math) );
	status_t res_coding = SerializeSubject(fp , &(engineering_p->coding) );
	
	if (res_math == SUCCESS && res_coding == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;	
}

/* This function reads a student record from a binary file and store it in a struct */
status_t DeSerializeStudent(const char *filename , student_t *stud_p)
{
	FILE *fp = NULL;
	
	status_t is_valid_name = SUCCESS;
	status_t is_valid_grades = SUCCESS;
		
	fp = fopen(filename , "rb");
	if (NULL == fp)
	{
		return ERROR_OPEN_FILE;
	}
	
	is_valid_name = DeSerializeStudentName(fp , stud_p);
	is_valid_grades = DeSerializeGrades(fp , &(stud_p->grades) );
	if (is_valid_grades != SUCCESS || is_valid_name != SUCCESS)
	{
		return ERROR_READ_DATA;
	}
	
	if (fclose(fp))
	{
		return ERROR_CLOSE_FILE;
	}
	
	return SUCCESS;
}

static status_t DeSerializeSubject(FILE *fp , float *grade_p)
{
	if ( !(fread(grade_p , sizeof(float) , ONE_ITEM , fp) ) ) 
	{
		return ERROR_READ_DATA;
	}			
	return SUCCESS;
}

static status_t DeSerializeStudentName(FILE *fp , student_t *stud_p)
{
	/* temporary buffer for copying strings */
	char buf[MAX_BUF_LEN] = {'\0'};
	
	size_t first_name_len = 0;
	size_t last_name_len = 0;
	
	/* read length of first name --> read first name string 
	   and store in buf --> copy from buf to struct */
	fread(&first_name_len , sizeof(size_t) , ONE_ITEM , fp); 
	if ( !(fread(buf , sizeof(char) , first_name_len , fp)) )
	{
		return ERROR_WRITE_DATA;
	}
	strncpy(stud_p->first_name , buf , first_name_len + NULL_TERM);
	
	/* init buf */
	memset(buf, '\0', MAX_BUF_LEN);
	
	/* read length of last name --> read last name string 
	   and store in buf --> copy from buf to struct */
	fread(&last_name_len , sizeof(size_t) , ONE_ITEM , fp); 
	if ( !(fread(buf , sizeof(char) , last_name_len , fp)) )
	{
		return ERROR_WRITE_DATA;
	}
	strncpy(stud_p->last_name , buf , last_name_len + NULL_TERM);
	
	return SUCCESS;	
}

static status_t DeSerializeGrades(FILE *fp , grades_t *grades_p)
{
	status_t res_human = DeSerializeHumanist(fp , &(grades_p->humanist) );  
	status_t res_real = DeSerializeRealist(fp , &(grades_p->realist) );
	status_t res_sports = DeSerializeSubject(fp , &(grades_p->sports) );
	
	if (res_human == SUCCESS && res_real == SUCCESS && res_sports == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;
}

static status_t DeSerializeHumanist(FILE *fp , humanist_t *humanist_p)
{
	status_t res_literature = DeSerializeSubject(fp , &(humanist_p->literature) );
	status_t res_history = DeSerializeSubject(fp , &(humanist_p->history) );
	
	if (res_literature == SUCCESS && res_history == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;	
}

static status_t DeSerializeRealist(FILE *fp , realist_t *realist_p)
{
	status_t res_science = DeSerializeScience(fp , &(realist_p->science) );
	status_t res_engineering = DeSerializeEngineering(fp , &(realist_p->engineering) );
	
	if (res_science == SUCCESS && res_engineering == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;
}

static status_t DeSerializeScience(FILE *fp , science_t *science_p)
{
	status_t res_biology = DeSerializeSubject(fp , &(science_p->biology) );
	status_t res_physics = DeSerializeSubject(fp , &(science_p->physics) );
	
	if (res_biology == SUCCESS && res_physics == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;	
}

static status_t DeSerializeEngineering(FILE *fp , engineering_t *engineering_p)
{
	status_t res_math = DeSerializeSubject(fp , &(engineering_p->math) );
	status_t res_coding = DeSerializeSubject(fp , &(engineering_p->coding) );
	
	if (res_math == SUCCESS && res_coding == SUCCESS)
	{
		return SUCCESS;
	}
	return ERROR_WRITE_DATA;	
}

