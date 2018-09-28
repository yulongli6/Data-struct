#pragma omce

#include "stdlib.h"
#include "assert.h"

typedef int SDataType;

typedef struct PSStack
{
	SDataType *array;
	int capacity;
	int top1;
	int top2;
} PSStack;


void PSStackInit(PSStack* pPS)
{
	pPS->capacity = 6;
	pPS->array = (SDataType *)malloc(sizeof(SDataType) * 6);
	pPS->top1 = 0;
	pPS->top2 = 1;
}

void PSStackDestroy(PSStack* pPS)
{
	free(pPS->array);
}


void ExpandCapacity(PSStack* pPS)
{
	if (pPS->top1 == pPS->capacity-2|| pPS->top2 == pPS->capacity - 1)
	{
		return;
	}

	int newCapacity = pPS->capacity * 2;
	SDataType* newArray = (SDataType*)malloc(sizeof(SDataType)*newCapacity);

	for (int i = 0; i < pPS->top1; i+=2)
	{
		newArray[i] = pPS->array[i];
	}

	for (int j = 1; j <pPS->top2; j+=2)
	{
		newArray[j] = pPS->array[j];
	}

	free(pPS->array);
	pPS->array = newArray;

}


void PSStackPush_1(PSStack* pPS, SDataType data)
{
	ExpandCapacity(pPS);

	pPS->array[pPS->top1] = data;
	pPS->top1+=2;
}


void PSStackPush_2(PSStack* pPS, SDataType data)
{
	ExpandCapacity(pPS);

	pPS->array[pPS->top2] = data;
	pPS->top1 += 2;
}


void PSStackPop_1(PSStack* pPS)
{
	if (pPS->top1 <= 0)
	{
		return;
	}

	pPS->top1-=2;
}


void PSStackPop_2(PSStack* pPS)
{
	if (pPS->top1 <= 1)
	{
		return;
	}

	pPS->top2 -= 2;
}


SDataType PSStackTop_1(PSStack* pPS)
{
	assert(pPS->top1 > 0);
	return pPS->array[pPS->top1 - 2];
}

SDataType PSStackTop_2(PSStack* pPS)
{
	assert(pPS->top2 > 1);
	return pPS->array[pPS->top1 - 2];
}


int PSStackSize_1(PSStack* pPS)
{
	return (pPS->top1)/ 2;
}

int PSStackSize_2(PSStack* pPS)
{
	return (pPS->top2) / 2;
}


int PSStackEmpty_1(PSStack* pPS)
{
	return pPS->top1 = 0 ? 1 : 0;
}


int PSStackEmpty_2(PSStack* pPS)
{
	return pPS->top2 = 1 ? 1 : 0;
}