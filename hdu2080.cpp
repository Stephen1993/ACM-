#include<iostream>
#include<math.h>
#include<iomanip>
#define PI 3.141592653
using namespace std;
double calculate(double x,double y)
{
	double num=atan2(y,x)/PI*180;
	/*if(x>=0&&y>=0)
	 while(num>=180)
	  return num-180;
    if(x<0&&y>=0)
     while(num>=180)
      return num-180;
    if(x<=0&&y<=0)
     while(num<180)
      return num+180;
    if(x>0&&y<=0)
     while(num<180)
      return num+180;*/
    return num;
}
int main()
{
	double x1,y1,x2,y2,sum;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		sum=fabs(calculate(x1,y1)-calculate(x2,y2));
	    if(sum>180)
	    sum=360-sum;
	    cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}