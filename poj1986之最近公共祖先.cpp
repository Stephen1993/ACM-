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

const int MAX=2000000+10;
int n,m,size;
int head[MAX],head2[MAX],dist[MAX],e[MAX],father[MAX];
int mark[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX],edge2[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=-1,mark[i]=0;
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

void InsertEdge2(int u,int v,int w){
	edge2[size]=Edge(v,w,head2[u]);
	head2[u]=size++;
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void LCA(int u,int k){
	mark[u]=k;
	father[u]=u;
	for(int i=head2[u];i != -1;i=edge2[i].next){
		int v=edge2[i].v,w=edge2[i].w;
		if(mark[v] != k)continue;
		int f=findset(v);
		e[w]=dist[u]+dist[v]-dist[f]-dist[f];
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(mark[v])continue;
		dist[v]=dist[u]+w;
		LCA(v,k);
		father[v]=u;
	}
}

int main(){
	int u,v,w,k;
	char s[2];
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d%s",&u,&v,&w,s);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		size=0;
		scanf("%d",&k);
		for(int i=0;i<k;++i){
			scanf("%d%d",&u,&v);
			InsertEdge2(u,v,i);
			InsertEdge2(v,u,i);
		}
		for(int i=1;i<=n;++i)if(!mark[i])dist[i]=0,LCA(1,i);
		for(int i=0;i<k;++i)printf("%d\n",e[i]);
	}
	return 0;
}