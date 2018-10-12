#pragma once

#include "stdio.h"
#include "stdlib.h"
#include<assert.h>
#include "Queue.h"
#include "Stack.h"

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


// 利用含空结点的前序创建二叉树
// 返回结果是二叉树的根结点
// preorder: 带空结点的前序
// size: preorder的长度
// 1. 递归
// 2. 创建树的过程中会返回使用过的结点个数
RESULT create_tree(TDataType preorder[], int size)
{
	if (size==0)
	{
		RESULT result = { NULL, 0 };
		return result;
	}

	//根 左子树 右子树
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


//二叉树的前序
void Preorder(BNode* root)
{
	//终止条件
	if (NULL == root)
	{
		return;
	}

	//根
	printf("%d ", root->data);
	//左子树，子问题用递归处理
	Preorder(root->left);
	//右子树，子问题用递归处理
	Preorder(root->right);
}


//中序
void Inorder(BNode* root)
{
	//终止条件
	if (NULL == root)
	{
		return;
	}

	//左子树，子问题用递归处理
	Inorder(root->left);
	//根
	printf("%d ", root->data);
	//右子树，子问题用递归处理
	Inorder(root->right);
}


//后序
void Postorder(BNode* root)
{
	//终止条件
	if (NULL == root)
	{
		return;
	}

	//左子树，子问题用递归处理
	Postorder(root->left);
	//右子树，子问题用递归处理
	Postorder(root->right);
	//根
	printf("%d ", root->data);
}


//求树的节点个数
int get_size(BNode* root)
{
	//终止条件
	if (NULL == root)
	{
		//空树
		return 0;
	}

	return get_size(root->left) + get_size(root->right) + 1;
}


//求叶子节点的个数
int get_leaf_size(BNode* root)
{
	//终止条件
	if (NULL == root)
	{
		//空树
		return 0;
	}

	else if (NULL == root->left && NULL == root->right)
	{
		//只有一个节点的树
		return 1;
	}

	else
		return get_leaf_size(root->left) 
		+ get_leaf_size(root->right);
}

//求 第k层 的节点个数
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


//求二叉树的高度
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


//查找结点：
//如果找到，返回节点地址
//如果没找到，反会NULL
//查找策略：
//如果是空树，返回NULL
//如果根命中，直接返回根的地址
//先去左子树找，左子树没找到，再去右子树找

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

	BNode* l_node = Search(root->left,data);
	if (NULL != l_node)
	{
		return l_node;
	}

	BNode* r_node = Search(root->right, data);
	if (NULL != r_node)
	{
		return r_node;
	}

	else
	{
		return NULL;
	}
}



//层序----队列
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
		printf("%d ", front->data);
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


//判断二叉树是否是完全二叉树
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
		PushQueue(&queue, front->left);
		PushQueue(&queue, front->right);
	}
	while (!QueueEmpty(&queue))
	{
		BNode* node = QueueFront(&queue);
		PopQueue(&queue);
		if (node != NULL)
			return 0;
	}
	return 1;
	DestroyQueue(&queue);
	return 1;
}




void pre_order_loop(BNode* root)
{
	Stack stack;
	StackInit(&stack);

	BNode* node = root;
	BNode* top;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (NULL != node)
		{
			printf("%d ", node->data);
			StackPush(&stack, node);   // 压栈，压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack);
		StackPop(&stack);
		node = top->right;
	}
}

void in_order_loop(BNode* root)
{
	Stack stack;
	StackInit(&stack);

	BNode* node = root;
	BNode* top;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (NULL != node)
		{
			StackPush(&stack, node);   // 压栈，压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d ",top->data);
		node = top->right;
	}
}


void post_order_loop(BNode* root)
{
	Stack stack;
	StackInit(&stack);

	BNode* node = root;
	BNode* top;
	BNode* last = NULL;
	while (node != NULL || !StackEmpty(&stack))
	{
		while (NULL != node)
		{
			StackPush(&stack, node);   // 压栈，压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			printf("%d ", top->data);
			last = top;
			StackPop(&stack);
		}
		else
			node = top->right;
	}
}


//二叉树的镜像
void Mirror(BNode* root)
{
	if (root == NULL) 
	{ 
		return; 
	}
	BNode *t = root->left;
	root->left = root->right;
	root->right = t;
	Mirror(root->left);
	Mirror(root->right);
}

//获取一个节点的双亲节点
BNode* get_parents(BNode*root, BNode* node)
{

}
//获取一个节点的左孩子节点


//获取一个节点的右孩子节点


//



void test()
{
	RESULT result;
	TDataType preorder[] = { 1, 2, 4, -1, 6, -1, -1, -1, 3, -1, 5, -1, -1 };
	int size = sizeof(preorder) / sizeof(preorder[0]);
	result = create_tree(preorder, size);
	BNode* root = result.root;

	printf("节点个数：%d\n", get_size(root));
	printf("高度：%d\n", get_height(root));
	printf("叶子个数：%d\n", get_leaf_size(root));
	printf("第k层节点个数：%d\n", get_k_level_size(root, 3));
	printf("查找F：%d\n", Search(root, 6)->data);

	Preorder(root);printf("\n");
	pre_order_loop(root); printf("\n");
	Inorder(root);printf("\n");
	in_order_loop(root); printf("\n");
	Postorder(root);printf("\n");
	post_order_loop(root); printf("\n");
	level_order(root);printf("\n");

	printf("%d\n", is_not_complete_binary_tree(root));

	Mirror(root);











































}