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

const int MAX=20+10;
int dp[MAX][MAX][MAX][MAX],s1[MAX],s2[MAX],sum1[MAX],sum2[MAX];
//dp[a][b][i][j]表示当前玩家从s1的a~b,s2的i~j能获得的最大价值 

int dfs(int a,int b,int i,int j){
    if(dp[a][b][i][j])return dp[a][b][i][j];
    if(a>b && i>j)return 0;
    int max1=0,max2=0;
    if(a<=b)max1=max(s1[a]+dfs(a+1,b,i,j),s1[b]+dfs(a,b-1,i,j));
    if(i<=j)max2=max(s2[i]+dfs(a,b,i+1,j),s2[j]+dfs(a,b,i,j-1));
    dp[a][b][i][j]=sum1[b]-sum1[a-1]+sum2[j]-sum2[i-1]-max(max1,max2); 
    return dp[a][b][i][j];
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)cin>>s1[i],sum1[i]=sum1[i-1]+s1[i];
        for(int i=1;i<=n;++i)cin>>s2[i],sum2[i]=sum2[i-1]+s2[i];
        memset(dp,0,sizeof dp);
        printf("%d\n",sum1[n]+sum2[n]-dfs(1,n,1,n));
    
    }
    return 0;
}
