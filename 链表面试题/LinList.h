#pragma  once


#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

typedef int DataType;

// ��������Ľṹ��
// ������һ�����Ľṹ��
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode;




//��ʼ��
void InitLinList(pNode* pn)
{
	assert(pn);
	*pn = NULL;
}

//�����µĽڵ�
Node* CreatNewNode(DataType d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;
	return node;
}


//��ӡ
void PrintLinList(pNode first)
{
	Node* cur = first;
	printf("first-->");
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//β��
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//����Ϊ��
	if (*pn == NULL)
	{
		*pn = newnode;
		return;
	}

	//������һ������
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}


// ���ң�˳����ң� �ҵ��ˣ��������ڽ���ַ��û���ҵ����� NULL
Node* FindLinList(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur;
	for (cur = *pn; cur != NULL; cur = cur->next)
	{
		if (cur->data == d)
		{
			return cur;
		}
	}
	return NULL;
}