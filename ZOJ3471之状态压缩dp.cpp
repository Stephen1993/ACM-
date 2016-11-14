#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<10)+10;
int n;
int dp[MAX],poww[20][20];

void DP(){
	memset(dp,0,sizeof dp);
	int bit=1<<n;
	for(int i=0;i<bit;++i){//状态i,1表示该原子已被撞没,0表示还存在 
		for(int j=0;j<n;++j){
			if(i&(1<<j))continue;
			for(int k=0;k<n;++k){//用k去撞击j 
				if(j == k)continue;
				if(i&(1<<k))continue;
				dp[i|(1<<k)]=max(dp[i|(1<<k)],dp[i]+poww[j][k]);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;++i)sum=max(sum,dp[bit-1-(1<<i)]);//最后只剩下原子i 
	printf("%d\n",sum);
}

int main(){
	while(~scanf("%d",&n),n){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)scanf("%d",&poww[i][j]);
		}
		DP();
	}
	return 0;
}
/*
10
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
*/