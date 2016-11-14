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

const int MAX=3000+10;
int head[MAX],size,n,m;
int val[MAX],dp[MAX][MAX];//dp记录以u为根的子树供给j个用户亏损的最少钱

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=1;i<=num;++i){
		head[i]=-1;
		for(int j=1;j<=num;++j)dp[i][j]=INF;
	}
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

int dfs(int u,int father){
	int ans=0,p,now;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(v == father)continue;
		now=dfs(v,u);
		if(v>=n-m+1)++now,p=1;
		else p=0;
		ans+=now;
		for(int j=min(m,ans);j>=1;--j){//这里注意一定要j=min(m,ans),复杂度为O(n^3)=>接近O(n^2)
			for(int k=min(j,now);k>=1;--k){//以u为根的子树供给给j个用户并且有k个用户属于v为根的子树时亏损的最少钱
				dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k-p]+w-val[v]);
			}
		}
	}
	return ans;
}

int main(){
	int k,v,w;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<=n-m;++i){
			scanf("%d",&k);
			val[i]=0;
			for(int j=1;j<=k;++j){
				scanf("%d%d",&v,&w);
				InsertEdge(i,v,w);
				InsertEdge(v,i,w);
			}
		}
		for(int i=n-m+1;i<=n;++i)scanf("%d",&val[i]);
		dfs(1,-1);
		int sum=0;
		for(n=1;n<=m;++n)if(dp[1][n]<=0)sum=n;
        printf("%d\n",sum);
	}
	return 0;
}
