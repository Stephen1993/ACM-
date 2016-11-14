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

const int MAX=10000+10;
int n,m,size,top,index;
int uu[MAX*5],vv[MAX*5];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],oud[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*5];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,oud[i]=mark[i]=0;
	size=top=index=0;
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
	if(low[u] == dfn[u]){
		while(stack[top] != u)mark[stack[top]]=-1,low[stack[top--]]=low[u];
		mark[u]=-1;
		--top;
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&uu[i],&vv[i]);
			InsertEdge(uu[i],vv[i]);
		}
		for(int i=1;i<=n;++i)tarjan(i);
		for(int i=0;i<m;++i){
			if(low[uu[i]] == low[vv[i]])continue;
			++oud[low[uu[i]]];
		}
		int sum=0,ans=0;
		for(int i=1;i<=n;++i){
			if(oud[low[i]])continue;
			++sum;
			if(mark[low[i]] != 2)++ans;
			mark[low[i]]=2;
		}
		if(ans == 1)cout<<sum<<endl;
		else cout<<0<<endl;
	}
	return 0;
}