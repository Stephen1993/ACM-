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
int n,size,sum;
int head[MAX],dp[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=0;
	sum=INF;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

int dfs(int u,int father){
	int last=0,num=0,temp=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		num=dfs(v,u);
		if(temp<num)temp=num;
		last+=num;
	}
	if(n-last-1>temp)temp=n-last-1;
	if(temp<sum)sum=temp;
	dp[u]=temp;
	return last+1;
}

int main(){
	int u,v;
	while(~scanf("%d",&n)){
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		dfs(1,-1);
		for(int i=1;i<=n;++i){
			if(sum == dp[i]){
				if(u == INF)printf(" ");
				printf("%d",i);
				u=INF;
			}
		}
		printf("\n");
	}
	return 0;
}