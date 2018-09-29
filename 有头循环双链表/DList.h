#pragma once

#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

typedef int Datatype;

typedef struct DNode 
{
	Datatype data;
	struct DNode* next;
	struct DNode* prev;
}DN;


//�����ڵ�
DN* CreateDNode(Datatype d)
{
	DN* node = (DN*)malloc(sizeof(DN));
	node->data = d;
	node->next = NULL;
	node->prev = NULL;
	return node;
}


//��ʼ��/����
void InitDList(DN** phead)
{
	assert(phead);
	DN* node = CreateDNode(0);

	node->next = node;
	node->prev = node;
	*phead = node;
}


//�����������ͷ��㣩
void Empty(DN* head)
{
	DN* next = NULL;
	for (DN* cur = head->next; cur != head;cur=next)
	{
		next = next->next;
		free(cur);
	}
	head->next = head->prev = NULL;
}


void DestroyDList(DN* head)
{
	Empty(head);
	free(head);
}



// ���뵽 pos ��ǰ��	��posһ���������У�
void InsertDList(DN* head, DN* pos, Datatype d)
{
	DN* node = CreateDNode(d);
	node->prev = pos->prev;
	node->next = pos;
	pos->prev = node;
	node->prev->next = node;
}


// ���������ǰ��
// �͵���������𣬲���Ҫ����ָ����
void PushFront(DN* head, Datatype d)
{
	DN* node = CreateDNode(d);
	node->next=head->next;
	head->next->prev=node;
	node->prev = head;
	head->next = node;
#if 0
	InsertDList(head, head->next, d);
#endif
}

void PushBack(DN* head, Datatype d)
{
#if 0
	InitDList(DN* head,DN* head,Datatype d);
#endif

	DN* node = CreateDNode(d);
	node->prev = head->prev;
	head->prev->next = node;
	node->next = head;
	head->prev = node;
}


// pos �������е�����һ����㣨ͷ��㣩
void Erase(DN* head, DN*pos)
{
	assert(head->next != head);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}


void PopFront(DN* head)
{
	assert(head->next != head);
	DN* Del = head->next;
	head ->next= Del->next;
	Del->next->prev = head;
	free(Del);
#if 0
	Erase(head,head->next);
#endif
	
}


void PopBack(DN* head)
{
	assert(head->next != head);
	DN* Del = head->prev;
	head->prev = Del->prev;
	Del->prev->next = head;
	free(Del);

#if 0
	Empty(head,head->prev;)
#endif
}


void PrintDList(DN* head)
{
	for (DN* cur = head->next; cur != head;cur=cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}


DN* Find(DN* head, Datatype d)
{
	assert(head->next != head);
	DN* cur = head->next;
	while (cur!=head)
	{
		if (cur->data==d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
