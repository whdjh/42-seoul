#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int x_;		//압축
	int compress;
}	point;

int compare_x(const void *a, const void *b)
{
	point A = *(point *)a;
	point B = *(point *)b;
	
	if(A.x < B.x)
		return -1;
	else if(A.x > B.x)
		return 1;
	else
		return 0;
}

int compare_x_(const void *a, const void *b)
{
	point A = *(point *)a;
	point B = *(point *)b;

	if(A.compress < B.compress)
		return -1;
	else if(A.compress > B.compress)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	point points[1000020];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &points[i].x);
		points[i].compress = i;
	}

	qsort(points, n, sizeof(point), compare_x);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
			points[i].x_ = 0;
		else
		{
			if(points[i - 1].x == points[i].x)
				points[i].x_ = points[i - 1].x_;
			else
				points[i].x_ = points[i - 1].x_ + 1;
		}
	}
	qsort(points, n, sizeof(point), compare_x_);
	for(int i = 0; i < n; i++)
		printf("%d ", points[i].x_);
	printf("\n");
}