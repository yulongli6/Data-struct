#pragma  once


#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

typedef int DataType;

// ��������Ľṹ��
// ������һ�����Ľṹ��
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode;




//��ʼ��
void InitLinList(pNode* pn)
{
	assert(pn);
	*pn = NULL;
}

//�����µĽڵ�
Node* CreatNewNode(DataType d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;
	return node;
}


//��ӡ
void PrintLinList(pNode first)
{
	Node* cur = first;
	printf("first-->");
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//β��
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//����Ϊ��
	if (*pn == NULL)
	{
		*pn = newnode;
		return;
	}

	//������һ������
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}


// ���ң�˳����ң� �ҵ��ˣ��������ڽ���ַ��û���ҵ����� NULL
Node* FindLinList(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur;
	for (cur = *pn; cur != NULL; cur = cur->next)
	{
		if (cur->data == d)
		{
			return cur;
		}
	}
	return NULL;
}


//һ����β��ͷ��ӡ������
//1.�ݹ�
void TailPrintR(Node* pfirst)
{
	if (pfirst == NULL)
	{
		return;

	}

	TailPrintR(pfirst->next);
	printf("%d ", pfirst->data);
}
//2.�ǵݹ�
void TailPrint(Node* pfirst)
{
	Node* cur = pfirst;
	Node* last = NULL;

	while (last != pfirst)
	{
		cur = pfirst;
		while (cur->next != last)
		{
			cur = cur->next;
		}

		printf("%d ", cur->data);
		last = cur;
	}
}

void TestTailPrint()
{
	Node* first;
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PushBack(&first, 5);
	PrintLinList(first);

	TailPrint(first);
}


//����ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
void RemoveNoHeadNotTail(Node* Del)
{
	assert(Del->next != NULL);
	Node* next = Del->next;
	Del->data = next->data;
	Del->next = next->next;
	free(next);
}


void TestRemoveNoHeadNotTail()
{
	Node* first;
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PushBack(&first, 5);
	PrintLinList(first);

	Node* Del = FindLinList(&first, 4);
	RemoveNoHeadNotTail(Del);
	PrintLinList(first);
}


//��������ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
void BeforeNode(Node* node, DataType d)
{
	assert(node);
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = node->data;
	newnode->next = node->next;

	node->data = d;
	node->next = newnode;
}


void TestBeforeNode()
{
	Node* first;
	InitLinList(&first);
	PushBack(&first, 1);
	PushBack(&first, 2);
	PushBack(&first, 3);
	PushBack(&first, 4);
	PushBack(&first, 5);
	PrintLinList(first);

	Node* Push = FindLinList(&first, 4);
	BeforeNode(Push, 10);
	PrintLinList(first);
}


//�ġ�������ʵ��Լɪ��
void JosephCircle(Node* first)
{
	// ���ɻ�
	Node *cur = first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = first;

	cur = first;
	while (cur->next != cur)
	{
		cur = cur->next;
		Node* Del = cur->next;
		cur->next = Del->next;
		free(Del);
		cur = cur->next;

	}

	printf("%d\n", cur->data);
}

void TestJosephCircle()
{
	Node* first;
	InitLinList(&first);
	for (int i = 1; i <= 32; i++)
	{
		PushBack(&first, i);
	}

	JosephCircle(first);
}


//�塢����/��ת������
void Reverse1(Node* first)
{
	if (first == NULL || first->next == NULL)
	{
		return;
	}

	Node* p1 = first;
	Node* p2 = first->next;
	Node* p3 = first->next->next;
	while (p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}
	first->next = NULL;

	PrintLinList(p1);
}


void TestReverse1()
{
	Node* first;
	InitLinList(&first);
	for (int i = 1; i <= 6; i++)
	{
		PushBack(&first, i);
	}
	PrintLinList(first);

	Reverse1(first);
}


void Reverse2(Node* first)
{
	assert(first);
	Node* result = NULL;
	Node* cur = first;
	Node* node;
	while (cur != NULL)
	{
		node = cur;
		cur = cur->next;

		node->next = result;
		result = node;
	}
	PrintLinList(result);
}


void TestReverse2()
{
	Node* first;
	InitLinList(&first);
	for (int i = 1; i <= 6; i++)
	{
		PushBack(&first, i);
	}
	PrintLinList(first);

	Reverse2(first);
}


//��������������ð������&��������
void BubbleSort(Node* first)
{
	assert(first);
	Node* tail = NULL;
	Node* cur = first;
	int flg = 1;//����
	while (cur != tail)
	{
		while (cur->next != tail)
		{
			if (cur->data > cur->next->data)
			{
				DataType tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
				flg = 0;
			}
			cur = cur->next;
		}
		if (flg == 1)
		{
			return;
		}
		tail = cur;
		cur = first;
	}

}


void TestBubbleSort()
{
	Node* first;
	InitLinList(&first);
	for (int i = 6; i > 0; i--)
	{
		PushBack(&first, i);
	}
	PrintLinList(first);

	BubbleSort(first);
	PrintLinList(first);
}

//�ߡ��ϲ��������������ϲ�����Ȼ����
void Merge(Node *list1, Node *list2)
{
	Node* result = NULL;
	Node* tail = NULL;	// result��������е����һ�����

	Node* cur1 = list1;
	Node* cur2 = list2;
	Node* node;

	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			node = cur1;//��Ҫ����Ľڵ㣻
			cur1 = cur1->next;

		}
		else
		{
			node = cur2;
			cur2 = cur2->next;

		}

		//���ҵ���node����result
		if (tail == NULL)
		{
			result = node;
		}
		else
		{
			tail->next = node;
		}
		node->next = NULL;
		//node��Ϊ���һ���ڵ㣻
		tail = node;
	}
	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->next = cur1;
	}

	PrintLinList(result);
}




void TestMerge()
{
	Node* first1 = NULL;
	Node* first2 = NULL;

	PushBack(&first1, 1);
	PushBack(&first1, 2);
	PushBack(&first1, 3);

	PushBack(&first2, 1);
	PushBack(&first2, 1);
	PushBack(&first2, 3);
	PushBack(&first2, 4);

	Merge(first1, first2);
}

//�ˡ�����������м�ڵ㣬Ҫ��ֻ�ܱ���һ��
void FindMidNode(Node* first)
{
	Node* fast = first;
	Node* slow = first;

	while (1)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
	}

	printf("%d\n", slow->data);
}

void TestFindMidNode()
{
	Node* first = NULL;
	for (int i = 1; i <= 6; i++)
	{
		PushBack(&first, i);
	}
	FindMidNode(first);

}

//�š���������������������ͬ������
void UnionSet(Node* last1, Node* last2)
{
	Node* cur1 = last1;
	Node* cur2 = last2;

	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data == cur2->data)
		{
			printf("%d ", cur1->data);
			Node* Front1 = cur1;
			Node* Front2 = cur2;
			cur1 = cur1->next;
			cur2 = cur2->next;

			//�����ظ����⣺�磺1 1 2 3     1 1 3 4
			if (Front1->data == cur1->data&&Front2->data == cur2->data)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
		else if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else
		{
			cur2 = cur2->next;
		}

	}
	printf("\n");
}


void TestUnionSet()
{
	Node* last1 = NULL;
	Node* last2 = NULL;

	PushBack(&last1, 1);
	PushBack(&last1, 1);
	PushBack(&last1, 3);
	PushBack(&last1, 7);
	PushBack(&last1, 9);

	PushBack(&last2, 1);
	PushBack(&last2, 1);
	PushBack(&last2, 4);
	PushBack(&last2, 5);
	PushBack(&last2, 7);

	UnionSet(last1, last2);
}


//ʮ��������������k���ڵ㣬Ҫ��ֻ�ܱ���һ��
void TheLastK(Node* first, int k)
{
	assert(first);
	assert(k > 0);
	Node* forward = first;
	Node* backward = first;
	Node* Front = first;
	//forward���ߣ�k-1����
	while (--k)
	{
		forward = forward->next;
	}

	while (forward->next != NULL)
	{
		Front = backward;
		backward = backward->next;
		forward = forward->next;
	}
	//��ӡ������k��
	printf("%d\n", backward->data);
	//ɾ��������k��
	Front->next = backward->next;
	free(backward);
	PrintLinList(first);

}


void TestTheLastK()
{
	Node* first = NULL;
	for (int i = 1; i <= 10; i++)
	{
		PushBack(&first, i);
	}
	int k = 3;
	TheLastK(first, k);
}





int main()
{
	//һ����β��ͷ��ӡ������
	//TestTailPrint();

	//����ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
	//TestRemoveNoHeadNotTail();

	//��������ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
	//TestBeforeNode();

	//�ġ�������ʵ��Լɪ��
	//TestJosephCircle();

	//�塢����/��ת������
	//TestReverse1();
	//TestReverse2();

	//��������������ð������&��������
	//TestBubbleSort();

	//�ߡ��ϲ��������������ϲ�����Ȼ����
	//TestMerge();

	//�ˡ�����������м�ڵ㣬Ҫ��ֻ�ܱ���һ��
	//TestFindMidNode();

	//�š���������������������ͬ������
	//TestUnionSet();

	//ʮ��������������k���ڵ㣬Ҫ��ֻ�ܱ���һ��/��ɾ��
	//TestTheLastK();


	return 0;
}










