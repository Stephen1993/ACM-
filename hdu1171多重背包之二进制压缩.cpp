#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAX=500000;
int dp[MAX],value[MAX][2];
int main(){
	int n,k;
	while(cin>>n,n>=0){
		memset(dp,0,sizeof(dp));
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d%d",&value[i][0],&value[i][1]);
			sum+=value[i][0]*value[i][1];
		}
		int all=sum;
		sum=sum/2;
		for(int i=0;i<n;++i){
			for(k=1;k*2-1<=value[i][1];k*=2){//¶þ½øÖÆÑ¹Ëõ. 
				for(int j=sum;j>=value[i][0]*k;--j){
					dp[j]=max(dp[j],dp[j-value[i][0]*k]+value[i][0]*k);
				}
			}
			for(int j=sum;j>=value[i][0]*(value[i][1]-k+1);--j){
			   dp[j]=max(dp[j],dp[j-value[i][0]*(value[i][1]-k+1)]+value[i][0]*(value[i][1]-k+1));
            }
		}
		cout<<all-dp[sum]<<' '<<dp[sum]<<endl;
	}
	return 0;
}