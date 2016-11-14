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
	int num;//记录子串数量
	int id;//记录含有子串的最后的字符串序号
	TrieNode *next[MAX];
	TrieNode(){
		id=num=0;
		memset(next,0,sizeof next);
	}
}root;

void InsertNode(char *a,int id){
	int k=0;
	TrieNode *p=&root;
	while(a[k]){
		if(!p->next[a[k]-'a'])p->next[a[k]-'a']=new TrieNode;
		p=p->next[a[k++]-'a'];
		if(p->id != id)++p->num;
		p->id=id;
	}
}

int SearchTrie(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k] && p->next[a[k]-'a'])p=p->next[a[k++]-'a'];
	if(a[k])return 0;
	return p->num;
}

int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;++i){
			cin>>s;
			int len=strlen(s);
			for(int j=0;j<len;++j)InsertNode(s+j,i);
		}
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>s;
			cout<<SearchTrie(s)<<endl;
		}
	}
	return 0;
}