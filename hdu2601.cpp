#include<iostream>
using namespace std;
int main()
{
	__int64 n,t;
	cin>>t;
	while(t--)
	{
		int num=0;
		cin>>n;
		for(__int64 i=2;i*i<=n+1;++i)
		{
			if((n+1)%i==0)num++;
		}
		cout<<num<<endl;
	}
	return 0;
}