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
const int MAX=1001;
int s[MAX],dp[21][MAX],p[21];
int n,m;
int main(){
	while(cin>>n,n){
		cin>>m;
		for(int i=1;i<=m;++i){
			cin>>p[i];
		}
		for(int i=1;i<=n;++i){
			cin>>s[i];
		}
		for(int i=1;i<=m;++i){//第i段 
			for(int j=p[i];j<=n;++j){//第i段前j个数的最大值. 
				int sum=0;
				for(int k=j;k>j-p[i];--k){ 
					sum+=s[k];
				}
				dp[i][j]=max(sum+dp[i-1][j-p[i]],dp[i][j-1]); 
			}
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
