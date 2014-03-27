

#include <stdio.h>
#include <malloc.h>
#include "trie.h"


Trie *NewTrie()
{
	Trie *temp = (Trie *)malloc(sizeof(Trie));
	temp->num = 1;
	temp->terminal = false;
	for(int i=0;i<sonnum;++i)
		temp->son[i] = NULL;
	return temp;
}

void TrieDelete(Trie *pnt)
{
	if(pnt!=NULL)
	{
		for(int i=0;i<sonnum;++i)
			if(pnt->son[i]!=NULL)
				Delete(pnt->son[i]);
		free(pnt);
		pnt = NULL;
	}
}

void TrieInsert(Trie *pnt,char *s,int len)
{
	Trie *temp = pnt;
	for(int i=0;i<len;++i)
	{
		if(temp->son[s[i]-base]==NULL)
			temp->son[s[i]-base]=NewTrie();
		else
			temp->son[s[i]-base]->num++;
		temp = temp->son[s[i]-base];
	}
	temp->terminal = true;
}

Trie *TrieFind(Trie *pnt,char *s,int len)
{
	Trie *temp = pnt;
	for(int i=0;i<len;++i)
		if(temp->son[s[i]-base]!=NULL)
			temp = temp->son[s[i]-base];
		else
			return NULL;
	return temp;
}




/* This is a Trie-tree apply programme

int main(int argc,char *argv[])
{
	Trie *root = NewTrie();

	char in_buff[100];

	while(1)
	{
		printf("Input words:\n");
		scanf("%s",in_buff);
		printf("%s\n",in_buff);
		if(in_buff[0]=='e'&&in_buff[1]=='n'&&in_buff[2]=='d')    //输入结束判断，真尼玛的麻烦，但我实在没想出更好的~
			break;
		else
			TrieInsert(root,in_buff,strlen(in_buff));
	}

	printf("Input search prex:\n");
		 
	scanf("%s",in_buff);
	
	Trie *Node = TrieFind(root,in_buff,strlen(in_buff));

	printf("%d\n",Node->num);			//output the prex number

	TrieDelete(root);			//destroy tree

	return 0;
}

*/