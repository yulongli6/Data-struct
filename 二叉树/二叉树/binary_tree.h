#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef int TDataType;

typedef struct BNode 
{
	TDataType data;
	struct BNode* left;
	struct BNode* right;
}BNode;

static BNode* create_BNode(TDataType data)
{
	BNode* node = (BNode*)malloc(sizeof(BNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

typedef struct  
{
	BNode* root;
	int used;
} RESULT;


// ���ú��ս���ǰ�򴴽�������
// ���ؽ���Ƕ������ĸ����
// preorder: ���ս���ǰ��
// size: preorder�ĳ���
// 1. �ݹ�
// 2. �������Ĺ����л᷵��ʹ�ù��Ľ�����

RESULT create_tree(TDataType pre_order[], int size)
{
	if (size==0)
	{
		RESULT result = { NULL, 0 };
		return result;
	}

	//�� ������ ������
	TDataType root_value = pre_order[0];

	if (-1 == root_value)
	{
		RESULT result = { NULL, 1 };
		return result;
	}

	BNode* root = create_BNode(root_value);

	RESULT lr = create_tree(&pre_order[1], size - 1);
	root->left = lr.root;
	RESULT rr = create_tree(&pre_order[1 + lr.used], size - 1 - lr.used);
	root->right = rr.root;

	RESULT result = { root, 1 + lr.used + rr.used };
	return result;
}
