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

const int MAX=500+10;
int dp[40][MAX],s[MAX];//dp表示长度为i花费了j钱的个数

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n>>m;
		for(int i=0;i<=m;++i)dp[0][i]=1;
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i){
			for(int j=i;j>=1;--j){
				for(int k=m;k>=s[i];--k){
					if(dp[j-1][k-s[i]])dp[j][k]+=dp[j-1][k-s[i]];
				}
			}
		}
		int sum=0,ans=0;
		for(int i=n;i>=1;--i){
			for(int j=0;j<=m;++j)sum=max(sum,dp[i][j]);
			if(sum){ans=i;break;}
		}
		if(sum)printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",sum,ans);
		else printf("Sorry, you can't buy anything.\n");
	}
} 