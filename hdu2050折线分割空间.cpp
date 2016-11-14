#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>m;
	while(m--)
	{
	   cin>>n;
	   cout<<2*n*n-n+1<<endl;//f(n)=f(n-1)+4n-3，若每次增加一条线，假如增加第n条线，则增加n-1个焦点，即增加n个空间，如改为增加平行线..... 
    }
	return 0;
} 