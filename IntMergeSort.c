#include<stdio.h>
#include<stdlib.h>
#include"IntMergeSort.h"
#include"UsefulFunction.h"
#define dataCnt 1000

void Merge(int *i,int *j,int *end){
    int A[dataCnt];
    int B[dataCnt];
    int k=0;
    for(k=0;k<dataCnt;k++){
        A[k]=0;
        B[k]=0;
    }
    int idx=0;
    int *writer;
    writer=i;
    //抄錄到新字串
    while(i<j){
        A[idx]=*i;
        i++;
        idx++;
    }
    idx=0;
    while(j<=end){
        B[idx]=*j;
        j++;
        idx++;
    }

    int *aptr;
    int *bptr;
    aptr=A;
    bptr=B;
    //放回原字串
    while(*aptr || *bptr){
        if(!*aptr){
            while(*bptr){
                *writer=*bptr;
                writer++;
                bptr++;
            }
            break;
        }
        if(!*bptr){
            while(*aptr){
                *writer=*aptr;
                writer++;
                aptr++;
            }
            break;
        }
        if(*aptr<*bptr){
            *writer=*aptr;
            aptr++;
            writer++;
        }
        else{
            *writer=*bptr;
            bptr++;
            writer++;
        }
    }
}

void MergeSort(int *data,int *start,int *end){
    if(start<end){
        int *middle;
        int *ptr;
        int i=0;
        ptr=start;
        while(ptr!=end){
            i++;
            ptr++;
        }
        middle=start+i/2;
        MergeSort(data,start,middle);
        MergeSort(data,middle+1,end);
        Merge(start,middle+1,end);
        //printData(data,i);
    }
    return;
}

void IntMergeSort(){
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
    MergeSort(data,start,end);
    //printData(data,i);
}
