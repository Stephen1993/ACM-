#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int dp[1001],s[1001];
	int n,m;
	while(cin>>n,n)
	{
		for(int i=0;i<n;++i)
		cin>>s[i];
		sort(s,s+n);
		int MAX=s[n-1];
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n-1;++i)
		  for(int j=m-5;j>=s[i];j--)
		     dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
        cout<<m-dp[m-5]-MAX<<endl;
	}
	return 0;
}