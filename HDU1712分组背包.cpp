#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=200;
int dp[MAX],value[MAX][MAX];
int main(){
	int n,m;
	while(cin>>n>>m,n||m){
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&value[i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=m;j>=0;--j){
				for(int k=1;k<=j;++k){
					dp[j]=max(dp[j],dp[j-k]+value[i][k]);
				}
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}