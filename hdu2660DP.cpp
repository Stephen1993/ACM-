#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=1001;
int dp[21][MAX];
int s[21][2];

int main(){
	int n,k,w,t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>s[i][0]>>s[i][1];
		}
		cin>>w;
		for(int i=1;i<=n;++i){
			for(int j=k;j>=1;--j){
				for(int v=w;v>=s[i][1];--v){
					dp[j][v]=max(dp[j][v],dp[j-1][v-s[i][1]]+s[i][0]);
				}
			}
		}
		int sum=0;
		for(int i=0;i<=w;++i)sum=max(sum,dp[k][i]);
		cout<<sum<<endl;
	}
	return 0;
}