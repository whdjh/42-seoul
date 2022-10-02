#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} coord;

int compare(const void *a, const void *b)
{
	coord A = *(coord *)a;
	coord B = *(coord *)b;
	if(A.y > B.y)		//오름차순 정렬
		return 1;
	else if(A.y == B.y)
	{
		if(A.x > B.x)	//오름차순 정렬
			return 1;
		else
			return -1;
	}
	return -1; 			//A.y < B.y 일 경우		
}

int main()
{
	int test;

	scanf("%d", &test);
	coord *arr;

	arr = (coord *)malloc(sizeof(coord) * test);

	for(int i = 0; i < test; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	qsort(arr, test, sizeof(coord), compare);
	for(int i = 0; i < test; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	free(arr);
	return 0;
}