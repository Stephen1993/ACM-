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
#define INF 999999999
typedef long long LL;
using namespace std;

const int MAX=10000+10;
int n,m,size,top,index;
int uu[MAX*10],vv[MAX*10],ww[MAX*10],ind[MAX];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*20];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,ind[i]=dfn[i]=0;
	size=top=index=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
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

int dfs(int u,int father){
	int num=0,v,w;
	for(int i=head[u];i != -1;i=edge[i].next){
		if(edge[i].v == father)continue;
		v=edge[i].v,w=edge[i].w;
		++num;
		if(num>1)break;
	}
	if(num == 1)return min(w,dfs(v,u));
	return INF;
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&uu[i],&vv[i],&ww[i]);
			InsertEdge(uu[i],vv[i],ww[i]);
			InsertEdge(vv[i],uu[i],ww[i]);
		}
		tarjan(1,-1);//缩点 
		for(int i=0;i<=n;++i)head[i]=-1;
		size=0;
		for(int i=0;i<m;++i){//缩点重建图 
			if(low[uu[i]] == low[vv[i]])continue;
			++ind[low[uu[i]]],++ind[low[vv[i]]];
			InsertEdge(low[uu[i]],low[vv[i]],ww[i]);
			InsertEdge(low[vv[i]],low[uu[i]],ww[i]);
		}
		int a=INF,b=INF,c=INF;
		for(int i=1;i<=n;++i){
			if(ind[i] != 1)continue;
			int sum=dfs(i,-1);
			if(sum<a)c=b,b=a,a=sum;
			else if(sum<b)c=b,b=sum;
			else if(sum<c)c=sum;
		}
		if(c == INF)printf("-1\n");
		else printf("%d\n",c);
	}
	return 0;
}