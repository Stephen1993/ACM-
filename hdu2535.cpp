#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num[101];
	int n;
	while(cin>>n,n)
	{
		int sum=0;
		for(int i=0;i<n;++i)
		cin>>num[i];
		sort(num,num+n);
		for(int i=0;i<n/2+1;++i)
		sum=sum+num[i]/2+1;
		cout<<sum<<endl;
	}
	return 0;
}