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
const int MAX=21;
__int64 dp[MAX][MAX];//i个H和j个D有多少种.
int main(){
	int n,m;
	for(int i=1;i<MAX;++i){
		dp[i][0]=1;//有i个H和0个D就只有一种. 
		for(int j=1;j<=i;++j){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	while(cin>>n>>m){
		cout<<dp[n][m]<<endl;
	}
	return 0;
} 