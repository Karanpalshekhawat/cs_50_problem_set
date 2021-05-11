#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);
int readability_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = readability_index(letters, words, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int count_letters(string txt)
{
    int letters = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
        if (isalpha(txt[i]))
        {
            letters+=1;
        }
    return letters;
}

int count_words(string txt)
{
    int words = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (txt[i] == '-' && isalpha(txt[i - 1])) {}

        else if (txt[i] == 39 && isalpha(txt[i - 1])) {}

        else if (!isalpha(txt[i]) && isalpha(txt[i - 1]))
        {
            words +=1;
        }

    }
    return words;
}

int count_sentences(string txt)
{
    int sentences = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        int character = txt[i];
        if (character == 46 || character == 33 || character == 63)
        {
            sentences +=1;
        }
    }
    return sentences;
}

int readability_index(int letters, int words, int sentences)
{
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}