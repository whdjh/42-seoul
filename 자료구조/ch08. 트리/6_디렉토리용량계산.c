#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

int calc_dir_size(treenode *root)
{
	int left_size, right_size;
	if(root == NULL)
		return 0;
	left_size = calc_dir_size(root -> left);
	right_size = calc_dir_size(root -> right);
	return (root -> data + left_size + right_size);
}

int main()
{
	treenode n4 = {500, NULL, NULL};
	treenode n5 = {200, NULL, NULL};
	treenode n3 = {100, &n4, &n5};
	treenode n2 = {50, NULL, NULL};
	treenode n1 = {0, &n2, &n3};

	printf("디렉토리의 크기 = %d\n", calc_dir_size(&n1));
}