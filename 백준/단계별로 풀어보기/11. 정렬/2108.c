#include <stdio.h>
#include <stdlib.h>
#include <math.h> //cell(double x) 올림, round(double x) 반올림, floor(double x) 내림

int compare(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;
	if(n1 < n2)
		return -1;
	else if(n1 > n2)
		return 1;
	else
		return 0;
}

int arith(int list[], int n)
{
	double sum = 0;

	for(int i = 0; i < n; i++)
		sum += (list[i]);
	return round(sum / n);
}

int median(int list[], int n)
{
	if(n == 1)
		return list[0];
	else
		return list[((n + 1) / 2) - 1];
}

//최빈값
int mode(int list[], int n)
{
	int arr[8001] = { 0 };
	int idx, max = 0, cnt = 0;

	for(int i = 0; i < n; i++)
	{
		idx = list[i] + 4000;
		arr[idx] += 1;
		if(arr[idx] > max)
			max = arr[idx];
	}
	idx = 0;
	for(int i = 0; i < 8001; i++)
	{
		if(arr[i] == 0)
			continue;
		if(arr[i] == max)
		{
			if(cnt == 0)
			{
				idx = i;
				cnt += 1;
			}
			else if(cnt == 1)
			{
				idx = i;
				break;
			}
		}
	}
	return (idx - 4000);
}

int range(int list[], int n)
{
	int max = list[n - 1];
	int min = list[0];

	return (max - min);
}

int main()
{
	int n, *list;

	scanf("%d", &n);

	list = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	qsort(list, n, sizeof(list[0]), compare);

	printf("%d\n", arith(list, n));
	printf("%d\n", median(list, n));
	printf("%d\n", mode(list, n));
	printf("%d\n", range(list, n));\
	return 0;
	
}