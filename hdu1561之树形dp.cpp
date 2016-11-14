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

const int MAX=200+10;
int head[MAX],size,u,w,n,m;
int dp[MAX][MAX],val[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(){
	memset(head,-1,sizeof head);
	memset(dp,0,sizeof dp);
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);//ͷ�巨
	head[u]=size++; 
}

int TreeDP(int u){
	int ans=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		ans+=TreeDP(v);//��dp[v][1~m]ȫ�������
		if(ans>m)ans=m;//��ans����ֱ����m��Ϊj�ĳ�ʼֵЧ����� 
		for(int j=ans;j>=1;--j){//01����,j��ʾ��������,���������Ӵ�С,��������dp[u][j] 
			for(int k=j;k>=1;--k){//��ʾ�ڵ�ǰ������Ӽ����֧������k���Ǳ�(�൱�ڱ�������Ϊj,��ǰ��Ʒռ����k)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);;//j�Ӵ�С��ú��Ӳ����ظ����� 
			} 
		}
	}
	if(u)for(int i=ans;i>=1;--i)dp[u][i]=dp[u][i-1]+val[u];
	return ans;
}

int main(){
	while(cin>>n>>m,n+m){
		Init();
		for(int i=1;i<=n;++i){
			cin>>u>>val[i];
			InsertEdge(u,i);
		}
		TreeDP(0);
		cout<<dp[0][m]<<endl;
	}
	return 0;
}