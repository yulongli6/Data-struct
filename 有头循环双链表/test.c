#define _CRT_SECURE_NO_DEPRECATE 1

#include "DList.h"

void Test()
{
	DN* head;
	InitDList(&head);
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PrintDList(head);

	PopBack(head);
	PrintDList(head);

	PopFront(head);
	PrintDList(head);

	PopBack(head);
	PrintDList(head);

	PopFront(head);
	PrintDList(head);




	InitDList(&head);
	PushFront(head, 1);
	PushFront(head, 2);
	PushFront(head, 3);
	PushFront(head, 4);//4 3 2 1

	PrintDList(head);

	DN* node = Find(head, 2);
	InsertDList(head, node, 10);
	PrintDList(head);

	Erase(head, node);
	PrintDList(head);

	
}


int main()
{
	Test();
	return 0;
}