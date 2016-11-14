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

const int MAX=(1<<11)+10;
int n;
int dp[MAX][12],dist[12][12];

void floyd(){
	for(int k=0;k<=n;++k){
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}

void DP(){
	int bit=1<<(n+1);
	for(int i=0;i<bit;++i){
		for(int j=0;j<=n;++j)dp[i][j]=INF;
	}
	dp[1][0]=0;
	for(int i=1;i<bit;++i){
		for(int k=0;k<=n;++k){
			for(int j=0;j<=n;++j){
				if(i&(1<<j) && j)continue;
				dp[i|(1<<j)][j]=min(dp[i|(1<<j)][j],dp[i][k]+dist[k][j]);
			}
		}
	}
	printf("%d\n",dp[bit-1][0]);
} 

int main(){
	while(~scanf("%d",&n),n){
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				scanf("%d",&dist[i][j]);
			}
		}
		floyd();
		DP();
	}
	return 0;
}