#include <stdio.h>

int main()
{
    int n, str[n];
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &str[i]);
    int min = str[0], max = str[0];
    for(int j = 0; j < n; j++)
    {
        if(str[j] < min)
            min = str[j];
        if(str[j] > max)
            max = str[j];
    }
    printf("%d %d", min, max);
    return 0;
}