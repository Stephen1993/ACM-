#include<iostream>
#define INF 6666666  
using namespace std;	
int dp[10010],s[505][505];
int main()
{
    int t,n,e,f,sum;
	cin>>t;
	while(t--)
	{
		cin>>e>>f>>n;
		int empty=f-e;
		for(int i=1;i<=empty;++i)
		 dp[i]=INF;
	    dp[0]=0;
		for(int i=0;i<n;++i)
		 cin>>s[i][0]>>s[i][1];
		for(int i=0;i<n;++i)
		 for(int j=s[i][1];j<=empty;j++)
		  dp[j]=min(dp[j],dp[j-s[i][1]]+s[i][0]);
	    if(dp[empty]<INF)
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<'.'<<endl;
        else 
        cout<<"This is impossible."<<endl;
	}
	return 0;
}