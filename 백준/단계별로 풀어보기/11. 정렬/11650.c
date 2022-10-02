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
	if(A.x > B.x)		//오름차순 정렬
		return 1;
	else if(A.x == B.x)
	{
		if(A.y > B.y)	//오름차순 정렬
			return 1;
		else
			return -1;
	}
	return -1; 			//A.x < B.x 일 경우		
}

int main()
{
	int n;
	
	scanf("%d", &n);
	coord arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);	//구조체 배열로 arr[0]의 x,y값을 각각 설정하면서 감
	qsort(arr, n, sizeof(coord), compare);
	for(int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}