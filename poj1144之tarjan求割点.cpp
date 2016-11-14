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
int n,size,index;
int head[MAX],dfn[MAX],low[MAX],sum[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,sum[i]=1,dfn[i]=0;
	size=index=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	dfn[u]=low[u]=++index;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		if(!dfn[v]){
			tarjan(v,u);
			if(low[v]>=dfn[u])++sum[u];
			low[u]=min(low[u],low[v]);
		}else low[u]=min(low[u],dfn[v]);
		//low[u]=min(low[u],low[v]);
	}
}

int main(){
	int u,v;
	char ch;
	while(cin>>n,n){
		Init(n);
		while(cin>>u,u){
			while(1){
				ch=getchar();
				if(ch == '\n')break;
				scanf("%d",&v);
				InsertEdge(u,v);
				InsertEdge(v,u);
			}
		}
		sum[1]=0;
		tarjan(1,-1);
		int ans=0;
		for(int i=1;i<=n;++i)if(sum[i]>1)++ans;
		cout<<ans<<endl;
	}
	return 0;
}
/*
5
1 3 2
2 4 5 3
4 5
0
5
1 2 3
2 3 4 5
4 5
0
*/