#include <stdio.h>

int self_num(int n)
{
    int sum = n;

    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int str[10001];
    int result = 0;
    
    for(int i = 0; i < 10001; i++)
    {
        result = self_num(i);
        if(result < 10001)
            str[result] = 1;
    }
    for(int j = 0; j < 10001; j++)
    {
        if(str[j] != 1)
            printf("%d\n", j);
    }
    return 0;
}