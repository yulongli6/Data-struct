#define _CRT_SECURE_NO_DEPRECATE 1

#include "binary_tree.h"

int main()
{
	RESULT result;
	TDataType pre_order[] = { 1, 2, 4, -1, 6 , - 1, -1, -1, 3, -1, 5, -1, -1 };
	int size = sizeof(pre_order) / sizeof(pre_order[0]);
	result=create_tree(pre_order,size);
	return 0;
}