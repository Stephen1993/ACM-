#include<iostream>
#include<cmath>
#define eps 1e-8;
using namespace std;
int main()
{
	double s,v,u,num;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>u>>v;
		num=atan2(1,u)+atan2(1,v);
		s=1/tan(num);
		double sum=v*u-s*u-s*v+eps;
		cout<<sum<<endl;
		printf("%d",(int)sum);
	}
	return 0;
}