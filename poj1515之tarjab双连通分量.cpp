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
int n,m,size,index;
int uu[MAX*MAX],vv[MAX*MAX];
int head[MAX],dfn[MAX],low[MAX];
bool mark[MAX*MAX];

struct Edge{
	int v,id,next;
	Edge(){}
	Edge(int V,int ID,int NEXT):v(V),id(ID),next(NEXT){}
}edge[MAX*MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=0;
	size=index=0;
}

void InsertEdge(int u,int v,int id){
	edge[size]=Edge(v,id,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	if(dfn[u])return;
	dfn[u]=low[u]=++index;
	bool flag=true;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,id=edge[i].id;
		if(v == father && flag){flag=false;continue;}
		tarjan(v,u);
		low[u]=min(low[u],low[v]);
		if(low[v]<=dfn[u] && !mark[id])uu[id]=u,vv[id]=v,mark[id]=true;
	}
}

int main(){
	int num=0;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&uu[i],&vv[i]);
			InsertEdge(uu[i],vv[i],i);
			InsertEdge(vv[i],uu[i],i);
			mark[i]=false;
		}
		tarjan(1,-1);
		printf("%d\n\n",++num);
		for(int i=0;i<m;++i){
			printf("%d %d\n",uu[i],vv[i]);
			if(!mark[i])printf("%d %d\n",vv[i],uu[i]);
		}
		printf("#\n");
	}
	return 0;
}