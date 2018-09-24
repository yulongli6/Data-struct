#define _CRT_SECURE_NO_DEPRECATE 1

#include "SeqListD.h"
SeqListD seq;




//��
void TestPushSeqListD()
{
	InitSeqListD(&seq);
	//β��
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PrintSeqListD(&seq);
	//ͷ��
	InitSeqListD(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 6);
	PrintSeqListD(&seq);
	//ָ��λ�ò���
	Insert(&seq, 2, 10);
	PrintSeqListD(&seq);
}


void TestPopSeqListD()
{
	InitSeqListD(&seq);
	//β��
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PrintSeqListD(&seq);
	//βɾ
	PopBack(&seq);
	PrintSeqListD(&seq);
	//ͷɾ
	PopFront(&seq);
	PrintSeqListD(&seq);
	//ָ��λ��ɾ��
	Erase(&seq, 2);
	PrintSeqListD(&seq);
}



void TestSort()
{
	InitSeqListD(&seq);
	//β��
	PushBack(&seq, 1);
	PushBack(&seq, 3);
	PushBack(&seq, 2);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	Sort(&seq);
	PrintSeqListD(&seq);
}


void TestBinarySearch()
{
	InitSeqListD(&seq);
	//β��
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PrintSeqListD(&seq);
	int ret=BinarySearch(&seq, 6);
	if (ret==-1)
	{
		return;
	}
	else
	{
		printf("%d\n", ret);
	}
}


void TestFind()
{
	int ret = 0;

	InitSeqListD(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	ret = Find(&seq, 2);

	if (ret == -1)
		printf("���ݲ�����\n");

	else
		printf("%d\n", ret);
}

void TestRemove()
{
	InitSeqListD(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 1);
	PushBack(&seq, 4);

	Remove(&seq, 1);
	PrintSeqListD(&seq);
}


void TestRemoveAll()
{
	InitSeqListD(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 1);
	PushBack(&seq, 4);

	RemoveAll(&seq, 1);
	PrintSeqListD(&seq);
}


int main()
{
	TestPushSeqListD();
	TestPopSeqListD();
	TestSort();
	TestBinarySearch();
	TestFind();
	TestRemove();
	TestRemoveAll();

	return 0;
}