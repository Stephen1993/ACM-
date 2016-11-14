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

const int MAX=1000+10;
int n,m,size,top,index;
int head[MAX],val[MAX],dfn[MAX],low[MAX];
int mark[MAX],stack[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,mark[i]=0;
	size=top=index=0;
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
		while(stack[top] != u){
			mark[stack[top]]=-1;
			val[u]=min(val[u],val[stack[top]]);
			low[stack[top--]]=low[u];
		}
		mark[u]=-1;
		--top;
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<=n;++i)scanf("%d",val+i);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v); 
		}
		for(int i=1;i<=n;++i){
			if(mark[i])continue;
			tarjan(i);
		}
		for(int i=0;i<=n;++i)mark[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=head[i];j != -1;j=edge[j].next){
				v=edge[j].v;
				if(low[i] == low[v])continue;
				mark[low[v]]=1;
			}
		}
		int sum=0,ans=0;
		for(int i=1;i<=n;++i){
			if(!mark[low[i]] && dfn[i] == low[i])++ans,sum+=val[i];
			mark[low[i]]=1;
		}
		printf("%d %d\n",ans,sum);
	}
	return 0;
}