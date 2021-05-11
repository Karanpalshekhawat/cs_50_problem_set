#include <stdio.h>
#include <cs50.h>
#include <math.h>

void draw(int);

int main(void)
{
    int h = get_int("What the height: ");

    //draw(h);
    int flag = 10 + 40 + 70 + 110 + 120 + 130 + 200 + 220 + 240;
    printf("flag: %i\n", flag);
    int rd = round(flag / 9);
    printf("round: %i\n", rd);
}

void draw(int a)
{
    if (a > 1)
    {
       draw(a - 1);
    }


    for (int i = 1; i <= a; i++)
    {
        printf("#");
    }
    printf("\n");
}