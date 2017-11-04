#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "student.h"

typedef struct LinkList
{
	int length;
	LinkNode* head;
}LinkList;

LinkNode* linklist_node_creat(); // finished
void linklist_node_delete(LinkNode* p); // finished

LinkList linklist_creat(int n); // finished
void linklist_clear(LinkList list); // finished

LinkNode* linklist_getnode(LinkList list, int n); // finished
void linklist_setnode(LinkList list, int n, LinkNode node); // finished

void linklist_push_back(LinkList list, LinkNode node); // finished
LinkNode linklist_pop_back(LinkList list); // finished

void linklist_insert(LinkList list, int n, LinkNode node); // finished
void linklist_erase(LinkList list, int n); // finished

void position_warning(int n, int n_upperlimit, char* function_name); // finished