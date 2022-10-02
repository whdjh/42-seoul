#include <stdio.h>

int main()
{
    int str[9], count, x =0;

    for(int i = 1; i < 10; i++)
    {
        scanf("%d\n", &str[i]);
        if(x < str[i])
        {
            x = str[i];
            count = i;
        }
    }
    printf("%d\n%d", x, count);
    return 0;
}