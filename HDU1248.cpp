#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,n,s[3]={150,200,350},dp[10001];
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<3;++i)
		 for(int j=s[i];j<=n;j++)
		  dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
	    cout<<n-dp[n]<<endl;
	}
	return 0;
}