#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_VERITICES 50

typedef struct graphtype {
	int n;
	int adj_mat[MAX_VERITICES][MAX_VERITICES];
} graphtype;

int visited[MAX_VERITICES];

void init_graph(graphtype *g)
{
	g -> n = 0;
	for(int r = 0; r < MAX_VERITICES; r++)
	{
		for(int c = 0; c < MAX_VERITICES; c++)
			g -> adj_mat[r][c] = 0;
	}
}

//정점 삽입 연산
void insert_vertex(graphtype *g, int v)
{
	if(((g -> n) + 1) > MAX_VERITICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g -> n++;
}

//간선 삽입 연산
void insert_edge(graphtype *g, int start, int end)
{
	if(start >= g -> n || end >= g -> n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g -> adj_mat[start][end] = 1;
	g -> adj_mat[end][start] = 1;
}

//인접 행렬로 표현된 그래프에 대한 깊이우선탐색
void dfs_mat(graphtype *g, int v)
{
	visited[v] = True;					//방문표시
	printf("정점 %d -> ", v);			 //방문한 정점 출력
	for(int w = 0; w < g -> n; w++)		//인접정점 탐색
	{
		if(g -> adj_mat[v][w] && !visited[w])
			dfs_mat(g, w);				//정점 w에서 DFS 새로 시작
	}
}

/*인접리스트로 표현된 그래프에 대한 깊이우선탐색
void dfs_list(graphtype *g, int v)
{
	graphnode *n;
	visited[v] = True;								   //방문표시
	printf("정점 %d -> ", v);			 				//방문한 정점 출력
	for(int w = g -> adj_list[v]; w; w = w -> link)	   //인접정점 탐색
	{
		if(!visited[w -> vertex])
			dfs_list(g, w -> vertex);					//정점 w에서 DFS 새로 시작
	}
}
*/

int main()
{
	graphtype *g;
	g = (graphtype *)malloc(sizeof(graphtype));
	init_graph(g);
	for(int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("DFS\n");
	dfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}