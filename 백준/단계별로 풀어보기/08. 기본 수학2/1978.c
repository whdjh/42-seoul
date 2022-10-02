#include <stdio.h>

int main()
{
	int i, j, n, num, cnt;

	scanf("%d", &n);
	for (i = 0, cnt = 0; i < n; i++)
	{
		scanf(" %d", &num);

		for (j = 2; j < num; j++)
		{
			if (num % j == 0)
				break;
		}
		if (j == num)
			cnt += 1;
	}
	printf("%d\n", cnt);
	return 0;
}