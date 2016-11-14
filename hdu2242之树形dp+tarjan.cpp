/*
5 6
1 1 1 1 1
0 4
0 1
1 3
1 2
2 4
2 3
impossible
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=20000+10;
int n,m,size,index,sum,ans,top;
int u[MAX],v[MAX],val[MAX],val2[MAX];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];//dfn表示点最开始出现的时间,low表示点能到达的最早祖先(包括本身) 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=val2[i]=0;
	size=index=sum=top=0;
	ans=INF;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void tarjan(int u,int father){
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	bool flag=true;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father && flag){flag=false;continue;}
		if(!dfn[v])tarjan(v,u);//dfn[u]=0表示未访问 
		if(low[v]<low[u])low[u]=low[v];
		//如果是有向图需要判断是否v在栈中,if(!dfn[v])...else if(mark[v])low[u]=min(low[u],low[v])
	}
	if(dfn[u] == low[u]){
		while(stack[top] != u)low[stack[top--]]=low[u];
		--top;
	}
}

int dfs(int u,int father){
	int num=val2[u];
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		num+=dfs(v,u);
	}
	int w=abs(sum-num-num);
	if(w<ans)ans=w;
	return num;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=0;i<n;++i)scanf("%d",val+i),sum+=val[i];
		for(int i=0;i<m;++i){
			scanf("%d%d",&u[i],&v[i]);
			InsertEdge(u[i],v[i]);
			InsertEdge(v[i],u[i]); 
		}
		tarjan(0,-1);//由于原图连通,所以从任意一点开始即可
		memset(head,-1,sizeof head);
		size=0;
		for(int i=0;i<n;++i)val2[low[i]]+=val[i];//计算缩点后每个点的价值 
		for(int i=0;i<m;++i){//缩点重建图
			if(low[u[i]] == low[v[i]])continue;
			InsertEdge(low[u[i]],low[v[i]]);
			InsertEdge(low[v[i]],low[u[i]]);
		}
		if(head[low[0]] == -1)printf("impossible\n");
		else{
			dfs(low[0],-1);//树形dp
			printf("%d\n",ans); 
		}
	}
	return 0;
}