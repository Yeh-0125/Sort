all: main.c UsefulFunction.o GetRand.o IntQuickSort.o IntMergeSort.o IntHeapSort.o StrQuickSort.o StrMergeSort.o StrHeapSort.o
	gcc main.c UsefulFunction.o GetRand.o IntQuickSort.o IntMergeSort.o IntHeapSort.o StrQuickSort.o StrMergeSort.o StrHeapSort.o -o a.out
	./a.out

UsefulFunction.o:UsefulFunction.c UsefulFunction.h
	gcc -c UsefulFunction.c -o UsefulFunction.o
GetRand.o:GetRand.c GetRand.h
	gcc -c GetRand.c -o GetRand.o
IntQuickSort.o:IntQuickSort.c IntQuickSort.h
	gcc -c IntQuickSort.c -o IntQuickSort.o
IntMergeSort.o:IntMergeSort.c IntMergeSort.h
	gcc -c IntMergeSort.c -o IntMergeSort.o
IntHeapSort.o:IntHeapSort.c IntHeapSort.h
	gcc -c IntHeapSort.c -o IntHeapSort.o
StrQuickSort.o:StrQuickSort.c StrQuickSort.h
	gcc -c StrQuickSort.c -o StrQuickSort.o
StrMergeSort.o:StrMergeSort.c StrMergeSort.h
	gcc -c StrMergeSort.c -o StrMergeSort.o
StrHeapSort.o:StrHeapSort.c StrHeapSort.h
	gcc -c StrHeapSort.c -o StrHeapSort.o
clean:
	rm -f a.out UsefulFunction.o GetRand.o IntQuickSort.o IntMergeSort.o IntHeapSort.o StrQuickSort.o StrMergeSort.o StrHeapSort.o
