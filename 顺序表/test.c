#define _CRT_SECURE_NO_DEPRECATE 1

#include "SeqList.h"
#include "stdio.h"

SeqList seq;

//增
void TestPushSeqList()
{
	//尾插
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	Insert(&seq, 2, 10);
	PrintSeqList(&seq);

	//头插
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	Insert(&seq, 2, 10);
	PrintSeqList(&seq);
}



//删
void TestPopSeqList()
{
	//尾插
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);

	PopBack(&seq);//尾删
	PrintSeqList(&seq);
	PopFront(&seq);//头删
	PrintSeqList(&seq);

	//尾插
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	Erase(&seq, 2);
	PrintSeqList(&seq);
}


//查
void TestFind()
{
	int ret = 0;

	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	
	ret = Find(&seq, 2);

	if (ret == -1)
		printf("数据不存在\n");

	else
		printf("%d\n", ret);
}


void TestRemove()
{
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	Remove(&seq, 3);
	PrintSeqList(&seq);
}


void TestRemoveAll()
{
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 1);
	PushBack(&seq, 4);

	RemoveAll(&seq, 1);
	PrintSeqList(&seq);
}


void TestEmpty()
{
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);

	Empty(&seq);
	PrintSeqList(&seq);
}


void TestSize()
{
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);

	printf("%d\n", Size(&seq));
}


void TestBubbleSort()
{
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 5);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PrintSeqList(&seq);
	BubbleSort(&seq);
	PrintSeqList(&seq);
}


void TestBinarySearch()
{
	int ret = 0;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);

	ret=BinarySearch(&seq, 1);
	if (ret==-1)
	{
		printf("数据不存在\n");
	}
	else
	{
		printf("%d\n", ret);
	}
}


void TestBinarySearch_R()
{
	int ret = 0;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	int left = 0;
	int right =(&seq)->sz - 1;
	ret = BinarySearch_R(&seq,left,right, 1);
	if (ret == -1)
	{
		printf("数据不存在\n");
	}
	else
	{
		printf("%d\n", ret);
	}
}

void TestSelectSort()
{
	InitSeqList(&seq);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	SelectSort(&seq);
	PrintSeqList(&seq);
}


int main()
{

	TestPushSeqList();
	TestPopSeqList();
	TestFind();
	TestRemove();
	TestRemoveAll();
	TestEmpty();
	TestSize();
	TestBubbleSort();
	TestBinarySearch();
	TestBinarySearch_R();
	TestSelectSort();
	return 0;
}
