#include <stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int tmp = i;
		int num = i;

		while(tmp > 0)
		{
			num += tmp % 10;
			tmp /= 10;
		}
		if(num == n)
		{
			printf("%d", i);
			n = 0;
			break;
		}
	}
	if(n != 0)
		printf("0");
}