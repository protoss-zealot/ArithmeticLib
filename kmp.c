#include <stdio.h>
#include <string.h>


#define BUFFSIZE 100


int KMPMatch(char *s,char *p)
{
	int next[BUFFSIZE];
	int i,j;
	i=0;
	j=0;
	int c;
	getNext(p,next);
	for(c=0;c<4;c++)
		printf("%d\t",next[c]);
	printf("\n");
	while(i<strlen(s))
	{
		if(j==-1||s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	
		if(j==strlen(p))					//弱模式串匹配则输出匹配的位置
			return i-strlen(p);
	}
	return -1;
}

static void getNext(char *p,int *next)
{
	int k,j;
	next[0]=-1;
	j=0;
	k=-1;
	while(j<strlen(p)-1)
	{
		if(k==-1||p[j]==p[k])
		{
			j++;
			k++;
			if(p[j]!=p[k])
				next[j]=k;
			else
				next[j]=next[k];
		}
		else
			k=next[k];

	}
}


/* A simple test
int main()
{
	char src[BUFFSIZE];
	char p[BUFFSIZE];
	printf("input source string:\n");
	scanf("%s",&src);
	printf("input pattern string:\n");
	scanf("%s",&p);
	printf("%d\n",KMPMatch(src,p));
	return 0;
}

*/

