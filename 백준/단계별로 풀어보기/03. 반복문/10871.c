#include <stdio.h>

int main()
{
    int n, x, input;

    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d\n", &input);
        if(x > input)
            printf("%d ", input);
    }
    return 0;
}