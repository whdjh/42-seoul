#include <stdio.h>

int main()
{
    int a, n = 1;
    
    scanf("%d", &a);
    while (n < 10)
    {
        printf("%d * %d = %d\n", a, n, a * n);
        n++;
    }
    return 0;
}