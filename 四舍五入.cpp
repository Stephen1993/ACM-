#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
double f(double x)
{
  double i, y;
  i = x*pow(10,2);
  i = (int)(i+0.5);
  y = i*pow(10,-2);
  return y;
}
int main()
{
	double sum=0;
	double s;
	for(int i=0;i<12;++i)
	{
		cin>>s;
		sum+=s;
	}
	double num=f(sum/12);
	cout<<fixed<<setprecision(2)<<'$'<<num<<endl;
	return 0;
}