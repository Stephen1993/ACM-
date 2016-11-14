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

const int MAX=10;
char s[MAX+2];
bool flag;

struct TrieNode{
	bool mark;
	TrieNode *next[MAX];
	TrieNode(){
		mark=false;
		memset(next,0,sizeof next);
	}
}root;

void InsertNode(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k]){
		if(!p->next[a[k]-'0'])p->next[a[k]-'0']=new TrieNode;
		else if(a[k+1] == '\0')flag=false;
		p=p->next[a[k++]-'0'];
		if(p->mark)flag=false;
	}
	p->mark=true;
}

void Free(TrieNode *p){
	for(int i=0;i<MAX;++i){
		if(p->next[i])Free(p->next[i]);
	}
	delete p;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		flag=true;
		while(n--){
			cin>>s;
			if(flag)InsertNode(s);
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		for(int i=0;i<MAX;++i){
			if(root.next[i])Free(root.next[i]);
			root.next[i]=NULL;
		}
	}
	return 0;