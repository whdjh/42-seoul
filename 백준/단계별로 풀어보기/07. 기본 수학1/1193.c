#include <stdio.h>

int main() 
{
	int input, k = 1;
    
	scanf("%d", &input);  
	while (1)
	{		
		if ((k - 1) * k / 2 < input && input <= k * (k + 1) / 2)
			break;
		k++;
	}

	if (k % 2 != 0)
	{
		int a = k * (k + 1) / 2;
		printf("%d/%d", a - input + 1, k -(a - input));
	}
	else 
	{
		int a = k * (k + 1) / 2;
		printf("%d/%d",k - (a - input), a - input + 1);
	}
	return 0;
}
