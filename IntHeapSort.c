#include<stdio.h>
#include<stdlib.h>
#include"UsefulFunction.h"
#define dataCnt 10000

void HeapPrintData(int *data,int idx){
    int i=0;
    for(i=1;i<6;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
}

void BuildMaxHeap(int *data,int root,int len){
    int left=root*2;
    int right=root*2+1;
    int *Max;

    if(left<=len && data[left]>data[root]){
        Max=&data[left];
    }
    else{
        Max=&data[root];
    }

    if(right<=len && data[right]>*Max){
        Max=&data[right];
    }

    if(Max!=&data[root]){
        swap(Max,&data[root]);
    }
}

void HeapSort(int *data,int len){
    int i=0,j=0;
    len=len-1;
    for(i=len/2;i>=1;i--){
        BuildMaxHeap(data,i,len);
    }
    for(i=len;i>1;i--){
        swap(&data[1],&data[i]);
        //printData(data,len);
        for(j=(i-1)/2;j>=1;j--){
            BuildMaxHeap(data,j,i-1);
        }
        //printf("=");
        //printData(data,len);
    }
    
}

void IntHeapSort(){
    char *str=(char *)malloc(16*sizeof(char));
    int data[dataCnt];
    int i=0;
    FILE *ifile;
    ifile=fopen("dataset1.txt","r");

    for(i=1;i<dataCnt;i++){
        fgets(str,16,ifile);
        data[i]=atoi(str);
    }
    fclose(ifile);
    //HeapPrintData(data,i);
    HeapSort(data,i);
    //HeapPrintData(data,i);
}
