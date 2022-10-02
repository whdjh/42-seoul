#include <stdio.h>

int main()
{
    int a, b, c, num;
    int str[10] = {0, };
    
    scanf("%d %d %d", &a, &b, &c);
    int n = a * b * c;
    
    while (n > 0)
    {
        num = n % 10;
        str[num]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++)
        printf("%d\n", str[i]);
    return 0;
}