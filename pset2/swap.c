#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x;
    int y;
    printf("x:\n");
    scanf("%i", &x);
    printf("y:\n");
    scanf("%i", &y);

    swap(&x, &y);

    printf("AFTER SWAP:\nx is %i,y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


