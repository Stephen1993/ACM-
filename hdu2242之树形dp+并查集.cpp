/*
树形dp+并查集
*/
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
#include<memory.h>
#define INF 99999999
typedef long long LL;
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")

const int MAX=20000+10;
int n,m,size,k,sum,dp;
int head[MAX],val[MAX],uu[MAX],vv[MAX];
int father[MAX],stack[MAX];
short mark[MAX];

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*8];

void makeset(int num){
	for(int i=0;i<=num;++i)father[i]=i;
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Init(int num){
    for(int i=0;i<=num;++i)head[i]=-1,mark[i]=0;
    size=k=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}

void dfs(int u,int Father){//寻找环O(N),把同一个环中的所有点压缩成一个点
	if(mark[u] == -1)return;
	if(mark[u] == 1){
		int b=findset(u);
		for(int i=k;stack[i] != u;--i){
			int a=findset(stack[i]);
			father[a]=father[b];
		}
		return;
	}
	mark[u]=1;
	stack[++k]=u;
	bool flag=true;
    for(int i=head[u];i != -1;i=edge[i].next){
    	int v=edge[i].v;
    	if(v == Father && flag){flag=false;continue;}//去除father->u的重边 
    	dfs(v,u);
    }
    mark[u]=-1; 
    --k;
    return;
}

int dfs2(int u,int father){
	int ans=val[u];
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		ans+=dfs2(v,u);
	}
	if(abs(sum-ans-ans)<dp)dp=abs(sum-ans-ans);
	return ans;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        Init(n);
        makeset(n);
        sum=0,dp=INF;
        for(int i=0;i<n;++i)scanf("%d",val+i),sum+=val[i];
        for(int i=0;i<m;++i){
            scanf("%d%d",&uu[i],&vv[i]);
            InsertEdge(uu[i],vv[i]);
            InsertEdge(vv[i],uu[i]); 
        }
        dfs(0,-1);
        Init(n);
        for(int i=0;i<m;++i){//环被压缩成点后重新建立图
        	int u=findset(uu[i]);
        	int v=findset(vv[i]); 
        	if(u != uu[i] && !mark[uu[i]])val[u]+=val[uu[i]];
        	if(v != vv[i] && !mark[vv[i]])val[v]+=val[vv[i]];
        	if(u != v)InsertEdge(u,v),InsertEdge(v,u);
        	mark[uu[i]]=1,mark[vv[i]]=1;
        }
        if(head[findset(0)] == -1)printf("impossiblen");//表示原来的全部点相连构成环,压缩成一个点 
        else{
        	dfs2(findset(0),-1);
        	printf("%dn",dp);
        } 
    }
    return 0;
}