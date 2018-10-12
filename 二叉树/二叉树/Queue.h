#pragma  once

#include "assert.h"
#include "stdio.h"
#include "stdlib.h"

typedef void* QDataType;

typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
	int size;
}	Queue;

//初始化
void InitQueue(Queue* pQ)
{
	assert(pQ);
	pQ->front = pQ->rear = NULL;
}

//销毁
void DestroyQueue(Queue* pQ)
{
	assert(pQ);
	QNode *cur, *next;
	for (cur = pQ->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQ->front = pQ->rear = NULL;
}

// 插入
void PushQueue(Queue *pQ, QDataType d)
{
	pQ->size++;
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = d;
	node->next = NULL;

	if (pQ->rear == NULL)
	{
		pQ->front = pQ->rear = node;
		return;
	}
	pQ->rear->next = node;
	pQ->rear = node;
}

//删除
void PopQueue(Queue* pQ)
{
	pQ->size--;
	assert(pQ);
	assert(pQ->front);
#if 0
	if (pQ->front == pQ->rear)
	{
		free(pQ->front);
		pQ->front = pQ->rear = NULL;
	}
	else
	{
		QNode* Del = pQ->front;
		pQ->front = pQ->front->next;
		free(Del);
	}
#endif
	QNode *del = pQ->front;
	pQ->front = pQ->front->next;
	free(del);
	if (pQ->front == NULL)
	{
		pQ->rear = NULL;
	}
}

QDataType QueueFront(const Queue *pQ)
{
	assert(pQ != NULL);
	assert(pQ->front != NULL);	// 表示不能是空队列

	return pQ->front->data;
}

int QueueEmpty(const Queue *pQ)
{
	return pQ->front == NULL ? 1 : 0;
}

int QueueSize(const Queue *pQ)
{
	return pQ->size;
}