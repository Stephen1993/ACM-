#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int s[40];
	for(int i=0;i<40;++i)
	s[i]=i;
	int n;
	while(cin>>n,n)
	{
		for(int i=1;i<=n;++i)
		cout<<setw(3)<<s[i];
		cout<<endl;
		int num=4*(n-1);
		int sum=n+1;
		for(int i=0;i<n-2;++i)
		{
			cout<<setw(3)<<s[num--];
			for(int j=0;j<n-2;++j)
			cout<<setw(3)<<' ';
			cout<<setw(3)<<sum++<<endl;
		}
		for(int i=num;i>=sum;--i)
		cout<<setw(3)<<s[i];
		cout<<endl;
	}
	return 0;
}