#include <stdio.h>
#include <string.h>
#include "inverted.h"
Status validate(char* argv){
    char* ptr=strrchr(argv,'.');
     if(ptr==NULL){
        printf("%s: file extension not present\n",argv);
        return e_failure;
     }

     if(strcmp(ptr,".txt")!=0){
        printf("%s:file type is invalid\n",argv);
        return e_failure;
     }

     FILE* fp=fopen(argv,"r");
        if(fp==NULL){
            printf("%s: file not present\n",argv);
            return e_failure;
        }
     
    fclose(fp);

    return e_success;


}

