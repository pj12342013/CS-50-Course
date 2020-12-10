#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int i = get_int("input:\n");

    int f = collatz(i);

    printf("Collatz: %i", f);
}


int collatz(int n)

{

    //base case
    if (n ==1)
    {

        return 0;
    }
    else if ( (n % 2 ) ==0)
    {

        return 1 + collatz(n/2);
    }
    else if ( (n % 2 )!= 0)
    {

        return 1 + collatz( 3*n + 1);

    }
    return n;
}