#include <stdio.h>

int main()
{
	int N, C, i, j;
	int not_prime[10001] = {0, };
	
	for(i = 2; i * i < 10001; i++)
    {
		if(!not_prime[i])
			for(j = i * i; j < 10001; j += i)
				not_prime[j] = 1;
    }	
	scanf("%d", &C);
	while(C--)
	{
		scanf("%d", &N);
		
		for(i = N / 2; i >= 2; i--)
        {
			if(!not_prime[i] && !not_prime[N-i])
			{
				printf("%d %d\n", i, N - i);
				break;
			}
        }
	}
	return 0;
}