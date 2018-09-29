#define _CRT_SECURE_NO_DEPRECATE 1

#include "LinList.h"

//初始化
void InitLinList(pNode* pn)
{
	assert(pn);
	pn = NULL;
}


//销毁
void DesLinList(pNode first)
{
	Node* cur = first;
	Node* next;
	while (cur!=NULL)
	{
		next = cur;
		cur = cur->next;
		free(next);
	}
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


//增
//头插
void PushFront(pNode* pn, DataType d)
{
	assert(pn);
	Node* newnode = CreatNewNode(d);
	newnode->next = *pn;
	*pn = newnode;

}


//尾插
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//链表为空
	if (*pn==NULL)
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


//删
//头删
void PopFront(pNode* pn)
{
	assert(pn);
	assert(*pn);

	Node* first = *pn;
	*pn = (*pn)->next;
	free(first);
}


//尾删
void PopBack(pNode* pn)
{
	assert(pn);
	assert(*pn);//没有节点

	//只有一个节点
	if ((*pn)->next==NULL)
	{
		free(*pn);
		*pn = NULL;
		return;
	}

	//至少两个节点
	Node *cur = *pn;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}


// 查找（顺序查找） 找到了，返回所在结点地址，没有找到返回 NULL
Node* FindLinList(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur;
	for (cur = *pn; cur != NULL;cur=cur->next)
	{
		if (cur->data==d)
		{
			return cur;
		}
	}
	return NULL;
}


// 插入，在结点 pos 前面插入
void Insert(pNode* pn, Node* pos, DataType d)
{
	assert(pn);
	assert(pos);
	if (*pn==pos)
	{
		PushFront(pn, d);
		return;
	}

	Node* newnode = CreatNewNode(d);
	Node*cur = *pn;
	// 找到 pos 前的一个结点
	while (cur->next!=pos)
	{
		cur = cur->next;
	}

	newnode->next = pos;
	cur->next = newnode;

}


// 删除 pos 这个结点	（pos一定在链表中）
void Erase(pNode* pn, Node* pos)
{
	assert(pn);
	assert(pos);
	if (*pn==pos)
	{
		PopFront(pn);
		return;
	}

	Node* cur = *pn;
	while (cur->next!=pos)
	{
		cur=cur->next;
	}

	cur->next = pos->next;
	free(pos);
}


// 按值删除，只删遇到的第一个 
void Remove(pNode *pn, DataType d)
{
	assert(pn);
	Node* Del = FindLinList(pn,d);

	Erase(pn, Del);
}


// 按值删除，删除所有的 
void RemoveAll(pNode *pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;
	Node* front = *pn;
	while (cur!=NULL)
	{
		
		if (cur->data == d)
		{
			
			Node* Del = cur;
			cur = cur->next;
			if (Del==*pn)
			{
				PopFront(pn);
			}
			else if (Del->next==NULL)
			{
				PopBack(pn);
			}
			else
			{
				
				front->next = Del->next;
				free(Del);
			}
		}
		else
		{
			front = cur;
			cur = cur->next;
		
		}
	}
}


