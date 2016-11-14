#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100+10;
int n,size,top,index,sum;
int uu[MAX*MAX],vv[MAX*MAX];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],ind[MAX],oud[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,ind[i]=oud[i]=mark[i]=0;
	size=top=index=sum=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u){
	if(mark[u])return;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	mark[u]=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		tarjan(v);
		if(mark[v] == 1)low[u]=min(low[u],low[v]);
	}
	if(dfn[u] == low[u]){
		++sum;
		while(stack[top] != u)mark[stack[top]]=-1,low[stack[top--]]=low[u];
		mark[u]=-1;
		--top;
	}
}

int main(){
	int v,k;
	while(~scanf("%d",&n)){
		Init(n);
		k=0;
		for(int i=1;i<=n;++i){
			while(cin>>v,v)uu[k]=i,vv[k++]=v,InsertEdge(i,v);
		}
		for(int i=1;i<=n;++i)tarjan(i);
		for(int i=0;i<k;++i){
			if(low[uu[i]] == low[vv[i]])continue;
			++ind[low[vv[i]]],++oud[low[uu[i]]];
		}
		int a=0,b=0;
		for(int i=1;i<=n;++i){
			if(ind[low[i]] == 0)++a,ind[low[i]]=1;
			if(oud[low[i]] == 0)++b,oud[low[i]]=1;
		}
		cout<<a<<endl;
		if(sum == 1)cout<<0<<endl;
		else cout<<max(a,b)<<endl;
	}
	return 0;
}