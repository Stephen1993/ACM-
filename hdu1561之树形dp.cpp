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
	edge[size]=Edge(v,head[u]);//头插法
	head[u]=size++; 
}

int TreeDP(int u){
	int ans=1;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		ans+=TreeDP(v);//将dp[v][1~m]全部计算好
		if(ans>m)ans=m;//用ans而不直接用m作为j的初始值效率提高 
		for(int j=ans;j>=1;--j){//01背包,j表示背包容量,在这里必须从大到小,由于是求dp[u][j] 
			for(int k=j;k>=1;--k){//表示在当前这个孩子及其分支攻克了k个城堡(相当于背包容量为j,当前物品占用了k)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);;//j从大到小则该孩子不会重复计算 
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