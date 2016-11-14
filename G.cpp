#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1111;
int value[MAX][2],dp[MAX];
int main(){
	int n,v,t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof dp);
		scanf("%d%D",&n,&v);
		for(int i=0;i<n;++i){
			scanf("%d",&value[i][0]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&value[i][1]);
		}
		for(int i=0;i<n;++i){
			for(int j=v;j>=value[i][1];j--){
				dp[j]=max(dp[j],dp[j-value[i][1]]+value[i][0]);
			}
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}