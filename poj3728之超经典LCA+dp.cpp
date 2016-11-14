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
int n,m,size;
int uu[MAX],vv[MAX];
int head[MAX],head2[MAX],head3[MAX];
int down[MAX],up[MAX],maxw[MAX],minw[MAX],ww[MAX],father[MAX],sum[MAX];
bool mark[MAX];

struct Edge{
	int v,id,next;
	Edge(){}
	Edge(int V,int ID,int NEXT):v(V),id(ID),next(NEXT){}
}edge[MAX*2],edge2[MAX*2],edge3[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=head3[i]=-1,mark[i]=false;
	size=0;
}

void InsertEdge(int u,int v,int id){
	edge[size]=Edge(v,id,head[u]);
	head[u]=size++;
}

void InsertEdge2(int u,int v,int id){
	edge2[size]=Edge(v,id,head2[u]);
	head2[u]=size++;
}

void InsertEdge3(int u,int v,int id){
	edge3[size]=Edge(v,id,head3[u]);
	head3[u]=size++;
} 

int findset(int v){
	if(v == father[v])return father[v];
	int fa=father[v];
	father[v]=findset(father[v]);
	up[v]=max(max(up[v],up[fa]),maxw[fa]-minw[v]);
	down[v]=max(max(down[v],down[fa]),maxw[v]-minw[fa]);
	maxw[v]=max(maxw[fa],maxw[v]);
	minw[v]=min(minw[fa],minw[v]);
	return father[v];
}

void LCA(int u){
	mark[u]=true;
	father[u]=u;
	for(int i=head2[u];i != -1;i=edge2[i].next){//对LCA(u,v)进行分类,便于计算以u为最近祖先的点u,v之间的最大利润 
		int v=edge2[i].v,id=edge2[i].id;
		if(!mark[v])continue;
		int f=findset(v);
		InsertEdge3(f,v,id);
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=ww[v];
		if(mark[v])continue;
		LCA(v);
		father[v]=u;
	}
	for(int i=head3[u];i != -1;i=edge3[i].next){//已把所有最近最祖先是u的询问找完,进行计算并且可以利用u的孩子已计算好的值 
		int id=edge3[i].id;
		findset(uu[id]);
		findset(vv[id]);
		sum[id]=max(max(up[uu[id]],down[vv[id]]),maxw[vv[id]]-minw[uu[id]]);
	}
} 

int main(){
	int u,v;
	while(~scanf("%d",&n)){
		Init(n);
		for(int i=1;i<=n;++i){
			scanf("%d",ww+i);
			up[i]=down[i]=0;
			maxw[i]=minw[i]=ww[i];
		} 
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v,i);
			InsertEdge(v,u,i);
		}
		size=0;
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			uu[i]=u,vv[i]=v;
			InsertEdge2(u,v,i);
			InsertEdge2(v,u,i);
		}
		size=0;
		LCA(1);
		for(int i=0;i<m;++i)printf("%d\n",sum[i]);
	}
	return 0;
}
/*
7
300
11
11
21
10
31
222
1 2
2 3
3 4
4 5
2 6
1 7
1
5 6
*/