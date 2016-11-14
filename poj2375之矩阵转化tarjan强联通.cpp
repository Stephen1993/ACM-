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

const int MAX=250000+10;
int n,m,size,top,index,sum;
int s[2][510],uu[MAX*4],vv[MAX*4];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],ind[MAX],oud[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*4];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,ind[i]=oud[i]=mark[i]=0;
	size=top=index=sum=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u){
	if(mark[u])return;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	mark[u]=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		tarjan(v);
		if(mark[v] == 1)low[u]=min(low[u],low[v]);
	}
	if(dfn[u] == low[u]){
		++sum;
		while(stack[top] != u)mark[stack[top]]=-1,low[stack[top--]]=low[u];
		mark[u]=-1;
		--top;
	}
}

int main(){
	int w,l;
	while(~scanf("%d%d",&w,&l)){
		n=w*l;
		Init(n);
		int k=0;
		for(int i=1;i<=l;++i){
			for(int j=1;j<=w;++j){
				scanf("%d",&s[i&1][j]);
				if(i-1){
					if(s[(i-1)&1][j]>=s[i&1][j]){uu[k]=(i-2)*w+j;vv[k]=(i-1)*w+j;InsertEdge(uu[k],vv[k]);++k;}
					if(s[(i-1)&1][j]<=s[i&1][j]){uu[k]=(i-1)*w+j;vv[k]=(i-2)*w+j;InsertEdge(uu[k],vv[k]);++k;}
				}
				if(j-1){
					if(s[i&1][j-1]>=s[i&1][j]){uu[k]=(i-1)*w+j-1;vv[k]=(i-1)*w+j;InsertEdge(uu[k],vv[k]);++k;}
					if(s[i&1][j-1]<=s[i&1][j]){uu[k]=(i-1)*w+j;vv[k]=(i-1)*w+j-1;InsertEdge(uu[k],vv[k]);++k;}
				}
			}
		}
		for(int i=1;i<=n;++i)tarjan(i);
		for(int i=0;i<k;++i){
			if(low[uu[i]] == low[vv[i]])continue;
			++ind[low[vv[i]]],++oud[low[uu[i]]];
		}
		int a=0,b=0;
		for(int i=1;i<=n;++i){
			if(ind[low[i]] == 0)++a,ind[low[i]]=1;
			if(oud[low[i]] == 0)++b,oud[low[i]]=1;
		}
		if(sum == 1)printf("0\n");
		else printf("%d\n",max(a,b));
	}
	return 0;
}