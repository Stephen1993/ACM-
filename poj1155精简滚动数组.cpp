#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <map>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=3000;
int n,m,size,val[MAX];
int head[MAX],dp[MAX],temp[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX];

void Init(int num){
	for(int i=1;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

int dfs(int u,int Id){
	int last=0,now=0,p=0;
	dp[Id]=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		now=dfs(v,Id+last+1);
		if(v>=n-m+1)++now,p=1;
		else p=0;
		for(int j=last+1;j<=last+now;++j)dp[Id+j]=INF;
		for(int j=last;j>=0;--j){
			for(int k=1;k<=now;++k){
				dp[Id+j+k]=min(dp[Id+j+k],dp[Id+j]+temp[k-p]+w-val[v]);
			}
		}
		last+=now; 
	}
	for(int i=1;i<=last;++i)temp[i]=dp[Id+i];
	return last;
}

int main(){
	int v,w,k;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<=n-m;++i){
			val[i]=0;
			scanf("%d",&k);
			for(int j=1;j<=k;++j){
				scanf("%d%d",&v,&w);
				InsertEdge(i,v,w);
			}
		}
		for(int i=n-m+1;i<=n;++i)scanf("%d",&val[i]);
		dfs(1,0);
		for(int i=m;i>=0;--i){
			if(temp[i]<=0){printf("%d\n",i);break;}
		}
	}
	return 0;
}