#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsefulFunction.h"
#define dataCnt 100000

void sMerge(char **data,int start,int mid,int end){
    char *A[mid-start+1];
    char *B[end-mid];
    int i=0;
    int j=0,k=0;

    for(i=0;i<(mid-start+1);i++){
    	A[i]=(char *)malloc(16*sizeof(char));
        A[i]=data[mid+1+i];
    }
    for(i=0;i<(end-mid);i++){
	B[i]=(char *)malloc(16*sizeof(char));
	B[i]=data[mid+1+i];
    }
    k=start;
    while(i<(mid-start+1) && j<(end-mid)){
    	if(strcmp(A[i],B[j])>0){
	    data[k]=B[j];
	    j++;
	}
	else{
	    data[k]=A[i];
            i++;
	}
	k++;
    }

    while(i<(mid-start+1)){
    	data[k]=A[i];
        i++;
	k++;
    }
    while(j<(end-mid)){
	data[k]=B[j];
        j++;
	k++;
    }
}

void sMergeSort(char **data,int start,int end){
    if(start<end){
        int middle=start+(end-start)/2;
        sMergeSort(data,start,middle);
        sMergeSort(data,middle+1,end);
        sMerge(data,start,middle,end);
    }
    return;
}

void StrMergeSort(){
    int i=0;
    char *str=(char *)malloc(16*sizeof(char));
    char *strdata[dataCnt];
    int StrStart=0;
    int StrEnd=0;
    FILE *sfile;
    sfile=fopen("dataset2.txt","r");

    for(i=0;i<dataCnt;i++){
        strdata[i]=(char *)malloc(16*sizeof(char));
    }
    for(i=0;i<dataCnt;i++){
        fgets(str,128,sfile);
        renewline(str);
        strcpy(strdata[i],str);
    }
    fclose(sfile);
    printStrData(strdata,i);
    StrEnd=dataCnt-1;
    sMergeSort(strdata,StrStart,StrEnd);
    printStrData(strdata,i);
}
