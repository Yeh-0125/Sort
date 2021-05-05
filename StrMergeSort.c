#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UsefulFunction.h"
#define dataCnt 1000000

void refresh(char *str){
    while(*str){
    	if(*str!='\0'){
	    *str='\0';
	}
    }
}

void sMerge(char **data,char **i,char **j,char **end){
    char *A[dataCnt];
    char *B[dataCnt];
    int k=0;
    int idx=0;
    char **writer;
    writer=i;
    for(k=0;k<dataCnt;k++){
        A[k]=(char *)malloc(16*sizeof(char));
        B[k]=(char *)malloc(16*sizeof(char));
	refresh(A[k]);
	refresh(B[k]);
    }
    //抄錄到新字串
    while(i<j){
        strcpy(A[idx],*i);
        i++;
        idx++;
    }
    idx=0;
    while(j<=end){
        strcpy(B[idx],*j);
        j++;
        idx++;
    }
    char **aptr;
    char **bptr;
    aptr=A;
    bptr=B;
    k=0;
    //放回原字串
    while(**aptr!='\0' && **bptr!='\0'){
	    if(strcmp(*aptr,*bptr)>0){
		strcpy(*writer,*bptr);
		bptr++;
	    }
	    else{
	    	strcpy(*writer,*aptr);
		aptr++;
	    }
	    writer++;
    }
    while(**aptr!='\0'){
    	strcpy(*writer,*aptr);
        aptr++;
	writer++;
    }
    while(**bptr!='\0'){
        strcpy(*writer,*bptr);
        bptr++;
        writer++;
    }
}

void sMergeSort(char **data,char **start,char **end){
    if(start!=end){
        char **middle;
        char **ptr;
        int i=0;
        ptr=start;
        while(ptr!=end){
            i++;
            ptr++;
        }
        middle=start+i/2;
        sMergeSort(data,start,middle);
        sMergeSort(data,middle+1,end);
        sMerge(data,start,middle+1,end);
	//printStrData(data,i);
    }
    return;
}

void StrMergeSort(){
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
    printStrData(strdata,i);
    StrStart=strdata;
    StrEnd=&strdata[i-1];
    sMergeSort(strdata,StrStart,StrEnd);
    printStrData(strdata,i);
}
