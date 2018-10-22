#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef int Key;

typedef int(*HashFunc)(Key, int);


// �޷�ֱ��ɾ������Ҫ����״̬���
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


//��ʼ��/����
void HashTableInit(HashTable* pHT, int capacity, HashFunc hashFunc)
{
	pHT->array = (Element *)malloc(sizeof(Element)*capacity);
	pHT->size = 0;
	pHT->capacity = capacity;
	pHT->hashFunc = hashFunc;

	//����״̬��Ϊ�� EMPTY
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


// ���� / ɾ�� / ����
// �ҵ������� 0
// û�ҷ��� -1
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
		i = (index + (c * c)) % pHT->capacity;//����̽��
		c++;
	}
	// TODO: ������������ѭ������Ϊ��������е�λ�ö��õ�
	return -1;
}


// �ҵ���ɾ���ɹ������� 0
// û�ҵ������� -1
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
		i = (index + (c * c)) % pHT->capacity;//����̽��
		c++;
	}
	// TODO: ������������ѭ������Ϊ��������е�λ�ö��õ�
	return -1;
}

int HashTableInsert(HashTable *pHT, Key key);

void ExpandIfNeed(HashTable* pHT)
{
	if (pHT->size * 10 / pHT->capacity < 7)
	{
		return;
	}

	//��������
	// �����¿ռ�
	// ����������
	// �ͷ��Ͽռ�
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

// ���� key �������ظ����ռ�����
// �Ȳ���һ�Σ�����ҵ�������ʧ�� ���� -1
// û�ҵ����ٴα��������� EMPTY | DELETED �����Բ�����
int HashTableInsert(HashTable *pHT, Key key)
{
	// ���������ж�
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

// ʵ���õ��� hash ����
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