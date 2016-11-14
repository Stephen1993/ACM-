#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double n;
	while(cin>>n)
	{
		if(pow((int)sqrt(n),2)==n)cout<<'1'<<endl;
		else cout<<'0'<<endl;
	}
	return 0;
} 