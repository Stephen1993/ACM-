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
const int MAX=301;
int dp[MAX][MAX];//表示i个格子且第一行为小于等于j个格子的自共轭个数. 
int main(){
      for(int i=1;i<MAX;i++){
      	  for(int j=1;j<MAX;j++){                           
              dp[i][j]=dp[i][j-1];
              if(2*j-1<=i){
              	 if(i-2*j+1==0)dp[i][j]+=1;
                 else dp[i][j]+=dp[i-2*j+1][j-1];
              }
          }
      }
	 int n;
	 while(cin>>n){
		 cout<<dp[n][n]<<endl;
	 }
	 return 0;
}