//实现一个栈，要求实现Push（入栈）、Pop（出栈）、Min（返回最小值）
//的时间复杂度为O（1)

#pragma once

#include "stack.h"

typedef struct MinStruct 
{
	struct Stack s;//普通的栈
	struct Stack m;//最小栈
}MinStack;


void MinStackInit(MinStack* pMS)
{
	StackInit(&pMS->s);
	StackInit(&pMS->m);
}


void MinStackDestroy(MinStack* pMS)
{
	StackDestroy(&pMS->s);
	StackDestroy(&pMS->m);
}


void MinStackPush(MinStack *pMS, SDataType data)
{
#if 0
	StackPush(&pMS->s, data);
	if (StackEmpty(&pMS->m) || data < StackTop(&pMS->m))
	{
		StackPush(&pMS->m, data);
	}
	else
	{
		StackPush(&pMS->m, StackTop(&pMS->m));
	}
#endif

	StackPush(&pMS->s, data);
	if (StackEmpty(&pMS->m) || data < StackTop(&pMS->m)) 
	{
		StackPush(&pMS->m, data);
	}
	
}


void MinStackPop(MinStack *pMS)
{
#if 0
	StackPop(&pMS->s);
	StackPop(&pMS->m);
#endif
	
	SDataType data = StackTop(&pMS->s);
	StackPop(&pMS->s);
	if (data==StackTop(&pMS->m))
	{
		StackPop(&pMS->m);
	}
}


SDataType MinStackTop(MinStack *pMS)
{
	return StackTop(&pMS->s);
}


SDataType MinStackMin(MinStack *pMS)
{
	return StackTop(&pMS->m);
}

