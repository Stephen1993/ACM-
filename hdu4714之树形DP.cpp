/*思路：由于给定的是一棵树，现在要求删除边和增添边最少使原来的树变成一个环
则应该是将原来的树先删除某些边变成k部分,这k部分都是一条链形(否则有其他分支就要去掉)
然后又需要增添k条边把这k部分链接起来,最后再增添一条边连接成环 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")

const int MAX=1000000+10;
int head[MAX],size,sum=0; 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	memset(head,-1,sizeof(int)*(num+1));
	size=sum=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

int dfs(int u,int father){
	int num=0,v;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		num+=dfs(v,u);
	}
	if(num>=2){
		if(u == 1)sum+=num-2;
		else sum+=num-1;
		return 0;
	}else return 1;
}

int main(){
	int t,n,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Init(n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		dfs(1,0);
		printf("%d\n",sum*2+1);
	}
	return 0;
}