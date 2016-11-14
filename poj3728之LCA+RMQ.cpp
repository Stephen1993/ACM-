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
int n,m,size,top;
int uu[MAX],vv[MAX],ww[MAX],anc[MAX];
int up[MAX][20],down[MAX][20],maxw[MAX][20],minw[MAX][20],deep[MAX];
int head[MAX],head2[MAX],bin[MAX],stack[MAX],mp[MAX][20],father[MAX];
bool mark[MAX];

struct Edge{
	int v,id,next;
	Edge(){}
	Edge(int V,int ID,int NEXT):v(V),id(ID),next(NEXT){}
}edge[MAX*2],edge2[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=-1,mark[i]=false;
	size=top=0;
}

void InsertEdge(int u,int v,int id){
	edge[size]=Edge(v,id,head[u]);
	head[u]=size++;
} 

void InsertEdge2(int u,int v,int id){
	edge2[size]=Edge(v,id,head2[u]);
	head2[u]=size++;
}

void dfs(int u,int father,int k){
	deep[u]=k;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs(v,u,k+1);
	}
}

void RMQ(int u,int father){
	stack[++top]=u;
	int fa=stack[top-1];
	up[u][0]=down[u][0]=0;
	maxw[u][0]=minw[u][0]=ww[u];
	for(int i=1;bin[i]<=top;++i){//2^i<=top
		fa=stack[top-bin[i-1]];
		up[u][i]=max(max(up[u][i-1],up[fa][i-1]),maxw[fa][i-1]-minw[u][i-1]);
		down[u][i]=max(max(down[u][i-1],down[fa][i-1]),maxw[u][i-1]-minw[fa][i-1]);
		maxw[u][i]=max(maxw[u][i-1],maxw[fa][i-1]);
		minw[u][i]=min(minw[u][i-1],minw[fa][i-1]);
		mp[u][i]=stack[top-bin[i]];
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		RMQ(v,u);
	}
	--top;
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void LCA(int u){
	mark[u]=true;
	father[u]=u;
	for(int i=head2[u];i != -1;i=edge2[i].next){
		int v=edge2[i].v,id=edge2[i].id;
		if(!mark[v])continue;
		anc[id]=findset(v);
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(mark[v])continue;
		LCA(v);
		father[v]=u;
	}
}

int search(int x){
	int i=0;
	while(bin[i+1]<=x)++i;
	return i;
}

int Minw(int u,int anc){
	int i=search(deep[u]-deep[anc]+1);
	if(bin[i] == deep[u]-deep[anc]+1)return minw[u][i];
	return min(minw[u][i],Minw(mp[u][i],anc));
}

int Maxw(int u,int anc){
	int i=search(deep[u]-deep[anc]+1);
	if(bin[i] == deep[u]-deep[anc]+1)return maxw[u][i];
	return max(maxw[u][i],Maxw(mp[u][i],anc));
}

int Down(int u,int anc){
	int i=search(deep[u]-deep[anc]+1);
	if(bin[i] == deep[u]-deep[anc]+1)return down[u][i];
	int downfa=Down(mp[u][i],anc);
	downfa=max(downfa,down[u][i]);
	int minwfa=Minw(mp[u][i],anc);
	return max(downfa,maxw[u][i]-minwfa); 
}

int UP(int u,int anc){
	int i=search(deep[u]-deep[anc]+1);
	if(bin[i] == deep[u]-deep[anc]+1)return up[u][i];
	int upfa=UP(mp[u][i],anc);
	upfa=max(upfa,up[u][i]);
	int maxwfa=Maxw(mp[u][i],anc);
	return max(upfa,maxwfa-minw[u][i]);
}

int main(){
	bin[0]=1;
	for(int i=1;bin[i-1]<MAX;++i)bin[i]=bin[i-1]*2;
	int u,v;
	while(~scanf("%d",&n)){
		Init(n);
		for(int i=1;i<=n;++i)scanf("%d",ww+i);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v,i);
			InsertEdge(v,u,i);
		}
		size=0;
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",uu+i,vv+i);
			InsertEdge2(uu[i],vv[i],i);
			InsertEdge2(vv[i],uu[i],i);
		}
		dfs(1,-1,1);
		RMQ(1,-1);
		LCA(1);	
		for(int i=0;i<m;++i){
			int upmax=UP(uu[i],anc[i]),downmax=Down(vv[i],anc[i]);	
			int Minww=Minw(uu[i],anc[i]),Maxww=Maxw(vv[i],anc[i]);
			printf("%d\n",max(max(upmax,downmax),Maxww-Minww));
		}
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