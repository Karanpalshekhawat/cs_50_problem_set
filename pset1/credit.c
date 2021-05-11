#include <stdio.h>
#include <math.h>
#include <cs50.h>

bool check_validity(long, int);
int count_num_of_digits(long);

int main(void)
{
    long ccnum = get_long("Enter credit card number: ");
    int digits = count_num_of_digits(ccnum);
    bool con;
    if (digits == 16 || digits == 13 || digits == 15)
    {
       con = check_validity(ccnum, digits);
    }
    else
    {
        con = false;
    }

    if (con)
    {
        long res = pow(10, digits-2);
        int num_to_check = ccnum / res;
        if (num_to_check / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (num_to_check == 51 || num_to_check == 52 || num_to_check == 53 || num_to_check == 54 || num_to_check == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (num_to_check == 34 || num_to_check == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


int count_num_of_digits(long num)
{
    int count = 0;
    while (num != 0)
    {
        num = num /10;
        count++;
    }
    return count;
}


bool check_validity(long num, int dig)
{
    int sum1 = 0;
    int sum2 = 0;
    int flag = 0;
    int flag2 = 0;
    for (int i = 1; i <= dig; i++ )
    {
        flag = num % 10;
        if (i % 2 == 0)
        {
            flag2 = flag * 2;
            if (flag2 > 9)
            {
                int dum = flag2 % 10;
                int new_num = flag2 / 10;
                flag2 = dum + new_num;
            }
            sum1 = sum1 + flag2;
        }
        else
        {
            sum2 = sum2 + flag;
        }
        num = num / 10;
    }
    int final_num = sum1 + sum2;

    if (final_num % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


