#include<stdio.h>
#include<stdlib.h>
#include"IntMergeSort.h"
#include"UsefulFunction.h"
#define dataCnt 10000

void Merge(int *i,int *j,int *end){
    int *A=(int *)malloc(dataCnt*sizeof(int));
    int *B=(int *)malloc(dataCnt*sizeof(int));
    int k=0;
    int *aptr;
    int *bptr;
    aptr=A;
    bptr=B;
    for(k=0;k<dataCnt;k++){
        *aptr=0;
        *bptr=0;
	aptr++;
	bptr++;
    }
    aptr=A;
    bptr=B;
    int idx=0;
    int *writer;
    writer=i;
    //抄錄到新字串
    while(i<=j){
        *aptr=*i;
        i++;
        aptr++;
    }
    idx=0;
    j++;
    while(j<=end){
        *bptr=*j;
        j++;
        bptr++;
    }
    //放回原字串
    aptr=A;
    bptr=B;
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
    free(A);
    free(B);
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
	//printData(data,i);
	if(i==2){
	    middle=start;
	}
	else{
	    middle=start+i/2;
	}
	//printf("===\n");
	
        MergeSort(data,start,middle);
        MergeSort(data,middle+1,end);
        Merge(start,middle,end);
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
    start=data;
    end=&data[i-1];
    //printData(data,i);
    MergeSort(data,start,end);
    //printData(data,i);
}
/*
int main(){
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
    start=data;
    end=&data[i-1];
    //printData(data,i);
    MergeSort(data,start,end);
    //printData(data,i);
    return 0;
}
*/
