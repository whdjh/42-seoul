#include <stdio.h>

int main()
{
    int c = 0, n = 0;
    
    scanf("%d", &c);
    for(int i = 0; i < c; i++)
    {
        scanf("%d", &n);
        int str[1000];
        int sum = 0;
        double avg = 0.000;
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &str[j]);
            sum += str[j];
        }
        avg = (double)sum / n;
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(avg < str[j])
                count++;
        }
        printf("%.3f%%\n", (double)count / n * 100 );
    }
    return 0;
}