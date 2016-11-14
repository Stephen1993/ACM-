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

const int MAX=2002;
int s[MAX];
int dp[MAX][MAX/2];
int sum[MAX];

int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i=1;i<=n;++i){
			scanf("%d",&s[i]);
		}
		sort(s,s+n+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n/2;++j)dp[i][j]=INF;
		}
		for(int i=0;i<=n;++i)dp[i][0]=0;
		for(int i=2;i<=n;++i)sum[i]=(s[i]-s[i-1])*(s[i]-s[i-1]);
		for(int i=2;i<=n;++i){
			for(int j=1;j*2<=i;++j){
				dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+sum[i]);
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}