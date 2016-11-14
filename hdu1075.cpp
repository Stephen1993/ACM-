#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=26;
char a[1000002][12],b[3002],c[12];

struct TrieNode{
	int k;
	TrieNode *next[MAX];
	TrieNode(){
		k=-1;
		memset(next,0,sizeof next);
	}
}root;

void InsertNode(char *s,int pos){
	int k=0;
	TrieNode *p=&root;
	while(s[k]){
		if(!p->next[s[k]-'a'])p->next[s[k]-'a']=new TrieNode;
		p=p->next[s[k++]-'a'];
	}
	p->k=pos;
}

char *SearchTrie(char *s){
	int k=0;
	TrieNode *p=&root;
	while(s[k] && p->next[s[k]-'a'])p=p->next[s[k++]-'a'];
	if(!s[k] && p->k != -1)return a[p->k];
	return s;
}

int main(){
	int k=0,i;
	scanf("%s%*c",c);
	while(scanf("%s",a[k]),a[k][0] != 'E'){
		scanf("%s",c);
		InsertNode(c,k++);
	}
	scanf("%s%*c",c);
	while(gets(b),b[0] != 'E'){
		for(k=i=0;b[k];++k){
			if(b[k]>='a' && b[k]<='z')c[i++]=b[k];
			else{
				c[i]='\0';
				i=0;
				cout<<SearchTrie(c)<<b[k];
			} 
		}
		if(b[k-1] >='a' && b[k-1]<='z'){c[i]='\0';cout<<SearchTrie(c);}
		cout<<endl;
	}
	return 0;
}