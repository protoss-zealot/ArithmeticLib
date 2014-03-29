/* This is the header file of trie tree */


#ifndef _TRIE_H_H
#define _TRIE_H_H


const int sonnum=26;
const int base='a';

struct Trie{
	int num;
	bool terminal;
	struct Trie *son[sonnum];
};

extern Trie *NewTrie();

extern void TrieDelete(Trie *pnt);

extern void TrieInsert(Trie *pnt,char *s,int len);

extern Trie *TrieFind(Trie *pnt,char *s,int len)

#endif