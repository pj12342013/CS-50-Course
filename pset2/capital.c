#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(void)
{
    char *a = get_string("input:");
    char *b = malloc(strlen(a + 1));

    strcpy(b, a);

    for(int i = 0, n = strlen(a); i <= n ; i++)
    {
        b[i] = toupper(b[i]);
    }

    printf("%s\n", a);
    printf("%s\n", b);
    
    free(b);
    free(a);
    
}