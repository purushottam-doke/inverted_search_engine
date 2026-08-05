#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>
void save_database(Hash arr[]){

    //check database is created or not before saving
    int flag = 0;

for (int i = 0; i < 27; i++)
{
    if (arr[i].link != NULL)
    {
        flag = 1;
        break;
    }
}

if (flag == 0)
{
    printf("Database is empty. Create the database first.\n");
    return;
}
    //read file name from user
    char file_name[30];
  GET_FILE:

printf("Enter the file name to save database: ");
scanf("%s", file_name);

/* Validate extension */
char *ptr = strrchr(file_name, '.');

if (ptr == NULL)
{
    printf("Extension is not present\n");
    goto GET_FILE;
}

if (strcmp(ptr, ".txt") != 0)
{
    printf("Invalid file format\n");
    goto GET_FILE;
}

/* Check whether file exists */
FILE *fp = fopen(file_name, "r");

if (fp != NULL)
{
    fseek(fp, 0, SEEK_END);

    if (ftell(fp) != 0)      // File is not empty
    {
        int choice;

        printf("\nFile already contains data.\n");
        printf("1. Overwrite\n");
        printf("2. Enter New File Name\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        fclose(fp);

        switch (choice)
        {
            case 1:
                goto WRITE_DATA;

            case 2:
                goto GET_FILE;

            default:
                printf("Invalid choice\n");
                goto GET_FILE;
        }
    }

    fclose(fp);
}

WRITE_DATA:

fp = fopen(file_name, "w");

if (fp == NULL)
{
    printf("Unable to open file\n");
    return;
}

/* Write database */
for (int i = 0; i < 27; i++)
{
    if (arr[i].link == NULL)
        continue;

    Mlist *main = arr[i].link;

    while (main != NULL)
    {
        fprintf(fp, "#%d;%s;%d;", i, main->word, main->file_count);

        Slist *sub = main->sub_link;

        while (sub != NULL)
        {
            fprintf(fp, "%s;%d;", sub->file_name, sub->word_count);
            sub = sub->sub_link;
        }

        fprintf(fp, "#\n");

        main = main->main_link;
    }
}

fclose(fp);
printf("Database saved successfully.\n");

}