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

const int MAX=5000+10;
int n,m,size,top,index;
int uu[MAX*6],vv[MAX*6];
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int mark[MAX],s[MAX],ind[MAX];
bool flag[MAX];
vector<int>a[MAX]; 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*6];

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
			low[stack[top--]]=low[u];
		}
		mark[u]=-1;
		--top;
	}
}

int dfs(int u){
	if(flag[u])return 0;
	flag[u]=1;
	int sum=ind[u];
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		sum+=dfs(v);
	}
	return sum;
}

int main(){
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&uu[i],&vv[i]);
			InsertEdge(uu[i],vv[i]);
		}
		for(int i=0;i<n;++i){
			if(mark[i])continue;
			tarjan(i);
		}
		for(int i=0;i<=n;++i)mark[i]=ind[i]=0,head[i]=-1,a[i].clear();
		for(int i=0;i<n;++i)++ind[low[i]],a[low[i]].push_back(i);
	 	size=0;
	 	for(int i=0;i<m;++i){//缩点逆向重建图 
	 		if(low[uu[i]] == low[vv[i]])continue;
	 		InsertEdge(low[vv[i]],low[uu[i]]);
	 		++mark[low[uu[i]]];
	 	}
	 	int ans=0,sum=0,k=0,t,v; 
	 	for(int i=0;i<=n;++i){
	 		t=a[i].size();
	 		if(t == 0)continue;
	 		v=a[i][0];
	 		if(mark[low[v]])continue;//入度不为0的一定不可能最大(因为该点的父节点就比该点大) 
	 		for(int j=0;j<=index;++j)flag[j]=false;
	 		ans=dfs(low[v]);
	 		if(ans<sum)continue;
	 		if(ans>sum)sum=ans,k=0;
	 		for(int j=0;j<t;++j)s[k++]=a[i][j];
	 	}
	 	sort(s,s+k);
		printf("Case %d: %d\n",++num,sum-1);
		for(int i=0;i<k;++i)printf("%d%c",s[i],i+1 == k?'\n':' ');
	}
	return 0;
}