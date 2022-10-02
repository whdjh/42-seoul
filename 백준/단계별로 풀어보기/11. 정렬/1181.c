#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int len;
	char str[51];
} word;

int compare(const void *a, const void *b)
{
	word A = *(word *)a;
	word B = *(word *)b;

	if(A.len < B.len)
		return -1;
	else if(A.len > B.len)
		return 1;
	else if(A.len == B.len)
	{
		if(strcmp(A.str, B.str) < 0)
			return -1;
		else
			return 1;
	} 
	return 0;
}

int main()
{
	int n;
	word *text;

	scanf("%d", &n);

	text = (word *)calloc(n + 1, sizeof(word));

	for(int i = 0; i < n; i++)
	{
		scanf(" %s", text[i].str);
		text[i].len = strlen(text[i].str);
		for(int j = 0; j < i; j++)
		{
			if(strcmp(text[i].str, text[j].str) == 0)	//중복사항제거
			{
				i -= 1;
				n -= 1;
				break;
			}
		}
	}
	qsort(text, n, sizeof(word), compare);
	for(int i = 0; i < n; i++)
		printf("%s\n", text[i].str);
	free(text);
	return 0;
}
