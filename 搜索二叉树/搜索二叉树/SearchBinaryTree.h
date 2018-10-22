#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Key;

typedef struct SBTreeNode 
{
	Key key;
	struct SBTreeNode* left;
	struct SBTreeNode* right;
}  SBTreeNode;


// ����ҵ��ˣ����� 0 ��ʾ�ɹ�
// ���û�ҵ������� -1 ��ʾʧ��
int SBTreeSearch(SBTreeNode* root, Key key)
{
	if (root==NULL)
	{
		// ����
		return -1;
	}
	if (key == root->key)
	{
		return 0;
	}
	else if (key < root->key)
	{
		return SBTreeSearch(root->left, key);
	}
	else
	{
		return SBTreeSearch(root->right, key);
	}
}


int SBTreeSearchLoop(SBTreeNode* root, Key key)
{
	SBTreeNode* cur = root;
	while (cur != NULL)
	{
		if (key == cur->key)
		{
			return 0;
		}
		else if (key < cur->key) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	return -1;
}


// ����
// ����ظ�������ʧ�ܣ� ���� -1
// ������ظ�������ɹ��� ���� 0
// �ǵݹ�
int SBTreeInsertLoop(SBTreeNode** pproot, Key key)
{
	assert(pproot);
	SBTreeNode* cur = *pproot;
	SBTreeNode* parent = NULL;

	while (cur != NULL)
	{
		if (key == cur->key)
		{
			return -1;
		}

		parent = cur;
		if (key < cur->key) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	SBTreeNode* node = (SBTreeNode*)malloc(sizeof(SBTreeNode));
	node->key = key;
	node->left = node->right = NULL;

	if (parent == NULL) 
	{
		// �Կ���������
		*pproot = node;
	}
	else if (key < parent->key)
	{
		parent->left = node;
	}
	else 
	{
		parent->right = node;
	}
	return 0;
}


int SBTreeInsert(SBTreeNode** pproot, Key key)
{
	if (*pproot == NULL) {
		SBTreeNode *node = (SBTreeNode *)malloc(sizeof(SBTreeNode));
		node->key = key;
		node->left = NULL; node->right = NULL;
		*pproot = node;
		return 0;
	}

	if (key == (*pproot)->key)
	{
		return -1;
	}

	if (key < (*pproot)->key) 
	{
		return SBTreeInsert(&(*pproot)->left, key);
	}
	else 
	{
		return SBTreeInsert(&(*pproot)->right, key);
	}
}


// ����ҵ����ɹ�ɾ�������� 0
// ���򷵻� -1
int SBTreeRemoveLoop(SBTreeNode** pproot, Key key)
{
	SBTreeNode* cur = *pproot;
	SBTreeNode*parent = NULL;

	while (cur != NULL)
	{
		if (key == cur->key)
		{
			if (cur->left == NULL)
			{
				if (parent == NULL)
				{
					*pproot = cur->right;
				}
				else if (key < parent->key)
				{
					parent->left = cur->right; 
				}
			}
			if (parent == NULL)
			{
				*pproot = cur->right;
			}
			else if (key < parent->key)
			{
				parent->left = cur->right;
			}
			else
			{
				parent->right = cur->right;
			}
			free(cur);
			return 0;
		}
		else if (cur->right == NULL)
		{
			if (parent == NULL) 
			{
				// Ҫɾ�����Ǹ����
				*pproot = cur->left;
			}
			else if (key < parent->key)
			{
				parent->left = cur->right;
			}
			else
			{
				parent->right = cur->left;
			}
			free(cur);
			return 0;
		}
		else
		{
			// �滻��ɾ��
			// ���Һ��Ӷ���Ϊ��

			// ������������С��һ��
			SBTreeNode* del = cur->right;
			SBTreeNode* delParent = cur;
			while (del->left != NULL)
			{
				delParent = del;
				del = del->left;
			}

			cur->key = del->key;
			if (delParent == cur)
			{
				delParent->right = del->right;
			}
			else
			{
				delParent->left = del->right;
			}
			free(del);
			return 0;
		}

		parent = cur;
		if (key < cur->key) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	return -1;
}


void test()
{
	SBTreeNode* root = NULL;

	SBTreeInsert(&root, 5);
	SBTreeInsert(&root, 3);
	SBTreeInsert(&root, 7);
	SBTreeInsert(&root, 1);
	SBTreeInsert(&root, 4);
	SBTreeInsert(&root, 6);
	SBTreeInsert(&root, 8);
	SBTreeInsert(&root, 0);
	SBTreeInsert(&root, 2);
	SBTreeInsert(&root, 9);

	printf("%d\n", SBTreeSearchLoop(root, 3));
	printf("%d\n", SBTreeSearchLoop(root, 2));
	printf("%d\n", SBTreeSearchLoop(root, -1));
}