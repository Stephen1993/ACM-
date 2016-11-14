#include<iostream>
using namespace std;
int sum[2001]={0},s[2001][2001]={0};
int main()
{
	int n,x;
	s[1][1]=1;
	sum[1]=1;
    for(int i=2;i<2001;++i)
    for(int j=1;j<=i;++j)
    {
	   s[i][j]=(s[i-1][j]*j+s[i-1][j-1])%1000;
	   sum[i]=(sum[i]+s[i][j])%1000;
    }
    cin>>n;
    while(n--)
    {
    	cin>>x;
    	cout<<sum[x]<<endl;
    }
    return 0;
} 