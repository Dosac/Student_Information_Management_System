#include "linklist.h"

LinkNode* linklist_node_creat()
{
	LinkNode* student = (LinkNode*)malloc(sizeof(LinkNode));
	if(!student)
	{
		printf("Error in \"LinkNode* linklist_node_creat()\",\n");
		printf("Failed to allicate memory!\n");
		exit(-1);
	}

	student->name = NULL;
	student->gender = male;
	student->ID = NULL;
	student->QQ = NULL;
	student->grade_Math = 0;
	student->grade_English = 0;
	student->link = NULL;

	return student;
}

void linklist_node_delete(LinkNode* p)
{
	if(!p)
	{
		return;
	}

	if(p->name)
	{
		free(p->name);
		p->name = NULL;
	}

	p->gender = male;

	if(p->ID)
	{
		free(p->ID);
		p->ID = NULL;
	}

	if(p->QQ)
	{
		free(p->QQ);
		p->QQ = NULL;
	}

	p->grade_Math = 0;
	p->grade_English = 0;
	p->link = NULL;
}