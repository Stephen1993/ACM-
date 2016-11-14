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

const int MAX=1000+10;
char s[MAX][MAX];
int n,m,dp[MAX],temp[MAX];//表示列有多少1

int main(){
	while(cin>>n>>m){
		int sum=0;
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;++i)scanf("%s",s+i);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(s[i][j] == '1')++dp[j];
				else dp[j]=0;
			}
			memcpy(temp,dp,sizeof dp);
			sort(temp,temp+m,greater<int>());
			for(int j=0;j<m;++j){
				if(temp[j])sum=max(sum,(j+1)*temp[j]);
				else break;
			}
		} 
		cout<<sum<<endl;
	}
	return 0;
}