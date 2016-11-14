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

const int MAX=20000+10;
int n,size,top,index,sum;
int head[MAX],dfn[MAX],low[MAX];
int mark[MAX],stack[MAX];
bool flag;

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
} edge[MAX*3];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,mark[i]=0;
	sum=size=top=index=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
	flag=true;
}

void tarjan(int u){
	if(mark[u]){
		if(mark[u] == 1 && dfn[u] != low[u])flag=false;
		return;	
	}
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	mark[u]=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		tarjan(v);
		if(mark[v] == 1){
			if(low[u] != dfn[u])flag=false;
			low[u]=min(low[u],low[v]);
		}
	}
	if(dfn[u] == low[u]){
		++sum;
		while(stack[top] != u){
			mark[stack[top]]=-1;
			low[stack[top--]]=low[u];
		}
		mark[u]=-1;
		--top;
	}
}

int main(){
	int t,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Init(n);
		while(scanf("%d%d",&u,&v),u+v)InsertEdge(u,v);
		for(int i=0;i<n;++i){
			if(mark[i])continue;
			tarjan(i);
		}
		if(!flag || sum>1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
/*
30
3
0 1
1 2
2 0
0 2
0 0
*/