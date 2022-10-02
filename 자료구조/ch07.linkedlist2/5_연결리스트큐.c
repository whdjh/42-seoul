#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct queuenode {
	element data;
	struct queuenode *link;
} queuenode;

typedef struct {
	queuenode *front, *rear;
} linkedqueuenode;

void init(linkedqueuenode *q)
{
	q -> front = q -> rear = 0;
}

int is_empty(linkedqueuenode *q)
{
	return (q -> front == NULL);
}

int is_full(linkedqueuenode *q)
{
	return 0;
}

void enqueue(linkedqueuenode *q, element data)
{
	queuenode *tmp = (queuenode *)malloc(sizeof(queuenode));
	tmp -> data = data;				//데이터 저장
	tmp -> link = NULL;				//링크 필드를 NULL
	if(is_empty(q))					//큐가 공백
	{
		q -> front = tmp;
		q -> rear = tmp;
	}
	else							//큐가 공백이 아님
	{
		q -> rear -> link = tmp;	//****순서 중요****
		q -> rear = tmp;
	}
}

element dequeue(linkedqueuenode *q)
{
	queuenode *tmp = q -> front;
	element data;
	if(is_empty(q))
	{
		fprintf(stderr, "empty!!\n");
		exit(1);
	}
	else
	{
		data = tmp -> data;					//데이터를 꺼낸다
		q -> front = q -> front -> link;	//front를 다음 노드를 가르키게 한다.
		if(q -> front == NULL)				//공백상태
			q -> rear = NULL;
		free(tmp);
		return data;
	}
}

void print_queue(linkedqueuenode *q)
{
	queuenode *p;
	for(p = q -> front; p != NULL; p = p -> link)
		printf("%d -> ", p -> data);
	printf("NULL\n");
}

int main()
{
	linkedqueuenode queue;

	init(&queue);

	enqueue(&queue, 1);
	print_queue(&queue);
	enqueue(&queue, 2);
	print_queue(&queue);
	enqueue(&queue, 3);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	return 0;
}