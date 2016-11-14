#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=26;
typedef struct TrieNode{
	int num;
	TrieNode *next[MAX];
    TrieNode(){
    	num=0;
    	memset(next,NULL,sizeof next);
    }
};
TrieNode root;
void InsertNode(char *s){
	int k=0;
	TrieNode *p=&root;
	while(s[k]){
		if(!p->next[s[k]-'a']){
			p->next[s[k]-'a']=new TrieNode;
		}
		p=p->next[s[k]-'a'];
		p->num++;
		k++;
	}
}
int SearchTrie(char *s){
	TrieNode *p=&root;
	int k=0;
	while(s[k]&&p->next[s[k]-'a']){
		p=p->next[s[k++]-'a'];
	}
	return s[k]?0:p->num;
}
int main(){
	char s[11];
	while(gets(s),s[0]!='\0'){
		InsertNode(s);
	}
	while(scanf("%s",s)!=EOF){
		printf("%d\n",SearchTrie(s));
	}
	return 0;
}
/*模板
代码

#include <stdio.h>
#define  MAX    26 

typedef struct TrieNode
{
    int nCount; 
    struct TrieNode *next[MAX];
}TrieNode;

TrieNode Memory[1000000];
int allocp = 0;

void InitTrieRoot(TrieNode **pRoot)
{
    *pRoot = NULL;
}

TrieNode *CreateTrieNode()
{
    int i;
    TrieNode *p;

    p = &Memory[allocp++];
    p->nCount = 1;
    for(i = 0 ; i < MAX ; i++)
    {
        p->next[i] = NULL;
    }

    return p;
}

void InsertTrie(TrieNode **pRoot , char *s)
{
    int i , k;
    TrieNode *p;

    if(!(p = *pRoot))
    {
        p = *pRoot = CreateTrieNode();
    }
    i = 0;
    while(s[i])
    {
        k = s[i++] - 'a'; //确定branch
        if(p->next[k])
            p->next[k]->nCount++;
        else
            p->next[k] = CreateTrieNode();
        p = p->next[k];
    }
}

int SearchTrie(TrieNode **pRoot , char *s)
{
    TrieNode *p;
    int i , k;

    if(!(p = *pRoot))
    {
        return 0;
    }
    i = 0;
    while(s[i])
    {
        k = s[i++] - 'a'; 
        if(p->next[k] == NULL)    return 0;
        p = p->next[k];
    }
    return p->nCount;
}
    
int main(void)
{
    char s[11];    
    
    TrieNode *Root = NULL;   
    InitTrieRoot(&Root);    
    while(gets(s) && s[0])  
    {       
        InsertTrie(&Root , s); 
    }    

    while(gets(s))   
    {        
        printf("%d\n", SearchTrie(&Root , s));   
    }    
    
    return    0;
}
*/ 