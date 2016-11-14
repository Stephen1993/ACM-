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

const int MAX=100000+10;
int n,m,size;
int head[MAX],head2[MAX],dp[MAX],anc[MAX],father[MAX];
bool mark[MAX];

struct Edge{
	int v,id,next;
	Edge(){}
	Edge(int V,int ID,int NEXT):v(V),id(ID),next(NEXT){}
} edge[MAX*2],edge2[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=-1,mark[i]=false,dp[i]=0;
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

void dfs(int u,int Father){
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == Father)continue;
		dfs(v,u);
		dp[u]+=dp[v];
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v,i);
			InsertEdge(v,u,i);
		}
		size=0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge2(u,v,i);
			InsertEdge2(v,u,i);
			++dp[u],++dp[v];
		}
		LCA(1);
		for(int i=0;i<m;++i){
			dp[anc[i]]-=2;//事先减去2,因为TreeDP时dp[ans[i]]会加上2,但是dp[ans[i]]其实不能加2 
		}
		dfs(1,-1);
		LL sum=0;
		for(int i=2;i<=n;++i){
			if(dp[i] == 0)sum+=m;
			if(dp[i] == 1)++sum;
		}
		cout<<sum<<endl;
	}
	return 0;
}