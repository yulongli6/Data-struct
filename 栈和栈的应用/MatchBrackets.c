//����ƥƥ������

#define _CRT_SECURE_NO_DEPRECATE 1

#include "Stack.h"

void MatchBrackets(const char* p)
{
	Stack stack;
	StackInit(&stack);

	while (*p != '\0')
	{
		switch (*p)
		{
		case '(':
		case '{':
		case '[':
			StackPush(&stack, *p);
			break;
		case ')':
		case '}':
		case ']':
			if (StackEmpty(&stack))
			{
				printf("�����Ŷ�\n");
				return;
			}
			char top = StackTop(&stack);
			StackPop(&stack);

			if (!((top == '(' && *p == ')') ||
				(top == '[' && *p == ']') ||
				(top == '{' && *p == '}')))
			{
				printf("�������Ų�ƥ��\n");
				return;
			}
			break;
		default:
			break;
		}
		p++;
	}
	if (!StackEmpty(&stack))
	{
		printf("�����Ŷ�\n");
	}
	else
	{
		printf("��������ƥ��\n");
	}
}


int main()
{
	char a[] = "(())abc{[(])}"; // �������Ŵ���ƥ�䲻��ȷ
	char b[] = "(()))abc{[]}"; // �����Ŷ���������
	char c[] = "(()()abc{[]}"; // �����Ŷ���������
	char d[] = "(())abc{[]()}";

	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
	return 0;
}
