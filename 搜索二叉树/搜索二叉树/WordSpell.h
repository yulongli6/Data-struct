#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct WNode 
{
	char word[100];
	struct WNode* left;
	struct WNode* right;
}WNode;


// 只有查找和插入
int Search(WNode* root, char* word)
{
	if (root == NULL)
	{
		return -1;
	}

	int r = strcmp(word, root->word);
	if (r == 0) 
	{
		return 0;
	}
	else if (r < 0) 
	{
		return Search(root->left, word);
	}
	else
	{
		return Search(root->right, word);
	}
}


int Insert(WNode **pproot, char *word)
{
	if (*pproot == NULL) 
	{
		// 插入
		WNode *node = (WNode *)malloc(sizeof(WNode));
		node->left = node->right = NULL;
		strcpy(node->word, word);
		*pproot = node;

		return 0;
	}

	int r = strcmp(word, (*pproot)->word);
	if (r == 0) 
	{
		return -1;
	}
	else if (r < 0) 
	{
		return Insert(&(*pproot)->left, word);
	}
	else 
	{
		return Insert(&(*pproot)->right, word);
	}
}



void test3()
{
	char * words[] = {
		"Apple", "Orange", "Banana", "Watermelon", "Pinapple",
		"Average", "Dictionary", "Pen", "Able"
	};

	WNode *root = NULL;
	for (int i = 0; i < sizeof(words) / sizeof(char *); ++i) 
	{
		Insert(&root, words[i]);
	}

	while (1)
	{
		char word[100];
		scanf("%s", word);
		if (Search(root, word) == 0) 
		{
			printf("拼写正确\n");
		}
		else {
			printf("拼写错误\n");
		}
	}
}