#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height of Pyramid:\n");
    }
    while(h < 0 || h >= 9);

    for(int row = 0; row < h; row++)
    {
        for(int i = 0; i < row; i++)
    
        {
            printf("#");
        }
    }
}