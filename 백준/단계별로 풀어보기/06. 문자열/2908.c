#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[4], str2[4], swap1, swap2;
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    swap1 = str1[0];
    str1[0]= str1[2];
    str1[2] = swap1;
    
    swap2 = str2[0];
    str2[0]= str2[2];
    str2[2] = swap2;
    if (strcmp(str1, str2) > 0)
        printf("%s", str1);
    else
        printf("%s", str2);
    return 0;
}