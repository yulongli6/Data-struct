#pragma  once


#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

typedef int DataType;

// 不是链表的结构体
// 链表中一个结点的结构体
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode;




//初始化
void InitLinList(pNode* pn)
{
	assert(pn);
	*pn = NULL;
}

//创建新的节点
Node* CreatNewNode(DataType d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;
	return node;
}


//打印
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


//尾插
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//链表为空
	if (*pn == NULL)
	{
		*pn = newnode;
		return;
	}

	//至少有一个数据
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}


// 查找（顺序查找） 找到了，返回所在结点地址，没有找到返回 NULL
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