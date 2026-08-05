#include<stdio.h>
#include<string.h>
#include"inverted.h"

void print_list(list *head)
{
    while (head)
    {
        printf("%s -> ", head->file);
        head = head->next;
    }

    printf("NULL\n");
}