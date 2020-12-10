#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float f;

    do
    {
        f = get_float("Cash Owed: \n");
    }
    while(f < 0);

    int cents = round(f * 100);

    int coins = 0;

    while(cents != 0)
    {
        coins += cents/25;
        cents %= 25;

        coins += cents/10;
        cents %= 10;

        coins += cents/5;
        cents %= 5;

        coins += cents/1;
        cents %= 1;

        printf("Cents= %i, Coins = %i", cents, coins);
    }


}