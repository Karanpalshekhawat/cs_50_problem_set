#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool check_alphabters_are_only_once(string);
string convert_plain_text(string, string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Command line argument should be 2 only !!\n");
        return 1;
    }
    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("But key should contain exactly 26 character (not less and not more than that). also it should not contain & and ! \n");
        return 1;
    }

    int count = 0;
    for (int i=0, n = strlen(key); i < n; i++)
    {
        if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
        {
            continue;
        }
        else
        {
            count++;
        }
    }

    if (count != 0)
    {
        printf("But key should contain only Alphabatic characters...\n ");
        return 1;
    }

    for (int i=0, n = strlen(key); i < n; i++)
    {
        if (isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }
    }

    bool repeat = check_alphabters_are_only_once(key);

    if (repeat == false)
    {
        printf("Alphabets in the key should not be repeated... \n");
        return 1;
    }

    string plain_text = get_string("plaintext: ");

    int d = strlen(plain_text);
    int case_check[d];

    for (int i=0; i < d; i++)
    {
        if (isupper(plain_text[i]))
        {
            plain_text[i] = tolower(plain_text[i]);
            case_check[i] = 1;
        }
        else
        {
            case_check[i] = 0;
        }
    }

    string ciper_text = convert_plain_text(key, plain_text);

    for (int i=0; i < d; i++)
    {
        if (case_check[i] == 1)
        {
            ciper_text[i] = toupper(ciper_text[i]);
        }
    }

    printf("ciphertext: %s\n", ciper_text);

}

string convert_plain_text(string k , string ptext)
{
    int x;
    int n = strlen(ptext);
    char ctext[n];
    for (int i=0; i < n; i++)
    {
        if (ptext[i] >= 'a' & ptext[i] <= 'z')
        {
            x = ptext[i] - 'a';
            ctext[i] = k[x];
        }
        else
        {
            ctext[i] = ptext[i];
        }
    }
    string c_t = ctext;
    return c_t;
}

bool check_alphabters_are_only_once(string alpha)
{
    int count_2[26] = {0};
    int c = 0, x;
    while (alpha[c] != '\0')
    {
        if (alpha[c] >= 'a' && alpha[c] <= 'z')
        {
            x = alpha[c] - 'a';
            count_2[x]++;
        }
        c++;
    }
    int count_one = 0;
    for (int i=0; i < 26; i++)
    {
        if (count_2[i] > 1)
        {
            count_one++;
        }
    }
    if (count_one == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}