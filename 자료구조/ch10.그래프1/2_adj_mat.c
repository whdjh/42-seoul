#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

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

void print_adj_list(graphtype *g)
{
	for(int i = 0; i < g -> n; i++)
	{
		graphnode *p = g -> adj_list[i];
		printf("정점 %d의 인접리스트 ", i);
		while(p != NULL)
		{
			printf("-> %d ", p -> vertex);
			p = p -> link;
		}
		printf("\n"); 
	}
}

int main()
{
	graphtype *g;
	g = (graphtype *)malloc(sizeof(graphtype));
	init_graph(g);
	for(int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	print_adj_list(g);
	free(g);
	return 0;
}