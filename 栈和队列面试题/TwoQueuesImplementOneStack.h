//使用两个队列实现一个栈

#pragma once

#include "Queue.h"

typedef struct TQIOStack
{
	struct Queue queue1;
	struct Queue queue2;
}TQStack;


void TQStackInit(TQStack* pTQS)
{
	QueueInit(&pTQS->queue1);
	QueueInit(&pTQS->queue2);
}


void TQStackDestroy(TQStack* pTQS)
{
	QueueDestroy(&pTQS->queue1);
	QueueDestroy(&pTQS->queue2);
}


void TQStackPush(TQStack* pTQS,QDataType data)
{
	//默认队列一
	Queue* pQueue = &pTQS->queue1;
	if (!QueueEmpty(&pTQS->queue2))
	{
		pQueue = &pTQS->queue2;
	}

	QueuePush(pQueue, data);
}


void TQStackPop(TQStack* pTQS)
{
	Queue* pNotEmpty = &pTQS->queue1;
	Queue* pEmpty = &pTQS->queue2;
	if (!QueueEmpty(&pTQS->queue2))
	{
		pNotEmpty = &pTQS->queue2;
		pEmpty = &pTQS->queue1;
	}

	while (QueueSize(pNotEmpty)>1)
	{
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	QueuePop(pNotEmpty);
}


QDataType TQStackTop(TQStack* pTQS)
{
	Queue* pNotEmpty = &pTQS->queue1;
	Queue* pEmpty = &pTQS->queue2;
	if (!QueueEmpty(&pTQS->queue2))
	{
		pNotEmpty = &pTQS->queue2;
		pEmpty = &pTQS->queue1;
	}

	while (QueueSize(pNotEmpty) > 1)
	{
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty, data);
	}

	QDataType data = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty, data);
	return data;
}