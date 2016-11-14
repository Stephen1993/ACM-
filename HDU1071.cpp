#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
typedef struct
{
	double x,y;
}point;
point p1,p2,p3;
double fun(double a,double b,double c,double x)
{
	return a*x*x*x/3+b*x*x/2+c*x;
}
int main()
{
	int t;
	double a,b,c;
	cin>>t;
	while(t--)
    {
    	cin>>p1.x>>p1.y;
		cin>>p2.x>>p2.y;
		cin>>p3.x>>p3.y;
		a=(p2.y-p1.y)/((p2.x-p1.x)*(p2.x+p1.x-2*p1.x));
		b=-2*a*p1.x;
		c=p1.y+b*b/(4*a);
		double s=fabs(fun(a,b,c,p3.x)-fun(a,b,c,p2.x));
		s=s-fabs((p2.y+p3.y)*(p3.x-p2.x)*0.5);
		cout<<fixed<<setprecision(2)<<s<<endl;
    } 
    return 0;
}