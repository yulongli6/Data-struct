#pragma once
#include<stdio.h>
#include <stdlib.h>
// 32 个房间的宿舍楼
typedef unsigned int uint32_t;

typedef struct {
	uint32_t *array;
	int size;		//	里面住了多少同学
	int capacity;	//	有多少楼
}	BitMap;


void BitMapInit(BitMap *pBM, int capacity)
{
	pBM->array = (uint32_t *)malloc(sizeof(uint32_t)*capacity);
	pBM->size = 0;
	pBM->capacity = capacity;
}

void BitMapDestroy(BitMap *pBM)
{
	free(pBM);
}



void BitMapSetOne(BitMap* pBM, unsigned int n)
{
	int index = n / 32;
	int bit = n % 32;
	pBM->size++;

	pBM->array[index] = pBM->array[index] | (1 << bit);
}


void BitMapSetZero(BitMap *pBM, unsigned int n)
{
	int index = n / 32;
	int bit = n % 32;
	pBM->size--;

	pBM->array[index] = pBM->array[index] & ~(1 << bit);
}


int BitMapIsSetOne(BitMap* pBM, unsigned int n)
{
	int index = n / 32;
	int bit = n % 32;

	return pBM->array[index] >> bit & 1;
}


void test3()
{
	BitMap bm;
	BitMapInit(&bm, 5);

	BitMapSetOne(&bm, 1);
	BitMapSetOne(&bm, 10);
	BitMapSetOne(&bm, 100);
	BitMapSetOne(&bm, 28);
	BitMapSetOne(&bm, 66);
	BitMapSetOne(&bm, 99);
	BitMapSetOne(&bm, 101);

	printf("%d\n", BitMapIsSetOne(&bm, 1));
	BitMapSetZero(&bm, 1);
	printf("%d\n", BitMapIsSetOne(&bm, 1));
	printf("成功\n");
}
