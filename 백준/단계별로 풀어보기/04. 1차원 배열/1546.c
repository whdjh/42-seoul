#include <stdio.h>

int main()
{
    int m, str[m], max = 0;
    double avg = 0;
    
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &str[i]);
        if(max < str[i])
            max = str[i];
    }
    for(int i = 0; i < m; i++)
        avg += (double)str[i] / max * 100;
    printf("%f\n", avg / m);
    return 0;
}