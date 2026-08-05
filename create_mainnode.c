#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status create_main_node(Hash *hash, char *word, char *filename)
{
    Mlist *new_main = malloc(sizeof(Mlist));

    if(new_main == NULL)
        return e_failure;

    strcpy(new_main->word, word);

    new_main->file_count = 1;
    new_main->main_link = NULL;

    Slist *new_sub = malloc(sizeof(Slist));

    if(new_sub == NULL)
        return e_failure;

    strcpy(new_sub->file_name, filename);

    new_sub->word_count = 1;
    new_sub->sub_link = NULL;

    new_main->sub_link = new_sub;

    if(hash->link == NULL)
    {
        hash->link = new_main;
    }
    else
    {
        Mlist *temp = hash->link;

        while(temp->main_link != NULL)
            temp = temp->main_link;

        temp->main_link = new_main;
    }

    return e_success;
}