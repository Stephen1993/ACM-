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

const int MAX=1000+10;
int n,m,size,top,index,sum;
int uu[MAX*6],vv[MAX*6];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],dp[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*6];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dp[i]=mark[i]=0;
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

int dfs(int u){
	if(dp[u])return dp[u];
	int num=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		num=max(num,dfs(v));
	}
	return dp[u]=num+1;
}

int main(){
	int t,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&uu[i],&vv[i]);
			InsertEdge(uu[i],vv[i]);
		}
		for(int i=1;i<=n;++i)tarjan(i);//缩点 
		for(int i=1;i<=n;++i)head[i]=-1;
		size=0;
		for(int i=0;i<m;++i){//缩点后重建图 
			if(low[uu[i]] == low[vv[i]])continue;
			InsertEdge(low[uu[i]],low[vv[i]]);
		}
		bool flag=false;
		for(int i=1;i<=n;++i){
			if(dfs(low[i]) == sum){flag=true;break;}
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}