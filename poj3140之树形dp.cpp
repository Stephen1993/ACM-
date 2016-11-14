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

const int MAX=100000+10;
int n,m,size;
int head[MAX];
LL sum,ans,val[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	sum=size=0; 
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

LL Abs(LL a){
	return a>0 ? a : (-a);
}

LL dfs(int u,int father){
	LL dp=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dp+=dfs(v,u);
	}
	dp+=val[u];
	if(Abs(sum-dp-dp)<ans)ans=Abs(sum-dp-dp);
	return dp;
}

int main(){
	int u,v,num=0;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=1;i<=n;++i)scanf("%lld",&val[i]),sum+=val[i];
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		ans=sum;
		dfs(1,-1);
		printf("Case %d: %lld\n",++num,ans);
	}
	return 0;
}