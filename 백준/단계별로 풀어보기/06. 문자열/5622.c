#include <stdio.h>
#include <string.h>

int main()
{
    char input[15];
    int sum = 0;
    int len = 0;
    
    scanf("%s", input);
    len = strlen(input);
    for (int i = 0; i < len; i++)
	{
		if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
			sum = sum + 3;
		if (input[i] == 'D' || input[i] == 'E' || input[i] == 'F')
			sum = sum + 4;
		if (input[i] == 'G' || input[i] == 'H' || input[i] == 'I')
            sum = sum + 5;
		if (input[i] == 'J' || input[i] == 'K' || input[i] == 'L')
			sum = sum + 6;
		if (input[i] == 'M' || input[i] == 'N' || input[i] == 'O')
			sum = sum + 7;
		if (input[i] == 'P' || input[i] == 'Q' || input[i] == 'R' || input[i] == 'S')
			sum = sum + 8;
		if (input[i] == 'T' || input[i] == 'U' || input[i] == 'V')
			sum = sum + 9;
		if (input[i] == 'W' || input[i] == 'X' || input[i] == 'Y' || input[i] == 'Z')
			sum = sum + 10;
	}
    printf("%d", sum);
	return 0;
}