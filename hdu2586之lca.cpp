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

const int MAX=40000+10;
int n,m,size;
int head[MAX],deep[MAX],fa[MAX][2];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

void dfs(int u,int father,int k){
	deep[u]=k;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(v == father)continue;
		dfs(v,u,k+1);
		fa[v][0]=u;
		fa[v][1]=w;
	}
}

int lca(int u,int v){
	int sum=0;
	while(u != v){
		if(deep[u]>=deep[v])sum+=fa[u][1],u=fa[u][0];
		else sum+=fa[v][1],v=fa[v][0];
	}
	return sum;
}

int main(){
	int t,u,v,w;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&u,&v,&w);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		dfs(1,-1,1);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			printf("%d\n",lca(u,v));
		}
	}
	return 0;
}