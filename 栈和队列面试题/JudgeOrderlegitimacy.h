//判断元素出栈、入栈的合法性

#pragma once

#include <stdio.h>
#include "stack.h"


void JOLPrint(int in[],int out[], int size)
{
	int ii = 0; int io = 0;
	Stack stack;
	StackInit(&stack);

	while (ii<size)
	{
		if (in[ii]==out[io])
		{
			ii++; io++;
		}
		else
		{
			if (!StackEmpty(&stack) && out[io] == StackTop(&stack))
			{
				StackPop(&stack);
				io++;
			}
			else
			{
				StackPush(&stack, in[ii]);
				ii++;
			}
		}
	}

	while (!StackEmpty(&stack))
	{
		if (out[io]!=StackTop(&stack))
		{
			printf("不合法\n");
			return;
		}

		StackPop(&stack);
		io++;
	}
	printf("合法\n");
}


void test()
{
	int in[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	int out[] = { 'f', 'e', 'g', 'd', 'a', 'c', 'b' };
	int size = sizeof(in) / sizeof(int);

	JOLPrint(in, out, size);
}