#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a)

typedef struct avlnode {
	int key;
	struct avlnode *left, *right;
} avlnode;

int get_height(avlnode *node)
{
	int height = 0;
	if(node != NULL)
		height = 1 + MAX((get_height(node -> left)), get_height(node -> right));
	return height;
}

//균형인수
int get_balance(avlnode *node)
{
	if(node == NULL)
		return 0;
	return get_height(node -> left) - get_height(node -> right);		//균형인수를 구하는 공식
}

avlnode *create_node(int key)
{
	avlnode *node = (avlnode *)malloc(sizeof(avlnode));
	node -> key = key;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

//오른쩍으로 회전시키는 함수
avlnode *rotate_right(avlnode *parent)
{
	avlnode *child = parent -> left;
	parent -> left = child -> right;
	child -> right = parent;
	return child;
}

//왼쪽으로 회전시키는 함수
avlnode *rotate_left(avlnode *parent)
{
	avlnode *child = parent -> right;
	parent -> right = child -> left;
	child -> left = parent;
	return child;
}

//avl트리에서 새로운 노드 추가함수, 새로운 루트를 반환한다.
avlnode *insert(avlnode *node, int key)
{
	if(node == NULL)									//이진탐색트리의 노드 추가 수행
		return create_node(key);
	if(key < node -> key)
		node -> left = insert(node -> left, key);
	else if(key > node -> key)
		node -> right = insert(node -> right, key);
	else												//동일한 키는 허용되지 않음
		return node;

	int balance = get_balance(node);					//노드들의 균형인수 재계산

	if(balance > 1 && key > node -> left -> key)		//LL(왼쪽자식의 왼쪽노드 추가!, 우회전)
		return rotate_right(node);
	if(balance < -1 && key > node -> right -> key)		//RR(오른쪽자식의 오른쪽노드 추가!, 좌회전)
		return rotate_left(node);
	if(balance > 1 && key > node -> left -> key)		//LR(왼쪽자식의 오른쪽노드 추가!, 좌회전후우회전)
	{
		node -> left = rotate_left(node -> left);
		return rotate_right(node);
	}
	if(balance < -1 && key > node -> right -> key)		//RL(오른쪽식의 왼쪽노드 추가!, 우회전후좌회전)
	{
		node -> right = rotate_right(node -> right);
		return rotate_left(node);
	}
	return node;
}

void preorder(avlnode *root)
{
	if(root != NULL)
	{
		printf("[%d] ", root -> key);
		preorder(root -> left);
		preorder(root -> right);
	}
}

int main()
{
	avlnode *root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);
	printf("preorder result \n");
	preorder(root);
	return 0;
}