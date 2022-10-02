#include <stdio.h>

int main()
{
    int m, n, min, flag, sum = 0;
    
    scanf("%d\n%d", &m, &n);
    for(int i = m; i <= n; i++)
    {
        flag = 0;
        if(i == 1)
            continue;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
                flag =1;
        }
        if(flag == 0)
        {
            if(sum == 0)
                min = i;
            sum += i;
        }
    }
    if(sum == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);
    return 0;
}