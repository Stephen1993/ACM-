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
#pragma comment(linker,"/STACK:102400000,102400000")

const int MAX=100000+10;
int uu[MAX*2],vv[MAX*2];
int n,m,size,top,index,sum;//sum记录桥的总数 
int head[MAX],dfn[MAX],low[MAX];
int deep[MAX],fa[MAX],pre[MAX],stack[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){} 
}edge[MAX*4];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,deep[i]=dfn[i]=0;
	size=top=index=sum=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int u,int father,int k){
	deep[u]=k;
	pre[u]=u;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs(v,u,k+1);
		fa[v]=u;
		++sum;
	}
}

int findset(int v){
	if(v != pre[v])pre[v]=findset(pre[v]);
	return pre[v];
}

void lca(int u,int v){
	u=findset(u),v=findset(v);
	top=0;
	while(u != v){
		if(deep[u]>deep[v])stack[++top]=u,u=findset(fa[u]);
		else stack[++top]=v,v=findset(fa[v]);
		--sum;
	}
	while(top)pre[stack[top--]]=u;
}

void tarjan(int u,int father){
	if(dfn[u])return;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	bool flag=true;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father && flag){flag=false;continue;}
		tarjan(v,u);
		low[u]=min(low[u],low[v]);
	}
	if(dfn[u] == low[u]){
		while(stack[top] != u)low[stack[top--]]=low[u];
		--top;
	}
}

int main(){
	int u,v,q,num=0;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&uu[i],&vv[i]);
			InsertEdge(uu[i],vv[i]);
			InsertEdge(vv[i],uu[i]);
		}
		tarjan(1,-1);
		for(int i=0;i<=n;++i)head[i]=-1;
		size=0;
		for(int i=0;i<m;++i){//缩点重建图 
			if(low[uu[i]] == low[vv[i]])continue;
			InsertEdge(low[uu[i]],low[vv[i]]);
			InsertEdge(low[vv[i]],low[uu[i]]);
		}
		dfs(low[1],-1,1);//对于缩点后的点求深度
		printf("Case %d:\n",++num);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&u,&v);
			lca(low[u],low[v]);
			printf("%d\n",sum);
		}
		printf("\n");
	}
	return 0;
}
/*
6 5
1 2
1 3
2 4
2 5
4 6
3
4 5
2 3
1 6
6 5
1 2
1 3
2 4
2 5
4 6
3
4 5
2 3
5 6
*/