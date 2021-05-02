#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsefulFunction.h"
#define dataCnt 1000000

void swap(int *a,int *b){
    int tmp=0;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void strswap(char **a,char **b){
    char *tmp=(char *)malloc(16*sizeof(char));
    strcpy(tmp,*a);
    strcpy(*a,*b);
    strcpy(*b,tmp);
}

void renewline(char *str){
    char *ptr;
    ptr=str;
    while(*ptr){
        if(*ptr=='\n'){
            *ptr='\0';
        }
        ptr++;
    }
}

void printData(int *data,int idx){
    int i=0;
    for(i=0;i<5;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
}

void printStrData(char ** data,int idx){
    char **ptr;
    int i=0;
    ptr=data;
    for(i=0;i<5;i++){
        printf("%s ",*ptr);
        ptr++;
    }
    printf("\n");
}
