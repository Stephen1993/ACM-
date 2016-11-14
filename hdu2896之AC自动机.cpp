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

const int MAX=10000+10;
char a[210],b[MAX];
int s[5];//记录病毒编号

struct TrieNode{
	int id;//记录病毒序号
	int pos;//表示最后查询该节点的网站
	TrieNode *next[127],*fail;//下一个字母和失败指针
	TrieNode(){
		pos=id=0;
		fail=0;
		memset(next,0,sizeof next);
	} 
}*root;

void InsertNode(char *a,int id){
	int k=0;
	TrieNode *p=root;
	while(a[k]){
		if(!p->next[a[k]])p->next[a[k]]=new TrieNode;
		p=p->next[a[k++]];
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
		for(int i=0;i<127;++i){
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

void SearchTrie(char *a,int id){
	int k=0;
	TrieNode *p=root,*next;
	while(a[k]){
		while(!p->next[a[k]] && p != root)p=p->fail;
		p=p->next[a[k++]];
		if(!p)p=root;
		next=p;
		while(next != root && next->pos != id){//pos=id表示从这开始已经寻找过,用节点的pos标记最后查询过该节点的网站 
			if(next->id)s[++s[0]]=next->id;//有些人另开一个数组标记,但是标记了id=0的就会出错,不标记则查询过的id=0的就会重复查询 
			next->pos=id;
			next=next->fail;
		}
	}
}

void output(int id){
	cout<<"web "<<id<<":";
	sort(s+1,s+1+s[0]);
	for(int i=1;i<=s[0];++i)cout<<' '<<s[i];
	cout<<endl;
}

void Free(TrieNode *p){
	for(int i=0;i<26;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}

int main(){
	int n,num=0;
	while(cin>>n){
		root=new TrieNode;
		num=0;
		for(int i=1;i<=n;++i){
			cin>>a;
			InsertNode(a,i);
		}
		Build_AC();
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>b;
			s[0]=0;
			SearchTrie(b,i);
			if(s[0]){++num;output(i);}
		}
		cout<<"total: "<<num<<endl;
		Free(root);
	}
	return 0;
}