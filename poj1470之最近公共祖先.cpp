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

const int MAX=500000+10;
int n,m,size;
int head[MAX],head2[MAX],father[MAX],sum[MAX];
bool mark[MAX];

struct Edge{
	int v,id,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX],edge2[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=head2[i]=-1,sum[i]=0;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void InsertEdge2(int u,int v){
	edge2[size]=Edge(v,head2[u]);
	head2[u]=size++;
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void LCA(int u){
	if(mark[u])return;
	mark[u]=true;
	father[u]=u;
	for(int i=head2[u];i != -1;i=edge2[i].next){
		int v=edge2[i].v;
		if(!mark[v])continue;
		++sum[findset(v)];
	}
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		LCA(v);
		father[v]=u;
	}
}

int main(){
	int u,k,v,root;
	char ch;
	while(~scanf("%d",&n)){
		Init(n);
		memset(mark,false,sizeof mark);
		for(int i=0;i<n;++i){
			scanf("%d:(%d)",&u,&k);
			for(int j=0;j<k;++j){
				scanf("%d",&v);
				InsertEdge(u,v);
				mark[v]=true; 
			}
		}	
		for(int i=1;i<=n;++i)if(!mark[i])root=i;
		memset(mark,false,sizeof mark);
		scanf("%d",&m);
		size=0;
		for(int i=0;i<m;++i){
			while(getchar() != '(');
			scanf("%d%d",&u,&v);
			InsertEdge2(u,v);
			InsertEdge2(v,u);
			while(getchar() != ')');
		}
		LCA(root);
		for(int i=1;i<=n;++i){
			if(sum[i])printf("%d:%d\n",i,sum[i]);
		}
	}
	return 0;
}