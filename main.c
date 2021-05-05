#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define dataCnt 1000
#include"GetRand.h"
#include"IntQuickSort.h"
#include"IntMergeSort.h"
#include"IntHeapSort.h"
#include"StrQuickSort.h"
#include"StrMergeSort.h"
#include"StrHeapSort.h"

int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff=0;

    //建立資料
    printf("==GetRand==\n");
    GetRandInt();
    GetRandStr();
    	/*
    printf("==IntQuickSort==\n");
    gettimeofday(&start,NULL);
    IntQuickSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);

    printf("==IntMergeSort==\n");
    gettimeofday(&start,NULL);
    IntMergeSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);

    printf("==IntHeapSort==\n");
    gettimeofday(&start,NULL);
    IntHeapSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);
    
    printf("==StrQuickSort==\n");
    gettimeofday(&start,NULL);
    StrQuickSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);
	*/
    printf("==StrMergeSort==\n");
    gettimeofday(&start,NULL);
    StrMergeSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);

    printf("==StrHeapSort==\n");
    StrHeapSort();
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    printf("use %ld microsecond\n\n",diff);
    return 0;
}
