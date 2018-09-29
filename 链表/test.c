#define _CRT_SECURE_NO_DEPRECATE 1

#include "LinList.h"
Node *first;

//头插
void TestPushFront()
{
	InitLinList(&first);
	PushFront(&first, 1);
	PushFront(&first, 2);
	PushFront(&first, 3);
	PushFront(&first, 4);
	PrintLinList(first);
}


//尾插
void TestPushBack()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);
}


void TestPopFront()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);

	PopFront(&first);
	PrintLinList(first);
	PopFront(&first);
	PrintLinList(first);
	PopFront(&first);
	PrintLinList(first);
	PopFront(&first);
	PrintLinList(first);
}


void TestPopBack()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);

	PopBack(&first);
	PrintLinList(first);
	PopBack(&first);
	PrintLinList(first);
	PopBack(&first); 
	PrintLinList(first);
	PopBack(&first); 
	PrintLinList(first);
}


void TestFindLinList()
{
	Node* ret = 0;
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);

	ret = FindLinList(&first, 1);
	if (ret == NULL)
	{
		printf("数据不存在\n");
	}
	else
		printf("%p\n", ret);

}


void TestInsert()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);

	Node* p = FindLinList(&first, 3);
	Insert(&first, p, 10);
	PrintLinList(first);
}


void TestErase()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PrintLinList(first);

	Node* p = FindLinList(&first, 3);
	Erase(&first, p);
	PrintLinList(first);
}


void TestRemove()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 1);
	PushBack(&first, 3);
	PushBack(&first, 1);
	PrintLinList(first);

	Remove(&first, 1);
	PrintLinList(first);
}



void TestRemoveAll()
{
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 1);
	PushBack(&first, 3);
	PushBack(&first, 1);
	PrintLinList(first);

	RemoveAll(&first, 1);
	PrintLinList(first);
}



int main()
{
	//TestPushFront();
	//TestPushBack();
	//TestPopFront();
	//TestPopBack();
	//TestFindLinList();
	//TestInsert();
	//TestErase();
	//TestRemove();
	TestRemoveAll();

	return 0;
}
