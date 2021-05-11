#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string checkhh = "abcde";
    char to[5];
    for (int i=0; i < 5;i++)
    {
        to[i] = checkhh[i];
    }
    //for (int i=0; i < 5;i++)
    //{
    //    printf("%c", to[i]);
    //}
    string s = to;
    printf("%s", to);
}