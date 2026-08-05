#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status insert_file(list **head, char *file)
{
    // Check if file is empty
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("%s : Unable to open file\n", file);
        return e_failure;
    }

    fseek(fp, 0, SEEK_END);

    if (ftell(fp) == 0)
    {
        printf("%s : Empty file. Not inserted.\n", file);
        fclose(fp);
        return e_failure;
    }

    fclose(fp);

    // Create new node
    list *new = malloc(sizeof(list));
    if (new == NULL)
    {
        return e_failure;
    }

    strcpy(new->file, file);
    new->next = NULL;

    // List is empty
    if (*head == NULL)
    {
        *head = new;
        return e_success;
    }

    // Check for duplicates
    list *temp = *head;

    while (temp->next != NULL)
    {
        if (strcmp(temp->file, file) == 0)
        {
            printf("%s : Already exists\n", file);
            free(new);
            return e_failure;
        }

        temp = temp->next;
    }

    // Check last node
    if (strcmp(temp->file, file) == 0)
    {
        printf("%s : Already exists\n", file);
        free(new);
        return e_failure;
    }

    temp->next = new;

    return e_success;
}