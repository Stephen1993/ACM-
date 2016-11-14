#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m,n,m)
	{
		int sum=(int)sqrt(2*m);
		for(int i=sum;i>=1;i--)
		{
			int num=(m*2/i+1-i)/2;
			if((2*num+i-1)*i==2*m&&num+i-1<=n)
			cout<<'['<<num<<','<<num+i-1<<']'<<endl;
		}
		cout<<endl;
	}
	return 0;
} 