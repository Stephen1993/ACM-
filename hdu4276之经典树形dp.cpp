#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100+10;
int n,m,size,sum,t; 
int head[MAX],dp[MAX][MAX*5],temp[MAX*5],val[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	memset(temp,0,sizeof temp);
	memset(dp,0,sizeof dp);
	sum=t=size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

void dfs2(int u,int father,int Son){
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=2*edge[i].w;
		if(v == father || v == Son)continue;
		dfs2(v,u,-1);
		for(int j=m+(m&1);j>=0;j-=2){
			for(int k=0;j+k+w<=m;k+=2){
				dp[u][j+k+w]=max(dp[u][j+k+w],dp[u][j]+dp[v][k]+val[v]);
			}
		}
	}
}

void DP(int u,int w){
	sum+=val[u],t+=w;
	for(int j=m+(m&1);j>=0;j-=2){ 
		for(int k=0;j+k<=m;k+=2){
			temp[j+k]=max(temp[j+k],temp[j]+dp[u][k]);
		}
	}
}

bool dfs(int u,int father){
	if(u == n){dfs2(u,father,-1);DP(u,0);return true;}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(v == father)continue;
		if(dfs(v,u)){dfs2(u,father,v);DP(u,w);return true;}
	}
	return false;
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&u,&v,&w);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		for(int i=1;i<=n;++i)scanf("%d",val+i);
		dfs(1,-1);
		if(t>m)printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
		else {
			int ans=0;
			for(int i=0;i<=m-t;++i)if(temp[i]>ans)ans=temp[i];
			printf("%d\n",sum+ans);
		}
	}
	return 0;
}