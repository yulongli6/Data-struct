#pragma once

#include <assert.h>

#define MAX_SIZE (100)

typedef void* SDataType;

typedef struct Stack
{
	SDataType array[MAX_SIZE];
	int top;
} Stack;

//��ʼ��
void StackInit(Stack *pS)
{
	pS->top = 0;
}

//����
void StackDestroy(Stack *pS)
{
	pS->top = 0;
}

//ѹջ
void StackPush(Stack *pS, SDataType data)
{
	assert(pS->top < MAX_SIZE);
	pS->array[pS->top++] = data;
}

//��ջ
void StackPop(Stack *pS)
{
	assert(pS->top > 0);
	pS->top--;
}

//����ջ��Ԫ��
SDataType StackTop(const Stack *pS)
{
	assert(pS->top > 0);
	return pS->array[pS->top - 1];
}

//վ��Ԫ�صĸ���
int StackSize(const Stack *pS)
{
	return pS->top;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(const Stack *pS)
{
	return pS->top == 0 ? 1 : 0;
}
