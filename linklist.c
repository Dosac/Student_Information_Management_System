#include "linklist.h"

LinkList linklist_creat(int n)
{
	LinkList list;

	list.head = linklist_node_creat();
	if(n < 0)
	{
		list.length = 0;
		printf("Warning: in \"LinkList linklist_creat(int n)\", n is negetive.\n");
		printf("Creat an empty list.\n");
		return list;
	}
	list.length = n;

	LinkNode* p = list.head;
	for(int i = 1; i <= n; i++)
	{
		LinkNode* node = linklist_node_creat();
		p->link = node;
		p = p->link;
	}

	return list;
}

void linklist_clear(LinkList list)
{
	LinkNode* p = list.head;
	while(list.head->link)
	{
		p = list.head->link;
		list.head->link = p->link;
		linklist_node_delete(p);
		free(p);
	}
	list.length = 0;
}

LinkNode* linklist_getnode(LinkList list, int n)
{
	if(n < 0)
	{
		printf("Warning: in \"LinkNode* linklist_getnode(LinkList list, int n)\", n is negtive!\n");
		printf("Return a null pointer!\n");
		return NULL;
	}
	if(n >= list.length)
	{
		printf("Warning: in \"LinkNode* linklist_getnode(LinkList list, int n)\", n is over list's length!\n");
		printf("Return a null pointer!\n");
		return NULL;
	}

	LinkNode* p = list.head;
	for(int i = 0; i <= n; i++)
	{
		p = p->link;
	}

	return p;
}

void position_warning(int n, int n_upperlimit, char* function_name)
{
	printf("Warning: in ");
	printf("\"%s\"", function_name);
	if(n < 0)
	{
		printf(", n is negtive!\n");
	}
	if(n >= n_upperlimit)
	{
		printf(", n over list's length!\n");
	}
	printf("Nothing has been done!\n");
}

void linklist_setnode(LinkList list, int n, LinkNode node)
{
	if(n < 0 || n >= list.length)
	{
		return position_warning(n, list.length, "void linklist_setnode(LinkList list, int n, LinkNode node)");
	}

	LinkNode* p = linklist_getnode(list, n);
	*p = node;
}

void linklist_push_back(LinkList list, LinkNode node)
{
	LinkNode* p = list.head;
	while(p->link)
	{
		p = p->link;
	}
	p->link = linklist_node_creat();
	node.link = NULL;
	*(p->link) = node;

	list.length++;
}

LinkNode linklist_pop_back(LinkList list)
{
	LinkNode* p = list.head;
	while(p->link)
	{
		p = p->link;
	}
	LinkNode node = *p;
	linklist_node_delete(p);
	free(p);

	list.length--;
	return node;
}

void linklist_insert(LinkList list, int n, LinkNode node)
{
	if(n < 0 || n >= list.length)
	{
		return position_warning(n, list.length, "void linklist_insert(LinkList list, int n, LinkNode node)");
	}

	LinkNode* p = linklist_getnode(list, n-1);
	LinkNode* p_next = p->link;
	LinkNode* newNode = linklist_node_creat();
	*newNode = node;
	p->link = newNode;
	newNode->link = p_next;

	list.length++;
}

void linklist_erase(LinkList list, int n)
{
	if(n < 0 || n >= list.length)
	{
		return position_warning(n, list.length, "void linklist_erase(LinkList list, int n)");
	}

	LinkNode* p = linklist_getnode(list, n-1);
	LinkNode* p_current = p->link;

	p->link = p->link->link;
	linklist_node_delete(p_current);
	free(p_current);

	list.length--;
}