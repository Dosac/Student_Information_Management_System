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

	student->gender = male;
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
	p->gender = male;
	p->grade_Math = 0;
	p->grade_English = 0;
	p->link = NULL;
}