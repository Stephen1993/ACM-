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
char s[MAX];

struct TrieNode{
	int num;
	TrieNode *next[MAX];
	TrieNode(){
		num=0;
		memset(next,NULL,sizeof next);
	}
}root;

void InsertNode(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k]){
		if(!p->next[a[k]-'a'])p->next[a[k]-'a']=new TrieNode;
		p=p->next[a[k++]-'a'];
		++p->num;
	}
}

int SearchNode(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k] && p->next[a[k]-'a'])p=p->next[a[k++]-'a'];
	return a[k]?0:p->num;
}

int main(){
	while(gets(s),s[0] != '\0')InsertNode(s);
	while(cin>>s)cout<<SearchNode(s)<<endl;
	return 0;
}