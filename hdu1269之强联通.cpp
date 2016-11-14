/*
利用dp+并查集实现强联通,算法复杂度O(n)
此方法是我写树形dp需要强联通缩点时想到的,所以对于你们写了树形dp
但是却又不会tarjan的人来说可以更好理解并且学习
不过对于数据量太大的由于并查集压缩路径可能会爆栈
所以此方法适用于数据量不是很大的强联通 
*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
using namespace std;

const int MAX=10000+10;
int n,m,size,k;
int head[MAX],father[MAX];
int mark[MAX],stack[MAX];
//int rank[MAX]; 

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*10];

void Init(int num){
	for(int i=0;i<=num;++i){
		head[i]=-1,father[i]=i,mark[i]=0;
		//rank[i]=1;
	}
	size=k=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void dfs(int u,int Father){
	if(mark[u] == -1)return;//环但是已经合并过的点 
	if(mark[u] == 1){//环并且没有合并过点 
		int b=findset(u);
		for(int i=k;stack[i] != u;--i){//对环中的点进行合并 
			int a=findset(stack[i]);
			if(a == b)break;
			//if(rank[a]>rank[b])father[b]=father[a],rank[a]+=rank[b],b=a;
		   //else father[a]=father[b],rank[b]+=rank[a];//需要时可以使用,增加效率 
			father[a]=father[b];
		}
		return;
	}
	mark[u]=1;
	stack[++k]=u;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == Father)continue;
		dfs(v,u);
	}
	mark[u]=-1;
	--k;
	return;
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
		}
		dfs(1,-1);//进行dp+并查集
		/*
		如果要缩点的话只需要把相同祖先的看成一个点,然后进行边的重新连接(边实现存在数组里)
		memset(head,-1,sizeof head);
		size=0;
		for(int i=0;i<m;++i){//环被压缩成点后重新建立图
        	int u=findset(uu[i]);
        	int v=findset(vv[i]); 
        	if(u != uu[i] && !mark[uu[i]])val[u]+=val[uu[i]];//边的权是压缩点之后的权 
        	if(v != vv[i] && !mark[vv[i]])val[v]+=val[vv[i]];
        	if(u != v)InsertEdge(u,v);//InsertEdge(v,u);
		}
		然后dfs1(findset(1),-1)进行计算 
		*/
		int u=findset(1);
		for(int i=2;i<=n;++i){
			if(findset(i) != u){u=INF;break;}
		}
		if(u == INF)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}