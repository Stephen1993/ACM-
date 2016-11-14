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
int n,q,size;
bool a[MAX];
int head[MAX],c[MAX],start[MAX],end[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,a[i]=false;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int u){
	start[u]=++size;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		dfs(v);
	}
	end[u]=size;
}

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y,int d){
	while(x<=y){
		c[x]+=d;
		x+=lowbit(x);
	}
}

int Query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	int u,v;
	char op[3];
	while(~scanf("%d",&n)){
		Init(n);
		memset(c,0,sizeof c);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			a[u]=a[v]=true;
		}
		size=0;
		dfs(1);
		for(int i=1;i<=n;++i){
			if(a[i] == 1)Update(start[i],end[1],1);
		}
		scanf("%d",&q);
		for(int i=0;i<q;++i){
			scanf("%s%d",op,&u);
			if(op[0] == 'C'){
				if(a[u])Update(start[u],end[1],-1);
				else Update(start[u],end[1],1);
				a[u]=!a[u];
			}else{
				printf("%d\n",Query(end[u])-Query(start[u]-1));
			}
		}
	}
	return 0; 
} 