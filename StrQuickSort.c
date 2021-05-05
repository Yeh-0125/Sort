#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsefulFunction.h"
#define dataCnt 1000000

char **StrPartition(char **start,char **end){
    char **i;
    char **j;
    char **pivot;
    pivot=end;
    i=start-1;
    j=start;

    while(j!=pivot){
        if(strcmp(*j,*pivot)>0){
            j++;
        }
        else{
            i++;
            strswap(i,j);
            j++;
        }
    }
    i++;
    strswap(i,pivot);
    return i;
}

void sQuickSort(char **data,char **start,char **end){
    if(start<end){
        char **middle;
        middle=StrPartition(start,end);
        sQuickSort(data,start,middle-1);
        sQuickSort(data,middle+1,end);
    }
    return;
}

void StrQuickSort(){
    //字串的QuickSort
    int i=0;
    char *str=(char *)malloc(16*sizeof(char));
    char *strdata[dataCnt];
    char **StrStart;
    char **StrEnd;
    FILE *sfile;
    sfile=fopen("dataset2.txt","r");

    for(i=0;i<dataCnt;i++){
        strdata[i]=(char *)malloc(16*sizeof(char));
    }
    for(i=0;i<dataCnt;i++){
        fgets(str,16,sfile);
        renewline(str);
        strcpy(strdata[i],str);
    }
    fclose(sfile);
    //printStrData(strdata,i);
    StrStart=strdata;
    StrEnd=&strdata[i-1];
    sQuickSort(strdata,StrStart,StrEnd);
    //printStrData(strdata,i);
}
