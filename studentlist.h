#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char* name;
	bool gender;
	int id;
	int qq;
	float grade_math;
	float grade_English;
	Student* link;
}Student;

typedef struct StudentList
{
	Student* head;
}StudentList;

Student* studentnode_creat();
StudentList studentlist_creat(int n);
void studentlist_erase(StudentList student_list, int n);
void studentlist_modify(StudentList student_list, int n, int index, void* data);
void studentlist_append(StudentList student_list, Student student);
void studentlist_insert(StudentList student_list, int n, Student student);
void studentlist_clear(StudentList student_list);
void studentlist_print(StudentList student_list);