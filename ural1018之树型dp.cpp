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
int head[MAX],size,dp[MAX][MAX],n,m;

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=1;i<=num;++i){
		head[i]=-1;
		dp[i][0]=0;
		for(int j=1;j<=num;++j)dp[i][j]=INF;
	}
	size=0; 
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

int dfs(int u,int father){
	int ans=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(v == father)continue;
		n=dfs(v,u)+1;
		ans+=n;
		for(int j=min(m,ans);j>=1;--j){
			dp[u][j]=min(dp[u][j],dp[u][j-n]+dp[v][n-1]+w);
			for(int k=min(j,n-1);k>=1;--k){
				dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
	return ans;
}

int main(){
	int u,v,w;
	while(cin>>n>>m){
		Init(n);
		int sum=0;
		for(int i=1;i<n;++i){
			cin>>u>>v>>w;
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
			sum+=w;
		}
		m=n-m-1;
		dfs(1,-1);
		cout<<sum-dp[1][m]<<endl;
	}
	return 0;
}