#include<iostream>
using namespace std;
int main()
{
	int s[25];
	int n,m;
	s[0]=0;
	s[1]=3;
	s[2]=7;
	for(int i=3;i<21;++i)
	{
		s[i]=2*s[i-1]+s[i-2];
	}
	cin>>n;
	while(n--)
	{
		cin>>m;
		cout<<s[m]<<endl;
	}
	return 0;
}