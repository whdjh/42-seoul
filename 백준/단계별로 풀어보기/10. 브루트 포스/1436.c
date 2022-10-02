#include <stdio.h>
#include <math.h> //pow(double base, double n) base^n 의 형태! 

int main()
{
	int num = 665; //시작이 666이니까 665부터 시작 시킬래~
	int n, a = 0;

	scanf("%d", &n);
	while(1)
	{
		if(a == n)
		{
			printf("%d", num);
			break;
		}
		num++;
		for(int i = 0; i <= 10; i++)
		{
			if(num / (int)pow(10, i) % 1000 == 666) //가나다라마 이렇게 있을때, i가 0일때는 다라마 % 1000, i가 1일때 나다라 % 1000
			{
				a++;
				break;
			}
		}
	}
	
}