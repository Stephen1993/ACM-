#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=200;
int dp[MAX][MAX],value[MAX][2];
int main(){
	int n,m,k,s;
	while(cin >> n >> m >> k >> s){
		int min=-1;
		memset(dp,0,sizeof dp);
		for(int i = 0;i < k;++ i){
			scanf("%d%d",&value[i][0],&value[i][1]);
		}
		for(int i = 0;i < k;++ i){
			for(int j = 1;j <= s;++ j){
				for(int k = value[i][1];k <= m;++ k){
					dp[j][k]=max(dp[j][k],dp[j-1][k-value[i][1]]+value[i][0]);
					if(dp[j][k] >= n){
						min = min > (m-k)?min:(m-k);
					}
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
} 