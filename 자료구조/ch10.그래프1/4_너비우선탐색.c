#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

//오류함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화함수
void init_queue(QueueType *q)
{
    q -> rear = 0;
    q -> front = 0;
}

//포화상태
int is_full(QueueType *q)
{
	return ((q -> rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

//빈상태
int is_empty(QueueType *q)
{
	return (q -> front == q -> rear);
}

//entry
void enqueue(QueueType *q, int item)
{
    if(is_full(q))
        error("full");
	q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    q -> data[(q -> rear)] = item;
}

//delete
int dequeue(QueueType *q)
{
    if(is_empty(q))
        error("empty");
    q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
	return q -> data[q -> front];
}

#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef struct graphtype {
	int n; 										//정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} graphtype;

void init_graph(graphtype *g)
{
	g -> n = 0;
	for(int r = 0; r < MAX_VERTICES; r++)
	{
		for(int c = 0; c < MAX_VERTICES; c++)
			g -> adj_mat[r][c] = 0;
	}
}

//정점 삽입 연산
void insert_vertex(graphtype *g, int v)
{
	if((g -> n) + 1 > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g -> n++;
}

//간섭 삽입 연산
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

//인접행렬버전
void bfs_mat(graphtype *g, int v)
{
	QueueType q;

	init_queue(&q);
	visited[v] = True;							//정점 v방문 표시
	printf("%d 방문 -> ", v);
	enqueue(&q, v);								//시작정점을 큐에 저장
	while(!is_empty(&q))
	{
		v = dequeue(&q);
		for(int w = 0; w < g -> n; w++)			//인접정점탐색
		{
			if(g -> adj_mat[v][w] && !visited[w])
			{
				visited[w] = True;				//방문표시
				printf("%d 방문 -> ", w);
				enqueue(&q, w);					//방문한 정점을 큐에 저장
			}
		}
	}
}

/*
//인접리스트버전
void bts_list(graphtype *g, int v)
{
	graphnode *w;
	QueueType q;

	init_queue(&q);
	visited[v] = Treu;											//정점 v방문 표시
	printf("%d 방문 -> ", v);
	enqueue(&q, v);												//시작정점을 큐에 저장
	while(!is_empty(&q))
	{
		v = dequeue(&q);
		for(int w = g -> adj_list[v]; w; w = w -> link)			//인접정점탐색
		{
			if(!visited[w -> vertex])
			{
				visited[w -> vertex] = True;					//방문표시
				printf("%d 방문 -> ", w -> vertex);
				enqueue(&q, w -> vertex);						//방문한 정점을 큐에 저장
			}
		}
	}
}
}*/

int main()
{
	graphtype *g;
	g = (graphtype *)malloc(sizeof(graphtype));
	init_graph(g);
	for(int i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("BFS\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}