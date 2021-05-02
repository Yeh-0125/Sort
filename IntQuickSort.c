#include<stdio.h>
#include<stdlib.h>
#include"IntQuickSort.h"
#include"UsefulFunction.h"
#define dataCnt 10000

int *partition(int *start,int *end){
    int *i;
    int *j;
    int *pivot;
    pivot=end;
    i=start-1;
    j=start;

    while(j!=pivot){
        if(*j>*pivot){
            j++;
        }
        else{
            i++;
            swap(i,j);
            j++;
        }
    }
    i++;
    swap(i,pivot);
    return i;
}

void QuickSort(int *data,int *start,int *end){
    if(start<end){
        int *middle;
        middle=partition(start,end);
        QuickSort(data,start,middle-1);
        QuickSort(data,middle+1,end);
    }
    return;
}

void IntQuickSort(){
    //整數的QuickSort
    char *str=(char *)malloc(16*sizeof(char));
    int data[dataCnt];
    int i=0,j=0;
    int *start;
    int *end;
    FILE *ifile;
    ifile=fopen("dataset1.txt","r");

    for(i=0;i<dataCnt;i++){
        fgets(str,16,ifile);
        data[i]=atoi(str);
    }
    fclose(ifile);
    //printData(data,i);
    start=data;
    end=&data[i-1];
    QuickSort(data,start,end);
    //printData(data,i);
}
