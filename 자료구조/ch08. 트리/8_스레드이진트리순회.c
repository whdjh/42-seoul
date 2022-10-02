#include <stdio.h>
#define true 1
#define false 0

typedef struct treenode {
	int data;
	struct treenode *left, *right;
	int is_thread; //만약 오른쪽 링크가 스레드이면 true
} treenode;

treenode n1 = {'A', NULL, NULL, 1};
treenode n2 = {'B', NULL, NULL, 1};
treenode n3 = {'C', &n1, &n2, 0};
treenode n4 = {'D', NULL, NULL, 1};
treenode n5 = {'E', NULL, NULL, 0};
treenode n6 = {'F', &n4, &n5, 0};
treenode n7 = {'G', &n3, &n6, 0};
treenode *exp = &n7;

treenode *find_successor(treenode *p)
{
	treenode *q = p -> right; //q는 p의 오른쪽 포인터
	if(q == NULL || p -> is_thread == true)
		 return q;
		while(q -> left != NULL) //만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
			q = q -> left;
		return q;
}

void thread_inorder(treenode *t)
{
	treenode *q;
	q = t;
	while(q -> left)					//가장 왼쪽 노드로 간다.
		q = q -> left;
	do {
		printf("%c -> ", q -> data);	//데이터 출력
		q = find_successor(q);			//후속자 함수 호출
	} while(q);							//NULL이 아니면!
}

int main()
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
	printf("\n");
	return 0;
}