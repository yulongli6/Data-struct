#define _CRT_SECURE_NO_DEPRECATE 1

#include "binary_tree.h"

int main()
{
	RESULT result;
	TDataType preorder[] = { 1, 2, 4, -1, 6 , - 1, -1, -1, 3, -1, 5, -1, -1 };
	int size = sizeof(preorder) / sizeof(preorder[0]);
	result=create_tree(preorder,size);
	return 0;
}