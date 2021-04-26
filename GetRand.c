#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"GetRand.h"
#define dataCnt 1000

void GetRandInt(){
    int apple;
    int i=0;
    FILE *file;
    file=fopen("dataset1.txt","w");

    srand(time(NULL));
    for(i=0;i<dataCnt;i++){
        apple=rand();
        //printf("%d=%d\n",i,apple[i]);
        fprintf(file,"%d\n",apple);
    }
    fclose(file);
}

void cleanstr(char *str){
    while(*str){
        *str='\0';
        str++;
    }
}

void GetRandStr(){
    char *ptr;
    char a;
    char str[16];
    cleanstr(str);
    int i=0,j=0;
    FILE *file;
    file=fopen("dataset2.txt","w");

    srand(time(NULL));
    //製造隨機字串
    for(i=0;i<dataCnt;i++){
        ptr=str;
        for(j=0;j<10;j++){
            //a=rand()%26+'a';
            //printf("a[%d]=%c\n",j,a);
            *ptr=rand()%26+'a';
            //fprintf(file,"%c\n",*ptr);
            ptr++;
        }
        fprintf(file,"%s\n",str);
        //fprintf(file,"===\n");
        cleanstr(str);
    }
    fclose(file);
}
