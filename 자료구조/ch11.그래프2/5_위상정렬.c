#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_VERTICES 100

typedef struct graphnode {
	int vertex;
	struct graphnode *link;
} graphnode;

typedef struct graphtype {
	int n;
	graphnode *adj_list[MAX_VERTICES];
} graphtype;

void init_graph(graphtype *g)
{
	g -> n = 0;
	for(int v = 0; v < MAX_VERTICES; v++)
		g -> adj_list[v] = NULL;
}

//정점 삽입 연산
void insert_vertex(graphtype *g, int v)
{
	if(((g -> n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g -> n++;
}

//간선 삽입 연산, v를 u의 인접리스트에 삽입한다. 정점 u에 간선 (u, v)를 삽입하는 연산은 정점 u의 인접리스트에 간선을 나타내는 노드를 하나 생성하여 삽입하면 된다. 위치는 상관이 없으므로 삽입을 쉽게 하기 위하여 연결리스트의 맨처음에 삽입할것!
void insert_edge(graphtype *g, int u, int v)
{
	graphnode *node;
	if(u >= g -> n || v >= g -> n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (graphnode *)malloc(sizeof(graphnode));
	node -> vertex = v;
	node -> link = g -> adj_list[u];
	g -> adj_list[u] = node;
}

#define MAX_STACK_SIZE 100       //스택의 최대 크기

typedef int element;             //데이터의 자료형

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType *s)
{
    s -> top = -1;
}

//공백
int is_empty(StackType *s)
{
    return (s -> top == -1);
}

//포화
int is_full(StackType *s)
{
    return (s -> top == (MAX_STACK_SIZE - 1));
}

//삽입
void push(StackType *s, element item)
{
    if(is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
		return;
    }
    else
        s -> data[++(s -> top)] = item;
}

//삭제
element pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return (s -> data[(s -> top)--]);
}

//위상정렬을 수행한다.
int topo_sort(graphtype *g)
{
	StackType s;
	graphnode *node;
	int i;

	//모든 정점의 진입 차수를 계산
	int *in_degree = (int *)malloc(g -> n * sizeof(int));
	for(int i = 0; i < g -> n; i++)
		in_degree[i] = 0;
	for(int i = 0; i < g -> n; i++)
	{
		graphnode *node = g ->adj_list[i];	//정점 i에서 나오는 간선들
		while(node != NULL)
		{
			in_degree[node -> vertex]++;
			node = node -> link;
		}
	}
	//진입 차수가 0인 정점을 스택에 삽입
	init_stack(&s);
	for(int i = 0; i < g -> n; i++)
	{
		if(in_degree[i] == 0)
			push(&s, i);
	}
	//위상 순서를 생성
	while(!is_empty(&s))
	{
		int w = pop(&s);
		printf("정점 %d ->", w);			//정점 출력
		node = g -> adj_list[w];		   //각 정점의 진입 차수를 변경
		while(node != NULL)
		{
			int u = node -> vertex;
			in_degree[u]--;				   //집입차수감소
			if(in_degree[u] == 0)
				push(&s, u);
			node = node -> link;		   //다음 정점
		}
	}
	free(in_degree);
	printf("\n");
	return i == g -> n;					   //반환값이 1이면 성공, 0이면 실패
}

int main()
{
	graphtype g;

	init_graph(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 3, 5);
	insert_edge(&g, 4, 5);
	topo_sort(&g);
	return 0;
}