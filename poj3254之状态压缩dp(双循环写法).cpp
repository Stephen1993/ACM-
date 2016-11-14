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

const int MAX=377+10;
const int mod=100000000;
int n,m,nowsize,lastsize;
int now[MAX],last[MAX];
int temp[MAX],dp[MAX],s[15][15];

void dfs(int id,int k,int p){
	if(k >= m){now[++nowsize]=p;return;}
	dfs(id,k+1,p);
	if(s[id][k] == 1)dfs(id,k+2,p|(1<<k));
}

void DP(){
	lastsize=1;
	last[1]=0;
	temp[1]=1;
	for(int k=1;k<=n;++k){
		nowsize=0;
		dfs(k,0,0);
		for(int i=1;i<=nowsize;++i)dp[i]=0;
		for(int i=1;i<=nowsize;++i){
			for(int j=1;j<=lastsize;++j){
				if(now[i] & last[j])continue;
				dp[i]=(dp[i]+temp[j])%mod;
			}
		}
		for(int i=1;i<=nowsize;++i)temp[i]=dp[i];
		for(int i=1;i<=nowsize;++i)last[i]=now[i];
		lastsize=nowsize;
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i){
			for(int j=0;j<m;++j)scanf("%d",&s[i][j]);
		}
		DP();
		int sum=0;
		for(int i=1;i<=lastsize;++i)sum=(sum+temp[i])%mod;
		printf("%d\n",sum);
	}
	return 0;
}