#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"inverted.h"

Status update_database(Hash arr[])
{

    int flag = 0;

for(int i = 0; i < 27; i++)
{
    if(arr[i].link != NULL)
    {
        flag = 1;
        break;
    }
}

if(flag)
{
    printf("Database already exists. Cannot update.\n");
    return e_failure;
}


    char filename[100];

    printf("Enter saved database file : ");
    scanf("%s", filename);

    if(validate(filename) == e_failure)
        return e_failure;

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return e_failure;
    }

    char line[500];

    while(fgets(line,sizeof(line),fp))
    {
        int index,file_count;

        char *token;

        token = strtok(line,"#;");
        index = atoi(token);

        token = strtok(NULL,";");
        char word[50];
        strcpy(word,token);

        token = strtok(NULL,";");
        file_count = atoi(token);

        Mlist *main = malloc(sizeof(Mlist));

        strcpy(main->word,word);
        main->file_count=file_count;
        main->main_link=NULL;
        main->sub_link=NULL;

        Slist *last=NULL;

        for(int i=0;i<file_count;i++)
        {
            Slist *new=malloc(sizeof(Slist));

            token=strtok(NULL,";");
            strcpy(new->file_name,token);

            token=strtok(NULL,";");
            new->word_count=atoi(token);

            new->sub_link=NULL;

            if(main->sub_link==NULL)
            {
                main->sub_link=new;
            }
            else
            {
                last->sub_link=new;
            }

            last=new;
        }

        if(arr[index].link==NULL)
        {
            arr[index].link=main;
        }
        else
        {
            Mlist *temp=arr[index].link;

            while(temp->main_link)
                temp=temp->main_link;

            temp->main_link=main;
        }
    }

    fclose(fp);

    printf("Database updated successfully.\n");

    return e_success;
}