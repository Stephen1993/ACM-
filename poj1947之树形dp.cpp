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

const int MAX=150+10;
int n,m,sum,size,head[MAX];
int dp[MAX],temp[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(int num){
	for(int i=1;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

int dfs(int u,int Id){
	int last=0,now=0;
	dp[Id]=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		now=dfs(v,Id+last+1)+1;
		for(int j=last+1;j<=last+now;++j)dp[Id+j]=INF;
		for(int j=last;j>=0;--j){
			for(int k=1;k<=now;++k){
				dp[Id+j+k]=min(dp[Id+j+k],dp[Id+j]+temp[k-1]);
			}
			dp[Id+j]=dp[Id+j]+1;//k=0表示以点v为根的子树全部删除,只要删除u->v的枝干就行 
		}
		last+=now;
	}
	for(int i=0;i<=last;++i)temp[i]=dp[Id+i];
	if(last+1>=m)sum=min(sum,dp[Id+m-1]+1);//以点u作为根保留m个点需要删除的最少边 
	return last;
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
		}
		sum=INF;
		dfs(1,0);
		printf("%d\n",min(sum,dp[m-1]));
	}
	return 0;
}
/*
input:
12 7
1 11
1 12
1 2
2 3
2 4
4 5
4 8
5 6
5 7
8 9
8 10
output:
1
*/