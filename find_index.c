#include<stdio.h>
#include<string.h>
#include"inverted.h"
#include<stdlib.h>

int find_index(char* word){
    if(word[0]>='a'&& word[0]<='z'){
        return word[0]-'a';
    }
    else if(word[0]>='A'&&word[0]<='Z'){
        return word[0]-'A';
    }
    else{
        return 26;
    }
}