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

const int MAX=100000+10;
int n,m,size,index;
int head[MAX],dfn[MAX],low[MAX],sum[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*20];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,sum[i]=1,dfn[i]=0;
	size=index=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	dfn[u]=low[u]=++index;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])++sum[u];
		}else low[u]=min(low[u],dfn[v]);
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		int ans=0,num=-1;
		for(int i=0;i<n;++i){
			if(dfn[i])continue;
			sum[i]=0;
			++num;
			tarjan(i,-1);
		}
		for(int i=0;i<n;++i)ans=max(ans,sum[i]);
		printf("%d\n",ans+num);
	}
	return 0;
}