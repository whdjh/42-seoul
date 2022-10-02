#include <stdio.h>
#include <string.h>

int main()
{
    int t, sum, add;
    char str[81];
    
    scanf("%d\n", &t);
    for(int i = 0; i < t; i++)
    {
        sum = 0; add = 1;
        scanf("%s", str);
        for(int j = 0; j < strlen(str); j++)
        {
            if(str[j] == 'O')
            {
                sum += add;
                add++;
            }
            else
                add = 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}