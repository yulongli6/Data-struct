#pragma once

#include "stdlib.h"
#include "assert.h"

typedef int SDataType;

typedef struct HTStack
{
	SDataType *array;
	int capacity;
	int top1;
	int top2;
} HTStack;


void HTStackInit(HTStack* pHT)
{
	pHT->capacity = 6;
	pHT->array = (SDataType *)malloc(sizeof(SDataType) * 6);
	pHT->top1 = 0;
	pHT->top2 = 6 - 1;
}

void HTStackDestroy(HTStack* pHT)
{
	free(pHT->array);
}


void ExpandCapacity(HTStack* pHT)
{
	if (pHT->top2 > pHT->top1-1)
	{
		return;
	}

	int newCapacity = pHT->capacity * 2;
	SDataType* newArray = (SDataType*)malloc(sizeof(SDataType)*newCapacity);

	for (int i = 0; i < pHT->top1;i++)
	{
		newArray[i] = pHT->array[i];
	}

	int expandLength = newCapacity - pHT->capacity;
	for (int j = pHT->capacity - 1; j > pHT->top2;j--)
	{
		newArray[j + expandLength] = pHT->array[j];
	}

	pHT->top2 += expandLength;

	free(pHT->array);
	pHT->array = newArray;
}


void HTStackPush_1(HTStack* pHT,SDataType data)
{
	ExpandCapacity(pHT);

	pHT->array[pHT->top1] = data;
	pHT->top1++;
}


void HTStackPush_2(HTStack* pHT, SDataType data)
{
	ExpandCapacity(pHT);

	pHT->array[pHT->top2] = data;
	pHT->top2--;
}


void HTStackPop_1(HTStack* pHT)
{
	if (pHT->top1<=0)
	{
		return;
	}

	pHT->top1--;
}



void HTStackPop_2(HTStack* pHT)
{
	if (pHT->top1>=pHT->capacity)
	{
		return;
	}

	pHT->top2++;
}


SDataType HTStackTop_1(HTStack* pHT)
{
	assert(pHT->top1 > 0);
	return pHT->array[pHT->top1 - 1];
}


SDataType HTStackTop_2(HTStack* pHT)
{
	assert(pHT->top1 < pHT->capacity-1);
	return pHT->array[pHT->top2 + 1];
}


int HTStackSize_1(HTStack* pHT)
{
	return pHT->top1;
}


int HTStackSize_2(HTStack* pHT)
{
	return pHT->capacity-1-pHT->top2;
}


int HTStackEmpty_1(HTStack* pHT)
{
	return pHT->top1 = 0 ? 1 : 0;
}


int HTStackEmpty_2(HTStack* pHT)
{
	return pHT->top2 = pHT->capacity-1 ? 1 : 0;
}