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

const int MAX=101;
int dp[MAX];//花费i元能购买的大米的最大重量 
int s[MAX][3];

int main(){
	int n,m,k,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,0,sizeof dp);
		for(int i=0;i<m;++i)cin>>s[i][0]>>s[i][1]>>s[i][2];
		for(int i=0;i<m;++i){
			for(k=1;k*2-1<=s[i][2];k=k*2){
				for(int j=n;j>=s[i][0]*k;--j){
					dp[j]=max(dp[j],dp[j-s[i][0]*k]+s[i][1]*k);
				}
			}
			for(int j=n;j>=(s[i][2]-k+1)*s[i][0];--j){
				dp[j]=max(dp[j],dp[j-(s[i][2]-k+1)*s[i][0]]+(s[i][2]-k+1)*s[i][1]);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}