#include<stdio.h>
#include<string.h>
#include"inverted.h"
int main(int argc,char* argv[]){
    if(argc<2){
        printf("Insufficient arguments\n");
        return  e_failure;
    }
//assign head to null
    list* head=NULL;
//validate files and store into the list
    for(int i=1;i<argc;i++){
      if(validate(argv[i])==e_success){
         insert_file(&head,argv[i]);
      }
    }

printf("\nValid Files:\n");
print_list(head);

Hash arr[27];
for(int i=0;i<27;i++){
    arr[i].index=i;
    arr[i].link=NULL;

}


//display menu
printf("1.Create Database\n");
printf("2.Display Database\n");
printf("3.Save Database\n");
printf("4.Search Database\n");
printf("5.Update Database\n");
printf("6.Exit\n");
int opt;
int db_created=0;
do{
printf("Enter the operation:");
scanf("%d",&opt);

switch(opt){
    case 1:
   

    if(db_created)
    {
        printf("INFO : Database already created.\n");
        break;
    }

    if(create_database(arr, head) == e_success)
    {
        printf("INFO : Database created successfully.\n");
        db_created = 1;
    }
    else
    {
        printf("INFO : Error in creating database.\n");
    }

    break;

    case 2:
    display_database(arr);
    break;

    case 3:
    save_database(arr);
    break;

    case 4:
    char word[20];
    printf("Enter the word for search:");
    scanf(" %[^\n]",word);
    
    search_database(arr,word);
    break;

    case 5:
    

    update_database(arr);
    break;

case 6:
    printf("Exiting...\n");
    break;
    

   
}

}while(opt!=6);

}


