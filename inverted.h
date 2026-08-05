#ifndef INVERTED_H
#define INVERTED_H


typedef enum
{
    e_success,
    e_failure
} Status;

typedef struct node{
    char file[100];
    struct node* next;
}list;

/* Sub node */

typedef struct sub_node
{
    int word_count;
    char file_name[100];
    struct sub_node *sub_link;
}Slist;

/* Main node */

typedef struct main_node
{
    char word[50];
    int file_count;

    Slist *sub_link;
    struct main_node *main_link;

}Mlist;

/* Hash table */

typedef struct hash
{
    int index;
    Mlist *link;

}Hash;

Status validate(char *filename);
Status insert_file(list **head, char *filename);
void print_list(list *head);

Status create_database(Hash arr[], list *head);
int find_index(char* word);
Status insert_word(Hash *hash, char *word, char *filename);
Status update_subnode(Mlist *main, char *filename);
Status create_main_node(Hash *hash, char *word, char *filename);
void display_database(Hash arr[]);
void save_database(Hash arr[]);
Status search_database(Hash* arr,char* word);
Status update_database(Hash arr[]);


#endif