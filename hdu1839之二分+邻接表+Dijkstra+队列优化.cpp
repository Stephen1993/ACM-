#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10000+10;
int s[MAX*5],n,m,t;
int size,head[MAX],dist[MAX];
bool mark[MAX];
typedef pair<int,int>mp;

struct Edge{
	int v,c,t,next;
	Edge(){}
	Edge(int &V,int &C,int &T,int NEXT):v(V),c(C),t(T),next(NEXT){}
}edge[MAX*5*2];

inline void Init(int num){
	memset(head,-1,sizeof(int)*(num+2));
	size=0;
}

inline void InsertEdge(int u,int v,int &c,int &t){
	edge[size]=Edge(v,c,t,head[u]);//头插法
	head[u]=size++; 
}

inline bool Dijkstra(int s,int t,int c,int T){
	for(int i=1;i<=n;++i)mark[i]=false,dist[i]=INF;
	dist[s]=0,mark[s]=true;
	priority_queue< mp,vector<mp>,greater<mp> >q;
	mp oq;
	q.push(mp(0,s));
	while(!q.empty()){
		oq=q.top();
		q.pop();
		if(oq.first>T)return false;
		if(oq.second == t)return dist[t];//dist[t]<=T;
		mark[oq.second]=true;
		for(int i=head[oq.second];i != -1;i=edge[i].next){
			int v=edge[i].v;
			if(mark[v] || edge[i].c<c)continue;
			if(oq.first+edge[i].t<dist[v]){
				dist[v]=oq.first+edge[i].t;
				q.push(mp(dist[v],v));
			}
		}
	}
	return false;//无法到达t 
}

int main(){
	int num,u,v,c,T;
	cin>>num;
	while(num--){
		scanf("%d%d%d",&n,&m,&t);
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&u,&v,&c,&T);
			InsertEdge(u,v,c,T);
			InsertEdge(v,u,c,T);
			s[i]=c;
		}
		sort(s,s+m);
		int left=0,right=0,mid;
		for(int i=1;i<m;++i)if(s[i] != s[i-1])s[++right]=s[i];
		while(left<=right){
			mid=left+right>>1;
			if(Dijkstra(1,n,s[mid],t))left=mid+1;
			else right=mid-1;
		}
		printf("%d\n",s[right]);
	}
	return 0;
}