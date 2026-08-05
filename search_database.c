#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

Status search_database(Hash* arr,char* word){
    int i=find_index(word);

    //index empty
    if(arr[i].link==NULL){
        printf("Word is not present\n");
        return e_failure;
    }

    //index non empty
    Mlist* mtemp=arr[i].link;
    //travese and compare
    while(mtemp){
       if(strcmp(mtemp->word,word)==0){
        printf("%s found in database\n",word);
        printf("index:%d\n",i);
        printf("word:%s\n",mtemp->word);
        printf("File count:%d\n",mtemp->file_count);
        printf("\n");
        printf("files:\n");

        Slist* tsub=mtemp->sub_link;
        while(tsub){
           printf( "file names:%s\n",tsub->file_name);
           printf( "word count:%d\n",tsub->word_count);
           tsub=tsub->sub_link;
        }
       

       }
       return e_failure;

       mtemp=mtemp->main_link;
    }

    printf("word not present in database\n");

    return e_failure;
    

}