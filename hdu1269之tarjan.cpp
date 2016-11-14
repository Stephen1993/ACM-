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

const int MAX=10000+10;
int n,m,size,Index,sum;
int head[MAX],dfn[MAX],low[MAX];//dfn记录节点出现的时间,low记录节点能到达的最早祖先(包括自己) 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*10];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=0;
	size=Index=sum=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u){
	if(dfn[u])return;//表示该点在u之前访问过 
	dfn[u]=low[u]=++Index;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		tarjan(v);
		low[u]=min(low[u],low[v]);
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
		}
		tarjan(1);//dfs,任意两个房间相连表示整个图强连通,这里因为只要判断所以只需要搜索一次即可,如果要求出多少个强连通分量,则要对所有点全部搜索防止图是个森林 
		for(int i=1;i<=n;++i)if(dfn[i] == low[i] || !dfn[i])++sum;//表示该点是某个强联通分量的根(多个连通分量不用考虑,sum肯定>1)
		if(sum == 1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
/*
5 6
1 2
2 3
3 5
3 4
4 2
5 1
*/