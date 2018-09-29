#pragma once

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
}Node,*pNode;

//初始化/销毁
void InitLinList(pNode* pn);
void DesLinList(pNode first);

//打印
void PrintLinList(pNode first);

//增
//头插
void PushFront(pNode* pn, DataType d);
//尾插
void PushBack(pNode* pn, DataType d);

//删
//头删
void PopFront(pNode* pn);
//尾删
void PopBack(pNode* pn);

//查找
Node* FindLinList(pNode* pn, DataType d);

// 插入，在结点 pos 前面插入
void Insert(pNode* pn, Node* pos, DataType d);

// 删除 pos 这个结点	（pos一定在链表中）
void Erase(pNode* pn, Node* pos);

// 按值删除，只删遇到的第一个 
void Remove(pNode *pn, DataType d);

// 按值删除，删除所有的 
void RemoveAll(pNode *pn, DataType d);


