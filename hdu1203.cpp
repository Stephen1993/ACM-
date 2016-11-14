#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int MAX=11111;
double dp[MAX],value[MAX];
int valume[MAX];
double max(double a,double b){
	return a>b?a:b;
}
int main(){
	int n,m;
	while(cin>>n>>m,n||m){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;++i){
			scanf("%d%lf",&valume[i],&value[i]);
		}
		for(int i=0;i<m;++i){
			for(int j=n;j>=0;j--){
				if(j<valume[i]){
					dp[j]=dp[j];
				}
				else{
					dp[j]=max(dp[j],(dp[j-valume[i]]*value[i]+(1-dp[j-valume[i]])*value[i]+dp[j-valume[i]]*(1-value[i])));
				}
			}
		}
		dp[n]=dp[n]*100;
		cout<<fixed<<setprecision(1)<<dp[n]<<'%'<<endl;
	}
	return 0;
}