#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct listnode {
	element data;
	struct listnode *link;
} listnode;

listnode *insert_first(listnode *head, element data)
{
	listnode *node = (listnode *)malloc(sizeof(listnode));
	strcpy(node -> data, data);
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

int main()
{
	listnode *head = NULL;

	head = insert_first(head, "kim");
	head = insert_first(head, "park");
	head = insert_first(head, "lee");

	listnode *p = head;
	for(int i = 0; i < 10; i++)
	{
		printf("who turn = %s \n", p -> data);
		p = p -> link;
	}
	return 0;
}