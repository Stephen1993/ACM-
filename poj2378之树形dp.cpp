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
int n,size;
int head[MAX];
bool mark[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
} 

int dfs(int u,int father){
	int num=0,last=0;
	bool flag=true;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		num=dfs(v,u);
		if(num>n/2)flag=false;
		last+=num;
	}
	if(n-last-1>n/2)flag=false;
	mark[u]=flag;
	return last+1;
}

int main(){
	int u,v;
	while(~scanf("%d",&n)){
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		dfs(1,-1);
		bool flag=true;
		for(int i=1;i<=n;++i){
			if(mark[i])printf("%d\n",i),flag=false;
		}
		if(flag)printf("NONE\n");
	}
	return 0;
}