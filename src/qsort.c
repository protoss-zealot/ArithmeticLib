#include <stdio.h>

static int Partition(int a[],int left,int right);

static void swap(int &s,int &t);

void quicksort(int a[],int left,int right)
{
	if(left<right)
	{
		int dp = Partition(a,left,right);
		quicksort(a,left,dp-1);
		quicksort(a,dp+1,right);
	}
}

staitc int Partition(int a[],int left,int right)
{
	int i = left,j = right+1;
	int key = a[left];
	while(true)
	{
		while(a[++i]<key);
		while(a[--j]>key);
		if(i>=j)
			break;
		swap(a[i],a[j]);
	}
	a[left] = a[j];
	a[j] = key;
	return j;
}

static void swap(int &s,int &t)
{
	int temp = s;
	s = t;
	t = temp;
}

/* a simple test
int main()
{
	int a[] = {17,25,8,32,7,14,9,12};
	quicksort(a,0,7);
	for(int i=0; i<8; i++)
		printf("Output is : %d\n",a[i]);
	return 0;
}
*/
