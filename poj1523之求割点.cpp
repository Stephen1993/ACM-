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

const int MAX=1000+10;
int size,index;
int head[MAX],dfn[MAX],low[MAX],sum[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,sum[i]=1,dfn[i]=0;
	size=index=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	if(dfn[u])return;
	dfn[u]=low[u]=++index;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		if(!dfn[v]){
			tarjan(v,u);
			if(low[v]>=dfn[u])++sum[u];
		}
		low[u]=min(low[u],low[v]);
	}
}

int main(){
	int u,v,num=0;
	while(cin>>u,u){
		Init(1000);
		cin>>v;
		InsertEdge(u,v);
		InsertEdge(v,u);
		while(cin>>u,u){
			cin>>v;
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		sum[1]=0;
		tarjan(1,-1);
		printf("Network #%d\n",++num);
		bool flag=true;
		for(int i=1;i<=1000;++i){
			if(sum[i]>1){
				printf("  SPF node %d leaves %d subnets\n",i,sum[i]);
				flag=false;
			}
		}
		if(flag)printf("  No SPF nodes\n");
		cout<<endl;
	}
	return 0;
}