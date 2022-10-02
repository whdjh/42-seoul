#include <stdio.h>

int hansu(int n)
{
    int count = 0;
    int a, b, c;
    
    if(n < 100)
        return n;
    else
    {
        for(int i = 100; i <= n; i++)
        {
            a = i / 100;
            b = i % 100 / 10;
            c = i % 100 % 10;
            if((a - b) == (b - c))
                count++;
        }
     return (99 + count);
    }
}

int main()
{
    int input, result;
    
    scanf("%d", &input);
    result = hansu(input);
    printf("%d", result);
    return 0;
}