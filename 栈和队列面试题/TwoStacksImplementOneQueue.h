//使用两个栈实现一个队列

#pragma once

#include "stack.h"

typedef struct TSIOQueue
{
	Stack push;
	Stack pop;
}TSQueue;


void TSQueueInit(TSQueue* pTSQ)
{
	StackInit(&pTSQ->push);
	StackInit(&pTSQ->pop);
}


void TSQueueDestroy(TSQueue* pTSQ)
{
	StackDestroy(&pTSQ->push);
	StackDestroy(&pTSQ->pop);
}


void TSQueuePush(TSQueue* pTSQ, SDataType data)
{
	StackPush(&pTSQ->push, data);
}


void TSQueuePop(TSQueue* pTSQ)
{
	if (StackEmpty(&pTSQ->pop))
	{
		while (!StackEmpty(&pTSQ->push))
		{
			SDataType data = StackTop(&pTSQ->push);
			StackPop(&pTSQ->push);

			StackPush(&pTSQ->pop, data);
		}
	}

	StackPop(&pTSQ->pop);
}


SDataType TSQueueFront(TSQueue* pTSQ)
{
	if (StackEmpty(&pTSQ->pop))
	{
		while (!StackEmpty(&pTSQ->push))
		{
			SDataType data = StackTop(&pTSQ->push);
			StackPop(&pTSQ->push);

			StackPush(&pTSQ->pop, data);
		}
	}

	return StackTop(&pTSQ->pop);
}