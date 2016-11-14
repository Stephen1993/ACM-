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
int n,m,size,top,index,ind,oud;
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],flag[MAX];
//dfn表示点u出现的时间,low表示点u能到达所属环中最早出现的点(记录的是到达的时间) 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[50000+10];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=top=index=ind=oud=0;
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
		if(mark[v] == 1)low[u]=min(low[u],low[v]);//必须点v在栈里面才行 
	}
	if(dfn[u] == low[u]){
		++ind,++oud;//计算缩点后点的个数,方便计算入度和出度
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
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
		}
		memset(mark,0,sizeof mark);
		for(int i=1;i<=n;++i){
			if(mark[i])continue;
			tarjan(i);//tarjan用来缩点 
		}
		if(ind == 1){cout<<0<<endl;continue;} 
		for(int i=0;i<=n;++i)mark[i]=flag[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=head[i];j != -1;j=edge[j].next){
				v=edge[j].v;
				if(low[i] == low[v])continue;
				if(mark[low[i]] == 0)--oud;//mark标记点u是否有出度
				if(flag[low[v]] == 0)--ind;//flag标记点u是否有入度
				mark[low[i]]=1,flag[low[v]]=1; 
			}
		}
		printf("%d\n",max(oud,ind));
	}
	return 0;
}