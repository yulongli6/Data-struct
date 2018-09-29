#include "LinList.h"



//�ж����������Ƿ��ཻ�����ཻ���󽹵㣨��������


int GetLength(Node* first)
{
	int count = 0;
	Node* cur = first;
	while (cur!=NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

Node* Intersect(Node* last1, Node* last2)
{
	Node* cur1 = last1;
	Node* cur2 = last2;
	while (cur1->next!=NULL)
	{
		cur1 = cur1->next;
	}
	while (cur2->next != NULL)
	{
		cur2 = cur2->next;
	}
	if (cur1!=cur2)
	{
		printf("���ཻ\n");
		return;
	}


	//һ���н���
	int len1 = GetLength(last1);
	int len2 = GetLength(last2);
	int lenD = 0;
	Node* forward = NULL;
	Node* backward = NULL;
	if (len1 <= len2)
	{
		forward = last2;
		backward = last1;
		lenD = len2 - len1;
	}
	else
	{
		forward = last1;
		backward = last2;
		lenD = len1 - len2;
	}

	while (lenD--)
	{
		forward = forward->next;
	}

	while (forward != backward)
	{
		forward = forward->next;
		backward = backward->next;
	}
	return forward;
}



//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿


void IsNoCircle(Node* first)
{
	Node* fast = first;
	Node* slow = first;
	while (fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast==slow)
		{
			printf("����\n");

			return;
		}
	}
	printf("������\n");
}


//����
int CircleLength(Node* first)
{
	Node* fast = first;
	Node* slow = first;
	fast = fast->next;
	slow = slow->next;
	int count = 1;
	while (fast!=slow)
	{
		fast = fast->next;
		slow = slow->next;
		count++;
	}
	return count;
}

//���
Node* Entry(Node* first)
{
	Node* fast = first;
	Node* slow = first;
	fast = fast->next;
	slow = slow->next;
	while (fast!=slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	Node* node = first;
	while (node!=slow)
	{
		node = node->next;
		slow = slow->next;
	}
	return node;
}




