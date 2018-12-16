


#include "stdio.h"
#include <stdlib.h>
#include <assert.h>

typedef int  DataType;


typedef struct ComplexNode
{
	struct ComplexNode* next;
	struct ComplexNode* random;
	DataType data;
}CN;


CN * CreateNode(int d)
{
	CN *node = (CN *)malloc(sizeof(CN));
	node->data = d;
	node->random = node->next = NULL;

	return node;
}


CN* InitComplexList()
{
	CN* n1 = CreateNode(1);
	CN* n2 = CreateNode(2);
	CN* n3 = CreateNode(3);
	CN* n4 = CreateNode(4);
	n1->next = n2; n2->next = n3; n3->next = n4;
	n1->random = n4; n2->random = n1; n3->random = n3;

	return n1;
}



void CopyComplexList(CN* list)
{
	// ��������ÿ����㣬���µĽ������ϵĽ����
	CN* cur = list;
	CN* newnode = NULL;
	// cur ֻ�����ϵĽ��
	while (cur != NULL)
	{
		newnode = CreateNode(cur->data);
		newnode->next = cur->next;
		cur->next = newnode;

		cur = newnode->next;
	}

//����random
	cur = list;
	while (cur!=NULL)
	{
		newnode = cur->next;
		if (cur->random!=NULL)
		{
			newnode->random = cur->random->next;
		}
		cur = newnode->next;
	}

	cur = list;
	CN *Next, *newNext;
	CN *result = list->next;
	while (cur!=NULL)
	{
		newnode = cur->next;
		Next = newnode->next;
		if (Next!=NULL)
		{
			newNext = Next->next;
		}
		else
		{
			newNext = NULL;
		}
		cur->next = Next;
		newnode->next = newNext;

		cur = cur->next;

	}
	printf("���Ƴɹ�\n");

}



int main()
{
	CN* list = InitComplexList();
	CopyComplexList(list);
	return 0;
}