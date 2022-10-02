#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct lisnode {
	element data;
	struct listnode *link;
} listnode;

//리스트의 항목 출력
void print_list(listnode *head)
{
	listnode *p;

	if(head == NULL)
		return;
	p = head -> link;
	do {
		printf("%d -> ", p -> data);
		p = p -> link;
	} while (p != head);
	printf("%d -> ", p -> data);	//마지막 노드 출력
}

listnode *insert_first(listnode *head, element data)
{
	listnode *node = (listnode *)malloc(sizeof(listnode));
	node -> data = data;
	if(head == NULL)
	{
		head = node;
		node -> link = head;
	}
	else
	{
		node -> link = head -> link;
		head -> link = node;
	}
	return head; //변경된 헤드 반환한다.
}

listnode *insert_last(listnode *head, element data)
{
	listnode *node = (listnode *)malloc(sizeof(listnode));
	node -> data = data;
	if(head == NULL)
	{
		head = node;
		node -> link = head;
	}
	else
	{
		node -> link = head -> link;
		head -> link = node;
		head = node;
	}
	return head;
}

int main()
{
	listnode *head = NULL;

	//list = 10 -> 20 -> 30 -> 40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}