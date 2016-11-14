#include<iostream>
#include<cmath>
using namespace std;
const double t=1.618033989;
int main()
{
	long a,b;
	while(cin>>a>>b,a!=0||b!=0)
	{
		long k=b-a;
		long c=k*t;
		if(a==c)cout<<"0\n";
		else
		{
			cout<<"1\n";
			if(!a)cout<<"0 0\n";
			if(a>=c&&b>=c+k)cout<<c<<' '<<c+k<<endl;
			for(int i=1;i<=b;++i)
			{
				if(a==(long)(i*t)&&b>=a+i)cout<<a<<' '<<a+i<<endl;
				if(a==(long)(i*t)+i&&b>=a)cout<<a-i<<' '<<a<<endl;
				else 
				if(b==(long)(i*t)+i&&a>=b-i)cout<<b-i<<' '<<b<<endl;
			}
		}
	}
	return 0;
}