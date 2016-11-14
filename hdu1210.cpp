#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int sum=0;
		int N=1;
		while(N!=n+1)
		{
			if(N>n)N=2*(N-n)-1;
			else N=2*N;
			sum++;
		}
		sum++;
		cout<<sum<<endl;
	}
	return 0;
}