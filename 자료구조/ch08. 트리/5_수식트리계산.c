#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

treenode n1 = {1, NULL, NULL};
treenode n2 = {4, NULL, NULL};
treenode n3 = {'*', &n1, &n2};
treenode n4 = {16, NULL, NULL};
treenode n5 = {25, NULL, NULL};
treenode n6 = {'+', &n4, &n5};
treenode n7 = {'+', &n3, &n6};
treenode *exp = &n7;

int evaluate(treenode *root)
{
	if(root == NULL)
		return 0;
	if(root -> left == NULL && root -> right == NULL)
		return root -> data;
	else
	{
		int op1 = evaluate(root -> left);
		int op2 = evaluate(root -> right);
		printf("%d %c %d을 계산합니다.\n", op1, root -> data, op2);
		switch(root -> data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

int main()
{
	printf("수식의 값은 %d입니다. \n", evaluate(exp));
	return 0;
}