#include <stdio.h>
#include <string.h>

int main()
{
    char alp[100];
    int sum;
    
    scanf("%s", alp);
    sum = strlen(alp);
    for(int i = 0; i < strlen(alp); i++)
    {
        if((alp[i] == 'l' || alp[i] == 'n') && alp[i + 1] == 'j')
            sum--;
        if(alp[i] == 'd' && alp[i + 1] == 'z' && alp[i + 2] == '=')
            sum--;
        if(alp[i] == '=' || alp[i] == '-')
            sum--;
    }
    printf("%d", sum);
    return 0;
}