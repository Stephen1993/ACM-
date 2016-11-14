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
#define INF 99999
typedef long long LL;
using namespace std;

const int MAX=100+10;
int n,size;
//以u为根的树:
//temp[0]表示点v为根的树仅属于一个环的最少添加边数
//temp[1]表示点v为根的树除v外仅属于一个环的最少添加边数 
//temp[2]表示点v为根的树除v和一条从v出发的链外仅属于一个环的最少添加边数
//由于每个v只会使用一次,所以采用每次temp[3]=dp[3]临时赋值(滚动数组的思想)节省空间,不需要dp[v][3] 
int head[MAX],temp[3];

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

void dfs(int u,int father){
	//a用来记录哪个点使得dp[u][1]-dp[v][0]+dp[v][2]+1最小,a是记录dp[v][2]-dp[v][0]即temp[2]-temp[0] 
   //b,c用来记录哪两个点使得dp[u][1]-dp[b][0]+min(dp[b][1],dp[b][2])-dp[c][0]+min(dp[c][1],dp[c][2])+1最小
   //b,c记录min(dp[v][1],dp[v][2])-dp[v][0]即min(temp[1],temp[2])-temp[0] 
	int dp[3]={0,0,INF},a=INF,b=INF,c=INF,v,w;
	for(int i=head[u];i != -1;i=edge[i].next){
		v=edge[i].v;
		if(v == father)continue;
		dfs(v,u);
		dp[1]+=temp[0];
		if(temp[2]-temp[0]<a)a=temp[2]-temp[0];
		w=min(temp[1],temp[2])-temp[0];
		if(w<b){c=b;b=w;}
		else if(w<c)c=w;
	}
	temp[1]=dp[1];//temp[1]=dp[1];
	temp[2]=dp[1]+b;//temp[2]=dp[2]=dp[1]+min(dp[v][1],dp[v][2])-dp[v][0]=dp[2]+b
	temp[0]=dp[1]+min(a,b+c)+1;//temp[0]=dp[0]=dp[1]+min(a,b,c)
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
		if(temp[0]>=INF)printf("-1\n");//cout<<-1<<endl;
		else printf("%d\n",temp[0]);//cout<<temp[0]<<endl;
	}
	return 0;
} 