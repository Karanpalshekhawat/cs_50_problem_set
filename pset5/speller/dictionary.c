// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Number of characters in dictionary
int dict_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);

    node *tmp3 = table[hash_value];

    while (tmp3!=NULL)
    {
        if (strcasecmp(word, tmp3->word) == 0)
        {
            return true;
        }
        tmp3 = tmp3->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long sum = 0;
    for (int i=0; i < strlen(word); i++)
    {
        sum+=tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary file %s.\n", dictionary);
        return false;
    }
    char dummy_word[LENGTH + 1];

    while(fscanf(file, "%s", dummy_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n==NULL)
        {
            printf("memory issues\n");
            return false;
        }

        strcpy(n->word, dummy_word);
        int value_hash = hash(dummy_word);
        n->next = table[value_hash];
        table[value_hash] = n;
        dict_size++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *n = tmp;
            tmp =  tmp->next;
            free(n);
        }
        if (tmp==NULL && i == N-1)
        {
            return true;
        }
    }
    return false;
}
