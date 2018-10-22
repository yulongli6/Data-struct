#pragma once

#include "Heap.h"
#include <stdlib.h>
//海量数据TopK问题,
void TopK(int array[], int size, int k)
{
	int *heap = (int*)malloc(sizeof(int)*k);
	for (int i = 0; i < k; i++) 
	{
		heap[i] = array[i];
	}
	CreateHeapSmall(heap, k);
	for (int j = k; j < size; j++)
	{
		if (array[j] < heap[0])
		{
			continue;
		}
		else
		{
			heap[0] = array[j];
			AdjustDownSmall(heap, k, 0);
		}
	}
	for (int z = 0; z < k; z++)
	{
		printf("%d ", heap[z]);
	}
	printf("\n");
	free(heap);
}




void test3()
{
	int array[100000];
	for (int i = 0; i < 100000; i++) 
	{
		array[i] = i;
	}

	TopK(array, 100000, 10);
}