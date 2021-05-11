#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long ccnum = get_long("Enter credit card number: ");
    int digits = get_int("Digits: ");
    long res = pow(10, digits-2);
    int num_to_check = ccnum / res;
    printf("num is %i", num_to_check);
}