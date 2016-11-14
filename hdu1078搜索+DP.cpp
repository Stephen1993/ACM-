#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=101;
int dp[MAX][MAX],value[MAX][MAX];
int n,k;
int dir[4][2]={0,1,0,-1,-1,0,1,0};
int dfs(int x,int y){
	if(dp[x][y])return dp[x][y];
	int max_=0;
	for(int i=0;i<4;++i){
		for(int j=1;j<=k;++j){
			int a=x+dir[i][0]*j;
			int b=y+dir[i][1]*j;
			if(a<0||a>=n||b<0||b>=n||value[a][b]<=value[x][y])continue;
			int temp=dfs(a,b);
			max_=max(max_,temp);
		}
	}
	dp[x][y]=value[x][y]+max_;
	return dp[x][y];
}
int main(){
	while(cin>>n>>k,n!=-1&&k!=-1){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>value[i][j];
				dp[i][j]=0;
			}
		}
		dfs(0,0);
		cout<<dp[0][0]<<endl;
	}
	return 0;
}