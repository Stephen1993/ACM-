#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10001;
int n,m,size,dist[111];
bool mark[111];
typedef pair<int,int>mp;

struct Edge{
	int v,w;
	Edge *next;
	Edge(){}
	Edge(int V,int W,Edge *NEXT):v(V),w(W),next(NEXT){}
}edge[MAX],*head[111];

inline void Init(int num){
	memset(head,0,sizeof(Edge*)*(num+2));
	size=0;
}

inline void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=&edge[size++];
}

inline int Dijkstra(int s,int t){
	for(int i=0;i<=n;++i)mark[i]=false,dist[i]=INF;
	mark[s]=true,dist[s]=0;
	priority_queue< mp,vector<mp>,greater<mp> >enqueue;
	enqueue.push(mp(0,s));
	mp outqueue;
	while(!enqueue.empty()){
		outqueue=enqueue.top();
		enqueue.pop();
		if(outqueue.second == t)return dist[t];
		mark[outqueue.second]=true;
		for(Edge *u=head[outqueue.second];u;u=u->next){
			if(outqueue.first+u->w<dist[u->v]){
				dist[u->v]=outqueue.first+u->w;
				enqueue.push(mp(dist[u->v],u->v));
			}
		}
	}
	return -1;
}

int main(){
	int u,v,w;
	while(scanf("%d%d",&n,&m),n || m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u,&v,&w);
			InsertEdge(u,v,w);
			InsertEdge(v,u,w);
		}
		printf("%d\n",Dijkstra(1,n));
	}
	return 0;
}