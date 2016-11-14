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

const int MAX=(1<<14)+10;
int n,m;
LL val[15],dp[MAX][15][15],num[MAX][15][15];
bool edge[15][15];

void DP(){
	int bit=1<<(n+1);
	for(int i=0;i<bit;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=n;++k)dp[i][j][k]=-1;
		}
	}
	//初始化0->i的状态,并且dp[s][i][0]也赋值是为了当n=1的时候也有0->1和1->0两种情况 
	for(int i=1;i<=n;++i)dp[1|(1<<i)][0][i]=dp[1|(1<<i)][i][0]=val[i],num[1|(1<<i)][0][i]=num[1|(1<<i)][i][0]=1;
	for(int i=0;i<bit;++i){
		for(int j=0;j<=n;++j){
			for(int k=1;k<=n;++k){//k必须从1开始,k如果从0开始会产生1->0>2这种1->2无边但是有结果的情况 
				if(dp[i][j][k] == -1)continue;//如果dp[i][j][k]这个状态没有出现过就不能由这个状态去推其他状态 
				for(int t=0;t<=n;++t){
					if(i&(1<<t))continue;//走过的点不能重复走 
					if(!edge[k][t])continue;//k->t有边才能从k->t 
					int w=dp[i][j][k]+val[t]+val[k]*val[t];
					if(edge[t][j])w+=val[k]*val[t]*val[j];
					if(w>dp[i|(1<<t)][k][t])dp[i|(1<<t)][k][t]=w,num[i|(1<<t)][k][t]=num[i][j][k];
					else if(w == dp[i|(1<<t)][k][t])num[i|(1<<t)][k][t]+=num[i][j][k];
				}
			}
		}
	}
	LL sum=0,ans=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(dp[bit-1][i][j]>sum)sum=dp[bit-1][i][j],ans=num[bit-1][i][j];
			else if(dp[bit-1][i][j] == sum)ans+=num[bit-1][i][j];
		}
	}
	printf("%lld %lld\n",sum,ans/2);
}

int main(){
	int t,u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&val[i]);
		memset(edge,false,sizeof edge);
		for(int i=1;i<=n;++i)edge[0][i]=edge[i][0]=true;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			edge[u][v]=edge[v][u]=true;
		}
		DP();
	}
	return 0;
}