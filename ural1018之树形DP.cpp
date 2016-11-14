#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100+10;
int head[MAX],size,n,m;
int dp[MAX][MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
} edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	memset(dp,0,sizeof dp);
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

int dfs(int u,int father){
	int ans=0;//u的子树有多少分支 
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(v == father)continue;
		ans+=dfs(v,u)+1;
		for(int j=min(ans,m);j>=1;--j){
			for(int k=min(j,ans);k>=1;--k){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k-1]+w);
			}
		}
	}
	return ans;
}

int main(){
	int u,v,w;
	while(cin>>n>>m){
		Init(n);
		for(int i=1;i<n;++i){
			cin>>u>>v>>w;
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		dfs(1,-1);
		cout<<dp[1][m]<<endl;
	}
	return 0;
}