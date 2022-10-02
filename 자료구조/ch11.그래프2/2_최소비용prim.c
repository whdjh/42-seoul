//비교후 최소값들끼리 더해서 정렬
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_VERTICES 100
#define INF 1000L //무한대(연결이 없는경우)

typedef struct graphtype {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} graphtype;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//최소 dist[v]값을 찾는 정점을 반환
int get_min_vertex(int n)
{
	int v;
	for(int i = 0; i < n; i++)
	{
		if(!selected[i])
		{
			v = i;
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!selected[i] && (distance[i] < distance[v]))
			v = i;
	}
	return v;
}

void prim(graphtype *g, int s)
{
	for(int u = 0; u < g -> n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for(int i = 0; i < g -> n; i++)
	{
		int u = get_min_vertex(g -> n);
		selected[u] = True;
		if(distance[u] == INF)
			return;
		printf("정점 %d 추가\n", u);
		for(int v = 0; v < g -> n; v++)
		{
			if(g -> weight[u][v] != INF)
			{
				if(!selected[v] && g -> weight[u][v] < distance[v])
					distance[v] = g -> weight[u][v];
			}
		}
	}
}

int main()
{
	graphtype g = {7, 
	{{0, 29, INF, INF, INF, 10, INF},
	{29, 0 , 16, INF, INF, INF, 15},
	{INF, 16, 0, 12, INF, INF, INF},
	{INF, INF, 12, 0, 22, INF, 18},
	{INF, INF, INF, 22, 0, 27, 25},
	{10, INF, INF, INF, 27, 0, INF},
	{INF, 15, INF, 18, 25, INF, 0 } }
	};
	prim(&g, 0);
	return 0;
}