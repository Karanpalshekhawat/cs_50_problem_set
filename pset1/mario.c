#include <stdio.h>
#include <cs50.h>

void create_pyramids(int);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    create_pyramids(height);
}

void create_pyramids(int h)
{
    int dm = h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (j >= dm)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("  ");

        int k = h;
        while (k >= dm)
        {
            printf("#");
            k--;
        }
        printf("\n");
        dm--;
    }
}