#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int fun1(int n)
{
    static int i = 0;
    if (n > 0)
    {
        ++i;
        fun1(n-1);
    }
    return(i);
}

int fun2(int n)
{
    static int i = 0;
    if (n > 0)
    {
        i = i + fun1(n);
        fun2(n-1);
    }
    return(i);
}

int simplefunction(int Y[], int n, int x)
{
    int total = Y[0], li;
    for (li = 1; li <= n - 1; li++)
    {
        total = x * total + Y[li];
    }
    return total;
}

int main(void)
{
    int x = fun1(5);
    printf("%d\n", x);
}