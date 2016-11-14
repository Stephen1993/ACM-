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

const int MAX=50000+10;
int n,m,size,top,index;
int u[MAX*2],v[MAX*2],w[MAX*2];
int head[MAX],dfn[MAX],low[MAX],dp[MAX];
int mark[MAX],stack[MAX];
bool ind[MAX];//ind标记缩点后的点是否有入度 

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,mark[i]=0,dp[i]=INF;
	size=top=index=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
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
		while(stack[top] != u){
			mark[stack[top]]=-1;
			low[stack[top--]]=low[u];
		}
		mark[u]=-1;
		--top;
	}
}

void dfs(int u){
	if(mark[u])return;
	mark[u]=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(w<dp[v])dp[v]=w;
		dfs(v);	
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			InsertEdge(u[i],v[i],w[i]);
		}
		for(int i=0;i<n;++i){//求连通分量进行缩点 
			if(mark[i])continue;
			tarjan(i);
		}
		
		for(int i=0;i<=n;++i)head[i]=-1,ind[i]=false,mark[i]=0;
		size=0;
		for(int i=0;i<m;++i){//缩点重建图 
			if(low[u[i]] == low[v[i]])continue;
			ind[low[v[i]]]=true;
			InsertEdge(low[u[i]],low[v[i]],w[i]);
		}
		for(int i=0;i<n;++i){
			if(!ind[low[i]])dp[low[i]]=0,dfs(low[i]);
			ind[low[i]]=true;
		}
		int sum=0;
		for(int i=0;i<n;++i){
			if(ind[low[i]])sum+=dp[low[i]];
			ind[low[i]]=false;
		}
		cout<<sum<<endl;
	}
	return 0;
}