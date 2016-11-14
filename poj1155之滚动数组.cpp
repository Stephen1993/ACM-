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

const int MAX=3000+10;
int n,m,size,head[MAX],temp[MAX];
int val[MAX],dp[MAX],dp2[MAX];//dp记录以u为根的树允许j个用户观看电视亏本的最少钱 

struct Edge{
	int v,w,next;
	Edge(){}
	Edge(int V,int W,int NEXT):v(V),w(W),next(NEXT){}
}edge[MAX*2];

void Init(int num){
	for(int i=1;i<=num;++i)head[i]=-1;
	size=0;
}

void InsertEdge(int u,int v,int w){
	edge[size]=Edge(v,w,head[u]);
	head[u]=size++;
}

int dfs(int u,int Id){
	int p=0,now=0,last=0,*f=dp,*g=dp2;
	f[Id]=g[Id]=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w;
		//if(v == father)continue;
		now=dfs(v,Id+last+1);
		if(v>=n-m+1)++now,p=1;
		else p=0;
		//swap(f,g);//采用滚动数组并用指针交换实现数组交换
		//for(int j=1;j<=last;++j)f[Id+j]=g[Id+j];
		for(int j=last+1;j<=last+now;++j)f[Id+j]=INF;
		for(int j=0;j<=last;++j){
			for(int k=1;k<=now;++k){
				f[Id+j+k]=min(f[Id+j+k],g[Id+j]+temp[k-p]+w-val[v]);
			}
		}
		last+=now;
		for(int j=1;j<=last;++j)g[Id+j]=f[Id+j];
	}
	for(int i=1;i<=last;++i)temp[i]=g[Id+i];
	return last;
}

int main(){
	int v,w,k;
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<=n-m;++i){
			scanf("%d",&k);
			val[i]=0;
			for(int j=1;j<=k;++j){
				scanf("%d%d",&v,&w);
				InsertEdge(i,v,w);
				//InsertEdge(v,i,w);
			}
		}
		for(int i=n-m+1;i<=n;++i)scanf("%d",&val[i]);
		dfs(1,0);
		for(int i=m;i>=0;--i){
			if(temp[i]<=0){printf("%d\n",i);break;}
		}
	}
	return 0;
} 