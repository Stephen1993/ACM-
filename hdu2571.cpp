#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;

const int MAX=1001;
int dp[21][MAX],s[21][MAX];
vector<int>factor[MAX];

void f(){
	for(int i=2;i<=1000;++i){
		factor[i].push_back(1);
		for(int j=2;j*j<=i;++j){
			if(i%j == 0){
			    factor[i].push_back(j);
   				factor[i].push_back(i/j);
			}
		}
	}
	return;
}


int main(){
	int n,m,sum,t;
	f();
	cin>>t;
	for(int i=1;i<=1000;++i)dp[0][i]=-INF;
	for(int i=1;i<=20;++i)dp[i][0]=-INF;
	while(t--){
	    cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
			
				cin>>s[i][j];	
				if(i == 1 && j == 1){
					dp[i][j]=s[i][j];
					continue;
				}
				sum=-INF;
				for(int k=0;k<factor[j].size();++k){
					sum=max(sum,dp[i][factor[j][k]]);
				}
				dp[i][j]=max(dp[i-1][j]+s[i][j],max(dp[i][j-1]+s[i][j],sum+s[i][j]));
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
} 
