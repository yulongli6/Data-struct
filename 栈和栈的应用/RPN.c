//Äæ²¨À¼±í´ïÊ½
#define _CRT_SECURE_NO_DEPRECATE 1

#include "stack.h"

typedef enum
{
	NUMBER,
	OPERATE
}Type;


typedef enum
{
	ADD,
	SUB,
	DIV,
	MUL,
	NOUSED
}OP;


typedef struct
{
	Type type;
	int number;
	OP operate;
}Item;


Item array[] =
{
	{
		NUMBER,
		125,
		NOUSED
	},
	{
		NUMBER,
		145,
		NOUSED
	},
	{
		OPERATE,
		-1,
		SUB
	}
};


void RPN(Item array[], int size)
{
	Stack stack;
	StackInit(&stack);

	for (int i = 0; i < size; i++)
	{
		if (array[i].type == NUMBER)
		{
			StackPush(&stack, array[i].number);
		}
		else
		{
			int n1 = StackTop(&stack);
			StackPop(&stack);
			int n2 = StackTop(&stack);
			StackPop(&stack);
			int result;

			switch (array[i].operate)
			{
			case ADD:
				result = n1 + n2;
				break;
			case SUB:
				result = n2 - n1;
				break;
			case MUL:
				result = n1 * n2;
				break;
			case DIV:
				result = n2 / n1;
				break;
			}
			StackPush(&stack, result);
		}
	}

	assert(StackSize(&stack) == 1);

	printf("%d\n", StackTop(&stack));
}

int main()
{
	int size = sizeof(array) / sizeof(array[0]);
	RPN(array, size);
	return 0;
}

