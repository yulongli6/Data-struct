#pragma once

#include "stdio.h"
#include "stdlib.h"
#include<assert.h>
#include "Queue.h"

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
RESULT create_tree(TDataType preorder[], int size)
{
	if (size==0)
	{
		RESULT result = { NULL, 0 };
		return result;
	}

	//�� ������ ������
	TDataType root_value = preorder[0];

	if (-1 == root_value)
	{
		RESULT result = { NULL, 1 };
		return result;
	}

	BNode* root = create_BNode(root_value);

	RESULT lr = create_tree(&preorder[1], size - 1);
	root->left = lr.root;
	RESULT rr = create_tree(&preorder[1 + lr.used], size - 1 - lr.used);
	root->right = rr.root;

	RESULT result = { root, 1 + lr.used + rr.used };
	return result;
}


//��������ǰ��
void Preorder(BNode* root)
{
	//��ֹ����
	if (NULL == root)
	{
		return;
	}

	//��
	printf("%d", root->data);
	//���������������õݹ鴦��
	Preorder(root->left);
	//���������������õݹ鴦��
	Preorder(root->right);
}


//����
void Inorder(BNode* root)
{
	//��ֹ����
	if (NULL == root)
	{
		return;
	}

	//���������������õݹ鴦��
	Inorder(root->left);
	//��
	printf("%d", root->data);
	//���������������õݹ鴦��
	Inorder(root->right);
}


//����
void Postorder(BNode* root)
{
	//��ֹ����
	if (NULL == root)
	{
		return;
	}

	//���������������õݹ鴦��
	Postorder(root->left);
	//���������������õݹ鴦��
	Postorder(root->right);
	//��
	printf("%d", root->data);
}


//�����Ľڵ����
int get_size(BNode* root)
{
	//��ֹ����
	if (NULL == root)
	{
		//����
		return 0;
	}

	return get_size(root->left) + get_size(root->right) + 1;
}


//��Ҷ�ӽڵ�ĸ���
int get_leaf_size(BNode* root)
{
	//��ֹ����
	if (NULL == root)
	{
		//����
		return 0;
	}

	else if (NULL == root->left && NULL == root->right)
	{
		//ֻ��һ���ڵ����
		return 1;
	}

	else
		return get_leaf_size(root->left) 
		+ get_leaf_size(root->right);
}

//�� ��k�� �Ľڵ����
int get_k_level_size(BNode* root,int k)
{
	assert(k > 0);
	if (NULL == root)
	{
		return 0;
	}

	if (1 == k)
	{
		return 1;
	}

	return get_k_level_size(root->left, k - 1) 
		+ get_k_level_size(root->right, k - 1);
}


//��������ĸ߶�
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int get_height(BNode* root)
{
	if (NULL == root)
	{
		return 0;
	}

	int left_height = get_height(root->left);
	int right_height = get_height(root->right);

	return MAX(left_height, right_height) + 1;
}


//���ҽ�㣺
//����ҵ������ؽڵ��ַ
//���û�ҵ�������NULL
//���Ҳ��ԣ�
//����ǿ���������NULL
//��������У�ֱ�ӷ��ظ��ĵ�ַ
//��ȥ�������ң�������û�ҵ�����ȥ��������

BNode* Search(BNode* root,TDataType data)
{
	if (NULL == root)
	{
		return NULL;
	}

	if (data == root->data)
	{
		return root;
	}

	BNode* node = Search(root->left,data);
	if (NULL != node)
	{
		return node;
	}

	BNode* node = Search(root->right, data);
	if (NULL != node)
	{
		return node;
	}

	else
	{
		return NULL;
	}
}



//����----����
void level_order(BNode* root)
{
	Queue queue;
	InitQueue(&queue);

	if (NULL == root)
	{
		return;
	}
	PushQueue(&queue, root);

	while (!QueueEmpty(&queue))
	{
		BNode* front = QueueFront(&queue);
		PopQueue(&queue);
		printf("%d", root->data);
		if (NULL != front->left)
		{
			PushQueue(&queue, front->left);
		}
		if (NULL != front->right)
		{
			PushQueue(&queue, front->right);
		}
	}
	DestroyQueue(&queue);
}


//�ж϶������Ƿ�����ȫ������
int is_not_complete_binary_tree(BNode* root)
{
	Queue queue;
	InitQueue(&queue);
	if (NULL == root)
	{
		return 1;
	}
	PushQueue(&queue,root);
	while (!QueueEmpty(&queue))
	{
		BNode* front = QueueFront(&queue);
		PopQueue(&queue);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}
	while (!QueueEmpty(&queue))
	{
		BNode* node = QueueFront(&queue);
		QueuePop(&queue);
		if (node != NULL)
			return 0;
	}
	return 1;
	DestroyQueue(&queue);
	return 1;
}