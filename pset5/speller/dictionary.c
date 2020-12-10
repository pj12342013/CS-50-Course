// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z' ;

// Hash table
node *table[N];

int counter = 0;

bool check(const char *word)
{
    int index = hash(word);

    node *cursor = table[index];

    while(cursor != NULL)
    {
       if(strcasecmp(cursor->word, word)== 0)
       {
           return true;
       }
       cursor = cursor->next;
    }

    return false;
}


unsigned int hash(const char* word)
{
    int sum = 0;

    for(int i = 0; i <strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
        unload();
        return false;
    }
    char word[LENGTH + 1];

    while(fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if(new_node == NULL)
            return false;

        strcpy(new_node->word, word);
        new_node->next = NULL;

        int index = hash(word);

        if(table[index] == NULL)
        {
            table[index] = new_node;
            counter++;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
            counter++;
        }
    }
    fclose(file);
    return true;


}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for(int i = 0; i < N ; i++)
    {
        node *head = table[i];
        node *temp = head ;
        node *cursor = head;

        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }

    }
    return true;
}
