#include <stdio.h>
#include <string.h>

int main() 
{
    char input[1000001];
    
    scanf("%[^\n]", input);
    int len = strlen(input), count=0;
    if(len == 1 && input[0] == ' ')
    {
        printf("0");
        return 0;
    }
    for(int i=1; i<len-1; i++)
    {
        if(input[i] == ' ')
            count++;
    }
    printf("%d", count+1);
    return 0;
}