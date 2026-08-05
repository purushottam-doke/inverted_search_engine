#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status insert_word(Hash *hash, char *word, char *filename)
{
    Mlist *mtemp = hash->link;

    while(mtemp != NULL)
    {
        if(strcmp(mtemp->word, word) == 0)
        {
            return update_subnode(mtemp, filename);
        }

        mtemp = mtemp->main_link;
    }

    create_main_node(hash, word, filename);

    return e_success;
}