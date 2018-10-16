#pragma once
#include<assert.h>
#include <string.h>

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
	int min = 0;
	while (1)
	{
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		if (left >= size)
		{
			return;
		}
		if (right < size && array[right] < array[left])
		{
			min = right;
		}
		else
		{
			min = left;
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


void HeapInit(Heap* pH)
{
	
}


void HeapPush(Heap* pH,int data)
{

}





#include <stdio.h>
void test()
{
	Heap heap;
	HeapInit(&heap);
	int array1[] = { 1, 4, 7, 2, 3, 8, 9 };
	int array2[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array1) / sizeof(int);
	int size2 = sizeof(array2) / sizeof(int);
	int root = 0;
	AdjustDownBig(array1, size, root);
	CreateHeapBig(array2, size2);
	for (int i = 0; i < size2; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
	CreateHeapSmall(array2, size2);
	for (int i = 0; i < size2; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
	

}

void test2()
{
	int array2[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size2 = sizeof(array2) / sizeof(int);
	CreateHeapSmall(array2, size2);
	for (int i = 0; i < size2; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
}