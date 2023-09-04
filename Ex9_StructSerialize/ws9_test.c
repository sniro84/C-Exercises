/************************************************ 
EXERCISE 9    : Struct Serialize
Implmented by : Snir Holland
Reviewed by   : Yehuda Tarona
Date          : 8/4/2023
File          : ws9_test.c
*************************************************/

#include <stdio.h>  /* printf */
#include <string.h> /* strcpy */
#include "ws9.h" 

static void PrintStudRecord(student_t *stud_p);
static void CreateStudRecord(student_t *stud_p);

int main(void)
{
	student_t student = {0};   /* first student record */
	student_t temp_stud = {0}; /* the new student with empty record for now */
	   
	CreateStudRecord(&student);

	/* Save student record into a binary file */
	SerializeStudent("student.bin" , &student);
	
	/* Load student record from a binary file into a sturct */
	DeSerializeStudent("student.bin" , &temp_stud);
	
	PrintStudRecord(&temp_stud);
	
	return (0);
}


static void CreateStudRecord(student_t *stud_p)
{
	/* creating the first student record */
	strcpy(stud_p->first_name , "Snir");
	strcpy(stud_p->last_name , "Holland");
	
	stud_p->grades.humanist.literature = 80;	
	stud_p->grades.humanist.history = 75;	
	stud_p->grades.realist.science.physics = 95.5;	
	stud_p->grades.realist.science.biology = 83;	
	stud_p->grades.realist.engineering.math = 92;	
	stud_p->grades.realist.engineering.coding = 87.5;	
	stud_p->grades.sports = 98;
}

static void PrintStudRecord(student_t *stud_p)
{
	/* printing new student record after getting it from binary file */
	printf("Student details :\n");
	printf("First Name: %s\n" , stud_p->first_name);	 
	printf("Last Name: %s\n" , stud_p->last_name);
	
	printf("\n");
	printf("Grades :\n");
	printf("%s: %.2f\n" , "Literature" , stud_p->grades.humanist.literature); 	                   
	printf("%s: %.2f\n" , "History" , stud_p->grades.humanist.history);
	printf("%s: %.2f\n" , "Physics" , stud_p->grades.realist.science.physics);                    
	printf("%s: %.2f\n" , "Biology" , stud_p->grades.realist.science.biology);                    
	printf("%s: %.2f\n" , "Math" , stud_p->grades.realist.engineering.math);                    
	printf("%s: %.2f\n" , "Engineering" , stud_p->grades.realist.engineering.coding); 
	printf("%s: %.2f\n" , "Sports" , stud_p->grades.sports); 
	                                         
}

