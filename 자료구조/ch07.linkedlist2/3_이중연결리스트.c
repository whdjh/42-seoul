#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dlistnode {
	element data;
	struct dlistnode *llink; //선행노드
	struct dlistnode *rlink; //후행노드
} dlistnode;

void init(dlistnode *phead)
{
	phead -> llink = phead;
	phead -> rlink = phead;
}

void print_dlist(dlistnode *phead)
{
	dlistnode *p;
	for(p = phead -> rlink; p != phead; p = p -> rlink)
		printf("<-| |%d| |-> ", p -> data);
	printf("\n");
}

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(dlistnode *before, element data)
{
	dlistnode *newnode = (dlistnode *)malloc(sizeof(dlistnode));
	newnode -> data = data;
	newnode -> llink = before;
	newnode -> rlink = before -> rlink;
	before -> rlink -> llink = newnode;
	before -> rlink = newnode;
}

//노드 removed를 삭제한다.
void ddelete(dlistnode *head, dlistnode *removed)
{
	if(removed == head)
		return;
	removed -> llink -> rlink =removed -> rlink;
	removed -> rlink -> llink =removed -> llink;
	free(removed);
}

int main()
{
	dlistnode *head = (dlistnode *)malloc(sizeof(dlistnode));
	init(head);
	printf("추가단계\n");
	for(int i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_dlist(head);
	}
	printf("삭제단계\n");
	for(int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head -> rlink);
	}
	free(head);
	return 0;
}