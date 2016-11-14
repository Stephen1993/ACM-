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
int n,m,size,Id,mark[MAX];
int pre[MAX];
int head[MAX],son[MAX][2][3],des[MAX],sum[MAX][3];
int d[2][3];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=0;i<=num;++i){
		head[i]=-1;
		son[i][0][0]=son[i][1][0]=INF;
		des[i]=INF;
	}
	d[0][0]=d[1][0]=INF;
	size=Id=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void checkDes(int u,int v,int x,int y){
	des[u]=min(des[u],min(v,des[v]));
	if(u == 1){
		v=min(v,des[v]);
		if(v<d[0][0]){
			d[1][0]=d[0][0],d[1][1]=d[0][1],d[1][2]=d[0][2];
			d[0][0]=v,d[0][1]=x,d[0][2]=y;
		}else if(v<d[1][0])d[1][0]=v,d[1][1]=x,d[1][2]=y;
	}
}

void checkSon(int u,int v,int x,int y){
	if(v<son[u][0][0]){
		son[u][1][0]=son[u][0][0];
		son[u][1][1]=son[u][0][1];
		son[u][1][2]=son[u][0][2];
		son[u][0][0]=v;
		son[u][0][1]=x;
		son[u][0][2]=y;
	}else if(v<son[u][1][0]){
		son[u][1][0]=v;
		son[u][1][1]=x;
		son[u][1][2]=y;
	}
}

int dfs(int u,int father,int Id){
	int last=0,num=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		num=dfs(v,u,Id+last);
		checkDes(u,v,Id+last+1,Id+last+num);
		checkSon(u,v,Id+last+1,Id+last+num);
		last+=num;
	}
	mark[u]=Id+last+1;
	sum[u][1]=Id+1;
	sum[u][2]=Id+last+1;
	pre[u]=father;
	return last+1;
}

int QuerySon(int x,int y){
	if(sum[y][1]>mark[x] || sum[y][2]<mark[x])return son[y][0][0];
	if(son[y][0][1]>mark[x] || son[y][0][2]<mark[x])return min(pre[y],son[y][0][0]);
	return min(pre[y],son[y][1][0]);
}

int QueryDes(int x,int y){
	if(y == 1){
		if(d[0][1]>mark[x] || d[0][2]<mark[x])return d[0][0];
		return d[1][0];
	}
	if(sum[y][1]>mark[x] || sum[y][2]<mark[x])return des[y];
	return 1;
}

int main(){
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		Init(n+1);
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			InsertEdge(x,y);
			InsertEdge(y,x);
		}
		dfs(1,-1,0);
		pre[1]=INF;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			if(QuerySon(x,y) == INF)printf("no answers!\n");
			else printf("%d %d\n",QuerySon(x,y),QueryDes(x,y));
		}
		printf("\n");
	}
	return 0;
}