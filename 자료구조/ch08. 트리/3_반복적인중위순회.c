#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

#define SIZE 100
int top = -1;
treenode *stack[SIZE];

void push(treenode *p)
{
	if(top < SIZE - 1)
		stack[++top] = p;
}

treenode *pop()
{
	treenode *p = NULL;
	if(top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(treenode *root)
{
	while(1)
	{
		for (; root; root = root -> left)
			push(root);
		root = pop();
		if(!root)
			break;
		printf("[%d] ", root -> data);
		root = root -> right;
	}
}

treenode n1 = {1, NULL, NULL};
treenode n2 = {4, &n1, NULL};
treenode n3 = {16, NULL, NULL};
treenode n4 = {25, NULL, NULL};
treenode n5 = {20 , &n3, &n4};
treenode n6 = {15, &n2, &n5};
treenode *root = &n6;

int main()
{
	printf("middle order = ");
	inorder_iter(root);
	printf("\n");
	return 0;
}