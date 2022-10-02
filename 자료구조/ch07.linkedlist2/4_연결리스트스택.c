#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stacknode {
	element data;
	struct stacknode *link;
} stacknode;

typedef struct {
	stacknode *top;
} linkedstactnode;

void init(linkedstactnode *s)
{
	s -> top = NULL;
}

int is_empty(linkedstactnode *s)
{
	return (s -> top == NULL);
}

int is_full(linkedstactnode *s)
{
	return 0;
}

void push(linkedstactnode *s, element item)
{
	stacknode *tmp = (stacknode *)malloc(sizeof(stacknode));
	tmp -> data = item;
	tmp -> link = s -> top;
	s -> top = tmp;
}

void print_stack(linkedstactnode *s)
{
	for(stacknode *p = s -> top; p != NULL; p = p -> link)
		printf("%d -> ", p -> data);
	printf("NULL \n");
}

element pop(linkedstactnode *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "empty!!\n");
		exit(1);
	}
	else
	{
		stacknode *tmp = s -> top;
		int data = tmp -> data;
		s -> top = s -> top -> link;
		free(tmp);
		return data;
	}
}

element peek(linkedstactnode *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "empty!!\n");
		exit(1);
	}
	else
		return (s -> top -> data);	
}

int main()
{
	linkedstactnode s;
	init(&s);
	push(&s, 1);
	print_stack(&s);
	push(&s, 2);
	print_stack(&s);
	push(&s, 3);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	return 0;
}