
#include "Arithmetic.h"


void countSort(int src[],int dest[],int temp[],int length,int num)
{
    int i;
    /*initial the temp arr*/

    for(i=0;i<length;i++)
        temp[src[i]] = temp[src[i]]+1;

    for(i=1;i<=num;i++)
        temp[i] = temp[i]+temp[i-1];
    for(i=length-1;i>=0;i--)
    {
        dest[temp[src[i]]-1] = src[i];  //这里需要将src中放置到正确的位置，注意要将dest的索引值-1
        temp[src[i]] = temp[src[i]] -1; //放置好一个后就将数量-1
    }
}

/************************
 *                      *
 *  A simple test here. *
 *                      *
 ************************
 */

/*
int main()
{
    int a[10] = {7,8,3,5,8,3,8,2,1,0};
    int buf[10];
    int temp[9];
    int j;
    for(j=0;j<=8;j++)
        temp[j] = 0;
    countSort(a,buf,temp,10,8);
    int index;
    for(index=0;index<10;index++)
        cout<<buf[index]<<" "<<endl;
    cout<<endl;
    return 0;
}
*/