#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H


/***ASCII list length***/

#define ASCII_LIST_LENGTH 256



/* Interfaces */

extern int BMSearch(char *src,char *pattern);

extern int KMPMatch(char *src,char *pattern);

extern void HeapSort(int *a,int arr_size);

extern void quicksort(int a[],int left,int right);

extern void countSort(int src[],int dest[],int temp[],int length,int num);

#endif
