#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000001];
    int alp[26];
    int m = 0;
    char c = '?';
    
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a')
            str[i] -= 32;
        alp[str[i] - 65]++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(m < alp[i])
        {
            m = alp[i];
            c = i;
        }
        else if(m == alp[i])
            c = '?';
    }
    if(c != '?')
        printf("%c", 65 + c);
    else
        printf("?");
    return 0;
}