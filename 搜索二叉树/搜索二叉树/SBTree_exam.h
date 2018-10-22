
//将一个二叉搜索树转换成一个排序的双向链表（不能创建新节点）
#pragma once


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}	Node;


Node* CreateNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->right = node->left = NULL;

	return node;
}

Node* prev = NULL;

void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	Inorder(root->left);

	if (prev != NULL)
	{
		prev->right = root;
	}
	root->left = prev;
	prev = root;

	Inorder(root->right);
}



void test2()
{
	Node *n1 = CreateNode(1);
	Node *n2 = CreateNode(2);
	Node *n3 = CreateNode(3);
	Node *n4 = CreateNode(4);
	Node *n5 = CreateNode(5);
	Node *n6 = CreateNode(6);

	n4->left = n2;
	n4->right = n6;
	n2->left = n1;
	n2->right = n3;
	n6->left = n5;

	Inorder(n4);

	printf("成功\n");
}