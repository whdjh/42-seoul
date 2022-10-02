#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct treenode {
	element key;
	struct treenode *left, *right;
} treenode;

treenode *search(treenode *node, int key)
{
	if(node == NULL)
		return NULL;
	if(key == node -> key)
		return node;
	else if(key < node -> key)
		return search(node -> left, key);
	else
		return search(node -> right, key);
}

treenode *new_node(int item)
{
	treenode *tmp = (treenode *)malloc(sizeof(treenode));
	tmp -> key = item;
	tmp -> left = tmp -> right = NULL;
	return tmp;
}

treenode *insert_node(treenode *node, int key)
{
	if(node ==NULL)
		return new_node(key);
	if(key < node -> key)
		node -> left = insert_node(node -> left, key);
	else if(key > node -> key)
		node -> right = insert_node(node -> right, key);
	return node;
}

treenode *min_value_node(treenode *node)
{
	treenode *current = node;
	while(current -> left != NULL)	//맨 왼쪽 단말 노드를 찾으러 내려감
		current = current -> left;
	return current;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.
treenode *delete_node(treenode *root, int key)
{
	if(root == NULL)
		return root;
	if(key < root -> key)											//만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것이다.
		root -> left = delete_node(root -> left, key);
	else if(key > root -> key) 										//만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것이다.
		root -> right = delete_node(root -> right, key);
	else															//키가 루트와 같으면 이 노드를 삭제해야 한다.
	{
		if(root -> left == NULL)									//첫번째나 두번째
		{
			treenode *tmp = root -> right;
			free(root);
			return tmp;
		}
		else if(root -> right == NULL)
		{
			treenode *tmp = root -> left;
			free(root);
			return tmp;
		}
		treenode *tmp = min_value_node(root -> right);				//세번째
		root -> key = tmp -> key;									//중위 순회시 후계 노드를 복사
		root -> right = delete_node(root -> right, tmp -> key);		//중위 순회시 후계 노드 삭제
	}
	return root;
}

//중위순회
void inorder(treenode *root)
{
	if(root)
	{
		inorder(root -> left);
		printf("[%d] ", root -> key);
		inorder(root -> right);
	}
}

int main()
{
	treenode *root = NULL;
	treenode *tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if(search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견! \n");
	else
		printf("이진 탐색트리에서 30을 발견못했어! \n");
	return 0;
}