#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;	
} treenode;

treenode n1 = {1, NULL, NULL};
treenode n2 = {4, &n1, NULL};
treenode n3 = {16, NULL, NULL};
treenode n4 = {25, NULL, NULL};
treenode n5 = {20, &n3, &n4};
treenode n6 = {15, &n2, &n5};
treenode *root = &n6;

//중위순회(LVR)
void inorder(treenode *root)
{
	if(root != NULL)
	{
		inorder(root -> left);				//왼쪽서브트리 순회
		printf("[%d] ", root -> data);		//노드 방문
		inorder(root -> right);				//오른쪽서브트리 순회
	}
}

//전위순회(VLR)
void preorder(treenode *root)
{
	if(root != NULL)
	{
		printf("[%d] ", root -> data);		//노드 방문
		preorder(root -> left);				//왼쪽서브트리 순회
		preorder(root -> right);			//오른쪽서브트리 순회
	}
}

//후위순회(LRV)
void postorder(treenode *root)
{
	if(root != NULL)
	{
		postorder(root -> left);			//왼쪽서브트리 순회
		postorder(root -> right);			//오른쪽서브트리 순회
		printf("[%d] ", root -> data);		//노드 방문
	}
}

int main()
{
	printf("중위 = ");
	inorder(root);
	printf("\n");

	printf("전위 = ");
	preorder(root);
	printf("\n");

	printf("후위 = ");
	postorder(root);
	printf("\n");
	return 0;	
}
