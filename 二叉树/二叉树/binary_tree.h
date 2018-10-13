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
	printf("%d ", root->data);
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
	printf("%d ", root->data);
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
	printf("%d ", root->data);
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
			StackPush(&stack, node);   // ѹջ��ѹ���ǽ���ַ
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
			StackPush(&stack, node);   // ѹջ��ѹ���ǽ���ַ
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
			StackPush(&stack, node);   // ѹջ��ѹ���ǽ���ַ
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


//�������ľ���
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

void MirrorLoop(BNode* root)
{
	Stack stack;
	StackInit(&stack);

	BNode* node = root;
	BNode* top;
	BNode* last = NULL;

	while (node != NULL || !StackEmpty(&stack))
	{
		while (node != NULL)
		{
			StackPush(&stack, node);
			node = node->left;
		}
		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			BNode* t = top->left;
			top->left = top->right;
			top->right = t;
			last = top;
			StackPop(&stack);
		}
		else
			node = top->right;
	
	}
}



//��ȡһ���ڵ��˫�׽ڵ�
BNode* get_parent(BNode*root, BNode* child)
{
	if (root==NULL || root == child)
	{
		return NULL;
	}
	if (root->left == child || root->right == child)
	{
		return root;
	}
	BNode* l_node =get_parent(root->left, child);
	if (l_node != NULL)
	{
		return l_node;
	}
   return get_parent(root->right, child);
	
}




//��ȡһ���ڵ�����ӽڵ�
BNode* get_left_child(BNode* root, BNode* parent)
{
	if (root == NULL || (root->left == NULL && root == NULL))
	{
		return NULL;
	}
	if (parent->left == NULL)
	{
		return NULL;
	}
	return parent->left;
}



//��ȡһ���ڵ���Һ��ӽڵ�

BNode* get_right_child(BNode* root, BNode* parent)
{
	if (root == NULL || (root->left == NULL && root == NULL))
	{
		return NULL;
	}
	if (parent->right == NULL)
	{
		return NULL;
	}
	return parent->right;
}

//��������������ڵ�������������
BNode * get_nearest_ancestor(BNode *root, int n1, int n2)
{
	BNode *n1InLeft = Search(root->left, n1);
	BNode *n2InLeft = Search(root->left, n2);

	if (n1InLeft && !n2InLeft) {
		return root;
	}

	if (!n1InLeft && n2InLeft) {
		return root;
	}

	if (n1InLeft) {
		return get_nearest_ancestor(root->left, n1, n2);
	}
	else {
		return get_nearest_ancestor(root->right, n1, n2);
	}
}

//�ж��Ƿ���ƽ�������
int IsBalance(BNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	int isBalance = IsBalance(root->left);
	if (isBalance == 0) 
	{
		return 0;
	}

	isBalance = IsBalance(root->right);
	if (isBalance == 0) 
	{
		return 0;
	}

	int leftHeight = get_height(root->left);
	int rightHeight = get_height(root->right);
	int diff = leftHeight - rightHeight;
	if (diff < -1 || diff > 1) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

int IsBalance2(BNode *root, int *pHeight)
{
	if (root == NULL) {
		// return �߶�ֵ
		*pHeight = 0;
		return 1;
	}

	int leftHeight;
	int rightHeight;
	int leftBalance = IsBalance2(root->left, &leftHeight);
	int rightBalance = IsBalance2(root->right, &rightHeight);
	// return �߶�ֵ
	*pHeight = MAX(leftHeight, rightHeight) + 1;

	if (leftBalance == 0 || rightBalance == 0) {
		return 0;
	}

	int diff = leftHeight - rightHeight;
	if (diff < -1 || diff > 1) {
		return 0;
	}
	else {
		return 1;
	}
}


int MAX3(int a, int b, int c)
{
	if (a >= b && a >= c) {
		return a;
	}

	if (b >= a && b >= c) {
		return b;
	}

	return c;
}

int GetFarrestDistance(BNode *root)
{
	if (root == NULL) {
		return 0;
	}

	int leftDistance = GetFarrestDistance(root->left);
	int rightDistance = GetFarrestDistance(root->right);

	int leftHeight = get_height(root->left);
	int rightHeight = get_height(root->right);
	int rootDistance = leftHeight + rightHeight;

	return MAX3(leftDistance, rightDistance, rootDistance);
}




void test()
{
	RESULT result;
	TDataType preorder[] = { 1, 2, 4, -1, 6, -1, -1, -1, 3, -1, 5, -1, -1 };
	int size = sizeof(preorder) / sizeof(preorder[0]);
	result = create_tree(preorder, size);
	BNode* root = result.root;

	printf("�ڵ������%d\n", get_size(root));
	printf("�߶ȣ�%d\n", get_height(root));
	printf("Ҷ�Ӹ�����%d\n", get_leaf_size(root));
	printf("��k��ڵ������%d\n", get_k_level_size(root, 3));
	printf("����F��%d\n", Search(root, 6)->data);
	

	Preorder(root);printf("\n");
	pre_order_loop(root); printf("\n");
	Inorder(root);printf("\n");
	in_order_loop(root); printf("\n");
	Postorder(root);printf("\n");
	post_order_loop(root); printf("\n");
	level_order(root);printf("\n");

	printf("%d\n", is_not_complete_binary_tree(root));

	Mirror(root);
	MirrorLoop(root);
	//�Ҹ�ĸ�ڵ�
	BNode* child = Search(root,5);
	BNode* parent = get_parent(root, child);
	printf("%d\n", parent->data);
	//����
	parent = Search(root, 1);
	BNode* leftchild = get_left_child(root, parent);
	printf("%d\n", leftchild->data);
	//�Һ���
	parent = Search(root,4);
	BNode* rightchild = get_right_child(root, parent);
	printf("%d\n", rightchild->data);

	//����
	BNode* pre_order[] = { 1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, 12, -1, -1, 7 ,-1,-1};
	int sz = sizeof(pre_order) / sizeof(int);
	RESULT tree = create_tree(pre_order,sz);
	BNode* ancestor = get_nearest_ancestor(tree.root, 9, 10);
	printf("%d\n", ancestor->data);

	//ƽ��
	int height;
	printf("�Ƿ�Ϊƽ���������%d\n", IsBalance(root));
	printf("�Ƿ�Ϊƽ���������%d\n", IsBalance2(tree.root,&height));
	//
	printf("��Զ�ľ��룺%d\n", GetFarrestDistance(root));
}


BNode * CreateTree2(TDataType preorder[], TDataType inorder[], int size)
{
	if (size <= 0) {
		return NULL;
	}

	TDataType rootValue = preorder[0];
	int i;
	int r = 0;
	for (i = 0; i < size; i++) {
		if (inorder[i] == rootValue) {
			r = i; break;
		}
	}
	BNode *root = create_BNode(rootValue);
	root->left = CreateTree2(preorder + 1, inorder, r);
	root->right = CreateTree2(preorder + 1 + r, inorder + r + 1, size - 1 - r);

	return root;
}

BNode * CreateTree3(TDataType postorder[], TDataType inorder[], int size)
{
	if (size <= 0) {
		return NULL;
	}

	TDataType rootValue = postorder[size-1];
	int i;
	int r = 0;
	for (i = 0; i < size; i++) {
		if (inorder[i] == rootValue) {
			r = i; break;
		}
	}
	
	BNode *root = create_BNode(rootValue);
	root->left = CreateTree2(postorder, inorder, r);
	root->right = CreateTree2(postorder+ r, inorder + r + 1, size - 1 - r);

	return root;
}


void test2()
{
	int preoder[] = { 1, 2, 3, 4, 5, 6, 7 };
	int inorder[] = { 3, 2, 4, 1, 6, 7, 5 };
	int posorder[] = { 3, 4, 2, 7, 6, 5, 1 };
	int size = sizeof(preoder) / sizeof(int);
	BNode*tree2 = CreateTree2(preoder, inorder, size);
	BNode*tree3 = CreateTree3(posorder, inorder, size);
}