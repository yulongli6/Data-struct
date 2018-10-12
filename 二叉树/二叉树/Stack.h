#pragma once

#include <assert.h>

#define MAX_SIZE (100)

typedef void* SDataType;

typedef struct Stack
{
	SDataType array[MAX_SIZE];
	int top;
} Stack;

//初始化
void StackInit(Stack *pS)
{
	pS->top = 0;
}

//销毁
void StackDestroy(Stack *pS)
{
	pS->top = 0;
}

//压栈
void StackPush(Stack *pS, SDataType data)
{
	assert(pS->top < MAX_SIZE);
	pS->array[pS->top++] = data;
}

//出栈
void StackPop(Stack *pS)
{
	assert(pS->top > 0);
	pS->top--;
}

//返回栈顶元素
SDataType StackTop(const Stack *pS)
{
	assert(pS->top > 0);
	return pS->array[pS->top - 1];
}

//站内元素的个数
int StackSize(const Stack *pS)
{
	return pS->top;
}

//判断栈是否为空
int StackEmpty(const Stack *pS)
{
	return pS->top == 0 ? 1 : 0;
}
