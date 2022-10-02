#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

int main()
{
	treenode *n1, *n2, *n3;
	n1 = (treenode *)malloc(sizeof(treenode));
	n2 = (treenode *)malloc(sizeof(treenode));
	n3 = (treenode *)malloc(sizeof(treenode));

	//첫번째 노드 생성
	n1 -> data = 10;
	n1 -> left = n2;
	n1 -> right = n3;

	//두번째 노드 생성
	n2 -> data = 20;
	n2 -> left = NULL;
	n2 -> right = NULL;

	//세번째 노드 생성
	n3 -> data = 30;
	n3 -> left = NULL;
	n3 -> right = NULL;

	free(n1);
	free(n2);
	free(n3);
	
	return 0;
}
