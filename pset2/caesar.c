#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool check_valid_key(string s);

int main(int argc, string argv[])

{
    if(argc !=  2 || ! check_valid_key(argv[1]) )
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string s = get_string("plaintext:\n");

    printf("ciphertext: ");

   for(int i = 0, len = strlen(s); i < len; i++)
   {
        char c = s[i];



        if(isalpha(c))
        {
            char m = 'A';

            if(islower(c))

            m = 'a';

            printf("%c", (c - m + key) % 26 + m);

        }
        else
        printf("%c", c);
   }
   printf("\n");
}

bool check_valid_key(string s)
{
for (int i = 0, len = strlen(s); i < len; i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}


