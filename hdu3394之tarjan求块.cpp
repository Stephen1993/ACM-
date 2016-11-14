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
int n,m,size,top,index,ans1,ans2;
int head[MAX],dfn[MAX],low[MAX],stack[MAX];
int block[MAX];
bool mark[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*20];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=0;
	size=top=index=ans1=ans2=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void check(){
	int num=0;
	for(int i=1;i<=block[0];++i){
		for(int j=head[block[i]];j != -1;j=edge[j].next){
			int v=edge[j].v;
			if(mark[v])++num;
		}
	}
	num=num/2;
	if(num>block[0])ans2+=num;
}

void tarjan(int u,int father){
	if(dfn[u])return;
	dfn[u]=low[u]=++index;
	stack[++top]=u;
	bool flag=true;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father && flag){flag=false;continue;}
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				memset(mark,false,sizeof mark);
				block[0]=0;
				while(stack[top] != v)block[++block[0]]=stack[top--],mark[block[block[0]]]=true;
				--top;
				block[++block[0]]=v,mark[v]=true;
				if(low[v] == dfn[u])block[++block[0]]=u,mark[u]=true,check();
				else ++ans1;
			}
		}else low[u]=min(low[u],dfn[v]);//���,�����ﲻ��low[v]ȥ����low[u],��Ϊ��u�������ڶ����,low[v]���������������Сֵ
		//����:1-2,2-3,3-1,2-4,4-5,5-2,��low[2]�Ѿ� == low[1]ʱ,low[5]������low[2]����,����low[5]�����low[1]�����,ֻ����dfn[v]���� 
	}
}

int main(){
	int u,v;
	while(~scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			InsertEdge(u,v);
			InsertEdge(v,u);
		}
		for(int i=0;i<n;++i)tarjan(i,-1);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}