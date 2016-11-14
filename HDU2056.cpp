#include<iostream>
#include<iomanip>
using namespace std;
double wide_high(double a,double b,double c,double d)
{
	double x1,x2,x3,x4;
	if(a>b)
	{
		 x1=b;
		 x2=a;
	}
	else
	{
		 x1=a;
	     x2=b;
	}
	if(c>d)
	{
		 x3=d;
		 x4=c;
	}
	else
	{
		 x3=c;
		 x4=d;
	}
	if(x3<=x1&&x2<=x4)
	return x2-x1;
	if(x1<=x3&&x4<=x2)
	return x4-x3;
	if(x1<x3&&x3<=x2&&x2<x4)
	return x2-x3;
	if(x3<x1&&x1<=x4&&x4<x2)
	return x4-x1;
	return 0;
}
int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		double la=wide_high(x1,x2,x3,x4);
		double lb=wide_high(y1,y2,y3,y4);
		cout<<fixed<<setprecision(2)<<la*lb<<endl;
	}
	return 0;
}