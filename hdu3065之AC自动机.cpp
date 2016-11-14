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

const int MAX=2000000+10;
char a[1010][60],b[MAX];
int num[1010];

struct TrieNode{
	int id; 
	TrieNode *next[95],*fail;//下一个字符和失败指针,可见字符ASCII为33~126,32是空格 
	TrieNode(){
		id=-1; 
		fail=0;
		memset(next,0,sizeof next);
	} 
}*root;

void InsertNode(char *a,int id){
	int k=0;
	TrieNode *p=root;
	while(a[k]){
		if(!p->next[a[k]-' '])p->next[a[k]-' ']=new TrieNode;
		p=p->next[a[k++]-' '];
	}
	p->id=id;
}

void Build_AC(){
	TrieNode *p=root,*next;
	queue<TrieNode *>q;
	q.push(root);
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=0;i<95;++i){
			if(p->next[i]){
				next=p->fail;
				while(next && !next->next[i])next=next->fail;
				if(next)p->next[i]->fail=next->next[i];
				else p->next[i]->fail=root;
				q.push(p->next[i]);
			}
		}
	}
}

void SearchTrie(char *a){
	int k=0;
	TrieNode *p=root,*next;
	while(a[k]){
		while(!p->next[a[k]-' '] && p != root)p=p->fail;
		p=p->next[a[k++]-' '];
		if(!p)p=root;
		next=p;
		while(next != root){
			if(next->id>=0)++num[next->id];
			next=next->fail;
		}
	}
}

void output(int n){
	for(int i=0;i<n;++i){
		if(num[i]){
			cout<<a[i]<<": "<<num[i]<<endl;
		}
	}
}

void Free(TrieNode *p){
	for(int i=0;i<95;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}

int main(){
	int n;
	while(cin>>n){
		memset(num,0,sizeof num);
		root=new TrieNode;
		for(int i=0;i<n;++i){
			cin>>a[i];
			InsertNode(a[i],i);
		}
		Build_AC();
		cin>>b;
		SearchTrie(b);
		output(n);
		Free(root);
	}
	return 0;
}