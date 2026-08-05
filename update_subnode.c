#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status update_subnode(Mlist *main, char *filename)
{
    Slist *stemp = main->sub_link;

    while(stemp != NULL)
    {
        if(strcmp(stemp->file_name, filename) == 0)
        {
            stemp->word_count++;
            return e_success;
        }

        stemp = stemp->sub_link;
    }

    Slist *new = malloc(sizeof(Slist));

    if(new == NULL)
        return e_failure;

    strcpy(new->file_name, filename);

    new->word_count = 1;

    new->sub_link = NULL;

    stemp = main->sub_link;

    while(stemp->sub_link != NULL)
        stemp = stemp->sub_link;

    stemp->sub_link = new;

    main->file_count++;

    return e_success;
}