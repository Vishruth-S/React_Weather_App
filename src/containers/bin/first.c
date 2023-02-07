#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char result[30] = "";
char foll[30] = "";
int c = 0;
int count = 0;
char prods[10][20];
int n;

void first(char);
void follow(char);

void follow(char S)
{
    if (prods[0][0] == S)
        result[count++] = '$';

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(prods[i]); j++)
        {
            if (prods[i][j] == S)
            {
                if (prods[i][j + 1] != '\0')
                    first(prods[i][j + 1]);
                if (prods[i][j + 1] == '\0' && S != prods[i][0])
                    follow(prods[i][0]);
            }
        }
    }
}

void first(char S)
{
    if (!isupper(S))
        result[count++] = S;
    for (int i = 0; i < n; i++)
    {
        if (prods[i][0] == S)
        {
            if (prods[i][2] == '$')
                follow(prods[i][0]);
            else if (islower(prods[i][2]))
            {
                result[count++] = prods[i][2];
            }
            else
                first(prods[i][2]);
        }
    }
}

int main()
{
    printf("\nEnter the number of productions: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &prods[i]);
    }
    printf("\nEnter the symbol whose first needs to be calculated\n");
    char start;
    scanf(" %c", &start);
    first(start);
    printf("\nFirst of %c is: {", start);
    printf("%s}", result);
    strcpy(result, " ");
    count = 0;
    follow(start);
    printf("\nFollow of %c is: {", start);
    printf("%s}", result);
    return 0;
}