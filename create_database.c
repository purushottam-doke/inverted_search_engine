#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status create_database(Hash arr[],list* head){
    list* temp=head;
    char word[50];   //buffer for word
    while(temp!=NULL){
        FILE* fp=fopen(temp->file,"r");  //open files

        while(fscanf(fp,"%s",word)!=EOF){   //get word
            //find index
          int index=  find_index(word);

         insert_word(&arr[index], word, temp->file);

        }

        fclose(fp);
        temp=temp->next;
    }

    return e_success;
}