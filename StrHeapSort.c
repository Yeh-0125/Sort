#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsefulFunction.h"
#define dataCnt 1000000

void sHeapPrintData(char **data,int idx){
    int i=0;
    for(i=1;i<6;i++){
        printf("%s ",data[i]);
    }
    printf("\n");
}

void sBuildMaxHeap(char **data,int root,int len){
    int left=root*2;
    int right=root*2+1;
    char **Max;

    if(left<=len && strcmp(data[left],data[root])>0){
        Max=&data[left];
    }
    else{
        Max=&data[root];
    }

    if(right<=len && strcmp(data[right],*Max)>0){
        Max=&data[right];
    }

    if(strcmp(*Max,data[root])!=0){
        strswap(Max,&data[root]);
    }
}

void sHeapSort(char **data,int len){
    int i=0,j=0;
    len=len-1;
    for(i=len/2;i>=1;i--){
        sBuildMaxHeap(data,i,len);
    }
    for(i=len;i>1;i--){
        strswap(&data[1],&data[i]);
        //sHeapPrintData(data,len);
        for(j=(i-1)/2;j>=1;j--){
            sBuildMaxHeap(data,j,i-1);
        }
        //printf("=");
        //sHeapPrintData(data,len);
    }
    
}

void StrHeapSort(){
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
    for(i=1;i<dataCnt;i++){
        fgets(str,16,sfile);
        renewline(str);
        strcpy(strdata[i],str);
    }
    fclose(sfile);
    sHeapPrintData(strdata,i);
    sHeapSort(strdata,i);
    sHeapPrintData(strdata,i);
}
