#include "studentlist.h"

void studentlist_print(LinkList student_list)
{
	printf("姓名\t学号");
	print_space(n_name-7);
	printf("性别  学号  ");
	print_space(n_ID-4);
	printf("QQ  ");
	print_space(n_QQ-2);
	printf("数学成绩  英语成绩\n\n");

	LinkNode* p = student_list.head;
	p = p->link;
	while(p)
	{
		printf("%s", p->name);
		print_space(n_name+2-strlength(p->name));
		switch(p->gender)
		{
			case 0: printf("%s", "男 "); break;
			case 1: printf("%s", "女 "); break;
		}
		print_space(3);
		printf("%s", p->ID);
		print_space(n_ID+2-strlength(p->ID));
		printf("%s", p->QQ);
		print_space(n_QQ+2-strlength(p->QQ));
		printf("%.1f", p->grade_Math);
		char* str_Math;
		sprintf(str_Math, "%.1f", p->grade_Math);
		print_space(n_Math+6-strlength(str_Math));
		printf("%.1f\n", p->grade_English);

		p = p->link;
	}
}

void studentlist_modify_name(LinkList student_list, int n, char* str_name)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_name(LinkList list, int n, char* str_name)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->name)
	{
		free(student->name);
	}
	student->name = (char*)malloc( strlen(str_name) * sizeof(char) );
	strcpy(student->name, str_name);
}

void studentlist_modify_gender(LinkList student_list, int n, Gender gender)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_gender(LinkList list, int n, Gender gender)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->gender = gender;
}

void studentlist_modify_ID(LinkList student_list, int n, char* str_ID)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_gender(LinkList list, int n, Gender gender)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->ID)
	{
		free(student->ID);
	}
	student->ID = (char*)malloc( strlen(str_ID) * sizeof(char) );
	strcpy(student->ID, str_ID);
}

void studentlist_modify_QQ(LinkList student_list, int n, char* str_QQ)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_QQ(LinkList list, int n, char* str)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	if(student->QQ)
	{
		free(student->QQ);
	}
	student->QQ = (char*)malloc( strlen(str_QQ) * sizeof(char) );
	strcpy(student->QQ, str_QQ);
}

void studentlist_modify_grade_Math(LinkList student_list, int n, float grade)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_grade_Math(LinkList list, int n, float grade)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->grade_Math = grade;
}

void studentlist_modify_grade_English(LinkList student_list, int n, float grade)
{
	if(n < 0 || n >= student_list.length)
	{
		return position_warning(n, student_list.length, "void studentlist_modify_grade_Math(LinkList list, int n, float grade)");
	}

	LinkNode* student = linklist_getnode(student_list, n);
	student->grade_English = grade;
}

// void studentlist_write(LinkList student_list, char* filename)
// {

// }