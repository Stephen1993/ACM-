#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10001;
int size,head[111],n,m,dist[111];
bool mark[111];
typedef pair<int,int>mp;
/*
如果不用pair也可以自己定义一个结构体储存点个距离:
struct node{ 
    int v,dist; 
    node(){} 
    node(int V,int DIST):v(V),dist(DIST){} 
    friend bool operator < (const node a, const node b){ 
            return a.dist > b.dist; 
    } 
}; 
*/

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX];

inline void Init(int num){
	memset(head,-1,sizeof(int)*(num+2));
	size=0;
}

inline void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

inline int Dijkstra(int s,int t){
	for(int i=1;i<=n;++i)mark[i]=false,dist[i]=INF;
	mark[s]=true,dist[s]=0;
	priority_queue< mp,vector<mp>,greater<mp> >enqueue;
	mp outqueue;
	enqueue.push(mp(0,s));
	while(!enqueue.empty()){
		outqueue=enqueue.top();
		enqueue.pop();
		if(outqueue.second == t)return dist[t];
		mark[outqueue.second]=true;
		for(int i=head[outqueue.second];i != -1;i=edge[i].next){
			int v=edge[i].v;
			if(mark[v])continue;
			if(outqueue.first+edge[i].w<dist[v]){
				dist[v]=outqueue.first+edge[i].w;
				enqueue.push(mp(dist[v],v));
			}
		}
	}
	return -1;
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m),n || m){
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