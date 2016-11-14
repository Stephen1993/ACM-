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

const int MAX=200+10;
int n,k,size;
//dp[u][j][0]表示以u为根的树经过j步没有回到点u得到的最值
//dp[u][j][1]表示以u为根的树经过j步回到点u得到的最值 
int dp[MAX][MAX][2],val[MAX],head[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=1;i<=num;++i){
		head[i]=-1;
		for(int j=1;j<=k;++j)dp[i][j][0]=dp[i][j][1]=0;
	}
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
		for(int j=k;j>=0;--j){
			for(int t=1;j+t<=k;++t){
				dp[u][j+t][0]=max(dp[u][j+t][0],dp[u][j][1]+dp[v][t-1][0]+val[v]);
				if(t>=2)dp[u][j+t][0]=max(dp[u][j+t][0],dp[u][j][0]+dp[v][t-2][1]+val[v]);
				if(t>=2)dp[u][j+t][1]=max(dp[u][j+t][1],dp[u][j][1]+dp[v][t-2][1]+val[v]);
			}
		}
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&k)){
		Init(n);
		for(int i=1;i<=n;++i)scanf("%d",&val[i]);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		dfs(1,-1);
		printf("%d\n",dp[1][k][0]+val[1]);
	}
	return 0;
}