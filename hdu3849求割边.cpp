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
int n,m,size,top,index;
int uu[MAX*10],vv[MAX*10];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
char a[MAX*10][20],b[MAX*10][15];
map<string,int>mp;

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*20];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=0;
	size=top=index=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	if(dfn[u])return;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		tarjan(v,u);
		low[u]=min(low[u],low[v]);
	}
	if(dfn[u] == low[u]){
		while(stack[top] != u)low[stack[top--]]=low[u];
		--top;
	}
}

int main(){
	int t,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n);
		mp.clear();
		int k=0;
		for(int i=0;i<m;++i){
			scanf("%s%s",a[i],b[i]);
			u=mp[a[i]],v=mp[b[i]];
			if(!u)mp[a[i]]=u=++k;
			if(!v)mp[b[i]]=v=++k;
			uu[i]=u,vv[i]=v;
			InsertEdge(u,v);
			InsertEdge(v,u); 
		}
		tarjan(1,-1);
		int sum=0;
		for(int i=1;i<=n;++i)if(!dfn[i]){sum=-1;break;}
		if(sum == -1){printf("0\n");continue;}
		for(int i=0;i<m;++i){
			if(low[uu[i]] == low[vv[i]])continue;
			++sum;
		}
		printf("%d\n",sum);
		for(int i=0;i<m;++i){
			if(low[uu[i]] != low[vv[i]])printf("%s %s\n",a[i],b[i]);
		}
	}
	return 0;
}