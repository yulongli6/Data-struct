#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef int Key;

typedef int(*HashFunc)(Key, int);


// 无法直接删除，需要利用状态标记
typedef enum State
{
	EMPTY,
	DELETED,
	EXIST
}  State;

typedef struct Element
{
	Key key;
	State state;
} Element;

typedef struct HashTable
{
	Element *array;
	int size;
	int capacity;
	HashFunc hashFunc;
}   HashTable;


//初始化/销毁
void HashTableInit(HashTable* pHT, int capacity, HashFunc hashFunc)
{
	pHT->array = (Element *)malloc(sizeof(Element)*capacity);
	pHT->size = 0;
	pHT->capacity = capacity;
	pHT->hashFunc = hashFunc;

	//所有状态置为空 EMPTY
	for (int i = 0; i < capacity; i++)
	{
		pHT->array[i].state = EMPTY;
	}
}


void HashTableDestroy(HashTable* pHT)
{
	free(pHT->array);
	pHT->capacity = pHT->size = 0;
	pHT->hashFunc = NULL;
}


// 查找 / 删除 / 插入
// 找到，返回 0
// 没找返回 -1
int HashTableSearch(HashTable* pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	int i = index;
	int c = 1;
	while (pHT->array[i].state != EMPTY)
	{
		if (pHT->array[i].state == EXIST && key == pHT->array[i].key)
		{
			return 0;
		}
		//i = (index + 1) % pHT->capacity;
		i = (index + (c * c)) % pHT->capacity;//二次探测
		c++;
	}
	// TODO: 看起来，会死循环，因为不会把所有的位置都用掉
	return -1;
}


// 找到，删除成功，返回 0
// 没找到，返回 -1
int HashTableRemove(HashTable* pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	int i = index;
	int c = 1;
	while (pHT->array[i].state != EMPTY)
	{
		if (pHT->array[i].state == EXIST && key == pHT->array[i].key)
		{
			pHT->array[i].state = DELETED;
			pHT->size--;
			return 0;
		}
		//i = (index + 1) % pHT->capacity;
		i = (index + (c * c)) % pHT->capacity;//二次探测
		c++;
	}
	// TODO: 看起来，会死循环，因为不会把所有的位置都用掉
	return -1;
}

int HashTableInsert(HashTable *pHT, Key key);

void ExpandIfNeed(HashTable* pHT)
{
	if (pHT->size * 10 / pHT->capacity < 7)
	{
		return;
	}

	//两倍扩容
	// 申请新空间
	// 搬移老数据
	// 释放老空间
	int newCapacity = pHT->capacity * 2;
	HashTable tempHT;
	HashTableInit(&tempHT, newCapacity, pHT->hashFunc);
	for (int i = 0; i < pHT->capacity; i++)
	{
		if (pHT->array[i].state==EXIST)
		{
			HashTableInsert(&tempHT, pHT->array[i].key);
		}
	}
	free(pHT->array);
	pHT->array = tempHT.array;
	pHT->capacity = tempHT.capacity;
}

// 插入 key 不允许重复，空间优先
// 先查找一次，如果找到，插入失败 返回 -1
// 没找到，再次遍历，遇到 EMPTY | DELETED 都可以插入了
int HashTableInsert(HashTable *pHT, Key key)
{
	// 进行扩容判断
	ExpandIfNeed(pHT);

	if (HashTableSearch(pHT, key) == 0) {
		return -1;
	}

	int index = pHT->hashFunc(key, pHT->capacity);
	int i = index;
	int c = 1;
	while (pHT->array[i].state == EXIST)
	{
		i = (index + (c * c)) % pHT->capacity;
		c++;
	}
	pHT->array[i].key = key;
	pHT->array[i].state = EXIST;
	pHT->size++;

	return 0;
}

// 实际用到的 hash 函数
int Hash(Key key, int capacity)
{
	return key % capacity;
}


void test()
{
	HashTable ht;
	HashTableInit(&ht, 7, Hash);

	HashTableInsert(&ht, 0);
	HashTableInsert(&ht, 15);
	HashTableInsert(&ht, 1);
	HashTableInsert(&ht, 3);
	HashTableInsert(&ht, 9);
	HashTableInsert(&ht, 10);

	printf("%d\n", HashTableSearch(&ht, 0));
	HashTableRemove(&ht, 0);
	printf("%d\n", HashTableSearch(&ht, 0));

	HashTableDestroy(&ht);
}