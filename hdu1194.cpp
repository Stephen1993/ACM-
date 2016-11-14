#include<iostream>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if((a+b)&1)cout<<"impossible"<<endl;
		else
		{
			b=(a+b)/2;
			a=a-b;
			if(a<0)cout<<"impossible"<<endl;
			else cout<<(a>b?a:b)<<' '<<(a>b?b:a)<<endl;
		}
	}
	return 0;
}