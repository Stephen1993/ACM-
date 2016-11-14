#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n)
	{
		int sum=1;
		int m=(n-1)%9+1;
		for(int i=0;i<n;++i)
		sum=(sum*m-1)%9+1;
		cout<<sum<<endl;
	}
	return 0;
}