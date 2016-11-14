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

const int MAX=400000+10;
int n,m,size;
int head[MAX],head2[MAX],fa[MAX],dist[MAX],e[MAX][3];
bool mark[MAX];

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2],edge2[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=-1,mark[i]=false;
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

void InsertEdge2(int u,int v,int w){//在这里w表示的是该边的下标 
	edge2[size]=Edge(v,w,head2[u]);
	head2[u]=size++;
}

int findset(int v){
	if(v != fa[v])fa[v]=findset(fa[v]);
	return fa[v];
}

void LCA(int u){
	mark[u]=true;
	fa[u]=u;
	for(int i=head2[u];i != -1;i=edge2[i].next){//求u,v的最近公共祖先 
		int v=edge2[i].v,w=edge2[i].w;
		if(!mark[v])continue;
		e[w][2]=findset(v);
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		if(mark[v])continue;
		dist[v]=dist[u]+w;
		LCA(v);//寻找和v相连的点的最近公共祖先
		fa[v]=u; 
	}
}

int main(){
	int t,u,v,w;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&u,&v,&w);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		size=0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge2(u,v,i);
			InsertEdge2(v,u,i);
			e[i][0]=u,e[i][1]=v;
		}
		dist[1]=0;
		LCA(1);//离线LCA
		for(int i=0;i<m;++i){
			printf("%d\n",dist[e[i][0]]+dist[e[i][1]]-dist[e[i][2]]-dist[e[i][2]]);
		}
	}
	return 0;
}