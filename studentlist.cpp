#include "studentlist.h"

void studentlist_print(LinkList student_list)
{
	printf("姓名\t 性别\t学号\t\t QQ\t\t\t数学成绩  英语成绩\n\n");
	LinkNode* p = student_list.head;
	p = p->link;
	while(p)
	{
		printf("%s\t ", p->name);
		switch(p->gender)
		{
			case 0: printf("%s\t", "男"); break;
			case 1: printf("%s\t", "女"); break;
		}
		printf("%s\t\t %s\t\t\t%.1f\t%.1f\n", p->ID, p->QQ, p->grade_math, p->grade_English);
		p = p->link;
	}
}

void studentlist_modify(LinkList list, int n, int index, void* data)
{
	if(n < 0)
	{
		printf("Warning: in \"void studentlist_modify(LinkList list, int n, int index, void* data)\", n is negtive!\n");
		printf("Nothing has been done!\n");
		return;
	}
	if(n >= list.length)
	{
		printf("Warning: in \"void studentlist_modify(LinkList list, int n, int index, void* data)\", n over list's length!\n");
		printf("Nothing has been done!\n");
		return;
	}

	LinkNode* student = linklist_getnode(list, n);
	switch(index)
	{
		case 1: strcpy(student->name, (char*)data); break;
		case 2: student->gender = *((Gender*)data); break;
		case 3: strcpy(student->ID, (char*)data); break;
		case 4: strcpy(student->QQ, (char*)data); break;
		case 5: student->grade_math = *((float*)data); break;
		case 6: student->grade_English = *((float*)data); break;
		default:
		{
			printf("Warning: in \"void studentlist_modify(LinkList list, int n, int index, void* data)\", index is over 6!\n");
			printf("Nothing has been done!\n");
			return;
		}
	}
}

void studentlist_modify_name(LinkList list, int n, char* str_name)
{
	if(n < 0)
	{
		printf("Warning: in \"void studentlist_modify_name(LinkList list, int n, char* str)\", n is negtive!\n");
		printf("Nothing has been done!\n");
		return;
	}
	if(n >= list.length)
	{
		printf("Warning: in \"void studentlist_modify_name(LinkList list, int n, char* str)\", n over list's length!\n");
		printf("Nothing has been done!\n");
		return;
	}

	LinkNode* student = linklist_getnode(student_list, n);
	strcpy(student->name, str_name);
}

void studentlist_modify_gender(LinkList list, int n, Gender gender)
{
	if(n < 0)
	{
		printf("Warning: in \"void studentlist_modify_gender(LinkList list, int n, Gender gender)\", n is negtive!\n");
		printf("Nothing has been done!\n");
		return;
	}
	if(n >= list.length)
	{
		printf("Warning: in \"void studentlist_modify_gender(LinkList list, int n, Gender gender)\", n over list's length!\n");
		printf("Nothing has been done!\n");
		return;
	}

	LinkNode* student = linklist_getnode(student_list, n);
	strcpy(student->name, str_name);
}
void studentlist_modify_ID(LinkList list, int n, char* str);
void studentlist_modify_QQ(LinkList list, int n, char* str);
void studentlist_modify_grade_Math(LinkList list, int n, float grade);
void studentlist_modify_grade_Englist(LinkList list, int n, float grade);

// void studentlist_write(LinkList student_list, char* filename)
// {

// }