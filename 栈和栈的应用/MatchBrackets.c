//¿®∫≈∆•∆•≈‰Œ Ã‚

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
				printf("”“¿®∫≈∂‡\n");
				return;
			}
			char top = StackTop(&stack);
			StackPop(&stack);

			if (!((top == '(' && *p == ')') ||
				(top == '[' && *p == ']') ||
				(top == '{' && *p == '}')))
			{
				printf("◊Û”“¿®∫≈≤ª∆•≈‰\n");
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
		printf("◊Û¿®∫≈∂‡\n");
	}
	else
	{
		printf("◊Û”“¿®∫≈∆•≈‰\n");
	}
}


int main()
{
	char a[] = "(())abc{[(])}"; // ◊Û”“¿®∫≈¥Œ–Ú∆•≈‰≤ª’˝»∑
	char b[] = "(()))abc{[]}"; // ”“¿®∫≈∂‡”⁄◊Û¿®∫≈
	char c[] = "(()()abc{[]}"; // ◊Û¿®∫≈∂‡”⁄”“¿®∫≈
	char d[] = "(())abc{[]()}";

	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
	return 0;
}
