#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX=1111;
int dp[MAX],value[MAX];
int main(){
	int n;
	while(cin>>n,n){
		//memset(dp,0,sizeof dp);
		for(int i=0;i<n;++i){
			scanf("%d",&value[i]);
		}
		int max_v=0;
		for(int i=0;i<n;++i){
			dp[i]=value[i];
			for(int j=0;j<i;++j){
				if(value[j]<value[i]){
					dp[i]=max(dp[i],dp[j]+value[i]);
					
				}
			}	
			max_v=max(max_v,dp[i]);
		}
		cout<<max_v<<endl;
	}
	return 0;
}