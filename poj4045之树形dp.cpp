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
int n,size;
int head[MAX],dp[MAX];
LL I,R,sum,val[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dp[i]=val[i]=0;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int u,int father){
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs(v,u);
		dp[u]+=dp[v];
		val[u]+=val[v]+dp[v];
	}
	++dp[u];
	return;
}

void dfs2(int u,int father){
	val[u]=val[father]+n-dp[u]-dp[u];//val[u]=val[father]-val[u]-dp[u]+val[u]+n-dp[u]
	if(val[u]<sum)sum=val[u];
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs2(v,u);
	}
}

int main(){
	int t,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld%lld",&n,&I,&R);
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		dfs(1,-1);
		val[0]=(sum=val[1])+n;
		dfs2(1,0);
		printf("%lld\n",I*I*R*sum);
		for(int i=1;i<=n;++i){
			if(val[i] == sum){
				if(u == INF)printf(" ");
				printf("%d",i);
				u=INF;
			}
		}
		printf("\n\n");
	}
	return 0;
}