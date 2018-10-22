#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Key;

typedef int(*HashFunc)(Key, int);

typedef struct Node 
{
	Key key;
	struct Node* next;
}  Node;


typedef struct HashBucket 
{
	Node** array;
	int size;
	int capacity;
	HashFunc hashFunc;
}   HashBucket;


void HashBucketInit(HashBucket* pHB, int capacity, HashFunc hashFunc)
{
	// ���� array �Ŀռ�
	pHB->array = (Node**)malloc(sizeof(Node)*capacity);
	//��ʼ��array��ֵ
	for (int i = 0; i < capacity; i++)
	{
		pHB->array[i] = NULL;//������
	}
	
	pHB->capacity = capacity;
	pHB->size = 0;
	pHB->hashFunc = hashFunc;
}


void HashBucketDestroy(HashBucket* pHB)
{
	// �Ӷ�������Ŀռ���ͷ�
	for (int i = 0; i < pHB->capacity; i++)
	{
		Node*cur;
		Node* next;
		for (cur = pHB->array[i]; cur != NULL; cur=next)
		{
			next = cur->next;
			free(cur);
		}
	}
	free(pHB->array);
}



int HashBucketSearch(HashBucket* pHB, Key key)
{
	int index = pHB->hashFunc(key, pHB->capacity);
	// pHB->array[index] ����ĵ�һ�����
	for (Node* cur = pHB->array[index]; cur != NULL; cur = cur->next)
	{
		if (key == cur->key)
		{
			return 0;
		}
	}
	return -1;
}


int HashBucketRemove(HashBucket* pHB, Key key)
{
	int index = pHB->hashFunc(key, pHB->capacity);
	// pHB->array[index] ����ĵ�һ�����
	Node* prev = NULL;
	for (Node* cur = pHB->array[index]; cur != NULL; cur = cur->next)
	{
		if (key == cur->key)
		{
			if (prev == NULL)
			{
				pHB->array[index] = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			pHB->size--;
			return 0;
		}
		prev = cur;
	}
	return -1;
}


int HashBucketInsert(HashBucket* pHB, Key key);

void ExpandIfRequired(HashBucket* pHB)
{
	if (pHB->size * 10 / pHB->capacity < 9) 
	{
		return;
	}

	int newCapacity = pHB->capacity * 2;
	HashBucket tempHB;
	HashBucketInit(&tempHB, newCapacity, pHB->hashFunc);

	for (int i = 0; i < pHB->capacity; i++)
	{
		for (Node* cur = pHB->array[i]; cur != NULL; cur = cur->next)
		{
			HashBucketInsert(&tempHB, cur->key);
		}
	}

	HashBucketDestroy(pHB);
	pHB->array = tempHB.array;
	pHB->capacity = tempHB.capacity;
}


int HashBucketInsert(HashBucket* pHB, Key key)
{
	// ����
	ExpandIfRequired(pHB);

	// �������ظ�
	if (HashBucketSearch(pHB, key) == 0) 
	{
		return -1;
	}

	int index = pHB->hashFunc(key, pHB->capacity);
	// ͷ�壬ʱ���ʡ
	Node *node = (Node *)malloc(sizeof(Node));
	node->key = key;
	node->next = pHB->array[index];
	pHB->array[index] = node;
	pHB->size++;

	return 0;
}



int hash(Key key, int capacity)
{
	return key % capacity;
}


void test2()
{
	HashBucket hb;
	HashBucketInit(&hb, 7, hash);

	HashBucketInsert(&hb, 0);
	HashBucketInsert(&hb, 7);
	HashBucketInsert(&hb, 14);
	HashBucketInsert(&hb, 21);
	HashBucketInsert(&hb, 28);
	HashBucketInsert(&hb, 1);
	HashBucketInsert(&hb, 8);
	HashBucketInsert(&hb, 5);


	printf("%d\n", HashBucketSearch(&hb, 14));
	HashBucketRemove(&hb, 14);
	printf("%d\n", HashBucketSearch(&hb, 14));

	printf("�ɹ�\n");
}