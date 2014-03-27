
#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}       

void HeapAdjust(int *a,int i,int size)
{
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	int max = i;
	if(i<=(size-1)/2)
	{
		if(lchild<=(size-1)&&a[lchild]>a[max])
		{
			max=lchild;
		}	
		if(rchild<=(size-1)&&a[rchild]>a[max])
		{
			max=rchild;
		}
		if(max!=i)
		{
			swap(&a[i],&a[max]);
			HeapAdjust(a,max,size);
		}
	}
}

void BuildHeap(int *a,int size)
{
	int i;
	for(i=size/2-1;i>=0;i--)
		HeapAdjust(a,i,size);
}

void HeapSort(int *a,int size)
{
	int i;
	BuildHeap(a,size);
	for(i=size-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		//swap(a[1],a[i]);
		HeapAdjust(a,0,i);
	}
}

/* a simple test 
int main(int argc,char *argv[])
{
	int a[]={17,12,5,8,40,30,22,19,30,27,13,7,17};
	int i;
	HeapSort(a,13);
	for(i=0;i<12;i++)
		printf("%d\t",a[i]);
	printf("\n");

	return 0;
}
*/


