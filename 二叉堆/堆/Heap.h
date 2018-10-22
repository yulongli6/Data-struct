#pragma once
#include<assert.h>
#include <string.h>
#include "assert.h"
#include <stdio.h>

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//向下调整
void AdjustDownBig(int array[], int size, int root)
{
	int max = 0;
	while (1)
	{
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		if (left >= size)
		{
			return;
		}

		if (right < size && array + right > array + left)
		{
			max = right;
		}
		else
		{
			max = left;
		}
		if (array + root >= array + max )
		{
			return;
		}
		Swap(array + root, array + max);
		root = max;
	}
}

void AdjustDownSmall(int array[], int size, int root)
{
	
	while (2 * root + 1 < size)
	{
		int min;
		if (2 * root + 2 < size && array[2 * root + 2] < array[2 * root + 1])
		{
			min = 2 * root + 2;
		}
		else
		{
			min = 2 * root + 1;
		}

		if (array [root] <= array[min])
		{
			return;
		}

		Swap(array + root, array + min);
		root = min;
	}
}



//向上调整O(logN)
void AdjustUpBig(int array[], int size, int child)
{
	while (child > 0)
	{
		int parent = (child - 1) / 2;
		if (array + child <= array + parent)
		{
			return;
		}

		Swap(array + child, array + parent);
		child = parent;
		
	}
}

//------------------------------------------//
//创建堆及堆的操作
//建大堆
void CreateHeapBig(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDownBig(array, size, i);
    }
}

//建小堆
void CreateHeapSmall(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDownSmall(array, size, i);
	}
}

typedef struct Heap
{
	int array[100];
	int size;
}Heap;


void HeapInit(Heap* pH,int array[],int size)
{
	assert(size <= 100);
	memcpy(pH->array, array, sizeof(int)*size);
	pH->size = size;

	CreateHeapBig(pH->array, pH->size);
}


//取最值
int HeapTop(Heap* pH)
{
	assert(pH->size > 0);
	return pH->array[0];
}

//o(logn)
void HeapPop(Heap* pH)
{
	assert(pH->size > 0);
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	AdjustDownBig(pH->array, pH->size, 0);
}


void HeapPush(Heap* pH,int data)
{
	assert(pH->size < 100);
	pH->array[pH->size] = data;
	pH->size++;

	AdjustUpBig(pH->array, pH->size, pH->size - 1);
}





#include <stdio.h>
void test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array) / sizeof(int);
	CreateHeapBig(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	
	Heap heap;
	HeapInit(&heap,array,size);
	printf("%d\n", HeapTop(&heap));
	HeapPush(&heap, 90);
	printf("%d\n", HeapTop(&heap));
	HeapPop(&heap);
	printf("%d\n", HeapTop(&heap));
}


void test2()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array) / sizeof(int);
	CreateHeapSmall(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

