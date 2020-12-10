#include <stdio.h>
#include <cs50.h>

void print(char c, int a);

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: \n");
    }
    while(h <= 0 || h >= 9 );

    for (int a = 0; a < h; a++)
    {
        print(' ', h - 1 - a);
        print('#', a + 1);
        print(' ', 2);
        print('#', a + 1);

    printf("\n");
    }
}


void print(char c, int h)

{
    for(int a = 0; a < h; a++)
        {
            printf("%c", c);
        }
}
