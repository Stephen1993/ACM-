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

const int MAX=1500+10;
int n,size;
int head[MAX],temp[2];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int u,int father){
	int dp[2]={0,0};//dp[0]表示当前点不放士兵,dp[1]表示当前点放士兵 
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs(v,u);
		dp[0]=dp[0]+temp[1];
		dp[1]=dp[1]+min(temp[0],temp[1]);
	}
	temp[0]=dp[0];
	temp[1]=dp[1]+1;
	return;
}

int main(){
	int k,u,v;
	while(~scanf("%d",&n)){
		Init(n);
		for(int i=0;i<n;++i){
			scanf("%d:(%d)",&u,&k);
			for(int j=0;j<k;++j){
				scanf("%d",&v);
				InsertEdge(u,v);
				InsertEdge(v,u);
			}
		}
		dfs(0,-1);
		printf("%d\n",min(temp[0],temp[1]));
	}
	return 0;
}