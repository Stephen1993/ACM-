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
int n,m,size;
int head[MAX],head2[MAX],father[MAX],sum[MAX*100],dist[MAX];
int mark[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2],edge2[MAX*200];

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
		sum[w]=dist[u]+dist[v]-dist[f]-dist[f];
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(mark[v] == k)continue;
		dist[v]=dist[u]+w;
		LCA(v,k);
		father[v]=u;
	}
}

int main(){
	int q,u,v,w;
	while(~scanf("%d%d%d",&n,&m,&q)){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u,&v,&w);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		size=0;
		for(int i=0;i<q;++i){
			scanf("%d%d",&u,&v);
			InsertEdge2(u,v,i);
			InsertEdge2(v,u,i);
			sum[i]=-1;
		}
		for(int i=1;i<=n;++i)if(!mark[i])dist[i]=0,LCA(i,i);//ÀëÏßLCA
		for(int i=0;i<q;++i){
			if(sum[i] == -1)printf("Not connected\n");
			else printf("%d\n",sum[i]);
		}
	}
	return 0;
}