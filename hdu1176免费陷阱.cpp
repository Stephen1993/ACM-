#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int dp[100010][13]; 
int max(int a,int b,int c)
{
	return (a>b?a:b)>(b>c?b:c)?(a>b?a:b):(b>c?b:c);
}
int main()
{
	
	int n;
	int num,t,sum_t;
	while(cin>>n,n)
	{
		memset(dp,0,sizeof(dp));
		sum_t=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&num,&t);
			dp[t][num]++;//改为dp[t][num+1]则将位置从0~10改为了1~11防止后面越界 
			if(t>sum_t)sum_t=t;
		}
		for(int i=sum_t-1;i>=0;i--)
		for(int j=10;j>=0;j--)//由dp[t][num+1]已防止越界可改为j=11;j>=1;j--； 
		{                     //改为dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1])即可 
		  if(j==0)dp[i][j]=dp[i][j]+max(dp[i+1][j],0,dp[i+1][j+1]);
		  else dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]);
        }
		printf("%d\n",dp[0][5]);//若上面已防止越界则改为dp[0][6] 
	}
	return 0;
} 