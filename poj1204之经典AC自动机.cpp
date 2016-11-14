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

const int MAX=1000+10;
char s[MAX][MAX],b[MAX];
int n,m,w;
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,1,-1,-1,1};//八个方向
char ch[9]="CGEADHFB";
int pos[MAX][3];

struct TrieNode{
	int id;//记录第几个字符串 
	TrieNode *next[26],*fail;
	TrieNode(){
		id=0;
		fail=0;
		memset(next,0,sizeof next);
	}
}*root;

void InsertNode(char *a,int id){
	int len=strlen(a)-1;
	TrieNode *p=root;
	while(len>=0){//这里将a数组倒着插入字典树,方便匹配时记录匹配的终点即原串的起始点
		if(!p->next[a[len]-'A'])p->next[a[len]-'A']=new TrieNode;
		p=p->next[a[len--]-'A'];
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
		for(int i=0;i<26;++i){
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

void SearchTrie(int x,int y,int d,int id){
	TrieNode *p=root,*next; 
	while(x>=0 && y>=0 && x<n && y<m){
		while(p && !p->next[s[x][y]-'A'])p=p->fail;
		if(!p)p=root;
		else p=p->next[s[x][y]-'A'];
		next=p;
		while(next != root){
			if(next->id){//记录原串被匹配的起始点
				int k=next->id;
				if(pos[k][0]>x || (pos[k][0] == x && pos[k][1]>y)){
					pos[k][0]=x,pos[k][1]=y,pos[k][2]=id;
				} 
			} 
			next=next->fail; 
		}
		x+=dir[d][0];
		y+=dir[d][1];
	}
}

void Free(TrieNode *p){
	for(int i=0;i<26;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}

int main(){
	while(cin>>n>>m>>w){
		root=new TrieNode;
		for(int i=0;i<n;++i)cin>>s[i];
		for(int i=1;i<=w;++i){
			cin>>b;
			InsertNode(b,i);
			pos[i][0]=pos[i][1]=INF;
		}
		Build_AC();
		for(int i=0;i<n;++i){
			SearchTrie(i,0,0,1),SearchTrie(i,m-1,1,0);//匹配左右方向
			SearchTrie(i,0,7,6),SearchTrie(i,m-1,6,7);//匹配左上部分的右上角和右下部分左下角
			SearchTrie(i,0,4,5),SearchTrie(i,m-1,5,4);//匹配左下部分右下角和右上部分左上角
		}
		for(int i=0;i<m;++i){
			SearchTrie(0,i,2,3),SearchTrie(n-1,i,3,2);//匹配上下方向
			SearchTrie(0,i,6,7),SearchTrie(n-1,i,7,6);//匹配左上部分左下角和右下部分右上角
			SearchTrie(0,i,4,5),SearchTrie(n-1,i,5,4);//匹配右上部分的右下角和左下部分左上角 
		}
		for(int i=1;i<=w;++i)cout<<pos[i][0]<<' '<<pos[i][1]<<' '<<ch[pos[i][2]]<<endl;
		Free(root);
	}
	return 0;
}