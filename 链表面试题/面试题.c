#pragma  once


#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

typedef int DataType;

// 不是链表的结构体
// 链表中一个结点的结构体
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode;




//初始化
void InitLinList(pNode* pn)
{
	assert(pn);
	*pn = NULL;
}

//创建新的节点
Node* CreatNewNode(DataType d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;
	return node;
}


//打印
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


//尾插
void PushBack(pNode* pn, DataType d)
{
	assert(pn);
	Node* cur = *pn;

	Node* newnode = CreatNewNode(d);

	//链表为空
	if (*pn == NULL)
	{
		*pn = newnode;
		return;
	}

	//至少有一个数据
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}


// 查找（顺序查找） 找到了，返回所在结点地址，没有找到返回 NULL
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


//一、从尾到头打印单链表
//1.递归
void TailPrintR(Node* pfirst)
{
	if (pfirst == NULL)
	{
		return;

	}

	TailPrintR(pfirst->next);
	printf("%d ", pfirst->data);
}
//2.非递归
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


//二、删除一个无头单链表的非尾节点（不能遍历链表）
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


//三、在无头单链表的一个节点前插入一个节点（不能遍历链表）
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


//四、单链表实现约瑟夫环
void JosephCircle(Node* first)
{
	// 构成环
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


//五、逆置/反转单链表
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


//六、单链表排序（冒泡排序&快速排序）
void BubbleSort(Node* first)
{
	assert(first);
	Node* tail = NULL;
	Node* cur = first;
	int flg = 1;//有序
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

//七、合并两个有序单链表，合并后依然有序
void Merge(Node *list1, Node *list2)
{
	Node* result = NULL;
	Node* tail = NULL;	// result这个链表中的最后一个结点

	Node* cur1 = list1;
	Node* cur2 = list2;
	Node* node;

	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			node = cur1;//需要插入的节点；
			cur1 = cur1->next;

		}
		else
		{
			node = cur2;
			cur2 = cur2->next;

		}

		//把找到的node插入result
		if (tail == NULL)
		{
			result = node;
		}
		else
		{
			tail->next = node;
		}
		node->next = NULL;
		//node成为最后一个节点；
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

//八、查找链表的中间节点，要求只能遍历一次
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

//九、求两个已排序单链表中相同的数据
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

			//处理重复问题：如：1 1 2 3     1 1 3 4
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


//十、查找链表倒数第k个节点，要求只能遍历一遍
void TheLastK(Node* first, int k)
{
	assert(first);
	assert(k > 0);
	Node* forward = first;
	Node* backward = first;
	Node* Front = first;
	//forward先走（k-1）步
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
	//打印倒数第k个
	printf("%d\n", backward->data);
	//删除倒数第k个
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
	//一、从尾到头打印单链表
	//TestTailPrint();

	//二、删除一个无头单链表的非尾节点（不能遍历链表）
	//TestRemoveNoHeadNotTail();

	//三、在无头单链表的一个节点前插入一个节点（不能遍历链表）
	//TestBeforeNode();

	//四、单链表实现约瑟夫环
	//TestJosephCircle();

	//五、逆置/反转单链表
	//TestReverse1();
	//TestReverse2();

	//六、单链表排序（冒泡排序&快速排序）
	//TestBubbleSort();

	//七、合并两个有序单链表，合并后依然有序
	//TestMerge();

	//八、查找链表的中间节点，要求只能遍历一次
	//TestFindMidNode();

	//九、求两个已排序单链表中相同的数据
	//TestUnionSet();

	//十、查找链表倒数第k个节点，要求只能遍历一遍/并删除
	//TestTheLastK();


	return 0;
}










