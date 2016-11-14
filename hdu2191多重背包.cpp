#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAX=1000;
int value[MAX][3],dp[MAX];
int main(){
	int n,m,t,k;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n>>m;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&value[i][0],&value[i][1],&value[i][2]);
		}
		for(int i=0;i<m;++i){
          for(k=1;2*k-1<=value[i][2];k=k*2){
          	for(int j=n;j>=k*value[i][0];j--){
	          	dp[j]=max(dp[j],dp[j-k*value[i][0]]+k*value[i][1]);
	          }
            }
          for(int j=n;j>=(value[i][2]-k+1)*value[i][0];j--){
         	  dp[j]=max(dp[j],dp[j-(value[i][2]-k+1)*value[i][0]]+(value[i][2]-k+1)*value[i][1]);       
          }
	   }
    cout<<dp[n]<<endl;
   }
	return 0;
}