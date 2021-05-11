#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));
    y = malloc(sizeof(int));

    *x = 42;
    *y = 13;

    printf("%i ::\n",*x);
    y = x;
    *y = 13;
    printf("%i ::\n",*y);
}