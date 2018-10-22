#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct SNode 
{
	char date[100];		// key
	int count;	// 课程数量	value
	struct SNode *left;
	struct SNode *right;
}SNode;


// 只有查找和插入
int * SchedulSearch(SNode *root, char *date)
{
	if (root == NULL) {
		return NULL;
	}

	int r = strcmp(date, root->date);
	if (r == 0) {
		return &root->count;
	}
	else if (r < 0) {
		return SchedulSearch(root->left, date);
	}
	else {
		return SchedulSearch(root->right, date);
	}
}





int SchedelInsert(SNode **pproot, char *date, int count)
{
	if (*pproot == NULL) 
	{
		// 插入
		SNode *node = (SNode *)malloc(sizeof(SNode));
		node->left = node->right = NULL;
		strcpy(node->date, date);
		node->count = count;
		*pproot = node;

		return 0;
	}

	int r = strcmp(date, (*pproot)->date);
	if (r == 0) 
	{
		return -1;
	}
	else if (r < 0) 
	{
		return SchedelInsert(&(*pproot)->left, date, count);
	}
	else 
	{
		return SchedelInsert(&(*pproot)->right, date, count);
	}
}


void test4()
{
	SNode *root = NULL;
	char *courses[][2] = {
		{ "2018-10-16", "DS" },
		{ "2018-10-16", "Linux" },
		{ "2018-10-17", "Computer" },
		{ "2018-10-17", "PE" },
		{ "2018-10-16", "PE" },
		{ "2018-10-18", "Linux" }
	};

	for (int i = 0; i < sizeof(courses) / sizeof(courses[0]); i++) 
	{
		char * date = courses[i][0];
		int *pCount = SchedulSearch(root, date);
		if (pCount != NULL) 
		{
			*pCount += 1;
		}
		else 
		{
			SchedelInsert(&root, date, 1);
		}
	}

	printf("成功\n");
}