/*
����dp+���鼯ʵ��ǿ��ͨ,�㷨���Ӷ�O(n)
�˷�������д����dp��Ҫǿ��ͨ����ʱ�뵽��,���Զ�������д������dp
����ȴ�ֲ���tarjan������˵���Ը�����Ⲣ��ѧϰ
��������������̫������ڲ��鼯ѹ��·�����ܻᱬջ
���Դ˷������������������Ǻܴ��ǿ��ͨ 
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
	if(mark[u] == -1)return;//�������Ѿ��ϲ����ĵ� 
	if(mark[u] == 1){//������û�кϲ����� 
		int b=findset(u);
		for(int i=k;stack[i] != u;--i){//�Ի��еĵ���кϲ� 
			int a=findset(stack[i]);
			if(a == b)break;
			//if(rank[a]>rank[b])father[b]=father[a],rank[a]+=rank[b],b=a;
		   //else father[a]=father[b],rank[b]+=rank[a];//��Ҫʱ����ʹ��,����Ч�� 
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
		dfs(1,-1);//����dp+���鼯
		/*
		���Ҫ����Ļ�ֻ��Ҫ����ͬ���ȵĿ���һ����,Ȼ����бߵ���������(��ʵ�ִ���������)
		memset(head,-1,sizeof head);
		size=0;
		for(int i=0;i<m;++i){//����ѹ���ɵ�����½���ͼ
        	int u=findset(uu[i]);
        	int v=findset(vv[i]); 
        	if(u != uu[i] && !mark[uu[i]])val[u]+=val[uu[i]];//�ߵ�Ȩ��ѹ����֮���Ȩ 
        	if(v != vv[i] && !mark[vv[i]])val[v]+=val[vv[i]];
        	if(u != v)InsertEdge(u,v);//InsertEdge(v,u);
		}
		Ȼ��dfs1(findset(1),-1)���м��� 
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