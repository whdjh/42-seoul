#include <stdio.h>
#include <string.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int main()
{
	char n[10];
	char tmp;

	scanf("%s", n);
	for(int i = 0; i < strlen(n) - 1; i++)
	{
		for(int j = 0; j < strlen(n); j++)
		{
			if(n[j] < n[j + 1])
				SWAP(n[j], n[j + 1], tmp);
		}
	}
	printf("%s", n);
	return 0;
}