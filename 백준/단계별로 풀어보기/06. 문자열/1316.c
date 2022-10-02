#include <stdio.h>
#include <string.h>

int main()
{
    int n, count = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char word[101];
        
        scanf("%s", word);      
        int alp[26];
        for(int j = 0; j < 26; j++)
            alp[j] = 0;
        int len = strlen(word);
        for(int k = 0; k < len; k++)
        {
            char letter = word[k];
            if(alp[letter - 'a'] == 0)
                alp[letter - 'a'] = 1;
            else
            {
                if(word[k - 1] != word[k])
                    break;
            }
            if(k == len - 1)
                count++;
        }
    }
    printf("%d\n", count);
    return 0;
}