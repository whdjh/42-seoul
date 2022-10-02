#include <stdio.h>

int main()
{
    int a, b, v;
    int count;
    
    scanf("%d %d %d", &a, &b, &v);
    count = (v - b - 1) / (a - b) + 1;
    printf("%d", count);
    return 0;
}