#include <stdio.h>
#include <stdlib.h>

#include "student.h"

typedef struct LinkList
{
	int length = 0;
	LinkNode* head = NULL;
}LinkList;

LinkNode* linklist_node_creat(); // finished
LinkNode* linklist_node_creat(LinkNode node); // finished
void linklist_node_delete(LinkNode* p); // finished

LinkList linklist_creat(int n); // finished
void linklist_clear(LinkList list); // finished

LinkNode* linklist_getnode(LinkList list, int n); // finished
void linklist_setnode(LinkList list, int n, LinkNode node); // finished

void linklist_push_back(LinkList list, LinkNode node); // finished
LinkNode linklist_pop_back(LinkList list); // finished

void linklist_insert(LinkList list, int n, LinkNode node); // finished
void linklist_erase(LinkList list, int n); // finished