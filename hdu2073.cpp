#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double calculate(int x,int y)
{
	int n=x+y;
	double num=0;
	double l=sqrt(2);
	for(int i=0;i<n;++i)
	    num+=i*l;
	num+=x*l;
	for(int i=0;i<n;i++)
	num+=sqrt(i*i+(i+1)*(i+1));
	return num;
}
int main()
{
	int t,x1,y1,x2,y2;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		double sum=fabs(calculate(x1,y1)-calculate(x2,y2));
		cout<<fixed<<setprecision(3)<<sum<<endl;
	}
	return 0;
}