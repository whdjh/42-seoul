#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

#define MAX_QUEUE_SIZE 100
typedef treenode *element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} queuetype;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(queuetype *q)
{
	q -> front = q -> rear = 0;
}

int is_empty(queuetype *q)
{
	return q -> front == q -> rear;
}

int is_full(queuetype *q)
{
	return ((q -> rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

void enqueue(queuetype *q, element item)
{
	if(is_full(q))
		error("full");
	q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
	q -> data[q -> rear] = item;
}

element dequeue(queuetype *q)
{
	if(is_empty(q))
		error("empty");
	q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
	return q -> data[q -> front];
}

void level_order(treenode *ptr)
{
	queuetype q;
	init_queue(&q);
	if(ptr == NULL)
		return;
	enqueue(&q, ptr);
	while(!is_empty(&q))
	{
		ptr = dequeue(&q);
		printf(" [%d] ", ptr -> data);
		if(ptr -> left)
			enqueue(&q, ptr -> left);
		if(ptr -> right)
			enqueue(&q, ptr -> right);
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
	printf("level order = ");
	level_order(root);
	printf("\n");
	return 0;
}