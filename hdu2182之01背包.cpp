#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=111;
int dp[MAX][MAX],s[MAX];
int num,n,a,b,k;
int main(){
	cin>>num;
	while(num--){
		scanf("%d%d%d%d",&n,&a,&b,&k);
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
		}
		memset(dp,0,sizeof dp);
		for(int i=0;i<=k;++i){
			dp[i][0]=s[0];
		}
		for(int i=1;i<=k;++i){
			for(int j=1;j<n;++j){
				for(int t=a;t<=b;++t){
					if(j-t>=0&&dp[i-1][j-t]&&dp[i][j]<dp[i-1][j-t]+s[j]){
						dp[i][j]=dp[i-1][j-t]+s[j];
					}
				}
			}
		}
		int max=-1;
		for(int i=0;i<n;++i){
			max=max>dp[k][i]?max:dp[k][i];
		}
		cout<<max<<endl;
	}
	return 0;
}