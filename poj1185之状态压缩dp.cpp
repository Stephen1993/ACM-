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

const int MAX=100+10;
int n,m,lastsize,lastlastsize,nowsize;
int last[MAX],lastlast[MAX],now[MAX];
int num[MAX],dp[MAX][MAX],temp[MAX][MAX];//dp[k][i][j]表示第k行选择i方案,第k-1行选择j方案的最大炮兵数
char Map[MAX][MAX];

void dfs(int id,int k,int p,int sum){
	if(k>=m){now[++nowsize]=p;num[nowsize]=sum;return;}
	if(Map[id][k] == 'P')dfs(id,k+3,p|(1<<k),sum+1);
	dfs(id,k+1,p,sum);
}

void DP(){
	for(int k=1;k<=n;++k){
		memset(now,0,sizeof now);
		nowsize=0;
		dfs(k,0,0,0);
		for(int i=1;i<=nowsize;++i)for(int j=1;j<=lastsize;++j)dp[i][j]=0;
		for(int i=1;i<=nowsize;++i){//本行选择第几个方案 
			for(int j=1;j<=lastsize;++j){//上一行选择第几个方案 
				for(int t=1;t<=lastlastsize;++t){//上上行选择第几个方案 
					if(now[i] & last[j])continue;//与上一行j方案不能共存
					if(now[i] & lastlast[t])continue;//与上上行t方案不能共存
					if(dp[i][j]<temp[j][t]+num[i])dp[i][j]=temp[j][t]+num[i];
				}
			}
		}
		for(int i=1;i<=nowsize;++i)for(int j=1;j<=lastsize;++j)temp[i][j]=dp[i][j];
		for(int i=1;i<=lastsize;++i)lastlast[i]=last[i];lastlastsize=lastsize;
		for(int i=1;i<=nowsize;++i)last[i]=now[i];lastsize=nowsize;
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i)scanf("%s",Map[i]);
		last[1]=lastlast[1]=temp[1][1]=0;
		lastsize=lastlastsize=1;
		DP();
		int sum=0;
		for(int i=1;i<=lastsize;++i){
			for(int j=1;j<=lastlastsize;++j){
				if(temp[i][j]>sum)sum=temp[i][j];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
/*
void DP(){//上面是采用滚动数组节省内存(dp,temp)
	for(int k=1;k<=n;++k){
		memset(now,0,sizeof now);
		nowsize=0;
		dfs(k,0,0,0);
		for(int i=1;i<=nowsize;++i){//本行选择第几个方案 
			for(int j=1;j<=lastsize;++j){//上一行选择第几个方案 
				for(int t=1;t<=lastlastsize;++t){//上上行选择第几个方案 
					if(now[i] & last[j])continue;//与上一行j方案不能共存
					if(now[i] & lastlast[t])continue;//与上上行t方案不能共存
					dp[k][i][j]=max(dp[k][i][j],dp[k-1][j][t]+num[i]); 
				}
			}
		}
		for(int i=1;i<=lastsize;++i)lastlast[i]=last[i];lastlastsize=lastsize;
		for(int i=1;i<=nowsize;++i)last[i]=now[i];lastsize=nowsize;
	}
}
*/