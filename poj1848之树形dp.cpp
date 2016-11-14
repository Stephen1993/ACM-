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
//��uΪ������:
//temp[0]��ʾ��vΪ������������һ������������ӱ���
//temp[1]��ʾ��vΪ��������v�������һ������������ӱ��� 
//temp[2]��ʾ��vΪ��������v��һ����v���������������һ������������ӱ���
//����ÿ��vֻ��ʹ��һ��,���Բ���ÿ��temp[3]=dp[3]��ʱ��ֵ(���������˼��)��ʡ�ռ�,����Ҫdp[v][3] 
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
	//a������¼�ĸ���ʹ��dp[u][1]-dp[v][0]+dp[v][2]+1��С,a�Ǽ�¼dp[v][2]-dp[v][0]��temp[2]-temp[0] 
   //b,c������¼��������ʹ��dp[u][1]-dp[b][0]+min(dp[b][1],dp[b][2])-dp[c][0]+min(dp[c][1],dp[c][2])+1��С
   //b,c��¼min(dp[v][1],dp[v][2])-dp[v][0]��min(temp[1],temp[2])-temp[0] 
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