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

const int MAX=103;
char s[MAX];
int dp[MAX][2];//dp[i][0]代表大写未开启,dp[i][1]代表大写开启. 

int main(){
	int t,i;
	cin>>t;
	while(t--){
		scanf("%s",s);
		memset(dp,0,sizeof dp);
		dp[0][1]=1;
		for(int i=0;i<strlen(s);++i){
			if(s[i]>='a'){
				dp[i+1][0]=min(dp[i][0]+1,dp[i][1]+2);
				dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+2);
			}
			else{
				dp[i+1][0]=min(dp[i][0]+2,dp[i][1]+2);
				dp[i+1][1]=min(dp[i][0]+2,dp[i][1]+1);
			}
		}
		cout<<min(dp[strlen(s)][0],dp[strlen(s)][1]+1)<<endl;
	} 
	return 0;
}