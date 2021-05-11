#include <stdio.h>
#include <cs50.h>

int find_time(int, int);

int main(void)
{
    int start_pop;
    do
    {
        start_pop = get_int("Start size: ");
    }
    while (start_pop < 9);

    int ending_pop;
    do
    {
        ending_pop = get_int("End size: ");
    }
    while (ending_pop < start_pop);

    printf("Finding n years .....\n");

    int n = find_time(start_pop, ending_pop);

    printf("Years: %i\n", n);
}


int find_time(int st, int en)
{
    int t = 0;
    while (st < en)
    {
        int new_pop = st / 3;
        int dec_pop = st / 4;
        st = st + new_pop - dec_pop;
        t++;
    }
    return t;
}
