#include<iostream>
#include<iomanip>
using namespace std;
int t,y;
bool calculate(double x)
{
	if(6+x*(3+x*(2+x*(7+x*8)))>=y)return true;
	else return false;
}
int main()
{
	double min,max,mid;
	cin>>t;
	while(t--)
	{
		cin>>y;
		max=100;
		min=0;
		if(y>=6&&y<=807020306)
		{
			while(max-min>1e-8)
			{
				mid=min+(max-min)/2;
				if(calculate(mid))max=mid;
				else min=mid;
			}
			cout<<fixed<<setprecision(4)<<max<<endl;
		}
		else 
		cout<<"No solution!"<<endl;
	}
	return 0;
}