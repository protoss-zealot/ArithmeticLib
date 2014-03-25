#include <stdio.h>
#include <string.h>
#include "Arithmetic.h"

#ifdef _cplusplus
extern "C"{
#endif

/*
 ******Implementation of Boyer-Moore Algorithm******
 *
 * This function is to solve the string search ,and somhow we
 * can find the position of pattern string in the dest string
 * quickly.
 *
 * Copyright(c) 2013.9.6 xiaoh
 * All rights reserved.
 *
 ***************************************************
*/


/*
 * This function is to build the jump list for each
 * charactor.
 *
*/

void BoyerMoore(char *pattern,int right[])
{
	int M = strlen(pattern);

	for(int c=0;c<ASCII_LIST_LENGTH;c++)
		right[c] = -1;
	for(int j=0;j<M;j++)
		right[pattern[j]] = j;
}

/*
 * Main function of Boyer-More Search Algorithm
 *
*/

int BMSearch(char *dest_str,char *pattern)
{
	/*Varable right: position occured in list*/
	int right[ASCII_LIST_LENGTH];

	BoyerMoore(pattern,right);

	int N = strlen(dest_str);
	int M = strlen(pattern);

	int skip; //number to jump
	for(int i=0;i<=N-M;i+=skip)
	{
		skip = 0;
		for(int j=M-1;j>=0;j--)
		{
			if(pattern[j]!=dest_str[j+i])
			{
				skip = j-right[dest_str[i+j]];//cal the step to jump
				if(skip<1)
					skip = 1;
				break;
			}
		}
		if(skip == 0)
		{
			printf("Search finished successfully.\n");
			return i;	
		}
	}
	printf("String cannot be found.\n");
	return N;
}

/* A simple test 
int main()
{
	char dest_buf[1024];
	char pattern_buf[256];
	printf("Input dest_string:\n");
	gets(dest_buf);
	
	printf("Input pattern string:\n");
	gets(pattern_buf);	// It seems that scanf do not support strings which including space(" ") charactors.

	int res = BMSearch(dest_buf,pattern_buf);

	printf("return val: %d\n",res);
	return 0;
}
*/

#ifdef _cplusplus
}
#endif


