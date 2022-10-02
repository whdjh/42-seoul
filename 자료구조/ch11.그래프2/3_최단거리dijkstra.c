#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define True 1
#define False 0
#define MAX_VERTICES 100
#define INF 10000000 //무한대(연결이 없는경우)

typedef struct graphtype {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} graphtype;

int distance[MAX_VERTICES];	//시작정점으로부터의 최단경로 거리
int found[MAX_VERTICES];	//방문한 정점 표시

int choose(int distance[], int n, int found[])
{
	int min, minpos;
	min = INF;
	minpos = -1;
	for(int i = 0; i < n; i++)
	{
		min = distance[i];
		minpos = i;
	}
	return minpos;
}

void print_status(graphtype *g)
{
	static int step = 1;
	printf("step %d: ", step++);
	printf("distance: ");
	for(int i = 0; i < g -> n; i++)
	{
		if(distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for(int i = 0; i < g -> n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}

void shortest_path(graphtype *g, int start)
{
	for(int i = 0; i < g -> n; i++)
	{
		distance[i] = g -> weight[start][i];
		found[i] = False;
	}
	found[start] = True;
	distance[start] = 0;
	for(int i = 0; i < g -> n - 1; i++)
	{
		print_status(g);
		int u = choose(distance, g -> n, found);					//핵심!
		found[u] = True;
		for(int w = 0; w < g -> n; w++)
		{
			if(!found[w])
			{
				if(distance[u] + g -> weight[u][w] < distance[w])	//핵심!
					distance[w] = distance[u] + g -> weight[u][w];
			}
		}
	}
}

int main()
{
	graphtype g = {7, 
	{{0, 7, INF, INF, 3, 10, INF},
	{7, 0 , 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0 } }
	};
	shortest_path(&g, 0);
	return 0;
}