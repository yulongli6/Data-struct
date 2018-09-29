#define _CRT_SECURE_NO_DEPRECATE 1

#include "LinList.h"

//��ʼ��
void InitLinList(pNode* pn)
{
	assert(pn);
	pn = NULL;
}


//����
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


//��
//ͷ��
void PushFront(pNode* pn, DataType d)
{
	assert(pn);
	Node* newnode = CreatNewNode(d);
	newnode->next = *pn;
	*pn = newnode;

}


//β��
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//����Ϊ��
	if (*pn==NULL)
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


//ɾ
//ͷɾ
void PopFront(pNode* pn)
{
	assert(pn);
	assert(*pn);

	Node* first = *pn;
	*pn = (*pn)->next;
	free(first);
}


//βɾ
void PopBack(pNode* pn)
{
	assert(pn);
	assert(*pn);//û�нڵ�

	//ֻ��һ���ڵ�
	if ((*pn)->next==NULL)
	{
		free(*pn);
		*pn = NULL;
		return;
	}

	//���������ڵ�
	Node *cur = *pn;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}


// ���ң�˳����ң� �ҵ��ˣ��������ڽ���ַ��û���ҵ����� NULL
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


// ���룬�ڽ�� pos ǰ�����
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
	// �ҵ� pos ǰ��һ�����
	while (cur->next!=pos)
	{
		cur = cur->next;
	}

	newnode->next = pos;
	cur->next = newnode;

}


// ɾ�� pos ������	��posһ���������У�
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


// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void Remove(pNode *pn, DataType d)
{
	assert(pn);
	Node* Del = FindLinList(pn,d);

	Erase(pn, Del);
}


// ��ֵɾ����ɾ�����е� 
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


