#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>


#include <stdio.h>
#include "inverted.h"

void display_database(Hash arr[])
{
    printf("\n---------------- DATABASE ----------------\n");

    for(int i = 0; i < 27; i++)
    {
        if(arr[i].link == NULL)
            continue;

        Mlist *main = arr[i].link;

        while(main != NULL)
        {
            printf("\nIndex        : %d\n", i);
            printf("Word         : %s\n", main->word);
            printf("File Count   : %d\n", main->file_count);

            printf("Files:\n");

            Slist *sub = main->sub_link;

            while(sub != NULL)
            {
                printf("   %-15s Count : %d\n",
                        sub->file_name,
                        sub->word_count);

                sub = sub->sub_link;
            }

            printf("-------------------------------------\n");

            main = main->main_link;
        }
    }
}