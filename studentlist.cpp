#include "studentlist.h"

Student* studentnode_creat()
{
	Student* student = (Student*)malloc(sizeof(Student));
	(*student).name = NULL;
	(*student).gender = false;
	(*student).id = 0;
	(*student).qq = 0;
	(*student).grade_math = 0;
	(*student).grade_English = 0;
	(*student).link = NULL;

	return student;
}

StudentList studentlist_creat(int n)
{
	StudentList student_list;
	student_list.head = studentnode_creat();
	Student* p = student_list.head;
	for(int i = 1; i <= n; i++)
	{
		Student* student_node = studentnode_creat();
		p->link = student_node;
		p = p->link;
	}

	return student_list;
}

void studentlist_erase(StudentList student_list, int n)
{
	
}

void studentlist_print(StudentList student_list)
{
	Student* p = student_list.head;
	p = p->link;
	while(p != NULL)
	{
		printf("%d\n", p->id);
		p = p->link;
	}
}