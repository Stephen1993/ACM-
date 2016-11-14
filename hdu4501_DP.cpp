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

const int MAX=111;
int dp[2][MAX][MAX][10];
int s[MAX][3];

int main(){
	int n,v1,v2,k;
	while(cin>>n>>v1>>v2>>k){
		for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1]>>s[i][2];
		int sum=0,m=0;
		for(int i=0;i<=v1;++i){
			for(int j=0;j<=v2;++j){
				for(int t=0;t<=k;++t)dp[0][i][j][t]=0;
			}
		}
		for(int i=1;i<=n;++i){
			m=m^1;
			for(int j=v1;j>=0;--j){
				for(int k1=v2;k1>=0;--k1){
					for(int t=k;t>=0;--t){
						dp[m][j][k1][t]=dp[m^1][j][k1][t];
						if(j>=s[i][0])dp[m][j][k1][t]=max(dp[m][j][k1][t],dp[m^1][j-s[i][0]][k1][t]+s[i][2]);
						if(k1>=s[i][1])dp[m][j][k1][t]=max(dp[m][j][k1][t],dp[m^1][j][k1-s[i][1]][t]+s[i][2]);
						if(t>=1)dp[m][j][k1][t]=max(dp[m][j][k1][t],dp[m^1][j][k1][t-1]+s[i][2]);
						sum=max(sum,dp[m][j][k1][t]);
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}