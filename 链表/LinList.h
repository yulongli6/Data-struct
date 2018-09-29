#pragma once

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
}Node,*pNode;

//��ʼ��/����
void InitLinList(pNode* pn);
void DesLinList(pNode first);

//��ӡ
void PrintLinList(pNode first);

//��
//ͷ��
void PushFront(pNode* pn, DataType d);
//β��
void PushBack(pNode* pn, DataType d);

//ɾ
//ͷɾ
void PopFront(pNode* pn);
//βɾ
void PopBack(pNode* pn);

//����
Node* FindLinList(pNode* pn, DataType d);

// ���룬�ڽ�� pos ǰ�����
void Insert(pNode* pn, Node* pos, DataType d);

// ɾ�� pos ������	��posһ���������У�
void Erase(pNode* pn, Node* pos);

// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void Remove(pNode *pn, DataType d);

// ��ֵɾ����ɾ�����е� 
void RemoveAll(pNode *pn, DataType d);


