#include <stdio.h>

int main()
{
	int n, k = 0;
	int x[50] = { 0 };
	int y[50] = { 0 };

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for(int i = 0; i < n; i++)
	{
		k = 0;
		for(int j = 0; j < n; j++)
		{
			if(x[i] < x[j] && y[i] < y[j])
				k++;
		}
		printf("%d ", k + 1);
	}
	return 0;
}